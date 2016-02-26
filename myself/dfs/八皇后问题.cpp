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
#define INF 1000000007
using namespace std;
bool v[8]={0};
int node[8];
int coun=0;
void dfs(int t)
{	
 	if(t==8)
 	{
 		for(int i=0;i<8;i++) printf("(%d,%d) ",i,node[i]);
 		printf("\n");
 		coun++;
 		return ;
	 }
	for(int i=0;i<8;i++)
	{
		if(!v[i])
		{
			int flag=true;
			for(int j=0;j<t;j++)
			{
				if(node[j]==i-(t-j)||node[j]==i+(t-j))
				{
					flag=false;
					break;
				}
			 } 
			 if(flag)
			 {
			 	node[t]=i;
				v[i]=1;
				dfs(t+1);
				v[i]=0;
			 }
			
		}
		
	}
	return ;
 }
 int main()
 {
 	dfs(0);
 	printf("count=%d\n",coun);
  } 

