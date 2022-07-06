#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

//����ṹ��
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
//��������
bool ListInsert(SqList& L, int i, ElemType e);//���뺯��
void PrintList(SqList L);//��ӡ����
bool ListDelete(SqList& L, int i, ElemType& e);//ɾ������
int LocateElem(SqList L, ElemType e);//����Ԫ��λ�ú���

int main()
{
	SqList L;
	bool ret;
	ElemType del;
	int elem_pos;

	//�ֶ���������ֵ
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;

	//�ڵ�2��λ�ò���60
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("����ɹ�\n");
		PrintList(L);
	}
	else {
		printf("����ʧ��");
	}


	//ɾ����һ��λ�õ�Ԫ�أ�����Ԫ��ֵ���
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("ɾ���ɹ�\n");
		printf("ɾ����Ԫ��ֵΪ%d\n", del);
		PrintList(L);
	}
	else {
		printf("ɾ��ʧ��");
	}

	//����Ԫ��60��λ��
	elem_pos = LocateElem(L, 60);
	if (elem_pos) {
		printf("���ҳɹ�\n");
		printf("Ԫ��λ��Ϊ%d", elem_pos);
	}
	else {
		printf("����ʧ��\n");
	}

	return 0;
}

//��������
bool ListInsert(SqList& L,int i,ElemType e) 
{	
	//�жϲ���λ���Ƿ����
	if (i<1 || i>L.length + 1) {
		return false;				
	}
	//�жϱ�ռ��Ƿ��㹻
	if (L.length >= MaxSize) {
		return false;				
	}
	//�ƶ�Ԫ��
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];	
	}
	//��ֵ������һ
	L.data[i - 1] = e;				
	L.length++;					

	return true;
}
void PrintList(SqList L) 
{
	for (int i = 0; i < L.length; i++) {
		printf("%3d", L.data[i]);
	}
	printf("\n");
}
bool ListDelete(SqList& L, int i, ElemType &e)
{
	//�ж�ɾ��λ���Ƿ����
	if (i<1 || i>L.length ) {
		return false;
	}
	if (L.length == 0) {
		return false;
	}
	//��ֵ
	e = L.data[i - 1];
	//�ƶ�Ԫ��
	for (int j = i; j <= L.length; j++) {
		L.data[j-1] = L.data[j];
	}
	//����һ
	L.length--;

	return true;
}
int LocateElem(SqList L, ElemType e)
{
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}