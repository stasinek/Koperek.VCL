object ListaForm: TListaForm
  Left = 233
  Top = 103
  Width = 728
  Height = 493
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
    Top = 401
    Width = 720
    Height = 46
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 0
    object Button3: TButton
      Left = 520
      Top = 12
      Width = 173
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = 'Return without changes...'
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
      Left = 439
      Top = 12
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = 'OK'
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
    Width = 720
    Height = 309
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    BevelWidth = 2
    TabOrder = 1
    object CheckListBox1: TCheckListBox
      Left = 4
      Top = 4
      Width = 281
      Height = 301
      Align = alLeft
      Anchors = [akLeft, akTop, akRight, akBottom]
      ItemHeight = 13
      TabOrder = 0
    end
    object CheckListBox2: TCheckListBox
      Left = 376
      Top = 4
      Width = 340
      Height = 301
      Align = alRight
      Anchors = [akLeft, akTop, akRight, akBottom]
      ItemHeight = 13
      TabOrder = 1
    end
    object Panel4: TPanel
      Left = 285
      Top = 4
      Width = 91
      Height = 301
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 2
      object SpeedButton5: TSpeedButton
        Left = 25
        Top = 212
        Width = 40
        Height = 38
      end
      object SpeedButton4: TSpeedButton
        Left = 25
        Top = 164
        Width = 40
        Height = 38
      end
      object SpeedButton3: TSpeedButton
        Left = 25
        Top = 116
        Width = 40
        Height = 38
      end
      object SpeedButton2: TSpeedButton
        Left = 25
        Top = 68
        Width = 40
        Height = 38
      end
      object SpeedButton1: TSpeedButton
        Left = 25
        Top = 24
        Width = 40
        Height = 38
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 309
    Width = 720
    Height = 92
    Align = alClient
    BevelOuter = bvLowered
    TabOrder = 2
    object ComboBox1: TComboBox
      Left = 12
      Top = 27
      Width = 237
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      Text = 'ComboBox1'
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
    Left = 76
    Top = 373
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
