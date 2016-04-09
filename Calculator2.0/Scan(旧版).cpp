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

/*************************************************************
  functionname:    GetString
  Description:     用于输入一个string类和返回这个string类,目
                   的是为了避免外界直接接触类中的string变量 
  Input:           NULL
  Return:          string s:类中的私有string类型的变量 
  Others:          NULL
**************************************************************/
string Scan::GetString()
{
	cin >> s;
	return s;
}

/*************************************************************
  functionname:    ToStringQueue
  Description:     将输入的字符串,逐个的字符扫描这，
                   将数字和符号提取出来分别存入队列 
  Input:           string input:输入字符串
  Return:         no return 
  Others:         NULL
**************************************************************/
void Scan::ToStringQueue(string input)
{
	string temp[100];               //默认为空串，用来存储数字和字符，传给队列
	bool flag = false;              //判断是否存在数超过10位
	bool flag_dot = false           //判断是否带小数点 
	int n = input.size(), coun = 0;
	temp[coun] += input[0];         //直接先存储输入字符串的第一个字符
	for (int i = 1; i < n; i++)   
	{
		if (flag)
		{
			break;
		} 	
		if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')   
		{
			if(input[i] == '.')
			{
				flag_dot = true;
			}
			if ((input[i-1] >= '0'&&input[i-1] <= '9')||input[i-1] == '.')
			{
				if(input[i-1] == '.')
		 	    {
				    flag_dot = true;
			    }
								
				/*判断前一个字符是不是数字或者小数点，如果是,则累计存储，先不传给队列*/
				temp[coun] += input[i];
				if (temp[coun].size() > 10)   //当前temp数组存的为数字,判断当前temp数组中的数字是否超过10位
				{
					
					/*超过10位,判断是不是带符号,如果带符号，则要超过11位*/
					if(temp[coun][0] == '-' || temp[coun][0] == '+')
					{
						if(temp[coun].size() == 12 && flag_dot == true)
						{
						}
						else if(temp[coun].size() > 11)
						{
							flag == true;
						}
					}
					else flag = true;
				}
			}
			else    //前一个字符是符号,下面分情况讨论
			{
				if (input[i-1] == '+' || input[i-1] == '-')    
				{
					if (i-2<0 || input[i-2]<'0' || input[i-2] > '9')    
					{
						temp[coun] += input[i];    
					}
					else    //如果符号前面是数字，那么该符号表示运算符
					{
						Scan::que.push(temp[coun++]);
						flag_dot = false;
						temp[coun] += input[i];
					}
				}
				else    //前面符号不是+，-，可以把temp传到队列，更新coun
				{
					if (temp[coun].size() > 10)   //判断是否超过10位，同理
					{
						if (temp[coun][0] == '-' || temp[coun][0] == '+')
						{
							if (temp[coun].size() > 11)
							{
								flag = true;
							}  
						}
						else
						{
							flag = true;
						 } 
					}
					Scan::que.push(temp[coun++]);
					flag_dot = false;
					temp[coun] += input[i];
				}
			}
		}
		else     //如果当前字符是符号,将temp传入队列，更新coun;
		{
			if (temp[coun].size() > 10)
			{

				if (temp[coun][0] == '-' || temp[coun][0] == '+')
				{
					if (temp[coun].size() > 11)  flag = true;
				}
				else flag = true;
			}
			Scan::que.push(temp[coun]);
			flag_dot = false;
			coun++;
			temp[coun] += input[i];
		}

	} 

	if (temp[coun].size() > 10)    
	{
		if (temp[coun][0] == '-' || temp[coun][0] == '+')
		{
			if (temp[coun].size() > 11)  flag = true;
		}
		else flag = true;
	}
	Scan::que.push(temp[coun]);
	coun++;
	if (flag)    
	{
		while (que.size())
		{
			que.pop();
		} 
		que.push("error:You can enter the number of digits can not be more than 10");
	}
}


