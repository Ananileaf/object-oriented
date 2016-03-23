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
	
	/*调用 GetString() 函数,利用其返回值将输入的字符串传递给 ToStringQueue() 函数*/
	get_scanf.ToStringQueue(get_scanf.GetString());	
	put_printf.que = get_scanf.que;
	put_printf.putqueue();    //调用函数输出分好的数字与字符 
	system("pause");
}

