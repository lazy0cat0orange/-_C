#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50

typedef int ElemType;
//����ջ�Ľṹ��
typedef struct {
	ElemType data[MAXSIZE];
	int top;
}SqStack;
//��ʼ��ջ
void InitStack(SqStack& S) {
	S.top = -1;
}
//�ж�ջ��
bool StackEmpty(SqStack S) {
	if (S.top == -1) {
		return true;
	}
	return false;
}
//��ջ
bool Push(SqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1) {
		return false;
	}
	S.top++;
	S.data[S.top] = x;
	return true;
}
//��ջ
bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1) {
		return false;
	}
	x = S.data[S.top];
	S.top--;
	return true;
}
//��ȡջ��Ԫ��
bool GetTop(SqStack S, ElemType& x) {
	if (S.top == -1) {
		return false;
	}
	x = S.data[S.top];
	return true;
}
int main() {
	SqStack S;
	bool flag;
	ElemType m;
	InitStack(S);
	flag = StackEmpty(S);
	if (flag) {
		printf("ջ�ǿյ�\n");
	}
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	flag = GetTop(S, m);
	if (flag) {
		printf("ջ��Ԫ��Ϊ%d\n", m);
	}
	flag = Pop(S, m);
	if (flag) {
		printf("��ջԪ��Ϊ%d\n", m);
	}
	return 0;
}