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

	  switch (Form2->ComboBox1->ItemIndex) {
		case 0: size = 512; break;
		case 1: size = 1024; break;
		case 2: size = 4096; break;
		case 3: size = 8192; break;
	  default: size = 512;
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
	  if (Terminated) break;
	  }

	  CloseHandle(hDisk);
}
//---------------------------------------------------------------------------


