	.386p
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
	?debug	S "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSoft_Koder.cpp"
	?debug	T "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSoft_Koder.cpp"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
DGROUP	group	_BSS,_DATA
_DATA	segment dword public use32 'DATA'
	align	4
_CRC32_tab	label	dword
	dd	0
	dd	1996959894
	dd	-301047508
	dd	-1727442502
	dd	124634137
	dd	1886057615
	dd	-379345611
	dd	-1637575261
	dd	249268274
	dd	2044508324
	dd	-522852066
	dd	-1747789432
	dd	162941995
	dd	2125561021
	dd	-407360249
	dd	-1866523247
	dd	498536548
	dd	1789927666
	dd	-205950648
	dd	-2067906082
	dd	450548861
	dd	1843258603
	dd	-187386543
	dd	-2083289657
	dd	325883990
	dd	1684777152
	dd	-43845254
	dd	-1973040660
	dd	335633487
	dd	1661365465
	dd	-99664541
	dd	-1928851979
	dd	997073096
	dd	1281953886
	dd	-715111964
	dd	-1570279054
	dd	1006888145
	dd	1258607687
	dd	-770865667
	dd	-1526024853
	dd	901097722
	dd	1119000684
	dd	-608450090
	dd	-1396901568
	dd	853044451
	dd	1172266101
	dd	-589951537
	dd	-1412350631
	dd	651767980
	dd	1373503546
	dd	-925412992
	dd	-1076862698
	dd	565507253
	dd	1454621731
	dd	-809855591
	dd	-1195530993
	dd	671266974
	dd	1594198024
	dd	-972236366
	dd	-1324619484
	dd	795835527
	dd	1483230225
	dd	-1050600021
	dd	-1234817731
	dd	1994146192
	dd	31158534
	dd	-1731059524
	dd	-271249366
	dd	1907459465
	dd	112637215
	dd	-1614814043
	dd	-390540237
	dd	2013776290
	dd	251722036
	dd	-1777751922
	dd	-519137256
	dd	2137656763
	dd	141376813
	dd	-1855689577
	dd	-429695999
	dd	1802195444
	dd	476864866
	dd	-2056965928
	dd	-228458418
	dd	1812370925
	dd	453092731
	dd	-2113342271
	dd	-183516073
	dd	1706088902
	dd	314042704
	dd	-1950435094
	dd	-54949764
	dd	1658658271
	dd	366619977
	dd	-1932296973
	dd	-69972891
	dd	1303535960
	dd	984961486
	dd	-1547960204
	dd	-725929758
	dd	1256170817
	dd	1037604311
	dd	-1529756563
	dd	-740887301
	dd	1131014506
	dd	879679996
	dd	-1385723834
	dd	-631195440
	dd	1141124467
	dd	855842277
	dd	-1442165665
	dd	-586318647
	dd	1342533948
	dd	654459306
	dd	-1106571248
	dd	-921952122
	dd	1466479909
	dd	544179635
	dd	-1184443383
	dd	-832445281
	dd	1591671054
	dd	702138776
	dd	-1328506846
	dd	-942167884
	dd	1504918807
	dd	783551873
	dd	-1212326853
	dd	-1061524307
	dd	-306674912
	dd	-1698712650
	dd	62317068
	dd	1957810842
	dd	-355121351
	dd	-1647151185
	dd	81470997
	dd	1943803523
	dd	-480048366
	dd	-1805370492
	dd	225274430
	dd	2053790376
	dd	-468791541
	dd	-1828061283
	dd	167816743
	dd	2097651377
	dd	-267414716
	dd	-2029476910
	dd	503444072
	dd	1762050814
	dd	-144550051
	dd	-2140837941
	dd	426522225
	dd	1852507879
	dd	-19653770
	dd	-1982649376
	dd	282753626
	dd	1742555852
	dd	-105259153
	dd	-1900089351
	dd	397917763
	dd	1622183637
	dd	-690576408
	dd	-1580100738
	dd	953729732
	dd	1340076626
	dd	-776247311
	dd	-1497606297
	dd	1068828381
	dd	1219638859
	dd	-670225446
	dd	-1358292148
	dd	906185462
	dd	1090812512
	dd	-547295293
	dd	-1469587627
	dd	829329135
	dd	1181335161
	dd	-882789492
	dd	-1134132454
	dd	628085408
	dd	1382605366
	dd	-871598187
	dd	-1156888829
	dd	570562233
	dd	1426400815
	dd	-977650754
	dd	-1296233688
	dd	733239954
	dd	1555261956
	dd	-1026031705
	dd	-1244606671
	dd	752459403
	dd	1541320221
	dd	-1687895376
	dd	-328994266
	dd	1969922972
	dd	40735498
	dd	-1677130071
	dd	-351390145
	dd	1913087877
	dd	83908371
	dd	-1782625662
	dd	-491226604
	dd	2075208622
	dd	213261112
	dd	-1831694693
	dd	-438977011
	dd	2094854071
	dd	198958881
	dd	-2032938284
	dd	-237706686
	dd	1759359992
	dd	534414190
	dd	-2118248755
	dd	-155638181
	dd	1873836001
	dd	414664567
	dd	-2012718362
	dd	-15766928
	dd	1711684554
	dd	285281116
	dd	-1889165569
	dd	-127750551
	dd	1634467795
	dd	376229701
	dd	-1609899400
	dd	-686959890
	dd	1308918612
	dd	956543938
	dd	-1486412191
	dd	-799009033
	dd	1231636301
	dd	1047427035
	dd	-1362007478
	dd	-640263460
	dd	1088359270
	dd	936918000
	dd	-1447252397
	dd	-558129467
	dd	1202900863
	dd	817233897
	dd	-1111625188
	dd	-893730166
	dd	1404277552
	dd	615818150
	dd	-1160759803
	dd	-841546093
	dd	1423857449
	dd	601450431
	dd	-1285129682
	dd	-1000256840
	dd	1567103746
	dd	711928724
	dd	-1274298825
	dd	-1022587231
	dd	1510334235
	dd	755167117
$mepbdfia	label	byte
	db	0
	db	1
	db	2
	db	4
	db	5
	db	7
	db	8
	db	10
	db	11
	db	12
	db	16
	db	22
	db	23
	db	26
_DATA	ends
_TEXT	segment dword public use32 'CODE'
Make_CRC32_tab	segment virtual
	align	2
@Make_CRC32_tab	proc	near
?live16385@0:
@1:
	push      ebx
	push      esi
	push      edi
	add       esp,-16
	mov       edi,esp
	mov       esi,offset $mepbdfia
	mov       ecx,3
?live16385@32: ; ESI = POLY_nominal
	mov       eax,esp
?live16385@48: ; 
	rep   movsd
	movsw
	xor       esi,esi
?live16385@80: ; ESI = POLY_nominal
	xor       ebx,ebx
?live16385@96: ; EBX = n, ESI = POLY_nominal, EAX = @temp4
@2:
	xor       edx,edx
	mov       ecx,31
	mov       dl,byte ptr [eax]
	inc       eax
	sub       ecx,edx
	mov       edx,1
	shl       edx,cl
	or        esi,edx
	inc       ebx
	cmp       ebx,14
	jb        short @2
?live16385@112: ; ESI = POLY_nominal
	xor       ebx,ebx
	mov       ecx,offset _CRC32_tab
?live16385@128: ; EBX = n, ESI = POLY_nominal, ECX = @temp5
@5:
	mov       eax,ebx
	xor       edx,edx
?live16385@144: ; EAX = c, EDX = k, EBX = n, ESI = POLY_nominal, ECX = @temp5
@7:
	test      al,1
	je        short @9
	shr       eax,1
	xor       eax,esi
	jmp       short @10
@9:
	shr       eax,1
@10:
	inc       edx
	cmp       edx,8
	jb        short @7
?live16385@176: ; EAX = c, EBX = n, ESI = POLY_nominal, ECX = @temp5
	mov       dword ptr [ecx],eax
	inc       ebx
	add       ecx,4
	cmp       ebx,256
	jb        short @5
?live16385@192: ; 
@13:
	add       esp,16
	pop       edi
	pop       esi
	pop       ebx
	ret 
@Make_CRC32_tab	endp
Make_CRC32_tab	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
	align	4
$eipbdfia	label	dword
	dd	_CRC32_tab
_DATA	ends
_TEXT	segment dword public use32 'CODE'
Calc_CRC32	segment virtual
	align	2
