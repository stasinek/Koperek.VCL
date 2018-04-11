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
	?debug	S "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSoft_HDR.cpp"
	?debug	T "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSoft_HDR.cpp"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
DGROUP	group	_BSS,_DATA
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@Price_ptrPass$qqsul	segment virtual
	align	2
@@__bitptr_hdrcoder@Price_ptrPass$qqsul	proc	near
?live16385@0:
	push      ebp
	mov       ebp,esp
@1:
 	xor	 EAX,EAX                  		
 	mov	 EDX,dword ptr [ebp+12]     
 	bsr	 EAX,EDX               		
 	add	  AL,3+2                		
 	mov	  AH,AL                   		
	test	  AH,007H                 		
	setnz	 AH                      		
 	shr	  AL,3                  		
 	add	  AL,AH                   		
@2:
	pop       ebp
	ret       8
@@__bitptr_hdrcoder@Price_ptrPass$qqsul	endp
@__bitptr_hdrcoder@Price_ptrPass$qqsul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@Code_ptrPass$qqspulul	segment virtual
	align	2
@@__bitptr_hdrcoder@Code_ptrPass$qqspulul	proc	near
?live16386@0:
	push      ebp
	mov       ebp,esp
	push      esi
	push      edi
@3:
 	xor	 EAX,EAX                  		
 	xor	 ECX,ECX               		
 	xor	 EDX,EDX                  		
 	mov	 ESI,dword ptr [ebp+16]     
 	bsr	 ECX,ESI               		
 	btr	 ESI,ECX               		
 	mov	  DH,CL                  		
  	or	 EAX,ESI                  		
 	shl	 EAX,3                 		
  	or	  AL,DH                  		
 	shl	 EAX,2                 		
  	or	  AL,BYTE(000H)          		
 	mov	  CL,DH                  		
 	add	  CL,3+2                		
 	mov	  EDI,dword ptr [ebp+12]           		
 	mov	 [EDI+0],AL            		
 	cmp	  CL, 8                		
	jbe       short @4
 	mov	 [EDI+1],AH            		
 	cmp	  CL,16                		
@4:
     MCODE_XX:
 	mov	  AL,CL                   		
	test	  CL,007H                 		
	setnz	 CL                      		
 	shr	  AL,3                  		
 	add	  AL,CL                   		
@5:
	pop       edi
	pop       esi
	pop       ebp
	ret       12
@@__bitptr_hdrcoder@Code_ptrPass$qqspulul	endp
@__bitptr_hdrcoder@Code_ptrPass$qqspulul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@DeCode_ptrPass$qqspult1	segment virtual
	align	2
@@__bitptr_hdrcoder@DeCode_ptrPass$qqspult1	proc	near
?live16387@0:
	push      ebp
	mov       ebp,esp
	push      esi
	push      edi
@6:
 	xor	 EAX,EAX                  		
 	xor	 ECX,ECX                  		
 	xor	 EDX,EDX                  		
 	mov	 ESI,dword ptr [ebp+16]                   
 	mov	  AX,[ESI]               		
 	mov	  DH,AL                  		
 	shr	  DH,2                    		
 	and	  DH,007H               		
 	mov	  CL,DH                   		
 	add	  CL,3+2                  		
 	shr	 EAX,3+2                 		
 	mov	 EDI,dword ptr [ebp+12]	
 	mov	 ESI,000000001H          		
 	mov	  CL,DH                    	
 	shl	 ESI,CL                		
 	dec	 ESI                   		
 	and	 ESI,EAX                		
 	bts	 ESI,ECX                  		
 	mov	 [EDI],ESI                		
 	mov	  AL,DH                   		
 	add	  AL,3+2                  		
 	mov	  AH,AL                   		
	test	  AH,007H                 		
	setnz	 AH                      		
 	shr	  AL,3                  		
 	add	  AL,AH                   		
@7:
	pop       edi
	pop       esi
	pop       ebp
	ret       12
@@__bitptr_hdrcoder@DeCode_ptrPass$qqspult1	endp
@__bitptr_hdrcoder@DeCode_ptrPass$qqspult1	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@Price_ptrBrun$qqsulul	segment virtual
	align	2
@@__bitptr_hdrcoder@Price_ptrBrun$qqsulul	proc	near
?live16388@0:
	push      ebp
	mov       ebp,esp
