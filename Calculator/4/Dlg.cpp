
// Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyCalculator.h"
#include "Dlg.h"
#include "Mydlg.h"
#include "afxdialogex.h"
#include "Scaner.h"
#include "Printer.h"
#include "CheckInpution.h"
#include "Calculation.h"
#include <Windows.h>
#include <string>
#include <afxwin.h>
#include <io.h>
#include <fcntl.h>
using namespace std;
#pragma warning(disable:4996)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框


void InitConsole()
{
	int nRet = 0;
	FILE* fp;
	AllocConsole();
	nRet = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	fp = _fdopen(nRet, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
}

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyDlg 对话框



CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY4_DIALOG, pParent)
	, expression(_T(""))
	, ans(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, expression);
	DDX_Text(pDX, IDC_EDIT3, ans);
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMyDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON12, &CMyDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON13, &CMyDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON7, &CMyDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMyDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMyDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMyDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON16, &CMyDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMyDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMyDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMyDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMyDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CMyDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDOK, &CMyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMyDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON23, &CMyDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON22, &CMyDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON24, &CMyDlg::OnBnClickedButton24)
//	ON_BN_CLICKED(IDC_BUTTON25, &CMyDlg::OnBnClickedButton25)
ON_BN_CLICKED(ID_BTN_ADD, &CMyDlg::OnBnClickedBtnAdd)
ON_BN_CLICKED(IDC_BUTTON26, &CMyDlg::OnBnClickedButton26)
END_MESSAGE_MAP()


// CMyDlg 消息处理程序

BOOL CMyDlg::OnInitDialog()
{
	//cmd命令行模式，但是没有成功
/*
for (int i = 0; i < __argc; i++)
	{
		__argv[i];
	}

	if (__argc > 1)
	{	//CString cstr;
		
		
		//freopen("CONIN$", "r", stdin);
		//cstr = "yes!\n"; 
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		CmdPrinter *p = new CmdPrinter;   //cmd下出错了

		cout << "yes" << endl;
		p->CmdInput(__argc, __argv);
		//MessageBox(cstr);
	}
	
	*/
	font.CreatePointFont(250, _T("黑体"), NULL);
	GetDlgItem(IDC_EDIT1)->SetFont(&font);
	GetDlgItem(IDC_EDIT3)->SetFont(&font);


	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
	

}


