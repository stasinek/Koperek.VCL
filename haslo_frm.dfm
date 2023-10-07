object Haslo_form: THaslo_form
  Left = 430
  Top = 241
  BorderStyle = bsDialog
  Caption = 'Set your password'
  ClientHeight = 179
  ClientWidth = 447
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 129
    Width = 447
    Height = 50
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 0
    object Label4: TLabel
      Left = 16
      Top = 20
      Width = 27
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = 'HINT'
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object OKBtn: TButton
      Left = 269
      Top = 15
      Width = 76
      Height = 23
      Anchors = [akRight, akBottom]
      Cancel = True
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
      OnClick = OKBtnClick
    end
    object CancelBtn: TButton
      Left = 356
      Top = 15
      Width = 76
      Height = 23
      Anchors = [akRight, akBottom]
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 0
    Width = 89
    Height = 129
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
    object Bevel1: TBevel
      Left = 65
      Top = 0
      Width = 24
      Height = 129
      Align = alRight
      Shape = bsRightLine
    end
    object Image1: TImage
      Left = 20
      Top = 16
      Width = 48
      Height = 48
    end
  end
  object Panel5: TPanel
    Left = 89
    Top = 0
    Width = 358
    Height = 129
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 2
    object Panel2: TPanel
      Left = 0
      Top = 48
      Width = 358
      Height = 81
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 0
      object Label1: TLabel
        Left = 14
        Top = 24
        Width = 50
        Height = 13
        Caption = '&Password:'
      end
      object Label2: TLabel
        Left = 14
        Top = 48
        Width = 110
        Height = 13
        Caption = '&REPEAT the password:'
      end
      object Password1: TEdit
        Left = 133
        Top = 15
        Width = 213
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        PasswordChar = '*'
        TabOrder = 0
        OnChange = Password1Change
      end
      object Password2: TEdit
        Left = 133
        Top = 43
        Width = 213
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        PasswordChar = '*'
        TabOrder = 1
        OnChange = Password2Change
      end
    end
    object Panel3: TPanel
      Left = 0
      Top = 0
      Width = 358
      Height = 45
      Align = alTop
      BevelOuter = bvNone
      Color = clInfoBk
      TabOrder = 1
      object Label3: TLabel
        Left = 18
        Top = 16
        Width = 278
        Height = 13
        Anchors = [akLeft, akTop, akRight]
        Caption = 'Set Your password for protecting a compressed file (.eno)'
        WordWrap = True
      end
    end
  end
  object ExeResource1: TExeResource
    Left = 24
    Top = 81
  end
end
