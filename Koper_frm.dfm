object Koper_form: TKoper_form
  Left = 196
  Top = 139
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'sstsoft->Koperek - please wait...'
  ClientHeight = 415
  ClientWidth = 574
  Color = clBtnFace
  Constraints.MinHeight = 320
  Constraints.MinWidth = 550
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  PrintScale = poNone
  Scaled = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 343
    Width = 574
    Height = 72
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 0
    object SpeedButton4: TSpeedButton
      Left = 9
      Top = 12
      Width = 95
      Height = 48
      Anchors = [akRight, akBottom]
      Caption = 'FILE LIST'
      Glyph.Data = {
        76020000424D7602000000000000760000002800000020000000200000000100
        0400000000000002000000000000000000001000000000000000FF00FF008080
        800000FFFF00C0C0C000FFFFFF0000000000FF00000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000003333333333333333333333300000000555555
        5555555555555555530000000054444444444444444444445300000000544444
        4444443333333334530000000054444444444555555555345300000000544444
        4444453111111534530000000054443333333543333315345300000000544555
        5555554444331534530000000054453444444555544435445300000000544534
        4444456665555444530000000054453444444555544444445300000000544534
        4444443333333334530000000054453444444555555555345300000000544534
        4444453111111534530000000054453333333543333315345300000000544555
        5555554444331534530000000054453444444555544435445300003333533533
        3333456665555444530005555555555555534555544444445300111111111111
        1153444444444444530014232323232321534444444444445300143232323232
        3155555555555555530014232323232321566666666666665300143232323232
        3155555555555555500014232323232321530000000000000000143232323232
        3153000000000000000014232323232321530000000000000000144444444444
        4150000000000000000012323232111111000000000000000000012323210000
        0000000000000000000000111110000000000000000000000000}
      OnClick = SpeedButton4Click
    end
    object SpeedButton3: TSpeedButton
      Left = 109
      Top = 12
      Width = 45
      Height = 48
      AllowAllUp = True
      Anchors = [akRight, akBottom]
      Caption = '+'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SpeedButton1: TSpeedButton
      Left = 462
      Top = 12
      Width = 45
      Height = 48
      Hint = 'Na chwile odpocznij'
      AllowAllUp = True
      Anchors = [akRight, akBottom]
      GroupIndex = 1
      Glyph.Data = {
        06020000424D0602000000000000760000002800000028000000140000000100
        0400000000009001000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        333333333333333333333333CCCC3333CCCC3333333377773333777733333333
        CCCC3333CCCC3333333377773333777733333333CCCC3333CCCC333333337777
        3333777733333333CCCC3333CCCC3333333377773333777733333333CCCC3333
        CCCC3333333377773333777733333333CCCC3333CCCC33333333777733337777
        33333333CCCC3333CCCC3333333377773333777733333333CCCC3333CCCC3333
        333377773333777733333333CCCC3333CCCC3333333377773333777733333333
        CCCC3333CCCC3333333377773333777733333333CCCC3333CCCC333333337777
        3333777733333333CCCC3333CCCC333333337777333377773333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        33333333333333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      Spacing = 0
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 513
      Top = 12
      Width = 49
      Height = 48
      Hint = 'Przerwij'
      AllowAllUp = True
      Anchors = [akRight, akBottom]
      GroupIndex = 2
      Glyph.Data = {
        06020000424D0602000000000000760000002800000028000000140000000100
        0400000000009001000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333339999999999993333333377777777777733333333
        9999999999993333333377777777777733333333999999999999333333337777
        7777777733333333999999999999333333337777777777773333333399999999
        9999333333337777777777773333333399999999999933333333777777777777
        3333333399999999999933333333777777777777333333339999999999993333
        3333777777777777333333339999999999993333333377777777777733333333
        9999999999993333333377777777777733333333999999999999333333337777
        7777777733333333999999999999333333337777777777773333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        33333333333333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      Spacing = 0
      OnClick = SpeedButton2Click
    end
    object SpeedButton5: TSpeedButton
      Left = 411
      Top = 12
      Width = 45
      Height = 48
      Hint = 'Set speed limits'
      AllowAllUp = True
      Anchors = [akRight, akBottom]
      GroupIndex = 1
      Glyph.Data = {
        B6060000424DB606000000000000760000002800000050000000280000000100
        0400000000004006000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333300000333
        3333300000333333003300333333333333333333333333333333333333333333
        3333333300000333333330000033333300330033333333333333333333333333
        3333333333333333333333330000033333333000003333330033003333333333
        3333333333333333333333333333333333333333000003333333300000333333
        0000033333333333333333333333333333333333333333333333333300000333
        3333300000333333003300333333333333333333333333333333333333333333
        3333333300000333333330000033333300330033333333333333333333333333
        3333333333333333333333330000033333333000003333330033003333333333
        3333333333333333333333333333333333333333000003333333300000333333
        0000033333333333333333333333333333333333333333333333333300000333
        3333300000333333333333333333333333333333333333333333333333333333
        3333333300000333333330000033333333333333333333333333333333333333
        3333333333333333333333330000033333333000003333333333333333333333
        3333333333333333333333333333333333333333000003333333300000333333
        3333333333333333333333333333333333333333333333333333333000000033
        3333000000033333333333333333333333333333333333333333333333333333
        3333333000000000000000000000000000000003333333333333333333333333
        3333333333333333333333300000000000000000000000000000000333333333
        3333333333333333333333333333333333333330000000000000000000000000
        0000000333333333333333333333333333333333333333333333333000000000
        0000000000000000000000033333333333333333333333333333333333333333
        3333333000000000000000000000000000000003333333333333333333333333
        3333333333333333333333300000003333330000000333333300000333333333
        3333333333333333333333333333333333333333000003333333300000333333
        3300000333333333333333333333333333333333333333333333333300000333
        3333300000333333330000033333333333333333333333333333333333333333
        3333333300000333333330000033333333000003333333333333333333333333
        3333333333333333333333330000033333333000003333333300000333333333
        3333333333333333333333333333333333333333000003333333300000333333
        3300000333333333333333333333333333333333333333333333333300000333
        3333300000333333330000033333333333333333333333333333333333333333
        3333333300000333333330000033333333000003333333333333333333333333
        3333333333333333333333330000033333333000003333333300000333333333
        3333333333333333333333333333333333333333000003333333300000333333
        3300000333333333333333333333333333333333333333333333333300000333
        3333300000333333330000033333333333333333333333333333333333333333
        3333333300000333333330000033333333000003333333333333333333333333
        3333333333333333333333330000033333333000003333333300000333333333
        3333333333333333333333333333333333333333000003333333300000333333
        3300000333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333333333333333
        3333333333333333333333333333333333333333333333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      Spacing = 0
      OnClick = SpeedButton5Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 343
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
    object Bevel1: TBevel
      Left = 135
      Top = 0
      Width = 50
      Height = 343
      Align = alRight
      Shape = bsRightLine
    end
    object AdvancedBar3: TAdvancedBar
      Left = 28
      Top = 129
      Width = 121
      Height = 20
      TextBackColor = clHighlight
      TextSuffix = '%'
    end
    object AdvancedBar4: TAdvancedBar
      Left = 28
      Top = 172
      Width = 121
      Height = 20
      TextBackColor = clHighlight
      TextSuffix = '%'
    end
    object AdvancedBar5: TAdvancedBar
      Left = 28
      Top = 216
      Width = 121
      Height = 20
      TextBackColor = clHighlight
      TextSuffix = '%'
    end
  end
  object Panel1: TPanel
    Left = 185
    Top = 0
    Width = 389
    Height = 343
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 2
    object Panel4: TPanel
      Left = 0
      Top = 0
      Width = 389
      Height = 313
      Align = alTop
      BevelOuter = bvNone
      BorderWidth = 10
      TabOrder = 0
      object Label1: TLabel
        Left = 10
        Top = 30
        Width = 369
        Height = 20
        Align = alTop
        AutoSize = False
        Caption = 'Averange speed is 0 B/s, 0 files/s'
        Constraints.MinHeight = 20
        ShowAccelChar = False
        Transparent = True
        Layout = tlCenter
      end
      object Label2: TLabel
        Left = 10
        Top = 10
        Width = 369
        Height = 20
        Align = alTop
        AutoSize = False
        Caption = 'Time left 0 sekund since 0 seconds'
        Constraints.MinHeight = 20
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ShowAccelChar = False
        Transparent = True
        Layout = tlCenter
      end
      object Label3: TLabel
        Left = 10
        Top = 63
        Width = 369
        Height = 20
        Align = alTop
        Caption = 'Actual speed ~ '
        Constraints.MinHeight = 20
        Transparent = True
        Layout = tlCenter
      end
      object Label4: TLabel
        Left = 10
        Top = 290
        Width = 369
        Height = 13
        Align = alBottom
        AutoSize = False
        Caption = 'File name'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Default'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
      end
      object Label5: TLabel
        Left = 10
        Top = 50
        Width = 369
        Height = 13
        Align = alTop
        Caption = 'Left x.xx MB and xxxx files.'
      end
      object Bevel2: TBevel
        Left = 10
        Top = 285
        Width = 369
        Height = 5
        Align = alBottom
        Shape = bsBottomLine
      end
      object Bevel3: TBevel
        Left = 10
        Top = 83
        Width = 369
        Height = 10
        Align = alTop
        Shape = bsTopLine
      end
      object AdvancedBar1: TAdvancedBar
        Left = 12
        Top = 129
        Width = 369
        Height = 20
        TextBackColor = clHighlight
        TextSuffix = '%'
      end
      object AdvancedBar2: TAdvancedBar
        Left = 12
        Top = 172
        Width = 369
        Height = 20
        TextBackColor = clHighlight
        TextSuffix = '%'
      end
      object AdvancedBar6: TAdvancedBar
        Left = 12
        Top = 216
        Width = 369
        Height = 20
        TextBackColor = clHighlight
        TextSuffix = '%'
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 220
    OnTimer = Timer1Timer
    Left = 180
    Top = 341
  end
  object SysTray1: TSysTray
    Hint = '????t????'
    Left = 224
    Top = 341
  end
end
