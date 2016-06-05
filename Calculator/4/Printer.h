#pragma once
/************************************************************
FileName: 	Printer.h
Author:       031502248
Date:         2016/5/2
Function:
输出所有有关该项目需要输出的所有内容
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

class FilePrinter :public Printer//输出到文件中
{
public:
	FilePrinter();
	~FilePrinter();
	void FileOutput(const char Input[], const char Output[]);
private:

};


class DisplayPrinter :public Printer//输出到计算器显示上
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



class CmdPrinter :public Printer//输出到cmd模式上
{
public:
	CmdPrinter();
	~CmdPrinter();
	void CmdInput(int argc, char* argv[]);
private:
};
