//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

///Inicializar o gerador de n�meros aleat�rios
Randomize();

//Cria��o de estrutura para armanezar os times sorteados
typedef struct t_stimes{

        //nome do time em AnsiString
        AnsiString Nome_s;

        //nome do time em char (para facilitar manipulacao das letras
        char Nome_c[20];

        //Vari�veis para armazenar a posi��o da palavra
        int Esquerda, Direita, Acima, Abaixo;

        //variavel boleana para informar se a pe�a foi descoberta ou nao
        bool Achou; 


} STimes;


//Declara��o de vari�veis globais
AnsiString Todos_Times[50];   //armazena todos os tipos
STimes Times[10];  //armazenar� os 10 times sorteados (do tipo STimes criado acima)
int tempo=0;   //tempo para cronometrar



//---------------------------------------------------------------------------

void Limpar(){
        int i, j;

        //for varrer as celulas do StringGrid e preenche com um espa�o vazio

        for(i=0; i<20; i++){
                for(j=0; j<20; j++){
                        Form1->StringGrid1->Cells[i][j]="";
                }
        }

}

//---------------------------------------------------------------------------

void Sortear_Times(){
        int i, j, t[10]; // o vetor t guarda o indice (em relacao ao vetor Todos_Times) dos times sorteados



        for(i=0; i<10; i++){

                t[i]=random(50);  //Sorteia um n�mero qualquer entre 0 e 49


                //Verifica se o n�mero j� foi sorteado

                for(j=0; j<i;j++){   //De 0 at� a quantidade de n�meros que j� foram sorteados (i)

                        if(t[i]==t[j]){ //Se o n�mero for igual a qualquer outro j� sorteado
                                t[i]=random(50);  //Sorteia-se outro n�mero para repor o repetido
                                j=-1; // j=-1 ao entrar no pr�ximo la�o de repeti��o se tornar� 0, portanto, varrer� o vetor novamente para verificar se � um repetido de novo ou n�o
                        }

                }

        }


        //em posse do �ndice de todos os times sorteados, adicionamo-os ao vetor Times[10] do tipo STimes
        for(i=0; i<10; i++){
                Times[i].Nome_s = Todos_Times[t[i]];   //insere o nome do tipo em AnsiString
                strcpy(Times[i].Nome_c, Times[i].Nome_s.c_str());    //insere o nome do tipo em CHAR
        }


        //Escreve os times sorteados na tela principal
        Form1->Label1->Caption = Times[0].Nome_s;
        Form1->Label2->Caption = Times[1].Nome_s;
        Form1->Label3->Caption = Times[2].Nome_s;
        Form1->Label4->Caption = Times[3].Nome_s;
        Form1->Label5->Caption = Times[4].Nome_s;
        Form1->Label6->Caption = Times[5].Nome_s;
        Form1->Label7->Caption = Times[6].Nome_s;
        Form1->Label8->Caption = Times[7].Nome_s;
        Form1->Label9->Caption = Times[8].Nome_s;
        Form1->Label10->Caption = Times[9].Nome_s;


}

//---------------------------------------------------------------------------