@Calc_CRC32	proc	near
?live16386@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
@14:
	mov	 EDI,dword ptr [ebp+8]
	mov	 EDX,EDI
	add	 EDX,dword ptr [ebp+12]
	cmp	 EDI,EDX
	jge       @15
	mov	 ESI,dword ptr $eipbdfia
	mov	 EAX,0FFFFFFFFH
	xor	 EBX,EBX
@16:
Calc_CRC32_NEXT:
	mov	 BL,[EDI]
	xor	 BL,AL
	shr	 EAX,8
	xor	 EAX,[ESI+EBX]
	inc	 EDI
	cmp	 EDI,EDX
	jl        @16
	xor	 EAX,0FFFFFFFFH
@15:
Calc_CRC32_EXIT:
@17:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       8
@Calc_CRC32	endp
Calc_CRC32	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Calc_ADLER32$qqspvul	segment virtual
	align	2
@@Calc_ADLER32$qqspvul	proc	near
?live16387@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
@18:
	mov	 EDI,dword ptr [ebp+8]
	mov	 EDX,EDI
	add	 EDX,dword ptr [ebp+12]
	cmp	 EDI,EDX
	jge       @19
	mov	 ESI,5552
	xor	 EAX,EAX
	xor	 EBX,EBX
	xor	 ECX,ECX
@20:
Calc_ADLER32_NEXT:
	mov	 CL,[EDI]
	add	 AX,CX
	add	 BX,AX
	dec	 ESI
	test	 ESI,ESI
	jne       @21
	push	 EDX
	mov	 EBX,65521
	div	 EBX
	push	 EDX
	mov	 EAX,EBX
	div	 EBX
	push	 EDX
	pop	 EBX
	pop	 EAX
	pop	 EDX
	mov	 ESI,5552
@21:
Calc_ADLER32_INC:
	inc	 EDI
	cmp	 EDI,EDX
	jl        @20
	shl	 EAX,16
	or	 AX,BX
@19:
Calc_ADLER32_EXIT:
@22:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       8
@@Calc_ADLER32$qqspvul	endp
@Calc_ADLER32$qqspvul	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCKC$@Compress_LZS$qqspvt1ulul	segment virtual
	align	2
@@_$DCKC$@Compress_LZS$qqspvt1ulul	label	dword
	dd	@@$xt$10TSoft_Huff
	dd	4
	dd	-12
	dd	@@$xt$13TSoft_BinTree
	dd	4
	dd	-76
	dd	0
	dd	@@$xt$10TSoft_Huff
	dd	4
	dd	-12
	dd	0
	dd	@@$xt$13TSoft_BinTree
	dd	4
	dd	-76
	dd	0
@_$DCKC$@Compress_LZS$qqspvt1ulul	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTLC$@Compress_LZS$qqspvt1ulul	segment virtual
	align	2
@@_$ECTLC$@Compress_LZS$qqspvt1ulul	label	dword
	dd	0
	dd	-112
	dw	0
	dw	5
	dd	0
	dd	@@_$DCKC$@Compress_LZS$qqspvt1ulul+28
	dw	0
	dw	5
	dd	0
	dd	@@_$DCKC$@Compress_LZS$qqspvt1ulul
	dw	20
	dw	5
	dd	1
	dd	@@_$DCKC$@Compress_LZS$qqspvt1ulul+44
@_$ECTLC$@Compress_LZS$qqspvt1ulul	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
Compress_LZS	segment virtual
	align	2
@Compress_LZS	proc	near
?live16388@0:
@23:
	push      ebp
	mov       ebp,esp
	add       esp,-1152
	mov       eax,offset @@_$ECTLC$@Compress_LZS$qqspvt1ulul
	push      ebx
	push      esi
	push      edi
	mov       esi,dword ptr [ebp+12]
	call      @__InitExceptBlockLDTC
?live16388@16: ; ESI = alpSrc
	xor       edx,edx
	mov       dword ptr [ebp-116],edx
	push      1024
	push      0
	lea       ecx,dword ptr [ebp-1152]
	push      ecx
	call      @_memset
	add       esp,12
	mov       eax,esi
	mov       ebx,eax
?live16388@48: ; EBX = ptrs, ESI = alpSrc, EAX = @temp21
	add       eax,dword ptr [ebp+16]
	mov       dword ptr [ebp-120],eax
?live16388@64: ; EBX = ptrs
	mov       eax,dword ptr [ebp+8]
	mov       dword ptr [ebp-124],eax
	xor       edi,edi
?live16388@96: ; EBX = ptrs, EDI = pass_text_length
	mov       dword ptr [ebp-128],ebx
	xor       esi,esi
?live16388@128: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
	mov       word ptr [ebp-96],8
	lea       eax,dword ptr [ebp-12]
	push      eax
	call      @@TSoft_Huff@$bctr$qqsv
	inc       dword ptr [ebp-84]
	lea       edx,dword ptr [ebp-12]
	mov       word ptr [ebp-96],20
	push      edx
	call      @@TSoft_Huff@Initialize$qqsv
	mov       word ptr [ebp-96],32
	mov       ecx,dword ptr [ebp+16]
	push      ecx
	mov       eax,dword ptr [ebp+20]
	push      eax
	lea       edx,dword ptr [ebp-76]
	push      edx
	call      @@TSoft_BinTree@$bctr$qqsulul
	inc       dword ptr [ebp-84]
	mov       word ptr [ebp-96],20
	push      ebx
	lea       ecx,dword ptr [ebp-76]
	push      ecx
	call      @@TSoft_BinTree@Initialize$qqspuc
@24:
	lea       eax,dword ptr [esi+ebx]
	mov       edx,eax
	add       edx,dword ptr [ebp-52]
	cmp       edx,dword ptr [ebp-120]
	jb        short @27
?live16388@240: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length, EAX = @temp9
	;	
	add       eax,8
	cmp       eax,dword ptr [ebp-120]
	jb        short @28
?live16388@256: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
	add       ebx,esi
?live16388@272: ; EBX = ptrs, EDI = pass_text_length
	mov       ecx,dword ptr [ebp-120]
	sub       ecx,ebx
	add       edi,ecx
?live16388@288: ; EDI = pass_text_length
	jmp       @29
?live16388@304: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
@28:
	mov       eax,dword ptr [ebp-120]
	sub       eax,ebx
	sub       eax,esi
	mov       dword ptr [ebp-52],eax
@27:
	push      esi
	push      ebx
	lea       edx,dword ptr [ebp-76]
	push      edx
	call      @@TSoft_BinTree@Update$qqspucul
	add       ebx,esi
	lea       ecx,dword ptr [ebp-76]
	push      ecx
	call      @@TSoft_BinTree@Search_brun$qqsv
	mov       eax,dword ptr [ebp-36]
	cmp       eax,1
	je        short @31
?live16388@384: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length, EAX = @temp11
	;	
	push      edi
	push      eax
	lea       edx,dword ptr [ebp-76]
	push      edx
	call      @@TSoft_BinTree@Optimum_brun_match$qqsulul
	test      al,al
	jne       short @33
?live16388@400: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
	mov       dword ptr [ebp-36],1
@31:
	lea       ecx,dword ptr [ebp-76]
	push      ecx
	call      @@TSoft_BinTree@Search_dict$qqsv
	mov       eax,dword ptr [ebp-56]
	test      eax,eax
	je        short @34
?live16388@448: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length, EAX = @temp12
	;	
	push      edi
	push      eax
	lea       edx,dword ptr [ebp-76]
	push      edx
	call      @@TSoft_BinTree@Optimum_dict_match$qqsulul
	test      al,al
	jne       short @33
?live16388@464: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
	xor       ecx,ecx
	mov       dword ptr [ebp-56],ecx
?live16388@480: ; EBX = ptrs, EDI = pass_text_length
@34:
	cmp       edi,255
	jb        short @36
	xor       esi,esi
?live16388@512: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
	jmp       short @33
?live16388@528: ; EBX = ptrs, EDI = pass_text_length
@36:
	mov       esi,1
?live16388@544: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
	inc       edi
	jmp       @24
