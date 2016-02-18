#include <iostream>
#include<cstdlib> 
#include"Scan.h"
#include"Print.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main()
{
	Scan get_scanf;//..临时传代码改好看一点的 
	Print put_printf;//同理，定义 
	get_scanf.ToStringQueue(get_scanf.GetString());//调用函数输入 
	/*这里说一下，为什么不直接输入字符串,而是调用了一个函数,是对原始字符串数据进行封装
	 虽然本题意义不大，只是体现一下类的保密性而已*/
	put_printf.que2=get_scanf.que;//本来这里也是，嫌麻烦就没弄了 
	put_printf.putqueue();//调用函数输出 
	system("pause");
 } 
