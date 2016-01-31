#include<iostream>
using namespace std;
int main()
{
	char s[100],c;
	int i=0;
	while((c=getchar())!='\n') s[i++]=c;//gets´úÌæ 
	s[i]='\0';
	puts(s);
	i=0;
	
	while((c=getchar())!='\n'&&c!=' ')	s[i++]=c;//scanf´úÌæ 
	s[i]='\0';
	puts(s); 
}
