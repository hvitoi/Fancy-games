unit UVelha;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TFrmPainel = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    Button9: TButton;
    Label1: TLabel;
    procedure JogoNovo;
    procedure Verificar;
    procedure FormCreate(Sender: TObject);
    procedure ButtonClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FrmPainel: TFrmPainel;
  Botao: array[1..9] of TButton;
  NumeroVezes: Integer;

implementation


{$R *.dfm}

{ TFrmPainel }


procedure TFrmPainel.ButtonClick(Sender: TObject);
begin
if ((Sender as TButton).Caption = '')
then begin
NumeroVezes:=NumeroVezes + 1;
(Sender as TButton).Caption:= 'X';
Verificar;
end;
end;

procedure TFrmPainel.FormCreate(Sender: TObject);
begin
  Randomize;
  Botao[1]:=Button1;
  Botao[2]:=Button2;
  Botao[3]:=Button3;
  Botao[4]:=Button4;
  Botao[5]:=Button5;
  Botao[6]:=Button6;
  Botao[7]:=Button7;
  Botao[8]:=Button8;
  Botao[9]:=Button9;
  JogoNovo;
end;

procedure TFrmPainel.JogoNovo;
var
  M, I:Integer;
begin
  for I:=1 to 9 do
    Botao[I].Caption:='';
    M:=1+Random(9);
    Botao[M].Caption:='O';
    NumeroVezes:=0;
end;

procedure TFrmPainel.Verificar;
var I, RESPOSTA : integer;
begin
if ((Button1.Caption='X') and (Button2.Caption='X') and (Button3.Caption='X')) or
((Button4.Caption='X') and (Button5.Caption='X') and (Button6.Caption='X')) or
((Button7.Caption='X') and (Button8.Caption='X') and (Button9.Caption='X')) or
((Button1.Caption='X') and (Button4.Caption='X') and (Button7.Caption='X')) or
((Button2.Caption='X') and (Button5.Caption='X') and (Button8.Caption='X')) or
((Button3.Caption='X') and (Button6.Caption='X') and (Button9.Caption='X')) or
((Button1.Caption='X') and (Button5.Caption='X') and (Button9.Caption='X')) or
((Button3.Caption='X') and (Button5.Caption='X') and (Button7.Caption='X'))
then
begin
Resposta:=Application.MessageBox
('Você ganhou, quer Jogar Novamente?','Vencedor',36);
if Resposta = 7 then Close;
JogoNovo;
exit;
end;
repeat
I:= 1+ Random(9);
until Botao[I].Caption='' ;
Botao[I].Caption:='O';
if ((Button1.Caption='O') and (Button2.Caption='O') and (Button3.Caption='O')) or
((Button4.Caption='O') and (Button5.Caption='O') and (Button6.Caption='O')) or
((Button7.Caption='O') and (Button8.Caption='O') and (Button9.Caption='O')) or
((Button1.Caption='O') and (Button4.Caption='O') and (Button7.Caption='O')) or
((Button2.Caption='O') and (Button5.Caption='O') and (Button8.Caption='O')) or
((Button3.Caption='O') and (Button6.Caption='O') and (Button9.Caption='O')) or
((Button1.Caption='O') and (Button5.Caption='O') and (Button9.Caption='O')) or
((Button3.Caption='O') and (Button5.Caption='O') and (Button7.Caption='O'))
then begin
Resposta:=Application.MessageBox
('Eu ganhei, quer Jogar Novamente?','Vencedor',36);
if Resposta = 7 then Close;
JogoNovo;
exit;
end;
if NumeroVezes= 4 then
begin
ShowMessage ('Partida Empatada');
JogoNovo;
exit;
end;
exit;
end;

end.
