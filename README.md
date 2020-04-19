# FmtCppBuilder

It is a header-only wrapper to simplify the use of Sysutils::Format with C++Builder. Works with new clang-based compilers (i.e. bcc32c/bcc64).

## Getting Started

Have you ever used the 'Format' function with C++Builder? I mean the System.SysUtils.Format. The one in the header file <System.SysUtils.hpp>.

For example:

```
ShowMessage( Format ( _T( "X=%d, Y=%d" ), ARRAYOFCONST(( Left, Top )) );
```
<img src="https://i.ibb.co/hmcr1K4/1-3-B1402-B1-A98-B-4640-ABF3-3-F7-AD098-A484.png" alt="Figure 1">

It's a nice function the System.SysUtils.Format, apart from some 'glitches' with C++. For example, if you try to format floating point numbers other than long double (Extended in Delphi) there are problems. For example,  double is not supported out of the box
with bcc32c.

```
double a = 10.5;
ShowMessage( Format( _T( "a=%g" ), ARRAYOFCONST(( a )) ) );
```

<img src="https://i.ibb.co/2k0Z8Lj/2-3-B1402-B1-A98-B-4640-ABF3-3-F7-AD098-A484.png" alt="Figure 2">

In order to fix the problem you have to make a cast to long double.

```
double a = 10.5;
ShowMessage( Format( _T( "a=%g" ), ARRAYOFCONST(( static_cast<long double>( a ) )) ) );
```

<img src="https://i.ibb.co/yWWt7wX/3-3-B1402-B1-A98-B-4640-ABF3-3-F7-AD098-A484.png" alt="Figure 3">

The culprit is TVarRec which, e.g., manifests the problem when compiled with bcc32c. Since we can't change TVarRec, we can try to rewrite the Format function, making sure it can accept floating point parameters other than long double without reporting errors.

Another purpose of this library is to eliminate the need to use the ARRAYOFCONST macro, as horrible as almost all macros. The ARRAYOFCONST macro is a forced choice with compilers prior to the C++11 standard. But bcc32c and bcc64 are modern compilers and support 'variadic arguments', so you can get rid of the ARRAYOFCONST macro and get a simpler and cleaner use.
### Prerequisites

It surely works with RAD Studio or C++Builder from 10.3.3 and higher.

### Installing

Just add the SysUt.Fmt.h file to your project, then use it in all those units where you need to format the text.

For example:

```
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SysUt.Fmt.h"

#include "Unit1.h"

using SysUt::Fmt;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
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
```

Produces:

<img src="https://i.ibb.co/x3N6v21/4-3-B1402-B1-A98-B-4640-ABF3-3-F7-AD098-A484.png" alt="Figure 4">

The function is called Fmt and lives in the SysUt namespace.

Since the SysUt::Fmt is based on System::Sysutils::Format, the syntax of the formatting string does not change: please see the official help of RAD Studio or C++Builder for details.

As a bonus, there is also a wrapper around the OutputDebugString API which is used as the aforeseen Fmt function. The OutputDebugString function is very useful while debugging when breakpoints are too intrusive. Unfortunately, it is only able to accept LPTSTR. The wrapper around OutputDebugString provided here makes it easy to write variables' content in the IDE debug log pane.

For example:

```
SysUt::OutputDebugString( _T( "The 'this' pointer for '%s' is 0x%p: " ), Name, this );
```

<img src="https://i.ibb.co/Rc7NzKn/5-3-B1402-B1-A98-B-4640-ABF3-3-F7-AD098-A484.png" alt="Figure 5">

(see also the example project under 'test_app' directory)

## License

This project is licensed under the "The Unlicense".
