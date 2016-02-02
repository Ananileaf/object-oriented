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
	char s[20];
	char ch;
	ch=cin.get();
	cout.put(ch);
	cin.get();
	cout<<endl;
	cin.getline(s,20);//cin.getline(s,20,'\0')默认'\0'
	cout<<s; 
	char d; 
	cout<<'a'<<'b'<<'\n';//用来验证缓冲区。。 
	cin>>d;
	cout<<d<<endl;
 } 