@8:
 	xor	 EAX,EAX                  		
 	mov	 EDX,dword ptr [ebp+16]     
 	bsr	 EAX,EDX               		
 	add	  AL,3+2+2              		
 	mov	  AH,AL                   		
	test	  AH,007H                 		
	setnz	 AH                      		
 	shr	  AL,3                  		
 	add	  AL,AH                   		
@9:
	pop       ebp
	ret       12
@@__bitptr_hdrcoder@Price_ptrBrun$qqsulul	endp
@__bitptr_hdrcoder@Price_ptrBrun$qqsulul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@Code_ptrBrun$qqspululul	segment virtual
	align	2
@@__bitptr_hdrcoder@Code_ptrBrun$qqspululul	proc	near
?live16389@0:
	push      ebp
	mov       ebp,esp
	push      esi
	push      edi
@10:
 	xor	 EAX,EAX                  		
 	xor	 EDX,EDX                  		
 	xor	 ECX,ECX               		
 	mov	 ESI,dword ptr [ebp+20]     
 	bsr	 ECX,ESI               		
 	btr	 ESI,ECX               		
 	mov	  DH,CL                  		
  	or	 EAX,ESI                  		
 	mov	 ESI,dword ptr [ebp+16]     
 	dec	 ESI                    		
 	shl	 EAX,3                 		
  	or	  AL,DH                  		
 	shl	 EAX,2                 		
  	or	 EAX,ESI                  		
 	shl	 EAX,2                 		
  	or	  AL,BYTE(002H)          		
 	mov	  CL,DH                		
 	add	  CL,3+2+2              		
 	mov	  EDI,dword ptr [ebp+12]           		
 	mov	 [EDI+0],AL            		
 	cmp	  CL, 8                		
	jbe       short @11
 	mov	 [EDI+1],AH            		
 	cmp	  CL,16                		
@11:
     MCODE_XX:
 	mov	  AL,CL                   		
	test	  CL,007H                 		
	setnz	 CL                      		
 	shr	  AL,3                  		
 	add	  AL,CL                   		
@12:
	pop       edi
	pop       esi
	pop       ebp
	ret       16
@@__bitptr_hdrcoder@Code_ptrBrun$qqspululul	endp
@__bitptr_hdrcoder@Code_ptrBrun$qqspululul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@DeCode_ptrBrun$qqspult1t1	segment virtual
	align	2
@@__bitptr_hdrcoder@DeCode_ptrBrun$qqspult1t1	proc	near
?live16390@0:
	push      ebp
	mov       ebp,esp
	push      esi
	push      edi
@13:
 	xor	 EAX,EAX                  		
 	xor	 ECX,ECX                  		
 	xor	 EDX,EDX                  		
 	mov	 ESI,dword ptr [ebp+20]                   
 	mov	  AX,[ESI]               		
 	mov	  DH,AL                  		
 	shr	  DH,4                    		
 	and	  DH,007H               		
 	mov	 EDI,dword ptr [ebp+12]	
 	mov	  CL,AL                  		
 	shr	  CL,2                  		
 	and	  CL,003H                 		
 	inc	  CL                    		
 	mov	[EDI],ECX                 		
 	mov	  CL,DH                   		
 	add	  CL,3+2+2                		
 	shr	 EAX,3+2+2                		
 	mov	 EDI,dword ptr [ebp+16]	
 	mov	 ESI,000000001H          		
 	mov	  CL,DH                    	
 	shl	 ESI,CL                		
 	dec	 ESI                   		
 	and	 ESI,EAX                		
 	bts	 ESI,ECX                		
 	mov	 [EDI],ESI                		
 	mov	  AL,DH                   		
 	add	  AL,3+2+2                		
 	mov	  AH,AL                   		
	test	  AH,007H                 		
	setnz	 AH                      		
 	shr	  AL,3                  		
 	add	  AL,AH                   		
@14:
	pop       edi
	pop       esi
	pop       ebp
	ret       16
@@__bitptr_hdrcoder@DeCode_ptrBrun$qqspult1t1	endp
@__bitptr_hdrcoder@DeCode_ptrBrun$qqspult1t1	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@Price_ptrDict$qqsulul	segment virtual
	align	2
@@__bitptr_hdrcoder@Price_ptrDict$qqsulul	proc	near
?live16391@0:
	push      ebp
	mov       ebp,esp
	push      ebx
@15:
 	xor	 EBX,EBX               		
 	mov	 EDX,dword ptr [ebp+16]	    
 	bsr	 EBX,EDX               		
 	xor	 EAX,EAX                  		
 	mov	 EDX,dword ptr [ebp+12]	    
 	bsr	 EAX,EDX               		
 	add	  AL,BL              		    
 	add	  AL,3+4+2              		
 	mov	  AH,AL                   		
	test	  AH,007H                 		
	setnz	 AH                      		
 	shr	  AL,3                  		
 	add	  AL,AH                   		
