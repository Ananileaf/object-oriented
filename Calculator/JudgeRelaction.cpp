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
	
						//+-*/()#  ��op1,��op2
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
  Description:     �ж��Ƿ�Ϊ����
  Input:            string ch:�ж϶���
  Return:         �����Ƿ�Ϊ���ŵĽ��
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
  Description:     �ж��������ŵ����ȼ�
  Input:            string opr1:ջ���ķ���
  					string opr2:���д����ķ���
  Return:         �������ȼ���ϵ
  Others:         1.Ĭ�����ȼ�ͬ��ʱ,ջ�����ȼ����ڶ���
  				  2.'('')'��'#''#'���ղ���������,
					�������������ȼ�('=')���⿼��
**************************************************************/
char JudgeRelaction::JudPrChater(string opr1,string opr2)
{
	char ep = OprRelation[p[opr1]][p[opr2]];
	return ep;
}

JudgeRelaction::~JudgeRelaction()
{

}

