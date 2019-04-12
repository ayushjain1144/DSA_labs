#ifndef _DNSTREE
#define _DNSTREE

typedef struct node
{
	char* name;
	struct node* child;
	struct node* sibling;

}Node;

typedef struct tree
{
	Node* head;
}Tree;

Tree* insertTree(Tree* t1, char* dnsname, char* ip);
Node* ret_sibling(Node* head, char* temp);
char* strrev(char* s);
Tree* createTree(void);
Node* insertNode(Node* head, char* temp1);
void readdata(Tree* t1, int n);
void printtree(Node* t1);
void printlist(Node* head);
void lookup(Tree* t1, char* str);

#endif
