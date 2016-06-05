// Mydlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Mydlg.h"
#include "Dlg.h"
#include "Printer.h"
#include "afxdialogex.h"
#include "Resource.h"
#include<iostream>
using namespace std;


// Mydlg 对话框

IMPLEMENT_DYNAMIC(Mydlg, CDialogEx)

Mydlg::Mydlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDC_DLGTEST, pParent)
	, CsEditInput(_T(""))
	, CsEditOutput(_T(""))
{

}

Mydlg::~Mydlg()
{
}

void Mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, CsEditInput);
	DDX_Text(pDX, IDC_EDIT2, CsEditOutput);
}


BEGIN_MESSAGE_MAP(Mydlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Mydlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &Mydlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Mydlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Mydlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Mydlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Mydlg 消息处理程序


void Mydlg::OnEnChangeEdit1()
{
	UpdateData(TRUE);
	CString str;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	CsEditInput = str;
	UpdateData(FALSE);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Mydlg::OnEnChangeEdit2()
{
	UpdateData(TRUE);
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	CsEditOutput = str;

	UpdateData(FALSE);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Mydlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
		_T("All Files(*.*)|*.*||"), AfxGetMainWnd());
	if (dlg.DoModal() == IDOK)
	{
		CString str = dlg.GetPathName();
		CsEditInput = str;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void Mydlg::OnBnClickedButton2()
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
		_T("All Files(*.*)|*.*||"), AfxGetMainWnd());
	if (dlg.DoModal() == IDOK)
	{
		CString str = dlg.GetPathName();
		//GetDlgItem(IDC_BUTTON2)->SetWindowText(str);
		CsEditOutput = str;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void Mydlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	CString cstr;
	if (CsEditInput == "" || CsEditOutput == "")
	{
		cstr = "Error : Input can't be empty!";
		MessageBox(cstr);
		return;
	}
	cstr = "Finish!";//messagebox要放在最后,不然不会执行后面的内容


	USES_CONVERSION;
	string in(W2A(CsEditInput));
	string out(W2A(CsEditOutput));
	FilePrinter *foutput = new FilePrinter;

	foutput->FileOutput(in.c_str(), out.c_str());
	CsEditInput = "";
	CsEditOutput = "";
	in = "";
	out = "";
	MessageBox(cstr);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void Mydlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	CsEditInput = "";
	CsEditOutput = "";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
