object Form2: TForm2
  Left = 405
  Top = 202
  BorderStyle = bsToolWindow
  Caption = 'Ranking'
  ClientHeight = 168
  ClientWidth = 441
  Color = clWindow
  Ctl3D = False
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 40
    Top = 62
    Width = 364
    Height = 52
    ColCount = 2
    DefaultColWidth = 180
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    TabOrder = 0
  end
  object Button1: TButton
    Left = 184
    Top = 128
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 441
    Height = 41
    Align = alTop
    Caption = 'Melhor Tempo'
    Color = clCream
    TabOrder = 2
  end
end
