	.686p
	ifdef ??version
	if    ??version GT 500H
	.mmx
	endif
	endif
	model flat
	ifndef	??version
	?debug	macro
	endm
	endif
	?debug	S "D:\stasiek\My Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLIO\TSoft_IO.cpp"
	?debug	T "D:\stasiek\My Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLIO\TSoft_IO.cpp"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BTYPES	segment byte public use32 'DEBTYP'
$$BTYPES	ends
$$BNAMES	segment byte public use32 'DEBNAM'
$$BNAMES	ends
$$BROWSE	segment byte public use32 'DEBSYM'
$$BROWSE	ends
$$BROWFILE	segment byte public use32 'DEBSYM'
$$BROWFILE	ends
DGROUP	group	_BSS,_DATA
_TEXT	segment dword public use32 'CODE'
strAlloc	segment virtual
	align	2
@strAlloc	proc	near
?live16385@0:
	?debug L 9
@1:
	push      ebp
	mov       ebp,esp
	?debug L 11
	mov       eax,dword ptr [ebp+8]
	push      eax
	push      64
	call      @LocalAlloc
	?debug L 12
@3:
@2:
	pop       ebp
	ret       4
	?debug L 0
@strAlloc	endp
strAlloc	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	db	2
	db	0
	db	0
	db	0
	dw	55
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch1
	dd	?patch2
	dd	?patch3
	df	@strAlloc
	dw	0
	dw	4096
	dw	0
	dw	1
	dw	0
	dw	0
	dw	0
	db	8
	db	115
	db	116
	db	114
	db	65
	db	108
	db	108
	db	111
	db	99
	dw	18
	dw	512
	dw	8
	dw	0
	dw	18
	dw	0
	dw	2
	dw	0
	dw	0
	dw	0
?patch1	equ	@3-@strAlloc+4
?patch2	equ	0
?patch3	equ	@3-@strAlloc
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strAllocEx	segment virtual
	align	2
@strAllocEx	proc	near
?live16386@0:
	?debug L 15
@4:
	push      ebp
	mov       ebp,esp
	?debug L 17
	mov       eax,dword ptr [ebp+12]
	push      eax
	mov       edx,dword ptr [ebp+8]
	push      edx
	call      @strAlloc
	push      eax
	call      @strEql
	?debug L 18
@6:
@5:
	pop       ebp
	ret       8
	?debug L 0
@strAllocEx	endp
strAllocEx	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	57
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch4
	dd	?patch5
	dd	?patch6
	df	@strAllocEx
	dw	0
	dw	4098
	dw	0
	dw	3
	dw	0
	dw	0
	dw	0
	db	10
	db	115
	db	116
	db	114
	db	65
	db	108
	db	108
	db	111
	db	99
	db	69
	db	120
	dw	18
	dw	512
	dw	8
	dw	0
	dw	18
	dw	0
	dw	4
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	5
	dw	0
	dw	0
	dw	0
?patch4	equ	@6-@strAllocEx+4
?patch5	equ	0
?patch6	equ	@6-@strAllocEx
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strReAlloc	segment virtual
	align	2
@strReAlloc	proc	near
?live16387@0:
	?debug L 21
@7:
	push      ebp
	mov       ebp,esp
	?debug L 23
	push      2
	mov       eax,dword ptr [ebp+12]
	push      eax
	mov       edx,dword ptr [ebp+8]
	push      edx
	call      @LocalReAlloc
	?debug L 24
@9:
@8:
	pop       ebp
	ret       8
	?debug L 0
@strReAlloc	endp
strReAlloc	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	57
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch7
	dd	?patch8
	dd	?patch9
	df	@strReAlloc
	dw	0
	dw	4102
	dw	0
	dw	6
	dw	0
	dw	0
	dw	0
	db	10
	db	115
	db	116
	db	114
	db	82
	db	101
	db	65
	db	108
	db	108
	db	111
	db	99
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	7
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	8
	dw	0
	dw	0
	dw	0
?patch7	equ	@9-@strReAlloc+4
?patch8	equ	0
?patch9	equ	@9-@strReAlloc
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strReAllocEx	segment virtual
	align	2
@strReAllocEx	proc	near
?live16388@0:
	?debug L 27
@10:
	push      ebp
	mov       ebp,esp
	?debug L 29
	mov       eax,dword ptr [ebp+16]
	push      eax
	mov       edx,dword ptr [ebp+12]
	push      edx
	mov       ecx,dword ptr [ebp+8]
	push      ecx
	call      @strReAlloc
	push      eax
	call      @strEql
	?debug L 30
@12:
@11:
	pop       ebp
	ret       12
	?debug L 0
@strReAllocEx	endp
strReAllocEx	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	59
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch10
	dd	?patch11
	dd	?patch12
	df	@strReAllocEx
	dw	0
	dw	4104
	dw	0
	dw	9
	dw	0
	dw	0
	dw	0
	db	12
	db	115
	db	116
	db	114
	db	82
	db	101
	db	65
	db	108
	db	108
	db	111
	db	99
	db	69
	db	120
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	10
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	11
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	4099
	dw	0
	dw	12
	dw	0
	dw	0
	dw	0
?patch10	equ	@12-@strReAllocEx+4
?patch11	equ	0
?patch12	equ	@12-@strReAllocEx
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strFree	segment virtual
	align	2
@strFree	proc	near
?live16389@0:
	?debug L 33
@13:
	push      ebp
	mov       ebp,esp
	?debug L 35
	mov       eax,dword ptr [ebp+8]
	push      eax
	call      @LocalFree
	?debug L 36
@14:
	pop       ebp
	ret       4
	?debug L 0
@strFree	endp
strFree	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	54
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch13
	dd	?patch14
	dd	?patch15
	df	@strFree
	dw	0
	dw	4106
	dw	0
	dw	13
	dw	0
	dw	0
	dw	0
	db	7
	db	115
	db	116
	db	114
	db	70
	db	114
	db	101
	db	101
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	14
	dw	0
	dw	0
	dw	0
?patch13	equ	@14-@strFree+4
?patch14	equ	0
?patch15	equ	@14-@strFree
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strDup	segment virtual
	align	2
@strDup	proc	near
?live16390@0:
	?debug L 39
@15:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
	?debug L 41
?live16390@16: ; EBX = alpdst
	push      ebx
	push      ebx
	call      @strLen
	inc       eax
	push      eax
	call      @strAlloc
	push      eax
	call      @strEql
	?debug L 42
?live16390@32: ; 
@17:
@16:
	pop       ebx
	pop       ebp
	ret       4
	?debug L 0
@strDup	endp
strDup	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch16
	dd	?patch17
	dd	?patch18
	df	@strDup
	dw	0
	dw	4108
	dw	0
	dw	15
	dw	0
	dw	0
	dw	0
	db	6
	db	115
	db	116
	db	114
	db	68
	db	117
	db	112
	dw	18
	dw	512
	dw	8
	dw	0
	dw	4099
	dw	0
	dw	16
	dw	0
	dw	0
	dw	0
	dw	?patch19
	dw	529
	dw	?patch20
	dd	?live16390@16-@strDup
	dd	?live16390@32-?live16390@16
	dw	20
?patch20	equ	1
?patch19	equ	14
?patch16	equ	@17-@strDup+5
?patch17	equ	0
?patch18	equ	@17-@strDup
	dw	2
	dw	6
	dw	8
	dw	531
	dw	1
	dw	65532
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strReDup	segment virtual
	align	2
@strReDup	proc	near
?live16391@0:
	?debug L 45
@18:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+12]
	?debug L 47
?live16391@16: ; EBX = alpsrc
	push      ebx
	push      ebx
	call      @strLen
	inc       eax
	push      eax
	mov       eax,dword ptr [ebp+8]
	push      eax
	call      @strReAlloc
	push      eax
	call      @strEql
	?debug L 48
?live16391@32: ; 
@20:
@19:
	pop       ebx
	pop       ebp
	ret       8
	?debug L 0
@strReDup	endp
strReDup	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	55
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch21
	dd	?patch22
	dd	?patch23
	df	@strReDup
	dw	0
	dw	4110
	dw	0
	dw	17
	dw	0
	dw	0
	dw	0
	db	8
	db	115
	db	116
	db	114
	db	82
	db	101
	db	68
	db	117
	db	112
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	18
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	19
	dw	0
	dw	0
	dw	0
	dw	?patch24
	dw	529
	dw	?patch25
	dd	?live16391@16-@strReDup
	dd	?live16391@32-?live16391@16
	dw	20
?patch25	equ	1
?patch24	equ	14
?patch21	equ	@20-@strReDup+5
?patch22	equ	0
?patch23	equ	@20-@strReDup
	dw	2
	dw	6
	dw	8
	dw	531
	dw	1
	dw	65532
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strLen	segment virtual
	align	2
@strLen	proc	near
?live16392@0:
	?debug L 51
	push      ebp
	mov       ebp,esp
	push      esi
	push      edi
	?debug L 54
@21:
	mov	 EDI,dword ptr [ebp+8]
	?debug L 55
	mov	 ESI,EDI
	?debug L 56
	mov	 ECX,0FFFFFFFFH
	?debug L 57
	xor	 EAX,EAX
	?debug L 58
	cld	
	?debug L 59
	repnz SCASB	
	?debug L 60
	not	 ECX
	?debug L 61
	dec	 ECX
	?debug L 62
	mov	 EAX,ECX
	?debug L 67
@22:
	pop       edi
	pop       esi
	pop       ebp
	ret       4
	?debug L 0
@strLen	endp
strLen	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch26
	dd	?patch27
	dd	?patch28
	df	@strLen
	dw	0
	dw	4112
	dw	0
	dw	20
	dw	0
	dw	0
	dw	0
	db	6
	db	115
	db	116
	db	114
	db	76
	db	101
	db	110
	dw	18
	dw	512
	dw	8
	dw	0
	dw	4099
	dw	0
	dw	21
	dw	0
	dw	0
	dw	0
?patch26	equ	@22-@strLen+6
?patch27	equ	0
?patch28	equ	@22-@strLen
	dw	2
	dw	6
	dw	8
	dw	531
	dw	6
	dw	65528
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strEql	segment virtual
	align	2
@strEql	proc	near
?live16393@0:
	?debug L 70
@23:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       esi,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+8]
	?debug L 72
?live16393@16: ; EBX = alpdst, ESI = alpsrc
	push      esi
	call      @strLen
	inc       eax
	push      eax
	push      esi
	push      ebx
	call      @ptrEql
	?debug L 73
?live16393@32: ; EBX = alpdst
	mov       eax,ebx
	?debug L 74
?live16393@48: ; 
@25:
@24:
	pop       esi
	pop       ebx
	pop       ebp
	ret       8
	?debug L 0
@strEql	endp
strEql	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch29
	dd	?patch30
	dd	?patch31
	df	@strEql
	dw	0
	dw	4114
	dw	0
	dw	22
	dw	0
	dw	0
	dw	0
	db	6
	db	115
	db	116
	db	114
	db	69
	db	113
	db	108
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	23
	dw	0
	dw	0
	dw	0
	dw	?patch32
	dw	529
	dw	?patch33
	dd	?live16393@16-@strEql
	dd	?live16393@48-?live16393@16
	dw	20
?patch33	equ	1
?patch32	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	24
	dw	0
	dw	0
	dw	0
	dw	?patch34
	dw	529
	dw	?patch35
	dd	?live16393@16-@strEql
	dd	?live16393@32-?live16393@16
	dw	23
?patch35	equ	1
?patch34	equ	14
?patch29	equ	@25-@strEql+6
?patch30	equ	0
?patch31	equ	@25-@strEql
	dw	2
	dw	6
	dw	8
	dw	531
	dw	5
	dw	65528
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strMov	segment virtual
	align	2
@strMov	proc	near
?live16394@0:
	?debug L 77
@26:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       esi,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+8]
	?debug L 79
?live16394@16: ; EBX = alpdst, ESI = alpsrc
	push      esi
	call      @strLen
	inc       eax
	push      eax
	push      esi
	push      ebx
	call      @ptrMov
	?debug L 80
?live16394@32: ; EBX = alpdst
	mov       eax,ebx
	?debug L 81
?live16394@48: ; 
@28:
@27:
	pop       esi
	pop       ebx
	pop       ebp
	ret       8
	?debug L 0
@strMov	endp
strMov	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch36
	dd	?patch37
	dd	?patch38
	df	@strMov
	dw	0
	dw	4116
	dw	0
	dw	25
	dw	0
	dw	0
	dw	0
	db	6
	db	115
	db	116
	db	114
	db	77
	db	111
	db	118
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	26
	dw	0
	dw	0
	dw	0
	dw	?patch39
	dw	529
	dw	?patch40
	dd	?live16394@16-@strMov
	dd	?live16394@48-?live16394@16
	dw	20
?patch40	equ	1
?patch39	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	27
	dw	0
	dw	0
	dw	0
	dw	?patch41
	dw	529
	dw	?patch42
	dd	?live16394@16-@strMov
	dd	?live16394@32-?live16394@16
	dw	23
?patch42	equ	1
?patch41	equ	14
?patch36	equ	@28-@strMov+6
?patch37	equ	0
?patch38	equ	@28-@strMov
	dw	2
	dw	6
	dw	8
	dw	531
	dw	5
	dw	65528
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
@strnEql$qqspcpxcl	segment virtual
	align	2
@@strnEql$qqspcpxcl	proc	near
?live16395@0:
	?debug L 84
@29:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
	?debug L 86
?live16395@16: ; EBX = alpdst
	mov       eax,dword ptr [ebp+16]
	push      eax
	mov       edx,dword ptr [ebp+12]
	push      edx
	push      ebx
	call      @ptrEql
	?debug L 87
	mov       eax,ebx
	?debug L 88
?live16395@48: ; 
@31:
@30:
	pop       ebx
	pop       ebp
	ret       12
	?debug L 0
@@strnEql$qqspcpxcl	endp
@strnEql$qqspcpxcl	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	65
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch43
	dd	?patch44
	dd	?patch45
	df	@@strnEql$qqspcpxcl
	dw	0
	dw	4118
	dw	0
	dw	28
	dw	0
	dw	0
	dw	0
	db	18
	db	64
	db	115
	db	116
	db	114
	db	110
	db	69
	db	113
	db	108
	db	36
	db	113
	db	113
	db	115
	db	112
	db	99
	db	112
	db	120
	db	99
	db	108
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	29
	dw	0
	dw	0
	dw	0
	dw	?patch46
	dw	529
	dw	?patch47
	dd	?live16395@16-@@strnEql$qqspcpxcl
	dd	?live16395@48-?live16395@16
	dw	20
?patch47	equ	1
?patch46	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	30
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	31
	dw	0
	dw	0
	dw	0
?patch43	equ	@31-@@strnEql$qqspcpxcl+5
?patch44	equ	0
?patch45	equ	@31-@@strnEql$qqspcpxcl
	dw	2
	dw	6
	dw	8
	dw	531
	dw	1
	dw	65532
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
@strnMov$qqspcpxcl	segment virtual
	align	2
@@strnMov$qqspcpxcl	proc	near
?live16396@0:
	?debug L 91
@32:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
	?debug L 93
?live16396@16: ; EBX = alpdst
	mov       eax,dword ptr [ebp+16]
	push      eax
	mov       edx,dword ptr [ebp+12]
	push      edx
	push      ebx
	call      @ptrMov
	?debug L 94
	mov       eax,ebx
	?debug L 95
?live16396@48: ; 
@34:
@33:
	pop       ebx
	pop       ebp
	ret       12
	?debug L 0
@@strnMov$qqspcpxcl	endp
@strnMov$qqspcpxcl	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	65
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch48
	dd	?patch49
	dd	?patch50
	df	@@strnMov$qqspcpxcl
	dw	0
	dw	4120
	dw	0
	dw	32
	dw	0
	dw	0
	dw	0
	db	18
	db	64
	db	115
	db	116
	db	114
	db	110
	db	77
	db	111
	db	118
	db	36
	db	113
	db	113
	db	115
	db	112
	db	99
	db	112
	db	120
	db	99
	db	108
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	33
	dw	0
	dw	0
	dw	0
	dw	?patch51
	dw	529
	dw	?patch52
	dd	?live16396@16-@@strnMov$qqspcpxcl
	dd	?live16396@48-?live16396@16
	dw	20
?patch52	equ	1
?patch51	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	34
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	35
	dw	0
	dw	0
	dw	0
?patch48	equ	@34-@@strnMov$qqspcpxcl+5
?patch49	equ	0
?patch50	equ	@34-@@strnMov$qqspcpxcl
	dw	2
	dw	6
	dw	8
	dw	531
	dw	1
	dw	65532
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strAdd	segment virtual
	align	2
@strAdd	proc	near
?live16397@0:
	?debug L 98
@35:
	push      ebp
	mov       ebp,esp
	?debug L 100
	mov       eax,dword ptr [ebp+12]
	push      eax
	mov       edx,dword ptr [ebp+8]
	push      edx
	call      @_strcat
	add       esp,8
	?debug L 101
@37:
@36:
	pop       ebp
	ret       8
	?debug L 0
@strAdd	endp
strAdd	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch53
	dd	?patch54
	dd	?patch55
	df	@strAdd
	dw	0
	dw	4122
	dw	0
	dw	36
	dw	0
	dw	0
	dw	0
	db	6
	db	115
	db	116
	db	114
	db	65
	db	100
	db	100
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	37
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	38
	dw	0
	dw	0
	dw	0
?patch53	equ	@37-@strAdd+4
?patch54	equ	0
?patch55	equ	@37-@strAdd
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strInsert	segment virtual
	align	2
@strInsert	proc	near
?live16398@0:
	?debug L 104