@33:
	test      edi,edi
	je        short @37
	push      edi
	mov       eax,dword ptr [ebp-124]
	push      eax
	lea       edx,dword ptr [ebp-20]
	push      edx
	call      @@__bitptr_hdrcoder@Code_ptrPass$qqspulul
	xor       ecx,ecx
	mov       cl,al
	add       dword ptr [ebp-124],ecx
	push      edi
	mov       eax,dword ptr [ebp-128]
	push      eax
	mov       edx,dword ptr [ebp-124]
	push      edx
	call      @ptrEql
	add       dword ptr [ebp-124],edi
	inc       dword ptr [ebp+4*edi-1152]
	mov       eax,dword ptr [ebp+4*edi-1152]
	cmp       eax,dword ptr [ebp-116]
	jbe       short @38
?live16388@640: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length, EAX = @temp17
	;	
	mov       dword ptr [ebp-116],eax
?live16388@656: ; EBX = ptrs, ESI = pass_skip_length
@38:
	mov       dword ptr [ebp-128],ebx
	xor       edi,edi
?live16388@688: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
@37:
	cmp       dword ptr [ebp-36],1
	je        short @39
?live16388@704: ; EBX = ptrs, EDI = pass_text_length
	mov       eax,dword ptr [ebp-32]
	push      eax
	mov       edx,dword ptr [ebp-28]
	push      edx
	mov       ecx,dword ptr [ebp-124]
	push      ecx
	lea       eax,dword ptr [ebp-20]
	push      eax
	call      @@__bitptr_hdrcoder@Code_ptrBrun$qqspululul
	xor       edx,edx
	mov       esi,ebx
	mov       dl,al
	add       dword ptr [ebp-124],edx
	mov       ecx,dword ptr [ebp-28]
	push      ecx
	push      esi
	mov       eax,dword ptr [ebp-124]
	push      eax
	call      @ptrEql
	mov       edx,dword ptr [ebp-28]
	add       dword ptr [ebp-124],edx
?live16388@720: ; EBX = ptrs, EDI = pass_text_length, ESI = @temp14
	mov       eax,dword ptr [ebp-32]
	inc       dword ptr [ebp+4*eax-1152]
?live16388@736: ; EBX = ptrs, EDI = pass_text_length, EAX = @temp13, ESI = @temp14
	;	
	mov       edx,dword ptr [ebp+4*eax-1152]
	cmp       edx,dword ptr [ebp-116]
	jbe       short @40
?live16388@752: ; EBX = ptrs, EDI = pass_text_length, ESI = @temp14
	mov       ecx,dword ptr [ebp-32]
	mov       eax,dword ptr [ebp+4*ecx-1152]
	mov       dword ptr [ebp-116],eax
@40:
	mov       eax,dword ptr [ebp-36]
	add       esi,eax
	mov       dword ptr [ebp-128],esi
?live16388@784: ; EBX = ptrs, EDI = pass_text_length, EAX = @temp15
	mov       esi,eax
?live16388@800: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
	jmp       @24
@39:
	cmp       dword ptr [ebp-56],0
	je        @24
	mov       eax,dword ptr [ebp-56]
	push      eax
	mov       edx,dword ptr [ebp-48]
	push      edx
	mov       ecx,dword ptr [ebp-124]
	push      ecx
	lea       eax,dword ptr [ebp-20]
	push      eax
	call      @@__bitptr_hdrcoder@Code_ptrDict$qqspululul
	xor       edx,edx
	mov       dl,al
	add       dword ptr [ebp-124],edx
?live16388@848: ; EBX = ptrs, EDI = pass_text_length
	mov       eax,dword ptr [ebp-56]
	inc       dword ptr [ebp+4*eax-1152]
?live16388@864: ; EBX = ptrs, EDI = pass_text_length, EAX = @temp5
	mov       edx,dword ptr [ebp+4*eax-1152]
	cmp       edx,dword ptr [ebp-116]
	jbe       short @42
	mov       ecx,dword ptr [ebp-56]
	mov       edx,dword ptr [ebp+4*ecx-1152]
	mov       dword ptr [ebp-116],edx
@42:
	mov       ecx,ebx
	mov       esi,eax
	add       ecx,eax
	mov       dword ptr [ebp-128],ecx
?live16388@944: ; EBX = ptrs, ESI = pass_skip_length, EDI = pass_text_length
	jmp       @24
@29:
	test      edi,edi
	je        short @43
?live16388@976: ; EDI = pass_text_length
	push      edi
	mov       eax,dword ptr [ebp-124]
	push      eax
	lea       edx,dword ptr [ebp-20]
	push      edx
	call      @@__bitptr_hdrcoder@Code_ptrPass$qqspulul
	xor       ecx,ecx
	mov       cl,al
	add       dword ptr [ebp-124],ecx
	push      edi
	mov       eax,dword ptr [ebp-128]
	push      eax
	mov       edx,dword ptr [ebp-124]
	push      edx
	call      @ptrEql
	add       dword ptr [ebp-124],edi
?live16388@992: ; 
@43:
	mov       eax,dword ptr [ebp-124]
	lea       edx,dword ptr [ebp-76]
	sub       eax,dword ptr [ebp+8]
	push      eax
	dec       dword ptr [ebp-84]
	push      2
	push      edx
	call      @@TSoft_BinTree@$bdtr$qqsv
	dec       dword ptr [ebp-84]
	push      2
	lea       ecx,dword ptr [ebp-12]
	push      ecx
	call      @@TSoft_Huff@$bdtr$qqsv
	pop       eax
	mov       edx,dword ptr [ebp-112]
	mov       dword ptr fs:[0],edx
@45:
@44:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       16
@Compress_LZS	endp
Compress_LZS	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCMC$@UnCompress_LZS$qqspvult1	segment virtual
	align	2
@@_$DCMC$@UnCompress_LZS$qqspvult1	label	dword
	dd	@@$xt$10TSoft_Huff
	dd	4
	dd	-12
	dd	0
	dd	@@$xt$10TSoft_Huff
	dd	4
	dd	-12
	dd	0
@_$DCMC$@UnCompress_LZS$qqspvult1	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTNC$@UnCompress_LZS$qqspvult1	segment virtual
	align	2
@@_$ECTNC$@UnCompress_LZS$qqspvult1	label	dword
	dd	0
	dd	-48
	dw	0
	dw	5
	dd	0
	dd	@@_$DCMC$@UnCompress_LZS$qqspvult1+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCMC$@UnCompress_LZS$qqspvult1
@_$ECTNC$@UnCompress_LZS$qqspvult1	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
UnCompress_LZS	segment virtual
	align	2
@UnCompress_LZS	proc	near
?live16393@0:
@46:
	push      ebp
	mov       ebp,esp
	add       esp,-72
	push      ebx
	push      esi
	push      edi
	lea       edi,dword ptr [ebp-56]
	mov       eax,offset @@_$ECTNC$@UnCompress_LZS$qqspvult1
	call      @__InitExceptBlockLDTC
?live16393@16: ; EBX = ptrs, EDI = &cnt
	mov       eax,dword ptr [ebp+8]
?live16393@32: ; EDI = &cnt
	mov       ebx,dword ptr [ebp+16]
?live16393@48: ; EBX = ptrs, EDI = &cnt
	mov       esi,eax
?live16393@64: ; EBX = ptrs, ESI = ptrd, EDI = &cnt, EAX = @temp6
	add       eax,dword ptr [ebp+12]
	mov       dword ptr [ebp-52],eax
?live16393@80: ; EBX = ptrs, ESI = ptrd, EDI = &cnt
	lea       eax,dword ptr [ebp-12]
	mov       word ptr [ebp-32],8
	push      eax
	call      @@TSoft_Huff@$bctr$qqsv
	inc       dword ptr [ebp-20]
	lea       edx,dword ptr [ebp-12]
	mov       word ptr [ebp-32],20
	push      edx
	call      @@TSoft_Huff@Initialize$qqsv
	cmp       esi,dword ptr [ebp-52]
	jae       @48
@47:
	mov       al,byte ptr [ebx]
	and       al,3
?live16393@176: ; EBX = ptrs, ESI = ptrd, EAX = hdr, EDI = &cnt
	cmp       al,1
	je        short @50
?live16393@192: ; EBX = ptrs, ESI = ptrd, EDI = &cnt
	cmp       al,2
	je        short @52
	test      al,al
	push      ebx
	push      edi
	lea       edx,dword ptr [ebp-72]
	push      edx
	call      @@__bitptr_hdrcoder@DeCode_ptrPass$qqspult1
	xor       ecx,ecx
	mov       cl,al
	add       ebx,ecx
	mov       eax,dword ptr [edi]
	push      eax
	push      ebx
	push      esi
	call      @ptrEql
	add       ebx,dword ptr [edi]
	add       esi,dword ptr [edi]
	jmp       short @55
