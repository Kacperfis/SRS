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

	 int return_id(string s){
		for(auto it : classes){
			if(it.second == s){
				return it.first;
			}
		}
        return -1;
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






void __fastcall TForm3::Add_user_buttonClick(TObject *Sender)
{

	if(Form_back->Visible == false){
	  Form_back->Visible = true;
	  Edit1->Visible = true;
	  Edit2->Visible = true;
	  Edit3->Visible = true;
	  Edit4->Visible = true;
	  Edit5->Visible = true;
	  Edit6->Visible = true;
	  Edit7->Visible = true;
	  Label1->Visible = true;
	  Label2->Visible = true;
	  Label3->Visible = true;
	  Label4->Visible = true;
	  Label5->Visible = true;
	  Label6->Visible = true;
	  Label7->Visible = true;
	  Label8->Visible = true;
	  Label9->Visible = true;
	  Button1->Visible = true;
	  ListBox1->Visible = true;
	  RadioButton1->Visible = true;
	  RadioButton2->Visible = true;
	}
	else{
	  Form_back->Visible = false;
	  Edit1->Visible = false;
	  Edit2->Visible = false;
	  Edit3->Visible = false;
	  Edit4->Visible = false;
	  Edit5->Visible = false;
	  Edit6->Visible = false;
	  Edit7->Visible = false;
	  Label1->Visible = false;
	  Label2->Visible = false;
	  Label3->Visible = false;
	  Label4->Visible = false;
	  Label5->Visible = false;
	  Label6->Visible = false;
	  Label7->Visible = false;
	  Label8->Visible = false;
      Label9->Visible = false;
	  Button1->Visible = false;
	  ListBox1->Visible = false;
	  RadioButton1->Visible = false;
	  RadioButton2->Visible = false;
    }

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


	 // Edit1->Text = ID_PERSON;
	 // Edit2->Text = ID_INFO;



	  String query1 = "insert into data(id_person, login, password)values('"+ID_PERSON+"','"+entry_login+"','"+entry_password+"')";
	  String query2 = "insert into info(id_info, id_person, name, surname, phone_number, email, PESEL)values('"+ID_INFO+"','"+ID_PERSON+"','"+name+"','"+surname+"','"+phone_number+"','"+email+"','"+pesel+"')";
	  String query3 = "insert into person_type(id_person, type)values('"+ID_PERSON+"','"+type+"')";

	  FDQuery1->SQL->Text = query1;
	  FDQuery2->SQL->Text = query2;
	  FDQuery3->SQL->Text = query3;

	  FDQuery1->ExecSQL(true);
	  FDQuery2->ExecSQL(true);
	  FDQuery3->ExecSQL(true);



	  /*
	  Edit1->Text = "";
	  Edit2->Text = "";
	  Edit3->Text = "";
	  Edit4->Text = "";
	  Edit5->Text = "";
	  Edit6->Text = "";
	  Edit7->Text = "";
      */
}
//---------------------------------------------------------------------------

