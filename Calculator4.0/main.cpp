#include"Calculation.h"
#include"Scan.h"
#include"Print.h"
#include"CheckInput.h"
#include<iostream>
#include<cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char* argv[])	//��cmd���εķ�����������
{

	Scan get_scanf;
	Print put_printf;
	if (strcmp(argv[1],"-a") == 0)
	{
		put_printf.PrExpression(argv[2]);	
		get_scanf.ToStringQueue(argv[2]);	//����"-a"�������Ϊ����������
	}
	else if (strcmp(argv[1],"-f") == 0)		//"-f" ���ļ�������� 
	{
		freopen(argv[2],"r",stdin);
		freopen(argv[3],"w",stdout);
		
		string str;
		cin >> str; 
		get_scanf.ToStringQueue(str);
	}
	else  
	{
		get_scanf.ToStringQueue(argv[1]);
	}
	
	CheckInput *ck = new CheckInput;
	get_scanf.ErrorType += ck->CheckIfCorrect(get_scanf.que); //��������������� 
	if (get_scanf.ErrorType == "")		    //�ж������Ƿ�Ϸ�,�޴���������Ϸ� 
	{
		Calculation *cal = new Calculation;
		cal->Calculate(get_scanf.que);	//����
		put_printf.PrResult(cal->result);
		delete  cal;
	}
	else
	{
		put_printf.PrErTpye(get_scanf.ErrorType);	//��������� 
	}
}

