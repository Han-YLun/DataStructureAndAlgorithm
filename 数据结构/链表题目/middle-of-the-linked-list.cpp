#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//题目链接：https://leetcode-cn.com/problems/middle-of-the-linked-list


//给定一个带有头结点 head 的非空单链表，返回链表的中间结点
struct ListNode* middleNode(struct ListNode* head) {
	
	//定义防止哨兵节点(防止对头节点进行处理时出错) 
	struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	//将哨兵节点的下一个节点指向头节点 
	dummy->next = head;
	
	//统计链表的长度 
    int length = 0;
    
    //利用哨兵节点统计链表的长度 
    while(dummy->next != NULL)
    {
    	dummy->next = dummy->next->next;
    	length++;
	}
	
	//求出链表的中间位置 
	length /= 2;
	//将哨兵节点重新指向头节点 
	dummy->next = head;
	//利用链表的中间位置索引,求出链表的中间的指针 
	while(length--)
		dummy->next = dummy->next->next;
	return dummy->next;
    
}

//解法二 
struct ListNode* middleNode(struct ListNode* head) {
	
	//设置快慢节点 
    struct ListNode *slow,*fast;
    //将快慢节点都指向头节点 
	slow = head;
	fast = head;
	
	//当慢节点不为空并且快节点的下一个节点不为空
	//(因为要使用要快节点的下下个节点,所以要确保快节点的下一个节点不为空) 
	while(fast != NULL && fast->next != NULL){
		//慢节点移动一次,快节点移动两次 
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
}

