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
  Description:     �ж��Ƿ���ڷǷ��ַ� 
  Input:           string input:�����ַ� 
  Return:         �жϽ�� 
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
  Description:     ��������ַ���,������ַ�ɨ���⣬
                   �����ֺͷ�����ȡ�����ֱ�������
  Input:           string input:�����ַ���
  Return:         no return
  Others:         NULL
**************************************************************/
void Scan::ToStringQueue(string input)
{
	stack<char> match;
	string temp = "";              //Ĭ��Ϊ�մ��������洢���ֺ��ַ�����������
	bool flag = false;             //�ж��Ƿ����������10λ
	bool flag_dot = false; 			//�ж��Ƿ��С����
	bool flag_match = true;        //�ж�ƥ������,���������Լ��Ƿ��д����ַ� 
	int n = input.size();
		
	if (input[0] == '(')			//��ջ�ж�����ƥ�� 
	{
		match.push('(');
	}
	else if(input[0] == ')') 
	{
		flag_match = false; 		//���Ų�ƥ�� 
	}
	
	temp += input[0];	    		//ֱ���ȴ洢�����ַ����ĵ�һ���ַ�
	
	if (input[0] == '-' && input[1] == '(')
	{
		que.push("0");   			//�����ͷ��-()��ʽ,���⴦��Ϊ0-()����ʽ
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
		
		if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')			//��ǰ�ַ������ֻ�С���� 
		{
			if (input[i] == '.')
			{
				flag_dot = true;
			}
			if ((input[i-1] >= '0' && input[i-1] <= '9') || input[i-1] == '.')
			{

				/*�ж�ǰһ���ַ��ǲ������ֻ���С���㣬�����,���ۼƴ洢���Ȳ���������*/
				temp += input[i];
			}
			else    //ǰһ���ַ��Ƿ���,������������
			{
				if (input[i-1] == '+' || input[i-1] == '-')
				{
					if ((i-2<0 || input[i-2]<'0' || input[i-2] > '9') && input[i-2] != ')' )
					{
						temp += input[i];
					}
					else    //�������ǰ�������֣���ô�÷��ű�ʾ�����
					{
						Scan::que.push(temp);
						temp = "";
						flag_dot = false;
						temp += input[i];
					}
				}
				else    //ǰ����Ų���+��-�����԰�temp�������У�����coun
				{
					Scan::que.push(temp);
					temp = "";
					flag_dot = false;
					temp += input[i];
				}
			}
		}
		else     	//�����ǰ�ַ��Ƿ���,��temp������У�����coun;
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
		
		if (!flag_match)	//��ƥ�� 
		{
			break;
		} 
		
		if (temp.size() > MAXDIGIT)   //���жϵ�ǰtemp�����е������Ƿ񳬹�10λ
		{

			/*����10λ,�ж��ǲ��Ǵ�����,��������ţ���Ҫ����11λ*/
			if (temp[0] == '-' || temp[0] == '+')
			{
				if (temp.size() == MAXDIGIT + 2 && flag_dot == true)		//�з�������С����Ҫ12λ����
				{
				}
				else if(temp.size() > MAXDIGIT + 1)		//�޷�����С����Ҫ11λ����
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
	if (flag || !flag_match || !match.empty())		//���ڳ���10λС��,Ϊ�˺����ж����error,��ն���
	{
		while (!que.empty())
		{
			que.pop();
		}
	}
}


