//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class Ttoy : public TForm
{
__published:	// IDE-managed Components
	TTimer *timeRiseringEnergy;
	TTimer *timeLoweringEnergy;
	TButton *Energy;
	TLabel *energyLabel;
	TLabel *energyScale;
	TLabel *healthStatus;
	TLabel *satietyLabel;
	TLabel *setietyScale;
	TTimer *timeLoweringSetiety;
	TButton *toFeed;
	TTimer *timeToNextToFeed;
	TLabel *freshnessLebel;
	TLabel *freshnessScale;
	TButton *wash;
	TTimer *timeToWash;
	TTimer *timeToNextWashUp;
	TImage *pichu;
	TImage *pikachu;
	TImage *raichu;
	TTimer *timeToTransformation;
	TImage *deadTamagochi;
	void __fastcall EnergyClick(TObject *Sender);
	void __fastcall timeRiseringEnergyTimer(TObject *Sender);
	void __fastcall timeLoweringEnergyTimer(TObject *Sender);
	void __fastcall timeLoweringSetietyTimer(TObject *Sender);
	void __fastcall toFeedClick(TObject *Sender);
	void __fastcall timeToNextToFeedTimer(TObject *Sender);
	void __fastcall timeToWashTimer(TObject *Sender);
	void __fastcall washClick(TObject *Sender);
	void __fastcall timeToNextWashUpTimer(TObject *Sender);
	void __fastcall timeToTransformationTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Ttoy(TComponent* Owner);
	void death();
	int tamagochiEvolutionState; // 0 - pichu; 1 - pikachu; 2 - raichu
};
//---------------------------------------------------------------------------
extern PACKAGE Ttoy *toy;
//---------------------------------------------------------------------------
#endif
