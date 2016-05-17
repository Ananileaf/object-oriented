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

void CreatLink(Link *head)//创建链表 
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
	N = coun; //可能有链表外的点 
	p->nx = NULL;
	return;
}

Link* Rotation(Link *p,Link *q)//p为需要反转的前一个节点, q为需要反转最后一个结点的后一个 
{
	Link *r1 = p->nx;	//当前反转的结点
	Link *r2;			//记录当前反转结点的下一个节点 
	Link *r3 = p->nx;	//记录反转的第一个结点,用于最后要连到全部反转后的下一个结点 
	while (r1 != q)
	{
		r2 = r1->nx;
		r1->nx = p->nx;
		p->nx = r1;
		r1 = r2;
	}
	r3->nx = q;
	return r3;//返回反转段的最后一个结点 
}
int main()
{
//	freopen("xx.txt","r",stdin);

	/*保存各个点*/ 
	scanf("%d %d %d",&Back[0],&N,&K);
	int i;
	for (i = 1; i < N + 1; i++)
	{
		scanf("%d %d %d",&Now[i],&Data[i],&Back[i]);
		f[Now[i]] = i;
	}

	/*创建链表*/ 
	Link *head = new Link;
	head->nx = NULL;
	CreatLink(head);

	/*反转链表*/ 
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

	/*输出链表 */ 
	p = head->nx;
	delete head;
	while (p->nx)
	{
		printf("%05d %d %05d\n",p->Adress ,p->Data, p->nx->Adress);
		q = p;
		p = p->nx;
		delete q;//C程序设计平台上面这句话留着会给你2个RE,我不知道为啥 
	}
	printf("%05d %d -1\n",p->Adress ,p->Data);
	delete p;
	
	return 0; 
}