@38:
	push      ebp
	mov       ebp,esp
	push      ecx
	push      ebx
	push      esi
	push      edi
	mov       edi,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+8]
	?debug L 106
?live16398@16: ; EBX = alpdst, EDI = astart
	mov       eax,dword ptr [ebp+16]
	push      eax
	call      @_strlen
	pop       ecx
	mov       esi,eax
	push      ebx
	call      @_strlen
	pop       ecx
	mov       dword ptr [ebp-4],eax
	?debug L 107
?live16398@32: ; EBX = alpdst, ESI = insertlen, EDI = astart
	test      esi,esi
	jne       short @39
	?debug L 108
?live16398@48: ; EBX = alpdst
	mov       eax,ebx
	jmp       short @40
	?debug L 109
?live16398@64: ; EBX = alpdst, ESI = insertlen, EDI = astart
@39:
	cmp       edi,dword ptr [ebp-4]
	jge       short @41
	?debug L 110
	mov       edx,dword ptr [ebp-4]
	mov       eax,ebx
	sub       edx,edi
	add       eax,edi
	push      edx
	push      eax
	add       eax,esi
	push      eax
	call      @@strnMov$qqspcpxcl
	?debug L 112
@41:
	push      esi
	mov       edx,dword ptr [ebp+16]
	push      edx
	add       edi,ebx
	push      edi
	call      @@strnMov$qqspcpxcl
	?debug L 113
?live16398@112: ; EBX = alpdst, ESI = insertlen
	mov       ecx,dword ptr [ebp-4]
	lea       eax,dword ptr [ebx+ecx]
	mov       byte ptr [eax+esi],0
	?debug L 114
?live16398@128: ; EBX = alpdst
	mov       eax,ebx
	?debug L 115
?live16398@144: ; 
@42:
@40:
	pop       edi
	pop       esi
	pop       ebx
	pop       ecx
	pop       ebp
	ret       12
	?debug L 0
@strInsert	endp
strInsert	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	56
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch56
	dd	?patch57
	dd	?patch58
	df	@strInsert
	dw	0
	dw	4124
	dw	0
	dw	39
	dw	0
	dw	0
	dw	0
	db	9
	db	115
	db	116
	db	114
	db	73
	db	110
	db	115
	db	101
	db	114
	db	116
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	40
	dw	0
	dw	0
	dw	0
	dw	?patch59
	dw	529
	dw	?patch60
	dd	?live16398@16-@strInsert
	dd	?live16398@144-?live16398@16
	dw	20
?patch60	equ	1
?patch59	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	41
	dw	0
	dw	0
	dw	0
	dw	?patch61
	dw	529
	dw	?patch62
	dd	?live16398@16-@strInsert
	dd	?live16398@48-?live16398@16
	dw	24
	dd	?live16398@64-@strInsert
	dd	?live16398@112-?live16398@64
	dw	24
?patch62	equ	2
?patch61	equ	24
	dw	18
	dw	512
	dw	16
	dw	0
	dw	4099
	dw	0
	dw	42
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	65532
	dw	65535
	dw	18
	dw	0
	dw	43
	dw	0
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	23
	dw	44
	dw	0
	dw	0
	dw	0
	dw	?patch63
	dw	529
	dw	?patch64
	dd	?live16398@32-@strInsert
	dd	?live16398@48-?live16398@32
	dw	23
	dd	?live16398@64-@strInsert
	dd	?live16398@128-?live16398@64
	dw	23
?patch64	equ	2
?patch63	equ	24
?patch56	equ	@42-@strInsert+8
?patch57	equ	0
?patch58	equ	@42-@strInsert
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65520
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strDel	segment virtual
	align	2
@strDel	proc	near
?live16399@0:
	?debug L 118
@43:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	mov       edi,dword ptr [ebp+16]
	mov       esi,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+8]
	?debug L 120
?live16399@16: ; EBX = alpdst, ESI = astart, EDI = alength
	push      ebx
	call      @strLen
	sub       eax,esi
	sub       eax,edi
	push      eax
	mov       eax,ebx
	add       eax,esi
	add       eax,edi
	push      eax
	add       esi,ebx
	push      esi
	call      @@strnEql$qqspcpxcl
	?debug L 121
?live16399@32: ; EBX = alpdst, EDI = alength
	push      ebx
	call      @_strlen
	pop       ecx
	sub       eax,edi
	mov       byte ptr [ebx+eax],0
	?debug L 122
?live16399@48: ; EBX = alpdst
	mov       eax,ebx
	?debug L 123
?live16399@64: ; 
@45:
@44:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
	?debug L 0
@strDel	endp
strDel	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch65
	dd	?patch66
	dd	?patch67
	df	@strDel
	dw	0
	dw	4126
	dw	0
	dw	45
	dw	0
	dw	0
	dw	0
	db	6
	db	115
	db	116
	db	114
	db	68
	db	101
	db	108
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	46
	dw	0
	dw	0
	dw	0
	dw	?patch68
	dw	529
	dw	?patch69
	dd	?live16399@16-@strDel
	dd	?live16399@64-?live16399@16
	dw	20
?patch69	equ	1
?patch68	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	47
	dw	0
	dw	0
	dw	0
	dw	?patch70
	dw	529
	dw	?patch71
	dd	?live16399@16-@strDel
	dd	?live16399@32-?live16399@16
	dw	23
?patch71	equ	1
?patch70	equ	14
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	48
	dw	0
	dw	0
	dw	0
	dw	?patch72
	dw	529
	dw	?patch73
	dd	?live16399@16-@strDel
	dd	?live16399@48-?live16399@16
	dw	24
?patch73	equ	1
?patch72	equ	14
?patch65	equ	@45-@strDel+7
?patch66	equ	0
?patch67	equ	@45-@strDel
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strDelEnd	segment virtual
	align	2
@strDelEnd	proc	near
?live16400@0:
	?debug L 126
@46:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	mov       esi,dword ptr [ebp+16]
	mov       edi,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+8]
	?debug L 128
?live16400@16: ; EBX = alpdst, ESI = aend, EDI = astart
	push      ebx
	call      @strLen
	sub       eax,esi
	mov       edx,ebx
	push      eax
	mov       eax,ebx
	add       eax,esi
	add       edx,edi
	push      eax
	push      edx
	call      @@strnEql$qqspcpxcl
	?debug L 129
	push      ebx
	call      @_strlen
	pop       ecx
	sub       esi,edi
	sub       eax,esi
	mov       byte ptr [ebx+eax],0
	?debug L 130
?live16400@48: ; EBX = alpdst
	mov       eax,ebx
	?debug L 131
?live16400@64: ; 
@48:
@47:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
	?debug L 0
@strDelEnd	endp
strDelEnd	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	56
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch74
	dd	?patch75
	dd	?patch76
	df	@strDelEnd
	dw	0
	dw	4128
	dw	0
	dw	49
	dw	0
	dw	0
	dw	0
	db	9
	db	115
	db	116
	db	114
	db	68
	db	101
	db	108
	db	69
	db	110
	db	100
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	50
	dw	0
	dw	0
	dw	0
	dw	?patch77
	dw	529
	dw	?patch78
	dd	?live16400@16-@strDelEnd
	dd	?live16400@64-?live16400@16
	dw	20
?patch78	equ	1
?patch77	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	51
	dw	0
	dw	0
	dw	0
	dw	?patch79
	dw	529
	dw	?patch80
	dd	?live16400@16-@strDelEnd
	dd	?live16400@48-?live16400@16
	dw	24
?patch80	equ	1
?patch79	equ	14
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	52
	dw	0
	dw	0
	dw	0
	dw	?patch81
	dw	529
	dw	?patch82
	dd	?live16400@16-@strDelEnd
	dd	?live16400@48-?live16400@16
	dw	23
?patch82	equ	1
?patch81	equ	14
?patch74	equ	@48-@strDelEnd+7
?patch75	equ	0
?patch76	equ	@48-@strDelEnd
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strPos	segment virtual
	align	2
@strPos	proc	near
?live16401@0:
	?debug L 134
	push      ebp
	mov       ebp,esp
	add       esp,-8
	push      ebx
	push      esi
	push      edi
	?debug L 136
@49:
	mov       eax,dword ptr [ebp+8]
	push      eax
	call      @strLen
	mov       dword ptr [ebp-4],eax
	mov       edx,dword ptr [ebp+16]
	push      edx
	call      @strLen
	mov       dword ptr [ebp-8],eax
	?debug L 140
	mov	 EDX,dword ptr [ebp-8]
	?debug L 141
	cmp	 EDX,0
	?debug L 142
	jle       @50
	?debug L 144
	mov	 ECX,dword ptr [ebp-4]
	?debug L 145
	cmp	 ECX,0
	?debug L 146
	jle       @50
	?debug L 148
	mov	 EBX,dword ptr [ebp+12]
	?debug L 149
	mov	 EAX,EBX
	?debug L 150
	add	 EAX,EDX
	?debug L 151
	cmp	 ECX,EAX
	?debug L 152
	jl        @50
	?debug L 154
	dec	 EDX
	?debug L 156
@51:
strPosDO:
	?debug L 158
	mov	 ESI,dword ptr [ebp+16]
	?debug L 159
	mov	 EDI,dword ptr [ebp+8]
	?debug L 160
	mov	 AL,[ESI]
	?debug L 161
	cmp	 AL,[EDI+EBX]
	?debug L 162
	jne       short @52
	?debug L 163
	add	 EDI,EBX
	?debug L 164
	mov	 ECX,dword ptr [ebp-8]
	?debug L 165
	cld	
	?debug L 166
	repe CMPSB	
	?debug L 167
	je        @53
	?debug L 169
@52:
strPosNEXT:
	?debug L 171
	inc	 EBX
	?debug L 172
	mov	 EAX,EBX
	?debug L 173
	add	 EAX,EDX
	?debug L 174
	cmp	 EAX,dword ptr [ebp-4]
	?debug L 175
	jl        @51
	?debug L 176
	jmp       @50
	?debug L 178
@53:
strPosFOUND:
	?debug L 179
	mov	 EAX,EBX
	?debug L 180
	jmp       @54
	?debug L 181
@50:
strPosERROR:
	?debug L 182
	mov	 EAX,-1
	?debug L 184
@54:
strPosBREAK:
	?debug L 209
@55:
	pop       edi
	pop       esi
	pop       ebx
	pop       ecx
	pop       ecx
	pop       ebp
	ret       12
	?debug L 0
@strPos	endp
strPos	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch83
	dd	?patch84
	dd	?patch85
	df	@strPos
	dw	0
	dw	4130
	dw	0
	dw	53
	dw	0
	dw	0
	dw	0
	db	6
	db	115
	db	116
	db	114
	db	80
	db	111
	db	115
	dw	18
	dw	512
	dw	8
	dw	0
	dw	4099
	dw	0
	dw	54
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	55
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	4099
	dw	0
	dw	56
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	65528
	dw	65535
	dw	18
	dw	0
	dw	57
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	65532
	dw	65535
	dw	18
	dw	0
	dw	58
	dw	0
	dw	0
	dw	0
?patch83	equ	@55-@strPos+9
?patch84	equ	0
?patch85	equ	@55-@strPos
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65516
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strSub	segment virtual
	align	2
@strSub	proc	near
?live16402@0:
	?debug L 212
@56:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       esi,dword ptr [ebp+20]
	mov       ebx,dword ptr [ebp+8]
	?debug L 214
?live16402@16: ; EBX = alpdst, ESI = alength
	push      esi
	mov       eax,dword ptr [ebp+12]
	add       eax,dword ptr [ebp+16]
	push      eax
	push      ebx
	call      @@strnEql$qqspcpxcl
	?debug L 215
	mov       byte ptr [ebx+esi],0
	?debug L 216
?live16402@48: ; EBX = alpdst
	mov       eax,ebx
	?debug L 217
?live16402@64: ; 
@58:
@57:
	pop       esi
	pop       ebx
	pop       ebp
	ret       16
	?debug L 0
@strSub	endp
strSub	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch86
	dd	?patch87
	dd	?patch88
	df	@strSub
	dw	0
	dw	4132
	dw	0
	dw	59
	dw	0
	dw	0
	dw	0
	db	6
	db	115
	db	116
	db	114
	db	83
	db	117
	db	98
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	60
	dw	0
	dw	0
	dw	0
	dw	?patch89
	dw	529
	dw	?patch90
	dd	?live16402@16-@strSub
	dd	?live16402@64-?live16402@16
	dw	20
?patch90	equ	1
?patch89	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	61
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	62
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	20
	dw	0
	dw	18
	dw	0
	dw	63
	dw	0
	dw	0
	dw	0
	dw	?patch91
	dw	529
	dw	?patch92
	dd	?live16402@16-@strSub
	dd	?live16402@48-?live16402@16
	dw	23
?patch92	equ	1
?patch91	equ	14
?patch86	equ	@58-@strSub+6
?patch87	equ	0
?patch88	equ	@58-@strSub
	dw	2
	dw	6
	dw	8
	dw	531
	dw	5
	dw	65528
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strSubEnd	segment virtual
	align	2
@strSubEnd	proc	near
?live16403@0:
	?debug L 220
@59:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	mov       edi,dword ptr [ebp+20]
	mov       esi,dword ptr [ebp+16]
	mov       ebx,dword ptr [ebp+8]
	?debug L 222
?live16403@16: ; EBX = alpdst, ESI = astart, EDI = aend
	mov       eax,edi
	sub       eax,esi
	push      eax
	mov       edx,dword ptr [ebp+12]
	add       edx,esi
	push      edx
	push      ebx
	call      @@strnEql$qqspcpxcl
	?debug L 223
	sub       edi,esi
	?debug L 224
?live16403@48: ; EBX = alpdst
	mov       eax,ebx
	?debug L 223
?live16403@64: ; EBX = alpdst, ESI = astart, EDI = aend
	mov       byte ptr [ebx+edi],0
	?debug L 225
?live16403@80: ; 
@61:
@60:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       16
	?debug L 0
@strSubEnd	endp
strSubEnd	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	56
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch93
	dd	?patch94
	dd	?patch95
	df	@strSubEnd
	dw	0
	dw	4134
	dw	0
	dw	64
	dw	0
	dw	0
	dw	0
	db	9
	db	115
	db	116
	db	114
	db	83
	db	117
	db	98
	db	69
	db	110
	db	100
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	65
	dw	0
	dw	0
	dw	0
	dw	?patch96
	dw	529
	dw	?patch97
	dd	?live16403@16-@strSubEnd
	dd	?live16403@80-?live16403@16
	dw	20
?patch97	equ	1
?patch96	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	66
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	67
	dw	0
	dw	0
	dw	0
	dw	?patch98
	dw	529
	dw	?patch99
	dd	?live16403@16-@strSubEnd
	dd	?live16403@48-?live16403@16
	dw	23
	dd	?live16403@64-@strSubEnd
	dd	?live16403@80-?live16403@64
	dw	23
?patch99	equ	2
?patch98	equ	24
	dw	18
	dw	512
	dw	20
	dw	0
	dw	18
	dw	0
	dw	68
	dw	0
	dw	0
	dw	0
	dw	?patch100
	dw	529
	dw	?patch101
	dd	?live16403@16-@strSubEnd
	dd	?live16403@48-?live16403@16
	dw	24
	dd	?live16403@64-@strSubEnd
	dd	?live16403@80-?live16403@64
	dw	24
?patch101	equ	2
?patch100	equ	24
?patch93	equ	@61-@strSubEnd+7
?patch94	equ	0
?patch95	equ	@61-@strSubEnd
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strDelimiter	segment virtual
	align	2
@strDelimiter	proc	near
?live16404@0:
	?debug L 228
@62:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	?debug L 230
?live16404@16: ; EBX = adelimiter
	cmp       dword ptr [ebp+16],0
	?debug L 228
?live16404@32: ; 
	mov       ebx,dword ptr [ebp+12]
	?debug L 230
?live16404@48: ; EBX = adelimiter
	jge       short @63
	?debug L 231
@64:
	mov       eax,dword ptr [ebp+8]
	push      eax
	call      @strLen
	dec       eax
	mov       edx,dword ptr [ebp+8]
	add       edx,eax
	test      eax,eax
	jl        short @66
	?debug L 232
?live16404@80: ; EAX = pos, EBX = adelimiter, EDX = @temp5
@65:
	cmp       bl,byte ptr [edx]
	je        short @68
	?debug L 231
?live16404@96: ; EAX = pos
	dec       eax
	dec       edx
	test      eax,eax
	jge       short @65
	?debug L 234
?live16404@112: ; 
@66:
	or        eax,-1
	jmp       short @68
	?debug L 235
@70:
	jmp       short @71
	?debug L 237
?live16404@144: ; EBX = adelimiter
@63:
@72:
	xor       edi,edi
	mov       eax,dword ptr [ebp+8]
	mov       esi,eax
	jmp       short @74
	?debug L 238
?live16404@160: ; EDI = pos, ESI = @temp1, EBX = adelimiter
@73:
	cmp       bl,byte ptr [esi]
	jne       short @75
	?debug L 239
?live16404@176: ; EDI = pos
	mov       eax,edi
	jmp       short @68
	?debug L 237
?live16404@192: ; EDI = pos, ESI = @temp1, EBX = adelimiter
@75:
	inc       edi
	inc       esi
@74:
	mov       edx,dword ptr [ebp+8]
	push      edx
	call      @strLen
	cmp       edi,eax
	jl        short @73
	?debug L 240
?live16404@208: ; 
	or        eax,-1
	?debug L 242
@77:
@71:
@78:
@68:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
	?debug L 0
