#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
	int top;
	unsigned capacity;
	int *array;
};

struct stack *createstack(unsigned capacity)
{
	struct stack *stack =(struct stack *)malloc(sizeof(struct stack));
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int *)malloc(capacity*sizeof(int));
	return(stack);

}

int isFull(struct stack *stack)
{
	return stack->top == stack->capacity -1;
}

int isEmpty(struct stack *stack)
{
	return stack->top == -1;
}

void push(struct stack *stack,int ele)
{
	if(isFull(stack))
	{
		printf("over flow\n");
		return;
	}
	stack->array[++stack->top]=ele;
	//printf("%d is the pushed element\n",stack->array[stack->top] );
}

void  pop(struct stack *stack)
{
	if(isEmpty(stack))
	{
		printf("no elements to pop\n");
		return;
	}	
	 stack->array[stack->top--];
}

void traverse(struct stack *stack)
{
	if(isEmpty(stack))
	{
		printf("no elements to print\n");
		return;
	}
	printf("******TRAVERSE*******\n");
	for(int i=0;i<=stack->top;i++)
		printf("\n the %d element is %d ",i+1,stack->array[i]);
	printf("\n");
}
int main()
{	int a;int ele;
	struct stack *stack=createstack(100);
	do{
		printf("entert the option\n");
		printf(" 1: for insertion(PUSH)\n");
		printf(" 2: for deleion  (POP) \n");
		printf(" 3: for traversing\n");
		printf(" 0: for quiting\n");	
		scanf("%d",&a);


		switch (a)
		{
			case 1: printf("enter the data to be pushed\n");
					scanf("%d",&ele);
					push(stack,ele);
					break;
			case 2: pop(stack);
					break;
			case 3: traverse(stack);
					break;
			default:printf("enter a valid option\n");		
		}


	}while(a!=0);
	return 0;

}
