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
	char str1[100],str2[100]="hello";
	strcpy(str1,str2,2);//编译过不去，说明还是只能用strncpy 
	cout<<str1;
	
 } 
