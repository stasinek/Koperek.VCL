object QuestForm: TQuestForm
  Left = 464
  Top = 114
  BorderStyle = bsDialog
  Caption = 'Potwierdz usuwanie'
  ClientHeight = 368
  ClientWidth = 485
  Color = clBtnFace
  DefaultMonitor = dmDesktop
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Default'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = True
  Position = poDesktopCenter
  PrintScale = poNone
  Scaled = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel0: TPanel
    Left = 138
    Top = 4
    Width = 340
    Height = 60
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 0
    object Label5: TLabel
      Left = 20
      Top = 12
      Width = 252
      Height = 13
      Caption = 'Kreator programu TSoft, where? - KOPEREK 7'
      Color = clWhite
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Default'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object Label6: TLabel
      Left = 44
      Top = 28
      Width = 157
      Height = 13
      Caption = 'Potwierd'#313#351' dokonanie operacji...'
    end
  end
  object PageControl1: TPageControl
    Left = 138
    Top = 68
    Width = 340
    Height = 253
    ActivePage = TabSheet1
    Style = tsFlatButtons
    TabIndex = 0
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'opcje plik'#258#322'w...'
      object SpeedButton3: TSpeedButton
        Left = 276
        Top = 108
        Width = 21
        Height = 21
        Hint = 'Dodaj katalog...'
        Flat = True
        Glyph.Data = {
          DE000000424DDE0000000000000076000000280000000D0000000D0000000100
          0400000000006800000000000000000000001000000010000000000000000000
          BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7000777777777777700077777000777770007777700077777000777770007777
          7000770000000007700077000000000770007700000000077000777770007777
          7000777770007777700077777000777770007777777777777000777777777777
          7000}
        ParentShowHint = False
        ShowHint = True
        OnClick = SpeedButton3Click
      end
      object SpeedButton4: TSpeedButton
        Left = 276
        Top = 152
        Width = 21
        Height = 21
        Hint = 'Dodaj katalog...'
        Flat = True
        Glyph.Data = {
          DE000000424DDE0000000000000076000000280000000D0000000D0000000100
          0400000000006800000000000000000000001000000010000000000000000000
          BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7000777777777777700077777000777770007777700077777000777770007777
          7000770000000007700077000000000770007700000000077000777770007777
          7000777770007777700077777000777770007777777777777000777777777777
          7000}
        ParentShowHint = False
        ShowHint = True
        OnClick = SpeedButton4Click
      end
      object SpeedButton1: TSpeedButton
        Left = 297
        Top = 108
        Width = 21
        Height = 21
        Hint = 'Pomi'#313#8222'...'
        Flat = True
        Glyph.Data = {
          42010000424D4201000000000000760000002800000011000000110000000100
          040000000000CC00000000000000000000001000000010000000000000000000
          BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          777770000000777777777777777770000000777777777777770F700000007777
          0F777777777770000000777000F7777770F770000000777000F777770F777000
          00007777000F77700F777000000077777000F700F7777000000077777700000F
          7777700000007777777000F777777000000077777700000F7777700000007777
          7000F70F7777700000007770000F77700F7770000000770000F7777700F77000
          00007700F7777777700F70000000777777777777777770000000777777777777
          777770000000}
        ParentShowHint = False
        ShowHint = True
        OnClick = SpeedButton1Click
      end
      object SpeedButton2: TSpeedButton
        Left = 297
        Top = 152
        Width = 21
        Height = 21
        Hint = 'Pomi'#313#8222'...'
        Flat = True
        Glyph.Data = {
          42010000424D4201000000000000760000002800000011000000110000000100
          040000000000CC00000000000000000000001000000010000000000000000000
          BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          777770000000777777777777777770000000777777777777770F700000007777
          0F777777777770000000777000F7777770F770000000777000F777770F777000
          00007777000F77700F777000000077777000F700F7777000000077777700000F
          7777700000007777777000F777777000000077777700000F7777700000007777
          7000F70F7777700000007770000F77700F7770000000770000F7777700F77000
          00007700F7777777700F70000000777777777777777770000000777777777777
          777770000000}
        ParentShowHint = False
        ShowHint = True
        OnClick = SpeedButton2Click
      end
      object StaticText1: TStaticText
        Left = 16
        Top = 3
        Width = 76
        Height = 17
        Caption = 'Text listowania'
        TabOrder = 0
      end
      object Edit2: TEdit
        Left = 16
        Top = 20
        Width = 180
        Height = 21
        TabStop = False
        AutoSelect = False
        AutoSize = False
        TabOrder = 1
        Text = '#file'
        OnChange = Edit2Change
      end
      object StaticText2: TStaticText
        Left = 16
        Top = 47
        Width = 70
        Height = 17
        Caption = 'Maska plik'#258#322'w'
        TabOrder = 2
      end
      object Edit3: TEdit
        Left = 16
        Top = 64
        Width = 180
        Height = 21
        TabStop = False
        AutoSelect = False
        AutoSize = False
        TabOrder = 3
        Text = '*.*'
        OnChange = Edit3Change
      end
      object StaticText3: TStaticText
        Left = 16
        Top = 91
        Width = 98
        Height = 17
        Caption = 'Lista '#313#351'r'#258#322'd'#313#8218'owa...'
        TabOrder = 4
      end
      object SrcListCombo: TComboBox
        Left = 16
        Top = 108
        Width = 257
        Height = 21
        Ctl3D = True
        ItemHeight = 13
        MaxLength = 430
        ParentCtl3D = False
        TabOrder = 5
        TabStop = False
        Text = 'Disabled'
      end
      object StaticText4: TStaticText
        Left = 16
        Top = 135
        Width = 86
        Height = 17
        Caption = 'Lista docelowa...'
        TabOrder = 6
      end
      object DstListCombo: TComboBox
        Left = 16
        Top = 152
        Width = 257
        Height = 21
        ItemHeight = 13
        MaxLength = 430
        TabOrder = 7
        TabStop = False
        Text = 'Disabled'
      end
      object CheckBox8: TCheckBox
        Left = 16
        Top = 184
        Width = 305
        Height = 17
        Caption = 'Nie nadpisuj plik'#258#322'w docelowych o tej samej dacie i rozmiarze'
        Enabled = False
        TabOrder = 8
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'opcje kompresji...'
      ImageIndex = 1
      object StaticText5: TStaticText
        Left = 156
        Top = 196
        Width = 90
        Height = 17
        Caption = 'Rozmiar s'#313#8218'ownika'
        TabOrder = 0
      end
      object ComboBox1: TComboBox
        Left = 252
        Top = 192
        Width = 69
        Height = 21
        ItemHeight = 13
        TabOrder = 1
        Text = '4096'
        OnChange = ComboBox1Change
        Items.Strings = (
          '256'
          '512'
          '2048'
          '4096'
          '16384'
          '65536')
      end
      object GroupBox1: TGroupBox
        Left = 16
        Top = 4
        Width = 313
        Height = 181
        Caption = 'Metoda kompresji'
        TabOrder = 2
        object CheckBox1: TCheckBox
          Left = 8
          Top = 20
          Width = 297
          Height = 17
          Caption = 'XOR - proste kodowanie'
          TabOrder = 0
          OnClick = CheckBox1Click
        end
        object CheckBox2: TCheckBox
          Left = 8
          Top = 40
          Width = 297
          Height = 17
          Caption = 'SXQ - kodowanie przestawianiem znak'#258#322'w'
          TabOrder = 1
          OnClick = CheckBox2Click
        end
        object CheckBox3: TCheckBox
          Left = 8
          Top = 60
          Width = 297
          Height = 17
          Caption = 'LZ77 - kodowanie s'#313#8218'ownikowe + RLE'
          TabOrder = 2
          OnClick = CheckBox3Click
        end
        object CheckBox5: TCheckBox
          Left = 8
          Top = 100
          Width = 297
          Height = 17
          Caption = 'Move to front - zmie'#313#8222' powtarzane znaki na ni'#313#317'szy liczby'
          TabOrder = 3
          OnClick = CheckBox5Click
        end
        object CheckBox4: TCheckBox
          Left = 8
          Top = 80
          Width = 297
          Height = 17
          Caption = 'Burrows-Weller - transformacja kolejnosci znak'#258#322'w'
          Enabled = False
          TabOrder = 4
          OnClick = CheckBox4Click
        end
        object CheckBox6: TCheckBox
          Left = 8
          Top = 120
          Width = 297
          Height = 17
          Caption = 'HUFF - zamie'#313#8222' powtarzane bajty do kodu z bit'#258#322'w'
          TabOrder = 5
          OnClick = CheckBox6Click
        end
        object CheckBox7: TCheckBox
          Left = 8
          Top = 140
          Width = 297
          Height = 17
          Caption = 'ARI - przedstaw bajty rachunkiem prawdopodobie'#313#8222'stwa'
          TabOrder = 6
          OnClick = CheckBox7Click
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 137
    Height = 327
    Align = alLeft
    BevelOuter = bvNone
    Color = clSilver
    TabOrder = 2
    object Image1: TImage
      Left = 0
      Top = 4
      Width = 134
      Height = 313
      AutoSize = True
      DragCursor = crDefault
      DragKind = dkDock
    end
    object Image2: TImage
      Left = 74
      Top = 34
      Width = 32
      Height = 32
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 327
    Width = 485
    Height = 41
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 3
    object Button3: TButton
      Left = 401
      Top = 10
      Width = 75
      Height = 23
      Caption = '&Anuluj'
      ModalResult = 7
      TabOrder = 0
      TabStop = False
    end
    object Button1: TButton
      Left = 231
      Top = 10
      Width = 80
      Height = 23
      Caption = '< &Wstecz'
      TabOrder = 1
      TabStop = False
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 311
      Top = 10
      Width = 80
      Height = 23
      Caption = '&Dalej >'
      TabOrder = 2
      TabStop = False
      OnClick = Button2Click
    end
  end
  object BrowseDialog1: TBrowseDialog
    Title = 'Dodaj katalog...'
    Options = [bdDontGoBelowDomain, bdReturnFsDirs]
    InitialPath = 'c:\'
    Left = 420
    Top = 16
  end
end
