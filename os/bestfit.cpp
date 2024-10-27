#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of processes:";
    cin >> n;
    cout << "Enter size of each process:\n";
    vector<vector<int>> pr(n , vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i][1];
        pr[i][0]=i+1;
        pr[i][2]=-1;
    }
    int bno;
    cout << "Enter no of blocks:";
    cin >> bno;
    cout << "Enter size of each blocks:\n";
    vector<vector<int>> block(bno, vector<int>(2));
    for (int i = 0; i < bno; i++)
    {
        cin >> block[i][0];
        block[i][1] = i ;
    }

    sort(block.begin(), block.end());

    vector<int> schedule(bno, -1);



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bno; j++)
        {
            if (schedule[block[j][1]] == -1 && block[j][0] >= pr[i][1] )
            {
                schedule[block[j][1]] = i;
                // cout<<j<<endl;
                pr[i][2]=block[j][1];
                break;
            }
        }
    }
    cout<<"PID\tsize\tbl_no\n";
    for (int i = 0; i < n; i++)
    {
        if(pr[i][2]+1>=1)
        cout << i + 1 << " \t" << pr[i][1] <<"\t"<<pr[i][2]+1<< endl;
        else{
         cout << i + 1 << " \t" << pr[i][1] <<"\t Not scheduled"<< endl;   
        }
    }
    return 0;
}