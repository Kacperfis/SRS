//---------------------------------------------------------------------------

#ifndef Unit4_MarksPageH
#define Unit4_MarksPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *pi;
	TListBox *ListBox1;
	TImage *Image3;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TDataSource *DataSource2;
	TFDQuery *FDQuery2;
	TImage *Image4;
	TListBox *ListBox2;
	TListBox *ListBox3;
	TImage *Image5;
	TFDQuery *FDQuery3;
	TImage *Image2;
	TStringGrid *StringGrid1;
	TFDQuery *FDQuery4;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TLabel *Label1;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit2;
	TFDQuery *FDQuery5;
	TEdit *Edit1;
	TImage *Image9;
	TImage *Image10;
	void __fastcall piClick(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif