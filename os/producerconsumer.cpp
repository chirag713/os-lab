#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the buffer: ";
    cin >> n;
    vector<int> buffer;
    int ip = 0;
    int ib = 0;
    while(1) { 
        char temp;
        cout << "Enter 'p' to produce or 'c' to consume: ";
        cin >> temp;
        if (temp == 'p') {
            if (ib < n) {
                ++ip;
                buffer.push_back(ip);
                ++ib;
                cout << "Produced item: " << ip << ". Items in buffer: " << ib << "\n";
            } else {
                cout << "Buffer is full, cannot produce more items.\n";
            }
        } else if (temp == 'c') {
            if (ib > 0) {
                cout << "Consumed item: " << buffer.back() << ". Items in buffer: " << --ib << "\n";
                buffer.pop_back();
            } else {
                cout << "Buffer is empty, cannot consume more items.\n";
            }
        } else {
            cout << "Invalid input. Use 'p' to produce or 'c' to consume.\n";
        }
        cout<<"Enter y to continue ";
        char ch;
        cin>>ch;
        if(ch=='y' || ch=='Y'){

        }else break;
    }
    return 0;
}
