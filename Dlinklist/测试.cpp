#include<stdlib.h>
#include<stdio.h>
#include"dlinklist.h"


typedef struct Value
{
	DLinkListNode node;
	int v;
}Value;
int main()
{
	
	int i = 0;
	DlinkList* list = DlinkList_Create();
	Value* pv = NULL;

	Value v1, v2, v3, v4, v5;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;

	DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));

	for (int i = 0; i < DLinkList_Length(list); i++)
	{
		pv = (Value*)DlinkList_Get(list, i);

		printf("%d\n", pv->v);
	}
	printf("\n");

	DlinkList_Delete(list, DLinkList_Length(list) - 1);
	DlinkList_Delete(list, 0);

	for (int i = 0; i < DLinkList_Length(list); i++)
	{
		pv = (Value*)DlinkList_Next(list);

		printf("%d\n", pv->v);
	}
	printf("\n");

	DlinkList_Reset(list); 
	DlinkList_Next(list);
	pv = (Value*)DlinkList_Current(list);
	//printf("%d\n", pv->v);

	DlinkList_DeleteNode(list, (DLinkListNode*)pv);
	pv = (Value*)DlinkList_Current(list);
	//printf("%d\n", pv->v);

	DlinkLinst_Pre(list);
	pv = (Value*)DlinkList_Current(list);
	//printf("%d\n", pv->v);

	printf("Length: %d\n", DLinkList_Length(list));

	DLinkList_Destory(list);
	
	return 0;
}