@16:
	pop       ebx
	pop       ebp
	ret       12
@@__bitptr_hdrcoder@Price_ptrDict$qqsulul	endp
@__bitptr_hdrcoder@Price_ptrDict$qqsulul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@Code_ptrDict$qqspululul	segment virtual
	align	2
@@__bitptr_hdrcoder@Code_ptrDict$qqspululul	proc	near
?live16392@0:
	push      ebp
	mov       ebp,esp
	push      esi
	push      edi
@17:
 	xor	 EAX,EAX                  		
 	xor	 EDX,EDX                  		
 	xor	 ECX,ECX               		
 	mov	 ESI,dword ptr [ebp+20]     
 	bsr	 ECX,ESI               		
 	btr	 ESI,ECX               		
 	mov	  DH,CL                  		
  	or	 EAX,ESI                  		
 	xor	 ECX,ECX               		
 	mov	 ESI,dword ptr [ebp+16]     
 	bsr	 ECX,ESI               		
 	btr	 ESI,ECX               		
 	mov	  DL,CL                  		
 	shl	 EAX,CL                 		
  	or	 EAX,ESI                  		
 	shl	 EAX,3                 		
  	or	  AL,DH                  		
 	shl	 EAX,4                 		
  	or	  AL,DL                  		
 	shl	 EAX,2                 		
  	or	  AL,BYTE(001H)  		        
 	mov	  CL,DL                		
 	add	  CL,DH                		
 	add	  CL,3+4+2             		
 	mov	  EDI,dword ptr [ebp+12]           		
 	mov	 [EDI+0],AL            		
 	cmp	  CL, 8                		
	jbe       short @18
 	mov	 [EDI+1],AH            		
 	cmp	  CL,16                		
	jbe       short @18
 	shr	 EAX,16                  		
 	mov	 [EDI+2],AL            		
 	cmp	  CL,24                		
	jbe       short @18
 	mov	 [EDI+3],AH            		
 	cmp	  CL,32                		
@18:
     MCODE_XX:
 	mov	  AL,CL                   		
	test	  CL,007H                 		
	setnz	 CL                      		
 	shr	  AL,3                  		
 	add	  AL,CL                   		
@19:
	pop       edi
	pop       esi
	pop       ebp
	ret       16
@@__bitptr_hdrcoder@Code_ptrDict$qqspululul	endp
@__bitptr_hdrcoder@Code_ptrDict$qqspululul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__bitptr_hdrcoder@DeCode_ptrDict$qqspult1t1	segment virtual
	align	2
@@__bitptr_hdrcoder@DeCode_ptrDict$qqspult1t1	proc	near
?live16393@0:
	push      ebp
	mov       ebp,esp
	push      esi
	push      edi
@20:
 	xor	 EAX,EAX                  		
 	xor	 ECX,ECX                  		
 	xor	 EDX,EDX                  		
 	mov	 ESI,dword ptr [ebp+20]                   
 	mov	 EAX,[ESI]               		
 	mov	  CX,AX                  		
 	shr	  CX,2                    		
 	mov	  DL,CL                   		
 	and	  DL,00FH                 		
 	mov	  CX,AX                  		
 	shr	  CX,2+4                  		
 	mov	  DH,CL                   		
 	and	  DH,007H                		
 	mov	  CL,DH                   		
 	add	  CL,DL                   		
 	add	  CL,3+4+2                		
 	shr	 EAX,3+4+2                		
 	mov	 EDI,dword ptr [ebp+12]	
 	mov	 ESI,000000001H          		
 	mov	  CL,DL                    	
 	shl	 ESI,CL                		
 	dec	 ESI                   		
 	and	 ESI,EAX                		
 	bts	 ESI,ECX                		
 	mov	 [EDI],ESI                		
 	shr	 EAX,CL                 		
 	mov	 EDI,dword ptr [ebp+16]	
 	mov	 ESI,000000001H          		
 	mov	  CL,DH                    	
 	shl	 ESI,CL                		
 	dec	 ESI                   		
 	and	 ESI,EAX                		
 	bts	 ESI,ECX                		
 	mov	 [EDI],ESI                		
 	mov	  AL,DL                   		
 	add	  AL,DH                   		
 	add	  AL,3+4+2                		
 	mov	  AH,AL                   		
	test	  AH,007H                 		
	setnz	 AH                      		
 	shr	  AL,3                  		
 	add	  AL,AH                   		
