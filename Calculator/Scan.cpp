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
	string temp="";//�ظ�����temp,������temp[100],coun=0;��������ֱ�洢 
	bool flag=false;	//�ж��Ƿ���ڳ���ʮλ���� 
	int n=input.size();//�����ַ����ĳ��� 
	for(int i=0;i<n;i++)//�����ַ��� 
	{
		if(flag) break;//����������ȣ�������,���ñ����� 
		if(input[i]>='0'&&input[i]<='9'||input[i]=='.')//�ж��ǲ������� 
		{
			if(i==0||(input[i-1]>='0'&&input[i-1]<='9'||input[i-1]=='.')) ;//���ǰ��һλҲ������ 
			else
			{
				if(temp.size())//��Ϊi=0,�����ǿյ�temp,���Ա�֤��Ϊ�ա����ǰ��һλ��������,��ô�Ͱ�temp�ķ��Ŵ�����У�Ȼ�����temp 
			    {
			 	  	 Scan::que.push(temp);//�����������,��ô��������temp[coun++],������� 
					 temp="";			
	 	         }
	 	         
			}
			temp+=input[i];	//������û����գ���ǰ������,�洢 
			if(temp.size()>10) flag=true;//�ж��Ƿ񳬹�10λ,33��֮���԰����жϣ���Ϊֻ�д洢���ֲ��п��ܳ���10λ		
		}
		else 
		{
		    if(temp.size()>10) flag=true;//ͬ�� 
			 if(temp.size()) //ͬ�� 
			 {
			 	Scan::que.push(temp);
				temp="";			
			 }
			temp+=input[i];	
		}
		
	}
	if(temp.size()>10) flag=true;
	if(temp.size()) Scan::que.push(temp);
	if(flag)//����г���10λ���� 
	{
		while(que.size()) que.pop();//ȫ����� 
		que.push("error:You can enter the number of digits can not be more than 10");//������ 
	}
}

