object Infos_form: TInfos_form
  Left = 80
  Top = 202
  VertScrollBar.Visible = False
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Confirm action to the file or directory'
  ClientHeight = 375
  ClientWidth = 659
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = True
  Position = poScreenCenter
  PrintScale = poNone
  OnCreate = FormCreate
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 356
    Width = 659
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 308
    Width = 659
    Height = 48
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 1
    object Tak: TButton
      Left = 393
      Top = 14
      Width = 80
      Height = 23
      Anchors = [akRight, akBottom]
      Caption = '&Yes'
      ModalResult = 6
      TabOrder = 1
    end
    object Ignore: TButton
      Left = 232
      Top = 14
      Width = 155
      Height = 23
      Anchors = [akRight, akBottom]
      Caption = '&Rename to KEEP BOTH'
      Default = True
      ModalResult = 5
      TabOrder = 0
    end
    object Nie: TButton
      Left = 479
      Top = 14
      Width = 80
      Height = 23
      Anchors = [akRight, akBottom]
      Caption = '&No'
      ModalResult = 7
      TabOrder = 2
    end
    object NoToAll: TButton
      Left = 565
      Top = 14
      Width = 80
      Height = 23
      Anchors = [akRight, akBottom]
      Caption = '&Cancel'
      ModalResult = 9
      TabOrder = 3
    end
    object Button1: TButton
      Left = 133
      Top = 14
      Width = 80
      Height = 23
      Anchors = [akRight, akBottom]
      Caption = '&Custom'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ModalResult = 6
      ParentFont = False
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 101
    Height = 308
    Align = alLeft
    BevelOuter = bvNone
    Color = clBlack
    TabOrder = 2
    object Bevel1: TBevel
      Left = 51
      Top = 0
      Width = 50
      Height = 308
      Align = alRight
      Shape = bsRightLine
    end
    object Panel2: TPanel
      Left = 24
      Top = 16
      Width = 50
      Height = 50
      BevelOuter = bvSpace
      BorderWidth = 2
      Color = clWhite
      TabOrder = 0
      object Image3: TImage
        Left = 3
        Top = 3
        Width = 44
        Height = 44
        Align = alClient
        Center = True
      end
    end
  end
  object Panel5: TPanel
    Left = 101
    Top = 0
    Width = 558
    Height = 308
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 3
    object CheckBox1: TCheckBox
      Left = 32
      Top = 276
      Width = 233
      Height = 17
      BiDiMode = bdLeftToRight
      Caption = 'Repeat same choice for all nested files.'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentBiDiMode = False
      ParentFont = False
      TabOrder = 0
    end
    object Panel4: TPanel
      Left = 0
      Top = 0
      Width = 558
      Height = 49
      Align = alTop
      BevelOuter = bvNone
      Color = clInfoBk
      TabOrder = 1
      object Label0: TLabel
        Left = 32
        Top = 16
        Width = 262
        Height = 13
        Caption = 'This folder contains file. Deceide what you want to do.'
      end
      object Bevel2: TBevel
        Left = 0
        Top = 36
        Width = 558
        Height = 13
        Align = alBottom
        Shape = bsBottomLine
      end
    end
    object Panel6: TPanel
      Left = 0
      Top = 49
      Width = 558
      Height = 105
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 2
      object Bevel3: TBevel
        Left = 0
        Top = 80
        Width = 558
        Height = 25
        Align = alBottom
        Shape = bsBottomLine
      end
      object Image1: TImage
        Left = 34
        Top = 32
        Width = 32
        Height = 32
        IncrementalDisplay = True
        ParentShowHint = False
        ShowHint = False
      end
      object Label1: TLabel
        Left = 68
        Top = 32
        Width = 477
        Height = 61
        Anchors = [akLeft, akTop, akRight]
        AutoSize = False
        Transparent = True
        Layout = tlCenter
      end
      object SpeedButton1: TSpeedButton
        Left = 34
        Top = 70
        Width = 32
        Height = 22
        Flat = True
        Glyph.Data = {
          EE000000424DEE000000000000007600000028000000180000000A0000000100
          0400000000007800000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00DDDDDDDDDDDD
          DDDDDDDDDDDDDDD000000DDDDDD777777DDDDDD000000DDDDDD777777DDDDDDD
          DDDDDDDDDDDDDDDDDDDDDDD000000DDDDDD777777DDDDDD000000DDDDDD77777
          7DDDDDDDDDDDDDDDDDDDDDDDDDDDDDD000000DDDDDD777777DDDDDD000000DDD
          DDD777777DDDDDDDDDDDDDDDDDDDDDDDDDDD}
        NumGlyphs = 2
      end
      object StaticText1: TStaticText
        Left = 34
        Top = 9
        Width = 235
        Height = 17
        Caption = 'Do you want to replace existing file (old):'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
    end
    object Panel7: TPanel
      Left = 0
      Top = 154
      Width = 558
      Height = 105
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 3
      object Image2: TImage
        Left = 34
        Top = 31
        Width = 32
        Height = 32
        IncrementalDisplay = True
        ParentShowHint = False
        ShowHint = False
      end
      object Label2: TLabel
        Left = 68
        Top = 28
        Width = 481
        Height = 65
        Anchors = [akLeft, akTop, akRight]
        AutoSize = False
        Transparent = True
        Layout = tlCenter
      end
      object SpeedButton2: TSpeedButton
        Left = 34
        Top = 69
        Width = 32
        Height = 22
        Flat = True
        Glyph.Data = {
          EE000000424DEE000000000000007600000028000000180000000A0000000100
          0400000000007800000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00DDDDDDDDDDDD
          DDDDDDDDDDDDDDD000000DDDDDD777777DDDDDD000000DDDDDD777777DDDDDDD
          DDDDDDDDDDDDDDDDDDDDDDD000000DDDDDD777777DDDDDD000000DDDDDD77777
          7DDDDDDDDDDDDDDDDDDDDDDDDDDDDDD000000DDDDDD777777DDDDDD000000DDD
          DDD777777DDDDDDDDDDDDDDDDDDDDDDDDDDD}
        NumGlyphs = 2
      end
      object Bevel4: TBevel
        Left = 0
        Top = 88
        Width = 558
        Height = 17
        Align = alBottom
        Shape = bsBottomLine
      end
      object StaticText2: TStaticText
        Left = 34
        Top = 8
        Width = 105
        Height = 17
        Caption = 'To this one (new):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
    end
  end
  object ExeResource1: TExeResource
    Kind = rkICON
    LibFileName = 'shell32.dll'
    SizeX = 32
    SizeY = 32
    Left = 32
    Top = 108
  end
end
