#include<bits/stdc++.h>
using namespace std;
void priority_scheduling(vector<vector<int>> &p) {
    vector<vector<int>> abc = p, temp;
    sort(p.begin(), p.end());
    int start = 0, n = p.size(), i = 0;
    while (true) {
        while (i < n && p[i][0] <= start) temp.push_back(p[i++]);
        if (temp.size()) {
            sort(temp.begin(), temp.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
            int process = temp[0][2];
            temp.erase(temp.begin());
            abc[process][4] = start += abc[process][3];
            abc[process][5] = abc[process][4] - abc[process][0];
            abc[process][6] = abc[process][5] - abc[process][3];
        } else if (i != n) start = p[i][0];
        else break;
    }
    cout << "PID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for (auto &x : abc) cout << x[2] + 1 << "\t" << x[0] << "\t" << x[3] << "\t" << x[1] << "\t\t" << x[4] << "\t" << x[5] << "\t" << x[6] << "\n";
    float tat = 0, wt = 0;
    for (auto &x : abc) tat += x[5], wt += x[6];
    cout << "Avg tat: " << tat / n << "\nAvg wt: " << wt / n;
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