@strDelimiter	endp
strDelimiter	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	59
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch102
	dd	?patch103
	dd	?patch104
	df	@strDelimiter
	dw	0
	dw	4136
	dw	0
	dw	69
	dw	0
	dw	0
	dw	0
	db	12
	db	115
	db	116
	db	114
	db	68
	db	101
	db	108
	db	105
	db	109
	db	105
	db	116
	db	101
	db	114
	dw	18
	dw	512
	dw	8
	dw	0
	dw	4099
	dw	0
	dw	70
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	112
	dw	0
	dw	71
	dw	0
	dw	0
	dw	0
	dw	?patch105
	dw	529
	dw	?patch106
	dd	?live16404@16-@strDelimiter
	dd	?live16404@32-?live16404@16
	dw	4
	dd	?live16404@48-@strDelimiter
	dd	?live16404@96-?live16404@48
	dw	4
	dd	?live16404@144-@strDelimiter
	dd	?live16404@176-?live16404@144
	dw	4
	dd	?live16404@192-@strDelimiter
	dd	?live16404@208-?live16404@192
	dw	4
?patch106	equ	4
?patch105	equ	44
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	72
	dw	0
	dw	0
	dw	0
	dw	24
	dw	519
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch107
	df	@64
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	17
	dw	73
	dw	0
	dw	0
	dw	0
	dw	?patch108
	dw	529
	dw	?patch109
	dd	?live16404@80-@strDelimiter
	dd	?live16404@112-?live16404@80
	dw	17
?patch109	equ	1
?patch108	equ	14
?patch107	equ	@70-@64
	dw	2
	dw	6
	dw	24
	dw	519
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch110
	df	@72
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	24
	dw	74
	dw	0
	dw	0
	dw	0
	dw	?patch111
	dw	529
	dw	?patch112
	dd	?live16404@160-@strDelimiter
	dd	?live16404@208-?live16404@160
	dw	24
?patch112	equ	1
?patch111	equ	14
?patch110	equ	@77-@72
	dw	2
	dw	6
?patch102	equ	@78-@strDelimiter+7
?patch103	equ	0
?patch104	equ	@78-@strDelimiter
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strExchange	segment virtual
	align	2
@strExchange	proc	near
?live16405@0:
	?debug L 245
@79:
	push      ebp
	mov       ebp,esp
	add       esp,-12
	push      ebx
	push      esi
	push      edi
	?debug L 247
?live16405@16: ; ESI = alpdst
	xor       edi,edi
	?debug L 245
?live16405@32: ; 
	mov       esi,dword ptr [ebp+8]
	?debug L 247
?live16405@48: ; ESI = alpdst
	mov       eax,dword ptr [ebp+12]
	push      eax
	call      @strLen
	mov       dword ptr [ebp-4],eax
	mov       edx,dword ptr [ebp+16]
	push      edx
	call      @strLen
	mov       dword ptr [ebp-8],eax
	push      esi
	call      @strLen
	mov       dword ptr [ebp-12],eax
	cmp       edi,dword ptr [ebp-12]
	jge       short @81
	?debug L 249
?live16405@64: ; ESI = alpdst, EDI = pos
@80:
	mov       ecx,dword ptr [ebp+12]
	push      ecx
	push      edi
	push      esi
	call      @strPos
	mov       ebx,eax
	inc       eax
	je        short @83
	?debug L 251
?live16405@80: ; ESI = alpdst
	mov       edx,dword ptr [ebp-4]
	push      edx
	push      ebx
	push      esi
	call      @strDel
	?debug L 252
?live16405@96: ; EBX = find, ESI = alpdst
	mov       ecx,dword ptr [ebp+16]
	push      ecx
	push      ebx
	push      esi
	call      @strInsert
	?debug L 247
	mov       edi,dword ptr [ebp-8]
	add       edi,ebx
	cmp       edi,dword ptr [ebp-12]
	jl        short @80
	?debug L 254
?live16405@128: ; ESI = alpdst
@81:
@83:
	mov       eax,esi
	?debug L 255
?live16405@144: ; 
@86:
@85:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       12
	?debug L 0
@strExchange	endp
strExchange	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	58
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch113
	dd	?patch114
	dd	?patch115
	df	@strExchange
	dw	0
	dw	4138
	dw	0
	dw	75
	dw	0
	dw	0
	dw	0
	db	11
	db	115
	db	116
	db	114
	db	69
	db	120
	db	99
	db	104
	db	97
	db	110
	db	103
	db	101
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	76
	dw	0
	dw	0
	dw	0
	dw	?patch116
	dw	529
	dw	?patch117
	dd	?live16405@16-@strExchange
	dd	?live16405@32-?live16405@16
	dw	23
	dd	?live16405@48-@strExchange
	dd	?live16405@144-?live16405@48
	dw	23
?patch117	equ	2
?patch116	equ	24
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	77
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	4099
	dw	0
	dw	78
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	65524
	dw	65535
	dw	18
	dw	0
	dw	79
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	65528
	dw	65535
	dw	18
	dw	0
	dw	80
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	65532
	dw	65535
	dw	18
	dw	0
	dw	81
	dw	0
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	20
	dw	82
	dw	0
	dw	0
	dw	0
	dw	?patch118
	dw	529
	dw	?patch119
	dd	?live16405@96-@strExchange
	dd	?live16405@128-?live16405@96
	dw	20
?patch119	equ	1
?patch118	equ	14
	dw	16
	dw	2
	dw	18
	dw	0
	dw	24
	dw	83
	dw	0
	dw	0
	dw	0
	dw	?patch120
	dw	529
	dw	?patch121
	dd	?live16405@64-@strExchange
	dd	?live16405@80-?live16405@64
	dw	24
?patch121	equ	1
?patch120	equ	14
?patch113	equ	@86-@strExchange+9
?patch114	equ	0
?patch115	equ	@86-@strExchange
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65512
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strExchangeChar	segment virtual
	align	2
@strExchangeChar	proc	near
?live16406@0:
	?debug L 258
@87:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	?debug L 260
?live16406@16: ; EBX = alpfnd, EDI = alpdst
	xor       esi,esi
	?debug L 258
?live16406@32: ; 
	mov       edi,dword ptr [ebp+8]
	mov       ebx,dword ptr [ebp+12]
	?debug L 260
?live16406@48: ; EBX = alpfnd, EDI = alpdst
	push      edi
	call      @_strlen
	pop       ecx
	mov       edx,eax
	mov       eax,edi
	cmp       edx,esi
	jle       short @89
	?debug L 262
?live16406@64: ; EAX = @temp0, ESI = pos, EDX = lencel, EBX = alpfnd, EDI = alpdst
	;	
@88:
	cmp       bl,byte ptr [eax]
	jne       short @90
	mov       cl,byte ptr [ebp+16]
	mov       byte ptr [eax],cl
	?debug L 260
@90:
	inc       esi
	inc       eax
	cmp       edx,esi
	jg        short @88
	?debug L 264
?live16406@96: ; EDI = alpdst
@89:
	mov       eax,edi
	?debug L 265
?live16406@112: ; 
@93:
@92:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
	?debug L 0
@strExchangeChar	endp
strExchangeChar	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	62
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch122
	dd	?patch123
	dd	?patch124
	df	@strExchangeChar
	dw	0
	dw	4140
	dw	0
	dw	84
	dw	0
	dw	0
	dw	0
	db	15
	db	115
	db	116
	db	114
	db	69
	db	120
	db	99
	db	104
	db	97
	db	110
	db	103
	db	101
	db	67
	db	104
	db	97
	db	114
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	85
	dw	0
	dw	0
	dw	0
	dw	?patch125
	dw	529
	dw	?patch126
	dd	?live16406@16-@strExchangeChar
	dd	?live16406@32-?live16406@16
	dw	24
	dd	?live16406@48-@strExchangeChar
	dd	?live16406@112-?live16406@48
	dw	24
?patch126	equ	2
?patch125	equ	24
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4100
	dw	0
	dw	86
	dw	0
	dw	0
	dw	0
	dw	?patch127
	dw	529
	dw	?patch128
	dd	?live16406@16-@strExchangeChar
	dd	?live16406@32-?live16406@16
	dw	4
	dd	?live16406@48-@strExchangeChar
	dd	?live16406@96-?live16406@48
	dw	4
?patch128	equ	2
?patch127	equ	24
	dw	18
	dw	512
	dw	16
	dw	0
	dw	4100
	dw	0
	dw	87
	dw	0
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	19
	dw	88
	dw	0
	dw	0
	dw	0
	dw	?patch129
	dw	529
	dw	?patch130
	dd	?live16406@64-@strExchangeChar
	dd	?live16406@96-?live16406@64
	dw	19
?patch130	equ	1
?patch129	equ	14
	dw	16
	dw	2
	dw	18
	dw	0
	dw	23
	dw	89
	dw	0
	dw	0
	dw	0
	dw	?patch131
	dw	529
	dw	?patch132
	dd	?live16406@64-@strExchangeChar
	dd	?live16406@96-?live16406@64
	dw	23
?patch132	equ	1
?patch131	equ	14
?patch122	equ	@93-@strExchangeChar+7
?patch123	equ	0
?patch124	equ	@93-@strExchangeChar
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strExtractFileRoot	segment virtual
	align	2
@strExtractFileRoot	proc	near
?live16407@0:
	?debug L 268
@94:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       ebx,dword ptr [ebp+12]
	mov       esi,dword ptr [ebp+8]
	?debug L 270
?live16407@16: ; EBX = alpsrc, ESI = alpdst
	push      1
	push      92
	push      ebx
	call      @strDelimiter
	?debug L 272
?live16407@32: ; EBX = alpsrc, ESI = alpdst, EAX = delimiter
	test      eax,eax
	jl        short @95
	?debug L 273
	push      eax
	push      0
	push      ebx
	push      esi
	call      @strSubEnd
	jmp       short @96
	?debug L 276
?live16407@64: ; EBX = alpsrc, ESI = alpdst
@95:
	cmp       esi,ebx
	je        short @97
	?debug L 277
	push      ebx
	call      @_strlen
	pop       ecx
	inc       eax
	push      eax
	push      ebx
	push      esi
	call      @@strnEql$qqspcpxcl
	jmp       short @96
	?debug L 280
@97:
	push      ebx
	call      @strLen
	mov       byte ptr [esi+eax],0
	?debug L 281
?live16407@112: ; ESI = alpdst
	mov       eax,esi
	?debug L 283
?live16407@128: ; 
@99:
@96:
	pop       esi
	pop       ebx
	pop       ebp
	ret       8
	?debug L 0
@strExtractFileRoot	endp
strExtractFileRoot	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	65
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch133
	dd	?patch134
	dd	?patch135
	df	@strExtractFileRoot
	dw	0
	dw	4142
	dw	0
	dw	90
	dw	0
	dw	0
	dw	0
	db	18
	db	115
	db	116
	db	114
	db	69
	db	120
	db	116
	db	114
	db	97
	db	99
	db	116
	db	70
	db	105
	db	108
	db	101
	db	82
	db	111
	db	111
	db	116
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	91
	dw	0
	dw	0
	dw	0
	dw	?patch136
	dw	529
	dw	?patch137
	dd	?live16407@16-@strExtractFileRoot
	dd	?live16407@128-?live16407@16
	dw	23
?patch137	equ	1
?patch136	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	92
	dw	0
	dw	0
	dw	0
	dw	?patch138
	dw	529
	dw	?patch139
	dd	?live16407@16-@strExtractFileRoot
	dd	?live16407@112-?live16407@16
	dw	20
?patch139	equ	1
?patch138	equ	14
	dw	16
	dw	2
	dw	116
	dw	0
	dw	17
	dw	93
	dw	0
	dw	0
	dw	0
	dw	?patch140
	dw	529
	dw	?patch141
	dd	?live16407@32-@strExtractFileRoot
	dd	?live16407@64-?live16407@32
	dw	17
?patch141	equ	1
?patch140	equ	14
?patch133	equ	@99-@strExtractFileRoot+6
?patch134	equ	0
?patch135	equ	@99-@strExtractFileRoot
	dw	2
	dw	6
	dw	8
	dw	531
	dw	5
	dw	65528
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strExtractFilePath	segment virtual
	align	2
@strExtractFilePath	proc	near
?live16408@0:
	?debug L 286
@100:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       ebx,dword ptr [ebp+12]
	mov       esi,dword ptr [ebp+8]
	?debug L 288
?live16408@16: ; EBX = alpsrc, ESI = alpdst
	push      -1
	push      92
	push      ebx
	call      @strDelimiter
	?debug L 290
?live16408@32: ; EBX = alpsrc, ESI = alpdst, EAX = delimiter
	test      eax,eax
	jl        short @101
	?debug L 291
	push      eax
	push      0
	push      ebx
	push      esi
	call      @strSubEnd
	jmp       short @102
	?debug L 294
?live16408@64: ; EBX = alpsrc, ESI = alpdst
@101:
	cmp       esi,ebx
	je        short @103
	?debug L 295
	push      ebx
	call      @_strlen
	pop       ecx
	inc       eax
	push      eax
	push      ebx
	push      esi
	call      @@strnEql$qqspcpxcl
	jmp       short @102
	?debug L 298
@103:
	push      ebx
	call      @strLen
	mov       byte ptr [esi+eax],0
	?debug L 299
?live16408@112: ; ESI = alpdst
	mov       eax,esi
	?debug L 301
?live16408@128: ; 
@105:
@102:
	pop       esi
	pop       ebx
	pop       ebp
	ret       8
	?debug L 0
@strExtractFilePath	endp
strExtractFilePath	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	65
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch142
	dd	?patch143
	dd	?patch144
	df	@strExtractFilePath
	dw	0
	dw	4144
	dw	0
	dw	94
	dw	0
	dw	0
	dw	0
	db	18
	db	115
	db	116
	db	114
	db	69
	db	120
	db	116
	db	114
	db	97
	db	99
	db	116
	db	70
	db	105
	db	108
	db	101
	db	80
	db	97
	db	116
	db	104
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	95
	dw	0
	dw	0
	dw	0
	dw	?patch145
	dw	529
	dw	?patch146
	dd	?live16408@16-@strExtractFilePath
	dd	?live16408@128-?live16408@16
	dw	23
?patch146	equ	1
?patch145	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	96
	dw	0
	dw	0
	dw	0
	dw	?patch147
	dw	529
	dw	?patch148
	dd	?live16408@16-@strExtractFilePath
	dd	?live16408@112-?live16408@16
	dw	20
?patch148	equ	1
?patch147	equ	14
	dw	16
	dw	2
	dw	116
	dw	0
	dw	17
	dw	97
	dw	0
	dw	0
	dw	0
	dw	?patch149
	dw	529
	dw	?patch150
	dd	?live16408@32-@strExtractFilePath
	dd	?live16408@64-?live16408@32
	dw	17
?patch150	equ	1
?patch149	equ	14
?patch142	equ	@105-@strExtractFilePath+6
?patch143	equ	0
?patch144	equ	@105-@strExtractFilePath
	dw	2
	dw	6
	dw	8
	dw	531
	dw	5
	dw	65528
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strExtractFileName	segment virtual
	align	2
@strExtractFileName	proc	near
?live16409@0:
	?debug L 304
@106:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+12]
	mov       esi,dword ptr [ebp+8]
	?debug L 306
?live16409@16: ; EBX = alpsrc, ESI = alpdst
	push      -1
	push      92
	push      ebx
	call      @strDelimiter
	mov       edi,eax
	?debug L 308
?live16409@32: ; EBX = alpsrc, ESI = alpdst, EDI = delimiter
	test      edi,edi
	jl        short @107
	?debug L 309
	push      ebx
	call      @_strlen
	pop       ecx
	push      eax
	inc       edi
	push      edi
	push      ebx
	push      esi
	call      @strSubEnd
	jmp       short @108
	?debug L 312
?live16409@64: ; EBX = alpsrc, ESI = alpdst
@107:
	cmp       esi,ebx
	je        short @109
	?debug L 313
	push      ebx
	call      @_strlen
	pop       ecx
	inc       eax
	push      eax
	push      ebx
	push      esi
	call      @@strnEql$qqspcpxcl
	jmp       short @108
	?debug L 316
@109:
	push      ebx
	call      @strLen
	mov       byte ptr [esi+eax],0
	?debug L 317
?live16409@112: ; ESI = alpdst
	mov       eax,esi
	?debug L 319
?live16409@128: ; 
@111:
@108:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       8
	?debug L 0
@strExtractFileName	endp
strExtractFileName	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	65
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch151
	dd	?patch152
	dd	?patch153
	df	@strExtractFileName
	dw	0
	dw	4146
	dw	0
	dw	98
	dw	0
	dw	0
	dw	0
	db	18
	db	115
	db	116
	db	114
	db	69
	db	120
	db	116
	db	114
	db	97
	db	99
	db	116
	db	70
	db	105
	db	108
	db	101
	db	78
	db	97
	db	109
	db	101
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	99
	dw	0
	dw	0
	dw	0
	dw	?patch154
	dw	529
	dw	?patch155
	dd	?live16409@16-@strExtractFileName
	dd	?live16409@128-?live16409@16
	dw	23
?patch155	equ	1
?patch154	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	100
	dw	0
	dw	0
	dw	0
	dw	?patch156
	dw	529
	dw	?patch157
	dd	?live16409@16-@strExtractFileName
	dd	?live16409@112-?live16409@16
	dw	20
?patch157	equ	1
?patch156	equ	14
	dw	16
	dw	2
	dw	18
	dw	0
	dw	24
	dw	101
	dw	0
	dw	0
	dw	0
	dw	?patch158
	dw	529
	dw	?patch159
	dd	?live16409@32-@strExtractFileName
	dd	?live16409@64-?live16409@32
	dw	24
