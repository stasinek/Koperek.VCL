object ListaForm: TListaForm
  Left = 30
  Top = 94
  Width = 924
  Height = 495
  Caption = 'Lista'
  Color = clBtnFace
  Constraints.MaxHeight = 600
  Constraints.MaxWidth = 990
  Constraints.MinHeight = 400
  Constraints.MinWidth = 640
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
    Top = 386
    Width = 900
    Height = 51
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 0
    object Button3: TButton
      Left = 17130
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
      Left = 17041
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
    Width = 908
    Height = 309
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    BevelWidth = 2
    TabOrder = 1
    object CheckListBox1: TCheckListBox
      Left = 34
      Top = 4
      Width = 400
      Height = 301
      Align = alLeft
      Constraints.MinWidth = 100
      ItemHeight = 13
      TabOrder = 0
    end
    object CheckListBox2: TCheckListBox
      Left = 474
      Top = 4
      Width = 400
      Height = 301
      Align = alRight
      Constraints.MinWidth = 100
      ItemHeight = 13
      TabOrder = 1
    end
    object Panel4: TPanel
      Left = 17614
      Top = 4
      Width = 72
      Height = 301
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
    object Panel5: TPanel
      Left = 434
      Top = 4
      Width = 40
      Height = 301
      Align = alClient
      BevelOuter = bvLowered
      Constraints.MinWidth = 40
      TabOrder = 3
    end
    object Panel6: TPanel
      Left = 4
      Top = 4
      Width = 30
      Height = 301
      Align = alLeft
      BevelOuter = bvNone
      Constraints.MinWidth = 30
      TabOrder = 4
    end
    object Panel7: TPanel
      Left = 874
      Top = 4
      Width = 30
      Height = 301
      Align = alRight
      BevelOuter = bvNone
      Constraints.MinWidth = 30
      TabOrder = 5
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 309
    Width = 900
    Height = 77
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 2
    object ComboBox1: TComboBox
      Left = 12
      Top = 51
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
      Top = 52
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
