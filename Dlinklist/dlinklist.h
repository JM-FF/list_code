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

//���ӷ����ϲ�ʹ�õ�ҵ����
DLinkListNode* DlinkList_DeleteNode(DlinkList* list, DLinkListNode * node);

DLinkListNode* DlinkList_Reset(DlinkList* list);   //�����α�

DLinkListNode* DlinkList_Current(DlinkList* list); //����α��Ԫ��

DLinkListNode* DlinkList_Next(DlinkList* list);  //�α����

DLinkListNode* DlinkLinst_Pre(DlinkList* list);  //�α�ǰ��


#endif