void Escrever_Times(){ //Essa sortear� a posi��o dos times dentro do StringGrid e ir� escreve-los

        int x, y, i, j, tam, invalido;


        for(i=0; i<10; i++){

                invalido=0;   //invalido ser� 1 se a posicao estiver em cima de outra j� sorteada
                tam = StrLen(Times[i].Nome_c); //informa o numero de letras do time


                //Essa repeti��o sortear� um time na horizontal e outro na vertical, alternadamente
                //Portanto para i par, sortear� na horizontal, e para i �mpar, sortear� na vertical

                //sorteio da posi��o na horizontal
                if(i%2==0){

                        //C�lculo com n�meros para sortear uma posicao na horizontal
                        x = random(20-tam+1);
                        y = random(20);

                        Times[i].Esquerda = x;
                        Times[i].Direita = x+tam-1;
                        Times[i].Acima = y;
                        Times[i].Abaixo = y;
                        //


                        //Verifica se todos os espa�os que a palavra ser� inserida est�o em branco
                        //ou seja, se n�o ir� sobrepor nenhuma outra palavra
                        for(j=0; j<tam; j++){
                                if (Form1->StringGrid1->Cells[x+j][y]!="") invalido=1; //se tiver em cima de outra palavra, invalido=1

                        }

                        //com invalido=1, reduz-se o i em 1 para novamente entrar dentro do for
                        if (invalido){
                                i--;
                                continue; //quebra o for pois a posicao � invalida
                        }

                        //se for posicao v�lida, apenas escreve-se a palavra no StringGrid, letra por letra (manipulacao com char)
                        else{
                                for(j=0; j<tam; j++) Form1->StringGrid1->Cells[x+j][y] = Times[i].Nome_c[j];

                                Times[i].Achou=false; //Informa se a palavra foi descoberta, como est� come�ando o jogo, recebe false

                        }
                }

               //mesmo procedimento do if anterior, por�m, com os c�lculos para sortear na vertical
                else{
                         //C�lculo com n�meros para sortear uma posicao na VERTICAL
                        x = random(20);
                        y = random(20-tam+1);

                        Times[i].Esquerda = x;
                        Times[i].Direita = x;
                        Times[i].Acima = y;
                        Times[i].Abaixo = y+tam-1;
                        //



                        for(j=0; j<tam; j++){
                                if (Form1->StringGrid1->Cells[x][y+j]!="") invalido=1;
                        }

                        if (invalido){
                                i--;
                                continue;

                        }

                        else{
                                for(j=0; j<tam; j++) Form1->StringGrid1->Cells[x][y+j] = Times[i].Nome_c[j];
                                Times[i].Achou=false;
                                
                        }

                }
        }

}

//---------------------------------------------------------------------------

bool Verificar(){ //esta func�o verifica se o jogador ganhou

        int i, n=0;

        //Verifica se todos os times est�o com a propriedade Achou=true
        for(i=0; i<10; i++){
               if(Times[i].Achou) n++;
        }

        //se todos os times foram descobertos, retorna true
        if (n==10) return true;
        else return false;
        

}

//---------------------------------------------------------------------------

void Adicionar_Letras(){ //Esta fun��o apenas escreve letras aleat�rias para preencher os espa�os em branco
        int i, j;
        char letra;

        for(i=0; i<20; i++){
                for (j=0; j<20; j++){
                        if (Form1->StringGrid1->Cells[i][j]==""){  //se a c�lula estiver em branco...
                                letra=random(26)+65; //equivale a um n�mero entre 65 e 90, que na tabela ASCII equivale �s letras A e Z
                                Form1->StringGrid1->Cells[i][j]=letra;
                        }
                }
        }

}
//---------------------------------------------------------------------------

