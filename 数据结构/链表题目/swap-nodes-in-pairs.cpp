#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//题目链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs 


//定义结构体 
struct ListNode {
    int val;
    struct ListNode *next;
};

//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
struct ListNode* swapPairs(struct ListNode* head) {

    //如果链表为空表或者只有一个节点,就直接返回 
    if(!head || !head->next)
    	return head;
    //定义临时节点tmp,并且指向头节点的下一个节点 
    struct ListNode *temp = head->next;
    //头节点的下一个节点指向后面一组两两交换后的地址 
    head->next = swapPairs(temp->next);
    //第二个节点的下一个节点指向头节点 
    temp->next = head;
    return temp;
}
