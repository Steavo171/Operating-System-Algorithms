#include<iostream>

using namespace std;
class memoryblock
{
    public:
    int processID;
    int size;
    bool allocated;

    memoryblock(int s): size(s),processID(-1),allocated(false){}
};

void firstfit(struct memoryblock memory[],int blocks,int psize,int process[])
{
    for(int i=0;i<psize;i++)
    {
        for(int j=0;j<blocks;j++)
        {
            if(!memory[j].allocated &&memory[j].size>=process[i])
            {
                memory[i].processID=i+1;
                memory[i].allocated=true;
                break;
            }
        }
    }

    cout<<"memory status"<<endl;

    for(int i=0;i<blocks;i++)
    {
        cout<<"Block"<<i+1<<":\n Size="<<memory[i].size<<" Process="<<memory[i].processID<<" allocated= "<<(memory[i].allocated ? "yes":"no");
        cout<<endl;
    }
}

int main()
{

    memoryblock memories[]{
        memoryblock(100),
        memoryblock(500),
        memoryblock(200),
        memoryblock(300),
        memoryblock(600)
    };
    int process[]={212,417,112,426};
    int blocks=sizeof(memories)/sizeof(memories[0]);
    int psize=sizeof(process)/sizeof(process[0]);

    firstfit(memories,blocks,psize,process);

    return 0;
}

//Code by Steavo Babu