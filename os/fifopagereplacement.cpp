#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Enter no of pages in string: ";
    int x; cin >> x;
    vector<int> temp(x);
    for (int& page : temp) cin >> page;
    cout << "Frames\tHit\tFault" << endl;
    for (int n = 1; n <= 7; n++) {
        vector<int> frames(n, 0);
        int pagefaults = 0, j = 0;
        for (int page : temp) {
            if (find(frames.begin(), frames.end(), page) == frames.end()) {
                frames[j] = page;
                j = (j + 1) % n;
                pagefaults++;
            }
        }
        cout << n << "\t" << x - pagefaults << "\t" << pagefaults << endl;
    }
}