
// 4Dlg.h : ͷ�ļ�
//

#pragma once
#include <string>
using namespace std;

// CMyDlg �Ի���
class CMyDlg : public CDialogEx
{
// ����
public:
	CMyDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	CString expression;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton22();
	BOOL PreTranslateMessage(MSG * pMsg);
	afx_msg void OnBnClickedButton24();

private :
	bool JudgeIfEqualToClear;
	string ToCalexpression;
	CFont font;
public:
	afx_msg void OnBnClickedButton11();
	CString ans;
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedButton26();
};
