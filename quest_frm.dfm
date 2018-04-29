object QuestForm: TQuestForm
  Left = 231
  Top = 178
  BorderStyle = bsDialog
  Caption = 'Confirm operation'
  ClientHeight = 440
  ClientWidth = 667
  Color = clBtnFace
  DefaultMonitor = dmDesktop
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = True
  Position = poDesktopCenter
  PrintScale = poNone
  Scaled = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 137
    Height = 399
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
    object Image1: TImage
      Left = 4
      Top = 4
      Width = 125
      Height = 313
      AutoSize = True
      DragCursor = crDefault
      DragKind = dkDock
    end
    object Image2: TImage
      Left = 74
      Top = 38
      Width = 32
      Height = 32
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 399
    Width = 667
    Height = 41
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 0
    object Button3: TButton
      Left = 500
      Top = 10
      Width = 156
      Height = 23
      Anchors = [akTop, akRight]
      Caption = '&Cancel'
      ModalResult = 7
      TabOrder = 0
      TabStop = False
    end
    object Button1: TButton
      Left = 308
      Top = 10
      Width = 80
      Height = 23
      Anchors = [akTop, akRight]
      Caption = '< &Back'
      TabOrder = 1
      TabStop = False
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 392
      Top = 10
      Width = 80
      Height = 23
      Anchors = [akTop, akRight]
      Caption = '&Next >'
      TabOrder = 2
      TabStop = False
      OnClick = Button2Click
    end
  end
  object Panel3: TPanel
    Left = 137
    Top = 0
    Width = 462
    Height = 399
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Panel0: TPanel
      Left = 0
      Top = 0
      Width = 462
      Height = 65
      Align = alTop
      BevelOuter = bvNone
      Color = clWhite
      TabOrder = 0
      object Label5: TLabel
        Left = 20
        Top = 12
        Width = 107
        Height = 13
        Caption = 'KOPEREK 7 Wizzard'
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        Transparent = True
      end
      object Label6: TLabel
        Left = 20
        Top = 28
        Width = 178
        Height = 13
        Caption = 'Confirm or deny requested operation'
      end
    end
    object PageControl1: TPageControl
      Left = 0
      Top = 140
      Width = 462
      Height = 259
      ActivePage = TabSheet1
      Align = alBottom
      Style = tsFlatButtons
      TabOrder = 1
      object TabSheet1: TTabSheet
        Caption = 'Global options...'
        object SpeedButton3: TSpeedButton
          Left = 284
          Top = 108
          Width = 29
          Height = 22
          Hint = 'Add dir...'
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
          Left = 284
          Top = 152
          Width = 29
          Height = 22
          Hint = 'Add dir...'
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
          Left = 313
          Top = 108
          Width = 32
          Height = 22
          Hint = 'Skip...'
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
          Left = 313
          Top = 152
          Width = 32
          Height = 22
          Hint = 'Skip...'
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
          Width = 69
          Height = 17
          Caption = 'Listing format'
          TabOrder = 0
        end
        object Edit2: TEdit
          Left = 16
          Top = 20
          Width = 257
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
          Width = 47
          Height = 17
          Caption = 'File mask'
          TabOrder = 2
        end
        object Edit3: TEdit
          Left = 16
          Top = 64
          Width = 257
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
          Width = 65
          Height = 17
          Caption = 'Source list...'
          TabOrder = 4
        end
        object SrcListCombo: TComboBox
          Left = 16
          Top = 108
          Width = 257
          Height = 21
          TabStop = False
          Ctl3D = True
          ItemHeight = 13
          MaxLength = 430
          ParentCtl3D = False
          TabOrder = 5
          Text = 'Disabled'
        end
        object StaticText4: TStaticText
          Left = 16
          Top = 135
          Width = 86
          Height = 17
          Caption = 'Destination list...'
          TabOrder = 6
        end
        object DstListCombo: TComboBox
          Left = 16
          Top = 152
          Width = 257
          Height = 21
          TabStop = False
          ItemHeight = 13
          MaxLength = 430
          TabOrder = 7
          Text = 'Disabled'
        end
        object CheckBox8: TCheckBox
          Left = 16
          Top = 188
          Width = 305
          Height = 17
          Caption = 'Don'#39't overwrite destination files with same date and size'
          Enabled = False
          Font.Charset = EASTEUROPE_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 8
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Compression options...'
        ImageIndex = 1
        object StaticText5: TStaticText
          Left = 12
          Top = 200
          Width = 100
          Height = 17
          Caption = 'Block/dictionary size'
          TabOrder = 0
        end
        object ComboBox1: TComboBox
          Left = 124
          Top = 196
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
          Left = 12
          Top = 4
          Width = 436
          Height = 181
          Anchors = [akLeft, akTop, akRight]
          Caption = 'Metoda kompresji'
          TabOrder = 2
          object CheckBox1: TCheckBox
            Left = 8
            Top = 20
            Width = 329
            Height = 17
            Caption = 'XOR - simple symetrical cipher based on boolean arithmetic'
            TabOrder = 0
            OnClick = CheckBox1Click
          end
          object CheckBox2: TCheckBox
            Left = 8
            Top = 40
            Width = 333
            Height = 17
            Caption = 'SXQ - another simple cipher based on chars rearangement'
            TabOrder = 1
            OnClick = CheckBox2Click
          end
          object CheckBox3: TCheckBox
            Left = 8
            Top = 60
            Width = 333
            Height = 17
            Caption = 'LZS - find duplicated blocks and letters (RLE included)'
            TabOrder = 2
            OnClick = CheckBox3Click
          end
          object CheckBox5: TCheckBox
            Left = 8
            Top = 100
            Width = 329
            Height = 17
            Caption = 'Move to front - expose local pattern as global simmilarities'
            TabOrder = 3
            OnClick = CheckBox5Click
          end
          object CheckBox4: TCheckBox
            Left = 8
            Top = 80
            Width = 325
            Height = 17
            Caption = 'BWT - Burrows-Weller sort local patterns and arrange in groups'
            Enabled = False
            TabOrder = 4
            OnClick = CheckBox4Click
          end
          object CheckBox6: TCheckBox
            Left = 8
            Top = 120
            Width = 325
            Height = 17
            Caption = 'HUFF - write most used letters using only few bits'
            TabOrder = 5
            OnClick = CheckBox6Click
          end
          object CheckBox7: TCheckBox
            Left = 8
            Top = 140
            Width = 325
            Height = 17
            Caption = 'ARI - code letters as their probability, code can be <1 bit'
            TabOrder = 6
            OnClick = CheckBox7Click
          end
        end
      end
    end
  end
  object Panel4: TPanel
    Left = 599
    Top = 0
    Width = 68
    Height = 399
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
    object SpeedButton9: TSpeedButton
      Left = 16
      Top = 275
      Width = 41
      Height = 40
      AllowAllUp = True
      Constraints.MinHeight = 36
      Constraints.MinWidth = 36
      GroupIndex = 8
      Glyph.Data = {
        76020000424D7602000000000000760000002800000020000000200000000100
        0400000000000002000000000000000000001000000000000000FF00FF008080
        8000FFFFFF00C0C0C0000000800000000000A4A0A00080000000808000000080
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000006666666666666666666666000000000155555
        5555555555555555600000000013333333333333333333356000000000122222
        2222222222222235600000000012222222222222222222356000000000122222
        2222222222222235600000000012225525522777777222356000000000122255
        2552222222222235600000000012255555552999999222356000000000122255
        2552222222222235600000000012225525522111111222356000000000122255
        2552222222222235600000000012225525522555555222356000000000122555
        5555222222222235600000000012225525522999999222356000000000122255
        2552222222222235600000000012222222222555555222356000000000122222
        2222222222222235600000000012244444444444444222356000000000122222
        2222222222222235600000000012288888888888888223356000000000122222
        2222222222223315600000000012277777777772222331156000000000122222
        2222222222331115600000000012255555555552215555550000000000122222
        2222222221223110000000000012244444444442212311000000000000122222
        2222222221311000000000000012222222222222211100000000000000122222
        2222222221100000000000000011111111111111110000000000}
      OnClick = SpeedButton9Click
    end
    object SpeedButton5: TSpeedButton
      Left = 16
      Top = 12
      Width = 40
      Height = 40
      AllowAllUp = True
      Constraints.MinHeight = 36
      Constraints.MinWidth = 36
      GroupIndex = 8
      Glyph.Data = {
        76020000424D7602000000000000760000002800000020000000200000000100
        0400000000000002000000000000000000001000000000000000FF00FF00FF00
        000080000000C0C0C000FFFFFF000000000080808000A4A0A000008080000080
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000777777777777777770000000009700
        0899999999999999997000000777997008888888888888888970000099999997
        0834444444444444897000009999999008344444444444448970000097009900
        0834455555555544897000009000900008344444444444448970000000000000
        0834455555544444897000000000000008344444444444448970000777777777
        7834455555555544897000122222222228344444444444448970001111111111
        1834455555555544897000134444444448344444444444438970001344444444
        4834455544444433897000134455555558344444444443368970001344444444
        4834455544999999990000134455555548344444448344489000001344444444
        4834455444834489000000134455555558344444448348900000001344444444
        4834444444838900000000134455555558333333338890000000001344444444
        4888888888890000000000134455544444433127000000000000001344444444
        4433612700000000000000134455544222222220000000000000001344444441
        3444120000000000000000134455544134412000000000000000001344444441
        3412000000000000000000134444444131200000000000000000001333333331
        1200000000000000000000111111111120000000000000000000}
      OnClick = SpeedButton5Click
    end
    object SpeedButton6: TSpeedButton
      Left = 16
      Top = 56
      Width = 40
      Height = 40
      AllowAllUp = True
      Constraints.MinHeight = 36
      Constraints.MinWidth = 36
      GroupIndex = 8
      Glyph.Data = {
        76020000424D7602000000000000760000002800000020000000200000000100
        0400000000000002000000000000000000001000000000000000FF00FF00FF00
        000080000000C0C0C000FFFFFF000000000080808000A4A0A000000080000000
        FF00000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000007000000000000000000000
        0000000005570000000000000000000000000000055570000000000000000000
        0000000005555700000000000000000000000000058855700000000000000000
        0777777775898557000000000000000055555555558998557000000000000000
        5888888888899985570000777777777758999999999999985570022222222222
        5899999999999999855001111111111158999999999999985500013444444444
        5888888888899985500001344555554455555555558998550000013444444444
        4444127005898550000001344555555555441270058855000000013444444444
        4444127005855000000001344555555444441270055500000000013444444444
        4444127005500000000001344555555555441270000000000000013444444444
        4444127000000000000001344555555554441270000000000000013444444444
        4443127000000000000001344555444444331270000000000000013444444444
        4336127000000000000001344555442222222200000000000000013444444413
        4441200000000000000001344554441344120000000000000000013444444413
        4120000000000000000001344444441312000000000000000000013333333311
        2000000000000000000001111111111200000000000000000000}
      OnClick = SpeedButton6Click
    end
    object SpeedButton7: TSpeedButton
      Left = 16
      Top = 188
      Width = 40
      Height = 40
      AllowAllUp = True
      Constraints.MinHeight = 36
      Constraints.MinWidth = 36
      GroupIndex = 8
      Glyph.Data = {
        76020000424D7602000000000000760000002800000020000000200000000100
        0400000000000002000000000000000000001000000000000000FF00FF000000
        0000C0C0C00080808000A4A0A000FFFFFF000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000222222222222222220000000000000011111
        1111111111112000000000000001233433433333333120000000000000015542
        3233333333312000000000000001525123212331333120000000000000015521
        2231323133312000000000000001522122312331333120000000000000015551
        2421333133312000000000000001552122313231333120000000000000015551
        2231233133312000000000000001555123213341333120000000000000015521
        2221233133312000000000000001525122313341333120000000000000015521
        2421243133312000000000002221525122313331333122222000000111115521
        2221343133311111200000011111552122314331333111110000000000015551
        2421243133312000000000000001552122313331333120000000000000015521
        2221233133312000000000000001522122312331333120000000000000215221
        4231333133312220000000000111111111111111111111200000000001552522
        2223234333333120000000000155552523223233333331200000000001525252
        2232233333333120000000000111111111111111111111000000000000000001
        2322331120000000000000000000000122324311200000000000000000000001
        2223223120000000000000000000000111111111000000000000}
      OnClick = SpeedButton7Click
    end
    object SpeedButton8: TSpeedButton
      Left = 16
      Top = 100
      Width = 40
      Height = 40
      AllowAllUp = True
      Constraints.MinHeight = 36
      Constraints.MinWidth = 36
      GroupIndex = 8
      Glyph.Data = {
        76020000424D7602000000000000760000002800000020000000200000000100
        0400000000000002000000000000000000001000000000000000FF00FF00FF00
        000080000000C0C0C000FFFFFF0000000000808080000000FF00000080000080
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000009000
        0788888888888888880000000000990007777777777777777800000099999990
        0734444444444444780000009999999007344454544555447800000090009900
        0734445454444444780000009000900007344555554555447800000000000000
        0734445454444444780000000000000007344454544555447800000000000000
        0734455555444444780000122222222227344454544555447800001111111111
        1734445454444444780000134444444447344444444444437800001344444444
        4734455544444433780000134455555557344444444443367800001344444444
        4734455544888888880000134455555557344444447344478000001344444444
        4734455544734478000000134455555557344444447347800000001344444444
        4734444444737800000000134455555557333333337780000000001344444444
        4777777777780000000000134455544444433120000000000000001344444444
        4433612000000000000000134455544222222220000000000000001344444441
        3444120000000000000000134455544134412000000000000000001344444441
        3412000000000000000000134444444131200000000000000000001333333331
        1200000000000000000000111111111120000000000000000000}
      OnClick = SpeedButton8Click
    end
    object SpeedButton10: TSpeedButton
      Left = 16
      Top = 144
      Width = 40
      Height = 40
      AllowAllUp = True
      Constraints.MinHeight = 36
      Constraints.MinWidth = 36
      GroupIndex = 8
      Glyph.Data = {
        76020000424D7602000000000000760000002800000020000000200000000100
        0400000000000002000000000000000000001000000000000000FF00FF000000
        FF0000008000C0C0C000FFFFFF000000000080808000FF000000800000000080
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000009000
        0788888888888888880000000000990007777777777777777800000099999990
        0734444444444444780000009999999007344444444444447800000090009900
        0734455555555544780000009000900007344444444444447800000000000000
        0734455555555544780000000000000007344444444444447800000000000000
        0734455555555544780000122222222227344444444444447800001111111111
        1734455555555544780000134444444447344444444444437800001344454544
        5734455544444433780000134445454447344444444443367800001344555554
        5734455544888888880000134445454447344444447344478000001344454544
        5734455544734478000000134455555447344444447347800000001344454544
        5734444444737800000000134445454447333333337780000000001344444444
        4777777777780000000000134455544444433120000000000000001344444444
        4433612000000000000000134455544222222220000000000000001344444441
        3444120000000000000000134455544134412000000000000000001344444441
        3412000000000000000000134444444131200000000000000000001333333331
        1200000000000000000000111111111120000000000000000000}
      OnClick = SpeedButton10Click
    end
    object SpeedButton11: TSpeedButton
      Left = 16
      Top = 232
      Width = 41
      Height = 40
      AllowAllUp = True
      Constraints.MinHeight = 36
      Constraints.MinWidth = 36
      GroupIndex = 8
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
      OnClick = SpeedButton11Click
    end
    object Bevel1: TBevel
      Left = 0
      Top = 0
      Width = 13
      Height = 399
      Align = alLeft
      Shape = bsLeftLine
    end
  end
  object BrowseDialog1: TBrowseDialog
    Title = '??'#0'?'#0' ??'#0'??????'#1
    Options = [bdDontGoBelowDomain, bdReturnFsDirs]
    InitialPath = '??p'
    Left = 76
    Top = 80
  end
end
