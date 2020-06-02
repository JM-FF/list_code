#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_
typedef void DlinkList;

typedef struct _tag_DLinkListNode
{
	_tag_DLinkListNode* next;
	_tag_DLinkListNode* pre;
}DLinkListNode;

DlinkList* DlinkList_Create();

void DLinkList_Destory(DlinkList* list);

void DLinkList_Clear(DlinkList* list);

int DLinkList_Length(DlinkList* list);

int DLinkList_Insert(DlinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DlinkList_Get(DlinkList* list, int pos);

DLinkListNode* DlinkList_Delete(DlinkList* list, int pos);

//增加方便上层使用的业务函数
DLinkListNode* DlinkList_DeleteNode(DlinkList* list, DLinkListNode * node);

DLinkListNode* DlinkList_Reset(DlinkList* list);   //重置游标

DLinkListNode* DlinkList_Current(DlinkList* list); //获得游标的元素

DLinkListNode* DlinkList_Next(DlinkList* list);  //游标后移

DLinkListNode* DlinkLinst_Pre(DlinkList* list);  //游标前移


#endif