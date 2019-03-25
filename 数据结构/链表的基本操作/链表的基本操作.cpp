#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

//������������ 
typedef int ElementType;

//����ڵ�Ķ��� 
typedef struct ListNode{
	ElementType Element; //������,���ڴ������ 
	ListNode *Next;		//ָ����һ����ڵ� 
}Node , *PNode; 


//��������
PNode createList(){
	
	int len ;//����������
	int val ;//������Žڵ����ֵ
	PNode pHead = (PNode)malloc(sizeof(Node)); 
	if(pHead == NULL){	//�ж��Ƿ����ɹ� 
		
		printf("�ռ����ʧ��\n");
		exit(-1); 
	}
	
	//pTail��ĩβ�ڵ�,�ʼָ��ͷ��� 
	PNode pTail = pHead;
	printf("������ڵ����:");
	 
	
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		//�����½ڵ� 
		PNode pNew = (PNode)malloc(sizeof(Node));
		
		if(pNew == NULL){
			printf("�����½ڵ�ʧ��!\n");
			exit(-1);
		}
		
		printf("�������%d���ڵ������ �� ",i+1); 
		scanf("%d",&val);
		
		pNew->Element = val;	//�����ݸ�ֵ���ڵ������� 
		pTail->Next = pNew;		//ĩβ�ڵ�ָ��ָ����һ���½ڵ� 
		pNew->Next = NULL;		//�½ڵ�ָ��ΪNULL 
		pTail = pNew; 			//���½ڵ㸳ֵ��ĩβ�ڵ� 
	} 
	
	printf("��������ɹ�\n");
	return pHead;	//����ͷ�ڵ� 
} 


//�������� 
void  traverseList(PNode pHead){
	//�׽ڵ㸳ֵ����ʱ�ڵ�p 
	PNode p = pHead->Next;
	printf("������е�ֵΪ : ");
	if(p == NULL)
		printf("����Ϊ��");
	//��p����β�ڵ�ʱ,�����ǰ�ڵ�ֵ 
	while(p != NULL){
		
		printf("%d",p->Element);
		p = p->Next;
		if(p != NULL)
			printf("->"); 
	} 
	
	printf("\n"); 
} 


//��ѯֵ�������е�λ�� 
void findValueInList(PNode pHead){
	//��ʱ�ڵ�pָ�������׽ڵ�ĵ�ַ 
	PNode p = pHead->Next;
	//������¼Ҫ��ѯ��ֵ 
	int val = -1;
	//������¼ֵ������λ�� 
	int index;
	printf("������Ҫ��ѯ���� : ");
	scanf("%d",&val); 
	while(p != NULL && p->Element != val){
		p = p->Next;
		++index;
	} 
	
	if(p != NULL)
		printf("�ҵ��Ľڵ�λ��Ϊ �� %d",index+1);
	else
		printf("�����ϲ����ڸ�ֵ");
	
	printf("\n");
	return; 
}

//��ָ����ֵ���뵽����ָ����λ���� 
void insertValueIntoList(PNode pHead,int index,int val){
	//���õ�ǰλ��Ϊ1 
	int pos = 1;
	//��ʱ�ڵ�pָ�������׽ڵ�ĵ�ַ 
	PNode p = pHead->Next;
	
	while(p != NULL && pos < index-1){
		p = p->Next; 
		++pos;
	} 
	//��ʱ�ڵ������洢Ҫ��������� 
	PNode tmp = (PNode)malloc(sizeof(Node));
	if(tmp == NULL){
		printf("�ڴ����ʧ��!");
		exit(-1); 
	}
	
	//����ڵ�
	tmp->Element = val;
	tmp->Next = p->Next;
	p->Next = tmp; 
	printf("����ɹ�!\n"); 
}

//ɾ�������еĵ�pos���ڵ� 
void deleteIndexInList(PNode pHead,int index){
	
	int pos = 1;
	//��ʱ�ڵ�pָ�������׽ڵ�ĵ�ַ
	PNode p = pHead->Next;
	while(p != NULL && pos < index-1){
		p = p->Next;
		++pos;
	} 
	
	//ɾ���ڵ�
	PNode tmp = p->Next;	//������ʱ�ڵ�ָ��Ҫɾ���Ľڵ� 
	p->Next = tmp->Next;	//��Ҫɾ���Ľڵ��ǰ���ڵ�ָ��������ڵ� 
	free(tmp);	//�ͷ�ɾ���ڵ���ڴ�ռ�,��ֹ�ڴ�й© 
	tmp = NULL; 	//��ֹ����Ұָ�� 
	printf("ɾ���ɹ�!!!\n");
}

//ɾ���������� 
PNode deleteList(PNode pHead){
	PNode p,tmp;
	//��ʱ�ڵ�pָ�������׽ڵ�ĵ�ַ
	p = pHead->Next;
	while(p != NULL){
		tmp = p->Next;		//ʹtmpָ��Ҫɾ���Ľڵ����һ���ڵ� 
		free(p); 			//�ͷŵ�ǰ��ɾ���ڵ���ڴ�ռ� 
		p = tmp;			//ָ����һ���ڵ� 
	}
	pHead->Next = NULL;
	printf("ɾ������ɹ�!\n"); 
	return pHead;
}



int main()
{
	//����һ������,����ʹ���䷵�ص�ͷ��� 
	PNode pHead = createList();
	
	//�������� 
	traverseList(pHead); 
	
	//�����ѯ
	findValueInList(pHead); 
	
	//������� 
	insertValueIntoList(pHead,3,99);
	
	//�������� 
	traverseList(pHead); 
	
	//ɾ������ָ��λ�õ�ֵ
	deleteIndexInList(pHead,3);
	
	 	
	//�������� 
	traverseList(pHead); 
	
	//ɾ������
	pHead = deleteList(pHead);
	
	//�������� 
	traverseList(pHead);
		
	return 0;
}