@50:
	push      ebx
	push      edi
	lea       edx,dword ptr [ebp-60]
	push      edx
	lea       ecx,dword ptr [ebp-72]
	push      ecx
	call      @@__bitptr_hdrcoder@DeCode_ptrDict$qqspult1t1
	and       eax,255
	add       ebx,eax
	mov       edx,dword ptr [edi]
	push      edx
	mov       ecx,esi
	sub       ecx,dword ptr [ebp-60]
	push      ecx
	push      esi
	call      @ptrEql
	add       esi,dword ptr [edi]
	jmp       short @55
@52:
	push      ebx
	push      edi
	lea       eax,dword ptr [ebp-64]
	push      eax
	lea       edx,dword ptr [ebp-72]
	push      edx
	call      @@__bitptr_hdrcoder@DeCode_ptrBrun$qqspult1t1
	xor       ecx,ecx
	mov       cl,al
	mov       eax,dword ptr [edi]
	push      eax
	add       ebx,ecx
	mov       dl,byte ptr [ebp-64]
	push      edx
	push      ebx
	push      esi
	call      @ptrSetEx
	add       ebx,dword ptr [ebp-64]
	mov       ecx,dword ptr [ebp-64]
	imul      ecx,dword ptr [edi]
	add       esi,ecx
@55:
	cmp       esi,dword ptr [ebp-52]
	jb        @47
?live16393@480: ; 
@48:
	dec       dword ptr [ebp-20]
	push      2
	lea       eax,dword ptr [ebp-12]
	push      eax
	call      @@TSoft_Huff@$bdtr$qqsv
	mov       edx,dword ptr [ebp-48]
	mov       dword ptr fs:[0],edx
@56:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       12
@UnCompress_LZS	endp
UnCompress_LZS	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCOC$@Compress_HUF$qqspvt1ulus	segment virtual
	align	2
@@_$DCOC$@Compress_HUF$qqspvt1ulus	label	dword
	dd	@@$xt$10TSoft_Huff
	dd	4
	dd	-12
	dd	0
	dd	@@$xt$10TSoft_Huff
	dd	4
	dd	-12
	dd	0
@_$DCOC$@Compress_HUF$qqspvt1ulus	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTPC$@Compress_HUF$qqspvt1ulus	segment virtual
	align	2
@@_$ECTPC$@Compress_HUF$qqspvt1ulus	label	dword
	dd	0
	dd	-48
	dw	0
	dw	5
	dd	0
	dd	@@_$DCOC$@Compress_HUF$qqspvt1ulus+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCOC$@Compress_HUF$qqspvt1ulus
@_$ECTPC$@Compress_HUF$qqspvt1ulus	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
Compress_HUF	segment virtual
	align	2
@Compress_HUF	proc	near
?live16396@0:
@57:
	push      ebp
	mov       ebp,esp
	add       esp,-52
	mov       eax,offset @@_$ECTPC$@Compress_HUF$qqspvt1ulus
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+12]
	call      @__InitExceptBlockLDTC
?live16396@16: ; EBX = alpSrc
	mov       eax,ebx
	mov       esi,eax
?live16396@32: ; ESI = ptrs, EBX = alpSrc, EAX = @temp6
	add       eax,dword ptr [ebp+16]
	mov       dword ptr [ebp-52],eax
?live16396@48: ; EBX = ptrd_bit, ESI = ptrs, EDI = ptrd
	lea       eax,dword ptr [ebp-12]
?live16396@64: ; ESI = ptrs
	mov       edi,dword ptr [ebp+8]
?live16396@80: ; ESI = ptrs, EDI = ptrd
	xor       ebx,ebx
?live16396@96: ; EBX = ptrd_bit, ESI = ptrs, EDI = ptrd
	mov       word ptr [ebp-32],8
	push      eax
	call      @@TSoft_Huff@$bctr$qqsv
	inc       dword ptr [ebp-20]
	lea       edx,dword ptr [ebp-12]
	mov       word ptr [ebp-32],20
	push      edx
	call      @@TSoft_Huff@Initialize$qqsv
	cmp       esi,dword ptr [ebp-52]
	jae       short @59
@58:
	mov       cl,byte ptr [esi]
	push      ecx
	push      ebx
	push      edi
	lea       eax,dword ptr [ebp-12]
	push      eax
	call      @@TSoft_Huff@Encode$qqspucucuc
	add       bl,al
	xor       edx,edx
	mov       dl,bl
	and       bl,7
	sar       edx,3
	inc       esi
	add       edi,edx
	cmp       esi,dword ptr [ebp-52]
	jb        short @58
?live16396@288: ; EBX = ptrd_bit, EDI = ptrd
@59:
	xor       ecx,ecx
	mov       cl,bl
	mov       eax,32
	sub       eax,ecx
	push      eax
	push      0
	push      offset s@
	push      ebx
	push      edi
	call      @bitEql
?live16396@304: ; EDI = ptrd
	add       edi,4
	lea       edx,dword ptr [ebp-12]
	mov       eax,edi
	sub       eax,dword ptr [ebp+8]
	push      eax
	dec       dword ptr [ebp-20]
	push      2
	push      edx
	call      @@TSoft_Huff@$bdtr$qqsv
	pop       eax
	mov       edx,dword ptr [ebp-48]
	mov       dword ptr fs:[0],edx
?live16396@336: ; 
@62:
@61:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       16
@Compress_HUF	endp
Compress_HUF	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCQC$@UnCompress_HUF$qqspvult1	segment virtual
	align	2
@@_$DCQC$@UnCompress_HUF$qqspvult1	label	dword
	dd	@@$xt$10TSoft_Huff
	dd	4
	dd	-12
	dd	0
	dd	@@$xt$10TSoft_Huff
	dd	4
	dd	-12
	dd	0
@_$DCQC$@UnCompress_HUF$qqspvult1	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTRC$@UnCompress_HUF$qqspvult1	segment virtual
	align	2
@@_$ECTRC$@UnCompress_HUF$qqspvult1	label	dword
	dd	0
	dd	-48
	dw	0
	dw	5
	dd	0
	dd	@@_$DCQC$@UnCompress_HUF$qqspvult1+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCQC$@UnCompress_HUF$qqspvult1
@_$ECTRC$@UnCompress_HUF$qqspvult1	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
UnCompress_HUF	segment virtual
	align	2
@UnCompress_HUF	proc	near
?live16399@0:
@63:
	push      ebp
	mov       ebp,esp
	add       esp,-52
	mov       eax,offset @@_$ECTRC$@UnCompress_HUF$qqspvult1
	push      ebx
	push      esi
	push      edi
	call      @__InitExceptBlockLDTC
?live16399@16: ; EBX = ptrs_bit, EDI = ptrs
	mov       eax,dword ptr [ebp+8]
?live16399@32: ; EDI = ptrs
	xor       ebx,ebx
?live16399@48: ; EBX = ptrs_bit, EDI = ptrs
	mov       esi,eax
?live16399@64: ; 
	mov       edi,dword ptr [ebp+16]
?live16399@80: ; EBX = ptrs_bit, ESI = ptrd, EDI = ptrs, EAX = @temp5
	add       eax,dword ptr [ebp+12]
	mov       dword ptr [ebp-52],eax
?live16399@96: ; EBX = ptrs_bit, ESI = ptrd, EDI = ptrs
	lea       eax,dword ptr [ebp-12]
	mov       word ptr [ebp-32],8
	push      eax
	call      @@TSoft_Huff@$bctr$qqsv
	inc       dword ptr [ebp-20]
	lea       edx,dword ptr [ebp-12]
	mov       word ptr [ebp-32],20
	push      edx
	call      @@TSoft_Huff@Initialize$qqsv
	cmp       esi,dword ptr [ebp-52]
	jae       short @65
@64:
	push      ebx
	push      edi
	push      esi
	lea       ecx,dword ptr [ebp-12]
	push      ecx
	call      @@TSoft_Huff@Decode$qqspuct1uc
	add       bl,al
	xor       eax,eax
	mov       al,bl
	and       bl,7
	sar       eax,3
	inc       esi
	add       edi,eax
	cmp       esi,dword ptr [ebp-52]
	jb        short @64
