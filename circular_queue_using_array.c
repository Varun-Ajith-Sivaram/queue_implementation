#include<stdio.h>
#include<stdlib.h>

#define size 10  //size of circular queue is initialized to 10

void enque();   //function to insert element
void deque();   //function to delete element
void display(); //function to display contents of queue

int CQ[size],front,rear,ch;

void main()
{
    front=-1;
    rear=-1;
    
    printf("\tCircular Queue Implementation\n");
    
    printf("\nSize of circular queue is initialized to %d\n",size);
    
    do{
        printf("\nOperations available: \n");
        printf("1.Enque\n");
        printf("2.Deque\n");
        printf("3.Display\n");
        printf("4.Exit\n");
    
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1:enque();
            break;
            case 2:deque();
            break;
            case 3:display();
            break;
            case 4:{
                    printf("\n   --> Exited the program\n");
                    exit(0);
                    }
            default: printf("\n   --> Invalid choice, Enter a valid choice\n");
        }

    }while(ch!=4);
}

void enque()
{
    if(front==(rear+1)%size)
    {
        printf("\n   --> Queue overflow,cannot insert\n");
    }
    
    else
    {
        if(front==-1)
        {
            front=front+1;
        }

        rear=(rear+1)%size;

        printf("\n   Enter the element to be inserted: ");
        scanf("%d",&CQ[rear]);

        printf("\n   --> Element %d is inserted to the queue\n",CQ[rear]);
    }
}

void deque()
{   
    int element;
    
    if(front==-1)
    {
        printf("\n   --> Queue underflow,cannot delete element\n");
    }

    else
    {
        element=CQ[front];
        
        if(front==rear)
        {
            front=rear=-1;
        }

        else
            front=(front+1)%size;

        printf("   --> Element %d is deleted from the queue\n",element);
    }
}

void display()
{
    int t=front;

    if(front==-1)
    {
        printf("\n   --> Queue is empty\n");
    }

    else
    {
        printf("\n   Elements in queue are: \n");

        while(t!=rear)
        {
            printf("\t\t%d\n",CQ[t]);
            t=(t+1)%size;
        }
        printf("\t\t%d\n",CQ[t]);
    }
}
