#include <vcl.h>
#pragma hdrstop

#include "Unit4_MarksPage.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

static float average_mark = 0;

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
	String choosen_class_id = ListBox1->ItemIndex + 1;
	String choosen_subject_id = ListBox2->ItemIndex + 1;

	String query3 = "select info.id_person, name, surname from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id+"'";
	FDQuery3->SQL->Text = query3;
	FDQuery3->Active = true;

	int choosen_person_id = ListBox3->ItemIndex;
	FDQuery3->First();
	for(int i = 0; i < choosen_person_id; i++){
		FDQuery3->Next();
	}
	String query_id_person = FDQuery3->Fields->Fields[0]->AsString;

	String query4 = "select mark, date_of_adding, description from marks where marks.id_person = '"+query_id_person+"' and marks.id_subject ='"+choosen_subject_id+"'";
	FDQuery4->SQL->Text = query4;
	FDQuery4->Active = true;

	float average = 0;
	int number_of_marks = 0;

	if(!FDQuery4->Eof){
		int i = 0;
		FDQuery4->First();
		do{
			number_of_marks++;
			average += FDQuery4->Fields->Fields[0]->AsFloat;

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
	else if(FDQuery4->Eof){
		//Clearing grid
		for(int i = 0; i < StringGrid1->RowCount; i++){
			StringGrid1->Rows[i]->Clear();
		}
    }

	if(number_of_marks) average /= number_of_marks;
	average_mark = average;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image10Click(TObject *Sender)
{
    Label4->Caption = average_mark;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image8Click(TObject *Sender)
{

	bool grade_check = false;
	String grade = Edit1->Text;
	String date = DateTimePicker1->Date;
	String description = Edit2->Text;

	if(grade == "1" || grade == "1+" || grade == "1" || grade == "2" || grade == "2+" || grade == "2-" || grade == "3"
		|| grade == "3+" || grade == "3-" || grade == "4" || grade == "4+" || grade == "4-" || grade == "5" || grade == "5-"
		|| grade == "5+" || grade == "6" || grade == "6-" || grade == "0")
	{
		grade_check = true;
	}

	if(!grade_check) Edit1->Text = "Set the Grade";
	else
	{
		String choosen_class_id = ListBox1->ItemIndex + 1;
		String choosen_subject_id = ListBox2->ItemIndex + 1;

		String query3 = "select info.id_person, name, surname from info, class where info.id_person = class.id_person and class.id_class = '"+choosen_class_id+"'";
		FDQuery3->SQL->Text = query3;
		FDQuery3->Active = true;

		int choosen_person_id = ListBox3->ItemIndex;
		FDQuery3->First();
		for(int i = 0; i < choosen_person_id; i++){
			FDQuery3->Next();
		}
		String query_id_person = FDQuery3->Fields->Fields[0]->AsString;

		//"insert into data(id_person, login, password)values('"+ID_PERSON+"','"+entry_login+"','"+entry_password+"')";

		String query6 =  "insert into marks(id_person, id_subject, mark, date_of_adding, description)values('"+query_id_person+"','"+choosen_subject_id+"','"+grade+"','"+date+"','"+description+"')";
		Label5->Caption = query6;
        FDQuery6->SQL->Text = query6;
        FDQuery6->ExecSQL(true);
	}
}
//---------------------------------------------------------------------------

