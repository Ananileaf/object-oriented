#include"Calculation.h"
#include"Scan.h"
#include"Print.h"
#include"CheckInput.h"
#include<iostream>
#include<cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char* argv[])	//用cmd传参的方法输入数据
{

	Scan get_scanf;
	Print put_printf;
	if (strcmp(argv[1],"-a") == 0)
	{
		put_printf.PrExpression(argv[2]);	
		get_scanf.ToStringQueue(argv[2]);	//含有"-a"情况数据为第三个参数
	}
	else if (strcmp(argv[1],"-f") == 0)		//"-f" 用文件输入输出 
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
	get_scanf.ErrorType += ck->CheckIfCorrect(get_scanf.que); //存入输入错误类型 
	if (get_scanf.ErrorType == "")		    //判断输入是否合法,无错误类型则合法 
	{
		Calculation *cal = new Calculation;
		cal->Calculate(get_scanf.que);	//计算
		put_printf.PrResult(cal->result);
		delete  cal;
	}
	else
	{
		put_printf.PrErTpye(get_scanf.ErrorType);	//输出计算结果 
	}
}

