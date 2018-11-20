#pragma once
#ifndef _SINGLE_LINKED_LIST_H_
#define _SINGLE_LINKED_LIST_H_
#include <iostream>
#include "pch.h"

//声明命名空间
namespace alg {

	struct ListNode {

		int val;
		ListNode *next;
		ListNode(int x) :val(x), next(NULL) {};


	};

	class LinkedList {

	public:
		//生成链表
		ListNode* createLinkedList(int arr[], int n);
		//反转链表
		ListNode* reverseLinkedList(ListNode* list);
		//移除值为val的所有节点
		ListNode* removeElements(ListNode* list, int val);
		//合并两个有序链表
		ListNode* mergeLists(ListNode* a, ListNode* b);
		//找到两个链表的交点
		ListNode* findIntersectionNode(ListNode *a, ListNode *b);
		//找到倒数第N个节点
		ListNode* findKthNodeToTail(ListNode *head, unsigned k);
		//移除倒数第N个节点
		ListNode* removeNthFromEnd(ListNode *head, int n);
		//移除重复节点（保留单个节点）
		ListNode* deleteDuplicates(ListNode* head);
		//移除所有重复节点
		ListNode* deleteAllDuplicates(ListNode* head);
		//链表是否有环
		bool hasCircle(ListNode* head);
		//删除某个节点
		void deleteNode(ListNode *node);
		//删除链表
		void deleteLinkedList(ListNode *head);
		//计算链表长度
		int calculateLength(ListNode *head);
		//正序打印链表
		void printLinkedList(ListNode *head);
		//倒序打印链表
		void printLinkedListReversely(ListNode *head);
		//奇偶链表
		ListNode* oddEvenList(ListNode *head);

	};
}

#endif // !_SINGLE_LINKED_LIST_H_
