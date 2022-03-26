#include <vcl.h>
#pragma hdrstop

#include "Unit4_MarksPage.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::piClick(TObject *Sender)
{
    Form4->Close();
}
//---------------------------------------------------------------------------




void __fastcall TForm4::Image4Click(TObject *Sender)
{
	String query2 = "select subject_name from subjects;";
	FDQuery2->SQL->Text = query2;
	FDQuery2->Active = true;

	if(ListBox2->Items->Count == 0){
		if(!FDQuery2->Eof){
			FDQuery2->First();
			do{
				String one = FDQuery2->Fields->Fields[0]->AsString;
				ListBox2->Items->Add(one);

				FDQuery2->Next();
			}while(!FDQuery2->Eof);
		}
	}
}
//---------------------------------------------------------------------------




void __fastcall TForm4::Image5Click(TObject *Sender)
{
	int choosen_class_id = ListBox1->ItemIndex + 1;
	String choosen_class_id_string = IntToStr(choosen_class_id);
	String query3 = "select info.id_person, name, surname from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id_string+"'";
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



void __fastcall TForm4::Image2Click(TObject *Sender)
{
	int choosen_class_id = ListBox1->ItemIndex + 1;
	String choosen_class_id_string = IntToStr(choosen_class_id);
	String query3 = "select info.id_person, name, surname from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id_string+"'";
	FDQuery3->SQL->Text = query3;
	FDQuery3->Active = true;

	String query_id_person = FDQuery3->Fields->Fields[0]->AsString;

	int choosen_student_id = ListBox3->ItemIndex + 1;
	String choosen_student_id_string = IntToStr(choosen_student_id);

	String query4 = "select mark, date_of_adding, description from marks where marks.id_person = '"+query_id_person+"'";
	FDQuery4->SQL->Text = query4;
	FDQuery4->Active = true;

	if(!FDQuery4->Eof){
		int i = 0;
		FDQuery4->First();
		do{
			String one = FDQuery4->Fields->Fields[0]->AsString;
			String two = FDQuery4->Fields->Fields[1]->AsString;
			String three = FDQuery4->Fields->Fields[2]->AsString;

			StringGrid1->Cells[0][i] = one;
			StringGrid1->Cells[1][i] = two;
			StringGrid1->Cells[2][i] = three;

			i++;
			FDQuery4->Next();
		}while(!FDQuery4->Eof);
	}
}
//---------------------------------------------------------------------------














