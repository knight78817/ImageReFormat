#define D_MAX_FOLDER_PATH_LENGTH 256

bool ChoiseFolder(CString &FolderPath);

bool ParseFileNameWithExtension(CString FileNameWithExtension, CString &FileName, CString &ExtensionName);

bool IsImageExtension(CString Str, bool &IsImage);