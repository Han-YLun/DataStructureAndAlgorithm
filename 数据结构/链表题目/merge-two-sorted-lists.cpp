#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//题目链接：https://leetcode-cn.com/problems/merge-two-sorted-lists

//定义结构体 
struct ListNode {
      int val;
      struct ListNode *next;
};
//合并两个链表,并将合并后的链表返回 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
	//如果l1链表为空,就返回l2链表 
    if(!l1)
		return l2;
	//如果l2为空,返回l1 
	if(!l2)
		return l1;
		
	//创建一个新节点,并指向空 
	struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode = NULL;
	
	//如果l1节点的值小于等于l2节点的值 
	if(l1->val <= l2->val){
		//新节点指向l1 
		newNode = l1;
		//新节点的下一个节点指向递归返回的值(因为此函数一直在做的就是找到两个对应的值,哪个最小) 
		newNode->next = mergeTwoLists(l1->next,l2);
	}else{
		//否则新节点指向l2 
		newNode = l2;
		newNode->next = mergeTwoLists(l1,l2->next);
	}
    return newNode;
        
}
