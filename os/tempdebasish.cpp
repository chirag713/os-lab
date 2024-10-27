#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans=n;
        int count=0;
        while(a.size()){
            int largest = a.size()-1;
            for(int i=a.size()-1;i>=0;i--){
                if(a[i]>=a[largest]){
                    largest = i;
                }
            }
            ans=min(ans , largest+count);
            count++;
            a.erase(a.begin()+largest);
        }
        cout<<ans<<endl;
    }
}