#include<stdio.h>
#include<stdlib.h>

#define size 5  //size of double ended queue is initialized to 10

void F_Insert();    //function to insert element through front
void R_Insert();    //function to insert element through rear
void F_Delete();    //function to delete element through front
void R_Delete();    //function to delete element through rear
void Display();     //function to display contents of queue

int DQ[size],front,rear,ch;

void main()
{
    front=-1;
    rear=-1;
    
    printf("\tDouble Ended Queue(DEQUE) Implementation\n");
    
    printf("\nSize of double ended queue is initialized to %d\n",size);
    
    do{
        printf("\nOperations available: \n");
        printf("1.Insert through Front\n");
        printf("2.Insert through Rear\n");
        printf("3.Delete through Front\n");
        printf("4.Delete through Rear\n");
        printf("5.Display DEQUE\n");
        printf("6.Exit Program\n");
        
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: F_Insert();
            break;
            case 2: R_Insert();
            break;
            case 3: F_Delete();
            break;
            case 4: R_Delete();
            break;
            case 5: Display();
            break;
            case 6:{
                    printf("\n   --> Exited the program\n");
                    exit(0);
                    }
            default:printf("\n   --> Invalid choice, Enter a valid choice\n");
        }
    
    }while(ch!=6);
}


void F_Insert()
{
    if(front==(rear+1)%size)
    {
        printf("\n   --> DEQUE Overflow, Cannot insert element\n");
    }
    
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        
        else if(front==0)
        {
            front=size-1;
        }
    
        else
        {
            front=front-1;
        }
        
        printf("\n   Enter the element to be inserted: ");
        scanf("%d",&DQ[front]);
    
        printf("\n   --> Element %d is inserted to the DEQUE through front\n", DQ[front]);
    }

}

void R_Insert()
{
    if(front==(rear+1)%size)
    {
        printf("\n   --> DEQUE Overflow, Cannot insert element\n");
    }
    
    else
    {
        if(front==-1)
        {
            front=front+1;
        }
    
        rear=(rear+1)%size;
        
        printf("\n   Enter the element to be inserted: ");
        scanf("%d",&DQ[rear]);
    
        printf("\n   --> Element %d is inserted to the DEQUE through rear\n", DQ[rear]);
    }

}

void F_Delete()
{
    int element;
    
    if(front==-1)
    {
        printf("\n   --> Queue Underflow, Cannot delete element\n");
    }
    
    else
    {
        element=DQ[front];
    
        if(front==rear)
        {
            front=rear=-1;
        }
        
        else 
        {
            front=(front+1)%size;
        }
            
        printf("\n   --> Element %d is deleted from the DEQUE through front\n",element);
    }

}

void R_Delete()
{
    int element;
    
    if(front==-1)
    {
        printf("\n   --> Queue Underflow, Cannot delete element\n");
    }
    
    else
    {
        element=DQ[rear];
        
        if(front==rear)
        {
            front=rear=-1;
        }

        else if(rear==0)
        {
            rear=size-1;
        }
    
        else
        {
            rear=rear-1;
        }
            
        printf("   --> Element %d is deleted from the DEQUE through rear\n",element);
    }

}

void Display()
{
    int t=front;
    
    if(front==-1)
    {
        printf ("\n   --> DEQUE is empty\n");
    }
    
    else
    {
        printf ("  Elements in the queue: \n");
        
        while(t!=rear)
        {
            printf("\t\t%d\n",DQ[t]);
            t=(t+1)%size;
        }
        printf("\t\t%d\n",DQ[t]);
        
    }
}
