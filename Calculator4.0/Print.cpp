#include "Print.h"

Print::Print()
{
}

Print::~Print()
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
void Print::PrExpression(string Expression)
{
	cout << Expression << "= " ;
}

/*************************************************************
  functionname:   PrErTpye
  Description:    �����������
  Input:          string ErrorType:����������� 
  Return:         no return
  Others:         PrErTypeΪprintErrorType����д 
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
  Description:    ��������� 
  Input:          double Result:������ 
  Return:         no return
  Others:         PrResultΪprintResult����д 
**************************************************************/
void Print::PrResult(double Result)
{
	cout << Result << endl;
}
