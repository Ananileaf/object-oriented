#include "Print.h"

Print::Print()
{
}

Print::~Print()
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
void Print::PrExpression(string Expression)
{
	cout << Expression << "= " ;
}

/*************************************************************
  functionname:   PrErTpye
  Description:    输出错误类型
  Input:          string ErrorType:输入错误类型 
  Return:         no return
  Others:         PrErType为printErrorType的缩写 
**************************************************************/
void Print::PrErTpye(string ErrorType)
{
	if (ErrorType == "over")
	{
		cout << "Error! over ten digits limit." << endl; 
	}
	else if (ErrorType == "mismatch")
	{
		cout << "Error! Wrong expression." << endl; 	
	}
	else if (ErrorType == "wrongch")
	{
		cout << "Error! Exist illegal character." << endl; 
	} 
	else 
	{
		cout << "Error!" << endl;
	}
}

/*************************************************************
  functionname:   PrResult
  Description:    输出计算结果 
  Input:          double Result:计算结果 
  Return:         no return
  Others:         PrResult为printResult的缩写 
**************************************************************/
void Print::PrResult(double Result)
{
	cout << Result << endl;
}
