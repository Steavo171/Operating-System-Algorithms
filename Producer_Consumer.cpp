#include <iostream>
#include <stdio.h>
int queue_size=11;
int mutex = 1;
int full= 0;
int empty=11;
int item_produce=0;

void producer()
{
    //locking
    mutex--;
    if(full>=queue_size)
    {
        printf("Queue is full\n");
    }else
    {
        item_produce++;
        full++;
        empty--;
        printf("Producer produced item %d\n",item_produce);
        }
    //release the lock
    mutex++;
}
void consumer()
{
    //lock the process
    mutex--;
    if(full<=0)
    {
        printf("Queue is empty\n");
    }else
    {
        empty++;
        full--;
        printf("Consumer has taken the product\n");
        }
    //release the lock
    mutex++;
}
int main()
{
    int n, i;
    printf("\n1. Press 1 for Producer"
    "\n2. Press 2 for Consumer"
    "\n3. Press 3 for Exit");
    for (i = 1; i > 0; i++)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n) {

            case 1:
            if ((mutex == 1) && (empty != 0)) {
                producer();
            }else 
                printf("Buffer is full!");
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                }else
                    printf ("Buffer is empty!");
            
                break;
            case 3:
                exit(0);
                break;
        }
    }
}

//Code by Steavo Babu