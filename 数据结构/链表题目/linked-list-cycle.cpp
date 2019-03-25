#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//创建结构体 
struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	//定义快慢指针 
	struct ListNode *slow,*fast;
	//初始将快慢指针都指向头节点 
	slow = head;
	fast = head;
	
	//当慢节点不为空且指针的下一个不为空时
	//(因为里面要执行快指针走两步,所以要判断快指针的下一个不为空) 
	while(slow != NULL && fast->next != NULL){
		
		//快指针走两步,慢指针走一步 
		slow = slow->next;
		fast = fast->next->next;
		
		//如果快指针等于慢指针,说明存在换 
		if(slow == fast)
			return true;
		//如果快指针等于空,说明不存在环 
		if(fast == NULL)
			return false;
	}
	return false;
}


