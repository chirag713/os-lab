#include <bits/stdc++.h>
using namespace std;
void priority_scheduling(vector<vector<int>> &p) {
    vector<vector<int>> abc = p, temp;
    sort(p.begin(), p.end());
    int n = p.size(), start = 0, i = 0;
    while (i < n || !temp.empty()) {
        while (i < n && p[i][0] <= start) temp.push_back(p[i++]);
        if (!temp.empty()) {
            sort(temp.begin(), temp.end(), [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; });
            int process = temp[0][2];
            start += abc[process][3];
            abc[process][4] = start;           
            abc[process][5] = start - abc[process][0];
            abc[process][6] = abc[process][5] - abc[process][3];
            temp.erase(temp.begin());
        } else if (i < n) start = p[i][0];
    }
    cout << "PID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    float totalTAT = 0, totalWT = 0;
    for (auto &x : abc) {
        cout << x[2] + 1 << "\t" << x[0] << "\t" << x[3] << "\t" << x[1] << "\t\t" << x[4] << "\t" << x[5] << "\t" << x[6] << endl;
        totalTAT += x[5];
        totalWT += x[6];
    }
    cout << "Avg TAT: " << totalTAT / n << "\nAvg WT: " << totalWT / n;
}
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<vector<int>> process(n, vector<int>(7));
    for (int i = 0; i < n; i++) {
        process[i][2] = i;
        cout << "Enter AT, Priority, and BT of process " << i + 1 << ": ";
        cin >> process[i][0] >> process[i][1] >> process[i][3];
    }
    priority_scheduling(process);
}