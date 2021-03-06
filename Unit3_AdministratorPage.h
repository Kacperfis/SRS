//---------------------------------------------------------------------------

#ifndef Unit3_AdministratorPageH
#define Unit3_AdministratorPageH
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
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *Background;
	TImage *pi;
	TImage *Add_user_button;
	TImage *Form_back;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TListBox *ListBox1;
	TButton *Button1;
	TLabel *Label9;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TFDQuery *FDQuery1;
	TFDQuery *FDQuery2;
	TFDQuery *FDQuery3;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery4;
	TFDQuery *FDQuery5;
	TFDQuery *FDQuery6;
	TImage *Image1;
	TImage *Image2;
	TEdit *Edit8;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TCheckBox *CheckBox1;
	TButton *Button2;
	TImage *Image7;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image11;
	TImage *Image13;
	TFDQuery *FDQuery7;
	TFDQuery *FDQuery8;
	TFDQuery *FDQuery9;
	TFDQuery *FDQuery10;
	TFDQuery *FDQuery11;
	TLabel *Label14;
	TImage *Image12;
	TImage *Image14;
	TDataSource *DataSource1;
	TLabel *Label10;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TFDQuery *FDQuery12;
	TFDQuery *FDQuery13;
	TFDQuery *FDQuery14;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TFDQuery *FDQuery15;
	TEdit *Edit9;
	TFDQuery *FDQuery16;
	TFDQuery *FDQuery17;
	TFDQuery *FDQuery18;
	TListBox *ListBox2;
	TEdit *Edit10;
	TImage *Image15;
	TImage *Image16;
	TImage *Image17;
	TFDQuery *FDQuery19;
	TDBGrid *DBGrid1;
	TChart *Chart1;
	TBarSeries *Series1;
	void __fastcall piClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit9Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Edit10Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Image16Click(TObject *Sender);
	void __fastcall Image17Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
