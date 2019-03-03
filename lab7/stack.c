#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include "stack.h"

stack* createStack()
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->arr = (int*)malloc(sizeof(int)*100);
	s->capacity = 100;
	s->top = 0;
	return s;

}

int isEmpty(stack* s)
{
	if(s->top == 0)
		return 1;
	return 0;
}

int isFull(stack* s)
{
	if(s->top == s->capacity)
		return 1;
	return 0;	

}
void push(stack* s, int ele)
{
	if(isFull(s))
		s->arr = realloc(s, s->capacity*2);
		
	s->arr[s->top] = ele;
	s->top+=1;

}
int peek(stack* s)
{	
	if(!isEmpty(s))
		return s->arr[s->top-1];
	return INT_MIN;	
}
int pop(stack* s)
{
	if(!isEmpty(s))
	{
		s->top--;
		return s->arr[s->top];
	}
	return INT_MIN;

}

