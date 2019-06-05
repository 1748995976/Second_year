.386
.model   flat,stdcall
option   casemap:none

WinMain  proto :DWORD,:DWORD,:DWORD,:DWORD
WndProc  proto :DWORD,:DWORD,:DWORD,:DWORD
Display  proto :DWORD

include      menuID.INC

include      windows.inc
include      user32.inc
include      kernel32.inc
include      gdi32.inc
include      shell32.inc

includelib   user32.lib
includelib   kernel32.lib
includelib   gdi32.lib
includelib   shell32.lib

good	struct
		GOODNAME   		db  10 dup(' ')
	    DISCOUNT 		db  0
	    COSTPRICE 		dw  0
	    MARKINTPRICE 	dw  0
	    COSTAMOUNT 		dw  0
	    MARKINTAMOUNT 	dw  0
	    SUGGEST			dw  0
good    ends

.data
N			 equ	  5
ClassName    db       'TryWinClass',0
AppName      db       'Our First Window',0
MenuName     db       'MyMenu',0
DlgName	     db       'MyDialog',0
AboutMsg     db       'I am CS1707 wangzhancheng',0
hInstance    dd       0
CommandLine  dd       0
goods	good  <'PEN',10,35,56,70,25,?>
		good  <'BOOK',9,12,30,25,5,?>
		good  <'JUICE',10,5,6,50,44,?>
		good  <'FOOTBALL',10,80,85,30,7,?>
		good  <'APPLE',9,4,5,100,20,?>
msg_name     		db       'name',0
msg_discount 		db       'discount',0
msg_costprice 		db       'costprice',0
msg_markingprice 	db       'markingprice',0
msg_costamount  	db       'costamount',0
msg_markingamount   db       'markingamount',0
msg_suggest 		db 		 'suggest',0
menuItem     db       0  ;当前菜单状态, 1=处于list, 2=Recommendation,0=Clear
number		 db 4 dup(' ')
			 db '$'
OFFSETY		 dd 40

.code
Start:	 invoke GetModuleHandle,NULL
	     mov    hInstance,eax
	     invoke GetCommandLine
	     mov    CommandLine,eax
	     invoke WinMain,hInstance,NULL,CommandLine,SW_SHOWDEFAULT
	     invoke ExitProcess,eax
	     ;;
WinMain      proc   hInst:DWORD,hPrevInst:DWORD,CmdLine:DWORD,CmdShow:DWORD
	     LOCAL  wc:WNDCLASSEX
	     LOCAL  msg:MSG
	     LOCAL  hWnd:HWND
         invoke RtlZeroMemory,addr wc,sizeof wc
	     mov    wc.cbSize,SIZEOF WNDCLASSEX
	     mov    wc.style, CS_HREDRAW or CS_VREDRAW
	     mov    wc.lpfnWndProc, offset WndProc
	     mov    wc.cbClsExtra,NULL
	     mov    wc.cbWndExtra,NULL
	     push   hInst
	     pop    wc.hInstance
	     mov    wc.hbrBackground,COLOR_WINDOW+1
	     mov    wc.lpszMenuName, offset MenuName
	     mov    wc.lpszClassName,offset ClassName
	     invoke LoadIcon,NULL,IDI_APPLICATION
	     mov    wc.hIcon,eax
	     mov    wc.hIconSm,0
	     invoke LoadCursor,NULL,IDC_ARROW
	     mov    wc.hCursor,eax
	     invoke RegisterClassEx, addr wc
	     INVOKE CreateWindowEx,NULL,addr ClassName,addr AppName,\
                    WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,\
                    CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,\
                    hInst,NULL
	     mov    hWnd,eax
	     INVOKE ShowWindow,hWnd,SW_SHOWNORMAL
	     INVOKE UpdateWindow,hWnd
	     ;;
MsgLoop: INVOKE GetMessage,addr msg,NULL,0,0
         cmp    EAX,0
         je     ExitLoop
         INVOKE TranslateMessage,addr msg
         INVOKE DispatchMessage,addr msg
	     jmp    MsgLoop 
ExitLoop:mov    eax,msg.wParam
	     ret
WinMain  endp

WndProc      proc   hWnd:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD
	     LOCAL  hdc:HDC
	     LOCAL  ps:PAINTSTRUCT
     .IF     uMsg == WM_DESTROY
	     invoke PostQuitMessage,NULL
     .ELSEIF uMsg == WM_KEYDOWN
	    .IF     wParam == VK_F1
             ;;your code
	    .ENDIF
     .ELSEIF uMsg == WM_COMMAND
	    .IF     wParam == IDM_FILE_EXIT
		    invoke SendMessage,hWnd,WM_CLOSE,0,0
	    .ELSEIF wParam == IDM_ACTION_LIST
		    mov menuItem, 1
		    invoke InvalidateRect,hWnd,0,1  ;擦除整个客户区
		    invoke UpdateWindow, hWnd
		.ELSEIF wParam == IDM_ACTION_RECOMMENDATION
		    mov menuItem, 2
		    invoke InvalidateRect,hWnd,0,1  ;擦除整个客户区
		    invoke UpdateWindow, hWnd	
	    .ELSEIF wParam == IDM_HELP_ABOUT
		    invoke MessageBox,hWnd,addr AboutMsg,addr AppName,0
	    .ENDIF
     .ELSEIF uMsg == WM_PAINT
             invoke BeginPaint,hWnd, addr ps
             mov hdc,eax
	     .IF menuItem == 1
		 invoke Display,hdc
		 .ELSEIF menuItem == 2
		 CALL COMPRE
		 invoke Display,hdc
	     .ENDIF
	     invoke EndPaint,hWnd,addr ps
     .ELSE
             invoke DefWindowProc,hWnd,uMsg,wParam,lParam
             ret
     .ENDIF
  	     xor    eax,eax
	     ret