@21:
	pop       edi
	pop       esi
	pop       ebp
	ret       16
@@__bitptr_hdrcoder@DeCode_ptrDict$qqspult1t1	endp
@__bitptr_hdrcoder@DeCode_ptrDict$qqspult1t1	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@Price_ptrPass$qqsul	segment virtual
	align	2
@@__ptrptr_hdrcoder@Price_ptrPass$qqsul	proc	near
?live16394@0:
@22:
	push      ebp
	mov       ebp,esp
	mov       al,1
@24:
@23:
	pop       ebp
	ret       8
@@__ptrptr_hdrcoder@Price_ptrPass$qqsul	endp
@__ptrptr_hdrcoder@Price_ptrPass$qqsul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@Code_ptrPass$qqspulul	segment virtual
	align	2
@@__ptrptr_hdrcoder@Code_ptrPass$qqspulul	proc	near
?live16395@0:
@25:
	push      ebp
	mov       ebp,esp
	mov       al,byte ptr [ebp+16]
	mov       edx,dword ptr [ebp+12]
	dec       eax
	shl       eax,2
	mov       byte ptr [edx],al
	mov       al,1
@27:
@26:
	pop       ebp
	ret       12
@@__ptrptr_hdrcoder@Code_ptrPass$qqspulul	endp
@__ptrptr_hdrcoder@Code_ptrPass$qqspulul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@DeCode_ptrPass$qqspult1	segment virtual
	align	2
@@__ptrptr_hdrcoder@DeCode_ptrPass$qqspult1	proc	near
?live16396@0:
@28:
	push      ebp
	mov       ebp,esp
	xor       edx,edx
	mov       eax,dword ptr [ebp+16]
	mov       ecx,dword ptr [ebp+12]
	mov       dl,byte ptr [eax]
	sar       edx,2
	mov       al,1
	and       edx,64
	mov       dword ptr [ecx],edx
@30:
@29:
	pop       ebp
	ret       12
@@__ptrptr_hdrcoder@DeCode_ptrPass$qqspult1	endp
@__ptrptr_hdrcoder@DeCode_ptrPass$qqspult1	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@Price_ptrBrun$qqsulul	segment virtual
	align	2
@@__ptrptr_hdrcoder@Price_ptrBrun$qqsulul	proc	near
?live16397@0:
@31:
	push      ebp
	mov       ebp,esp
	mov       al,2
@33:
@32:
	pop       ebp
	ret       12
@@__ptrptr_hdrcoder@Price_ptrBrun$qqsulul	endp
@__ptrptr_hdrcoder@Price_ptrBrun$qqsulul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@Code_ptrBrun$qqspululul	segment virtual
	align	2
@@__ptrptr_hdrcoder@Code_ptrBrun$qqspululul	proc	near
?live16398@0:
@34:
	push      ebp
	mov       ebp,esp
	mov       ax,word ptr [ebp+16]
	mov       ecx,dword ptr [ebp+12]
	mov       dx,word ptr [ebp+20]
	dec       eax
	dec       edx
	shl       edx,2
	shl       eax,8
	or        ax,dx
	or        ax,2
	mov       word ptr [ecx],ax
	mov       al,2
@36:
@35:
	pop       ebp
	ret       16
@@__ptrptr_hdrcoder@Code_ptrBrun$qqspululul	endp
@__ptrptr_hdrcoder@Code_ptrBrun$qqspululul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@DeCode_ptrBrun$qqspult1t1	segment virtual
	align	2
@@__ptrptr_hdrcoder@DeCode_ptrBrun$qqspult1t1	proc	near
?live16399@0:
@37:
	push      ebp
	mov       ebp,esp
	mov       eax,dword ptr [ebp+20]
?live16399@16: ; EAX = alpcode
	mov       ecx,dword ptr [ebp+16]
	movzx     edx,word ptr [eax]
	sar       edx,2
	and       edx,64
	mov       dword ptr [ecx],edx
	movzx     eax,word ptr [eax]
	mov       edx,dword ptr [ebp+12]
	sar       eax,8
	and       eax,4
	mov       dword ptr [edx],eax
?live16399@48: ; 
	mov       al,2
@39:
@38:
	pop       ebp
	ret       16
