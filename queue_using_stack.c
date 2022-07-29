#include<stdio.h>
#include<stdlib.h>

#define size 10  //size of stack is initialized to 10

void enque();
void deque();
void display();

int s1[size],s2[size],ch,top1,top2,count1,count2;

void main()
{
    top1=-1,top2=-1;
    count1=0,count2=0;
    
    printf("\tImplementation of Queue Using Stack\n");

    do{
        printf("\nQueue Operations: \n");
        printf("1.Enque\n");
        printf("2.Deque\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("\nEnter your choice: ");
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
            
            default:printf("\n   --> Invalid choice, Enter a valid choice\n");
        }
    
    }while(ch!=4);
}


void enque()
{
    int element;
    
    if((count1+count2)>=size || top1==size-1)
        printf("\n   --> Queue Overflow, Cannot insert element\n");

    else
    {
        printf("\n   Enter the element to be inserted: ");
        scanf("%d",&element);

        top1++;
        s1[top1]=element;
        
        printf("\n   --> Element %d is inserted into the queue\n",element);
        count1++;
    }
    
}

void deque()
{
    int element;
    
    if(top2==-1&&top1==-1)
        printf("\n   --> Queue Underflow, Cannot delete element\n");
    
    else
    {
        if(top2==-1)
        {
            while(top1!=-1)
            {
                top2++;
                s2[top2]=s1[top1];
                top1--;
                count1--;
                count2++;
            }
            
            element=s2[top2];
            top2--;
            count2--;
            
            printf("\n   --> Element %d is deleted from the queue\n",element);
        }
        
        else if(top2!=-1)
        {
            if(top2>=0)
            {
                element=s2[top2];
                top2--;
                count2--;
                
                printf("\n   --> Element %d is deleted from the queue\n",element);
            }
        }
    }
    
}

void display()
{
    if(top1==-1&&top2==-1)
        printf("\n   --> Queue is empty\n");
    
    else
    {
        printf("\n   Elements in the queue:  ");
        int t=top2;
        
        while(t>=0)
        {
            printf("%d ",s2[t]);
            t--;    
        }
        
        t=0;
        int t1=top1;
        
        while(t<=top1)
        {
            printf(" %d ",s1[t]);
            t++;    
        }
    }
    
    printf("\n");   
}