?patch159	equ	1
?patch158	equ	14
?patch151	equ	@111-@strExtractFileName+7
?patch152	equ	0
?patch153	equ	@111-@strExtractFileName
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strFixFilePath	segment virtual
	align	2
@strFixFilePath	proc	near
?live16410@0:
	?debug L 322
@112:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	mov       edi,dword ptr [ebp+12]
	mov       ebx,dword ptr [ebp+8]
	?debug L 324
?live16410@16: ; EBX = alpdst, EDI = alpsrc
	push      edi
	call      @_strlen
	pop       ecx
	mov       esi,eax
	?debug L 326
?live16410@32: ; EBX = alpdst, ESI = lensrc, EDI = alpsrc
	test      esi,esi
	jne       short @113
	?debug L 327
?live16410@48: ; EBX = alpdst
	mov       byte ptr [ebx],0
	?debug L 328
	mov       eax,ebx
	jmp       short @114
	?debug L 331
?live16410@80: ; EBX = alpdst, ESI = lensrc, EDI = alpsrc
@113:
	movsx     edx,byte ptr [edi+esi-1]
	cmp       edx,92
	jne       short @115
	?debug L 332
	cmp       ebx,edi
	je        short @116
	?debug L 333
	lea       ecx,dword ptr [esi-1]
	push      ecx
	push      edi
	push      ebx
	call      @@strnEql$qqspcpxcl
	?debug L 334
?live16410@128: ; EBX = alpdst, ESI = lensrc
@116:
	mov       byte ptr [ebx+esi-1],0
	?debug L 335
?live16410@144: ; EBX = alpdst
	mov       eax,ebx
	jmp       short @114
	?debug L 338
?live16410@160: ; EBX = alpdst, ESI = lensrc, EDI = alpsrc
@115:
	cmp       ebx,edi
	je        short @117
	?debug L 339
	push      esi
	push      edi
	push      ebx
	call      @@strnEql$qqspcpxcl
	?debug L 340
?live16410@192: ; EBX = alpdst, ESI = lensrc
@117:
	mov       byte ptr [ebx+esi],0
	?debug L 341
?live16410@208: ; EBX = alpdst
	mov       eax,ebx
	?debug L 343
?live16410@224: ; 
@119:
@114:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       8
	?debug L 0
@strFixFilePath	endp
strFixFilePath	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	61
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch160
	dd	?patch161
	dd	?patch162
	df	@strFixFilePath
	dw	0
	dw	4148
	dw	0
	dw	102
	dw	0
	dw	0
	dw	0
	db	14
	db	115
	db	116
	db	114
	db	70
	db	105
	db	120
	db	70
	db	105
	db	108
	db	101
	db	80
	db	97
	db	116
	db	104
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1136
	dw	0
	dw	103
	dw	0
	dw	0
	dw	0
	dw	?patch163
	dw	529
	dw	?patch164
	dd	?live16410@16-@strFixFilePath
	dd	?live16410@224-?live16410@16
	dw	20
?patch164	equ	1
?patch163	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4099
	dw	0
	dw	104
	dw	0
	dw	0
	dw	0
	dw	?patch165
	dw	529
	dw	?patch166
	dd	?live16410@16-@strFixFilePath
	dd	?live16410@48-?live16410@16
	dw	24
	dd	?live16410@80-@strFixFilePath
	dd	?live16410@128-?live16410@80
	dw	24
	dd	?live16410@160-@strFixFilePath
	dd	?live16410@192-?live16410@160
	dw	24
?patch166	equ	3
?patch165	equ	34
	dw	16
	dw	2
	dw	18
	dw	0
	dw	23
	dw	105
	dw	0
	dw	0
	dw	0
	dw	?patch167
	dw	529
	dw	?patch168
	dd	?live16410@32-@strFixFilePath
	dd	?live16410@48-?live16410@32
	dw	23
	dd	?live16410@80-@strFixFilePath
	dd	?live16410@144-?live16410@80
	dw	23
	dd	?live16410@160-@strFixFilePath
	dd	?live16410@208-?live16410@160
	dw	23
?patch168	equ	3
?patch167	equ	34
?patch160	equ	@119-@strFixFilePath+7
?patch161	equ	0
?patch162	equ	@119-@strFixFilePath
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_BSS	segment dword public use32 'BSS'
$ipjgdfia	label	byte
	db	32	dup(?)
_BSS	ends
_TEXT	segment dword public use32 'CODE'
intToStr	segment virtual
	align	2
@intToStr	proc	near
?live16411@0:
	?debug L 347
@120:
	push      ebp
	mov       ebp,esp
	?debug L 350
	push      10
	push      offset $ipjgdfia
	mov       eax,dword ptr [ebp+8]
	push      eax
	call      @_itoa
	add       esp,12
	?debug L 351
@122:
@121:
	pop       ebp
	ret       4
	?debug L 0
@intToStr	endp
intToStr	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	55
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch169
	dd	?patch170
	dd	?patch171
	df	@intToStr
	dw	0
	dw	4150
	dw	0
	dw	106
	dw	0
	dw	0
	dw	0
	db	8
	db	105
	db	110
	db	116
	db	84
	db	111
	db	83
	db	116
	db	114
	dw	18
	dw	512
	dw	8
	dw	0
	dw	18
	dw	0
	dw	107
	dw	0
	dw	0
	dw	0
	dw	22
	dw	513
	df	$ipjgdfia
	dw	0
	dw	4152
	dw	0
	dw	108
	dw	0
	dw	0
	dw	0
?patch169	equ	@122-@intToStr+4
?patch170	equ	0
?patch171	equ	@122-@intToStr
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
strToInt	segment virtual
	align	2
@strToInt	proc	near
?live16412@0:
	?debug L 354
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	?debug L 359
@123:
	xor	 EAX,EAX
	?debug L 360
	xor	 EBX,EBX
	?debug L 361
	xor	 ESI,ESI
	?debug L 362
	mov	 EDI,alpsrc
	?debug L 364
	mov	 AL,' '
	?debug L 365
	repe SCASB	
	?debug L 366
	je        @124
	?debug L 367
	dec	 EDI
	?debug L 369
strToIntPLUS:
	?debug L 370
	mov	 AL,'+'
	?debug L 371
	cmp	 AL,[EDI]
	?debug L 372
	jne       short @125
	?debug L 373
	inc	 EDI
	?debug L 374
@125:
strToIntSIGN:
	?debug L 375
	mov	 AL,'-'
	?debug L 376
	cmp	 AL,[EDI]
	?debug L 377
	jne       short @126
	?debug L 378
	inc	 EDI
	?debug L 379
	not	 ESI
	?debug L 381
@126:
strToIntLOOP:
	?debug L 382
	mov	 AL,[EDI]
	?debug L 383
	cmp	 AL,'0'
	?debug L 384
	jl        @124
	?debug L 385
	cmp	 AL,'9'
	?debug L 386
	ja        @124
	?debug L 387
	sub	 AL,'0'
	?debug L 389
	push	 EAX
	?debug L 390
	mov	 EAX,10
	?debug L 391
	mul	 EBX
	?debug L 392
	mov	 EBX,EAX
	?debug L 393
	pop	 EAX
	?debug L 394
	add	 EBX,EAX
	?debug L 395
	inc	 EDI
	?debug L 396
	jmp       @126
	?debug L 398
@124:
strToIntX:
	?debug L 399
	test	 ESI,ESI
	?debug L 400
	je        short @127
	?debug L 401
	neg	 EBX
	?debug L 402
@127:
strToIntRET:
	?debug L 403
	mov	 EAX,EBX
	?debug L 408
@128:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       4
	?debug L 0
@strToInt	endp
strToInt	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	55
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch172
	dd	?patch173
	dd	?patch174
	df	@strToInt
	dw	0
	dw	4153
	dw	0
	dw	109
	dw	0
	dw	0
	dw	0
	db	8
	db	115
	db	116
	db	114
	db	84
	db	111
	db	73
	db	110
	db	116
	dw	18
	dw	512
	dw	8
	dw	0
	dw	4099
	dw	0
	dw	110
	dw	0
	dw	0
	dw	0
?patch172	equ	@128-@strToInt+7
?patch173	equ	0
?patch174	equ	@128-@strToInt
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrAlloc	segment virtual
	align	2
@ptrAlloc	proc	near
?live16413@0:
	?debug L 411
@129:
	push      ebp
	mov       ebp,esp
	?debug L 413
	mov       eax,dword ptr [ebp+8]
	push      eax
	push      64
	call      @LocalAlloc
	?debug L 414
@131:
@130:
	pop       ebp
	ret       4
	?debug L 0
@ptrAlloc	endp
ptrAlloc	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	55
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch175
	dd	?patch176
	dd	?patch177
	df	@ptrAlloc
	dw	0
	dw	4155
	dw	0
	dw	111
	dw	0
	dw	0
	dw	0
	db	8
	db	112
	db	116
	db	114
	db	65
	db	108
	db	108
	db	111
	db	99
	dw	18
	dw	512
	dw	8
	dw	0
	dw	18
	dw	0
	dw	112
	dw	0
	dw	0
	dw	0
?patch175	equ	@131-@ptrAlloc+4
?patch176	equ	0
?patch177	equ	@131-@ptrAlloc
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrReAlloc	segment virtual
	align	2
@ptrReAlloc	proc	near
?live16414@0:
	?debug L 417
@132:
	push      ebp
	mov       ebp,esp
	?debug L 419
	push      2
	mov       eax,dword ptr [ebp+12]
	push      eax
	mov       edx,dword ptr [ebp+8]
	push      edx
	call      @LocalReAlloc
	?debug L 420
@134:
@133:
	pop       ebp
	ret       8
	?debug L 0
@ptrReAlloc	endp
ptrReAlloc	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	57
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch178
	dd	?patch179
	dd	?patch180
	df	@ptrReAlloc
	dw	0
	dw	4157
	dw	0
	dw	113
	dw	0
	dw	0
	dw	0
	db	10
	db	112
	db	116
	db	114
	db	82
	db	101
	db	65
	db	108
	db	108
	db	111
	db	99
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	114
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	115
	dw	0
	dw	0
	dw	0
?patch178	equ	@134-@ptrReAlloc+4
?patch179	equ	0
?patch180	equ	@134-@ptrReAlloc
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrFree	segment virtual
	align	2
@ptrFree	proc	near
?live16415@0:
	?debug L 423
@135:
	push      ebp
	mov       ebp,esp
	?debug L 425
	mov       eax,dword ptr [ebp+8]
	push      eax
	call      @LocalFree
	?debug L 426
@136:
	pop       ebp
	ret       4
	?debug L 0
@ptrFree	endp
ptrFree	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	54
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch181
	dd	?patch182
	dd	?patch183
	df	@ptrFree
	dw	0
	dw	4159
	dw	0
	dw	116
	dw	0
	dw	0
	dw	0
	db	7
	db	112
	db	116
	db	114
	db	70
	db	114
	db	101
	db	101
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	117
	dw	0
	dw	0
	dw	0
?patch181	equ	@136-@ptrFree+4
?patch182	equ	0
?patch183	equ	@136-@ptrFree
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrEql	segment virtual
	align	2
@ptrEql	proc	near
?live16416@0:
	?debug L 429
@137:
	push      ebp
	mov       ebp,esp
	?debug L 444
	mov       eax,dword ptr [ebp+16]
	push      eax
	mov       edx,dword ptr [ebp+12]
	push      edx
	mov       ecx,dword ptr [ebp+8]
	push      ecx
	call      @_memmove
	add       esp,12
	?debug L 446
@138:
	pop       ebp
	ret       12
	?debug L 0
@ptrEql	endp
ptrEql	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch184
	dd	?patch185
	dd	?patch186
	df	@ptrEql
	dw	0
	dw	4161
	dw	0
	dw	118
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	69
	db	113
	db	108
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	119
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4162
	dw	0
	dw	120
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	121
	dw	0
	dw	0
	dw	0
?patch184	equ	@138-@ptrEql+4
?patch185	equ	0
?patch186	equ	@138-@ptrEql
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrRev	segment virtual
	align	2
@ptrRev	proc	near
?live16417@0:
	?debug L 449
@139:
	push      ebp
	mov       ebp,esp
	push      ecx
	push      ebx
	push      esi
	mov       ebx,dword ptr [ebp+16]
	?debug L 469
?live16417@16: ; EBX = acount
	mov       eax,dword ptr [ebp+12]
	?debug L 470
?live16417@32: ; EAX = r_src_start, EBX = acount
	lea       edx,dword ptr [ebx+eax-1]
	?debug L 471
?live16417@48: ; EAX = r_src_start, EDX = r_src_end, EBX = acount
	mov       ecx,dword ptr [ebp+8]
	?debug L 472
?live16417@64: ; EAX = r_src_start, EDX = r_src_end, ECX = r_dst_start, EBX = acount
	;	
	lea       esi,dword ptr [ebx+ecx-1]
	?debug L 475
?live16417@80: ; EAX = r_src_start, EDX = r_src_end, ECX = r_dst_start, ESI = r_dst_end
	;	
	cmp       edx,eax
	jbe       short @141
	?debug L 476
@140:
	mov       bl,byte ptr [eax]
	?debug L 475
	inc       eax
	?debug L 476
	mov       byte ptr [ebp-1],bl
	?debug L 477
	mov       bl,byte ptr [edx]
	?debug L 475
	dec       edx
	?debug L 477
	mov       byte ptr [ecx],bl
	?debug L 475
	inc       ecx
	?debug L 478
	mov       bl,byte ptr [ebp-1]
	mov       byte ptr [esi],bl
	?debug L 475
	dec       esi
	cmp       edx,eax
	ja        short @140
	?debug L 481
?live16417@240: ; 
@141:
@143:
	pop       esi
	pop       ebx
	pop       ecx
	pop       ebp
	ret       12
	?debug L 0
@ptrRev	endp
ptrRev	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch187
	dd	?patch188
	dd	?patch189
	df	@ptrRev
	dw	0
	dw	4165
	dw	0
	dw	122
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	82
	db	101
	db	118
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	123
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4162
	dw	0
	dw	124
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	125
	dw	0
	dw	0
	dw	0
	dw	?patch190
	dw	529
	dw	?patch191
	dd	?live16417@16-@ptrRev
	dd	?live16417@80-?live16417@16
	dw	20
?patch191	equ	1
?patch190	equ	14
	dw	18
	dw	512
	dw	65535
	dw	65535
	dw	112
	dw	0
	dw	126
	dw	0
	dw	0
	dw	0
	dw	16
	dw	2
	dw	1136
	dw	0
	dw	23
	dw	127
	dw	0
	dw	0
	dw	0
	dw	?patch192
	dw	529
	dw	?patch193
	dd	?live16417@80-@ptrRev
	dd	?live16417@240-?live16417@80
	dw	23
?patch193	equ	1
?patch192	equ	14
	dw	16
	dw	2
	dw	1136
	dw	0
	dw	18
	dw	128
	dw	0
	dw	0
	dw	0
	dw	?patch194
	dw	529
	dw	?patch195
	dd	?live16417@64-@ptrRev
	dd	?live16417@240-?live16417@64
	dw	18
?patch195	equ	1
?patch194	equ	14
	dw	16
	dw	2
	dw	1136
	dw	0
	dw	19
	dw	129
	dw	0
	dw	0
	dw	0
	dw	?patch196
	dw	529
	dw	?patch197
	dd	?live16417@48-@ptrRev
	dd	?live16417@240-?live16417@48
	dw	19
?patch197	equ	1
?patch196	equ	14
	dw	16
	dw	2
	dw	1136
	dw	0
	dw	17
	dw	130
	dw	0
	dw	0
	dw	0
	dw	?patch198
	dw	529
	dw	?patch199
	dd	?live16417@32-@ptrRev
	dd	?live16417@240-?live16417@32
	dw	17
?patch199	equ	1
?patch198	equ	14
?patch187	equ	@143-@ptrRev+7
?patch188	equ	0
?patch189	equ	@143-@ptrRev
	dw	2
	dw	6
	dw	8
	dw	531
	dw	5
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrMov	segment virtual
	align	2
@ptrMov	proc	near
?live16418@0:
	?debug L 484
@144:
	push      ebp
	mov       ebp,esp
	?debug L 520
	mov       eax,dword ptr [ebp+16]
	push      eax
	mov       edx,dword ptr [ebp+12]
	push      edx
	mov       ecx,dword ptr [ebp+8]
	push      ecx
	call      @_memmove
	add       esp,12
	?debug L 522
@145:
	pop       ebp
	ret       12
	?debug L 0
@ptrMov	endp
ptrMov	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch200
	dd	?patch201
	dd	?patch202
	df	@ptrMov
	dw	0
	dw	4167
	dw	0
	dw	131
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	77
	db	111
	db	118
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	132
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4162
	dw	0
	dw	133
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	134
	dw	0
	dw	0
	dw	0
?patch200	equ	@145-@ptrMov+4
?patch201	equ	0
?patch202	equ	@145-@ptrMov
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrSet	segment virtual
	align	2
@ptrSet	proc	near
?live16419@0:
	?debug L 525
@146:
	push      ebp
	mov       ebp,esp
	?debug L 535
@147:
	pop       ebp
	ret       12
	?debug L 0
@ptrSet	endp
ptrSet	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch203
	dd	?patch204
	dd	?patch205
	df	@ptrSet
	dw	0
	dw	4169
	dw	0
	dw	135
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	83
	db	101
	db	116
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	136
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	112
	dw	0
	dw	137
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	138
	dw	0
	dw	0
	dw	0
?patch203	equ	@147-@ptrSet+4
?patch204	equ	0
?patch205	equ	@147-@ptrSet
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrSetEx	segment virtual
	align	2
