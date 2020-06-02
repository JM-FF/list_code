#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"linklist.h"

typedef struct _tag_LinlList
{
	LinkListNode header;
	int length;
}TLinkList;


LinkList* LinkList_Create()
{
	TLinkList *ret = NULL;

	ret = (TLinkList*)malloc(sizeof(TLinkList));
	memset(ret, 0, sizeof(TLinkList));
	ret->length = 0;
	ret->header.next = NULL;

	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}
//让链表回到初始状态
void LinkList_Clear(LinkList* list)
{
	TLinkList *ret = NULL;

	if (list == NULL)
	{
		return;
	}
	ret = (TLinkList*)list;
	ret->length = 0;
	ret->header.next = NULL;
	return;

}

int LinkList_Length(LinkList* list)
{
	TLinkList *ret = NULL;

	if (list == NULL)
	{
		return -1;
	}
	ret = (TLinkList*)list;
	return ret->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList *ret = NULL;
	LinkListNode* current = NULL;

	if (list == NULL||node ==NULL||pos<0)
	{
		return -1;
	}
	ret = (TLinkList*)list;
	current = &(ret->header);

	for (int i = 0; i < pos&&(current->next!=NULL); i++)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	ret->length++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	TLinkList *ret = NULL;
	LinkListNode* current = NULL;

	if (list == NULL || pos<0)
	{
		return NULL;
	}
	ret = (TLinkList*)list;
	current = &(ret->header);

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList *ret = NULL;
	LinkListNode* current = NULL;
	LinkListNode* tmp = NULL;

	if (list == NULL || pos<0)
	{
		return NULL;
	}
	ret = (TLinkList*)list;
	current = &(ret->header);

	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
		/*if (current->next = NULL)
		{
			tmp = current;
			current = NULL;
			return tmp;
		}*/
	}
	tmp = current->next;
	current->next = tmp->next;
	ret->length--;

	return tmp;
	
}