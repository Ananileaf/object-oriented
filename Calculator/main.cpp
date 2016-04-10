#include "Calculation.h"
#include"Scan.h"
#include <iostream>
#include<sstream>
#include<cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char* argv[])	//用cmd传参的方法输入数据
{

	Scan get_scanf;
	if (strcmp(argv[1],"-a") == 0)
	{
		cout << argv[2] << " = ";
		get_scanf.ToStringQueue(argv[2]);	//含有"-a"情况数据为第三个参数
	}
	else
	{
		get_scanf.ToStringQueue(argv[1]);
	}

	if (!get_scanf.que.empty())		//令空队列表示存在数字超过10位
	{
		Calculation *cal = new Calculation;
		cal -> Calculate(get_scanf.que);	//计算
	}
	else
	{
		cout << "error!" << endl;
	}
}

