#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define ull unsigned __int64
#define Min(a,b) ((a>b)?b:a)
#define Max(a,b) ((a>b)?a:b)
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int j=1;j<t+1;j++)
	{
		int m,n,k;
		scanf("%d %d",&m,&n); 
		if(m<n) k=n-m;
		else k=m-n;
		int sum=0;
		for(int i=1;i*i<=k;i++)
		{
			if(k%i==0) 
			{
				if(i*i==k) sum++;
				else sum+=2;
			}
		}
		printf("Case %d: %d\n",j,sum);
	 } 
 } 