@@__ptrptr_hdrcoder@DeCode_ptrBrun$qqspult1t1	endp
@__ptrptr_hdrcoder@DeCode_ptrBrun$qqspult1t1	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@Price_ptrDict$qqsulul	segment virtual
	align	2
@@__ptrptr_hdrcoder@Price_ptrDict$qqsulul	proc	near
?live16400@0:
@40:
	push      ebp
	mov       ebp,esp
	mov       al,3
@42:
@41:
	pop       ebp
	ret       12
@@__ptrptr_hdrcoder@Price_ptrDict$qqsulul	endp
@__ptrptr_hdrcoder@Price_ptrDict$qqsulul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@Code_ptrDict$qqspululul	segment virtual
	align	2
@@__ptrptr_hdrcoder@Code_ptrDict$qqspululul	proc	near
?live16401@0:
@43:
	push      ebp
	mov       ebp,esp
	mov       eax,dword ptr [ebp+16]
	mov       edx,dword ptr [ebp+20]
	dec       edx
	dec       eax
	shl       edx,2
	mov       ecx,dword ptr [ebp+12]
	shl       eax,8
	or        eax,edx
	or        eax,1
	mov       dword ptr [ecx],eax
	mov       al,3
@45:
@44:
	pop       ebp
	ret       16
@@__ptrptr_hdrcoder@Code_ptrDict$qqspululul	endp
@__ptrptr_hdrcoder@Code_ptrDict$qqspululul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@__ptrptr_hdrcoder@DeCode_ptrDict$qqspult1t1	segment virtual
	align	2
@@__ptrptr_hdrcoder@DeCode_ptrDict$qqspult1t1	proc	near
?live16402@0:
@46:
	push      ebp
	mov       ebp,esp
	mov       eax,dword ptr [ebp+20]
?live16402@16: ; EAX = alpcode
	mov       ecx,dword ptr [ebp+16]
	mov       edx,dword ptr [eax]
	shr       edx,2
	and       edx,64
	mov       dword ptr [ecx],edx
	mov       eax,dword ptr [eax]
	mov       edx,dword ptr [ebp+12]
	shr       eax,8
	and       eax,65536
	mov       dword ptr [edx],eax
?live16402@48: ; 
	mov       al,3
@48:
@47:
	pop       ebp
	ret       16
@@__ptrptr_hdrcoder@DeCode_ptrDict$qqspult1t1	endp
@__ptrptr_hdrcoder@DeCode_ptrDict$qqspult1t1	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Code_bitHeader$qqspulcc	segment virtual
	align	2
@@Code_bitHeader$qqspulcc	proc	near
?live16403@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      edi
@49:
	xor	  AX,AX
	mov	  AL,byte ptr [ebp+16]
	test	  AL,003H
	setp	  CL
	add	  CL,CL
	add	  CL,00002H
	mov	  BL,001H
	shl	  BL,CL
	dec	  BL
	and	  AL,BL
	mov	  CH,CL
	mov	 EDI,dword ptr [ebp+8]
	mov	  CL,byte ptr [ebp+12]
	shl	  AX,CL
	mov	  BL,001H
	shl	  BL,CL
	dec	  BL
	and	  BL,[EDI]
	xor	  AL,BL
	add	  CL,CH
MCODE_00:
	mov	 [EDI+0],AL
	cmp	  CL,8
	jbe       @50
MCODE_01:
	mov	 [EDI+1],AH
@50:
MCODE_1X:
	mov	  AL,CH
@51:
	pop       edi
	pop       ebx
	pop       ebp
	ret       12
@@Code_bitHeader$qqspulcc	endp
@Code_bitHeader$qqspulcc	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@DeCode_bitHeader$qqspcpulc	segment virtual
	align	2
@@DeCode_bitHeader$qqspcpulc	proc	near
?live16404@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
@52:
	mov	 ESI,dword ptr [ebp+12]
	mov	  AX,[ESI]
	mov	  CL,byte ptr [ebp+16]
	shr	  AX,CL
	test	  AL,003H
	setp	  CL
	add	  CL,CL
	add	  CL,00002H
	mov	  BX,0FF00H
	rol	  BX,CL
	and	  AL,BL
	mov	  CH,CL
	mov	  EDI ,dword ptr [ebp+8]
	mov	 [EDI],AL
	mov	  AL,CH
@53:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
@@DeCode_bitHeader$qqspcpulc	endp
@DeCode_bitHeader$qqspcpulc	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Price_bitHeader$qqsc	segment virtual
	align	2
@@Price_bitHeader$qqsc	proc	near
?live16405@0:
	push      ebp
	mov       ebp,esp
