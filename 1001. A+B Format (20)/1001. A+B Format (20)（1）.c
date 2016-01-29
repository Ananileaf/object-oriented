#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a,b,c;
	char s[10];
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		c=a+b;
		sprintf(s,"%d",c);
	//	itoa(c,s,10); 
		int i=0,k=0;
		if(s[0]=='-')
		{
			printf("-");
			i=1;
		 } 
		 int n=strlen(s);
		 n-=i;//È¥¸ººÅ 
		 k=3-n%3; 
		while(s[i]!='\0')
		{
			printf("%c",s[i++]);
			k++;
			if(k%3==0&&k!=0&&s[i]!='\0') printf(",");
		}
		printf("\n");
//		printf("%s\n",s);
	}
	return 0;
 } 
