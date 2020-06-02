#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"linklist.h"

typedef struct Teacher
{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;

int main01()
{
	int len = 0,ret = 0;
	Teacher t1, t2, t3;
	t1.age = 1;
	t2.age = 2;
	t3.age = 3;

	t1.name;

	LinkList *list = NULL;
	list = LinkList_Create();

	if (list == NULL)
	{
		return -1;
	}

	len = LinkList_Length(list);

	ret = LinkList_Insert(list, (LinkListNode*)&t1, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t2, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t3, 0);


	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teacher* tmp = (Teacher*)LinkList_Get(list, i);
		if (tmp == NULL)
		{
			return -1;
		}
		printf("tmp->age: %d", tmp->age);

	}

	while (LinkList_Length(list) >0)
	{
		LinkList_Delete(list, 0);
	}
	LinkList_Destroy(list);
	/*LinkListNode* LinkList_Create();

	void LinkList_Destroy(LinkList* list);

	void LinkList_Clear(LinkList* list);

	int LinkList_Length(LinkList* list);

	int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

	LinkListNode* LinkList_Get(LinkList* list, int pos);

	LinkListNode* LinkList_Delete(LinkList* list, int pos);*/

	return 0;
}
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
//class Solution
//{
//public:
//	int maxSubArray(vector<int> &nums)
//	{
//		int size = nums.size();
//		for (int i = 1; i < size; i++)
//		{
//			if (nums[i - 1]>0)
//				nums[i] += nums[i - 1];
//		}
//
//		return *max_element(nums.begin(), nums.end());
//	}
//};
//
//
//int main()
//{
//	Solution s1;
//	int m = 0;
//	vector<int> nums = {3,4,5,6,7,8,-1,-6};
//
//	m = s1.maxSubArray(nums);
//	cout << m << endl;
//
//
//	return 0;
//
//}