@54:
	mov	  AL,byte ptr [ebp+8]
	test	  AL,003H
	setp	  AL
	add	  AL,AL
	add	  AL,00002H
@55:
	pop       ebp
	ret       4
@@Price_bitHeader$qqsc	endp
@Price_bitHeader$qqsc	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Code_bitLength$qqspulcul	segment virtual
	align	2
@@Code_bitLength$qqspulcul	proc	near
?live16406@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      edi
@56:
 	xor	 ECX,ECX 
 	mov	 EAX,dword ptr [ebp+16] 
 	xor	 EDX,EDX 
 	bsr	 ECX,EAX 
 	btr	 EAX,ECX 
	shld	 EDX,EAX,3 
 	shl	 EAX,3 
 	or	 EAX,ECX 
 	mov	 CH,CL 
 	add	 CH,3 
 	mov	 EDI,dword ptr [ebp+8] 
 	mov	 CL,byte ptr [ebp+12] 
 	mov	 BX,0FF00H 
 	rol	 BX,CL 
	shld	 EDX,EAX,CL 
 	shl	 EAX,CL 
 	and	 BL,[EDI] 
 	or	 AL,BL 
 	add	 CL,CH 
M_00:
 	mov	 [EDI+0],AL 
 	cmp	 CL, 8 
	jbe       @57
M_01:
 	mov	 [EDI+1],AH 
 	cmp	 CL,16 
	jbe       @57
M_1X:
	shrd	 EAX,EDX,16 
M_02:
 	mov	 [EDI+2],AL 
 	cmp	 CL,24 
	jbe       @57
M_03:
 	mov	 [EDI+3],AH 
 	cmp	 CL,32 
	jbe       @57
M_2X:
	shrd	 EAX,EDX,16 
M_04:
 	mov	 [EDI+4],AL 
 	cmp	 CL,40 
	jbe       @57
M_05:
 	mov	 [EDI+5],AH 
@57:
M_3X:
 	mov	 AL,CH 
@58:
	pop       edi
	pop       ebx
	pop       ebp
	ret       12
@@Code_bitLength$qqspulcul	endp
@Code_bitLength$qqspulcul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@DeCode_bitLength$qqspult1c	segment virtual
	align	2
@@DeCode_bitLength$qqspult1c	proc	near
?live16407@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
@59:
 	mov	 ESI,dword ptr [ebp+12] 
 	mov	 CL,byte ptr [ebp+16] 
 	mov	 EAX,[ESI+0] 
 	mov	 EDX,[ESI+4] 
	shrd	 EAX,EDX,CL 
 	shr	 EDX,CL 
 	mov	 ECX,0FF00H 
 	rol	 ECX,3 
 	and	 CL,AL 
	shrd	 EAX,EDX,3 
 	mov	 CH,CL 
 	add	 CH,3 
 	mov	 EBX,000000001H 
 	shl	 EBX,CL 
 	dec	 EBX 
 	and	 EAX,EBX 
 	inc	 EBX 
 	or	 EAX,EBX 
 	mov	 EDI ,dword ptr [ebp+8] 
 	mov	 [EDI],EAX 
 	mov	 AL,CH 
@60:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
@@DeCode_bitLength$qqspult1c	endp
@DeCode_bitLength$qqspult1c	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Price_bitLength$qqsul	segment virtual
	align	2
@@Price_bitLength$qqsul	proc	near
?live16408@0:
	push      ebp
	mov       ebp,esp
@61:
 	mov	 EAX,dword ptr [ebp+8] 
 	xor	 ECX,ECX 
 	bsr	 ECX,EAX 
 	mov	 AL,3 
 	add	 AL,CL 
@62:
	pop       ebp
	ret       4
@@Price_bitLength$qqsul	endp
@Price_bitLength$qqsul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Code_bitOffset$qqspulcul	segment virtual
	align	2
@@Code_bitOffset$qqspulcul	proc	near
?live16409@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      edi
@63:
 	xor	 ECX,ECX 
 	mov	 EAX,dword ptr [ebp+16] 
 	xor	 EDX,EDX 
 	bsr	 ECX,EAX 
 	btr	 EAX,ECX 
	shld	 EDX,EAX,4 
 	shl	 EAX,4 
 	or	 EAX,ECX 
 	mov	 CH,CL 
 	add	 CH,4 
 	mov	 EDI,dword ptr [ebp+8] 
 	mov	 CL,byte ptr [ebp+12] 
 	mov	 BX,0FF00H 
 	rol	 BX,CL 
	shld	 EDX,EAX,CL 
 	shl	 EAX,CL 
 	and	 BL,[EDI] 
 	or	 AL,BL 
 	add	 CL,CH 
