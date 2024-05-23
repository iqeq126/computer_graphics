#include <windows.h> // 오류를 막기 위한 헤더
// ase 파일 불러오기
char* glFileDlg(const char* filter) {
	const int file_name_len = 1024;
	static char fileName[file_name_len] = "";
	OPENFILENAME	open_file;
	memset(&open_file, 0, sizeof(OPENFILENAME)); // memset : 메모리 복사 함수. strcpy와 유사함
	open_file.lStructSize = sizeof(OPENFILENAME); // OPENFILENAME 타입으로 크기 지정
	open_file.hwndOwner = NULL;
	open_file.lpstrFilter = L"ASE 3D data (*.ase)\0*.ase\0All(*.*)\0*.*\0"; // 인코딩 방식 지정
	open_file.nFilterIndex = 1; // 1칸씩 읽기
	//open_file.lpstrFile = fileName;
	//open_file.nMaxFile = file_name_len;
	//open_file.lpstrTitle = L"Select a ASE file";
	//open_file.lpstrDefExt = L"ase";
	//open_file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	//char str[256];
	//WideCharToMultiByte(CP_ACP, 0, fileName, 256, str, 256, NULL, NULL);
	bool ret = GetOpenFileName(&open_file);	// 파일 오픈 여부 확인
	return (ret) ? fileName : NULL; // 이상시 NULL 반환
}