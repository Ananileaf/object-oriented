#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Link
{
	int Data;
	int Adress;
	Link *nx;
};

int N,K;
int f[1000050] = {0};
int Now[100050] = {0};
int Back[100050] = {0};
int Data[100050] = {0};

void CreatLink(Link *head)//�������� 
{
	Link *p,*q = head;
	int coun = 0;
	int t = 0;
	while (Back[t] != -1)
	{
		t = f[Back[t]];
		p = new Link;
		p->Data = Data[t];
		p->Adress = Now[t];
		q->nx = p;
		q = p;
		coun++;
	}
	N = coun; //������������ĵ� 
	p->nx = NULL;
	return;
}

Link* Rotation(Link *p,Link *q)//pΪ��Ҫ��ת��ǰһ���ڵ�, qΪ��Ҫ��ת���һ�����ĺ�һ�� 
{
	Link *r1 = p->nx;	//��ǰ��ת�Ľ��
	Link *r2;			//��¼��ǰ��ת������һ���ڵ� 
	Link *r3 = p->nx;	//��¼��ת�ĵ�һ�����,�������Ҫ����ȫ����ת�����һ����� 
	while (r1 != q)
	{
		r2 = r1->nx;
		r1->nx = p->nx;
		p->nx = r1;
		r1 = r2;
	}
	r3->nx = q;
	return r3;//���ط�ת�ε����һ����� 
}
int main()
{
//	freopen("xx.txt","r",stdin);

	/*���������*/ 
	scanf("%d %d %d",&Back[0],&N,&K);
	int i;
	for (i = 1; i < N + 1; i++)
	{
		scanf("%d %d %d",&Now[i],&Data[i],&Back[i]);
		f[Now[i]] = i;
	}

	/*��������*/ 
	Link *head = new Link;
	head->nx = NULL;
	CreatLink(head);

	/*��ת����*/ 
	int T = N/K;
	Link *p,*q = head;
	for (i = 0; i < T; i++) 
	{
		p = q;
		int coun = 0;
		while(coun < K)
		{
			coun++;
			q = q->nx;
		}
		q = Rotation(p,q->nx);
	}

	/*������� */ 
	p = head->nx;
	delete head;
	while (p->nx)
	{
		printf("%05d %d %05d\n",p->Adress ,p->Data, p->nx->Adress);
		q = p;
		p = p->nx;
		delete q;//C�������ƽ̨������仰���Ż����2��RE,�Ҳ�֪��Ϊɶ 
	}
	printf("%05d %d -1\n",p->Adress ,p->Data);
	delete p;
	
	return 0; 
}