@ptrSetEx	proc	near
?live16420@0:
	?debug L 538
@148:
	push      ebp
	mov       ebp,esp
	?debug L 625
@149:
	pop       ebp
	ret       16
	?debug L 0
@ptrSetEx	endp
ptrSetEx	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	55
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch206
	dd	?patch207
	dd	?patch208
	df	@ptrSetEx
	dw	0
	dw	4171
	dw	0
	dw	139
	dw	0
	dw	0
	dw	0
	db	8
	db	112
	db	116
	db	114
	db	83
	db	101
	db	116
	db	69
	db	120
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	140
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4162
	dw	0
	dw	141
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	32
	dw	0
	dw	142
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	20
	dw	0
	dw	18
	dw	0
	dw	143
	dw	0
	dw	0
	dw	0
?patch206	equ	@149-@ptrSetEx+4
?patch207	equ	0
?patch208	equ	@149-@ptrSetEx
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrShl	segment virtual
	align	2
@ptrShl	proc	near
?live16421@0:
	?debug L 628
@150:
	push      ebp
	mov       ebp,esp
	mov       eax,dword ptr [ebp+8]
	?debug L 644
?live16421@16: ; EAX = alpdst
	mov       edx,dword ptr [ebp+12]
	push      edx
	mov       ecx,eax
	dec       ecx
	push      ecx
	push      eax
	call      @_memmove
	add       esp,12
	?debug L 646
?live16421@32: ; 
@151:
	pop       ebp
	ret       8
	?debug L 0
@ptrShl	endp
ptrShl	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch209
	dd	?patch210
	dd	?patch211
	df	@ptrShl
	dw	0
	dw	4173
	dw	0
	dw	144
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	83
	db	104
	db	108
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	145
	dw	0
	dw	0
	dw	0
	dw	?patch212
	dw	529
	dw	?patch213
	dd	?live16421@16-@ptrShl
	dd	?live16421@32-?live16421@16
	dw	17
?patch213	equ	1
?patch212	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	146
	dw	0
	dw	0
	dw	0
?patch209	equ	@151-@ptrShl+4
?patch210	equ	0
?patch211	equ	@151-@ptrShl
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrShr	segment virtual
	align	2
@ptrShr	proc	near
?live16422@0:
	?debug L 649
@152:
	push      ebp
	mov       ebp,esp
	mov       eax,dword ptr [ebp+8]
	?debug L 670
?live16422@16: ; EAX = alpdst
	mov       edx,dword ptr [ebp+12]
	push      edx
	mov       ecx,eax
	inc       ecx
	push      ecx
	push      eax
	call      @_memmove
	add       esp,12
	?debug L 672
?live16422@32: ; 
@153:
	pop       ebp
	ret       8
	?debug L 0
@ptrShr	endp
ptrShr	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch214
	dd	?patch215
	dd	?patch216
	df	@ptrShr
	dw	0
	dw	4175
	dw	0
	dw	147
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	83
	db	104
	db	114
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	148
	dw	0
	dw	0
	dw	0
	dw	?patch217
	dw	529
	dw	?patch218
	dd	?live16422@16-@ptrShr
	dd	?live16422@32-?live16422@16
	dw	17
?patch218	equ	1
?patch217	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	149
	dw	0
	dw	0
	dw	0
?patch214	equ	@153-@ptrShr+4
?patch215	equ	0
?patch216	equ	@153-@ptrShr
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrCmp	segment virtual
	align	2
@ptrCmp	proc	near
?live16423@0:
	?debug L 675
@154:
	push      ebp
	mov       ebp,esp
	?debug L 701
	mov       eax,dword ptr [ebp+16]
	push      eax
	mov       edx,dword ptr [ebp+12]
	push      edx
	mov       ecx,dword ptr [ebp+8]
	push      ecx
	call      @_memcmp
	add       esp,12
	?debug L 703
@156:
@155:
	pop       ebp
	ret       12
	?debug L 0
@ptrCmp	endp
ptrCmp	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch219
	dd	?patch220
	dd	?patch221
	df	@ptrCmp
	dw	0
	dw	4177
	dw	0
	dw	150
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	67
	db	109
	db	112
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	151
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4162
	dw	0
	dw	152
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	153
	dw	0
	dw	0
	dw	0
?patch219	equ	@156-@ptrCmp+4
?patch220	equ	0
?patch221	equ	@156-@ptrCmp
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
@ptrSca$qqspvcl	segment virtual
	align	2
@@ptrSca$qqspvcl	proc	near
?live16424@0:
	?debug L 706
@157:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
	?debug L 725
?live16424@16: ; EBX = alpdst
	mov       eax,dword ptr [ebp+16]
	push      eax
	movsx     edx,byte ptr [ebp+12]
	push      edx
	push      ebx
	call      @@std@memchr$qpviui
	add       esp,12
	sub       eax,ebx
	?debug L 727
?live16424@32: ; 
@159:
@158:
	pop       ebx
	pop       ebp
	ret       12
	?debug L 0
@@ptrSca$qqspvcl	endp
@ptrSca$qqspvcl	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	62
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch222
	dd	?patch223
	dd	?patch224
	df	@@ptrSca$qqspvcl
	dw	0
	dw	4179
	dw	0
	dw	154
	dw	0
	dw	0
	dw	0
	db	15
	db	64
	db	112
	db	116
	db	114
	db	83
	db	99
	db	97
	db	36
	db	113
	db	113
	db	115
	db	112
	db	118
	db	99
	db	108
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	155
	dw	0
	dw	0
	dw	0
	dw	?patch225
	dw	529
	dw	?patch226
	dd	?live16424@16-@@ptrSca$qqspvcl
	dd	?live16424@32-?live16424@16
	dw	20
?patch226	equ	1
?patch225	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	112
	dw	0
	dw	156
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	157
	dw	0
	dw	0
	dw	0
?patch222	equ	@159-@@ptrSca$qqspvcl+5
?patch223	equ	0
?patch224	equ	@159-@@ptrSca$qqspvcl
	dw	2
	dw	6
	dw	8
	dw	531
	dw	1
	dw	65532
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
ptrChr	segment virtual
	align	2
@ptrChr	proc	near
?live16425@0:
	?debug L 730
@160:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
	?debug L 749
?live16425@16: ; EBX = alpdst
	mov       eax,dword ptr [ebp+16]
	push      eax
	movsx     edx,byte ptr [ebp+12]
	push      edx
	push      ebx
	call      @@std@memchr$qpxviui
	add       esp,12
	sub       eax,ebx
	?debug L 751
?live16425@32: ; 
@162:
@161:
	pop       ebx
	pop       ebp
	ret       12
	?debug L 0
@ptrChr	endp
ptrChr	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch227
	dd	?patch228
	dd	?patch229
	df	@ptrChr
	dw	0
	dw	4181
	dw	0
	dw	158
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	67
	db	104
	db	114
	dw	18
	dw	512
	dw	8
	dw	0
	dw	4162
	dw	0
	dw	159
	dw	0
	dw	0
	dw	0
	dw	?patch230
	dw	529
	dw	?patch231
	dd	?live16425@16-@ptrChr
	dd	?live16425@32-?live16425@16
	dw	20
?patch231	equ	1
?patch230	equ	14
	dw	18
	dw	512
	dw	12
	dw	0
	dw	112
	dw	0
	dw	160
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	161
	dw	0
	dw	0
	dw	0
?patch227	equ	@162-@ptrChr+5
?patch228	equ	0
?patch229	equ	@162-@ptrChr
	dw	2
	dw	6
	dw	8
	dw	531
	dw	1
	dw	65532
	dw	65535
$$BSYMS	ends
_BSS	segment dword public use32 'BSS'
	align	4
$ijkgdfia	label	dword
	db	4	dup(?)
_BSS	ends
_DATA	segment dword public use32 'DATA'
	align	4
$ankgdfia	label	dword
	dd	$ijkgdfia
_DATA	ends
_BSS	segment dword public use32 'BSS'
$ialgdfia	label	byte
	db	256	dup(?)
_BSS	ends
_DATA	segment dword public use32 'DATA'
	align	4
$aelgdfia	label	dword
	dd	$ialgdfia
_DATA	ends
_TEXT	segment dword public use32 'CODE'
ptrFndLast	segment virtual
	align	2
@ptrFndLast	proc	near
?live16426@0:
	?debug L 754
@163:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	mov       ebx,offset $ialgdfia
	mov       esi,dword ptr [ebp+24]
	?debug L 756
?live16426@16: ; ESI = aco_size, EAX = asrc_size, EDI = alpfnd, EBX = &$ialgdfia
	;	
	mov       edx,dword ptr [ebp+12]
	add       edx,esi
	?debug L 754
?live16426@32: ; 
	mov       eax,dword ptr [ebp+16]
	?debug L 756
?live16426@48: ; ESI = aco_size, EAX = asrc_size, EDI = alpfnd, EBX = &$ialgdfia
	;	
	cmp       eax,edx
	?debug L 754
?live16426@64: ; 
	mov       edi,dword ptr [ebp+20]
	?debug L 756
?live16426@80: ; ESI = aco_size, EAX = asrc_size, EDI = alpfnd, EBX = &$ialgdfia
	;	
	jl        short @165
	test      esi,esi
	jle       short @165
	test      eax,eax
	jg        short @164
	?debug L 757
?live16426@96: ; 
@165:
	or        eax,-1
	jmp       short @166
	?debug L 761
?live16426@112: ; ESI = aco_size, EDI = alpfnd, EBX = &$ialgdfia
@164:
	cmp       esi,255
	jle       short @167
	?debug L 762
?live16426@128: ; EDI = alpfnd, EBX = &$ialgdfia
	push      255
	push      0
	push      ebx
	call      @ptrSet
	?debug L 763
@168:
	mov       eax,254
	lea       edx,dword ptr [edi+254]
	?debug L 764
?live16426@160: ; EAX = i, EDX = @temp3, EBX = &$ialgdfia
@169:
	movsx     ecx,byte ptr [edx]
	mov       byte ptr [ebx+ecx],al
	?debug L 763
	dec       eax
	dec       edx
	test      eax,eax
	jge       short @169
	?debug L 766
?live16426@192: ; 
@172:
	jmp       short @173
	?debug L 768
?live16426@208: ; ESI = aco_size, EDI = alpfnd, EBX = &$ialgdfia
@167:
	push      esi
	push      0
	push      ebx
	call      @ptrSet
	?debug L 769
@174:
	lea       eax,dword ptr [esi-1]
	lea       edx,dword ptr [edi+eax]
	test      eax,eax
	jl        short @176
	?debug L 770
?live16426@240: ; EAX = i, EDX = @temp1, EBX = &$ialgdfia
@175:
	movsx     ecx,byte ptr [edx]
	mov       byte ptr [ebx+ecx],al
	?debug L 769
	dec       eax
	dec       edx
	test      eax,eax
	jge       short @175
	?debug L 813
?live16426@272: ; 
@176:
@178:
@173:
	mov       eax,dword ptr [$ijkgdfia]
	jmp       short @166
	?debug L 815
	or        eax,-1
	?debug L 816
@179:
@166:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       20
	?debug L 0
@ptrFndLast	endp
ptrFndLast	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	57
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch232
	dd	?patch233
	dd	?patch234
	df	@ptrFndLast
	dw	0
	dw	4183
	dw	0
	dw	162
	dw	0
	dw	0
	dw	0
	db	10
	db	112
	db	116
	db	114
	db	70
	db	110
	db	100
	db	76
	db	97
	db	115
	db	116
	dw	18
	dw	512
	dw	8
	dw	0
	dw	4099
	dw	0
	dw	163
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	164
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	165
	dw	0
	dw	0
	dw	0
	dw	?patch235
	dw	529
	dw	?patch236
	dd	?live16426@16-@ptrFndLast
	dd	?live16426@32-?live16426@16
	dw	17
	dd	?live16426@48-@ptrFndLast
	dd	?live16426@64-?live16426@48
	dw	17
	dd	?live16426@80-@ptrFndLast
	dd	?live16426@96-?live16426@80
	dw	17
?patch236	equ	3
?patch235	equ	34
	dw	18
	dw	512
	dw	20
	dw	0
	dw	4099
	dw	0
	dw	166
	dw	0
	dw	0
	dw	0
	dw	?patch237
	dw	529
	dw	?patch238
	dd	?live16426@16-@ptrFndLast
	dd	?live16426@32-?live16426@16
	dw	24
	dd	?live16426@48-@ptrFndLast
	dd	?live16426@64-?live16426@48
	dw	24
	dd	?live16426@80-@ptrFndLast
	dd	?live16426@96-?live16426@80
	dw	24
	dd	?live16426@112-@ptrFndLast
	dd	?live16426@160-?live16426@112
	dw	24
	dd	?live16426@208-@ptrFndLast
	dd	?live16426@240-?live16426@208
	dw	24
?patch238	equ	5
?patch237	equ	54
	dw	18
	dw	512
	dw	24
	dw	0
	dw	18
	dw	0
	dw	167
	dw	0
	dw	0
	dw	0
	dw	?patch239
	dw	529
	dw	?patch240
	dd	?live16426@16-@ptrFndLast
	dd	?live16426@32-?live16426@16
	dw	23
	dd	?live16426@48-@ptrFndLast
	dd	?live16426@64-?live16426@48
	dw	23
	dd	?live16426@80-@ptrFndLast
	dd	?live16426@96-?live16426@80
	dw	23
	dd	?live16426@112-@ptrFndLast
	dd	?live16426@128-?live16426@112
	dw	23
	dd	?live16426@208-@ptrFndLast
	dd	?live16426@240-?live16426@208
	dw	23
?patch240	equ	5
?patch239	equ	54
	dw	22
	dw	513
	df	$aelgdfia
	dw	0
	dw	1056
	dw	0
	dw	168
	dw	0
	dw	0
	dw	0
	dw	22
	dw	513
	df	$ialgdfia
	dw	0
	dw	4185
	dw	0
	dw	169
	dw	0
	dw	0
	dw	0
	dw	22
	dw	513
	df	$ankgdfia
	dw	0
	dw	1042
	dw	0
	dw	170
	dw	0
	dw	0
	dw	0
	dw	22
	dw	513
	df	$ijkgdfia
	dw	0
	dw	18
	dw	0
	dw	171
	dw	0
	dw	0
	dw	0
	dw	24
	dw	519
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch241
	df	@168
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	17
	dw	172
	dw	0
	dw	0
	dw	0
	dw	?patch242
	dw	529
	dw	?patch243
	dd	?live16426@160-@ptrFndLast
	dd	?live16426@192-?live16426@160
	dw	17
?patch243	equ	1
?patch242	equ	14
?patch241	equ	@172-@168
	dw	2
	dw	6
	dw	24
	dw	519
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch244
	df	@174
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	17
	dw	173
	dw	0
	dw	0
	dw	0
	dw	?patch245
	dw	529
	dw	?patch246
	dd	?live16426@240-@ptrFndLast
	dd	?live16426@272-?live16426@240
	dw	17
?patch246	equ	1
?patch245	equ	14
?patch244	equ	@178-@174
	dw	2
	dw	6
?patch232	equ	@179-@ptrFndLast+7
?patch233	equ	0
?patch234	equ	@179-@ptrFndLast
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_BSS	segment dword public use32 'BSS'
	align	4
$ihlgdfia	label	dword
	db	4	dup(?)
_BSS	ends
_DATA	segment dword public use32 'DATA'
	align	4
$allgdfia	label	dword
	dd	$ihlgdfia
_DATA	ends
_BSS	segment dword public use32 'BSS'
$iolgdfia	label	byte
	db	256	dup(?)
_BSS	ends
_DATA	segment dword public use32 'DATA'
	align	4
$acmgdfia	label	dword
	dd	$iolgdfia
_DATA	ends
_TEXT	segment dword public use32 'CODE'
ptrFnd	segment virtual
	align	2
@ptrFnd	proc	near
?live16427@0:
	?debug L 819
@180:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+24]
	?debug L 821
?live16427@16: ; EBX = aco_size, EAX = asrc_size
	mov       edx,dword ptr [ebp+12]
	add       edx,ebx
	?debug L 819
?live16427@32: ; 
	mov       eax,dword ptr [ebp+16]
	?debug L 821
?live16427@48: ; EBX = aco_size, EAX = asrc_size
	cmp       eax,edx
	jl        short @182
	test      ebx,ebx
	jle       short @182
	test      eax,eax
	jg        short @181
	?debug L 822
?live16427@64: ; 
@182:
	or        eax,-1
	jmp       short @183
	?debug L 826
?live16427@80: ; EBX = aco_size
@181:
	cmp       ebx,255
	jle       short @184
	?debug L 827
	push      255
	push      0
	push      offset $iolgdfia
	call      @ptrSet
	?debug L 828
@185:
	lea       eax,dword ptr [ebx-256]
	mov       edx,dword ptr [ebp+20]
	add       edx,eax
	cmp       ebx,eax
	mov       esi,256
	jle       short @190
	?debug L 829
?live16427@128: ; EBX = aco_size, EAX = i, EDX = @temp5, ESI = ic
@186:
	movsx     edi,byte ptr [edx]
	mov       ecx,esi
	?debug L 828
	dec       esi
	?debug L 829
	add       cl,-1
	?debug L 828
	inc       edx
	inc       eax
	?debug L 829
	mov       byte ptr [edi+$iolgdfia],cl
	?debug L 828
	cmp       ebx,eax
	jg        short @186
	?debug L 831
?live16427@224: ; 
@189:
	jmp       short @190
	?debug L 833
?live16427@240: ; EBX = aco_size
@184:
	push      ebx
	push      0
	push      offset $iolgdfia
	call      @ptrSet
	?debug L 834
