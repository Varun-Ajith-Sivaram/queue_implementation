#include<stdio.h>

#define size 10 //size of queue is initialized to 10

int queue[size],front,rear,ch;
 
 void enque();    //function to insert element to queue
 void deque();    //function to delete element from queue
 void peek();     //function to display the element in front of queue
 void display();  //function to display elements in queue
 
 void main()
 {
      printf("\tImplmentation of queue using arrays\n");
      printf("\n   Size of queue: %d\n",size);
      
      front= -1;
      rear=-1;
    
        do{
            printf("\n\tPossible operations on queue: \n");
            printf("\t\t  1.Enque\n");
            printf("\t\t  2.Deque\n");
            printf("\t\t  3.Peek\n");
            printf("\t\t  4.Display\n");
            printf("\t\t  5.Exit\n");
            
            printf("\n\tEnter the choice: ");
            scanf("%d", &ch);
            printf("\n");
          
              switch (ch)
              {
                case 1: enque();
	                    break;
                case 2: deque();
                        break;
                case 3: peek();
                        break;
                case 4: display();
	                    break;
                case 5:
	                {
	                printf("\t  --> Exited from queue program!!\n");
	                break;
	                }
                default:
	                printf("  --> Wrong Choice, Enter a valid choice!!\n");
              }
         
          }while (ch != 5);
   }
    

void enque()
{
    if(rear==size - 1)
        {
            printf("   Queue Overflow--Cannot insert element!!\n");
            return;
        }
  
    else if(front==-1)
        {
            front=0;
        }
            rear++;
            printf("  Enter the element to be inserted: ");
            scanf("%d",&queue[rear]);
            printf("   --> Element %d is inserted to the queue\n", queue[rear]);
}

void deque()
{
    if (front==-1)
        {
            printf("   Queue Underflow--Cannot delete element!!\n");
        }
   
    else if(front==rear)
        {
            printf("   --> Element %d is deleted from the queue\n", queue[front]);
            front=-1;
            rear=-1;
        }
    
    else
        {
            printf("   --> Element %d is deleted from the queue\n", queue[front]);
            front++;
        }
}

void peek()
{
    if(front==-1)
      printf ("  --> Queue is empty!!\n");

    else
      printf ("   -->Element in front: %d\n",queue[front]);
    
}


void display()
{
    int t;
    
    if (front==-1)
        {
            printf ("  --> Queue is empty!!\n");
        }
    
    else
        {
            t = front;
            printf ("  Elements in the queue: \n");
               
              while (t<=rear)
                  {
                    printf ("\t\t%d\n", queue[t]);
                    t++;
                  }
        }
}
