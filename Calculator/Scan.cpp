#include "Scan.h"
#include<cstring>
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
	string temp[100];//默认为空串，用来存储数字和字符，传给队列 
	bool flag=false;//判断是否存在数超过10位 
	int n=input.size(),coun=0;//n用于记录字符串长度,coun来控制将字符存入temp的不同数组中 
	temp[coun]+=input[0];//直接先存储输入字符串的第一个字符 
	for(int i=1;i<n;i++)//遍历字符串所有字符(除了第一个) 
	{
		if(flag) break;//如果存在数超过10位,直接跳出循环 
/*数*/	if(input[i]>='0'&&input[i]<='9'||input[i]=='.')//判断当前字符是不是数字或者小数点 
		{
			if((input[i-1]>='0'&&input[i-1]<='9')||input[i-1]=='.') 
			{
				//判断前一个字符是不是数字或者小数点，如果是,则累计存储，先不传给队列 				
				temp[coun]+=input[i];
				if(temp[coun].size()>10)//当前temp数组存的为数字,判断当前temp数组中的数字是否超过10位 
                   {	
                        //超过10位,判断是不是带符号,如果带符号，则要超过11位 
     			   		if(temp[coun][0]=='-'||temp[coun][0]=='+')
	            		{
					         if(temp[coun].size()>11)  flag=true;
 			            }  
	                     else flag=true;
		            }
			 } 			
        	else //前一个是符号,下面分情况讨论    100*(20+1)*1.00000000  这个是测试数据 
			{
			 	if(input[i-1]=='+'||input[i-1]=='-')//如果前面符号是+,或者-，再考虑2种情况， 
				{
					if(i-2<0||input[i-2]<'0'||input[i-2]>'9')//如果符号前不是数字,或者已经到字符串头了 
					{
						temp[coun]+=input[i];//那么该符号表示数字的正负，存储到temp,先不传给队列 
					}
					else //如果符号前面是数字，那么该符号表示运算符 
					{
						Scan::que.push(temp[coun++]);
						temp[coun]+=input[i];
					}
				}//前面符号不是+，-，可以把temp传到队列，更新coun 
				else 
				{
					if(temp[coun].size()>10)//判断是否超过10位，同理
                   {	
     			   		if(temp[coun][0]=='-'||temp[coun][0]=='+')
	            		{
					         if(temp[coun].size()>11)  flag=true;
 			            }  
	                     else flag=true;
		            }
					 
                    Scan::que.push(temp[coun++]);
					temp[coun]+=input[i];
				}			
			}			
		}
		else //如果当前字符是符号,将temp传入队列，更新coun; 
		{
		    if(temp[coun].size()>10)
			{
				
				if(temp[coun][0]=='-'||temp[coun][0]=='+')
				{
					if(temp[coun].size()>11)  flag=true;
				}
				else flag=true;
			 } 
			Scan::que.push(temp[coun]);	
			coun++; 
			temp[coun]+=input[i];
		}
		
	}//跳出循环了； 
	
	if(temp[coun].size()>10)//最后一个temp还没有存,判断同理 
	{				
	    if(temp[coun][0]=='-'||temp[coun][0]=='+')
	    {
	        if(temp[coun].size()>11)  flag=true;
	    }
	    else flag=true;
    } 
	Scan::que.push(temp[coun]);//存最后一个 
	coun++;
	if(flag)//如果超过10位,那么，把原来存进去的都清空，push上 下面的警告. 
	{
		while(que.size()) que.pop();
		que.push("error:You can enter the number of digits can not be more than 10");
	}
}