@191:
	xor       esi,esi
	mov       edx,ebx
	mov       eax,dword ptr [ebp+20]
	cmp       ebx,esi
	jle       short @193
	?debug L 835
?live16427@272: ; EBX = aco_size, EAX = @temp1, EDX = ic, ESI = i
@192:
	movsx     edi,byte ptr [eax]
	mov       ecx,edx
	?debug L 834
	dec       edx
	?debug L 835
	add       cl,-1
	?debug L 834
	inc       eax
	inc       esi
	?debug L 835
	mov       byte ptr [edi+$iolgdfia],cl
	?debug L 834
	cmp       ebx,esi
	jg        short @192
	?debug L 881
?live16427@368: ; 
@193:
@195:
@190:
	mov       eax,dword ptr [$ihlgdfia]
	jmp       short @183
	?debug L 883
	or        eax,-1
	?debug L 884
@196:
@183:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       20
	?debug L 0
@ptrFnd	endp
ptrFnd	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch247
	dd	?patch248
	dd	?patch249
	df	@ptrFnd
	dw	0
	dw	4186
	dw	0
	dw	174
	dw	0
	dw	0
	dw	0
	db	6
	db	112
	db	116
	db	114
	db	70
	db	110
	db	100
	dw	18
	dw	512
	dw	8
	dw	0
	dw	4099
	dw	0
	dw	175
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	18
	dw	0
	dw	176
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	18
	dw	0
	dw	177
	dw	0
	dw	0
	dw	0
	dw	?patch250
	dw	529
	dw	?patch251
	dd	?live16427@16-@ptrFnd
	dd	?live16427@32-?live16427@16
	dw	17
	dd	?live16427@48-@ptrFnd
	dd	?live16427@64-?live16427@48
	dw	17
?patch251	equ	2
?patch250	equ	24
	dw	18
	dw	512
	dw	20
	dw	0
	dw	4099
	dw	0
	dw	178
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	24
	dw	0
	dw	18
	dw	0
	dw	179
	dw	0
	dw	0
	dw	0
	dw	?patch252
	dw	529
	dw	?patch253
	dd	?live16427@16-@ptrFnd
	dd	?live16427@32-?live16427@16
	dw	20
	dd	?live16427@48-@ptrFnd
	dd	?live16427@64-?live16427@48
	dw	20
	dd	?live16427@80-@ptrFnd
	dd	?live16427@224-?live16427@80
	dw	20
	dd	?live16427@240-@ptrFnd
	dd	?live16427@368-?live16427@240
	dw	20
?patch253	equ	4
?patch252	equ	44
	dw	22
	dw	513
	df	$acmgdfia
	dw	0
	dw	1056
	dw	0
	dw	180
	dw	0
	dw	0
	dw	0
	dw	22
	dw	513
	df	$iolgdfia
	dw	0
	dw	4188
	dw	0
	dw	181
	dw	0
	dw	0
	dw	0
	dw	22
	dw	513
	df	$allgdfia
	dw	0
	dw	1042
	dw	0
	dw	182
	dw	0
	dw	0
	dw	0
	dw	22
	dw	513
	df	$ihlgdfia
	dw	0
	dw	18
	dw	0
	dw	183
	dw	0
	dw	0
	dw	0
	dw	24
	dw	519
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch254
	df	@185
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	23
	dw	184
	dw	0
	dw	0
	dw	0
	dw	?patch255
	dw	529
	dw	?patch256
	dd	?live16427@128-@ptrFnd
	dd	?live16427@224-?live16427@128
	dw	23
?patch256	equ	1
?patch255	equ	14
	dw	16
	dw	2
	dw	18
	dw	0
	dw	17
	dw	185
	dw	0
	dw	0
	dw	0
	dw	?patch257
	dw	529
	dw	?patch258
	dd	?live16427@128-@ptrFnd
	dd	?live16427@224-?live16427@128
	dw	17
?patch258	equ	1
?patch257	equ	14
?patch254	equ	@189-@185
	dw	2
	dw	6
	dw	24
	dw	519
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch259
	df	@191
	dw	0
	dw	0
	dw	16
	dw	2
	dw	18
	dw	0
	dw	19
	dw	186
	dw	0
	dw	0
	dw	0
	dw	?patch260
	dw	529
	dw	?patch261
	dd	?live16427@272-@ptrFnd
	dd	?live16427@368-?live16427@272
	dw	19
?patch261	equ	1
?patch260	equ	14
	dw	16
	dw	2
	dw	18
	dw	0
	dw	23
	dw	187
	dw	0
	dw	0
	dw	0
	dw	?patch262
	dw	529
	dw	?patch263
	dd	?live16427@272-@ptrFnd
	dd	?live16427@368-?live16427@272
	dw	23
?patch263	equ	1
?patch262	equ	14
?patch259	equ	@195-@191
	dw	2
	dw	6
?patch247	equ	@196-@ptrFnd+7
?patch248	equ	0
?patch249	equ	@196-@ptrFnd
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65524
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
bitEql	segment virtual
	align	2
@bitEql	proc	near
?live16428@0:
	?debug L 891
@197:
	push      ebp
	mov       ebp,esp
	add       esp,-8
	push      ebx
	push      esi
	push      edi
	?debug L 1015
	mov       eax,dword ptr [ebp+24]
	mov       dword ptr [ebp-4],eax
	?debug L 1016
	mov       esi,dword ptr [ebp+16]
	?debug L 1017
?live16428@48: ; ESI = src
	mov       al,byte ptr [ebp+20]
	mov       byte ptr [ebp-5],al
	?debug L 1018
	mov       eax,dword ptr [ebp+8]
	?debug L 1019
?live16428@80: ; EAX = dst, ESI = src
	mov       dl,byte ptr [ebp+12]
	?debug L 1020
?live16428@96: ; EAX = dst, EDX = dst_bit, ESI = src
	cmp       dword ptr [ebp-4],32
	jb        short @199
	?debug L 1022
@198:
	cmp       dword ptr [eax],0
	je        short @205
	xor       ecx,ecx
	mov       cl,dl
	push      ecx
	mov       ecx,32
	pop       ebx
	sub       ecx,ebx
	or        ebx,-1
	shr       ebx,cl
	test      bl,bl
	jne       short @203
@205:
	xor       ebx,ebx
	jmp       short @204
@203:
	mov       ebx,1
@204:
	mov       cl,byte ptr [ebp-5]
	mov       edi,dword ptr [esi]
	sar       edi,cl
	mov       ecx,edx
	shl       edi,cl
	or        ebx,edi
	je        short @202
	mov       ecx,edx
	or        ebx,-1
	shl       ebx,cl
	test      ebx,ebx
	jne       short @200
@202:
	xor       ecx,ecx
	jmp       short @201
@200:
	mov       ecx,1
@201:
	mov       dword ptr [eax],ecx
	?debug L 1023
	add       eax,3
	?debug L 1024
	add       esi,3
	?debug L 1025
	sub       dword ptr [ebp-4],24
	?debug L 1020
	cmp       dword ptr [ebp-4],32
	jae       short @198
	?debug L 1027
@199:
	cmp       dword ptr [ebp-4],0
	jbe       short @207
	?debug L 1028
@206:
	cmp       byte ptr [eax],0
	je        short @210
	mov       ecx,edx
	mov       ebx,255
	sar       ebx,cl
	test      bl,bl
	jne       short @208
@210:
	xor       ebx,ebx
	jmp       short @209
@208:
	mov       ebx,1
@209:
	mov       cl,byte ptr [ebp-5]
	movsx     esi,byte ptr [esi]
	sar       esi,cl
	mov       ecx,edx
	shl       esi,cl
	test      esi,esi
	je        short @213
	mov       ecx,edx
	mov       esi,255
	shl       esi,cl
	test      esi,esi
	jne       short @211
@213:
	xor       ecx,ecx
	jmp       short @212
@211:
	mov       ecx,1
@212:
	or        bl,cl
	mov       byte ptr [eax],bl
	?debug L 1029
?live16428@224: ; EAX = dst, EDX = dst_bit
	inc       eax
	?debug L 1031
?live16428@240: ; EAX = dst, EDX = dst_bit, ESI = src
	sub       dword ptr [ebp-4],8
	?debug L 1027
	cmp       dword ptr [ebp-4],0
	?debug L 1030
?live16428@272: ; EAX = dst, EDX = dst_bit
	lea       esi,dword ptr [eax+1]
	?debug L 1027
?live16428@288: ; EAX = dst, EDX = dst_bit, ESI = src
	ja        short @206
	?debug L 1035
?live16428@304: ; 
@207:
@214:
	pop       edi
	pop       esi
	pop       ebx
	pop       ecx
	pop       ecx
	pop       ebp
	ret       20
	?debug L 0
@bitEql	endp
bitEql	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch264
	dd	?patch265
	dd	?patch266
	df	@bitEql
	dw	0
	dw	4189
	dw	0
	dw	188
	dw	0
	dw	0
	dw	0
	db	6
	db	98
	db	105
	db	116
	db	69
	db	113
	db	108
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	189
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	32
	dw	0
	dw	190
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	4162
	dw	0
	dw	191
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	20
	dw	0
	dw	32
	dw	0
	dw	192
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	24
	dw	0
	dw	34
	dw	0
	dw	193
	dw	0
	dw	0
	dw	0
	dw	16
	dw	2
	dw	32
	dw	0
	dw	3
	dw	194
	dw	0
	dw	0
	dw	0
	dw	?patch267
	dw	529
	dw	?patch268
	dd	?live16428@96-@bitEql
	dd	?live16428@304-?live16428@96
	dw	3
?patch268	equ	1
?patch267	equ	14
	dw	16
	dw	2
	dw	1136
	dw	0
	dw	17
	dw	195
	dw	0
	dw	0
	dw	0
	dw	?patch269
	dw	529
	dw	?patch270
	dd	?live16428@80-@bitEql
	dd	?live16428@304-?live16428@80
	dw	17
?patch270	equ	1
?patch269	equ	14
	dw	18
	dw	512
	dw	65531
	dw	65535
	dw	32
	dw	0
	dw	196
	dw	0
	dw	0
	dw	0
	dw	16
	dw	2
	dw	1136
	dw	0
	dw	23
	dw	197
	dw	0
	dw	0
	dw	0
	dw	?patch271
	dw	529
	dw	?patch272
	dd	?live16428@48-@bitEql
	dd	?live16428@224-?live16428@48
	dw	23
	dd	?live16428@240-@bitEql
	dd	?live16428@272-?live16428@240
	dw	23
	dd	?live16428@288-@bitEql
	dd	?live16428@304-?live16428@288
	dw	23
?patch272	equ	3
?patch271	equ	34
	dw	18
	dw	512
	dw	65532
	dw	65535
	dw	117
	dw	0
	dw	198
	dw	0
	dw	0
	dw	0
?patch264	equ	@214-@bitEql+9
?patch265	equ	0
?patch266	equ	@214-@bitEql
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65516
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
bitSet	segment virtual
	align	2
@bitSet	proc	near
?live16429@0:
	?debug L 1038
@215:
	push      ebp
	mov       ebp,esp
	add       esp,-8
	push      ebx
	push      esi
	push      edi
	?debug L 1141
	mov       eax,dword ptr [ebp+24]
	shl       eax,3
	mov       dword ptr [ebp-4],eax
	?debug L 1146
?live16429@32: ; EAX = dst, EDX = dst_bit, ECX = src
	cmp       dword ptr [ebp-4],0
	?debug L 1144
?live16429@48: ; EDX = dst_bit, ECX = src
	mov       eax,dword ptr [ebp+8]
	?debug L 1142
?live16429@64: ; 
	mov       ecx,dword ptr [ebp+12]
	?debug L 1143
?live16429@80: ; ECX = src
	mov       dl,byte ptr [ebp+16]
	?debug L 1146
?live16429@96: ; EAX = dst, EDX = dst_bit, ECX = src
	jbe       short @217
	?debug L 1147
@216:
	xor       esi,esi
	jmp       short @219
	?debug L 1148
?live16429@128: ; EAX = dst, ESI = zr, EDX = dst_bit, ECX = src
@218:
	movsx     ecx,byte ptr [ecx+esi]
	mov       dword ptr [ebp-8],ecx
	?debug L 1149
?live16429@144: ; EAX = dst, ESI = zr, EDX = dst_bit
	cmp       byte ptr [eax],0
	je        short @222
	mov       ecx,edx
	mov       ebx,255
	sar       ebx,cl
	test      bl,bl
	jne       short @220
@222:
	xor       ebx,ebx
	jmp       short @221
@220:
	mov       ebx,1
@221:
	mov       ecx,edx
	mov       edi,dword ptr [ebp-8]
	shl       edi,cl
	test      edi,edi
	je        short @225
	mov       ecx,edx
	mov       edi,255
	shl       edi,cl
	test      edi,edi
	jne       short @223
@225:
	xor       ecx,ecx
	jmp       short @224
@223:
	mov       ecx,1
@224:
	or        bl,cl
	mov       byte ptr [eax],bl
	?debug L 1150
	inc       eax
	?debug L 1152
?live16429@176: ; EAX = dst, ESI = zr, EDX = dst_bit, ECX = src
	sub       dword ptr [ebp-4],8
	inc       esi
	?debug L 1151
?live16429@192: ; EAX = dst, ESI = zr, EDX = dst_bit
	lea       ecx,dword ptr [eax+1]
@219:
	xor       ebx,ebx
	mov       bl,byte ptr [ebp+20]
	cmp       esi,ebx
	jl        short @218
	?debug L 1146
?live16429@208: ; EAX = dst, EDX = dst_bit, ECX = src
	cmp       dword ptr [ebp-4],0
	ja        short @216
	?debug L 1156
?live16429@224: ; 
@217:
@228:
	pop       edi
	pop       esi
	pop       ebx
	pop       ecx
	pop       ecx
	pop       ebp
	ret       20
	?debug L 0
@bitSet	endp
bitSet	ends
_TEXT	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	53
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch273
	dd	?patch274
	dd	?patch275
	df	@bitSet
	dw	0
	dw	4191
	dw	0
	dw	199
	dw	0
	dw	0
	dw	0
	db	6
	db	98
	db	105
	db	116
	db	83
	db	101
	db	116
	dw	18
	dw	512
	dw	8
	dw	0
	dw	1027
	dw	0
	dw	200
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	12
	dw	0
	dw	4162
	dw	0
	dw	201
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	16
	dw	0
	dw	32
	dw	0
	dw	202
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	20
	dw	0
	dw	32
	dw	0
	dw	203
	dw	0
	dw	0
	dw	0
	dw	18
	dw	512
	dw	24
	dw	0
	dw	34
	dw	0
	dw	204
	dw	0
	dw	0
	dw	0
	dw	16
	dw	2
	dw	116
	dw	0
	dw	23
	dw	205
	dw	0
	dw	0
	dw	0
	dw	?patch276
	dw	529
	dw	?patch277
	dd	?live16429@128-@bitSet
	dd	?live16429@208-?live16429@128
	dw	23
?patch277	equ	1
?patch276	equ	14
	dw	18
	dw	512
	dw	65528
	dw	65535
	dw	116
	dw	0
	dw	206
	dw	0
	dw	0
	dw	0
	dw	16
	dw	2
	dw	1136
	dw	0
	dw	17
	dw	207
	dw	0
	dw	0
	dw	0
	dw	?patch278
	dw	529
	dw	?patch279
	dd	?live16429@32-@bitSet
	dd	?live16429@48-?live16429@32
	dw	17
	dd	?live16429@96-@bitSet
	dd	?live16429@224-?live16429@96
	dw	17
?patch279	equ	2
?patch278	equ	24
	dw	16
	dw	2
	dw	32
	dw	0
	dw	3
	dw	208
	dw	0
	dw	0
	dw	0
	dw	?patch280
	dw	529
	dw	?patch281
	dd	?live16429@32-@bitSet
	dd	?live16429@64-?live16429@32
	dw	3
	dd	?live16429@96-@bitSet
	dd	?live16429@224-?live16429@96
	dw	3
?patch281	equ	2
?patch280	equ	24
	dw	16
	dw	2
	dw	1027
	dw	0
	dw	18
	dw	209
	dw	0
	dw	0
	dw	0
	dw	?patch282
	dw	529
	dw	?patch283
	dd	?live16429@32-@bitSet
	dd	?live16429@64-?live16429@32
	dw	18
	dd	?live16429@80-@bitSet
	dd	?live16429@144-?live16429@80
	dw	18
	dd	?live16429@176-@bitSet
	dd	?live16429@192-?live16429@176
	dw	18
	dd	?live16429@208-@bitSet
	dd	?live16429@224-?live16429@208
	dw	18
?patch283	equ	4
?patch282	equ	44
	dw	18
	dw	512
	dw	65532
	dw	65535
	dw	117
	dw	0
	dw	210
	dw	0
	dw	0
	dw	0
?patch273	equ	@228-@bitSet+9
?patch274	equ	0
?patch275	equ	@228-@bitSet
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65516
	dw	65535
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
 ?debug  C A0020008737472416C6C6F63000000
@LocalAlloc equ LocalAlloc
 extrn   LocalAlloc:near
 ?debug  C A002000A737472416C6C6F634578000000
 ?debug  C A002000673747245716C000000
 ?debug  C A002000A7374725265416C6C6F63000000
@LocalReAlloc equ LocalReAlloc
 extrn   LocalReAlloc:near
 ?debug  C A002000C7374725265416C6C6F634578000000
 ?debug  C A002000773747246726565000000
