//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
//Photos taken from:
//<a href="https://www.freepik.com/vectors/background">Background vector created by liuzishan - www.freepik.com</a>
//<a href="https://stocksnap.io/photo/chalkboard-chalk-FQCCUDQ3N0">Photo</a> by <a href="https://stocksnap.io/author/flatlayphotos">Flat Lay Photos</a> on <a href="https://stocksnap.io">StockSnap</a>
//<a href='https://www.freepik.com/vectors/icons'>Icons vector created by starline - www.freepik.com</a>
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString entry_login, entry_password;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoginClick(TObject *Sender)
{
    Login->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PasswordClick(TObject *Sender)
{
	  Password->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::background_image1Click(TObject *Sender)
{
	 Login->Text = "Login";
     Password->Text = "Password";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::login_templateClick(TObject *Sender)
{
	 Login->Text = "Login";
	 Password->Text = "Password";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Login_buttonClick(TObject *Sender)
{
	  entry_login = Login->Text;
	  entry_password = Password->Text;

	  //database
	  //FDConnection1->Connected = false;
	 // FDConnection1->Connected = true;

	 // Label1->Caption = DBGrid1->Columns[0];
     //  DBText1->

}
//---------------------------------------------------------------------------













