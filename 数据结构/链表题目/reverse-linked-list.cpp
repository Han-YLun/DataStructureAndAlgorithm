#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

//定义结构体 
struct ListNode{
      int val;
      struct ListNode* next;
};

//解法一 
struct ListNode* reverseList(struct ListNode* head) {
	//定义三个指针 
    struct ListNode *nodePre,*nodeCur,*nodeNext;
    
    //为三个指针开辟空间 
    nodePre = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    nodeCur = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    nodeNext = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    
    //如果链表为空或者只有一个节点,直接返回head 
    if(head == NULL || head->next == NULL)
    	return head;
    
    //将pre,cur,next分别指向链表的第一、第二和第三个节点 
    nodePre = head;
    nodeCur = head->next;
    nodeNext = nodeCur->next;
    
    //当前节点不为空 
    while(nodeCur)
    {
    	//当前节点的下一个节点变为前一个节点 
    	nodeCur->next = nodePre;
    	//将第一、第二个节点往后移 
    	nodePre = nodeCur;
    	nodeCur = nodeNext;
    	//如果第三个节点不为空,就往后移 
    	if(nodeNext)
    		nodeNext = nodeNext->next;
	}
	
	//此时反转完成,head节点为最后一个节点 
	head->next = NULL;
	//将头节点指向最后一个节点 
	head = nodePre;
	return head;
}

struct ListNode* reverseList(struct ListNode* head) {
	//将前一个节点置为空,当前节点指向头节点 
   struct ListNode *prev = NULL,*cur = head;
   
   //当当前节点不为空时 
   while(cur)
   {
   		//nextNode指向当前节点的下一个节点 
		ListNode *nextNode = cur->next;
		//当前节点的下一个节点指向上一个节点 
		cur->next = prev;
		//将当前节点和前一个节点都往后移 
		prev = cur;
		cur = nextNode;
   }
   return prev;
}
