#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void srtf(vector<vector<int>> &p){
    vector<vector<int>> v = p;
    vector<vector<int>> temp;
    sort(p.begin(), p.end());
    int start = 0;
    int n = p.size();
    int completed = 0;
    vector<int> remainingTime(n);
    for (int i = 0; i < n; i++) remainingTime[i] = p[i][2]; 
    while (completed != n){
        for (int i = 0; i < n; i++)
            if (p[i][0] <= start && remainingTime[i] > 0)
                temp.push_back(p[i]);
        auto cbs = [&](vector<int> &a, vector<int> &b){
            if (remainingTime[a[1]] == remainingTime[b[1]]) return a[1] < b[1];                          
            return remainingTime[a[1]] < remainingTime[b[1]]; 
        };
        if (temp.size())  sort(temp.begin(), temp.end(), cbs);
        if (temp.size()){
            int pr = temp[0][1];
            remainingTime[pr]--;
            start++;
            if (remainingTime[pr] == 0){
                completed++;
                v[pr][3] = start;               
                v[pr][4] = v[pr][3] - v[pr][0]; 
                v[pr][5] = v[pr][4] - v[pr][2]; 
            }
            temp.clear();
        }
        else start++;
    }
    cout << "\nThe process completion order is: \n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;
    float a = 0, b = 0;
    for (int i = 0; i < n; i++){
        cout << v[i][1] + 1 << " \t" << v[i][0] << " \t" << v[i][2] << " \t" << v[i][3] << " \t" << v[i][4] << " \t" << v[i][5] << endl;
        a += v[i][4];
        b += v[i][5];
    }
    cout << "Avg TAT: " << a / n << endl;
    cout << "Avg WT: " << b / n;
}
int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<vector<int>> p(n, vector<int>(6, 0));
    for (int i = 0; i < n; i++){
        cin >> p[i][0] >> p[i][2];
        p[i][1] = i; 
    }
    srtf(p);
}