void Mudar_Cor_Bolinha(int pos, int cor){ //muda a cor da bolinha do menu para verde ou vermelho

        //pos indica qual Shape ir� transformar em outra cor
        //cor indica para qual cor o Shape mudar� vermelho=0, verde=1

        switch(pos){
        case 0:
                if(cor) Form1->Shape1->Brush->Color=clGreen;
                else Form1->Shape1->Brush->Color=clRed;
                break;

        case 1:
                if(cor) Form1->Shape2->Brush->Color=clGreen;
                else Form1->Shape2->Brush->Color=clRed;
                break;

        case 2:
                if(cor) Form1->Shape3->Brush->Color=clGreen;
                else Form1->Shape3->Brush->Color=clRed;
                break;

        case 3:
                if(cor) Form1->Shape4->Brush->Color=clGreen;
                else Form1->Shape4->Brush->Color=clRed;
                break;

        case 4:
                if(cor) Form1->Shape5->Brush->Color=clGreen;
                else Form1->Shape5->Brush->Color=clRed;
                break;

        case 5:
                if(cor) Form1->Shape6->Brush->Color=clGreen;
                else Form1->Shape6->Brush->Color=clRed;
                break;

        case 6:
                if(cor) Form1->Shape7->Brush->Color=clGreen;
                else Form1->Shape7->Brush->Color=clRed;
                break;

        case 7:
                if(cor) Form1->Shape8->Brush->Color=clGreen;
                else Form1->Shape8->Brush->Color=clRed;
                break;

        case 8:
                if(cor) Form1->Shape9->Brush->Color=clGreen;
                else Form1->Shape9->Brush->Color=clRed;
                break;

        case 9:
                if(cor) Form1->Shape10->Brush->Color=clGreen;
                else Form1->Shape10->Brush->Color=clRed;
                break;
                
        }

}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

        //Adicionar todos os times ao vetor de times

        Todos_Times[0] = "VASCO";
        Todos_Times[1] = "BOTAFOGO";
        Todos_Times[2] = "FLAMENGO";
        Todos_Times[3] = "FLUMINENSE";
        Todos_Times[4] = "TUPI";
        Todos_Times[5] = "ATLETICO";
        Todos_Times[6] = "CRUZEIRO";
        Todos_Times[7] = "CORINTHIANS";
        Todos_Times[8] = "PALMEIRAS";
        Todos_Times[9] = "SANTOS";
        Todos_Times[10] = "VITORIA";
        Todos_Times[11] = "BAHIA";
        Todos_Times[12] = "CURITIBA";
        Todos_Times[13] = "INTERNACIONAL";
        Todos_Times[14] = "GR�MIO";
        Todos_Times[15] = "PARAN�";
        Todos_Times[16] = "AM�RICA";
        Todos_Times[17] = "ASA";
        Todos_Times[18] = "CHELSEA";
        Todos_Times[19] = "BARCELONA";
        Todos_Times[20] = "ARSENAL";
        Todos_Times[21] = "REAL";
        Todos_Times[22] = "VAL�NCIA";
        Todos_Times[23] = "MANCHESTER";
        Todos_Times[24] = "LIVERPOOL";
        Todos_Times[25] = "SEVILHA";
        Todos_Times[26] = "LYON";
        Todos_Times[27] = "RIVER";
        Todos_Times[28] = "BOCA";
        Todos_Times[29] = "GOI�S";
        Todos_Times[30] = "BANGU";
        Todos_Times[31] = "MADUREIRA";
        Todos_Times[32] = "OLARIA";
        Todos_Times[33] = "BRAGANTINO";
        Todos_Times[34] = "JUVENTUS";
        Todos_Times[35] = "MILAN";
        Todos_Times[36] = "AVA�";
        Todos_Times[37] = "GUARANI";
        Todos_Times[38] = "BAYER";
        Todos_Times[39] = "BORUSSIA";
        Todos_Times[40] = "TOTTEHAM";
        Todos_Times[41] = "BRASILIENSE";
        Todos_Times[42] = "GAMA";
        Todos_Times[43] = "VELEZ";
        Todos_Times[44] = "ITUANO";
        Todos_Times[45] = "BARUERI";
        Todos_Times[46] = "CAMPINENSE";
        Todos_Times[47] = "PAULISTA";
        Todos_Times[48] = "MIRASSOL";
        Todos_Times[49] = "OESTE";

        //Chama as fun��es para come�ar o jogo
        Limpar();  //limpa o StringGrid
        Sortear_Times(); //sortear 10 dos 50 times
        Escrever_Times(); //sorteia-se as posicoes dos times e escreve-os no StringGrid
        Adicionar_Letras(); //escreve-se letras aleatorias aos espa�os vazios do StringGrid

        //Escreve In�cio no Menu
        Form1->Panel1->Font->Color=clBlue;
        Form1->Panel1->Caption="In�cio";



}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
        int i;

        //Habilita o StringGrid
        Form1->StringGrid1->Enabled=true;

        //Chama as fun��es para come�ar um novo jogo
        Limpar();
        Sortear_Times();
        Escrever_Times();
        Adicionar_Letras();

        //Escreve In�cio no Menu
        Form1->Panel1->Font->Color=clBlue;
        Form1->Panel1->Caption="In�cio";

        //Muda a cor de todas as bolinhas do menu para vermelho
        for(i=0; i<10; i++) Mudar_Cor_Bolinha(i,0);

        //come�a o tempo
        tempo=0;
        Timer1->Enabled=true ;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
        //Fecha a tela
        Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
        int i;

        //Este procedimento termina o jogo, definindo todas a propriedades de Achou para true
        for(i=0; i<10; i++){
                Times[i].Achou=true;
        }

        //Apenas 'pisca' o StringGrid para ele atualizar
        Form1->StringGrid1->Visible=false;
        Form1->StringGrid1->Visible=true;

        //Muda a cor de todas as bolinhas do menu para verde
        for(i=0; i<10; i++) Mudar_Cor_Bolinha(i,1);

        //para o tempo
        Timer1->Enabled=false;

        //Escreve no Menu
        Form1->Panel1->Font->Color=clPurple;
        Form1->Panel1->Caption="Desistiu";

        //Desabilita o StringGrid
        Form1->StringGrid1->Enabled=false;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::StringGrid1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

        TGridRect Selecao;
        int i;
        bool acertou=false;

        //recebe as 4 posicoes da �rea selecionada
        Selecao = StringGrid1->Selection;

        for(i=0; i<10; i++){

                //compara as 4 posicoes selecionadas com as 4 posi��es de cada time
                if((Selecao.Left==Times[i].Esquerda) &&
                   (Selecao.Right==Times[i].Direita) &&
                   (Selecao.Top==Times[i].Acima) &&
                   (Selecao.Bottom==Times[i].Abaixo))
                   {
                        //Se forem iguais, Achou=true
                        Times[i].Achou=true;
                        Mudar_Cor_Bolinha(i, 1); //muda a cor da bolinha para verde
                        acertou=true;


                        //Escreve no Menu
                        Form1->Panel1->Font->Color=clGreen;
                        Form1->Panel1->Caption="Acertou";

                        //Verifica se o jogo est� ganho, se sim motra uma mensagem;
                        if (Verificar()){
                                Timer1->Enabled=false;  //para o tempo

                                //Desabilita o StringGrid
                                Form1->StringGrid1->Enabled=false;

                               //Escreve no Menu
                                Form1->Panel1->Font->Color=clFuchsia;
                                Form1->Panel1->Caption="Ganhou";
                                
                                AnsiString mensagem =  "Parab�ns! Voc� descobriu todas as palavras em "+IntToStr(tempo)+" segundos.";
                                Application->MessageBox(mensagem.c_str(), "Ganhou", MB_OK | MB_ICONASTERISK);
                                
                        }
                   }

        }

        if(!acertou){ //escre no menu que o usuario nao acertou a selecao
                //Escreve no Menu
                Form1->Panel1->Font->Color=clRed;
                Form1->Panel1->Caption="Errou";
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
        int i;

        //este evento colore todas a c�lulas dos times que est�o com Achou=true (todas as palavras descobertas)

        for(i=0; i<10; i++){
                if((ACol >= Times[i].Esquerda)&&
                   (ACol <= Times[i].Direita)&&
                   (ARow >= Times[i].Acima)&&
                   (ARow <= Times[i].Abaixo)&&
                   (Times[i].Achou==true))
                {
                        StringGrid1->Canvas->Brush->Color = clMoneyGreen;
                        StringGrid1->Canvas->Font->Color = clHotLight;
                        StringGrid1->Canvas->FillRect(Rect);
                        StringGrid1->Canvas->TextOut(Rect.Left, Rect.Top, StringGrid1->Cells[ACol][ARow]);
                }
        } 
        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        //conta o tempo
        tempo++;
        Label11->Caption=IntToStr(tempo);
}
//---------------------------------------------------------------------------

