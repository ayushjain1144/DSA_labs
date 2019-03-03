#ifndef _STACK
#define _STACK

typedef struct stack
{
	int* arr;
	int capacity;
	int top;
}stack;

stack* createStack();
int isEmpty(stack* s);
int isFull(stack* s);
void push(stack* s, int ele);
int peek(stack* s);
int pop(stack* s);

#endif
