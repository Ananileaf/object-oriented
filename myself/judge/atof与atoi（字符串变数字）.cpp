#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	char s1[]="53.2";
	char s2[]="23";
	printf("%d\n%.2f\n",atoi(s2),atof(s1));
	int a;
	double b;
	a=atoi(s2);
	b=atof(s1);
	printf("%d\n%.2f\n",a,b); 
	char s3[]="53.2";
	printf("%d\n%.2f\n",atof(s3),atof(s3));
	printf("%d\n%.2f\n",atoi(s3),atoi(s3));
	
 } 
