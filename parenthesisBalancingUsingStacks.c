#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define STR_MAX_SIZE 10
#include <stdbool.h>

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

int  pop(struct stack *stack)
{
	if(isEmpty(stack))
	{
		printf("no elements to pop\n");
		return INT_MIN;
	}	
	 return stack->array[stack->top--];
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


bool isMatchingPair(char character1, char character2)
{
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;//0 in bool is false
}


bool areParenthesisBalanced(struct stack *stack,char str[])
{

	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]=='{'||str[i]=='('||str[i]=='[')
			push(stack,str[i]);

		if(str[i]=='}'||str[i]==')'||str[i]==']')
		{
			if(isEmpty(stack)==1)
			{
				printf("stack is empty ,no open parenthesis to compare with\n");
				return 0; //This return is only for while loop
			}
			else if(isMatchingPair(pop(stack),str[i]) == false)
				return 0;

		
		}	
		i++;	
	}

	if(isEmpty(stack)==1)
		return 1;
	else
		return 0;



}


int main()
{	int a;int ele;
	struct stack *stack=createstack(100);
	
	char str[STR_MAX_SIZE];
	printf("enter the string of parenthesis\n" );
	scanf("%s",str);

	if(areParenthesisBalanced(stack,str) == true)
		printf("balanced\n");
	else
		printf("not balanced\n");
		
			return 0;

}
