#include<stdio.h>
#include<stdlib.h>

#define size 10  //size of priority queue is initialized to 10

void enque();   //function to insert element into queue
void deque();   //function to delete element from queue
void display(); //function to display contents of queue

int PQ_VAL[size],PQ_PRI[size],ch,front,rear;

void main()
{
    front=rear=-1;
    
    printf("\tPriority Queue Implementation\n");
    
    printf("\nSize of priority queue is initialized to %d\n",size);
    
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
    if(front==0 && rear==size-1)
        printf("\n   --> Queue overflow, Cannot insert element\n");
    
    else
    {
        int i,element,priority;
        
        printf("\n   Enter the element to be inserted: ");
        scanf("%d",&element);
        printf("   Enter the priority of %d: ",element);
        scanf("%d",&priority);
        
        if(front==-1)
        {
            front=rear=0;
            
            PQ_VAL[rear]=element;
            PQ_PRI[rear]=priority;
            
            printf("\n   --> Element %d of priority %d is inserted to the queue\n",element,priority);
        }
        
        else
        {
            if(rear==size-1)
            {
                for(i=front;i<=rear;i++)
                {
                    PQ_VAL[i-front]=PQ_VAL[i];
                    PQ_PRI[i-front]=PQ_PRI[i];
                }
                
                rear=rear-front;
                front=0;
            }
            
            for(i=rear;i>=front;i--)
            {
                if(priority<PQ_PRI[i])
                {
                    PQ_VAL[i+1]=PQ_VAL[i];
                    PQ_PRI[i+1]=PQ_PRI[i];
                
                }
                
                else
                    break;
                    
            }
            
            PQ_VAL[i+1]=element;
            PQ_PRI[i+1]=priority;
            rear=rear+1;    
            
            printf("\n   --> Element %d of priority %d is inserted to the queue\n",element,priority);  
        }
    }
}

void deque()
{
    if(front==-1)
        printf("\n   --> Queue underflow, Cannot delete element\n");
    
    else
    {
        int element=PQ_VAL[front];
        int priority=PQ_PRI[front];
        
        if(front==rear)
            front=rear=-1;
            
        else
            front=front+1;
        
        printf("\n   --> Element %d of priority %d is deleted from queue\n",element,priority);
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
        printf("\n   Elements in queue with their respective priorities: \n\n");
        printf("\tPriority\tElement\n");
        
        while(t!=rear)
        {
            printf("\t    %d\t\t  %d\n",PQ_PRI[t],PQ_VAL[t]);
            t=t+1;
        }
        printf("\t    %d\t\t  %d\n",PQ_PRI[t],PQ_VAL[t]);
    }
}
