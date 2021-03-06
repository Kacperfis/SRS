#include <vcl.h>
#include <algorithm>
#include <map>
#include <string>

#pragma hdrstop

#include "Unit3_AdministratorPage.h"
#include "Unit2_MainPage.h"
//---------------------------------------------------------------------------
//<a href='https://www.freepik.com/vectors/background'>Background vector created by starline - www.freepik.com</a>
//<a href='https://www.freepik.com/vectors/background'>Background vector created by freepik - www.freepik.com</a>
//<a href='https://www.freepik.com/photos/background'>Background photo created by benzoix - www.freepik.com</a>

static int id_person = 1;
static int id_info = 1;
static int id_class = 1;

namespace std{
	map<int,string> classes = {{1, "1A"}, {2, "1B"}, {3, "2A"}, {4, "2B"}, {5, "3A"}, {6, "3B"},
	 {7, "4A"}, {8, "4B"}, {9, "5A"}, {10, "5B"}, {11, "6A"}, {12, "6B"}};

	 string return_id(int x){
		for(auto it : classes){
			if(it.first == x){
				return it.second;
			}
		}
		return "";
	 }
}

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

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	  String entry_login = Edit1->Text;
	  String entry_password = Edit2->Text;
	  String name = Edit3->Text;
	  String surname = Edit4->Text;
	  String phone_number = Edit5->Text;
	  String email = Edit6->Text;
	  String pesel = Edit7->Text;
	  int Listbox_index = ListBox1->ItemIndex + 1;
	  String type;
	  if(RadioButton1->Checked == true){
		 type = "Teacher";
	  }
	  else if(RadioButton2->Checked == true){
         type = "Student";
	  }

	  String query_id_person = "select max(id_person) from data";
	  String query_id_info = "select max(id_info) from info";

	  FDQuery4->SQL->Text = query_id_person;
	  FDQuery5->SQL->Text = query_id_info;

	  FDQuery4->Active = true;
	  FDQuery5->Active = true;

	  String ID_PERSON;
	  String ID_INFO;

	  ID_PERSON = FDQuery4->Fields->Fields[0]->AsString;
	  int temp_id_person = ID_PERSON.ToInt();
	  temp_id_person++;
	  ID_PERSON = IntToStr(temp_id_person);

	  ID_INFO = FDQuery5->Fields->Fields[0]->AsString;
	  int temp_id_info = ID_INFO.ToInt();
	  temp_id_info++;
	  ID_INFO = IntToStr(temp_id_info);

	  int list_id = ListBox1->ItemIndex + 1;
	  std::string klasa = std::return_id(list_id);
	  AnsiString Ansiklasa = AnsiString(klasa.c_str());

	  if(RadioButton1->Checked == true){
		 String query15 = "insert into form_teacher(id_person, id_class)values('"+ID_PERSON+"','"+list_id+"')";
		 FDQuery15->SQL->Text = query15;
		 FDQuery15->ExecSQL(true);
	  }
	  if(Edit1->Text != "" && Edit2->Text != "" && Edit3->Text != "" && Edit4->Text != "" && Edit5->Text != "" && Edit6->Text != "" && Edit7->Text != "" && (RadioButton1->Checked == true || RadioButton2->Checked == true)){
		  String query1 = "insert into data(id_person, login, password)values('"+ID_PERSON+"','"+entry_login+"','"+entry_password+"')";
		  String query2 = "insert into info(id_info, id_person, name, surname, phone_number, email, PESEL)values('"+ID_INFO+"','"+ID_PERSON+"','"+name+"','"+surname+"','"+phone_number+"','"+email+"','"+pesel+"')";
		  String query3 = "insert into person_type(id_person, type)values('"+ID_PERSON+"','"+type+"')";
		  String query6 = "insert into class(id_person, id_class, class)values('"+ID_PERSON+"','"+list_id+"','"+Ansiklasa+"')";

		  FDQuery1->SQL->Text = query1;
		  FDQuery2->SQL->Text = query2;
		  FDQuery3->SQL->Text = query3;
		  FDQuery6->SQL->Text = query6;

		  FDQuery1->ExecSQL(true);
		  FDQuery2->ExecSQL(true);
		  FDQuery3->ExecSQL(true);
		  FDQuery6->ExecSQL(true);

		  ShowMessage("User added succesfully");

		  Edit1->Text = "";
		  Edit2->Text = "";
		  Edit3->Text = "";
		  Edit4->Text = "";
		  Edit5->Text = "";
		  Edit6->Text = "";
		  Edit7->Text = "";
		  RadioButton1->Checked = false;
		  RadioButton2->Checked = false;
	  }
	  else{
	      ShowMessage("You must enter all the data");
      }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	String input_pesel = Edit8->Text;
	if(CheckBox1->Checked == true){
        Label14->Visible = false;
		String query = "select id_person from info where pesel = '"+input_pesel+"'";
		FDQuery7->SQL->Text = query;
		FDQuery7->Active = true;
		if(!FDQuery7->Eof){
			String ERASE_ID;
			ERASE_ID = FDQuery7->Fields->Fields[0]->AsString;
			String erase_query1 = "delete from data where id_person = '"+ERASE_ID+"'";
			String erase_query2 = "delete from class where id_person = '"+ERASE_ID+"'";
			String erase_query3 = "delete from info where id_person = '"+ERASE_ID+"'";
			String erase_query4 = "delete from person_type where id_person = '"+ERASE_ID+"'";

			FDQuery8->SQL->Text = erase_query1;
			FDQuery9->SQL->Text = erase_query2;
			FDQuery10->SQL->Text = erase_query3;
			FDQuery11->SQL->Text = erase_query4;

			FDQuery8->ExecSQL(true);
			FDQuery9->ExecSQL(true);
			FDQuery10->ExecSQL(true);
			FDQuery11->ExecSQL(true);

			ShowMessage("User removed succesfully");
			CheckBox1->Checked == false;
		}
	}
	else{
		Label14->Visible = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
	String num_students_query = "select count(*) from person_type where type = 'Student'";
	String num_teachers_query = "select count(*) from person_type where type = 'Teacher'";
	String num_total_query = "select count(*) from person_type";

	FDQuery12->SQL->Text = num_students_query;
	FDQuery13->SQL->Text = num_teachers_query;
	FDQuery14->SQL->Text = num_total_query;

	FDQuery12->Active = true;
	FDQuery13->Active = true;
	FDQuery14->Active = true;

	String num_students = FDQuery12->Fields->Fields[0]->AsString;
	String num_teachers = FDQuery13->Fields->Fields[0]->AsString;
	String num_total = FDQuery14->Fields->Fields[0]->AsString;

	Label10->Caption = num_students;
	Label15->Caption = num_teachers;
	Label16->Caption = "12";   //numer of classes
    Label17->Caption = num_total;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Edit9Click(TObject *Sender)
{
    Edit9->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{

	//String query15 = "insert into form_teacher(id_person, id_class)values('"+ID_PERSON+"','"+list_id+"')";
	if(Edit9->Text != ""){
		String content = Edit9->Text;
		String query16 = "insert into admin_tasks(task_message)values('"+content+"')";
		FDQuery16->SQL->Text = query16;
		FDQuery16->ExecSQL(true);
		ShowMessage("Task added succesfully");
		Edit9->Text = "Your task content";
	}
	else ShowMessage("You cannot add task with empty content");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
	//clear the ListBox
	ListBox2->Clear();
	//if(ListBox2->Items->Count == 0){
		String query17 = "select * from admin_tasks";
		FDQuery17->SQL->Text = query17;
		FDQuery17->Active = true;

		if(!FDQuery17->Eof){
			FDQuery17->First();
			do{
				String one = FDQuery17->Fields->Fields[0]->AsString;
				String two = FDQuery17->Fields->Fields[1]->AsString;

				ListBox2->Items->Add(one + ". \t" + two);

				FDQuery17->Next();
			}while(!FDQuery17->Eof);
		}
		else ShowMessage("Task list is empty");
   //	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit10Click(TObject *Sender)
{
    Edit10->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button6Click(TObject *Sender)
{
	String temp_id = Edit10->Text;
	String query18 = "delete from admin_tasks where id_task = '"+temp_id+"'";
	FDQuery18->SQL->Text = query18;
	FDQuery18->ExecSQL(true);
	ShowMessage("Task deleted succesfully");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image16Click(TObject *Sender)
{
	String query19 = "select name, surname, phone_number, email, PESEL, class from info, class, person_type where info.id_person = class.id_person and person_type.id_person = info.id_person and person_type.type = 'Teacher';";
	FDQuery19->SQL->Text = query19;
	FDQuery19->Active = true;
}
//---------------------------------------------------------------------------




void __fastcall TForm3::Image17Click(TObject *Sender)
{
	String query19 = "select name, surname, phone_number, email, PESEL, class from info, class, person_type where info.id_person = class.id_person and person_type.id_person = info.id_person and person_type.type = 'Student';";
	FDQuery19->SQL->Text = query19;
	FDQuery19->Active = true;
}
//---------------------------------------------------------------------------

