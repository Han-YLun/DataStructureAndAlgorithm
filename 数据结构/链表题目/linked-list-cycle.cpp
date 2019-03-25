#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//�����ṹ�� 
struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	//�������ָ�� 
	struct ListNode *slow,*fast;
	//��ʼ������ָ�붼ָ��ͷ�ڵ� 
	slow = head;
	fast = head;
	
	//�����ڵ㲻Ϊ����ָ�����һ����Ϊ��ʱ
	//(��Ϊ����Ҫִ�п�ָ��������,����Ҫ�жϿ�ָ�����һ����Ϊ��) 
	while(slow != NULL && fast->next != NULL){
		
		//��ָ��������,��ָ����һ�� 
		slow = slow->next;
		fast = fast->next->next;
		
		//�����ָ�������ָ��,˵�����ڻ� 
		if(slow == fast)
			return true;
		//�����ָ����ڿ�,˵�������ڻ� 
		if(fast == NULL)
			return false;
	}
	return false;
}


