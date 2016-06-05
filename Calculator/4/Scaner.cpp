#include "stdafx.h"
#include "Scaner.h"

#include "Scaner.h"

Scaner::Scaner()
{
	ErrorType = "";
}

Scaner::~Scaner()
{
}

/*************************************************************
functionname:    Judge
Description:     �ж��Ƿ���ڷǷ��ַ�
Input:           string input:�����ַ�
Return:         �жϽ��
Others:         NULL
**************************************************************/
bool Scaner::Judge(char temp)
{
	if (temp >= '0' && temp <= '9' || temp == '.')
	{
		return true;
	}
	else if (temp == '+' || temp == '-' || temp == '*'
		|| temp == '/' || temp == '(' || temp == ')')
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
void Scaner::ToStringQueue(string input)
{
	string temp = "";				//Ĭ��Ϊ�մ��������洢���ֺ��ַ�����������
	bool flag_digits = false;		//�ж��Ƿ����������10λ
	bool flag_dot = false;			//�ж��Ƿ��С����
	bool flag_ch = false;			//�жϷ���ڷǷ��ַ� 
	int n = input.size();

	temp += input[0];				//ֱ���ȴ洢�����ַ����ĵ�һ���ַ�	
	if (input[0] == '-' && input[1] == '(')
	{
		que.push("0");   			//�����ͷ��-()��ʽ,���⴦��Ϊ0-()����ʽ
	}
	if (!Judge(input[0]))			//�Ƿ���ڷǷ��ַ�
	{
		flag_ch = true;
	}

	for (int i = 1; i < n; i++)
	{

		if (!Judge(input[i]))
		{
			flag_ch = true;
			break;
		}

		/*��ǰ�ַ������ֻ�С���� */
		if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')
		{
			if (input[i] == '.')
			{
				flag_dot = true;
			}
			if ((input[i - 1] >= '0' && input[i - 1] <= '9') || input[i - 1] == '.')
			{

				/*�ж�ǰһ���ַ��ǲ������ֻ���С���㣬�����,���ۼƴ洢���Ȳ���������*/
				temp += input[i];
			}
			else    //ǰһ���ַ��Ƿ���,������������
			{
				if (input[i - 1] == '+' || input[i - 1] == '-')
				{
					if (i == 1 || (i - 2<0 || input[i - 2]<'0' || input[i - 2] > '9') && input[i - 2] != ')')
					{
						temp += input[i];
					}
					else    //�������ǰ�������֣���ô�÷��ű�ʾ�����
					{
						Scaner::que.push(temp);
						temp = "";
						flag_dot = false;
						temp += input[i];
					}
				}
				else    //ǰ����Ų���+��-�����԰�temp�������У�����coun
				{
					Scaner::que.push(temp);
					temp = "";
					flag_dot = false;
					temp += input[i];
				}
			}
		}
		else    //�����ǰ�ַ��Ƿ���,��temp������У�����coun;
		{

			Scaner::que.push(temp);
			temp = "";
			flag_dot = false;
			temp += input[i];
		}

		if (flag_ch || flag_digits)
		{
			break;
		}

		if (temp.size() > MAXDIGIT)   //���жϵ�ǰtemp�����е������Ƿ񳬹�10λ
		{

			/*����10λ,�ж��ǲ��Ǵ�����,��������ţ���Ҫ����11λ*/
			if (temp[0] == '-' || temp[0] == '+')
			{
				if (temp.size() == MAXDIGIT + 2 && flag_dot == true)	//�з�������С����Ҫ12λ����
				{
				}
				else if (temp.size() > MAXDIGIT + 1)		//�޷�����С����Ҫ11λ����
				{
					flag_digits = true;
					break;
				}
			}
			else
			{
				if (temp.size() == MAXDIGIT + 1 && flag_dot == true)
				{
				}
				else
				{
					flag_digits = true;
					break;
				}

			}
		}


	}

	que.push(temp);
	temp = "";

	if (flag_digits || flag_ch)		//���ڳ���10λС��,���ߴ��ڷǷ��ַ�,��ն���
	{
		while (!que.empty())
		{
			que.pop();
		}

		if (flag_digits)
		{
			ErrorType += "over";
		}
		if (flag_ch)
		{
			ErrorType += "wrongch";
		}
	}
}


