//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <windows.h>
#pragma hdrstop

#include "Unit1_LogonPage.h"
#include "Unit2_MainPage.h"

//---------------------------------------------------------------------------
//Photos taken from:
//<a href="https://www.freepik.com/vectors/background">Background vector created by liuzishan - www.freepik.com</a>
//<a href="https://stocksnap.io/photo/chalkboard-chalk-FQCCUDQ3N0">Photo</a> by <a href="https://stocksnap.io/author/flatlayphotos">Flat Lay Photos</a> on <a href="https://stocksnap.io">StockSnap</a>
//<a href='https://www.freepik.com/vectors/icons'>Icons vector created by starline - www.freepik.com</a>
//<a href='https://www.freepik.com/vectors/background'>Background vector created by starline - www.freepik.com</a>
//<div>Icons made by <a href="https://www.freepik.com" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString entry_login, entry_password;
int counter = 0;

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
	  String entry_login = Login->Text;
	  String entry_password = Password->Text;
	  String query = "select id_person from data where login = '"+entry_login+"' and password = '"+entry_password+"'";


	  FDQuery1->SQL->Text = query;
	  FDQuery1->Active = true;
	  DataSource1->DataSet = FDQuery1;
	 // DBGrid1->DataSource = DataSource1;

	  if(!FDQuery1 ->Eof){ //login and go to main page
		 Form1->Visible = false;
		 Form2->Visible = true;


	  }
	  else{ //no records
		   ShowMessage("There is no such user. Please login to valid account");
	  }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1Click(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PasswordKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN){
		Form1->Login_buttonClick(Form1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LoginKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN){
		Form1->Login_buttonClick(Form1);
	}
}
//---------------------------------------------------------------------------