void CMyDlg::OnBnClickedButton1()//1
{
	UpdateData(TRUE);
	
	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	ToCalexpression += '1';
	expression += '1';

	UpdateData(FALSE);

	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton2()//2
{
	UpdateData(TRUE);
	if (JudgeIfEqualToClear)
	{
		expression = "";
		ans = "";
		ToCalexpression = "";
		JudgeIfEqualToClear = false;
	}

	expression += '2';
	ToCalexpression += '2';

	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton3()//3
{
	UpdateData(TRUE);
	if (JudgeIfEqualToClear)
	{
		expression = "";
		ans = "";
		ToCalexpression = "";
		JudgeIfEqualToClear = false;
	}

	expression += '3';
	ToCalexpression += '3';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton12()
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ans = "";
		ToCalexpression = "";
		JudgeIfEqualToClear = false;
	}

	expression += '+';
	ToCalexpression += '+';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton4()//4
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += '4';
	ToCalexpression += '4';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton5()//5
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += '5';
	ToCalexpression += '5';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton6()//6
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += '6';
	ToCalexpression += '6';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton13()
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += '-';
	ToCalexpression += '-';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton7()//7
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += '7';
	ToCalexpression += '7';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton8()//8
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += '8';
	ToCalexpression += '8';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton9()//9
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += '9';
	ToCalexpression += '9';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton10()
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ans = "";
		ToCalexpression = "";
		JudgeIfEqualToClear = false;
	}

	expression += '0';
	ToCalexpression += '0';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton16() //*
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ans = "";
		ToCalexpression = "";
		JudgeIfEqualToClear = false;
	}

	expression += "×";
	ToCalexpression += "*";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton17()
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += "÷";
	ToCalexpression += "/";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton18()
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ans = "";
		ToCalexpression = "";
		JudgeIfEqualToClear = false;
	}

	expression += '(';
	ToCalexpression += '(';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton19()
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ans = "";
		ToCalexpression = ""; 
		JudgeIfEqualToClear = false;
	}

	expression += ')';
	ToCalexpression += ')';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton20()
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression += '.';
	ToCalexpression += '.';
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton21()
{
	UpdateData(TRUE);
	expression = "";
	ToCalexpression = "";
	ans = "";
	UpdateData(FALSE);
	// TODO: 在此添加控
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMyDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMyDlg::OnBnClickedButton23()
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	expression = expression.Left(expression.GetLength() - 1);
	ToCalexpression = ToCalexpression.substr(0, ToCalexpression.length() - 1);

	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton22()//按键为"="
{
	UpdateData(TRUE);

	if (JudgeIfEqualToClear)
	{
		expression = "";
		ToCalexpression = "";
		ans = "";
		JudgeIfEqualToClear = false;
	}

	if (ToCalexpression.empty())
	{
		return;
	}

	JudgeIfEqualToClear = true;
	Scaner get_scanf;
	/*USES_CONVERSION;
	string tmp(W2A(expression));


	get_scanf.ToStringQueue(ToCalexpression);

	Printer put_printf;
	CheckInpution *ck = new CheckInpution;
	get_scanf.ErrorType += ck->CheckIfCorrect(get_scanf.que);
	if (get_scanf.ErrorType == "")
	{
		Calculation *cal = new Calculation;
		cal->Calculate(get_scanf.que);
		if (cal->ErrorType == "")
		{
			put_printf.PrResult(cal->result);
		}
		else
		{
			put_printf.PrErTpye(cal->ErrorType);
		}
		delete  cal;
	}
	else
	{
		put_printf.PrErTpye(get_scanf.ErrorType);
	}
	ans = put_printf.tmp.c_str();

	delete ck;
*/
	DisplayPrinter *p = new DisplayPrinter;
	ans = p->DisplayOutput(ToCalexpression);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}

BOOL  CMyDlg:: PreTranslateMessage(MSG* pMsg)
{

	if (pMsg->message == WM_KEYDOWN)
	{
		UINT key = pMsg->wParam;
		switch (key)
		{	
			case VK_ESCAPE: OnBnClickedButton21();  return true;//ESC
			case VK_RETURN: OnBnClickedButton22();  return true;//enter

			case 187:											//'=' + 组合数
			{
					if (GetKeyState(VK_SHIFT) < 0)
					{
						OnBnClickedButton12();//+
					}
					else
					{
						OnBnClickedButton22();//=
						return true;
					}
					break;
			}
			case VK_DECIMAL: OnBnClickedButton20();  break;//.
			case VK_BACK:   OnBnClickedButton23();	break;//BackSpace


				/*为了让方向键不能控制..*/
			case VK_LEFT:  return true;//
			case VK_UP:    return true;//
			case VK_RIGHT: return true;//
			case VK_DOWN:  return true;//
				

			

			case 48:									//0+组合数
			{
				if (GetKeyState(VK_SHIFT) < 0)
				{
					OnBnClickedButton19();//)
				}
				else
				{
					OnBnClickedButton10();//0
				}
				break;
			} 
			case VK_NUMPAD0: OnBnClickedButton10(); break;//0
			case VK_NUMPAD1: OnBnClickedButton1();  break;//1
			case 49 : OnBnClickedButton1();  break;//1
			case VK_NUMPAD2: OnBnClickedButton2();  break;//2
			case 50 : OnBnClickedButton2();  break;//2
			case VK_NUMPAD3: OnBnClickedButton3();  break;//3
			case 51: OnBnClickedButton3();  break;//3
			case VK_NUMPAD4: OnBnClickedButton4();  break;//4
			case 52: OnBnClickedButton4();  break;//4
			case VK_NUMPAD5: OnBnClickedButton5();  break;//5
			case 53: OnBnClickedButton5();  break;//5
			case VK_NUMPAD6: OnBnClickedButton6();  break;//6
			case 54: OnBnClickedButton6();  break;//6
			case VK_NUMPAD7: OnBnClickedButton7();  break;//7
			case 55: OnBnClickedButton7();  break;//7
			case VK_NUMPAD8: OnBnClickedButton8();  break;//8
			case 56:									  //8+组合数
			{	
				if (GetKeyState(VK_SHIFT) < 0)
				{
					OnBnClickedButton16();//*
				}
				else
				{
					OnBnClickedButton8();//8
				}
				break;
			}
			case VK_NUMPAD9: OnBnClickedButton9();  break;//9

			case 57:									  //9+组合数
			{
				if (GetKeyState(VK_SHIFT) < 0)
				{
					OnBnClickedButton18();//'('
				}
				else
				{
					OnBnClickedButton9();  //9
				}
				break;
			}
				
			

			case VK_ADD: OnBnClickedButton12();break;//
			case VK_SUBTRACT: OnBnClickedButton13(); break;//-
			case 189:   	  OnBnClickedButton13(); break;//-
			case VK_MULTIPLY: OnBnClickedButton16(); break;//*
			case VK_DIVIDE:   OnBnClickedButton17(); break;///

			

		}
	}

	return    CDialog::PreTranslateMessage(pMsg);
}

void CMyDlg::OnBnClickedButton24()
{
	CDialogEx::OnOK();
	//CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}

void CMyDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMyDlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedBtnAdd()
{
	UpdateData(TRUE);
	Mydlg Dlg;
	Dlg.DoModal();
	UpdateData(FALSE);

	// TODO: 在此添加控件通知处理程序代码
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMyDlg::OnBnClickedButton26()
{
	UpdateData(TRUE);
	CString cstr;
	cstr = "Author :  Anani_leaf\nBlog    :  http://home.cnblogs.com/u/Anani-leaf/\n";
	MessageBox(cstr);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}

