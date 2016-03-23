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
	
	/*temp作为中间变量,暂时存储将要存入队列中的元素,重复利用temp,或者用temp[100]与int类型变量coun,利用数组分别存储数字与字符,再存入队列 */
	string temp = "";
	bool flag = false;			//判断是否存在超过十位的数
	bool flag_dot = false;		//判断是否存在小数点 
	int n = input.size();		//n表示字符串的长度
	for (int i = 0; i<n; i++) 	//遍历字符串中的字符 
	{ 
		if (flag)    
		{ 
		    break;
		}
		if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')    
		{
			if (input[i] == '.') flag_dot = true;
			
			/*如果前面一位字符也是数字,或者当前字符是第一个字符,则先不将temp传入队列*/
			if (i == 0 || (input[i-1] >= '0' && input[i-1] <= '9' || input[i-1] == '.'))
			{
			}
			else if (temp.size())    //为了防止出现空串而错误将空串存入队列 
		    {
					Scan::que.push(temp);    
					flag_dot = false;
					temp = "";
			}
			temp += input[i];
			if (temp.size() > 10)    //判断是否存在超过10位的数字 
			{
				if (temp.size() == 11 && flag_dot == true)    //排除包含小数点而实际只有10位数的情况 
				{
				}
				else
				{
				    flag = true;
				} 
			}
		}
	    else    //当前字符是符号 
		{
			if (temp.size()>10) 
			{ 
				if (temp.size() == 11 && flag_dot)
				{
                } 
				else 
				{
					flag = true;
				} 
			}
			if (temp.size())     
			{ 
				Scan::que.push(temp);
				flag_dot = false;
				temp = "";
			}
			temp += input[i];
		}

	}
	
	/*遍历完成时,temp中依然有字符未存入队列,所以还需判断存在超过10位的数和将temp内容存入队列*/
	if (temp.size() > 10)    
	{ 
		if (temp.size() == 11 && flag_dot)
		{
		} 
		else
		{
			flag = true;
	    } 
	}
	if (temp.size()) 
	{
		Scan::que.push(temp);
		temp = ""; 
	}
	if (flag)    //判断如果存在超过十位的数,则只输出警告内容
	{ 
		while (!que.empty())    
		{
			que.pop();
		}    
		que.push("error:You can enter the number of digits can not be more than 10\n");
	}
	return ; 
}

