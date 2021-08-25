#include<stdio.h>//Header file for standard input and output(printf, scanf)
#include<stdlib.h>//Header file for standard library used to allocate memory(malloc function)
void enqueue();//Function prototype
void dequeue();//Function prototype
void view();//Function prototype
int count=0;//VAriable declaration
typedef struct linkedlist//Node structure
{
    int data;//Data of the node
    struct linkedlist *next;//Address of the next node
}node;//Structure variable
node *front=NULL;//As the queue is empty so therefore front=null
node *rear=NULL;//Same with the last as above
int main()
{
    int choice;
    printf("Welcome\n");
    do
    {
        printf("Main Menu\n");
        printf("Press 1 to enqueue\n");
        printf("Press 2 to dequeue\n");
        printf("Press 3 to view the queue\n");
        printf("Press 4 to exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                view();
                break;  

            case 4:
                printf("Thanks Visit Again\n");
                break;

            default:
                printf("Enter a valid input(1/2/3)\n"); 

        }


    }while(choice!=4);
}

void enqueue()//Enqueue Function definition
{
    node *ptr;//Ptr node declaration
    ptr=(node*) malloc(sizeof(node));//Memory allocation of ptr node

    if (ptr==NULL)//if the memory is not allocated in the ram then pointer ptr will return null
    {
        printf("Oops! can't enqueue.....Memory not available\n");
    }

    printf("Enter the element\n");
    scanf("%d",&ptr->data);//Entering data in the node
    ptr->next=NULL;//Initialising next of ptr to null

    if (front==NULL && rear==NULL)//if queue is empty
    {
        front=ptr;//front will be equal to ptr as its the first node
        rear=ptr;//last will be equal to ptr as its the first node
        printf("%d enqueued\n",ptr->data);
        count++;
    }
    else
    {
        rear->next=ptr;//as in queue we can only insert from rear
                      //so therefore inserting from last
        rear=ptr;//updating rear
        printf("%d enqueued\n",ptr->data);
        count++;
    }
    printf("rear=%d\n",rear->data);
}

void dequeue()//dequeue function definition
{
    node *temp;//temporary node declaration
    if (front==NULL && rear==NULL)//If list is empty
    {
        printf("Oops! can't dequeue.....Queue is empty\n");
    }
    else
    {
       temp=front;//else as we know that we can only dequeue list from last
       front=front->next;//front will point to the next element to dequeue 1st element
       printf("%d is dequeued\n",temp->data);
       free(temp);//deallocating the memory as the node is deleted
       count--;
    }
    printf("Total Elements=%d\n",count);
     printf("rear=%d\n",rear->data);
}

void view()
{
    node *temp;//temporary node declaration
    if (front==NULL && rear==NULL)//if the list is empty
    {
        printf("Oops! can't dequeue.....Queue is empty\n");
    }
    else
    {
        temp=front;
        while(temp!=NULL)//treversing the queue
        {
            printf("%d\t",temp->data);//printing the elements in the queue
            temp=temp->next;
        }
        printf("\nTotal elements=%d\n",count);
        printf("rear=%d\n",rear->data);
    }
}
