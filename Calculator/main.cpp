#include <iostream>
#include<cstdlib>
#include"Scan.h"
#include"Print.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main()
{
	Scan get_scanf;
	Print put_printf;
	
	/*���� GetString() ����,�����䷵��ֵ��������ַ������ݸ� ToStringQueue() ����*/
	get_scanf.ToStringQueue(get_scanf.GetString());	
	put_printf.que = get_scanf.que;
	put_printf.putqueue();    //���ú�������ֺõ��������ַ� 
	system("pause");
}

