#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//��Ŀ���ӣ�https://leetcode-cn.com/problems/merge-two-sorted-lists

//����ṹ�� 
struct ListNode {
      int val;
      struct ListNode *next;
};
//�ϲ���������,�����ϲ���������� 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
	//���l1����Ϊ��,�ͷ���l2���� 
    if(!l1)
		return l2;
	//���l2Ϊ��,����l1 
	if(!l2)
		return l1;
		
	//����һ���½ڵ�,��ָ��� 
	struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode = NULL;
	
	//���l1�ڵ��ֵС�ڵ���l2�ڵ��ֵ 
	if(l1->val <= l2->val){
		//�½ڵ�ָ��l1 
		newNode = l1;
		//�½ڵ����һ���ڵ�ָ��ݹ鷵�ص�ֵ(��Ϊ�˺���һֱ�����ľ����ҵ�������Ӧ��ֵ,�ĸ���С) 
		newNode->next = mergeTwoLists(l1->next,l2);
	}else{
		//�����½ڵ�ָ��l2 
		newNode = l2;
		newNode->next = mergeTwoLists(l1,l2->next);
	}
    return newNode;
        
}