@LocalFree equ LocalFree
 extrn   LocalFree:near
 ?debug  C A0020006737472447570000000
 ?debug  C A00200067374724C656E000000
 ?debug  C A00200087374725265447570000000
 ?debug  C A002000670747245716C000000
 ?debug  C A00200067374724D6F76000000
 ?debug  C A00200067074724D6F76000000
 ?debug  C A0020006737472416464000000
@_strcat equ _strcat
 extrn   _strcat:near
 ?debug  C A0020009737472496E73657274000000
@_strlen equ _strlen
 extrn   _strlen:near
 ?debug  C A002000673747244656C000000
 ?debug  C A002000973747244656C456E64000000
 ?debug  C A0020006737472506F73000000
 ?debug  C A0020006737472537562000000
 ?debug  C A0020009737472537562456E64000000
 ?debug  C A002000C73747244656C696D69746572000000
 ?debug  C A002000B73747245786368616E6765000000
 ?debug  C A002000F73747245786368616E676543686172000000
 ?debug  C A00200127374724578747261637446696C65526F6F74000000
 ?debug  C A00200127374724578747261637446696C6550617468000000
 ?debug  C A00200127374724578747261637446696C654E616D65000000
 ?debug  C A002000E73747246697846696C6550617468000000
 ?debug  C A0020008696E74546F537472000000
@_itoa equ _itoa
 extrn   _itoa:near
 ?debug  C A0020008737472546F496E74000000
 ?debug  C A0020008707472416C6C6F63000000
 ?debug  C A002000A7074725265416C6C6F63000000
 ?debug  C A002000770747246726565000000
@_memmove equ _memmove
 extrn   _memmove:near
 ?debug  C A0020006707472526576000000
 ?debug  C A0020006707472536574000000
 ?debug  C A00200087074725365744578000000
 ?debug  C A002000670747253686C000000
 ?debug  C A0020006707472536872000000
 ?debug  C A0020006707472436D70000000
@_memcmp equ _memcmp
 extrn   _memcmp:near
@@std@memchr$qpviui equ @std@memchr$qpviui
 extrn   @std@memchr$qpviui:near
 ?debug  C A0020006707472436872000000
@@std@memchr$qpxviui equ @std@memchr$qpxviui
 extrn   @std@memchr$qpxviui:near
 ?debug  C A002000A707472466E644C617374000000
 ?debug  C A0020006707472466E64000000
 ?debug  C A002000662697445716C000000
 ?debug  C A0020006626974536574000000
 ?debug  C 9F757569642E6C6962
 ?debug  C 9F757569642E6C6962
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	?patch284
	dw	37
	dw	211
	dw	0
	dw	0
	dw	0
	dw	0
?patch284	equ	12
	dw	?patch285
	dw	38
	dw	254
	dw	212
	dw	0
	dw	213
	dw	0
	dw	214
	dw	0
	dw	215
	dw	0
	dw	216
	dw	0
	dw	217
	dw	0
	dw	218
	dw	0
	dw	219
	dw	0
	dw	220
	dw	0
	dw	221
	dw	0
	dw	222
	dw	0
	dw	223
	dw	0
	dw	224
	dw	0
	dw	225
	dw	0
	dw	226
	dw	0
	dw	227
	dw	0
	dw	228
	dw	0
	dw	229
	dw	0
	dw	230
	dw	0
	dw	231
	dw	0
	dw	232
	dw	0
	dw	233
	dw	0
	dw	234
	dw	0
	dw	235
	dw	0
	dw	236
	dw	0
	dw	237
	dw	0
	dw	238
	dw	0
	dw	239
	dw	0
	dw	240
	dw	0
	dw	241
	dw	0
	dw	242
	dw	0
	dw	243
	dw	0
	dw	244
	dw	0
	dw	245
	dw	0
	dw	246
	dw	0
	dw	247
	dw	0
	dw	248
	dw	0
	dw	249
	dw	0
	dw	250
	dw	0
	dw	251
	dw	0
	dw	252
	dw	0
	dw	253
	dw	0
	dw	254
	dw	0
	dw	255
	dw	0
	dw	256
	dw	0
	dw	257
	dw	0
	dw	258
	dw	0
	dw	259
	dw	0
	dw	260
	dw	0
	dw	261
	dw	0
	dw	262
	dw	0
	dw	263
	dw	0
	dw	264
	dw	0
	dw	265
	dw	0
	dw	266
	dw	0
	dw	267
	dw	0
	dw	268
	dw	0
	dw	269
	dw	0
	dw	270
	dw	0
	dw	271
	dw	0
	dw	272
	dw	0
	dw	273
	dw	0
	dw	274
	dw	0
	dw	275
	dw	0
	dw	276
	dw	0
	dw	277
	dw	0
	dw	278
	dw	0
	dw	279
	dw	0
	dw	280
	dw	0
	dw	281
	dw	0
	dw	282
	dw	0
	dw	283
	dw	0
	dw	284
	dw	0
	dw	285
	dw	0
	dw	286
	dw	0
	dw	287
	dw	0
	dw	288
	dw	0
	dw	289
	dw	0
	dw	290
	dw	0
	dw	291
	dw	0
	dw	292
	dw	0
	dw	293
	dw	0
	dw	294
	dw	0
	dw	295
	dw	0
	dw	296
	dw	0
	dw	297
	dw	0
	dw	298
	dw	0
	dw	299
	dw	0
	dw	300
	dw	0
	dw	301
	dw	0
	dw	302
	dw	0
	dw	303
	dw	0
	dw	304
	dw	0
	dw	305
	dw	0
	dw	306
	dw	0
	dw	307
	dw	0
	dw	308
	dw	0
	dw	309
	dw	0
	dw	310
	dw	0
	dw	311
	dw	0
	dw	312
	dw	0
	dw	313
	dw	0
	dw	314
	dw	0
	dw	315
	dw	0
	dw	316
	dw	0
	dw	317
	dw	0
	dw	318
	dw	0
	dw	319
	dw	0
	dw	320
	dw	0
	dw	321
	dw	0
	dw	322
	dw	0
	dw	323
	dw	0
	dw	324
	dw	0
	dw	325
	dw	0
	dw	326
	dw	0
	dw	327
	dw	0
	dw	328
	dw	0
	dw	329
	dw	0
	dw	330
	dw	0
	dw	331
	dw	0
	dw	332
	dw	0
	dw	333
	dw	0
	dw	334
	dw	0
	dw	335
	dw	0
	dw	336
	dw	0
	dw	337
	dw	0
	dw	338
	dw	0
	dw	339
	dw	0
	dw	340
	dw	0
	dw	341
	dw	0
	dw	342
	dw	0
	dw	343
	dw	0
	dw	344
	dw	0
	dw	345
	dw	0
	dw	346
	dw	0
	dw	347
	dw	0
	dw	348
	dw	0
	dw	349
	dw	0
	dw	350
	dw	0
	dw	351
	dw	0
	dw	352
	dw	0
	dw	353
	dw	0
	dw	354
	dw	0
	dw	355
	dw	0
	dw	356
	dw	0
	dw	357
	dw	0
	dw	358
	dw	0
	dw	359
	dw	0
	dw	360
	dw	0
	dw	361
	dw	0
	dw	362
	dw	0
	dw	363
	dw	0
	dw	364
	dw	0
	dw	365
	dw	0
	dw	366
	dw	0
	dw	367
	dw	0
	dw	368
	dw	0
	dw	369
	dw	0
	dw	370
	dw	0
	dw	371
	dw	0
	dw	372
	dw	0
	dw	373
	dw	0
	dw	374
	dw	0
	dw	375
	dw	0
	dw	376
	dw	0
	dw	377
	dw	0
	dw	378
	dw	0
	dw	379
	dw	0
	dw	380
	dw	0
	dw	381
	dw	0
	dw	382
	dw	0
	dw	383
	dw	0
	dw	384
	dw	0
	dw	385
	dw	0
	dw	386
	dw	0
	dw	387
	dw	0
	dw	388
	dw	0
	dw	389
	dw	0
	dw	390
	dw	0
	dw	391
	dw	0
	dw	392
	dw	0
	dw	393
	dw	0
	dw	394
	dw	0
	dw	395
	dw	0
	dw	396
	dw	0
	dw	397
	dw	0
	dw	398
	dw	0
	dw	399
	dw	0
	dw	400
	dw	0
	dw	401
	dw	0
	dw	402
	dw	0
	dw	403
	dw	0
	dw	404
	dw	0
	dw	405
	dw	0
	dw	406
	dw	0
	dw	407
	dw	0
	dw	408
	dw	0
	dw	409
	dw	0
	dw	410
	dw	0
	dw	411
	dw	0
	dw	412
	dw	0
	dw	413
	dw	0
	dw	414
	dw	0
	dw	415
	dw	0
	dw	416
	dw	0
	dw	417
	dw	0
	dw	418
	dw	0
	dw	419
	dw	0
	dw	420
	dw	0
	dw	421
	dw	0
	dw	422
	dw	0
	dw	423
	dw	0
	dw	424
	dw	0
	dw	425
	dw	0
	dw	426
	dw	0
	dw	427
	dw	0
	dw	428
	dw	0
	dw	429
	dw	0
	dw	430
	dw	0
	dw	431
	dw	0
	dw	432
	dw	0
	dw	433
	dw	0
	dw	434
	dw	0
	dw	435
	dw	0
	dw	436
	dw	0
	dw	437
	dw	0
	dw	438
	dw	0
	dw	439
	dw	0
	dw	440
	dw	0
	dw	441
	dw	0
	dw	442
	dw	0
	dw	443
	dw	0
	dw	444
	dw	0
	dw	445
	dw	0
	dw	446
	dw	0
	dw	447
	dw	0
	dw	448
	dw	0
	dw	449
	dw	0
	dw	450
	dw	0
	dw	451
	dw	0
	dw	452
	dw	0
	dw	453
	dw	0
	dw	454
	dw	0
	dw	455
	dw	0
	dw	456
	dw	0
	dw	457
	dw	0
	dw	458
	dw	0
	dw	459
	dw	0
	dw	460
	dw	0
	dw	461
	dw	0
	dw	462
	dw	0
	dw	463
	dw	0
	dw	464
	dw	0
	dw	465
	dw	0
?patch285	equ	1020
	dw	?patch286
	dw	1
	db	6
	db	1
	db	0
	db	24
	db	11
	db	66
	db	67
	db	67
	db	51
	db	50
	db	32
	db	53
	db	46
	db	53
	db	46
	db	49
?patch286	equ	18
$$BSYMS	ends
$$BTYPES	segment byte public use32 'DEBTYP'
	db        2,0,0,0,14,0,8,0,112,4,0,0,7,0,1,0
	db        1,16,0,0,8,0,1,2,1,0,18,0,0,0,14,0
	db        8,0,112,4,0,0,7,0,2,0,5,16,0,0,8,0
	db        2,0,10,0,4,16,0,0,8,0,1,0,1,0,112,0
	db        0,0,12,0,1,2,2,0,18,0,0,0,3,16,0,0
	db        14,0,8,0,112,4,0,0,7,0,2,0,7,16,0,0
	db        12,0,1,2,2,0,112,4,0,0,18,0,0,0,14,0
	db        8,0,112,4,0,0,7,0,3,0,9,16,0,0,16,0
	db        1,2,3,0,112,4,0,0,18,0,0,0,3,16,0,0
	db        14,0,8,0,3,0,0,0,7,0,1,0,11,16,0,0
	db        8,0,1,2,1,0,112,4,0,0,14,0,8,0,112,4
	db        0,0,7,0,1,0,13,16,0,0,8,0,1,2,1,0
	db        3,16,0,0,14,0,8,0,112,4,0,0,7,0,2,0
	db        15,16,0,0,12,0,1,2,2,0,112,4,0,0,3,16
	db        0,0,14,0,8,0,18,0,0,0,7,0,1,0,17,16
	db        0,0,8,0,1,2,1,0,3,16,0,0,14,0,8,0
	db        112,4,0,0,7,0,2,0,19,16,0,0,12,0,1,2
	db        2,0,112,4,0,0,3,16,0,0,14,0,8,0,112,4
	db        0,0,7,0,2,0,21,16,0,0,12,0,1,2,2,0
	db        112,4,0,0,3,16,0,0,14,0,8,0,112,4,0,0
	db        7,0,3,0,23,16,0,0,16,0,1,2,3,0,112,4
	db        0,0,3,16,0,0,18,0,0,0,14,0,8,0,112,4
	db        0,0,7,0,3,0,25,16,0,0,16,0,1,2,3,0
	db        112,4,0,0,3,16,0,0,18,0,0,0,14,0,8,0
	db        112,4,0,0,7,0,2,0,27,16,0,0,12,0,1,2
	db        2,0,112,4,0,0,3,16,0,0,14,0,8,0,112,4
	db        0,0,7,0,3,0,29,16,0,0,16,0,1,2,3,0
	db        112,4,0,0,18,0,0,0,3,16,0,0,14,0,8,0
	db        112,4,0,0,7,0,3,0,31,16,0,0,16,0,1,2
	db        3,0,112,4,0,0,18,0,0,0,18,0,0,0,14,0
	db        8,0,112,4,0,0,7,0,3,0,33,16,0,0,16,0
	db        1,2,3,0,112,4,0,0,18,0,0,0,18,0,0,0
	db        14,0,8,0,18,0,0,0,7,0,3,0,35,16,0,0
	db        16,0,1,2,3,0,3,16,0,0,18,0,0,0,3,16
	db        0,0,14,0,8,0,112,4,0,0,7,0,4,0,37,16
	db        0,0,20,0,1,2,4,0,112,4,0,0,3,16,0,0
	db        18,0,0,0,18,0,0,0,14,0,8,0,112,4,0,0
	db        7,0,4,0,39,16,0,0,20,0,1,2,4,0,112,4
	db        0,0,3,16,0,0,18,0,0,0,18,0,0,0,14,0
	db        8,0,18,0,0,0,7,0,3,0,41,16,0,0,16,0
	db        1,2,3,0,3,16,0,0,112,0,0,0,18,0,0,0
	db        14,0,8,0,112,4,0,0,7,0,3,0,43,16,0,0
	db        16,0,1,2,3,0,112,4,0,0,3,16,0,0,3,16
	db        0,0,14,0,8,0,112,4,0,0,7,0,3,0,45,16
	db        0,0,16,0,1,2,3,0,112,4,0,0,4,16,0,0
	db        4,16,0,0,14,0,8,0,112,4,0,0,7,0,2,0
	db        47,16,0,0,12,0,1,2,2,0,112,4,0,0,3,16
	db        0,0,14,0,8,0,112,4,0,0,7,0,2,0,49,16
	db        0,0,12,0,1,2,2,0,112,4,0,0,3,16,0,0
	db        14,0,8,0,112,4,0,0,7,0,2,0,51,16,0,0
	db        12,0,1,2,2,0,112,4,0,0,3,16,0,0,14,0
	db        8,0,112,4,0,0,7,0,2,0,53,16,0,0,12,0
	db        1,2,2,0,112,4,0,0,3,16,0,0,14,0,8,0
	db        112,4,0,0,7,0,1,0,55,16,0,0,8,0,1,2
	db        1,0,18,0,0,0,18,0,3,0,112,0,0,0,17,0
	db        0,0,0,0,0,0,32,0,32,0,14,0,8,0,18,0
	db        0,0,7,0,1,0,58,16,0,0,8,0,1,2,1,0
	db        3,16,0,0,14,0,8,0,3,4,0,0,7,0,1,0
	db        60,16,0,0,8,0,1,2,1,0,18,0,0,0,14,0
	db        8,0,3,4,0,0,7,0,2,0,62,16,0,0,12,0
	db        1,2,2,0,3,4,0,0,18,0,0,0,14,0,8,0
	db        3,0,0,0,7,0,1,0,64,16,0,0,8,0,1,2
	db        1,0,3,4,0,0,14,0,8,0,3,0,0,0,7,0
	db        3,0,68,16,0,0,8,0,2,0,10,0,67,16,0,0
	db        8,0,1,0,1,0,3,0,0,0,16,0,1,2,3,0
	db        3,4,0,0,66,16,0,0,18,0,0,0,14,0,8,0
	db        3,0,0,0,7,0,3,0,70,16,0,0,16,0,1,2
	db        3,0,3,4,0,0,66,16,0,0,18,0,0,0,14,0
	db        8,0,3,0,0,0,7,0,3,0,72,16,0,0,16,0
	db        1,2,3,0,3,4,0,0,66,16,0,0,18,0,0,0
	db        14,0,8,0,3,0,0,0,7,0,3,0,74,16,0,0
	db        16,0,1,2,3,0,3,4,0,0,112,0,0,0,18,0
	db        0,0,14,0,8,0,3,0,0,0,7,0,4,0,76,16
	db        0,0,20,0,1,2,4,0,3,4,0,0,66,16,0,0
	db        32,0,0,0,18,0,0,0,14,0,8,0,3,0,0,0
	db        7,0,2,0,78,16,0,0,12,0,1,2,2,0,3,4
	db        0,0,18,0,0,0,14,0,8,0,3,0,0,0,7,0
	db        2,0,80,16,0,0,12,0,1,2,2,0,3,4,0,0
	db        18,0,0,0,14,0,8,0,18,0,0,0,7,0,3,0
	db        82,16,0,0,16,0,1,2,3,0,3,4,0,0,66,16
	db        0,0,18,0,0,0,14,0,8,0,18,0,0,0,7,0
	db        3,0,84,16,0,0,16,0,1,2,3,0,3,4,0,0
	db        112,0,0,0,18,0,0,0,14,0,8,0,18,0,0,0
	db        7,0,3,0,86,16,0,0,16,0,1,2,3,0,66,16
	db        0,0,112,0,0,0,18,0,0,0,14,0,8,0,18,0
	db        0,0,7,0,5,0,88,16,0,0,24,0,1,2,5,0
	db        3,16,0,0,18,0,0,0,18,0,0,0,3,16,0,0
	db        18,0,0,0,18,0,3,0,32,0,0,0,17,0,0,0
	db        0,0,0,0,0,1,0,1,14,0,8,0,18,0,0,0
	db        7,0,5,0,91,16,0,0,24,0,1,2,5,0,3,16
	db        0,0,18,0,0,0,18,0,0,0,3,16,0,0,18,0
	db        0,0,18,0,3,0,32,0,0,0,17,0,0,0,0,0
	db        0,0,0,1,0,1,14,0,8,0,3,0,0,0,7,0
	db        5,0,94,16,0,0,24,0,1,2,5,0,3,4,0,0
	db        32,0,0,0,66,16,0,0,32,0,0,0,34,0,0,0
	db        14,0,8,0,3,0,0,0,7,0,5,0,96,16,0,0
	db        24,0,1,2,5,0,3,4,0,0,66,16,0,0,32,0
	db        0,0,32,0,0,0,34,0,0,0,14,0,8,0,3,4
	db        0,0,7,0,2,0,98,16,0,0,12,0,1,2,2,0
	db        117,0,0,0,34,0,0,0,14,0,8,0,3,4,0,0
	db        7,0,3,0,100,16,0,0,16,0,1,2,3,0,3,4
	db        0,0,34,0,0,0,117,0,0,0,14,0,8,0,3,4
	db        0,0,7,0,1,0,102,16,0,0,8,0,1,2,1,0
	db        3,4,0,0,14,0,8,0,112,4,0,0,0,0,2,0
	db        104,16,0,0,12,0,1,2,2,0,112,4,0,0,3,16
	db        0,0,14,0,8,0,117,0,0,0,0,0,1,0,106,16
	db        0,0,8,0,1,2,1,0,3,16,0,0,14,0,8,0
	db        112,4,0,0,0,0,3,0,108,16,0,0,16,0,1,2
	db        3,0,116,0,0,0,112,4,0,0,116,0,0,0,14,0
	db        8,0,3,4,0,0,0,0,3,0,110,16,0,0,16,0
	db        1,2,3,0,3,4,0,0,66,16,0,0,117,0,0,0
	db        14,0,8,0,116,0,0,0,0,0,3,0,112,16,0,0
	db        16,0,1,2,3,0,66,16,0,0,66,16,0,0,117,0
	db        0,0,14,0,8,0,3,4,0,0,0,0,3,0,114,16
	db        0,0,16,0,1,2,3,0,3,4,0,0,116,0,0,0
	db        117,0,0,0,14,0,8,0,66,16,0,0,0,0,3,0
	db        116,16,0,0,16,0,1,2,3,0,66,16,0,0,116,0
	db        0,0,117,0,0,0