WndProc      endp

Display      proc   hdc:HDC
			 PUSH EBX
			 PUSH CX
             XX     equ  10
             YY     equ  10
			 XX_GAP equ  150
			 YY_GAP equ  30
             invoke TextOut,hdc,XX+0*XX_GAP,YY+0*YY_GAP,offset msg_name,4
             invoke TextOut,hdc,XX+1*XX_GAP,YY+0*YY_GAP,offset msg_discount,8
             invoke TextOut,hdc,XX+2*XX_GAP,YY+0*YY_GAP,offset msg_costprice,9
             invoke TextOut,hdc,XX+3*XX_GAP,YY+0*YY_GAP,offset msg_markingprice,12
             invoke TextOut,hdc,XX+4*XX_GAP,YY+0*YY_GAP,offset msg_costamount,10
             invoke TextOut,hdc,XX+5*XX_GAP,YY+0*YY_GAP,offset msg_markingamount,13
			 invoke TextOut,hdc,XX+6*XX_GAP,YY+0*YY_GAP,offset msg_suggest,7
             ;;
			 MOV DWORD PTR OFFSETY,40
			 MOV CX,N
			 MOV EBX,0
D1:          PUSH CX;cx为什么需要保护？？？
			 invoke TextOut,hdc,XX+0*XX_GAP,OFFSETY,addr goods[EBX].GOODNAME,10
			 MOV 	AX,0
			 MOV	AL,goods[EBX].DISCOUNT
			 CALL OUTNUM
             invoke TextOut,hdc,XX+1*XX_GAP,OFFSETY,offset number,4
			 MOV	AX,goods[EBX].COSTPRICE
			 CALL OUTNUM
             invoke TextOut,hdc,XX+2*XX_GAP,OFFSETY,offset number,4
			 MOV	AX,goods[EBX].MARKINTPRICE
			 CALL OUTNUM
             invoke TextOut,hdc,XX+3*XX_GAP,OFFSETY,offset number,4
			 MOV	AX,goods[EBX].COSTAMOUNT
			 CALL OUTNUM
             invoke TextOut,hdc,XX+4*XX_GAP,OFFSETY,offset number,4
			 MOV	AX,goods[EBX].MARKINTAMOUNT
			 CALL OUTNUM
             invoke TextOut,hdc,XX+5*XX_GAP,OFFSETY,offset number,4
			 MOV	AX,goods[EBX].SUGGEST
			 CALL OUTNUM
			 invoke TextOut,hdc,XX+6*XX_GAP,OFFSETY,offset number,4
			 ADD WORD PTR OFFSETY,30
			 ADD EBX,21
			 POP CX
			 DEC CX
			 CMP CX,0
			 JNE D1
			 
			 POP CX
			 POP EBX
			 ret

Display      endp

;显示10进制数字
OUTNUM	PROC;AX是传递参数，代表着需要显示的10进制数
		PUSH EDI
		PUSH DX
		PUSH ECX
		PUSH AX
		
		LEA EDI,number
		MOV ECX,4
RESET:	MOV BYTE PTR [EDI+ECX],' '
		LOOP RESET
		
		MOV ECX,0
NOEND:	CMP AX,0
		JE YESEND
		INC CX
		MOV DL,10
		DIV	DL
		ADD AH,48
		MOVZX DX,AH
		PUSH DX
		MOVZX AX,AL
		JMP NOEND
		
		MOV EAX,0
		
YESEND:	CMP CX,0
		JE	NOOUT
		POP DX
		MOV [EDI+EAX],DL
		INC EAX
		LOOP YESEND
		JMP	NUMEND

NOOUT:	MOV BYTE PTR [EDI],' '
		
NUMEND:	NOP
		
		POP AX
		POP ECX
		POP DX
		POP EDI
		RET
OUTNUM	ENDP

;计算推荐度(没有考虑除数为0的情况)
COMPRE	PROC
		PUSHAD
		
		LEA EBX,goods
		MOV CX,N
		
RECOMM:	PUSH CX
		MOV AX,[EBX+13]
		MOVZX EAX,AX
		MOV EDX,EAX;EDX 售价
		MOV AL,[EBX+10]
		MOV AH,0
		MOVZX EAX,AX;EAX 折扣*10
		MUL	EDX;EDX存储高位，EAX存储低位
		MOV ECX,EAX
		
		MOV AX,[EBX+11];进价
		MOVZX EAX,AX
		MOV EDX,1280
		MUL EDX;EDX存储高位，EAX存储低位
		DIV ECX;EAX为商，EDX为余数
		
		MOV EDI,EAX;进价*1280与实际售价*折扣*10的商
	
		MOV AX,[EBX+15];进货量
		MOVZX EAX,AX
		MOV ECX,EAX
		MOV AX,[EBX+17];销售量
		MOVZX EAX,AX
		MOV EDX,128
		MUL EDX;EDX存储高位，EAX存储低位
		DIV ECX;EAX为商，EDX为余数
		
		ADD EAX,EDI
		MOV [EBX+19],AX
		
		ADD EBX,21
		POP CX
		LOOP RECOMM
		
		POPAD
		RET
COMPRE	ENDP

             end  Start
