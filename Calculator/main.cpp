#include "Calculation.h"
#include"Scan.h"
#include <iostream>
#include<sstream>
#include<cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char* argv[])	//��cmd���εķ�����������
{

	Scan get_scanf;
	if (strcmp(argv[1],"-a") == 0)
	{
		cout << argv[2] << " = ";
		get_scanf.ToStringQueue(argv[2]);	//����"-a"�������Ϊ����������
	}
	else
	{
		get_scanf.ToStringQueue(argv[1]);
	}

	if (!get_scanf.que.empty())		//��ն��б�ʾ�������ֳ���10λ
	{
		Calculation *cal = new Calculation;
		cal -> Calculate(get_scanf.que);	//����
	}
	else
	{
		cout << "error!" << endl;
	}
}

