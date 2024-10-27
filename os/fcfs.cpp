#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void fcfs(vector<vector<int>>&p){
    sort(p.begin() , p.end());

    int start=0;
    int n=p.size();

    for(int i=0;i<n;i++){
        if(start<p[i][0]){
            start=p[i][0];
        }

        start+=p[i][2];

        p[i][3]=start;
    }

    for(int i=0;i<n;i++){
        p[i][4]=p[i][3]-p[i][0];
        p[i][5]=p[i][4]-p[i][2];
    }

    cout<<"PID\tAT\tBT\tCT\tTAT\tWT"<<endl;

    for(int i=0;i<n;i++){
        cout<<p[i][1]+1<<"\t"<<p[i][0]<<"\t"<<p[i][2]<<"\t"<<p[i][3]<<"\t"<<p[i][4]<<"\t"<<p[i][5]<<endl;
    }

    float a=0 , b=0;

    for(int i=0;i<n;i++){
        a+=p[i][4];
        b+=p[i][5];
    }

    cout<<"Avg tat :"<<a/n<<endl;
    cout<<"Avg wt :"<<b/n;

}

int main(){
    int n;
    cout<<"Enter number of processes:";
    cin>>n;
    vector<vector<int>> p(n , vector<int>(6 ,0));

    for(int i=0;i<n;i++){
        cout<<"Enter arrival time of process "<<i+1<<":";
        cin>>p[i][0];
        cout<<"Enter burst time of process "<< i+1<<":";
        cin>>p[i][2];
        p[i][1]=i;
    }

    fcfs(p);

}