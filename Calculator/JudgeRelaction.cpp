#include "JudgeRelaction.h"
#include<cstring>
using namespace std;
JudgeRelaction::JudgeRelaction()
{
	p["+"] = 0;
	p["-"] = 1;
	p["*"] = 2;
	p["/"] = 3;
	p["("] = 4;
	p[")"] = 5;
	p["#"] = 6;
	
						//+-*/()#  竖op1,横op2
	strcpy(OprRelation[0],">><<<>>");//'+'
	strcpy(OprRelation[1],">><<<>>");//'-'
	strcpy(OprRelation[2],">>>><>>");//'*'
	strcpy(OprRelation[3],">>>><>>");//'/'
	strcpy(OprRelation[4],"<<<<<= ");//'('
	strcpy(OprRelation[5],">>>> >>");//')'
	strcpy(OprRelation[6],"<<<<< =");//'#'
}

/*************************************************************
  functionname:    JudIfChater
  Description:     判断是否为符号
  Input:            string ch:判断对象
  Return:         返回是否为符号的结果
  Others:         NULL
**************************************************************/
bool JudgeRelaction::JudIfChater(string ch)
{
	if (ch == "+" || ch == "-" || ch == "*"  || ch == "/"
	        || ch == "(" || ch ==")" || ch == "#")
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*************************************************************
  functionname:    JudPrChater
  Description:     判断两个符号的优先级
  Input:            string opr1:栈顶的符号
  					string opr2:队列传出的符号
  Return:         返回优先级关系
  Others:         1.默认优先级同级时,栈顶优先级高于队列
  				  2.'('')'与'#''#'最终不参与运算,
					所以用特殊优先级('=')另外考虑
**************************************************************/
char JudgeRelaction::JudPrChater(string opr1,string opr2)
{
	char ep = OprRelation[p[opr1]][p[opr2]];
	return ep;
}

JudgeRelaction::~JudgeRelaction()
{

}

