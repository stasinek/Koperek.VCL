object ListaForm: TListaForm
  Left = 174
  Top = 107
  Width = 696
  Height = 493
  Caption = 'Lista'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Default'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 189
    Height = 13
    Caption = 'Lista plik'#243'w w oczekiwaniu na operacje:'
  end
  object CheckListBox1: TCheckListBox
    Left = 4
    Top = 36
    Width = 281
    Height = 293
    ItemHeight = 13
    TabOrder = 0
  end
  object FilterComboBox1: TFilterComboBox
    Left = 456
    Top = 336
    Width = 145
    Height = 21
    TabOrder = 1
  end
  object FILTRUJ: TButton
    Left = 608
    Top = 336
    Width = 75
    Height = 21
    Caption = 'FILTRUJ'
    TabOrder = 2
  end
  object Button2: TButton
    Left = 464
    Top = 432
    Width = 75
    Height = 25
    Caption = 'OK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Default'
    Font.Style = []
    ModalResult = 10
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 552
    Top = 432
    Width = 129
    Height = 25
    Caption = 'Wr'#243'c bez zmian...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = Button3Click
  end
  object GroupBox1: TGroupBox
    Left = 4
    Top = 340
    Width = 381
    Height = 117
    Caption = 'Informacje por'#243'wnawcze...'
    TabOrder = 5
  end
  object CheckListBox2: TCheckListBox
    Left = 392
    Top = 36
    Width = 289
    Height = 293
    ItemHeight = 13
    TabOrder = 6
  end
  object ValueListEditor1: TValueListEditor
    Left = 292
    Top = 36
    Width = 93
    Height = 293
    ScrollBars = ssVertical
    Strings.Strings = (
      'z=do')
    TabOrder = 7
    TitleCaptions.Strings = (
      '<'
      '>')
    ColWidths = (
      33
      54)
  end
end