?live16399@288: ; 
@65:
	dec       dword ptr [ebp-20]
	push      2
	lea       edx,dword ptr [ebp-12]
	push      edx
	call      @@TSoft_Huff@$bdtr$qqsv
	mov       ecx,dword ptr [ebp-48]
	mov       dword ptr fs:[0],ecx
@67:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       12
@UnCompress_HUF	endp
UnCompress_HUF	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCSC$@Compress_ARI$qqspvt1ulus	segment virtual
	align	2
@@_$DCSC$@Compress_ARI$qqspvt1ulus	label	dword
	dd	@@$xt$9TSoft_Ari
	dd	4
	dd	-32
	dd	0
	dd	@@$xt$9TSoft_Ari
	dd	4
	dd	-32
	dd	0
@_$DCSC$@Compress_ARI$qqspvt1ulus	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTTC$@Compress_ARI$qqspvt1ulus	segment virtual
	align	2
@@_$ECTTC$@Compress_ARI$qqspvt1ulus	label	dword
	dd	0
	dd	-68
	dw	0
	dw	5
	dd	0
	dd	@@_$DCSC$@Compress_ARI$qqspvt1ulus+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCSC$@Compress_ARI$qqspvt1ulus
@_$ECTTC$@Compress_ARI$qqspvt1ulus	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
Compress_ARI	segment virtual
	align	2
@Compress_ARI	proc	near
?live16402@0:
@68:
	push      ebp
	mov       ebp,esp
	add       esp,-72
	mov       eax,offset @@_$ECTTC$@Compress_ARI$qqspvt1ulus
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+12]
	call      @__InitExceptBlockLDTC
?live16402@16: ; EBX = alpSrc
	mov       eax,ebx
	mov       esi,eax
?live16402@32: ; ESI = ptrs, EBX = alpSrc, EAX = @temp6
	add       eax,dword ptr [ebp+16]
	mov       dword ptr [ebp-72],eax
?live16402@48: ; EBX = ptrd_bit, ESI = ptrs, EDI = ptrd
	lea       eax,dword ptr [ebp-32]
?live16402@64: ; ESI = ptrs
	mov       edi,dword ptr [ebp+8]
?live16402@80: ; ESI = ptrs, EDI = ptrd
	xor       ebx,ebx
?live16402@96: ; EBX = ptrd_bit, ESI = ptrs, EDI = ptrd
	mov       word ptr [ebp-52],8
	push      eax
	call      @@TSoft_Ari@$bctr$qqsv
	inc       dword ptr [ebp-40]
	lea       edx,dword ptr [ebp-32]
	mov       word ptr [ebp-52],20
	push      edx
	call      @@TSoft_Ari@Initialize_Encoder$qqsv
	cmp       esi,dword ptr [ebp-72]
	jae       short @70
@69:
	mov       cl,byte ptr [esi]
	push      ecx
	push      ebx
	push      edi
	lea       eax,dword ptr [ebp-32]
	push      eax
	call      @@TSoft_Ari@Encode$qqspulucuc
	add       bl,al
	xor       edx,edx
	mov       dl,bl
	and       bl,7
	sar       edx,3
	inc       esi
	add       edi,edx
	cmp       esi,dword ptr [ebp-72]
	jb        short @69
?live16402@288: ; EBX = ptrd_bit, EDI = ptrd
@70:
	push      ebx
	push      edi
	lea       ecx,dword ptr [ebp-32]
	push      ecx
	call      @@TSoft_Ari@Flush_Encoder$qqspuluc
	add       bl,al
	xor       eax,eax
	mov       al,bl
?live16402@320: ; EDI = ptrd
	lea       edx,dword ptr [ebp-32]
?live16402@336: ; EBX = ptrd_bit, EDI = ptrd
	sar       eax,3
	add       edi,eax
?live16402@352: ; EDI = ptrd
	mov       eax,edi
	sub       eax,dword ptr [ebp+8]
	push      eax
	dec       dword ptr [ebp-40]
	push      2
	push      edx
	call      @@TSoft_Ari@$bdtr$qqsv
	pop       eax
	mov       edx,dword ptr [ebp-68]
	mov       dword ptr fs:[0],edx
?live16402@368: ; 
@73:
@72:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       16
@Compress_ARI	endp
Compress_ARI	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCUC$@UnCompress_ARI$qqspvult1	segment virtual
	align	2
@@_$DCUC$@UnCompress_ARI$qqspvult1	label	dword
	dd	@@$xt$9TSoft_Ari
	dd	4
	dd	-32
	dd	0
	dd	@@$xt$9TSoft_Ari
	dd	4
	dd	-32
	dd	0
@_$DCUC$@UnCompress_ARI$qqspvult1	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTVC$@UnCompress_ARI$qqspvult1	segment virtual
	align	2
@@_$ECTVC$@UnCompress_ARI$qqspvult1	label	dword
	dd	0
	dd	-68
	dw	0
	dw	5
	dd	0
	dd	@@_$DCUC$@UnCompress_ARI$qqspvult1+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCUC$@UnCompress_ARI$qqspvult1
@_$ECTVC$@UnCompress_ARI$qqspvult1	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
UnCompress_ARI	segment virtual
	align	2
@UnCompress_ARI	proc	near
?live16406@0:
@74:
	push      ebp
	mov       ebp,esp
	add       esp,-72
	mov       eax,offset @@_$ECTVC$@UnCompress_ARI$qqspvult1
	push      ebx
	push      esi
	push      edi
	call      @__InitExceptBlockLDTC
?live16406@16: ; EBX = ptrs_bit, EDI = ptrs
	mov       eax,dword ptr [ebp+8]
?live16406@32: ; EDI = ptrs
	xor       ebx,ebx
?live16406@48: ; EBX = ptrs_bit, EDI = ptrs
	mov       esi,eax
?live16406@64: ; 
	mov       edi,dword ptr [ebp+16]
?live16406@80: ; EBX = ptrs_bit, ESI = ptrd, EDI = ptrs, EAX = @temp5
	add       eax,dword ptr [ebp+12]
	mov       dword ptr [ebp-72],eax
?live16406@96: ; EBX = ptrs_bit, ESI = ptrd, EDI = ptrs
	lea       eax,dword ptr [ebp-32]
	mov       word ptr [ebp-52],8
	push      eax
	call      @@TSoft_Ari@$bctr$qqsv
	inc       dword ptr [ebp-40]
	lea       edx,dword ptr [ebp-32]
	mov       word ptr [ebp-52],20
	push      ebx
	push      edi
	push      edx
	call      @@TSoft_Ari@Initialize_Decoder$qqspuluc
	add       bl,al
	xor       ecx,ecx
	mov       cl,bl
	sar       ecx,3
	add       edi,ecx
	and       bl,7
	cmp       esi,dword ptr [ebp-72]
	jae       short @76
@75:
	push      ebx
	push      edi
	push      esi
	lea       eax,dword ptr [ebp-32]
	push      eax
	call      @@TSoft_Ari@Decode$qqspucpuluc
	add       bl,al
	xor       edx,edx
	mov       dl,bl
	and       bl,7
	sar       edx,3
	inc       esi
	add       edi,edx
	cmp       esi,dword ptr [ebp-72]
	jb        short @75
?live16406@320: ; 
@76:
	dec       dword ptr [ebp-40]
	push      2
	lea       ecx,dword ptr [ebp-32]
	push      ecx
	call      @@TSoft_Ari@$bdtr$qqsv
	mov       eax,dword ptr [ebp-68]
	mov       dword ptr fs:[0],eax
@78:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       12
@UnCompress_ARI	endp
UnCompress_ARI	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCWC$@Cript_MTF$qqspvul	segment virtual
	align	2
@@_$DCWC$@Cript_MTF$qqspvul	label	dword
	dd	@@$xt$9TSoft_Mtf
	dd	4
	dd	-4
	dd	0
	dd	@@$xt$9TSoft_Mtf
	dd	4
	dd	-4
	dd	0
@_$DCWC$@Cript_MTF$qqspvul	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTXC$@Cript_MTF$qqspvul	segment virtual
	align	2
@@_$ECTXC$@Cript_MTF$qqspvul	label	dword
	dd	0
	dd	-40
	dw	0
	dw	5
	dd	0
	dd	@@_$DCWC$@Cript_MTF$qqspvul+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCWC$@Cript_MTF$qqspvul
@_$ECTXC$@Cript_MTF$qqspvul	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
Cript_MTF	segment virtual
	align	2