M_00:
 	mov	 [EDI+0],AL 
 	cmp	 CL, 8 
	jbe       @64
M_01:
 	mov	 [EDI+1],AH 
 	cmp	 CL,16 
	jbe       @64
M_1X:
	shrd	 EAX,EDX,16 
M_02:
 	mov	 [EDI+2],AL 
 	cmp	 CL,24 
	jbe       @64
M_03:
 	mov	 [EDI+3],AH 
 	cmp	 CL,32 
	jbe       @64
M_2X:
	shrd	 EAX,EDX,16 
M_04:
 	mov	 [EDI+4],AL 
 	cmp	 CL,40 
	jbe       @64
M_05:
 	mov	 [EDI+5],AH 
@64:
M_3X:
 	mov	 AL,CH 
@65:
	pop       edi
	pop       ebx
	pop       ebp
	ret       12
@@Code_bitOffset$qqspulcul	endp
@Code_bitOffset$qqspulcul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@DeCode_bitOffset$qqspult1c	segment virtual
	align	2
@@DeCode_bitOffset$qqspult1c	proc	near
?live16410@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
@66:
 	mov	 ESI,dword ptr [ebp+12] 
 	mov	 CL,byte ptr [ebp+16] 
 	mov	 EAX,[ESI+0] 
 	mov	 EDX,[ESI+4] 
	shrd	 EAX,EDX,CL 
 	shr	 EDX,CL 
 	mov	 ECX,0FF00H 
 	rol	 ECX,4 
 	and	 CL,AL 
	shrd	 EAX,EDX,4 
 	mov	 CH,CL 
 	add	 CH,4 
 	mov	 EBX,000000001H 
 	shl	 EBX,CL 
 	dec	 EBX 
 	and	 EAX,EBX 
 	inc	 EBX 
 	or	 EAX,EBX 
 	mov	 EDI ,dword ptr [ebp+8] 
 	mov	 [EDI],EAX 
 	mov	 AL,CH 
@67:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
@@DeCode_bitOffset$qqspult1c	endp
@DeCode_bitOffset$qqspult1c	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Price_bitOffset$qqsul	segment virtual
	align	2
@@Price_bitOffset$qqsul	proc	near
?live16411@0:
	push      ebp
	mov       ebp,esp
@68:
 	mov	 EAX,dword ptr [ebp+8] 
 	xor	 ECX,ECX 
 	bsr	 ECX,EAX 
 	mov	 AL,4 
 	add	 AL,CL 
@69:
	pop       ebp
	ret       4
@@Price_bitOffset$qqsul	endp
@Price_bitOffset$qqsul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Code_bitString$qqspulcul	segment virtual
	align	2
@@Code_bitString$qqspulcul	proc	near
?live16412@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      edi
@70:
 	xor	 ECX,ECX 
 	mov	 EAX,dword ptr [ebp+16] 
 	xor	 EDX,EDX 
 	bsr	 ECX,EAX 
 	btr	 EAX,ECX 
	shld	 EDX,EAX,5 
 	shl	 EAX,5 
 	or	 EAX,ECX 
 	mov	 CH,CL 
 	add	 CH,5 
 	mov	 EDI,dword ptr [ebp+8] 
 	mov	 CL,byte ptr [ebp+12] 
 	mov	 BX,0FF00H 
 	rol	 BX,CL 
	shld	 EDX,EAX,CL 
 	shl	 EAX,CL 
 	and	 BL,[EDI] 
 	or	 AL,BL 
 	add	 CL,CH 
M_00:
 	mov	 [EDI+0],AL 
 	cmp	 CL, 8 
	jbe       @71
M_01:
 	mov	 [EDI+1],AH 
 	cmp	 CL,16 
	jbe       @71
M_1X:
	shrd	 EAX,EDX,16 
M_02:
 	mov	 [EDI+2],AL 
 	cmp	 CL,24 
	jbe       @71
M_03:
 	mov	 [EDI+3],AH 
 	cmp	 CL,32 
	jbe       @71
M_2X:
	shrd	 EAX,EDX,16 
M_04:
 	mov	 [EDI+4],AL 
 	cmp	 CL,40 
	jbe       @71
M_05:
 	mov	 [EDI+5],AH 
@71:
M_3X:
 	mov	 AL,CH 
