//---------------------------------------------------------------------------

#ifndef Unit7_MessagingPageH
#define Unit7_MessagingPageH
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
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *pi;
	TListBox *ListBox3;
	TImage *Image5;
	TListBox *ListBox1;
	TImage *Image3;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery2;
	TFDQuery *FDQuery3;
	TImage *Image2;
	TImage *Image4;
	TListBox *ListBox2;
	TImage *Image6;
	TEdit *Edit1;
	TImage *Image7;
	TMemo *Memo1;
	TFDQuery *FDQuery1;
	TFDQuery *FDQuery4;
	TFDQuery *FDQuery5;
	TFDQuery *FDQuery6;
	TDatePicker *DatePicker1;
	TFDQuery *FDQuery7;
	TFDQuery *FDQuery8;
	void __fastcall piClick(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall ListBox2Click(TObject *Sender);
	void __fastcall Memo1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif