#include<stdlib.h>
#include<stdio.h>
#include"dlinklist.h"


typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}TDLinkList;

DlinkList* DlinkList_Create()
{
	TDLinkList *ret = (TDLinkList*)malloc(sizeof(TDLinkList));

	if (ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}

	return ret;
}

void DLinkList_Destory(DlinkList* list)
{
	if (list != NULL)
	{
		free(list);
	}
}

void DLinkList_Clear(DlinkList* list)
{
	TDLinkList*slist = (TDLinkList*)list;

	if (slist != NULL)
	{
		slist->length = 0;
		slist->header.next = NULL;
		slist->header.pre = NULL;
		slist->slider = NULL;
	}
	return ;
}

int DLinkList_Length(DlinkList* list)
{
	TDLinkList*slist = (TDLinkList*)list;
	int ret = -1;
	if (slist != NULL)
	{
		ret = slist->length;
	}
	return ret;
}

int DLinkList_Insert(DlinkList* list, DLinkListNode* node, int pos)
{
	TDLinkList*slist = (TDLinkList*)list;
	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	DLinkListNode* current = (DLinkListNode*)slist;   //定义DLinkListNode类型指针进行遍历寻找node
	DLinkListNode* next = NULL;  //需要增加next指针

	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}
	next = current->next;
	//-----------------------------
	current->next = node;
	node->next = next;
	//-------------------------
	if (next != NULL)
	{
		next->pre = node;
	}
	node->pre = current;
	//--------------------------------
	if (slist->length == 0)
	{
		slist->slider = node;  //如果是第一个节点处理游标
	}
	//--------------------------------
	//处理插入0号位置
	if (current == (DLinkListNode*)slist)
	{
		node->pre = NULL;
	}

	slist->length++;

	return 0;
}

DLinkListNode* DlinkList_Get(DlinkList* list, int pos)
{
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if ((slist != NULL) && (pos >= 0) && (pos < slist->length))
	{
		DLinkListNode* current = (DLinkListNode*)slist;
		for (int i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
	}

	return ret;
}

DLinkListNode* DlinkList_Delete(DlinkList* list, int pos)
{
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (slist == NULL || pos < 0)
	{
		return NULL;
	}
	DLinkListNode* current = (DLinkListNode*)slist;
	DLinkListNode* next = NULL;
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	ret = current->next;
	next = current->next->next;

	current->next = next;

	if (next != NULL)
	{
		next->pre = current;
		if (current == (DLinkListNode*)slist)
		{
			next->pre = NULL;
		}
	}
	if (slist->slider == ret)
	{
		slist->slider = next;
	}

	slist->length--;

	return ret;
}

//增加方便上层使用的业务函数
DLinkListNode* DlinkList_DeleteNode(DlinkList* list, DLinkListNode * node)
{
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	if (slist != NULL)
	{
		DLinkListNode* current = (DLinkListNode*)slist;
		for (i = 0; i < slist->length; i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}
		if (ret!=NULL)
			DlinkList_Delete(list, i);
	}

	return ret;
}

DLinkListNode* DlinkList_Reset(DlinkList* list)
{
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if (slist != NULL)
	{
		slist->slider = slist->header.next;
		ret = slist->slider;
	}
	return ret;
}

DLinkListNode* DlinkList_Current(DlinkList* list)
{
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if (slist != NULL)
	{
		ret = slist->slider;
	}
	return ret;
}

DLinkListNode* DlinkList_Next(DlinkList* list)
{
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if (slist != NULL&&slist->slider!=NULL)
	{
		ret = slist->slider;
		slist->slider = ret->next;
	}
	return ret;
}

DLinkListNode* DlinkLinst_Pre(DlinkList* list)
{
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if (slist != NULL&&slist->slider != NULL)
	{
		ret = slist->slider;
		slist->slider = ret->pre;
	}
	return ret;
}