@72:
	pop       edi
	pop       ebx
	pop       ebp
	ret       12
@@Code_bitString$qqspulcul	endp
@Code_bitString$qqspulcul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@DeCode_bitString$qqspult1c	segment virtual
	align	2
@@DeCode_bitString$qqspult1c	proc	near
?live16413@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	push      edi
@73:
 	mov	 ESI,dword ptr [ebp+12] 
 	mov	 CL,byte ptr [ebp+16] 
 	mov	 EAX,[ESI+0] 
 	mov	 EDX,[ESI+4] 
	shrd	 EAX,EDX,CL 
 	shr	 EDX,CL 
 	mov	 ECX,0FF00H 
 	rol	 ECX,5 
 	and	 CL,AL 
	shrd	 EAX,EDX,5 
 	mov	 CH,CL 
 	add	 CH,5 
 	mov	 EBX,000000001H 
 	shl	 EBX,CL 
 	dec	 EBX 
 	and	 EAX,EBX 
 	inc	 EBX 
 	or	 EAX,EBX 
 	mov	 EDI ,dword ptr [ebp+8] 
 	mov	 [EDI],EAX 
 	mov	 AL,CH 
@74:
	pop       edi
	pop       esi
	pop       ebx
	pop       ebp
	ret       12
@@DeCode_bitString$qqspult1c	endp
@DeCode_bitString$qqspult1c	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@Price_bitString$qqsul	segment virtual
	align	2
@@Price_bitString$qqsul	proc	near
?live16414@0:
	push      ebp
	mov       ebp,esp
@75:
 	mov	 EAX,dword ptr [ebp+8] 
 	xor	 ECX,ECX 
 	bsr	 ECX,EAX 
 	mov	 AL,5 
 	add	 AL,CL 
@76:
	pop       ebp
	ret       4
@@Price_bitString$qqsul	endp
@Price_bitString$qqsul	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
 ?debug  C A0020026405F5F6269747074725F686472636F6465724050726963655F7074725061737324717173756C000000
 ?debug  C A0020028405F5F6269747074725F686472636F64657240436F64655F707472506173732471717370756C756C000000
 ?debug  C A002002A405F5F6269747074725F686472636F646572404465436F64655F707472506173732471717370756C7431000000
 ?debug  C A0020028405F5F6269747074725F686472636F6465724050726963655F7074724272756E24717173756C756C000000
 ?debug  C A002002A405F5F6269747074725F686472636F64657240436F64655F7074724272756E2471717370756C756C756C000000
 ?debug  C A002002C405F5F6269747074725F686472636F646572404465436F64655F7074724272756E2471717370756C74317431000000
 ?debug  C A0020028405F5F6269747074725F686472636F6465724050726963655F7074724469637424717173756C756C000000
 ?debug  C A002002A405F5F6269747074725F686472636F64657240436F64655F707472446963742471717370756C756C756C000000
 ?debug  C A002002C405F5F6269747074725F686472636F646572404465436F64655F707472446963742471717370756C74317431000000
 ?debug  C A0020026405F5F7074727074725F686472636F6465724050726963655F7074725061737324717173756C000000
 ?debug  C A0020028405F5F7074727074725F686472636F64657240436F64655F707472506173732471717370756C756C000000
 ?debug  C A002002A405F5F7074727074725F686472636F646572404465436F64655F707472506173732471717370756C7431000000
 ?debug  C A0020028405F5F7074727074725F686472636F6465724050726963655F7074724272756E24717173756C756C000000
 ?debug  C A002002A405F5F7074727074725F686472636F64657240436F64655F7074724272756E2471717370756C756C756C000000
 ?debug  C A002002C405F5F7074727074725F686472636F646572404465436F64655F7074724272756E2471717370756C74317431000000
 ?debug  C A0020028405F5F7074727074725F686472636F6465724050726963655F7074724469637424717173756C756C000000
 ?debug  C A002002A405F5F7074727074725F686472636F64657240436F64655F707472446963742471717370756C756C756C000000
 ?debug  C A002002C405F5F7074727074725F686472636F646572404465436F64655F707472446963742471717370756C74317431000000
 ?debug  C 9F757569642E6C6962
 ?debug  C 9F757569642E6C6962
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSOFT_HDR.H" 18058 42009
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
	?debug	D "C:\Program Files\Borland\CBuilder5\Projects\OBSOLETE\PROGS\Koperek.VCL\LIB\DLLKop32\TSoft_HDR.cpp" 19073 26279
	end
