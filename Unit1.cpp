//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include <windows.h>
#pragma package(smart_init)
int i; int size; BYTE *data;
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall MyThread::MyThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall MyThread::Execute(){

	  FreeOnTerminate = true;
	  size = 0;
	  try {
		StrToInt(Form2->Edit1->Text); }
	  catch (...) {
		MessageBox(GetActiveWindow(), L"Размер блока должен быть натуральным числом", NULL, MB_ICONERROR); return;
	  }

	  size = StrToInt(Form2->Edit1->Text);
	  if (size <=0) {
	  MessageBox(GetActiveWindow(), L"Размер блока должен быть натуральным числом", NULL, MB_ICONERROR); return;
	  }

	  data = new BYTE[size]; DWORD bytesRead = 1;
	  HANDLE hDisk = CreateFileW(L"\\\\.\\C:", GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	  if (hDisk == INVALID_HANDLE_VALUE) {
	  MessageBox(GetActiveWindow(), L"Ошибка чтения диска", NULL, MB_ICONERROR); exit(1); }
	  i=1; BOOL readRes = false;
	  //for (i=1; i<=10; i++) {
	  while(GetLastError()!= ERROR_HANDLE_EOF){
	  readRes = ReadFile(hDisk,data,size,&bytesRead,NULL);
	  if (readRes == false || bytesRead != size) {
	  MessageBox(GetActiveWindow(), L"Ошибка чтения файла", NULL, MB_ICONERROR); exit(2); }

	  myThreadPtr2 = new MyThread2(false);  Sleep(100); i++;
	  }

	  CloseHandle(hDisk);
}
//---------------------------------------------------------------------------


