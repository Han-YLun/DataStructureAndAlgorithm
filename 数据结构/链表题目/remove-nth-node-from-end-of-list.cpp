#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//����ṹ�� 
struct ListNode {
    int val;
    struct ListNode *next;
};

//����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ���
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	
	//�����ڱ�(��ֹ��ͷ�ڵ���д���ʱ����) 
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    //�ڱ��ڵ����һ���ڵ㶨��Ϊͷ�ڵ� 
    dummy->next = head;
    
    //�������ڵ�Ϳ�ڵ�,��ָ���ڱ� 
    struct ListNode *slowNode = dummy;
	struct ListNode *fastNode = dummy;
    
    //����ڵ����һ���ڵ㲻Ϊ��ʱ 
    while(fastNode->next != NULL)
    {
    	//��n<=0ʱ,�����ƶ����ڵ� 
    	if(n<=0)
    		slowNode = slowNode->next;
    	//�ƶ���ڵ� 
    	fastNode = fastNode->next;
    	//ÿ��n-- 
    	n--;
	}
	
	//�����ڵ����һ���ڵ㲻Ϊ��ʱ 
	if(slowNode->next != NULL)
		//���ڵ����һ���ڵ�ָ�����¸��ڵ�,�¸��ڵ㼴ΪҪɾ���Ľڵ� 
		slowNode->next = slowNode->next->next;
	//�����ڱ�����һ���ڵ�,��ͷ�ڵ� 
    return dummy->next;
}
