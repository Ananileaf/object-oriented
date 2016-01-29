#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		c=a+b;
		if(c<0)
		{
			printf("-");
			c*=-1;
		}
		if(c<1000) printf("%d",c);
		else if(c<1000000)
		{
			d=c%1000;
			c/=1000;
			printf("%d,%.3d\n",c,d);
		}
		else
		{
			d=c%1000;
			e=c%1000000;
			e/=1000;
			c/=1000000;
			printf("%d,%.3d,%.3d\n",c,e,d);
		}
	}
 } 
