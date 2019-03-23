#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

//定义数据类型 
typedef int ElementType;

//链表节点的定义 
typedef struct ListNode{
	ElementType Element; //数据域,用于存放数据 
	ListNode *Next;		//指向下一链表节点 
}Node , *PNode; 


//创建链表
PNode createList(){
	
	int len ;//定义链表长度
	int val ;//用来存放节点的数值
	PNode pHead = (PNode)malloc(sizeof(Node)); 
	if(pHead == NULL){	//判断是否分配成功 
		
		printf("空间分配失败\n");
		exit(-1); 
	}
	
	//pTail是末尾节点,最开始指向头结点 
	PNode pTail = pHead;
	printf("请输入节点个数:");
	 
	
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		//分配新节点 
		PNode pNew = (PNode)malloc(sizeof(Node));
		
		if(pNew == NULL){
			printf("分配新节点失败!\n");
			exit(-1);
		}
		
		printf("请输入第%d个节点的数据 ： ",i+1); 
		scanf("%d",&val);
		
		pNew->Element = val;	//将数据赋值给节点数据域 
		pTail->Next = pNew;		//末尾节点指针指向下一个新节点 
		pNew->Next = NULL;		//新节点指向为NULL 
		pTail = pNew; 			//将新节点赋值给末尾节点 
	} 
	
	printf("创建链表成功\n");
	return pHead;	//返回头节点 
} 


//遍历链表 
void  traverseList(PNode pHead){
	//首节点赋值给临时节点p 
	PNode p = pHead->Next;
	printf("链表的中的值为 : ");
	if(p == NULL)
		printf("链表为空");
	//当p不是尾节点时,输出当前节点值 
	while(p != NULL){
		
		printf("%d",p->Element);
		p = p->Next;
		if(p != NULL)
			printf("->"); 
	} 
	
	printf("\n"); 
} 


//查询值在链表中的位置 
void findValueInList(PNode pHead){
	//临时节点p指向链表首节点的地址 
	PNode p = pHead->Next;
	//用来记录要查询的值 
	int val = -1;
	//用来记录值的索引位置 
	int index;
	printf("请输入要查询的数 : ");
	scanf("%d",&val); 
	while(p != NULL && p->Element != val){
		p = p->Next;
		++index;
	} 
	
	if(p != NULL)
		printf("找到的节点位置为 ： %d",index+1);
	else
		printf("链表上不存在该值");
	
	printf("\n");
	return; 
}

//将指定的值插入到链表指定的位置中 
void insertValueIntoList(PNode pHead,int index,int val){
	//设置当前位置为1 
	int pos = 1;
	//临时节点p指向链表首节点的地址 
	PNode p = pHead->Next;
	
	while(p != NULL && pos < index-1){
		p = p->Next; 
		++pos;
	} 
	//临时节点用来存储要插入的数据 
	PNode tmp = (PNode)malloc(sizeof(Node));
	if(tmp == NULL){
		printf("内存分配失败!");
		exit(-1); 
	}
	
	//插入节点
	tmp->Element = val;
	tmp->Next = p->Next;
	p->Next = tmp; 
	printf("插入成功!\n"); 
}

//删除链表中的第pos个节点 
void deleteIndexInList(PNode pHead,int index){
	
	int pos = 1;
	//临时节点p指向链表首节点的地址
	PNode p = pHead->Next;
	while(p != NULL && pos < index-1){
		p = p->Next;
		++pos;
	} 
	
	//删除节点
	PNode tmp = p->Next;	//定义临时节点指向要删除的节点 
	p->Next = tmp->Next;	//将要删除的节点的前驱节点指向其后驱节点 
	free(tmp);	//释放删除节点的内存空间,防止内存泄漏 
	tmp = NULL; 	//防止产生野指针 
	printf("删除成功!!!\n");
}

//删除整个链表 
PNode deleteList(PNode pHead){
	PNode p,tmp;
	//临时节点p指向链表首节点的地址
	p = pHead->Next;
	while(p != NULL){
		tmp = p->Next;		//使tmp指向要删除的节点的下一个节点 
		free(p); 			//释放当前被删除节点的内存空间 
		p = tmp;			//指向下一个节点 
	}
	pHead->Next = NULL;
	printf("删除链表成功!\n"); 
	return pHead;
}



int main()
{
	//创建一个链表,并且使用其返回的头结点 
	PNode pHead = createList();
	
	//遍历链表 
	traverseList(pHead); 
	
	//链表查询
	findValueInList(pHead); 
	
	//链表插入 
	insertValueIntoList(pHead,3,99);
	
	//遍历链表 
	traverseList(pHead); 
	
	//删除链表指定位置的值
	deleteIndexInList(pHead,3);
	
	 	
	//遍历链表 
	traverseList(pHead); 
	
	//删除链表
	pHead = deleteList(pHead);
	
	//遍历链表 
	traverseList(pHead);
		
	return 0;
}

