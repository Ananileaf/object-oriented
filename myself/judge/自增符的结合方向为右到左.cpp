#include<stdio.h>
#include<iostream>
using namespace std; 
int main()
{
	int i=1;
	int a,b;
	a=++i,b=++i;
	printf("a=%d b=%d\n",a,b);
	cout<<++i<<' '<<i++<<endl;
	i=3;
	cout<<i++<<' '<<i++; 
 } 
