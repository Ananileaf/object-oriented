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
	
	/*temp��Ϊ�м����,��ʱ�洢��Ҫ��������е�Ԫ��,�ظ�����temp,������temp[100]��int���ͱ���coun,��������ֱ�洢�������ַ�,�ٴ������ */
	string temp = "";
	bool flag = false;			//�ж��Ƿ���ڳ���ʮλ����
	bool flag_dot = false;		//�ж��Ƿ����С���� 
	int n = input.size();		//n��ʾ�ַ����ĳ���
	for (int i = 0; i<n; i++) 	//�����ַ����е��ַ� 
	{ 
		if (flag)    
		{ 
		    break;
		}
		if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')    
		{
			if (input[i] == '.') flag_dot = true;
			
			/*���ǰ��һλ�ַ�Ҳ������,���ߵ�ǰ�ַ��ǵ�һ���ַ�,���Ȳ���temp�������*/
			if (i == 0 || (input[i-1] >= '0' && input[i-1] <= '9' || input[i-1] == '.'))
			{
			}
			else if (temp.size())    //Ϊ�˷�ֹ���ֿմ������󽫿մ�������� 
		    {
					Scan::que.push(temp);    
					flag_dot = false;
					temp = "";
			}
			temp += input[i];
			if (temp.size() > 10)    //�ж��Ƿ���ڳ���10λ������ 
			{
				if (temp.size() == 11 && flag_dot == true)    //�ų�����С�����ʵ��ֻ��10λ������� 
				{
				}
				else
				{
				    flag = true;
				} 
			}
		}
	    else    //��ǰ�ַ��Ƿ��� 
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
	
	/*�������ʱ,temp����Ȼ���ַ�δ�������,���Ի����жϴ��ڳ���10λ�����ͽ�temp���ݴ������*/
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
	if (flag)    //�ж�������ڳ���ʮλ����,��ֻ�����������
	{ 
		while (!que.empty())    
		{
			que.pop();
		}    
		que.push("error:You can enter the number of digits can not be more than 10\n");
	}
	return ; 
}

