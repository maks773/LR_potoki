//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "sqlite3.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int size = 0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	  try {
		StrToInt(Edit1->Text);
	  } catch (...) {
		MessageBox(GetActiveWindow(), L"Размер блока должен быть натуральным числом", NULL, MB_ICONERROR); return;
	  }

	  int size = StrToInt(Edit1->Text);
	  if (size <=0) {
	  MessageBox(GetActiveWindow(), L"Размер блока должен быть натуральным числом", NULL, MB_ICONERROR); return;
	  }

	  BYTE *data = new BYTE[size]; DWORD bytesRead;
	  HANDLE hDisk = CreateFileW(L"\\\\.\\C:", GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	  if (hDisk == INVALID_HANDLE_VALUE) {
	  MessageBox(GetActiveWindow(), L"Ошибка чтения диска", NULL, MB_ICONERROR); exit(1); }

	  for (int i=1; i<=100; i++) {

	  BOOL readRes = ReadFile(hDisk,data,size,&bytesRead,NULL);
	  if (readRes == false || bytesRead != size) {
	  MessageBox(GetActiveWindow(), L"Ошибка чтения файла", NULL, MB_ICONERROR); exit(2); }

	  FILE *ptrFile = fopen("file.txt", "a");
	  if (ptrFile != NULL) {
		for(int j=0; j<size; j++)     {
		if (data[j]<=15) fprintf(ptrFile, "0%X ", data[j]); else
		fprintf(ptrFile, "%X ", data[j]);
		if ((j+1)%16 ==0 && j!=0) {
		fprintf(ptrFile, "\t\t");
		for (int z = j-15; z<=j; z++)
		if (data[z]=='\n' || data[z]=='\r' || data[z]=='\v' || data[z]=='\t')  fprintf(ptrFile, " "); else
		fprintf(ptrFile, "%c", data[z]);
		fprintf(ptrFile, "\n");  }	  }
						 }
	  fprintf(ptrFile, "\n------------Считан %d-ый блок данных------------\n\n", i);
	  delete[] data;
	  fclose (ptrFile);
	  }
	  CloseHandle(hDisk);
}
//---------------------------------------------------------------------------

