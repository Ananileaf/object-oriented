#include "stdafx.h"
#include "Printer.h"
#include "Scaner.h"
#include "afxwin.h"
#include <Windows.h>
#include "MyCalculator.h"
#include "Dlg.h"
#include "Mydlg.h"
#include "afxdialogex.h"
#include "Scaner.h"
#include "Printer.h"
#include "CheckInpution.h"
#include "Calculation.h"
#include <string>
#pragma warning(disable:4996)

Printer::Printer()
{
}

Printer::~Printer()
{
}


/*************************************************************
functionname:   PrExpression
Description:    输出表达式
Input:          string Expression:输入表达式
Return:         no return
Others:         PrExpression为printExpression的缩写
在保持可读性的情况下
**************************************************************/
void Printer::PrExpression(string Expression)
{
	cout << Expression << "= ";
}

/*************************************************************
functionname:   PrErTpye
Description:    输出错误类型
Input:          string ErrorType:输入错误类型
Return:         no return
Others:         PrErType为printErrorType的缩写
**************************************************************/
void Printer::PrErTpye(string ErrorType)
{
	if (ErrorType == "over")
	{
		cout << "Error! over ten digits limit." << endl;
		tmp = "Error!";
	}
	else if (ErrorType == "mismatch")
	{
		cout << "Error! Wrong expression." << endl;
		tmp = "Error!";
	}
	else if (ErrorType == "wrongch")
	{
		cout << "Error! Exist illegal character." << endl;
		tmp = "Error!";
	}
	else
	{
		cout << "Error!" << endl;
		tmp = "Error!";
	}
}

/*************************************************************
functionname:   PrResult
Description:    输出计算结果
Input:          double Result:计算结果
Return:         no return
Others:         PrResult为printResult的缩写
**************************************************************/
void Printer::PrResult(double Result)
{

	cout << Result << endl;
	stringstream stream;
	stream.clear();
	stream << Result;
	stream >> tmp;
}

FilePrinter::FilePrinter()
{
}

FilePrinter::~FilePrinter()
{
}

void FilePrinter::FileOutput(const char Input[], const char Output[])
{
	freopen(Input, "r", stdin);
	freopen(Output, "w", stdout);
	string str;
	while (cin >> str)
	{
		CheckInpution *ck = new CheckInpution;
		/*定义在循环内,缩小变量作用域,代替每次的初始化，避免造成多次输出留下问题 */
		Scaner get_scanf;
		get_scanf.ToStringQueue(str);
		get_scanf.ErrorType += ck->CheckIfCorrect(get_scanf.que); //存入输入错误类型
		if (get_scanf.ErrorType == "")					//判断输入是否合法,无错误类型则合法
		{
			Calculation *cal = new Calculation;
			cal->Calculate(get_scanf.que);				//计算
			PrResult(cal->result);
			delete  cal;
		}
		else
		{
			PrErTpye(get_scanf.ErrorType);	//输出计算结果
		}

		str = "";
		delete ck;
	}
}

DisplayPrinter::DisplayPrinter()
{
	ans = "";
	ck = new CheckInpution;
	cal = new Calculation;
}

DisplayPrinter::~DisplayPrinter()
{
	delete ck;
	delete cal;
}



const char * DisplayPrinter::DisplayOutput(string str)
{

	Scaner get_scanf;
	get_scanf.ToStringQueue(str);
	get_scanf.ErrorType += ck->CheckIfCorrect(get_scanf.que); //存入输入错误类型
	if (get_scanf.ErrorType == "")					//判断输入是否合法,无错误类型则合法
	{

		cal->Calculate(get_scanf.que);			//计算
		if (cal->ErrorType == "")
		{
			PrResult(cal->result);
		}
		else
		{
			ans = cal->ErrorType;
		}
	}
	else
	{
		ans = get_scanf.ErrorType;	//输出计算结果
	}
	return ans.c_str();
}

void DisplayPrinter::PrResult(double Result)
{
	stringstream stream;
	stream.clear();
	stream << Result;
	stream >> ans;
}

CmdPrinter::CmdPrinter()
{
}

CmdPrinter::~CmdPrinter()
{
}

void CmdPrinter::CmdInput(int argc, char* argv[])
{
	cout << "ee.." << endl;
		
	Scaner get_scanf;
	cout << "1" << endl;
	cout << *argv[1] << endl;
	cout << "2" << endl;
	get_scanf.ToStringQueue(argv[1]);		

	CheckInpution *ck = new CheckInpution;
	get_scanf.ErrorType += ck->CheckIfCorrect(get_scanf.que);
	if (get_scanf.ErrorType == "")
	{
			Calculation *cal = new Calculation;
			cal->Calculate(get_scanf.que);
			if (cal->ErrorType == "")
			{
				PrResult(cal->result);
			}
			else
			{
				PrErTpye(cal->ErrorType);
			}
			delete  cal;
	}
	else
	{
		PrErTpye(get_scanf.ErrorType);
	}
		delete ck;
}
