//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3_AdministratorPage.h"
#include "Unit2_MainPage.h"
//---------------------------------------------------------------------------
//<a href='https://www.freepik.com/vectors/background'>Background vector created by starline - www.freepik.com</a>
//<a href='https://www.freepik.com/vectors/background'>Background vector created by freepik - www.freepik.com</a>
//<a href='https://www.freepik.com/photos/background'>Background photo created by benzoix - www.freepik.com</a>

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm3::piClick(TObject *Sender)
{
      Form3->Close();
}
//---------------------------------------------------------------------------

