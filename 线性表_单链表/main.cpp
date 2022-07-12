#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <corecrt_malloc.h>


typedef int ElemType;

//���嵥����ڵ�
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//ͷ�巨�½�����
LinkList CreatList1(LinkList &L);
//��ӡ����
void PrintList(LinkList L);
//β�巨�½�����
LinkList CreatList2(LinkList& L);
//����Ų���Ԫ��
LinkList GetElem(LinkList L,int i);
//��ֵ����Ԫ��
LinkList LocateElem(LinkList L, ElemType e);
//������Ԫ��
bool ListInsert(LinkList& L, int i, ElemType e);
//ɾ��Ԫ��
bool ListDelete(LinkList& L, int i);
int main(void)
{
	LinkList L;
	LinkList search;
//	CreatList1(L);
	CreatList2(L);
	PrintList(L);
	search = GetElem(L, 2);
	if (search != NULL) {
		printf("����Ų��ҳɹ�\n");
		printf("%d\n", search->data);
	}
	search = LocateElem(L, 4);
	if (search != NULL) {
		printf("��ֵ���ҳɹ�\n");
		printf("%d\n", search->data);
	}
	int ret=ListInsert(L, 2,8);
	if (ret){
		printf("����ɹ�\n");
		PrintList(L);
	}
	ret = ListDelete(L, 2);
	if (ret) {
		printf("ɾ���ɹ�\n");
		PrintList(L);
	}
	return 0;
}

LinkList CreatList1(LinkList& L)
{
	LNode* s;
	int x;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
void PrintList(LinkList L) {
	L = L->next;
	while (L != NULL) {
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}
LinkList CreatList2(LinkList& L) {
	int x;
	L = (LNode*)malloc(sizeof(LNode));
	LNode* s,*r=L;
	scanf("%d", &x);
	while(x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next=s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}
LinkList GetElem(LinkList L, int i)
{	
	LinkList p=L->next ;
	if (i == 0) {
		return L ;
	}
	if (i < 1) {
		return NULL ;
	}
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
LinkList LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	while (p!=NULL&& p->data !=e) {
		p = p->next;
	}
	return p;
}
bool ListInsert(LinkList& L, int i, ElemType e)
{
	LinkList p = GetElem(L, i - 1);
	if (NULL == p) {
		return false;
	}
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool ListDelete(LinkList& L, int i)
{
	LinkList p = GetElem(L, i - 1);
	if (NULL == p) {
		return false;
	}
	LinkList q = p->next;
	if (NULL == q) {
		return false;
	}
	p->next = q->next;
	free(q);
	q = NULL;
	return true;
}