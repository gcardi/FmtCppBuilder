//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SysUt.Fmt.h"

#include "Unit1.h"

using SysUt::Fmt;
using SysUt::OutputDebugString;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    OutputDebugString( _T( "The 'this' pointer for '%s' is 0x%p: " ), Name, this );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Currency f = 23.45;
    double g = 10.55;
    float b = 11.15F;
    long double ld = 1923.328749;
    Memo1->Lines->Append(
        Fmt(
            _T( "" )
            "double g: %g\r\n"
            "float b: %g\r\n"
            "Currency f: %m\r\n"
            "a constant: %u\r\n"
            "long double: %g",
            g, b, f, 100, ld
        )
    );
}
//---------------------------------------------------------------------------