@Cript_MTF	proc	near
?live16409@0:
@79:
	push      ebp
	mov       ebp,esp
	add       esp,-40
	mov       eax,offset @@_$ECTXC$@Cript_MTF$qqspvul
	push      ebx
	push      esi
	push      edi
	mov       esi,dword ptr [ebp+8]
	call      @__InitExceptBlockLDTC
?live16409@16: ; ESI = alpDst
	mov       eax,esi
?live16409@32: ; EBX = ptrd, ESI = alpDst, EAX = @temp4
	mov       edi,eax
?live16409@48: ; ESI = alpDst
	mov       ebx,eax
?live16409@64: ; EBX = ptrd, ESI = alpDst, EAX = @temp4
	add       edi,dword ptr [ebp+12]
?live16409@80: ; EBX = ptrd, EDI = ptrd_end
	lea       eax,dword ptr [ebp-4]
	mov       word ptr [ebp-24],8
	push      eax
	call      @@TSoft_Mtf@$bctr$qqsv
	inc       dword ptr [ebp-12]
	lea       edx,dword ptr [ebp-4]
	mov       word ptr [ebp-24],20
	push      edx
	call      @@TSoft_Mtf@Initialize$qqsv
	cmp       edi,ebx
	jbe       short @81
@80:
	mov       esi,ebx
	mov       al,byte ptr [esi]
	push      eax
	lea       edx,dword ptr [ebp-4]
	push      edx
	call      @@TSoft_Mtf@Encode$qqsuc
	mov       byte ptr [esi],al
	inc       ebx
	cmp       edi,ebx
	ja        short @80
?live16409@192: ; 
@81:
	dec       dword ptr [ebp-12]
	push      2
	lea       ecx,dword ptr [ebp-4]
	push      ecx
	call      @@TSoft_Mtf@$bdtr$qqsv
	mov       eax,dword ptr [ebp-40]
	mov       dword ptr fs:[0],eax
@83:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       8
@Cript_MTF	endp
Cript_MTF	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCYC$@UnCript_MTF$qqspvul	segment virtual
	align	2
@@_$DCYC$@UnCript_MTF$qqspvul	label	dword
	dd	@@$xt$9TSoft_Mtf
	dd	4
	dd	-4
	dd	0
	dd	@@$xt$9TSoft_Mtf
	dd	4
	dd	-4
	dd	0
@_$DCYC$@UnCript_MTF$qqspvul	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTZC$@UnCript_MTF$qqspvul	segment virtual
	align	2
@@_$ECTZC$@UnCript_MTF$qqspvul	label	dword
	dd	0
	dd	-40
	dw	0
	dw	5
	dd	0
	dd	@@_$DCYC$@UnCript_MTF$qqspvul+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCYC$@UnCript_MTF$qqspvul
@_$ECTZC$@UnCript_MTF$qqspvul	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
UnCript_MTF	segment virtual
	align	2
@UnCript_MTF	proc	near
?live16413@0:
@84:
	push      ebp
	mov       ebp,esp
	add       esp,-40
	mov       eax,offset @@_$ECTZC$@UnCript_MTF$qqspvul
	push      ebx
	push      esi
	push      edi
	mov       esi,dword ptr [ebp+8]
	call      @__InitExceptBlockLDTC
?live16413@16: ; ESI = alpDst
	mov       eax,esi
?live16413@32: ; EBX = ptrd, ESI = alpDst, EAX = @temp4
	mov       edi,eax
?live16413@48: ; ESI = alpDst
	mov       ebx,eax
?live16413@64: ; EBX = ptrd, ESI = alpDst, EAX = @temp4
	add       edi,dword ptr [ebp+12]
?live16413@80: ; EBX = ptrd, EDI = ptrd_end
	lea       eax,dword ptr [ebp-4]
	mov       word ptr [ebp-24],8
	push      eax
	call      @@TSoft_Mtf@$bctr$qqsv
	inc       dword ptr [ebp-12]
	lea       edx,dword ptr [ebp-4]
	mov       word ptr [ebp-24],20
	push      edx
	call      @@TSoft_Mtf@Initialize$qqsv
	cmp       edi,ebx
	jbe       short @86
@85:
	mov       esi,ebx
	mov       al,byte ptr [esi]
	push      eax
	lea       edx,dword ptr [ebp-4]
	push      edx
	call      @@TSoft_Mtf@Decode$qqsuc
	mov       byte ptr [esi],al
	inc       ebx
	cmp       edi,ebx
	ja        short @85
?live16413@192: ; 
@86:
	dec       dword ptr [ebp-12]
	push      2
	lea       ecx,dword ptr [ebp-4]
	push      ecx
	call      @@TSoft_Mtf@$bdtr$qqsv
	mov       eax,dword ptr [ebp-40]
	mov       dword ptr fs:[0],eax
@88:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       8
@UnCript_MTF	endp
UnCript_MTF	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
Cript_XOR	segment virtual
	align	2
@Cript_XOR	proc	near
?live16416@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
@89:
	mov	 EDI,dword ptr [ebp+8]
	mov	 EDX,EDI
	add	 EDX,dword ptr [ebp+12]
	cmp	 EDI,EDX
	jge       @90
	mov	 ESI,dword ptr [ebp+16]
	movzx	 ECX,byte ptr [ebp+20]
	add	 ECX,ESI
	cmp	 ESI,ECX
	jge       @90
	mov	 EBX,ESI
@91:
Cript_XOR_LOOP:
	mov	 AL,[ESI]
	xor	 [EDI],AL
	inc	 ESI
	cmp	 ESI,ECX
	jl        short @92
	mov	 ESI,EBX
@92:
Cript_XOR_PASS:
	inc	 EDI
	cmp	 EDI,EDX
	jl        @91
	mov	 ESI,EBX
@90:
Cript_XOR_EXIT:
@93:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       16
@Cript_XOR	endp
Cript_XOR	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
UnCript_XOR	segment virtual
	align	2
@UnCript_XOR	proc	near
?live16417@0:
@94:
	push      ebp
	mov       ebp,esp
	mov       al,byte ptr [ebp+20]
	push      eax
	mov       edx,dword ptr [ebp+16]
	push      edx
	mov       ecx,dword ptr [ebp+12]
	push      ecx
	mov       eax,dword ptr [ebp+8]
	push      eax
	call      @Cript_XOR
@95:
	pop       ebp
	ret       16
@UnCript_XOR	endp
UnCript_XOR	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
Cript_SXQ	segment virtual
	align	2
@Cript_SXQ	proc	near
?live16418@0:
@96:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
	mov       eax,dword ptr [ebp+16]
	mov       edi,dword ptr [ebp+8]
?live16418@16: ; EDI = alpDst, EAX = aHaslo_count
	cmp       al,1
	jbe       short @98
?live16418@32: ; 
	xor       ebx,ebx
	mov       bl,al
?live16418@48: ; EBX = buff_count, EDI = alpDst
	movzx     esi,bx
?live16418@64: ; EBX = buff_count, ESI = @temp1, EDI = alpDst
	mov       eax,esi
	inc       eax
	push      eax
	call      @strAlloc
?live16418@80: ; EBX = buff_count, ESI = @temp1, EDI = alpDst, EAX = buff_ptr
	push      eax
	call      @strFree
?live16418@96: ; 
@99:
@98:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
@Cript_SXQ	endp
Cript_SXQ	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
UnCript_SXQ	segment virtual
	align	2
@UnCript_SXQ	proc	near
?live16419@0:
@100:
	push      ebp
	mov       ebp,esp
	mov       al,byte ptr [ebp+16]
	push      eax
	mov       edx,dword ptr [ebp+12]
	push      edx
	mov       ecx,dword ptr [ebp+8]
	push      ecx
	call      @Cript_SXQ
@101:
	pop       ebp
	ret       12
@UnCript_SXQ	endp
UnCript_SXQ	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@_$DCAD$@Compress_BWT$qqspvt1ulus	segment virtual
	align	2
@@_$DCAD$@Compress_BWT$qqspvt1ulus	label	dword
	dd	@@$xt$15TSoft_BWTMatrix
	dd	4
	dd	-28
	dd	0
	dd	@@$xt$15TSoft_BWTMatrix
	dd	4
	dd	-28
	dd	0
@_$DCAD$@Compress_BWT$qqspvt1ulus	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@_$ECTBD$@Compress_BWT$qqspvt1ulus	segment virtual
	align	2
