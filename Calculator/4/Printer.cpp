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
Description:    ������ʽ
Input:          string Expression:������ʽ
Return:         no return
Others:         PrExpressionΪprintExpression����д
�ڱ��ֿɶ��Ե������
**************************************************************/
void Printer::PrExpression(string Expression)
{
	cout << Expression << "= ";
}

/*************************************************************
functionname:   PrErTpye
Description:    �����������
Input:          string ErrorType:�����������
Return:         no return
Others:         PrErTypeΪprintErrorType����д
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
Description:    ���������
Input:          double Result:������
Return:         no return
Others:         PrResultΪprintResult����д
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
		/*������ѭ����,��С����������,����ÿ�εĳ�ʼ����������ɶ������������� */
		Scaner get_scanf;
		get_scanf.ToStringQueue(str);
		get_scanf.ErrorType += ck->CheckIfCorrect(get_scanf.que); //���������������
		if (get_scanf.ErrorType == "")					//�ж������Ƿ�Ϸ�,�޴���������Ϸ�
		{
			Calculation *cal = new Calculation;
			cal->Calculate(get_scanf.que);				//����
			PrResult(cal->result);
			delete  cal;
		}
		else
		{
			PrErTpye(get_scanf.ErrorType);	//���������
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
	get_scanf.ErrorType += ck->CheckIfCorrect(get_scanf.que); //���������������
	if (get_scanf.ErrorType == "")					//�ж������Ƿ�Ϸ�,�޴���������Ϸ�
	{

		cal->Calculate(get_scanf.que);			//����
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
		ans = get_scanf.ErrorType;	//���������
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
