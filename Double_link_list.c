#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void dinsert(DListNode* before, element data);
void init(DListNode* phead);
void ddelete(DListNode* head, DListNode* removed);
void print_dlist(DListNode* phead);

int main()
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("add \n");
	for (int i = 0; i < 5; i++)
	{
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n delete \n");
	for (int i = 0; i < 5; i++)
	{
		print_dlist(head);
		ddelete(head, head->rlink);
	}

	free(head);
	return 1;
}

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("<-| |%d | |->", p->data);
	}
	printf("\n");
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head)
		return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	// strcpy(newnode->data = data);
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	
	before->rlink->llink = newnode;
	before->rlink = newnode;

}