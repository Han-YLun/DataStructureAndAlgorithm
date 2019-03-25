#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//��Ŀ���ӣ�https://leetcode-cn.com/problems/middle-of-the-linked-list


//����һ������ͷ��� head �ķǿյ���������������м���
struct ListNode* middleNode(struct ListNode* head) {
	
	//�����ֹ�ڱ��ڵ�(��ֹ��ͷ�ڵ���д���ʱ����) 
	struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	//���ڱ��ڵ����һ���ڵ�ָ��ͷ�ڵ� 
	dummy->next = head;
	
	//ͳ������ĳ��� 
    int length = 0;
    
    //�����ڱ��ڵ�ͳ������ĳ��� 
    while(dummy->next != NULL)
    {
    	dummy->next = dummy->next->next;
    	length++;
	}
	
	//���������м�λ�� 
	length /= 2;
	//���ڱ��ڵ�����ָ��ͷ�ڵ� 
	dummy->next = head;
	//����������м�λ������,���������м��ָ�� 
	while(length--)
		dummy->next = dummy->next->next;
	return dummy->next;
    
}

//�ⷨ�� 
struct ListNode* middleNode(struct ListNode* head) {
	
	//���ÿ����ڵ� 
    struct ListNode *slow,*fast;
    //�������ڵ㶼ָ��ͷ�ڵ� 
	slow = head;
	fast = head;
	
	//�����ڵ㲻Ϊ�ղ��ҿ�ڵ����һ���ڵ㲻Ϊ��
	//(��ΪҪʹ��Ҫ��ڵ�����¸��ڵ�,����Ҫȷ����ڵ����һ���ڵ㲻Ϊ��) 
	while(fast != NULL && fast->next != NULL){
		//���ڵ��ƶ�һ��,��ڵ��ƶ����� 
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
}

