//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#pragma package(smart_init)
extern int i; extern int size; extern BYTE *data;
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MyThread2::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall MyThread2::MyThread2(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall MyThread2::Execute()
{
	  FreeOnTerminate = true;
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
	fprintf(ptrFile, "\n------------—читан %d-ый блок данных------------\n\n", i);
	Form2->Label2->Caption = "—читан "+UnicodeString(i)+"-ый блок данных";
	delete[] data;
	fclose (ptrFile);
}
//---------------------------------------------------------------------------
