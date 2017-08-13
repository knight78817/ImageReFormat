#include <vector>
#include "CommonAPI.h"

// ImageReFormatDlg.h : 標頭檔
//

#pragma once

#define D_MAX_THREAD_NUMBER 4

#define D_THREAD_STATUS_RUN		0
#define D_THREAD_STATUS_IDLE	1
#define D_THREAD_STATUS_STOP	2
#define D_THREAD_STATUS_BREAK	3

struct S_ThreadStruct
{
	void * sImageReFormatDlg;
	int sThreadOrder;
};


// CImageReFormatDlg 對話方塊
class CImageReFormatDlg : public CDialogEx
{
// 建構
public:
	CImageReFormatDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_IMAGEREFORMAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援

	S_ThreadStruct m_ThreadStruct[4];

private:
	CString m_SrcFolderPath;
	CString m_DesFolderPath;
	
	std::vector<CString> m_FilesName;
	int m_NumberFiles;
	int m_IsThreadStatus;
	


public:
	CString GetSrcFolderPath();
	CString GetDesFolderPath();
	CString GetFileName(int Index);
	int GetNumberFiles();
	int GetIsThreadStatus();

	CComboBox m_Combo_TransformFormat;
	CProgressCtrl m_ProgressCtrl;
	CButton m_Check_ShowImage;
	CButton m_Check_DeleteOriginalImage;
	void ShowText(int PictureID, CString Text);
	void ShowImage(int PictureID, int Height, int Width, int WidthStep, int Channels, unsigned char * Data);
// 程式碼實作
protected:
	HICON m_hIcon;
	
	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBrowser();
	afx_msg void OnBnClickedButtonExecute();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonBrowserSource();
	afx_msg void OnBnClickedButtonBrowserDestination();
	afx_msg void OnEnKillfocusEditSourceFolderPath();
	afx_msg void OnEnKillfocusEditDestinationFolderPath();
	afx_msg void OnBnClickedButtonGetNumberOfFiles();
	afx_msg void OnDestroy();
};
