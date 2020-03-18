program Velha;

uses
  Forms,
  UVelha in 'UVelha.pas' {FrmPainel};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFrmPainel, FrmPainel);
  Application.Run;
end.
