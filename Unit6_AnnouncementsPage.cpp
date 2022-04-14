//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6_AnnouncementsPage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::piClick(TObject *Sender)
{
    ListBox2->Clear();
    Form6->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button4Click(TObject *Sender)
{
	String content = Edit1->Text;
	if(content != "")
	{
		FDQuery1->SQL->Text = "insert into announcements(content)values('"+content+"')";
		FDQuery1->ExecSQL(true);
        Edit1->Text = "";
	}
    else Edit1->Text = "Please enter the text content";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button5Click(TObject *Sender)
{
    ListBox2->Clear();
	String query2 = "select content from announcements";
	FDQuery2->SQL->Text = query2;
	FDQuery2->Active = true;
	int counter = 0;
	if(!FDQuery2->Eof)
	{
		FDQuery2->First();
		do
		{
			counter++;
			String content = FDQuery2->Fields->Fields[0]->AsString;
			ListBox2->Items->Add((IntToStr(counter)) + ". " + content + ". \t");

			FDQuery2->Next();
		}while(!FDQuery2->Eof);
	}
	else ShowMessage("Announcements list is empty");
}
//---------------------------------------------------------------------------