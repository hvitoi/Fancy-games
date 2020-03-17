//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

extern char MelhorTempo[10]="0";

//Variáveis globais;
int CartasViradas=0, acertos=0, tempo=0;
TImage *PrimeiraCarta, *SegundaCarta;
bool acertou=false;


//---------------------------------------------------------------------------
void Sortear(){
        int i, j, k, n=0, NumerosSorteados[16];

        Randomize();

        //Zera a quantidade de acertos
        acertos=0;

        //Zera a quantidade de cartas viradas
        CartasViradas=0;

        //Zera o Tempo e começa
        Form1->Label1->Caption=0;
        tempo=0;
        Form1->Timer1->Enabled=true;

        //Escreve Início no Menu
        Form1->Panel1->Font->Color=clBlue;
        Form1->Panel1->Caption="Início";

        for(i=0; i<16; i++){

                NumerosSorteados[i]=random(8)+1;  //Sorteia um número qualquer entre 1 e 8


                //Verifica se o número já foi sorteado

                for(j=0; j<n;j++){   //De 0 até a quantidade de números que já foram sorteados (i)

                        if(NumerosSorteados[j]==NumerosSorteados[i]){ //Se o número for igual a qualquer outro já sorteado
                                k++;  // k informará se um número já foi sorteado mais 2 vezes, que é o máximo
                                if(k==2){ // se o determinado número já foi sorteado 2 vezes
                                        NumerosSorteados[i]=random(8)+1;  //sorteia-se outro número
                                        k=0;
                                        j=-1; // j=-1 ao entrar no próximo laço de repetição se tornará 0, portanto, varrerá o vetor novamente
                                }
                        }

                }

                k=0;
                n++; //Incrementa a quantidade de números sorteados

        }

        Form1->Image1->Tag=NumerosSorteados[0];
        Form1->Image2->Tag=NumerosSorteados[1];
        Form1->Image3->Tag=NumerosSorteados[2];
        Form1->Image4->Tag=NumerosSorteados[3];
        Form1->Image5->Tag=NumerosSorteados[4];
        Form1->Image6->Tag=NumerosSorteados[5];
        Form1->Image7->Tag=NumerosSorteados[6];
        Form1->Image8->Tag=NumerosSorteados[7];
        Form1->Image9->Tag=NumerosSorteados[8];
        Form1->Image10->Tag=NumerosSorteados[9];
        Form1->Image11->Tag=NumerosSorteados[10];
        Form1->Image12->Tag=NumerosSorteados[11];
        Form1->Image13->Tag=NumerosSorteados[12];
        Form1->Image14->Tag=NumerosSorteados[13];
        Form1->Image15->Tag=NumerosSorteados[14];
        Form1->Image16->Tag=NumerosSorteados[15];



        Form1->Image1->Picture->LoadFromFile("verso.jpg");
        Form1->Image2->Picture->LoadFromFile("verso.jpg");
        Form1->Image3->Picture->LoadFromFile("verso.jpg");
        Form1->Image4->Picture->LoadFromFile("verso.jpg");
        Form1->Image5->Picture->LoadFromFile("verso.jpg");
        Form1->Image6->Picture->LoadFromFile("verso.jpg");
        Form1->Image7->Picture->LoadFromFile("verso.jpg");
        Form1->Image8->Picture->LoadFromFile("verso.jpg");
        Form1->Image9->Picture->LoadFromFile("verso.jpg");
        Form1->Image10->Picture->LoadFromFile("verso.jpg");
        Form1->Image11->Picture->LoadFromFile("verso.jpg");
        Form1->Image12->Picture->LoadFromFile("verso.jpg");
        Form1->Image13->Picture->LoadFromFile("verso.jpg");
        Form1->Image14->Picture->LoadFromFile("verso.jpg");
        Form1->Image15->Picture->LoadFromFile("verso.jpg");
        Form1->Image16->Picture->LoadFromFile("verso.jpg");

        Form1->Image1->Enabled=true;
        Form1->Image2->Enabled=true;
        Form1->Image3->Enabled=true;
        Form1->Image4->Enabled=true;
        Form1->Image5->Enabled=true;
        Form1->Image6->Enabled=true;
        Form1->Image7->Enabled=true;
        Form1->Image8->Enabled=true;
        Form1->Image9->Enabled=true;
        Form1->Image10->Enabled=true;
        Form1->Image11->Enabled=true;
        Form1->Image12->Enabled=true;
        Form1->Image13->Enabled=true;
        Form1->Image14->Enabled=true;
        Form1->Image15->Enabled=true;
        Form1->Image16->Enabled=true;



}

