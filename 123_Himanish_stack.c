#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void view();

int ch, stack[10], top=-1, i, n, p, b,MAX;

int main()
{
	printf("\nEnter size of Array:\n");
	scanf("%d",&p);
	
	while(1)
	{
		printf("\n Select 1 for Push\n");
		printf("\n Select 2 for Pop\n");
		printf("\n Select 3 for View\n");
		printf("\n Select 4 for Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
			break;
			
			case 2: pop();
			break;
			
			case 3: view();
			break;
			
			case 4: exit(0);
			break;	
		}

	}
	
	}
void push()
{
	printf("\nEnter the value you want to push:\n");
		scanf("%d", &p);
		
	if(top==top-1)
	{
		printf("\nOverflow\n");
	}
	else
	{
		
		top++;
		
		stack[top]=p;
	}
}

void pop()
{
	if(top==-1)
		{
			printf("\nUnderflow\n");
		}
		else
		{
			b=stack[top];
			top--;
			
			printf("%d",b);
			
		}
}

void view()
{
	if(top==-1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nStack is...\n");
		for(i=top;i>=0;--i)
		printf("%d\n",stack[i]);
	}
	
}
