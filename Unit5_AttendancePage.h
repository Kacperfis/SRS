//---------------------------------------------------------------------------

#ifndef Unit5_AttendancePageH
#define Unit5_AttendancePageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.WinXPickers.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image3;
	TListBox *ListBox1;
	TImage *Image4;
	TListBox *ListBox2;
	TFDQuery *FDQuery2;
	TImage *pi;
	TImage *Image5;
	TListBox *ListBox3;
	TFDQuery *FDQuery3;
	TFDConnection *FDConnection1;
	TListBox *ListBox4;
	TImage *Image2;
	TImage *Image6;
	TImage *Image7;
	TListBox *ListBox5;
	TImage *Image8;
	TFDQuery *FDQuery4;
	TDatePicker *DatePicker1;
	TFDQuery *FDQuery5;
	TFDQuery *FDQuery6;
	TImage *Image9;
	TImage *Image10;
	TFDQuery *FDQuery8;
	TFDQuery *FDQuery7;
	TLabel *Label1;
	TImage *Image11;
	TDataSource *DataSource1;
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall piClick(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall Image8Click(TObject *Sender);
	void __fastcall Image9Click(TObject *Sender);
	void __fastcall Image10Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif