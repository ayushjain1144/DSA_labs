#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dnstree.h"

Tree* createTree(void)
{
	Tree* t1 = (Tree*)malloc(sizeof(Tree));
	
	t1->head = (Node*)malloc(sizeof(Node));
	(t1->head)->name = NULL;
	(t1->head)->child = NULL;
	(t1->head)->sibling = NULL;
	
	return t1;

}

char* strrev(char* s)
{
	int len = strlen(s);
	char* s1 = (char*)malloc(sizeof(char)*len);
	
	for(int i = 0; i < len; i++)
	{
		s1[i] = s[len - 1 - i];
	}
	
	s1[len] = '\0';
	
	return s1;
}

Node* ret_sibling(Node* head, char* temp)
{
	
	head = head->child;
	while(head != NULL)
	{
		if(strcmp(head->name, temp) == 0)
			return head;
		head = head->sibling;	
	}
	
	return NULL;
		

}

Node* insertNode(Node* head, char* temp1)
{

	Node* temp_parent;
	temp_parent = ret_sibling(head, temp1);
	
	
	if(temp_parent != NULL)
		{
			head = temp_parent->child;
			return head;
		}
		
		else
		{
			Node* data = (Node*)malloc(sizeof(Node));
			data->name = temp1;
			data->sibling = NULL;
			data->child = NULL;
			
			//if first node
			
			if(head->child == NULL)
			{
				head->child = data;
				head = head->child;
				return head;
			}
			
			else
			{
				head = head->child;
				while(head->sibling !=  NULL)
				{
					head = head->sibling;
				}
				
				head->sibling = data;
				head = head->sibling;
				return head;
			
			}
		}
	
	
	

}


Tree* insertTree(Tree* t1, char* dnsname, char* ip)
{
	char arr[] = ".";
	char* temp = (char*)malloc(sizeof(char) * strlen(dnsname));
	strcpy(temp, dnsname);
	temp = strrev(temp);
	
	
	
	char* loc = strstr(temp, arr);
	
	Node* head = t1->head;
	Node* temp_parent;
	while(loc != NULL)
	{
		*loc  = '\0';
		char* temp1 = strrev(temp);
		head = insertNode(head, temp1);
		
		loc++;
		temp = loc;
		
		loc = strstr(temp, arr);
		
	
	}
	
	strcpy(temp, dnsname);
	loc = strstr(temp, arr);
	*loc = '\0';
	
	head = insertNode(head, temp);
	
	head = insertNode(head, ip);
	
	
	
	return t1;
	
}

void readdata(Tree* t1, int n)
{
	for(int i = 0; i < n; i++)
	{
		char* dnsname = (char*)malloc(sizeof(char)*100);
		char* ip = (char*)malloc(sizeof(char)* 20);
		
		scanf("%s %s", dnsname, ip);
		//getchar();
		
		t1 = insertTree(t1, dnsname, ip);
	
	}

}

void printlist(Node* head)
{
	Node* temp = head;
	
	while(temp != NULL)
	{
		printf("%s ", temp->name);
		temp = temp->sibling;
	
	}
	
	//printf("\n");


}

void printtree(Node* temp)
{
	
	
	if(temp == NULL)
		return;
	
	/*
	while(temp != NULL)
	{
		//printlist(temp);
		
		Node* temp1 = temp;
		while(temp1 != NULL)
		{
			//printlist(temp1);
			printf("%s ", temp1->name);
			temp1 = temp1->child;
		
		}
		
		//printlist(temp->child);
		
		
		
		temp = temp->sibling;
		
		printf("\n");
		
	}
		
		
		while(temp != NULL)
		{
			printf("%s\n", temp->name);
			temp = temp->child;
		}
		
		
		
		*/
		while(temp != NULL)
		{
			printf("%s ", temp->name);
			printtree(temp->child);
			temp = temp->sibling;
		
		}
	
	
	
	
	

}


void lookup(Tree* t1, char* str)
{
	char arr_b[] = ".";
	char* temp = (char*)malloc(sizeof(char) * strlen(str));
	strcpy(temp, str);
	temp = strrev(temp);
	
	
	
	char* loc = strstr(temp, arr_b);
	
	Node* head = t1->head;
	Node* temp_parent;
	int arr[10];
	int count =  0;
	while(loc != NULL)
	{
		*loc  = '\0';
		char* temp1 = strrev(temp);
		
		head = head->child;
		int j = 0;
		while(head != NULL)
		{
			if(strcmp(head->name, temp1) == 0)
				break;
				
			head = head->sibling;
			j++;
		}
		
		if(head == NULL)
		{
			for(int i = 0; i < count; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
		else
		{
			arr[count] = j;
			count++;
			
		}
		
		loc++;
		temp = loc;
		
		loc = strstr(temp, arr_b);
		
	
	}
	
	strcpy(temp, str);
	loc = strstr(temp, arr_b);
	*loc = '\0';
	int j = 0;
	head = head->child;
	while(head != NULL)
	{
			if(strcmp(head->name, temp) == 0)
				break;
			head = head->sibling;
			j++;	
	}
	if(head != NULL)
	{
		printf("%s\n", (head->child)->name);
	}
	
	else
	{
		for(int i = 0; i < count; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	
	}
	
	


}

