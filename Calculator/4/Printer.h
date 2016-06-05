#pragma once
/************************************************************
FileName: 	Printer.h
Author:       031502248
Date:         2016/5/2
Function:
��������йظ���Ŀ��Ҫ�������������
History:
<author>     <time>   <version>      <desc>
***********************************************************/
#include<string>
#include<cstring>
#include<iostream> 
#include<sstream>
#include "MyCalculator.h"
#include "Dlg.h"
#include "afxdialogex.h"
#include <string>
#include "CheckInpution.h"
#include "Calculation.h"
using namespace std;

class Printer
{
public:
	Printer();
	~Printer();
	virtual void PrErTpye(string ErrorType);
	void PrExpression(string Expression);
	virtual void PrResult(double Result);
	string tmp;
protected:
};

class FilePrinter :public Printer//������ļ���
{
public:
	FilePrinter();
	~FilePrinter();
	void FileOutput(const char Input[], const char Output[]);
private:

};


class DisplayPrinter :public Printer//�������������ʾ��
{
public:
	DisplayPrinter();
	~DisplayPrinter();
	const char * DisplayOutput(string str);
	void PrResult(double Result) override;

private:
	string ans;
	CheckInpution *ck;
	Calculation *cal;
};



class CmdPrinter :public Printer//�����cmdģʽ��
{
public:
	CmdPrinter();
	~CmdPrinter();
	void CmdInput(int argc, char* argv[]);
private:
};
