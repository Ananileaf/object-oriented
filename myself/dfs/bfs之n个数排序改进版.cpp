#include<cstdio>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<iostream>
#define PI acos(-1)
#define ull unsigned __int64
#define Min(a,b) ((a>b)?b:a)
#define Max(a,b) ((a>b)?a:b)
using namespace std;
int v[100],a[100],b[100],n;
void dfs(int t)
{
	if(t==n)
	{
		printf("%d",b[0]);
		for(int i=1;i<n;i++) printf(" %d",b[i]);
		cout<<endl;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		{
			bool flag=true;
			for(int j=0;j<i;j++)
			{
				if(a[i]==a[j]&&!v[j])
				{
					flag=false;
					break;
				}
			}
			if(flag) 
			{
				if(!t&&a[i]==0) ;
				else
				{
					v[i]=1;
					b[t]=a[i];
					dfs(t+1);
					v[i]=0;
				}
				
			}
		}
	}
	return ;
	
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));		
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		dfs(0);
	
	}
 } 

