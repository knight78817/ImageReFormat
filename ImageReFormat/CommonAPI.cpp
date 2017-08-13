#include "StdAfx.h"
#include "CommonAPI.h"


bool ChoiseFolder(CString &FolderPath)
{
	CFolderPickerDialog tFolderPickerDialog(NULL);
	if(tFolderPickerDialog.DoModal() == IDCANCEL)
	{ return false; }
	FolderPath.Format("%s", tFolderPickerDialog.GetPathName());
	return true;
}
bool ParseFileNameWithExtension(CString FileNameWithExtension, CString &FileName, CString &ExtensionName)
{
	if( FileNameWithExtension.GetLength() < 0)
	{ return false; }
	FileName.Format("%s","");
	ExtensionName.Format("%s","");
	
	int tStart = 0 ;
	tStart = FileNameWithExtension.Find(".", tStart);
	for(int i = 0 ; i < FileNameWithExtension.GetLength() ; i++)
	{
		if(i < tStart)
		{ FileName.AppendChar(FileNameWithExtension.GetAt(i)); }
		else
		{ ExtensionName.AppendChar(FileNameWithExtension.GetAt(i)); }
	}
	return true;
}
	
bool IsImageExtension(CString Str, bool &IsImage)
{
	IsImage = false;
	if (Str.MakeLower().Compare(".bmp") == 0 )
	{ IsImage =true; }
	if (Str.MakeLower().Compare(".jpg") == 0 )
	{ IsImage =true; }
	if (Str.MakeLower().Compare(".jpeg") == 0 )
	{ IsImage =true; }
	if (Str.MakeLower().Compare(".png") == 0 )
	{ IsImage =true; }
	return true;
}