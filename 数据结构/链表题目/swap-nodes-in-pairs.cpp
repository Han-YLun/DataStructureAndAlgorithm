#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//��Ŀ���ӣ�https://leetcode-cn.com/problems/swap-nodes-in-pairs 


//����ṹ�� 
struct ListNode {
    int val;
    struct ListNode *next;
};

//����һ���������������������ڵĽڵ㣬�����ؽ����������
struct ListNode* swapPairs(struct ListNode* head) {

    //�������Ϊ�ձ����ֻ��һ���ڵ�,��ֱ�ӷ��� 
    if(!head || !head->next)
    	return head;
    //������ʱ�ڵ�tmp,����ָ��ͷ�ڵ����һ���ڵ� 
    struct ListNode *temp = head->next;
    //ͷ�ڵ����һ���ڵ�ָ�����һ������������ĵ�ַ 
    head->next = swapPairs(temp->next);
    //�ڶ����ڵ����һ���ڵ�ָ��ͷ�ڵ� 
    temp->next = head;
    return temp;
}
