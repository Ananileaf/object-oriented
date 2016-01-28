#include<stdio.h>
int main()
{
	double n;
	while(scanf("%lf",&n)!=EOF)
	{
		double sum=0;
		for(int i=n;i>=1;i--) sum+=1/i;
		printf("%.12lf\n",sum);
	}
} 
