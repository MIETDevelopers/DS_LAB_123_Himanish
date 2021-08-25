#include<stdio.h>//header file to include standard input output functions
#include<stdlib.h>//header file which include functions involving memory allocation in this program


int count=0;// VAriable declaration


void push();//function prototype
void pop();
void view();
typedef struct linkedlist //structure of the node
{
	int data;//Data Part of the node
	struct linkedlist *next;// Address of the next node to be linked
}node;


node *head=NULL;//structure variable
int main()
{
	int choice;//variable declaration


	printf("(:  Welcome  :)\n");
  do{
  	printf("Main Menu\n");
	printf("Press 1 to push\n");// menu to display in the program
	printf("Press 2 to pop\n");
	printf("Press 3 to View\n");
	printf("Press 4 to exit\n");
	scanf("%d", &choice);

	switch(choice)//switch case for the menu
	{
		case 1:
			 push();
			 break;

		case 2:
			pop();
			break;

		case 3:
		 	view();
		 	break;

		 case 4:
		 	printf("Thanks visit again\n");	
		 	break;

		 default:
		 	printf("Wrong input entered\n");	

				
	}
}while(choice!=4);
return 0;

}

void push()// push function definition
{
	node *ptr;//Structure variable decleration
	ptr=(node*) malloc(sizeof(node));//Memory allocation for ptr pointer


	if (ptr==NULL)// if ptr pointer returns NULL it means that there is no space in the ram
	{
		printf("Stack overflow\n");
	}


	printf("Enter the element\n");//Asking user to enter the element
	scanf("%d",&ptr->data);
	ptr->next=NULL;//initialising next of ptr with null

	if (head==NULL)// if stack is empty
	{
		head=ptr;//head will store the address of ptr
		count++;//increment count by 1 as we have pushed an element in the stack
		printf("Element pushed\n");
	}


	else
	{
		ptr->next=head;
		head=ptr;
		printf("Element pushed\n");
		count++;
	}
	printf("Total Elements=%d\n",count);//printing total elements left
}


void pop()// pop function definition
{

	node *temp;
	if (head==NULL)//This is the condition if the stack is empty
	{
		printf("Stack underflow\n");
	}


	else 
	{
		temp=head;//Assigning the value of head to a temporery variable


		head=head->next;//As in stack we have to delete from the beginning so assigning head to the second element of the list


		printf("%d is popped\n",temp->data);
		count--;//Decrease r=the count as we have removed an element

		
		free(temp);//deallocating the space of the element deleted 
	}
}

void view()//View  function definition
{
	node *temp;
	if (head==NULL)//If the list is empty
	{
		printf("Stack underflow\n");
	}
	temp=head;//Assigning head to a temporary variable to treverse the list
	while(temp!=NULL)//Treversing the linked list to access every element of the satck
	{
		printf("%d\n",temp->data);//Printing the element
		temp=temp->next;
	}
	printf("Total elements=%d\n",count);//Printing total elements in the stack
}
