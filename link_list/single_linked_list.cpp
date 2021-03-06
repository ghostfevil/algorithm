// link_list.cpp
#include "pch.h"
#include "single_linked_list.h"

using namespace alg;

/***
创建链表
***/
ListNode* LinkedList::createLinkedList(int arr[], int n)
{
	if (n == 0)
	{
		return NULL;
	}
	ListNode *head = new ListNode(arr[0]);
	ListNode *curNode = head;
	for (int i = 1; i < n; i++)
	{
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;				//关键代码 curNode起到承上启下的作用
	}
	return head;
};

/*****
反转链表
**/
ListNode* LinkedList::reverseLinkedList(ListNode *head)
{

	ListNode *preNode = NULL;
	ListNode *curNode = head;

	while (curNode!=NULL)
	{
		//改变指针方向
		ListNode *nextNode = curNode->next;
		curNode->next = preNode;					//反转方向
		preNode = curNode;
		curNode = nextNode;
	
	}

	//preNode将会是链表第一个节点
	return preNode;

};

/**
移除值为val的所有节点
**/
ListNode* LinkedList::removeElements(ListNode *head, int val)
{
	//链表头虚拟一个头节点，方便循环
	ListNode *dummyHead = new ListNode(-1);
	dummyHead->next = head;

	ListNode *cur = dummyHead;
	while (cur->next!=NULL)
	{
		if (cur->next->val == val)
		{
			ListNode *delNode = cur->next;
			cur->next = delNode->next;		//关键代码
			delete delNode;
		}
		else
		{
			cur = cur->next;
		}

	}

	//还原链表头
	ListNode *returnNode = dummyHead->next;
	delete dummyHead;
	return returnNode;

};
/****
合并两个有序链表
****/
ListNode* LinkedList::mergeLists(ListNode *a, ListNode *b)
{

	if (a == NULL)
	{
		return b;
	}
	else if (b == NULL)
	{
		return a;
	}

	ListNode *mergeHead = NULL;
	if (a->val < b->val)
	{
		mergeHead = a;
		mergeHead->next = mergeLists(mergeHead->next, b);
	}
	else
	{
		mergeHead = b;
		mergeHead->next = mergeLists(a, mergeHead->next);
	}

	return mergeHead;
};
/***************
找到两个链表的交点
***************/
ListNode* LinkedList::findIntersectionNode(ListNode *a, ListNode *b)
{

	int lengthA = calculateLength(a);
	int lengthB = calculateLength(b);

	ListNode *pa = a;
	ListNode *pb = b;

	int n = lengthA - lengthB;
	for (int i = 0; i <abs(n); ++i)
	{

		if (n > 0)
		{
			pa = pa->next;
		}
		else
		{
			pb = pb->next;
		}

	}

	while (pa && pb)
	{

		if (pa->val == pb->val)
			return pb;

		pa = pa->next;
		pb = pb->next;
	}

	return NULL;

};

/***
找到倒数第n个节点
****/
ListNode* LinkedList::findKthNodeToTail(ListNode *head, unsigned k)
{
	if (head == NULL || k == 0)
	{
		return NULL;
	}

	ListNode *aheadNode = head;
	ListNode *behindNode = NULL;

	for (int i = 0; i < k - 1; ++i)
	{
		if (aheadNode->next != NULL)
			aheadNode = aheadNode->next;
		else
		{
			std::cout << "k is out of range" << std::endl;
			return NULL;
		}
			
	}

	behindNode = head;

	while (aheadNode->next !=NULL)
	{
		aheadNode = aheadNode->next;
		behindNode = behindNode->next;
	}

	return behindNode;

}

/******
移除倒数第n个节点
*******/
ListNode* LinkedList::removeNthFromEnd(ListNode *head, int n)
{

	if (head == NULL && head->next == NULL)
	{
		return NULL;
	}
	ListNode *aheadNode = head;
	ListNode *behindNode = head;

	for (int i = 0; i < n; ++i)
	{
		aheadNode = aheadNode->next;
	}

	if (aheadNode == NULL)
		return head->next;

	while (aheadNode->next!=NULL)
	{
		aheadNode = aheadNode->next;
		behindNode = behindNode->next;
	}

	behindNode->next = behindNode->next->next;

	return head;

}

/*****
移除所有重复的节点
*******/
ListNode* LinkedList::deleteAllDuplicates(ListNode* head)
{
	if (head == NULL)
		return NULL;
	ListNode *fakeHead = new ListNode(0);
	fakeHead->next = head;
	ListNode *pre = fakeHead;
	ListNode *cur = head;

	while (cur!=NULL)
	{
		while (cur->next != NULL && cur->val == cur->next->val)
		{
			cur = cur->next;
		}
		if (pre->next == cur)
		{
			pre = pre->next;
		}
		else
		{
			pre->next = cur->next;
		}
		pre->next = cur->next;
	}
	return fakeHead->next;
}

bool LinkedList::hasCircle(ListNode *head)
{

	ListNode *slowerNode = head;
	ListNode *fasterNode = head;

	while (slowerNode->next!=NULL && fasterNode->next!=NULL &&fasterNode->next->next!=NULL)
	{
		slowerNode = slowerNode->next;
		fasterNode = fasterNode->next->next;

		if (slowerNode == fasterNode)
		{
			return true;
		}

	}
	return false;

}

void LinkedList::deleteNode(ListNode *node)
{
	if (node == NULL || node->next == NULL)
		return;
	node->val = node->next->val;
	node->next = node->next ->next;

}

void LinkedList::deleteLinkedList(ListNode *head)
{
	ListNode *curNode = head;
	while (curNode!=NULL)
	{
		ListNode *delNode = curNode;
		curNode = curNode->next;
		delete delNode;
	}
	return;
}

/******
计算链表长度
*********/
int LinkedList::calculateLength(ListNode *head)
{
	if (head == NULL)
		return 0;
	int count = 0;
	while (head->next)
	{
		count++;
		head = head->next;
	}
	return count;
}
/*****
打印链表
*****/
void LinkedList::printLinkedList(ListNode *head)
{

	ListNode *curNode = head;
	while (curNode!=NULL)
	{
		std::cout << curNode->val << "->";
		curNode = curNode->next;
	}
	std::cout << "NULL" << std::endl;
}

/*****
反向打印链表
******/
void LinkedList::printLinkedListReversely(ListNode *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			printLinkedListReversely(head->next);
		}
		std::cout << head->val << std::endl;
	}
}

/********
奇偶链表
**********/
ListNode* LinkedList::oddEvenList(ListNode *head)
{

	if (head == NULL || head->next == NULL)
		return NULL;
	ListNode *odd = head;
	ListNode *even = odd->next;
	ListNode *evenHead = even;

	while (even != NULL && even->next != NULL)
	{
		odd->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;

}