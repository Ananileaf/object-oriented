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
bool vis[3][18]={0}; 
int node[8];
int coun=0;
void dfs(int t)
{	
 	if(t==8)
 	{
 		printf("(%d,%d)",0,node[0]);
 		for(int i=1;i<8;i++) printf("	(%d,%d)",i,node[i]);
 		printf("\n");
 		coun++;
 		return ;
	 }
	for(int i=0;i<8;i++)
	{
		if(!vis[0][i]&&!vis[1][i+t]&&!vis[2][t-i+8])
//V[0][i]表示记忆，vis[1][i]表示左下右上的斜线,vis[2][i]表现左上右下 
		{
		 		vis[0][i]=vis[1][i+t]=vis[2][t-i+8]=1;													 
			 	node[t]=i;
				dfs(t+1);
				vis[0][i]=vis[1][i+t]=vis[2][t-i+8]=0;
			
		}
		
	}
	return ;
 }
 int main()
 {
 	dfs(0);
 	printf("count=%d\n",coun);
  } 

