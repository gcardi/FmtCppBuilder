object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 286
  ClientWidth = 674
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 16
    Top = 16
    Width = 105
    Height = 25
    Caption = 'Simple Test'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    AlignWithMargins = True
    Left = 16
    Top = 56
    Width = 642
    Height = 214
    Margins.Left = 16
    Margins.Right = 16
    Margins.Bottom = 16
    Align = alBottom
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 1
  end
end
