//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

typedef void  (WINAPI* f_test)();
f_test test = NULL;

//#   pragma comment (lib, "MEMMGR.lib")

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	HINSTANCE h = LoadLibraryW(L"Project4.dll");
	test = (f_test)GetProcAddress( h, "test" );
	test();
	FreeLibrary(h);
}
//---------------------------------------------------------------------------
