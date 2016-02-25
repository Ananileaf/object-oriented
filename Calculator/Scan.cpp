#include "Scan.h"
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
Scan::Scan()
{
}

Scan::~Scan()
{
}
string Scan::GetString()
{
	cin>>s;
	return s;
}
void Scan::ToStringQueue(string input)
{
	string temp="";//重复利用temp,或者用temp[100],coun=0;利用数组分别存储 
	bool flag=false;	//判断是否存在超过十位的数 
	int n=input.size();//输入字符串的长度 
	for(int i=0;i<n;i++)//遍历字符串 
	{
		if(flag) break;//如果超过长度，就跳出,不用遍历了 
		if(input[i]>='0'&&input[i]<='9'||input[i]=='.')//判断是不是数字 
		{
			if(i==0||(input[i-1]>='0'&&input[i-1]<='9'||input[i-1]=='.')) ;//如果前面一位也是数字 
			else
			{
				if(temp.size())//因为i=0,可能是空的temp,所以保证不为空。如果前面一位不是数字,那么就把temp的符号传入队列，然后清空temp 
			    {
			 	  	 Scan::que.push(temp);//如果是用数组,那么这里是用temp[coun++],不用清空 
					 temp="";			
	 	         }
	 	         
			}
			temp+=input[i];	//无论有没有清空，当前是数字,存储 
			if(temp.size()>10) flag=true;//判断是否超过10位,33行之所以吧用判断，因为只有存储数字才有可能超过10位		
		}
		else 
		{
		    if(temp.size()>10) flag=true;//同理 
			 if(temp.size()) //同理 
			 {
			 	Scan::que.push(temp);
				temp="";			
			 }
			temp+=input[i];	
		}
		
	}
	if(temp.size()>10) flag=true;
	if(temp.size()) Scan::que.push(temp);
	if(flag)//如果有超过10位的数 
	{
		while(que.size()) que.pop();//全部清空 
		que.push("error:You can enter the number of digits can not be more than 10");//输出这个 
	}
}

