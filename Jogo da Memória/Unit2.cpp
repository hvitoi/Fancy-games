//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern char MelhorTempo[10];

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{

        char nome[100];
        
        StringGrid1->Cells[0][0]="Nome:";
        StringGrid1->Cells[0][1]="Tempo:";

        //Leitura do arquivo txt
        FILE *arquivo;
        arquivo = fopen("rank.txt", "r+");

        fscanf(arquivo, "%s", nome);
        fscanf(arquivo, "%s", MelhorTempo);

        fclose(arquivo);
        //

        StringGrid1->Cells[1][0]=nome;
        StringGrid1->Cells[1][1]=MelhorTempo;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        ModalResult=true;
}
//---------------------------------------------------------------------------

