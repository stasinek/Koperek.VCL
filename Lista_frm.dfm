object ListaForm: TListaForm
  Left = -239
  Top = 20
  Width = 1292
  Height = 495
  Caption = 'Lista'
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 155
    Height = 13
    Caption = 'Files list of requested operation:'
  end
  object Panel1: TPanel
    Left = 0
    Top = 398
    Width = 17690
    Height = 51
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 0
    object Button3: TButton
      Left = 17506
      Top = 13
      Width = 173
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = 'Return without &changes...'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button3Click
    end
    object Button2: TButton
      Left = 17417
      Top = 13
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = '&OK'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ModalResult = 10
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 17690
    Height = 309
    Align = alTop
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    BevelWidth = 2
    TabOrder = 1
    object CheckListBox1: TCheckListBox
      Left = 4
      Top = 4
      Width = 17610
      Height = 301
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
    end
    object CheckListBox2: TCheckListBox
      Left = 763
      Top = 4
      Width = 17243
      Height = 301
      ItemHeight = 13
      TabOrder = 1
    end
    object Panel4: TPanel
      Left = 17614
      Top = 4
      Width = 72
      Height = 301
      Align = alClient
      Anchors = []
      BevelOuter = bvNone
      Constraints.MaxWidth = 72
      Constraints.MinWidth = 72
      TabOrder = 2
      object SpeedButton5: TSpeedButton
        Left = 17
        Top = 200
        Width = 40
        Height = 38
      end
      object SpeedButton4: TSpeedButton
        Left = 17
        Top = 156
        Width = 40
        Height = 38
      end
      object SpeedButton3: TSpeedButton
        Left = 17
        Top = 112
        Width = 40
        Height = 38
      end
      object SpeedButton2: TSpeedButton
        Left = 17
        Top = 68
        Width = 40
        Height = 38
      end
      object SpeedButton1: TSpeedButton
        Left = 17
        Top = 24
        Width = 40
        Height = 38
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 309
    Width = 17690
    Height = 89
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 2
    object ComboBox1: TComboBox
      Left = 12
      Top = 27
      Width = 237
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      Text = '*.*'
      Items.Strings = (
        '*.*')
    end
    object FILTRUJ: TButton
      Left = 266
      Top = 28
      Width = 103
      Height = 21
      Caption = 'SET THIS FILTER'
      TabOrder = 1
    end
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 405
    object Export1: TMenuItem
      Caption = 'Source'
    end
    object Right1: TMenuItem
      Caption = 'Destination'
    end
    object Help1: TMenuItem
      Caption = 'HELP'
    end
  end
end
