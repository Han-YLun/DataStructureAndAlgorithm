#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//定义结构体 
struct ListNode {
    int val;
    struct ListNode *next;
};

//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	
	//创建哨兵(防止对头节点进行处理时出错) 
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    //哨兵节点的下一个节点定义为头节点 
    dummy->next = head;
    
    //定义慢节点和快节点,并指向哨兵 
    struct ListNode *slowNode = dummy;
	struct ListNode *fastNode = dummy;
    
    //当快节点的下一个节点不为空时 
    while(fastNode->next != NULL)
    {
    	//当n<=0时,往后移动慢节点 
    	if(n<=0)
    		slowNode = slowNode->next;
    	//移动快节点 
    	fastNode = fastNode->next;
    	//每次n-- 
    	n--;
	}
	
	//当慢节点的下一个节点不为空时 
	if(slowNode->next != NULL)
		//慢节点的下一个节点指向下下个节点,下个节点即为要删除的节点 
		slowNode->next = slowNode->next->next;
	//返回哨兵的下一个节点,即头节点 
    return dummy->next;
}
