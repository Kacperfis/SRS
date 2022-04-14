//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7_MessagingPage.h"
#include "Unit1_LogonPage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;

static bool block;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::piClick(TObject *Sender)
{
    Form7->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Image5Click(TObject *Sender)
{
	String choosen_class_id = ListBox1->ItemIndex + 1;
	String query3 = "select info.id_person, name, surname from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id+"'";
	FDQuery3->SQL->Text = query3;
	FDQuery3->Active = true;

	if(ListBox3->Items->Count != 0) ListBox3->Items->Clear();

	if(!FDQuery3->Eof){
		FDQuery3->First();
		do{
			String one = FDQuery3->Fields->Fields[0]->AsString;
			String two = FDQuery3->Fields->Fields[1]->AsString;
			String three = FDQuery3->Fields->Fields[2]->AsString;
			ListBox3->Items->Add(one + " " + two + " " + three);

			FDQuery3->Next();
		}while(!FDQuery3->Eof);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Image2Click(TObject *Sender)
{
	if(block) ShowMessage("You cannot resend received message");
	else
	{
		//SENDER
		String sender_login = Form1->Login->Text;
		String sender_password = Form1->Password->Text;

		String query1 = "select id_person from data where login = '"+sender_login+"' and password = '"+sender_password+"'";
		FDQuery1->SQL->Text = query1;
		FDQuery1->Active = true;
		FDQuery1->First();
		String sender_id_person = FDQuery1->Fields->Fields[0]->AsString;

		//RECIPIENT
		String choosen_class_id = ListBox1->ItemIndex + 1;
		String query6 = "select info.id_person from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id+"'";
		FDQuery6->SQL->Text = query6;
		FDQuery6->Active = true;

		int choosen_person_id = ListBox3->ItemIndex;
		FDQuery6->First();
		for(int i = 0; i < choosen_person_id; i++)
		{
			FDQuery6->Next();
		}
		String recipient_id_person = FDQuery6->Fields->Fields[0]->AsString;

		//MESSAGE
		String sender_message[200];
		String parsed_message = "";

		for(int i = 0; i < Memo1->Lines->Count; i++){sender_message[i] = "";}
		for(int i = 0; i < Memo1->Lines->Count; i++)
		{
			sender_message[i] += (*(Memo1->Lines))[i];
			sender_message[i] += " #END# ";
			parsed_message += sender_message[i];
		}

		String message_date = DatePicker1->Date;
		String message_title = Edit1->Text;

		ListBox2->Items->Add(message_date);

		String query5 = "insert into messaging(sender, recipient, content, date, title)values('"+sender_id_person+"','"+recipient_id_person+"','"+parsed_message+"','"+message_date+"','"+message_title+"')";
		FDQuery5->SQL->Text = query5;
		FDQuery5->ExecSQL(true);
		ShowMessage("Message sent successfully");
		Edit1->Text = "";
		Memo1->Lines->Clear();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Image7Click(TObject *Sender)
{
	//RECIPIENT
	ListBox2->Clear();
	String recipient_login = Form1->Login->Text;
	String recipient_password = Form1->Password->Text;

	String query1 = "select id_person from data where login = '"+recipient_login+"' and password = '"+recipient_password+"'";
	FDQuery1->SQL->Text = query1;
	FDQuery1->Active = true;
	FDQuery1->First();
	String recipient_id_person = FDQuery1->Fields->Fields[0]->AsString;

	String query7 = "select sender, date, title, content from messaging where messaging.recipient = '"+recipient_id_person+"'";
	FDQuery7->SQL->Text = query7;
	FDQuery7->Active = true;

	if(FDQuery7->Eof)
	{
		ShowMessage("You have no messages received");
	}
	else
	{
		//SENDER
		String sender_id = FDQuery7->Fields->Fields[0]->AsString;
		String query8 = "select name, surname from info where info.id_person = '"+sender_id+"'";
		FDQuery8->SQL->Text = query8;
		FDQuery8->Active = true;
		String sender_name = FDQuery8->Fields->Fields[0]->AsString;
		String sender_surname = FDQuery8->Fields->Fields[1]->AsString;

		if(ListBox2->Items->Count != 0) ListBox2->Items->Clear();

		if(!FDQuery7->Eof){
			FDQuery7->First();
			do{
				String sender = (sender_name + " " + sender_surname);
				String date = FDQuery7->Fields->Fields[1]->AsString;
				String title = FDQuery7->Fields->Fields[2]->AsString;
				ListBox2->Items->Add(date + " | " + sender + " | " + title);

				FDQuery7->Next();
			}while(!FDQuery7->Eof);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ListBox2Click(TObject *Sender)
{
    block = true;
    Memo1->Lines->Clear();
	String recipient_login = Form1->Login->Text;
	String recipient_password = Form1->Password->Text;

	String query1 = "select id_person from data where login = '"+recipient_login+"' and password = '"+recipient_password+"'";
	FDQuery1->SQL->Text = query1;
	FDQuery1->Active = true;
	FDQuery1->First();
	String recipient_id_person = FDQuery1->Fields->Fields[0]->AsString;

	String query7 = "select sender, date, title, content from messaging where messaging.recipient = '"+recipient_id_person+"'";
	FDQuery7->SQL->Text = query7;
	FDQuery7->Active = true;

	String choosen_message_id = ListBox2->ItemIndex;
	FDQuery7->First();
	for(int i = 0; i < choosen_message_id; i++)
	{
		FDQuery7->Next();
	}
	String parsed_message = " ";
	parsed_message += FDQuery7->Fields->Fields[3]->AsString;
	parsed_message += "     ";

    //HANDLE MESSAGE
	String word = "";
	int i = 1;
	while(i + 5 < parsed_message.Length())
	{
		if(parsed_message[i+1] == '#' && parsed_message[i+2] == 'E' && parsed_message[i+3] == 'N'
		   && parsed_message[i+4] == 'D' && parsed_message[i+5] == '#')
		{
			if(word != "") Memo1->Lines->Append(word);
			word = "";
			if(i + 6 < parsed_message.Length()) i +=6;
			else break;
		}
		else
		{
			word += parsed_message[i];
			i++;
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm7::Memo1Change(TObject *Sender)
{
    block = false;
}
//---------------------------------------------------------------------------
