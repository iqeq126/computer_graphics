#include <windows.h> // ������ ���� ���� ���
// ase ���� �ҷ�����
char* glFileDlg(const char* filter) {
	const int file_name_len = 1024;
	static char fileName[file_name_len] = "";
	OPENFILENAME	open_file;
	memset(&open_file, 0, sizeof(OPENFILENAME)); // memset : �޸� ���� �Լ�. strcpy�� ������
	open_file.lStructSize = sizeof(OPENFILENAME); // OPENFILENAME Ÿ������ ũ�� ����
	open_file.hwndOwner = NULL;
	open_file.lpstrFilter = L"ASE 3D data (*.ase)\0*.ase\0All(*.*)\0*.*\0"; // ���ڵ� ��� ����
	open_file.nFilterIndex = 1; // 1ĭ�� �б�
	//open_file.lpstrFile = fileName;
	//open_file.nMaxFile = file_name_len;
	//open_file.lpstrTitle = L"Select a ASE file";
	//open_file.lpstrDefExt = L"ase";
	//open_file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	//char str[256];
	//WideCharToMultiByte(CP_ACP, 0, fileName, 256, str, 256, NULL, NULL);
	bool ret = GetOpenFileName(&open_file);	// ���� ���� ���� Ȯ��
	return (ret) ? fileName : NULL; // �̻�� NULL ��ȯ
}