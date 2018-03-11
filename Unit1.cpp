//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.XLgXhdpiTb.fmx", _PLAT_ANDROID)
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.LgXhdpiTb.fmx", _PLAT_ANDROID)

Ttoy *toy;


//---------------------------------------------------------------------------
__fastcall Ttoy::Ttoy(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Ttoy::EnergyClick(TObject *Sender)
{
	if (Energy->Text == "Go to bed") {
		Energy->Text = "Wake up";
		timeLoweringSetiety->Interval = 5000;
		toFeed->Enabled = 0;
		timeToWash->Interval = 2000;
		wash->Enabled = 0;
	}
	else if (Energy->Text == "Wake up") {
			Energy->Text = "Go to bed";
			timeLoweringSetiety->Interval = 1000;
			if (timeToNextToFeed->Enabled == 0) {
				toFeed->Enabled = 1;
			}
			if (timeToNextWashUp->Enabled == 0) {
				wash->Enabled = 1;
			}
			timeToWash->Interval = 5000;
		 }
	timeRiseringEnergy->Enabled = !timeRiseringEnergy->Enabled;
	timeLoweringEnergy->Enabled = !timeRiseringEnergy->Enabled;

}
//---------------------------------------------------------------------------
void __fastcall Ttoy::timeRiseringEnergyTimer(TObject *Sender)
{
	if (StrToInt(energyScale->Text) < 95) {
		energyScale->Text = StrToInt(energyScale->Text) + 10;
	}
	else {
		energyScale->Text = 100;
    }

}
//---------------------------------------------------------------------------
void __fastcall Ttoy::timeLoweringEnergyTimer(TObject *Sender)
{
	energyScale->Text = StrToInt(energyScale->Text) - 5;
	if (energyScale->Text <= 30) {
		healthStatus->Text = "I want to sleep!";
	}
	if (energyScale->Text <= 0) {
		death();
	}
}
//---------------------------------------------------------------------------
void Ttoy::death(){
	healthStatus->Text = "Your Tamagochi is dead!(((";

	timeRiseringEnergy->Enabled = 0;
	timeLoweringEnergy->Enabled = 0;
	timeLoweringSetiety->Enabled = 0;
	timeToNextToFeed->Enabled = 0;
	timeToNextWashUp->Enabled = 0;
	timeToWash->Enabled = 0;
	timeToTransformation->Enabled = 0;

	wash->Enabled = 0;
	toFeed->Enabled = 0;
	Energy->Enabled = 0;

	pichu->Enabled = 0;
	pikachu->Enabled = 0;
	raichu->Enabled = 0;
	deadTamagochi->Enabled = 1;
	pichu->Visible = 0;
	pikachu->Visible = 0;
	raichu->Visible = 0;
	deadTamagochi->Visible = 1;
}
//---------------------------------------------------------------------------

void __fastcall Ttoy::timeLoweringSetietyTimer(TObject *Sender)
{
	setietyScale->Text = StrToInt(setietyScale->Text) - 5;
		if (setietyScale->Text <= 30) {
			healthStatus->Text = "I want to eat!";
		}
		if (setietyScale->Text <= 0) {
			death();
		}
}
//---------------------------------------------------------------------------

void __fastcall Ttoy::toFeedClick(TObject *Sender)
{
	if (StrToInt(setietyScale->Text) >= 70) {
		setietyScale->Text = 100;
	}
	else{
		setietyScale->Text = StrToInt(setietyScale->Text) + 30;
	}
	toFeed->Enabled = 0;
	timeToNextToFeed->Enabled = 1;
}
//---------------------------------------------------------------------------
void __fastcall Ttoy::timeToNextToFeedTimer(TObject *Sender)
{
	if (Energy->Text == "Go to bed") {
		toFeed->Enabled = 1;
	}
	timeToNextToFeed->Enabled = 0;
}
//---------------------------------------------------------------------------
void __fastcall Ttoy::timeToWashTimer(TObject *Sender)
{
	freshnessScale->Text = StrToInt(freshnessScale->Text) - 5;
	if (freshnessScale->Text <= 30) {
		healthStatus->Text = "I want to wash up!";
	}
	if (freshnessScale->Text <= 0) {
		death();
	}
}
//---------------------------------------------------------------------------

void __fastcall Ttoy::washClick(TObject *Sender)
{
	if (StrToInt(freshnessScale->Text) >= 60) {
		freshnessScale->Text = 100;
	}
	else{
		freshnessScale->Text = StrToInt(freshnessScale->Text) + 40;
	}
	wash->Enabled = 0;
	timeToNextWashUp->Enabled = 1;

}
//---------------------------------------------------------------------------
void __fastcall Ttoy::timeToNextWashUpTimer(TObject *Sender)
{
	if (Energy->Text == "Go to bed") {
		wash->Enabled = 1;
	}
	timeToNextWashUp->Enabled = 0;
}
//---------------------------------------------------------------------------

void __fastcall Ttoy::timeToTransformationTimer(TObject *Sender)
{
	if (tamagochiEvolutionState == 0) {
		tamagochiEvolutionState = 1;
		pichu->Visible = 0;
		pikachu->Visible = 1;
	}
	else if (tamagochiEvolutionState == 1) {
			tamagochiEvolutionState = 2;
			pikachu->Visible = 0;
			raichu->Visible = 1;
		 }
	else if (tamagochiEvolutionState == 2) {
			death();
		 }
}
//---------------------------------------------------------------------------

void __fastcall Ttoy::FormCreate(TObject *Sender)
{
	tamagochiEvolutionState = 0;
}
//---------------------------------------------------------------------------



