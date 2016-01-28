#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		
		int sum=0,x,y,a[110];
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++) 
		{
			scanf("%d %d",&x,&y);
			a[y]++;
			for(int j=y+1;j<101;j++) 
			{
				sum+=a[j];
				if(sum>=1000000) sum-=1000000;
			}
		}
		printf("%d\n",sum);
	}
}