void VerificarCartas(TImage *CartaClicada){
        switch(CartasViradas){
                case 0:
                        PrimeiraCarta = CartaClicada;

                        //Desvira a carta clicada
                        CartaClicada->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(CartaClicada->Tag)+".jpg");
                        CartaClicada->Enabled=false;

                        CartasViradas++;

                        break;


                case 1:
                        SegundaCarta = CartaClicada;

                        //Desvira a carta clicada
                        CartaClicada->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(CartaClicada->Tag)+".jpg");

                        //Verifica se é igual à primeira  - se sim...
                        if(PrimeiraCarta->Tag==SegundaCarta->Tag){

                                acertou=true;
                                acertos++;

                                //Desabilita-a para não poder ser clicada novamente, a primeira já foi desabilitada
                                SegundaCarta->Enabled=false;

                                //Verifica se ganhou o jogo ou não
                                if(acertos!=8){
                                        Form1->Panel1->Font->Color=clGreen;
                                        Form1->Panel1->Caption = "Acertou!";
                                }
                                else{
                                        Form1->Panel1->Font->Color=clNavy;
                                        Form1->Panel1->Caption = "Parabéns!";

                                        //Pára o tempo
                                        Form1->Timer1->Enabled=false;

                                        //Verifica se houve recorde
                                        if(tempo>=StrToInt(MelhorTempo)){
                                                AnsiString mensagem =  "Parabéns! Você descobriu todas as cartas em "+IntToStr(tempo)+" segundos.";
                                                Application->MessageBox(mensagem.c_str(), "Vitória", MB_OK | MB_ICONASTERISK);
                                        }
                                        else{

                                                AnsiString nome;
                                                AnsiString mensagem =  "Você bateu um novo recorde com "+IntToStr(tempo)+" segundos. Insira seu nome.";
                                                nome = InputBox("Recorde", mensagem.c_str(), "");

                                                if(nome!=""){

                                                        //Gravação do arquivo txt
                                                        FILE *arquivo;
                                                        arquivo = fopen("rank.txt", "w+");

                                                        fprintf(arquivo, "%s", nome+" ");
                                                        fprintf(arquivo, "%s", IntToStr(tempo).c_str());

                                                        fclose(arquivo);
                                                        //
                                                        ShowMessage("Nome gravado com sucesso. Reinicie o jogo para alterar as modificações.");
                                                }

                                        }



                                }


                        }

                        else{
                                acertou=false;

                                Form1->Panel1->Font->Color=clRed;
                                Form1->Panel1->Caption = "Errou!";

                                //Habilita a Primeira Carta Novamente
                                PrimeiraCarta->Enabled=true;
                        }

                        //Zera o número de cartas viradas
                        CartasViradas++;
                        break;

                case 2:
                        if(acertou){ //Se a pessoa acertou, faz-se o mesmo de 0

                                PrimeiraCarta = CartaClicada;

                                //Desvira a carta clicada
                                CartaClicada->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(CartaClicada->Tag)+".jpg");
                                CartaClicada->Enabled=false;

                                CartasViradas=1; //vai para 1 pois o caso 0 acabou de ser feito acima (goto)

                        }

                        else{ //Se a pessoa não acertou...

                                //Desvira as cartas
                                PrimeiraCarta->Picture->LoadFromFile("verso.jpg");
                                SegundaCarta->Picture->LoadFromFile("verso.jpg");

                                CartasViradas=0;
                        }
                 



        } //fecha switch

}  //fecha funcao

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Sortear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1Click(TObject *Sender)
{
        VerificarCartas(Image1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
        VerificarCartas(Image2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
        VerificarCartas(Image3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4Click(TObject *Sender)
{
        VerificarCartas(Image4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
        VerificarCartas(Image5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
        VerificarCartas(Image6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image7Click(TObject *Sender)
{
        VerificarCartas(Image7);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8Click(TObject *Sender)
{
        VerificarCartas(Image8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9Click(TObject *Sender)
{
        VerificarCartas(Image9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10Click(TObject *Sender)
{
        VerificarCartas(Image10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image11Click(TObject *Sender)
{
        VerificarCartas(Image11);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image12Click(TObject *Sender)
{
        VerificarCartas(Image12);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image13Click(TObject *Sender)
{
        VerificarCartas(Image13);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image14Click(TObject *Sender)
{
        VerificarCartas(Image14);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image15Click(TObject *Sender)
{
        VerificarCartas(Image15);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image16Click(TObject *Sender)
{
        VerificarCartas(Image16);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
        Form1->Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        tempo++;
        Label1->Caption=IntToStr(tempo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
        Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
        Sortear();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
        Application->MessageBox("O jogo atual será fechado. \nUm novo sorteio com o novo baralho será feito.", "Trocar Baralho", MB_OK | MB_ICONASTERISK);
        Sortear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
        Form1->Panel1->Font->Color=clPurple;
        Form1->Panel1->Caption=":(";

        Form1->Timer1->Enabled=false;
        
        Image1->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image1->Tag)+".jpg");
        Image2->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image2->Tag)+".jpg");
        Image3->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image3->Tag)+".jpg");
        Image4->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image4->Tag)+".jpg");
        Image5->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image5->Tag)+".jpg");
        Image6->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image6->Tag)+".jpg");
        Image7->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image7->Tag)+".jpg");
        Image8->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image8->Tag)+".jpg");
        Image9->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image9->Tag)+".jpg");
        Image10->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image10->Tag)+".jpg");
        Image11->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image11->Tag)+".jpg");
        Image12->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image12->Tag)+".jpg");
        Image13->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image13->Tag)+".jpg");
        Image14->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image14->Tag)+".jpg");
        Image15->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image15->Tag)+".jpg");
        Image16->Picture->LoadFromFile(IntToStr(Form1->RadioGroup1->ItemIndex)+"/"+IntToStr(Image16->Tag)+".jpg");

        Form1->Image1->Enabled=false;
        Form1->Image2->Enabled=false;
        Form1->Image3->Enabled=false;
        Form1->Image4->Enabled=false;
        Form1->Image5->Enabled=false;
        Form1->Image6->Enabled=false;
        Form1->Image7->Enabled=false;
        Form1->Image8->Enabled=false;
        Form1->Image9->Enabled=false;
        Form1->Image10->Enabled=false;
        Form1->Image11->Enabled=false;
        Form1->Image12->Enabled=false;
        Form1->Image13->Enabled=false;
        Form1->Image14->Enabled=false;
        Form1->Image15->Enabled=false;
        Form1->Image16->Enabled=false;
}
//---------------------------------------------------------------------------


