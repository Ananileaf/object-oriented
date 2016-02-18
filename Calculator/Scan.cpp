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
	string temp[100];
	bool flag=false;	
	int n=input.size(),coun=0;
	temp[coun]+=input[0];
	for(int i=1;i<n;i++)
	{
		if(flag) break;
		if(input[i]>='0'&&input[i]<='9'||input[i]=='.')
		{
			if((input[i-1]>='0'&&input[i-1]<='9')||input[i-1]=='.') temp[coun]+=input[i];
			else //100*(20+1)*1.00000000
			{
				if(input[i-1]=='+'||input[i-1]=='-')
				{
					if(i-2<0||input[i-2]<'0'||input[i-2]>'9')
					{
						temp[coun]+=input[i];
					}
					else 
					{
						if(temp[coun].size()>10)
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
				else 
				{
					if(temp[coun].size()>10)
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
		else 
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
		
	}
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
	if(flag)
	{
		while(que.size()) que.pop();
		que.push("error:You can enter the number of digits can not be more than 10");
	}
}