$$BTYPES	ends
$$BNAMES	segment byte public use32 'DEBNAM'
	db	8,'strAlloc'
	db	7,'alength'
	db	10,'strAllocEx'
	db	7,'alength'
	db	6,'alpsrc'
	db	10,'strReAlloc'
	db	6,'alpdst'
	db	7,'alength'
	db	12,'strReAllocEx'
	db	6,'alpdst'
	db	7,'alength'
	db	6,'alpsrc'
	db	7,'strFree'
	db	6,'alpdst'
	db	6,'strDup'
	db	6,'alpdst'
	db	8,'strReDup'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'strLen'
	db	6,'alpsrc'
	db	6,'strEql'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'strMov'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	7,'strnEql'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	7,'alength'
	db	7,'strnMov'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	7,'alength'
	db	6,'strAdd'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	9,'strInsert'
	db	6,'alpdst'
	db	6,'astart'
	db	7,'ainsert'
	db	6,'cellen'
	db	9,'insertlen'
	db	6,'strDel'
	db	6,'alpdst'
	db	6,'astart'
	db	7,'alength'
	db	9,'strDelEnd'
	db	6,'alpdst'
	db	6,'astart'
	db	4,'aend'
	db	6,'strPos'
	db	6,'alpsrc'
	db	6,'abegin'
	db	6,'alpfnd'
	db	8,'fnd_size'
	db	8,'src_size'
	db	6,'strSub'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'astart'
	db	7,'alength'
	db	9,'strSubEnd'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'astart'
	db	4,'aend'
	db	12,'strDelimiter'
	db	6,'alpsrc'
	db	10,'adelimiter'
	db	10,'adirection'
	db	3,'pos'
	db	3,'pos'
	db	11,'strExchange'
	db	6,'alpdst'
	db	6,'alpfnd'
	db	6,'alpexh'
	db	6,'lencel'
	db	7,'lennaco'
	db	5,'lenco'
	db	4,'find'
	db	3,'pos'
	db	15,'strExchangeChar'
	db	6,'alpdst'
	db	6,'alpfnd'
	db	6,'alpexh'
	db	6,'lencel'
	db	3,'pos'
	db	18,'strExtractFileRoot'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	9,'delimiter'
	db	18,'strExtractFilePath'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	9,'delimiter'
	db	18,'strExtractFileName'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	9,'delimiter'
	db	14,'strFixFilePath'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'lensrc'
	db	8,'intToStr'
	db	4,'aint'
	db	3,'str'
	db	8,'strToInt'
	db	4,'asrc'
	db	8,'ptrAlloc'
	db	6,'acount'
	db	10,'ptrReAlloc'
	db	6,'alpdst'
	db	6,'acount'
	db	7,'ptrFree'
	db	6,'alpdst'
	db	6,'ptrEql'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'acount'
	db	6,'ptrRev'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'acount'
	db	1,'a'
	db	9,'r_dst_end'
	db	11,'r_dst_start'
	db	9,'r_src_end'
	db	11,'r_src_start'
	db	6,'ptrMov'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'acount'
	db	6,'ptrSet'
	db	6,'alpdst'
	db	6,'aznakb'
	db	6,'acount'
	db	8,'ptrSetEx'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'aesize'
	db	6,'acount'
	db	6,'ptrShl'
	db	6,'alpdst'
	db	6,'acount'
	db	6,'ptrShr'
	db	6,'alpdst'
	db	6,'acount'
	db	6,'ptrCmp'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	6,'acount'
	db	6,'ptrSca'
	db	6,'alpdst'
	db	6,'aznakb'
	db	6,'acount'
	db	6,'ptrChr'
	db	6,'alpdst'
	db	6,'aznakb'
	db	6,'acount'
	db	10,'ptrFndLast'
	db	6,'alpsrc'
	db	8,'asrc_min'
	db	9,'asrc_size'
	db	6,'alpfnd'
	db	8,'aco_size'
	db	7,'lpshift'
	db	5,'shift'
	db	7,'lpret_i'
	db	5,'ret_i'
	db	1,'i'
	db	1,'i'
	db	6,'ptrFnd'
	db	6,'alpsrc'
	db	8,'asrc_min'
	db	9,'asrc_size'
	db	6,'alpfnd'
	db	8,'aco_size'
	db	7,'lpshift'
	db	5,'shift'
	db	7,'lpret_i'
	db	5,'ret_i'
	db	2,'ic'
	db	1,'i'
	db	2,'ic'
	db	1,'i'
	db	6,'bitEql'
	db	6,'alpdst'
	db	8,'adst_bit'
	db	6,'alpsrc'
	db	8,'asrc_bit'
	db	8,'abit_num'
	db	7,'dst_bit'
	db	3,'dst'
	db	7,'src_bit'
	db	3,'src'
	db	4,'bits'
	db	6,'bitSet'
	db	6,'alpdst'
	db	6,'alpsrc'
	db	8,'adst_bit'
	db	11,'asrc_elsize'
	db	10,'adst_count'
	db	2,'zr'
	db	3,'aku'
	db	3,'dst'
	db	7,'dst_bit'
	db	3,'src'
	db	4,'bits'
	db	3,'std'
	db	5,'_rotr'
	db	5,'_rotl'
	db	6,'_crotr'
	db	6,'_lrotr'
	db	6,'_lrotl'
	db	6,'_crotl'
	db	3,'abs'
	db	6,'wctomb'
	db	7,'wcstoul'
	db	8,'wcstombs'
	db	6,'wcstol'
	db	6,'wcstod'
	db	5,'ultoa'
	db	4,'time'
	db	6,'system'
	db	4,'swab'
	db	7,'strtoul'
	db	6,'strtol'
	db	6,'strtod'
	db	5,'srand'
	db	7,'realloc'
	db	4,'rand'
	db	6,'putenv'
	db	6,'perror'
	db	6,'mbtowc'
	db	8,'mbstowcs'
	db	5,'mblen'
	db	13,'_seterrormode'
	db	14,'@std@max$qulul'
	db	26,'@std@%max$T1%$qrxT1t1$rxT1'
	db	14,'@std@min$qulul'
	db	26,'@std@%min$T1%$qrxT1t1$rxT1'
	db	17,'@std@randomize$qv'
	db	14,'@std@random$qi'
	db	4,'ltoa'
	db	4,'gcvt'
	db	4,'fcvt'
	db	4,'ecvt'
	db	6,'malloc'
	db	4,'ldiv'
	db	4,'labs'
	db	4,'itoa'
	db	6,'getenv'
	db	4,'free'
	db	4,'exit'
	db	3,'div'
	db	6,'calloc'
	db	4,'atol'
	db	4,'atoi'
	db	4,'atof'
	db	6,'atexit'
	db	5,'abort'
	db	6,'_wtold'
	db	5,'_wtol'
	db	5,'_wtoi'
	db	5,'_wtof'
	db	8,'_wsystem'
	db	11,'_wsplitpath'
	db	11,'_wsearchstr'
	db	11,'_wsearchenv'
	db	8,'_wputenv'
	db	8,'_wperror'
	db	10,'_wmakepath'
	db	8,'_wgetenv'
	db	10,'_wfullpath'
	db	8,'_wcstold'
	db	8,'_strtold'
	db	10,'_splitpath'
	db	10,'_searchstr'
	db	10,'_searchenv'
	db	9,'_makepath'
	db	7,'_wtoi64'
	db	8,'_ui64tow'
	db	8,'_ui64toa'
	db	7,'_i64tow'
	db	7,'_i64toa'
	db	7,'_atoi64'
	db	5,'_ltow'
	db	5,'_ltoa'
	db	6,'_lrand'
	db	5,'_itow'
	db	6,'_ultow'
	db	17,'@std@_swab$qpct1i'
	db	17,'@std@_putenv$qpxc'
	db	18,'@std@_ultoa$qulpci'
	db	16,'@std@_itoa$qipci'
	db	5,'_gcvt'
	db	5,'_fcvt'
	db	9,'_fullpath'
	db	5,'_exit'
	db	6,'_atold'
	db	5,'_ecvt'
	db	7,'__errno'
	db	10,'__doserrno'
	db	5,'qsort'
	db	7,'lsearch'
	db	5,'lfind'
	db	7,'bsearch'
	db	7,'wcsxfrm'
	db	6,'wcstok'
	db	6,'wcsstr'
	db	6,'wcsspn'
	db	7,'wcsrchr'
	db	7,'wcspcpy'
	db	7,'wcspbrk'
	db	7,'wcsncpy'
	db	7,'wcsncmp'
	db	7,'wcsncat'
	db	6,'wcslen'
	db	7,'wcscspn'
	db	6,'wcscpy'
	db	7,'wcscoll'
	db	6,'wcscmp'
	db	6,'wcschr'
	db	6,'wcscat'
	db	6,'strtok'
	db	18,'@std@strstr$qpxct1'
	db	18,'@std@strstr$qpcpxc'
	db	6,'strspn'
	db	19,'@std@strpbrk$qpxct1'
	db	19,'@std@strpbrk$qpcpxc'
	db	8,'strerror'
	db	7,'strcspn'
	db	18,'@std@strrchr$qpxci'
	db	17,'@std@strrchr$qpci'
	db	7,'strncpy'
	db	7,'strncmp'
	db	7,'strncat'
	db	6,'strlen'
	db	17,'@std@strchr$qpxci'
	db	16,'@std@strchr$qpci'
	db	6,'strcat'
	db	6,'strset'
	db	6,'stpcpy'
	db	7,'strnset'
	db	7,'_wcsset'
	db	7,'_wcsrev'
	db	8,'_wcspcpy'
	db	8,'_wcsnset'
	db	10,'_wcsnicoll'
	db	9,'_wcsnicmp'
	db	9,'_wcsncoll'
	db	9,'_wcsicoll'
	db	8,'_wcsicmp'
	db	7,'_wcsdup'
	db	10,'_strnicoll'
	db	9,'_strncoll'
	db	9,'_stricoll'
	db	9,'_strerror'
	db	9,'_lwcsxfrm'
	db	8,'_lwcsupr'
	db	11,'_lwcsnicoll'
	db	10,'_lwcsncoll'
	db	8,'_lwcslwr'
	db	10,'_lwcsicoll'
	db	9,'_lwcscoll'
	db	9,'_lstrxfrm'
	db	11,'_lstrnicoll'
	db	10,'_lstrncoll'
	db	10,'_lstricoll'
	db	9,'_lstrcoll'
	db	9,'_strnicmp'
	db	7,'_strcmp'
	db	8,'_stricmp'
	db	8,'_strcmpi'
	db	7,'_strlwr'
	db	7,'_strdup'
	db	7,'_strupr'
	db	8,'_strnset'
	db	7,'_strset'
	db	7,'_strrev'
	db	6,'strrev'
	db	8,'strnicmp'
	db	7,'stricmp'
	db	6,'strdup'
	db	7,'_stpcpy'
	db	8,'_lstrupr'
	db	8,'_lstrlwr'
	db	12,'_lwsetlocale'
	db	11,'_wsetlocale'
	db	12,'_llocaleconv'
	db	10,'localeconv'
	db	11,'_lsetlocale'
	db	10,'_ltowlower'
	db	10,'_ltowupper'
	db	8,'towupper'
	db	8,'towlower'
	db	9,'_ltoupper'
	db	7,'toupper'
	db	9,'_ltolower'
	db	7,'tolower'
	db	8,'iswascii'
	db	9,'iswxdigit'
	db	8,'iswupper'
	db	8,'iswspace'
	db	8,'iswpunct'
	db	8,'iswprint'
	db	8,'iswlower'
	db	8,'iswgraph'
	db	8,'iswdigit'
	db	8,'iswcntrl'
	db	8,'iswalpha'
	db	8,'iswalnum'
	db	7,'isascii'
	db	8,'isxdigit'
	db	7,'isupper'
	db	7,'isspace'
	db	7,'ispunct'
	db	7,'isprint'
	db	7,'islower'
	db	7,'isgraph'
	db	7,'isdigit'
	db	7,'iscntrl'
	db	7,'isalpha'
	db	7,'isalnum'
	db	6,'memset'
	db	6,'memcpy'
	db	6,'memcmp'
	db	19,'@std@memchr$qpxviui'
	db	18,'@std@memchr$qpviui'
	db	7,'memmove'
	db	7,'memicmp'
	db	7,'memccpy'
	db	8,'_wmemset'
	db	8,'_wmemcpy'
	db	21,'@std@_wmemchr$qpxviui'
	db	20,'@std@_wmemchr$qpviui'
	db	10,'__threadid'
	db	14,'@std@ptrdiff_t'
	db	11,'@std@size_t'
	db	11,'@std@wint_t'
	db	13,'@std@wctype_t'
	db	12,'@std@va_list'
	db	9,'_chartype'
	db	6,'_lower'
	db	6,'_upper'
	db	5,'lconv'
	db	5,'_argc'
	db	5,'_argv'
	db	12,'__mb_cur_max'
	db	16,'_cmdline_escapes'
	db	8,'_environ'
	db	9,'_fileinfo'
	db	6,'_fmode'
	db	8,'_osmajor'
	db	8,'_osminor'
	db	7,'_osmode'
	db	10,'_osversion'
	db	12,'_sys_errlist'
	db	9,'_sys_nerr'
	db	9,'_wenviron'
	db	13,'@std@atexit_t'
	db	10,'@std@div_t'
	db	11,'@std@ldiv_t'
$$BNAMES	ends
	?debug	D "D:\stasiek\My Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLIO\TSoft_build_conf.h" 19510 30771
	?debug	D "D:\stasiek\My Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLIO\TSOFT_IO.H" 19599 42164
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\imm.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\mcx.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winsvc.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\commdlg.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\oleauto.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\propidl.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\oaidl.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\msxml.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\servprov.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\oleidl.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\urlmon.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\cguid.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\objidl.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\unknwn.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\search.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\stdlib.h" 10503 12320
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\objbase.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\ole2.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\prsht.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winspool.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winsmcrd.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winioctl.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcnsip.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcndr.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\wtypes.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winscard.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winefs.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\wincrypt.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\qos.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winsock2.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winperf.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\shellapi.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcasync.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcnterr.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcnsi.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcdcep.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcdce.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\windows.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpc.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\nb30.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\mmsystem.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\lzexpand.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\dlgs.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\ddeml.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\dde.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\cderr.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winnetwk.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winreg.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winver.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\wincon.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winnls.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\tvout.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winuser.h" 18052 45771
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\pshpack1.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\wingdi.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winerror.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winbase.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\pshpack8.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\pshpack2.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\poppack.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\pshpack4.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_loc.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\locale.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_str.h" 10503 12320
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\string.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\guiddef.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\basetsd.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\mbctype.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\ctype.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winnt.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\windef.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\stdarg.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\excpt.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_null.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_defs.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_stddef.h" 10305 12288
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\mem.h" 10503 12320
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\WINDOWS.H" 10305 12288
	?debug	D "D:\stasiek\My Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLIO\TSoft_IO.cpp" 19605 29693
	end
