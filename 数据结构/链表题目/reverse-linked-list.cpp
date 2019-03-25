#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

//����ṹ�� 
struct ListNode{
      int val;
      struct ListNode* next;
};

//�ⷨһ 
struct ListNode* reverseList(struct ListNode* head) {
	//��������ָ�� 
    struct ListNode *nodePre,*nodeCur,*nodeNext;
    
    //Ϊ����ָ�뿪�ٿռ� 
    nodePre = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    nodeCur = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    nodeNext = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
    
    //�������Ϊ�ջ���ֻ��һ���ڵ�,ֱ�ӷ���head 
    if(head == NULL || head->next == NULL)
    	return head;
    
    //��pre,cur,next�ֱ�ָ������ĵ�һ���ڶ��͵������ڵ� 
    nodePre = head;
    nodeCur = head->next;
    nodeNext = nodeCur->next;
    
    //��ǰ�ڵ㲻Ϊ�� 
    while(nodeCur)
    {
    	//��ǰ�ڵ����һ���ڵ��Ϊǰһ���ڵ� 
    	nodeCur->next = nodePre;
    	//����һ���ڶ����ڵ������� 
    	nodePre = nodeCur;
    	nodeCur = nodeNext;
    	//����������ڵ㲻Ϊ��,�������� 
    	if(nodeNext)
    		nodeNext = nodeNext->next;
	}
	
	//��ʱ��ת���,head�ڵ�Ϊ���һ���ڵ� 
	head->next = NULL;
	//��ͷ�ڵ�ָ�����һ���ڵ� 
	head = nodePre;
	return head;
}

struct ListNode* reverseList(struct ListNode* head) {
	//��ǰһ���ڵ���Ϊ��,��ǰ�ڵ�ָ��ͷ�ڵ� 
   struct ListNode *prev = NULL,*cur = head;
   
   //����ǰ�ڵ㲻Ϊ��ʱ 
   while(cur)
   {
   		//nextNodeָ��ǰ�ڵ����һ���ڵ� 
		ListNode *nextNode = cur->next;
		//��ǰ�ڵ����һ���ڵ�ָ����һ���ڵ� 
		cur->next = prev;
		//����ǰ�ڵ��ǰһ���ڵ㶼������ 
		prev = cur;
		cur = nextNode;
   }
   return prev;
}
