object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 239
  ClientWidth = 470
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 141
    Width = 146
    Height = 16
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1072#1079#1084#1077#1088' '#1073#1083#1086#1082#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 173
    Width = 297
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 336
    Top = 136
    Width = 113
    Height = 30
    Caption = #1053#1072#1095#1072#1090#1100' '#1089#1095#1080#1090#1099#1074#1072#1085#1080#1077
    Enabled = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 176
    Top = 140
    Width = 145
    Height = 21
    Style = csDropDownList
    TabOrder = 1
    OnChange = ComboBox1Change
    Items.Strings = (
      '512 '#1041#1072#1081#1090
      '1024 '#1041#1072#1081#1090#1072
      '4096 '#1041#1072#1081#1090
      '8192 '#1041#1072#1081#1090#1072)
  end
  object Button2: TButton
    Left = 336
    Top = 172
    Width = 113
    Height = 30
    Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100
    Enabled = False
    TabOrder = 2
    OnClick = Button2Click
  end
end