@@_$ECTBD$@Compress_BWT$qqspvt1ulus	label	dword
	dd	0
	dd	-64
	dw	0
	dw	5
	dd	0
	dd	@@_$DCAD$@Compress_BWT$qqspvt1ulus+16
	dw	0
	dw	5
	dd	0
	dd	@@_$DCAD$@Compress_BWT$qqspvt1ulus
@_$ECTBD$@Compress_BWT$qqspvt1ulus	ends
_DATA	ends
_TEXT	segment dword public use32 'CODE'
Compress_BWT	segment virtual
	align	2
@Compress_BWT	proc	near
?live16420@0:
@102:
	push      ebp
	mov       ebp,esp
	add       esp,-64
	mov       eax,offset @@_$ECTBD$@Compress_BWT$qqspvt1ulus
	push      ebx
	push      esi
	push      edi
	mov       ebx,dword ptr [ebp+12]
	call      @__InitExceptBlockLDTC
?live16420@16: ; EBX = alpSrc
	mov       eax,ebx
	mov       esi,eax
?live16420@32: ; ESI = ptrs, EBX = alpSrc, EAX = @temp6
	mov       edi,eax
	add       edi,dword ptr [ebp+16]
?live16420@48: ; ESI = ptrs, EDI = ptrs_end
	mov       ebx,dword ptr [ebp+8]
?live16420@64: ; EBX = ptrd, ESI = ptrs, EDI = ptrs_end
	mov       word ptr [ebp-48],8
	movzx     eax,word ptr [ebp+20]
	push      eax
	lea       edx,dword ptr [ebp-28]
	push      edx
	call      @@TSoft_BWTMatrix@$bctr$qqsul
	inc       dword ptr [ebp-36]
	mov       word ptr [ebp-48],20
	mov       cx,word ptr [ebp-20]
	mov       word ptr [ebx],cx
	add       ebx,2
	jmp       short @104
@103:
	push      esi
	lea       eax,dword ptr [ebp-28]
	push      eax
	call      @@TSoft_BWTMatrix@Generate$qqspuc
	add       esi,dword ptr [ebp-20]
	lea       edx,dword ptr [ebp-28]
	push      edx
	call      @@TSoft_BWTMatrix@Sort$qqsv
	mov       word ptr [ebx],ax
	add       ebx,2
	push      ebx
	lea       ecx,dword ptr [ebp-28]
	push      ecx
	call      @@TSoft_BWTMatrix@Flush$qqspuc
	add       ebx,dword ptr [ebp-20]
@104:
	mov       eax,edi
	sub       eax,dword ptr [ebp-20]
	cmp       esi,eax
	jbe       short @103
	mov       word ptr [ebx],0
	add       ebx,2
	cmp       edi,esi
	jbe       short @106
@105:
	mov       dl,byte ptr [esi]
	inc       esi
	mov       byte ptr [ebx],dl
	inc       ebx
	cmp       edi,esi
	ja        short @105
?live16420@304: ; EBX = ptrd
@106:
	mov       eax,ebx
	lea       edx,dword ptr [ebp-28]
	sub       eax,dword ptr [ebp+8]
	push      eax
	dec       dword ptr [ebp-36]
	push      2
	push      edx
	call      @@TSoft_BWTMatrix@$bdtr$qqsv
	pop       eax
	mov       edx,dword ptr [ebp-64]
	mov       dword ptr fs:[0],edx
?live16420@320: ; 
@108:
@107:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret       16
@Compress_BWT	endp
Compress_BWT	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
UnCompress_BWT	segment virtual
	align	2
@UnCompress_BWT	proc	near
?live16424@0:
@109:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       eax,dword ptr [ebp+8]
	mov       edx,dword ptr [ebp+12]
?live16424@16: ; EAX = alpDst, EDX = acount, ECX = alpSrc
	mov       ebx,eax
?live16424@32: ; 
	mov       ecx,dword ptr [ebp+16]
?live16424@48: ; EAX = alpDst, EDX = acount, ECX = alpSrc, EBX = @temp3
	mov       ebx,edx
	add       ebx,ebx
	shr       ebx,10
	sub       edx,ebx
	sub       edx,2
	push      edx
	push      ecx
	push      eax
	call      @ptrEql
?live16424@64: ; 
@110:
	pop       ebx
	pop       ebp
	ret       12
@UnCompress_BWT	endp
UnCompress_BWT	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$15TSoft_BWTMatrix	segment virtual
	align	2
@@$xt$15TSoft_BWTMatrix	label	byte
	dd	28
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	64
	dw	68
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@TSoft_BWTMatrix@$bdtr$qqsv
	dw	5
	dw	72
	db	84
	db	83
	db	111
	db	102
	db	116
	db	95
	db	66
	db	87
	db	84
	db	77
	db	97
	db	116
	db	114
	db	105
	db	120
	db	0
	dd	0
	dd	0
	dd	0
@$xt$15TSoft_BWTMatrix	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$9TSoft_Mtf	segment virtual
	align	2
@@$xt$9TSoft_Mtf	label	byte
	dd	4
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	60
	dw	64
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@TSoft_Mtf@$bdtr$qqsv
	dw	5
	dw	68
	db	84
	db	83
	db	111
	db	102
	db	116
	db	95
	db	77
	db	116
	db	102
	db	0
	db	0
	db	0
	dd	0
	dd	0
	dd	0
@$xt$9TSoft_Mtf	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$9TSoft_Ari	segment virtual
	align	2
@@$xt$9TSoft_Ari	label	byte
	dd	32
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	60
	dw	64
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@TSoft_Ari@$bdtr$qqsv
	dw	5
	dw	68
	db	84
	db	83
	db	111
	db	102
	db	116
	db	95
	db	65
	db	114
	db	105
	db	0
	db	0
	db	0
	dd	0
	dd	0
	dd	0
@$xt$9TSoft_Ari	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$13TSoft_BinTree	segment virtual
	align	2
@@$xt$13TSoft_BinTree	label	byte
	dd	64
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	64
	dw	68
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@TSoft_BinTree@$bdtr$qqsv
	dw	5
	dw	72
	db	84
	db	83
	db	111
	db	102
	db	116
	db	95
	db	66
	db	105
	db	110
	db	84
	db	114
	db	101
	db	101
	db	0
	db	0
	db	0
	dd	0
	dd	0
	dd	0
@$xt$13TSoft_BinTree	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@$xt$10TSoft_Huff	segment virtual
	align	2
@@$xt$10TSoft_Huff	label	byte
	dd	12
	dw	3
	dw	48
	dd	-1
	dd	3
	dw	60
	dw	64
	dd	0
	dw	0
	dw	0
	dd	0
	dd	1
	dd	1
	dd	@@TSoft_Huff@$bdtr$qqsv
	dw	5
	dw	68
	db	84
	db	83
	db	111
	db	102
	db	116
	db	95
	db	72
	db	117
	db	102
	db	102
	db	0
	db	0
	dd	0
	dd	0
	dd	0
@$xt$10TSoft_Huff	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
s@	label	byte
	db	0,0,0,0,0
	align	4
_DATA	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
@_memset equ _memset
 extrn   _memset:near
@@TSoft_Huff@$bctr$qqsv equ @TSoft_Huff@$bctr$qqsv
 extrn   @TSoft_Huff@$bctr$qqsv:near
@@TSoft_Huff@Initialize$qqsv equ @TSoft_Huff@Initialize$qqsv
 extrn   @TSoft_Huff@Initialize$qqsv:near
@@TSoft_BinTree@$bctr$qqsulul equ @TSoft_BinTree@$bctr$qqsulul
 extrn   @TSoft_BinTree@$bctr$qqsulul:near
@@TSoft_BinTree@Initialize$qqspuc equ @TSoft_BinTree@Initialize$qqspuc
 extrn   @TSoft_BinTree@Initialize$qqspuc:near
@@TSoft_BinTree@Update$qqspucul equ @TSoft_BinTree@Update$qqspucul
 extrn   @TSoft_BinTree@Update$qqspucul:near
@@TSoft_BinTree@Search_brun$qqsv equ @TSoft_BinTree@Search_brun$qqsv
 extrn   @TSoft_BinTree@Search_brun$qqsv:near
@@TSoft_BinTree@Optimum_brun_match$qqsulul equ @TSoft_BinTree@Optimum_brun_match$qqsulul
 extrn   @TSoft_BinTree@Optimum_brun_match$qqsulul:near
