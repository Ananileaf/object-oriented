#include<iostream>
using namespace std;
int main()
{
	char s[100],c;
	int i=0;
	while((c=getchar())!='\n') s[i++]=c;//gets���� 
	s[i]='\0';
	puts(s);
	i=0;
	
	while((c=getchar())!='\n'&&c!=' ')	s[i++]=c;//scanf���� 
	s[i]='\0';
	puts(s); 
}
