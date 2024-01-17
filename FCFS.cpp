#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter no of process";
    cin>>n;
    int w[n],b[n],t[n],wt=0,tat=0;
    w[0]=0;
    
    for(int i =0;i<n;i++){
        cout<<"Enter burst time of process"<<i+1<<":";
        cin>>b[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
            w[i+1]=w[i]+b[i];
            cout<<"Waiting time of process"<<i+1<<" : "<<w[i]<<endl;;
            t[i]=w[i]+b[i];
            cout<<"Turn around time of process"<<i+1<<" : "<<t[i]<<endl;
            wt=wt+w[i];
            tat=tat+t[i];
    }
    cout<<"Average waiting time = "<<wt/n<<endl;
    cout<<"Average turn around time = "<<tat/n<<endl;
    
}

//Code by Steavo Babu