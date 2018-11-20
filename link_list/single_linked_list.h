#pragma once
#ifndef _SINGLE_LINKED_LIST_H_
#define _SINGLE_LINKED_LIST_H_
#include <iostream>
#include "pch.h"

//���������ռ�
namespace alg {

	struct ListNode {

		int val;
		ListNode *next;
		ListNode(int x) :val(x), next(NULL) {};


	};

	class LinkedList {

	public:
		//��������
		ListNode* createLinkedList(int arr[], int n);
		//��ת����
		ListNode* reverseLinkedList(ListNode* list);
		//�Ƴ�ֵΪval�����нڵ�
		ListNode* removeElements(ListNode* list, int val);
		//�ϲ�������������
		ListNode* mergeLists(ListNode* a, ListNode* b);
		//�ҵ���������Ľ���
		ListNode* findIntersectionNode(ListNode *a, ListNode *b);
		//�ҵ�������N���ڵ�
		ListNode* findKthNodeToTail(ListNode *head, unsigned k);
		//�Ƴ�������N���ڵ�
		ListNode* removeNthFromEnd(ListNode *head, int n);
		//�Ƴ��ظ��ڵ㣨���������ڵ㣩
		ListNode* deleteDuplicates(ListNode* head);
		//�Ƴ������ظ��ڵ�
		ListNode* deleteAllDuplicates(ListNode* head);
		//�����Ƿ��л�
		bool hasCircle(ListNode* head);
		//ɾ��ĳ���ڵ�
		void deleteNode(ListNode *node);
		//ɾ������
		void deleteLinkedList(ListNode *head);
		//����������
		int calculateLength(ListNode *head);
		//�����ӡ����
		void printLinkedList(ListNode *head);
		//�����ӡ����
		void printLinkedListReversely(ListNode *head);
		//��ż����
		ListNode* oddEvenList(ListNode *head);

	};
}

#endif // !_SINGLE_LINKED_LIST_H_
