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
  Description:     ��������һ��string��ͷ������string��,Ŀ
                   ����Ϊ�˱������ֱ�ӽӴ����е�string���� 
  Input:           NULL
  Return:          string s:���е�˽��string���͵ı��� 
  Others:          NULL
**************************************************************/
string Scan::GetString()
{
	cin >> s;
	return s;
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
	string temp[100];               //Ĭ��Ϊ�մ��������洢���ֺ��ַ�����������
	bool flag = false;              //�ж��Ƿ����������10λ
	bool flag_dot = false           //�ж��Ƿ��С���� 
	int n = input.size(), coun = 0;
	temp[coun] += input[0];         //ֱ���ȴ洢�����ַ����ĵ�һ���ַ�
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
								
				/*�ж�ǰһ���ַ��ǲ������ֻ���С���㣬�����,���ۼƴ洢���Ȳ���������*/
				temp[coun] += input[i];
				if (temp[coun].size() > 10)   //��ǰtemp������Ϊ����,�жϵ�ǰtemp�����е������Ƿ񳬹�10λ
				{
					
					/*����10λ,�ж��ǲ��Ǵ�����,��������ţ���Ҫ����11λ*/
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
			else    //ǰһ���ַ��Ƿ���,������������
			{
				if (input[i-1] == '+' || input[i-1] == '-')    
				{
					if (i-2<0 || input[i-2]<'0' || input[i-2] > '9')    
					{
						temp[coun] += input[i];    
					}
					else    //�������ǰ�������֣���ô�÷��ű�ʾ�����
					{
						Scan::que.push(temp[coun++]);
						flag_dot = false;
						temp[coun] += input[i];
					}
				}
				else    //ǰ����Ų���+��-�����԰�temp�������У�����coun
				{
					if (temp[coun].size() > 10)   //�ж��Ƿ񳬹�10λ��ͬ��
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
		else     //�����ǰ�ַ��Ƿ���,��temp������У�����coun;
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


