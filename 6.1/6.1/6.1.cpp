#include "afxwin.h"

boolean isValidText(CString text) {
	int count = 0;
	for (int i = 0; i < text.GetLength(); i++) {
		TCHAR currChar = text.GetAt(i);
		if (currChar == _T('(')) {
			count++;
		}
		else if (currChar == _T(')')) {
			count--;
			if (count < 0) {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return count == 0;
}

class CMyWindow : public CFrameWnd {

public:
	CMyWindow()
	{

		RECT myRect;
		myRect.left = 0;
		myRect.right = 800;
		myRect.top = 0;
		myRect.bottom = 600;

		Create(NULL, _T("Пример MFC окна"), WS_OVERLAPPEDWINDOW, myRect, nullptr, nullptr, WS_EX_WINDOWEDGE, nullptr);
		RECT buttonRect;
		buttonRect.left = 10;
		buttonRect.right = 100;
		buttonRect.top = 10;
		buttonRect.bottom = 40;
		myButton.Create(_T("Okay"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, buttonRect, this, 1);
		RECT staticRect;
		staticRect.left = 10;
		staticRect.right = 100;
		staticRect.top = 50;
		staticRect.bottom = 70;
		myStatic.Create(_T("This is static text"), WS_CHILD | WS_VISIBLE, staticRect, this, 2);


		editBox.Create(
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
			CRect(10, 80 + 10, 200, 80 + 30),
			this,
			3);

	}
protected:

	void OnButtonClicked()
	{
		CString text;
		editBox.GetWindowText(text);

		bool isValid = isValidText(text);

		CString answer = isValid ? " раставлены правильно" : " раставлены неверно";

		MessageBox(_T("Скобки: ") + text + answer, _T("My Application"), isValid ? MB_ICONINFORMATION : MB_ICONERROR);
	}

	CButton myButton;
	CStatic myStatic;
	CEdit editBox;

	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(CMyWindow, CFrameWnd)
	ON_COMMAND(1, &CMyWindow::OnButtonClicked)
END_MESSAGE_MAP()


class CMyApp : CWinApp
{
	virtual BOOL InitApplication()
	{
		this->m_pMainWnd = new CMyWindow();
		this->m_pMainWnd->ShowWindow(SW_SHOW);
		this->m_pMainWnd->UpdateWindow();

		return TRUE;
	}
};


CMyApp myApplication;
