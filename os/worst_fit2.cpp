#include <bits/stdc++.h>
using namespace std;
void worstFit(vector<int> b, int m, vector<int> p, int n){
    vector<int> al(n, -1);
    for (int i = 0; i < n; i++){
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
            if (b[j] >= p[i] && (worstIdx == -1 || b[worstIdx] < b[j]))
                worstIdx=j;
        if (worstIdx != -1){
            al[i] = worstIdx;
            b[worstIdx] -= p[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++){
        cout << " " << i + 1 << "\t\t" << p[i] << "\t\t";
        if (al[i] != -1) cout << al[i] + 1<<endl;
        else cout << "Not Allocated"<<endl;
    }
}
int main(){
    int m, n;
    cout << "Enter the number of memory blocks: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < m; i++) cin >> b[i];
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<int> p(n);
    cout << "Enter the size of each process:\n";
    for (int i = 0; i < n; i++) cin >> p[i];
    worstFit(b, m, p, n);
    return 0;
}