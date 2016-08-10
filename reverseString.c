#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX_STRING_SIZE 10
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

void ReverseString(char *str)
{
	int stringlength=strlen(str);

	struct stack *stack = createstack(stringlength);

	for(int i=0;i<stringlength;i++)
		push(stack,str[i]);

	for(int i=0;i<stringlength;i++)
		str[i]=pop(stack);
}

int main()
{
	char string[MAX_STRING_SIZE];
	printf("Enter the string to be reversed\n");
	scanf("%s",string);		

	ReverseString(string);

	printf("the string after reversing is %s\n",string);



}