#include<iostream>
#include<vector>
using namespace std;

int sumvector(vector <int> b, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=b[i];
    }
    return sum;
}

int main()
{
    int n,ts;
    cout<<"Enter the number of process:";
    cin>>n;
    vector<int>bt(n);
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter burst time for process"<<i+1<<":";
        cin>>bt[i];
    }
    cout<<"Enter the time slot";
    cin>>ts;
    
    while(sumvector(bt,n))
    {
        for(int j=0;j<n;j++)
        {
            if(bt[j]<ts)
            {
                bt[j]=0;
            }
            else{
                bt[j]=bt[j]-ts;
            }
            cout<<"\t"<<bt[j];
        }
        cout<<endl;
    }
    return 0;
}

//Code by Steavo Babu