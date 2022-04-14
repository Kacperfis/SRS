//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9_HomeworkPage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::piClick(TObject *Sender)
{
    Form9->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Image4Click(TObject *Sender)
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

void __fastcall TForm9::Image2Click(TObject *Sender)
{
	String choosen_class_id = ListBox1->ItemIndex + 1;
	String choosen_subject_id = ListBox2->ItemIndex + 1;

	String query4 = "select content, start_data, end_data from homework where homework.id_class = '"+choosen_class_id+"' and homework.id_subject ='"+choosen_subject_id+"'";
	FDQuery4->SQL->Text = query4;
	FDQuery4->Active = true;

	int i = 0;
	if(!FDQuery4->Eof)
	{
		FDQuery4->First();
		do
		{
			String content = FDQuery4->Fields->Fields[0]->AsString;
			String start_data = FDQuery4->Fields->Fields[1]->AsString;
			String end_data = FDQuery4->Fields->Fields[2]->AsString;

			StringGrid1->Cells[0][i] = content;
			StringGrid1->Cells[1][i] = start_data;
			StringGrid1->Cells[2][i] = end_data;

            i++;
			FDQuery4->Next();
		}while(!FDQuery4->Eof);
	}
	else if(FDQuery4->Eof)
	{
		//Clearing grid
		for(int i = 0; i < StringGrid1->RowCount; i++)
		{
			StringGrid1->Rows[i]->Clear();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Image5Click(TObject *Sender)
{
	String starting_date = DatePicker1->Date;
	String end_date = DatePicker2->Date;
	String choosen_class_id = ListBox1->ItemIndex + 1;
	String choosen_subject_id = ListBox2->ItemIndex + 1;
	String content = Edit2->Text;

	String query1 =  "insert into homework(start_data, end_data, id_class, id_subject, content)values('"+starting_date+"','"+end_date+"','"+choosen_class_id+"','"+choosen_subject_id+"','"+content+"')";
	FDQuery1->SQL->Text = query1;
	FDQuery1->ExecSQL(true);
	ShowMessage("Homework added successfully");
}
//---------------------------------------------------------------------------

