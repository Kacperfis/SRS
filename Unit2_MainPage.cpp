//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2_MainPage.h"
#include "Unit1_LogonPage.h"
#include "Unit3_AdministratorPage.h"

//---------------------------------------------------------------------------
//<a href='https://www.freepik.com/vectors/background'>Background vector created by starline - www.freepik.com</a>
//<a href='https://www.freepik.com/vectors/button'>Button vector created by freepik - www.freepik.com</a>
//<a href='https://www.freepik.com/vectors/button'>Button vector created by freepik - www.freepik.com</a>
//<div>Icons made by <a href="https://www.freepik.com" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>
//<div>Icons made by <a href="https://www.freepik.com" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>
//<div>Icons made by <a href="https://www.freepik.com" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>
//<div>Icons made by <a href="https://www.flaticon.com/authors/dmitri13" title="dmitri13">dmitri13</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>


#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image2Click(TObject *Sender)
{
    Form3->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image11Click(TObject *Sender)
{
    Form1->Visible = true;
    Form2->Close();
}
//---------------------------------------------------------------------------


