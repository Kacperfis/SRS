//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5_AttendancePage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Image4Click(TObject *Sender)
{
    String query2 = "select subject_name from subjects;";
	FDQuery2->SQL->Text = query2;
	FDQuery2->Active = true;

	if(ListBox2->Items->Count == 0)
	{
		if(!FDQuery2->Eof)
		{
			FDQuery2->First();
			do
			{
				String one = FDQuery2->Fields->Fields[0]->AsString;
				ListBox2->Items->Add(one);

				FDQuery2->Next();
			}while(!FDQuery2->Eof);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm5::piClick(TObject *Sender)
{
    Form5->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image5Click(TObject *Sender)
{
    int choosen_class_id = ListBox1->ItemIndex + 1;
	String choosen_class_id_string = IntToStr(choosen_class_id);
	String query3 = "select info.id_person, name, surname from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id_string+"'";
	FDQuery3->SQL->Text = query3;
	FDQuery3->Active = true;

	if(ListBox3->Items->Count != 0) ListBox3->Items->Clear();

	if(!FDQuery3->Eof)
	{
		FDQuery3->First();
		do
		{
			String one = FDQuery3->Fields->Fields[0]->AsString;
			String two = FDQuery3->Fields->Fields[1]->AsString;
			String three = FDQuery3->Fields->Fields[2]->AsString;
			ListBox3->Items->Add(one + " " + two + " " + three);

			FDQuery3->Next();
		}while(!FDQuery3->Eof);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image6Click(TObject *Sender)
{
	String choosen_class_id = ListBox1->ItemIndex + 1;
	String choosen_subject_id = ListBox2->ItemIndex + 1;

	String query3 = "select info.id_person, name, surname from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id+"'";
	FDQuery3->SQL->Text = query3;
	FDQuery3->Active = true;

	int choosen_person_id = ListBox3->ItemIndex;
	FDQuery3->First();
	for(int i = 0; i < choosen_person_id; i++)
	{
		FDQuery3->Next();
	}
    String person_id = FDQuery3->Fields->Fields[0]->AsString;
	String person_name = FDQuery3->Fields->Fields[1]->AsString;
	String person_surname = FDQuery3->Fields->Fields[2]->AsString;
	String type = "0";
	String date = DatePicker1->Date;

	ListBox4->Items->Add(person_name + " " + person_surname);

	String query4 = "insert into attendance(id_person, type, date, id_subject)values('"+person_id+"','"+type+"','"+date+"','"+choosen_subject_id+"')";
	FDQuery4->SQL->Text = query4;
	FDQuery4->ExecSQL(true);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image7Click(TObject *Sender)
{
	String choosen_class_id = ListBox1->ItemIndex + 1;
	String choosen_subject_id = ListBox2->ItemIndex + 1;

	String query3 = "select info.id_person, name, surname from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id+"'";
	FDQuery3->SQL->Text = query3;
	FDQuery3->Active = true;

	int choosen_person_id = ListBox3->ItemIndex;
	FDQuery3->First();
	for(int i = 0; i < choosen_person_id; i++)
	{
		FDQuery3->Next();
	}
	String person_id = FDQuery3->Fields->Fields[0]->AsString;
	String person_name = FDQuery3->Fields->Fields[1]->AsString;
	String person_surname = FDQuery3->Fields->Fields[2]->AsString;
	String type = "1";
	String date = DatePicker1->Date;

	ListBox5->Items->Add(person_name + " " + person_surname);

	String query4 = "insert into attendance(id_person, type, date, id_subject)values('"+person_id+"','"+type+"','"+date+"','"+choosen_subject_id+"')";
	FDQuery4->SQL->Text = query4;
	FDQuery4->ExecSQL(true);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image8Click(TObject *Sender)
{
	ListBox5->Items->Clear();

	String date = DatePicker1->Date;
	String choosen_subject_id = ListBox2->ItemIndex + 1;
	String query5 = "select name, surname from info, attendance where info.id_person = attendance.id_person and attendance.type = 1 and attendance.id_subject = '"+choosen_subject_id+"' and attendance.date = '"+date+"'";

	FDQuery5->SQL->Text = query5;
	FDQuery5->Active = true;

	if(!FDQuery5->Eof)
	{
		FDQuery5->First();
		do
		{
			String one = FDQuery5->Fields->Fields[0]->AsString;
			String two = FDQuery5->Fields->Fields[1]->AsString;
			ListBox5->Items->Add(one + " " + two);

			FDQuery5->Next();
		}while(!FDQuery5->Eof);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image9Click(TObject *Sender)
{
	ListBox5->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image10Click(TObject *Sender)
{
	ListBox4->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image2Click(TObject *Sender)
{
	ListBox4->Items->Clear();

	String date = DatePicker1->Date;
	String choosen_subject_id = ListBox2->ItemIndex + 1;
	String query6 = "select name, surname from info, attendance where info.id_person = attendance.id_person and attendance.type = 0 and attendance.id_subject = '"+choosen_subject_id+"' and attendance.date = '"+date+"'";

	FDQuery6->SQL->Text = query6;
	FDQuery6->Active = true;

	if(!FDQuery6->Eof)
	{
		FDQuery6->First();
		do
		{
			String one = FDQuery6->Fields->Fields[0]->AsString;
			String two = FDQuery6->Fields->Fields[1]->AsString;
			ListBox4->Items->Add(one + " " + two);

			FDQuery6->Next();
		}while(!FDQuery6->Eof);
	}
}
//---------------------------------------------------------------------------



