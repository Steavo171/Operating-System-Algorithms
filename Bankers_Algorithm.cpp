#include<iostream>
using namespace std;

struct Memory
{
    int a;
    int b;
    int c;
};

int main()
{
    Memory allocation[5];
    Memory maxi[5];
    Memory available;
    Memory Need_Matrix[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter the allocation for process " << i + 1 << ": ";
        cin >> allocation[i].a >> allocation[i].b >> allocation[i].c;

        cout << "Enter the max for process " << i + 1 << ": ";
        cin >> maxi[i].a >> maxi[i].b >> maxi[i].c;
    }

    cout << "Enter the available resource: ";
    cin >> available.a >> available.b >> available.c;

    for (int i = 0; i < 5; i++)
    {
        Need_Matrix[i].a = maxi[i].a - allocation[i].a;
        Need_Matrix[i].b = maxi[i].b - allocation[i].b;
        Need_Matrix[i].c = maxi[i].c - allocation[i].c;
    }

    cout << "Safe sequence: ";
    bool executed[5] = { false };

    for (int count = 0; count < 5; count++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (!executed[i] &&
                Need_Matrix[i].a <= available.a &&
                Need_Matrix[i].b <= available.b &&
                Need_Matrix[i].c <= available.c)
            {
                available.a += allocation[i].a;
                available.b += allocation[i].b;
                available.c += allocation[i].c;

                executed[i] = true;
                cout << "P" << i + 1 << "-->";
            }
        }
    }
    cout<<"End"<<endl;

    return 0;
}

//Code by Steavo Babu