@@TSoft_BinTree@Search_dict$qqsv equ @TSoft_BinTree@Search_dict$qqsv
 extrn   @TSoft_BinTree@Search_dict$qqsv:near
@@TSoft_BinTree@Optimum_dict_match$qqsulul equ @TSoft_BinTree@Optimum_dict_match$qqsulul
 extrn   @TSoft_BinTree@Optimum_dict_match$qqsulul:near
@@__bitptr_hdrcoder@Code_ptrPass$qqspulul equ @__bitptr_hdrcoder@Code_ptrPass$qqspulul
 extrn   @__bitptr_hdrcoder@Code_ptrPass$qqspulul:near
@ptrEql equ ptrEql
 extrn   ptrEql:near
@@__bitptr_hdrcoder@Code_ptrBrun$qqspululul equ @__bitptr_hdrcoder@Code_ptrBrun$qqspululul
 extrn   @__bitptr_hdrcoder@Code_ptrBrun$qqspululul:near
@@__bitptr_hdrcoder@Code_ptrDict$qqspululul equ @__bitptr_hdrcoder@Code_ptrDict$qqspululul
 extrn   @__bitptr_hdrcoder@Code_ptrDict$qqspululul:near
@@TSoft_BinTree@$bdtr$qqsv equ @TSoft_BinTree@$bdtr$qqsv
 extrn   @TSoft_BinTree@$bdtr$qqsv:near
@@TSoft_Huff@$bdtr$qqsv equ @TSoft_Huff@$bdtr$qqsv
 extrn   @TSoft_Huff@$bdtr$qqsv:near
 extrn   __Exception_list:dword
 extrn   @__InitExceptBlockLDTC:near
@@__bitptr_hdrcoder@DeCode_ptrPass$qqspult1 equ @__bitptr_hdrcoder@DeCode_ptrPass$qqspult1
 extrn   @__bitptr_hdrcoder@DeCode_ptrPass$qqspult1:near
@@__bitptr_hdrcoder@DeCode_ptrDict$qqspult1t1 equ @__bitptr_hdrcoder@DeCode_ptrDict$qqspult1t1
 extrn   @__bitptr_hdrcoder@DeCode_ptrDict$qqspult1t1:near
@@__bitptr_hdrcoder@DeCode_ptrBrun$qqspult1t1 equ @__bitptr_hdrcoder@DeCode_ptrBrun$qqspult1t1
 extrn   @__bitptr_hdrcoder@DeCode_ptrBrun$qqspult1t1:near
@ptrSetEx equ ptrSetEx
 extrn   ptrSetEx:near
@@TSoft_Huff@Encode$qqspucucuc equ @TSoft_Huff@Encode$qqspucucuc
 extrn   @TSoft_Huff@Encode$qqspucucuc:near
@bitEql equ bitEql
 extrn   bitEql:near
@@TSoft_Huff@Decode$qqspuct1uc equ @TSoft_Huff@Decode$qqspuct1uc
 extrn   @TSoft_Huff@Decode$qqspuct1uc:near
@@TSoft_Ari@$bctr$qqsv equ @TSoft_Ari@$bctr$qqsv
 extrn   @TSoft_Ari@$bctr$qqsv:near
@@TSoft_Ari@Initialize_Encoder$qqsv equ @TSoft_Ari@Initialize_Encoder$qqsv
 extrn   @TSoft_Ari@Initialize_Encoder$qqsv:near
@@TSoft_Ari@Encode$qqspulucuc equ @TSoft_Ari@Encode$qqspulucuc
 extrn   @TSoft_Ari@Encode$qqspulucuc:near
@@TSoft_Ari@Flush_Encoder$qqspuluc equ @TSoft_Ari@Flush_Encoder$qqspuluc
 extrn   @TSoft_Ari@Flush_Encoder$qqspuluc:near
@@TSoft_Ari@$bdtr$qqsv equ @TSoft_Ari@$bdtr$qqsv
 extrn   @TSoft_Ari@$bdtr$qqsv:near
@@TSoft_Ari@Initialize_Decoder$qqspuluc equ @TSoft_Ari@Initialize_Decoder$qqspuluc
 extrn   @TSoft_Ari@Initialize_Decoder$qqspuluc:near
@@TSoft_Ari@Decode$qqspucpuluc equ @TSoft_Ari@Decode$qqspucpuluc
 extrn   @TSoft_Ari@Decode$qqspucpuluc:near
@@TSoft_Mtf@$bctr$qqsv equ @TSoft_Mtf@$bctr$qqsv
 extrn   @TSoft_Mtf@$bctr$qqsv:near
@@TSoft_Mtf@Initialize$qqsv equ @TSoft_Mtf@Initialize$qqsv
 extrn   @TSoft_Mtf@Initialize$qqsv:near
@@TSoft_Mtf@Encode$qqsuc equ @TSoft_Mtf@Encode$qqsuc
 extrn   @TSoft_Mtf@Encode$qqsuc:near
@@TSoft_Mtf@$bdtr$qqsv equ @TSoft_Mtf@$bdtr$qqsv
 extrn   @TSoft_Mtf@$bdtr$qqsv:near
@@TSoft_Mtf@Decode$qqsuc equ @TSoft_Mtf@Decode$qqsuc
 extrn   @TSoft_Mtf@Decode$qqsuc:near
@strAlloc equ strAlloc
 extrn   strAlloc:near
@strFree equ strFree
 extrn   strFree:near
@@TSoft_BWTMatrix@$bctr$qqsul equ @TSoft_BWTMatrix@$bctr$qqsul
 extrn   @TSoft_BWTMatrix@$bctr$qqsul:near
@@TSoft_BWTMatrix@Generate$qqspuc equ @TSoft_BWTMatrix@Generate$qqspuc
 extrn   @TSoft_BWTMatrix@Generate$qqspuc:near
@@TSoft_BWTMatrix@Sort$qqsv equ @TSoft_BWTMatrix@Sort$qqsv
 extrn   @TSoft_BWTMatrix@Sort$qqsv:near
@@TSoft_BWTMatrix@Flush$qqspuc equ @TSoft_BWTMatrix@Flush$qqspuc
 extrn   @TSoft_BWTMatrix@Flush$qqspuc:near
@@TSoft_BWTMatrix@$bdtr$qqsv equ @TSoft_BWTMatrix@$bdtr$qqsv
 extrn   @TSoft_BWTMatrix@$bdtr$qqsv:near
 ?debug  C 9F757569642E6C6962
 ?debug  C 9F757569642E6C6962
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSoft_Koder.h" 18791 20064
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSOFT_MTF.H" 18791 20064
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSOFT_ARI.H" 18791 20064
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSOFT_HUFF.H" 18791 20064
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSOFT_BINTREE.H" 18791 20064
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSOFT_HDR.H" 18058 42009
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSOFT_BWTMATRIX.H" 18791 20064
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\..\DLLIO\TSOFT_IO.H" 18817 26213
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\CONIO.H" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_nfile.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\STDIO.H" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\imm.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\mcx.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winsvc.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\commdlg.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\oleauto.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\propidl.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\oaidl.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\msxml.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\servprov.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\oleidl.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\urlmon.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\cguid.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\objidl.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\unknwn.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\search.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\stdlib.h" 10503 10272
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\objbase.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\ole2.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\prsht.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winspool.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winsmcrd.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winioctl.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcnsip.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcndr.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\wtypes.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winscard.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winefs.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\wincrypt.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\qos.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winsock2.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winperf.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\shellapi.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcasync.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcnterr.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcnsi.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcdcep.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpcdce.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\windows.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\rpc.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\nb30.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\mmsystem.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\lzexpand.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\dlgs.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\ddeml.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\dde.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\cderr.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winnetwk.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winreg.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winver.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\wincon.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winnls.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\tvout.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winuser.h" 18052 43723
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\pshpack1.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\wingdi.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winerror.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winbase.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\pshpack8.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\pshpack2.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\poppack.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\pshpack4.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_loc.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\locale.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_str.h" 10503 10272
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\string.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\guiddef.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\basetsd.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\mbctype.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\ctype.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\winnt.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\windef.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\stdarg.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\excpt.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_null.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_defs.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\_stddef.h" 10305 10240
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\mem.h" 10503 10272
	?debug	D "C:\PROGRAM FILES\BORLAND\CBUILDER5\INCLUDE\WINDOWS.H" 10305 10240
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSoft_Koder.cpp" 19509 27843
	end
