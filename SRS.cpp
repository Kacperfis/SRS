//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit5_AttendancePage.cpp", Form5);
USEFORM("Unit6_AnnouncementsPage.cpp", Form6);
USEFORM("Unit7_MessagingPage.cpp", Form7);
USEFORM("Unit8_SchedulePage.cpp", Form8);
USEFORM("Unit9_HomeworkPage.cpp", Form9);
USEFORM("Unit4_MarksPage.cpp", Form4);
USEFORM("Unit1_LogonPage.cpp", Form1);
USEFORM("Unit2_MainPage.cpp", Form2);
USEFORM("Unit3_AdministratorPage.cpp", Form3);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->CreateForm(__classid(TForm8), &Form8);
		Application->CreateForm(__classid(TForm9), &Form9);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
