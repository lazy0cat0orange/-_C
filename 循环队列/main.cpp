#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int front, rear;
}SqQueue;
//��ʼ��
void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}
//�п�
bool isEmpty(SqQueue Q) {
	if (Q.rear == Q.front) {
		return true;
	}
	return false;
}
bool EnQueue(SqQueue& Q,ElemType x) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
int main()
{
	SqQueue Q;
	bool ret;
	ElemType element;
	InitQueue(Q);
	ret = isEmpty(Q);
	if (ret) {
		printf("����Ϊ��\n");
	}
	else {
		printf("���в�Ϊ��\n");
	}
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	ret =EnQueue(Q, 6);
	ret =EnQueue(Q,7);
	if (ret) {
		printf("��ӳɹ�\n");
	}
	else {
		printf("���ʧ��\n");
	}
	ret = DeQueue(Q, element);
	if (ret) {
		printf("���ӳɹ���Ԫ��ֵΪ%d\n",element);
	}
	else {
		printf("����ʧ��\n");
	}
	ret = DeQueue(Q, element);
	if (ret) {
		printf("���ӳɹ���Ԫ��ֵΪ%d\n", element);
	}
	else {
		printf("����ʧ��\n");
	}
	return 0;
}