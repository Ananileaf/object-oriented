#include "Scan.h"
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
#define MAXDIGIT 10
using namespace std;
Scan::Scan()
{
}

Scan::~Scan()
{
}

/*************************************************************
  functionname:    Judge
  Description:     判断是否存在非法字符 
  Input:           string input:输入字符 
  Return:         判断结果 
  Others:         NULL
**************************************************************/
bool Scan::Judge(char temp)
{
	if(temp >= '0' && temp <= '9' || temp == '.')
	{
		return true;
	}
	else if (temp == '+' || temp == '-' || temp == '*'  ||
	 temp == '/' || temp == '(' || temp == ')' )
	{
		return true;
	}
	return false; 
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
	stack<char> match;
	string temp = "";              //默认为空串，用来存储数字和字符，传给队列
	bool flag = false;             //判断是否存在数超过10位
	bool flag_dot = false; 			//判断是否带小数点
	bool flag_match = true;        //判断匹配问题,包括括号以及是否有错误字符 
	int n = input.size();
		
	if (input[0] == '(')			//入栈判断括号匹配 
	{
		match.push('(');
	}
	else if(input[0] == ')') 
	{
		flag_match = false; 		//括号不匹配 
	}
	
	temp += input[0];	    		//直接先存储输入字符串的第一个字符
	
	if (input[0] == '-' && input[1] == '(')
	{
		que.push("0");   			//如果开头是-()形式,特殊处理为0-()的形式
	}
	
	if	(!Judge(input[0]))
	{
		flag_match = false;
	}
	
	for (int i = 1; i < n; i++)
	{
			
		if	(!Judge(input[i]))
		{
			flag_match = false;
			break;
		}
		
		if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')			//当前字符是数字或小数点 
		{
			if (input[i] == '.')
			{
				flag_dot = true;
			}
			if ((input[i-1] >= '0' && input[i-1] <= '9') || input[i-1] == '.')
			{

				/*判断前一个字符是不是数字或者小数点，如果是,则累计存储，先不传给队列*/
				temp += input[i];
			}
			else    //前一个字符是符号,下面分情况讨论
			{
				if (input[i-1] == '+' || input[i-1] == '-')
				{
					if ((i-2<0 || input[i-2]<'0' || input[i-2] > '9') && input[i-2] != ')' )
					{
						temp += input[i];
					}
					else    //如果符号前面是数字，那么该符号表示运算符
					{
						Scan::que.push(temp);
						temp = "";
						flag_dot = false;
						temp += input[i];
					}
				}
				else    //前面符号不是+，-，可以把temp传到队列，更新coun
				{
					Scan::que.push(temp);
					temp = "";
					flag_dot = false;
					temp += input[i];
				}
			}
		}
		else     	//如果当前字符是符号,将temp传入队列，更新coun;
		{
		
			if(input[i] == '(')			
			{
				match.push('(');
			} 
			else if (input[i] == ')')
			{
				if (match.empty())
				{
					flag_match = false;
				} 				
				else if(match.top() == '(')
				{
					match.pop();
				}
				else
				{
					flag_match = false;
				}
			}
			
			Scan::que.push(temp);
			temp = "";
			flag_dot = false;
			temp += input[i];
		}
		
		if (!flag_match)	//不匹配 
		{
			break;
		} 
		
		if (temp.size() > MAXDIGIT)   //当判断当前temp数组中的数字是否超过10位
		{

			/*超过10位,判断是不是带符号,如果带符号，则要超过11位*/
			if (temp[0] == '-' || temp[0] == '+')
			{
				if (temp.size() == MAXDIGIT + 2 && flag_dot == true)		//有符号且有小数点要12位以上
				{
				}
				else if(temp.size() > MAXDIGIT + 1)		//无符号有小数点要11位以上
				{
					flag == true;
				}
			}
			else
			{
				if (temp.size() == MAXDIGIT + 1 && flag_dot == true)
				{
				}
				else
				{
					flag = true;
					break;
				}

			}
		}
		

	}

	Scan::que.push(temp);
	temp = "";
	if (flag || !flag_match || !match.empty())		//存在超过10位小数,为了后续判断输出error,清空队列
	{
		while (!que.empty())
		{
			que.pop();
		}
	}
}


