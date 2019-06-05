;编写者：王占成		同组同学：李辉
PUBLIC GA1,CHANGE,CO_NAME,N,RANK
EXTRN WAN3:NEAR,WAN4:NEAR,WAN5:NEAR,MESS1:BYTE,MESS2:BYTE,MESS3:BYTE,MESS4:BYTE,MESS5:BYTE,MESS6:BYTE
.386
DATA    SEGMENT USE16 PARA PUBLIC 'D1'
BNAME   DB 'ZHANCHENG',0
BPASS   DB 't' XOR 'W','e' XOR 'W','s' XOR 'W','t' XOR 'W',0,0
N       EQU 2
INTERVAL DB ' $'
INTERVAL1 DB ' >> $'
CHANGE	DB 0AH,0DH,'$'
LEAVES	DB '--*--*--*--*--*--*--*--*--*--*',0AH,0DH,'$'
SNAME   DB 'SHOP',0,'$'
GA1     DB 'PEN',7 DUP(0),10
	    DW 35 XOR 'B',56,70,25,?
GA2     DB 'BOOK',6 DUP(0),9
	    DW 12 XOR 'B',30,25,5,?
GA3     DB 'BALL',6 DUP(0),9
	    DW 12 XOR 'B',30,25,5,?
REMIND1	DB 'Please input your account number!',0AH,0DH,'$'
REMIND2 DB 'Please input your password!',0AH,0DH,'$'
REINPUT	DB 'The account number or password is not right.Please try again!',0AH,0DH,'$'
REMIND3	DB 'Please input the name of commodity!',0AH,0DH,'$'
REMIND4 DB 'There is not this commodity!Please try again!',0AH,0DH,'$'
REMIND 	DB 'Please choose your choice!',0AH,0DH,'$'
REMIND5 DB 'Please enter the modified values in order!',0AH,0DH,'$'
REMIND6	DB 'Have illegal character.Please re-enter the modified values in order!',0AH,0DH,'$'
REMIND7 DB 'Please re-enter this modified values!',0AH,0DH,'$'
SFCI	DB '1.Search for commodity information',0AH,0DH,'$'
MCI		DB '2.Modifying commodity information',0AH,0DH,'$'
CTEDOC	DB '3.Compute the recommendation degree of commodity',0AH,0DH,'$'
RANKME	DB '4.Compute the rank of commodity',0AH,0DH,'$'
OACI	DB '5.Output all commodity information',0AH,0DH,'$'
ESYSTEM	DB '6.Exit system',0AH,0DH,'$'
RANK 	DB N DUP(3 DUP(0))
IN_NAME	DB 20
		DB ?
		DB 20 DUP(0)
IN_PWD	DB 20
		DB ?
		DB 20 DUP(0)
CO_NAME	DB 20
		DB ?
		DB 20 DUP(0)
CHOICE	DB 0
AUTH	DB 0
SEEK	DB 0
UPDATE	DB 2
NEW		DB 10
		DB ?
		DB 10 DUP(0)	
OLDINT1 DW  0,0               ;1号中断的原中断矢量（用于中断矢量表反跟踪）
OLDINT3 DW  0,0               ;3号中断的原中断矢量
P1      DW  SPWD             ;地址表（用于间接转移反跟踪）
DATA    ENDS
STACK   SEGMENT USE16 PARA PUBLIC 'STACK'
	    DW N+50 DUP(0)
STACK   ENDS
WRITE	MACRO A
		LEA DX,A
		MOV	AH,9
		INT 21H
		ENDM
READ	MACRO A
		LEA DX,A
		MOV	AH,10
		INT 21H
		ENDM
		
CODE	SEGMENT USE16 PARA PUBLIC 'CODE'
		ASSUME DS:DATA,SS:STACK,CS:CODE
START:	MOV AX,DATA
		MOV DS,AX
		
		xor  ax,ax                  ;接管调试用中断，中断矢量表反跟踪
		mov  es,ax
		mov  ax,es:[1*4]            ;保存原1号和3号中断矢量
		mov  OLDINT1,ax
		mov  ax,es:[1*4+2]
		mov  OLDINT1+2,ax
		mov  ax,es:[3*4]
		mov  OLDINT3,ax
		mov  ax,es:[3*4+2]
		mov  OLDINT3+2,ax
		cli                           ;设置新的中断矢量
		mov  ax,OFFSET NEWINT
		mov  es:[1*4],ax
		mov  es:[1*4+2],cs
		mov  es:[3*4],ax
		mov  es:[3*4+2],cs
		sti

		MOV CX,3
		PUSH CX
		WRITE SNAME
		
		WRITE CHANGE
		
		WRITE LEAVES
		
INPUT:	WRITE CHANGE
		
		MOV AX,DATA
		MOV DS,AX
		
		WRITE REMIND1
		
		READ IN_NAME
		
		WRITE CHANGE
		
		WRITE REMIND2
		
		READ IN_PWD
		
		WRITE CHANGE
		
DECIDE:	MOV AX,DATA
		MOV DS,AX
		
CUST:	LEA DI,IN_NAME
		ADD DI,2
	
		MOV AH,0DH
		CMP AH,[DI]
		JE	ISCUST
		
CUSTEND:NOP
		
WTQ_1:	MOV AH,'q'
		CMP AH,[DI]
		JE	WTQ_2
		JMP SHORT READY
		
WTQ_2:	MOV AH,0DH
		ADD DI,1
		CMP	AH,[DI]
		JE QUIT
		
WTQEND:	NOP
		
READY:	LEA BX,BNAME ;判断阶段的准备
		LEA DI,IN_NAME
		ADD DI,2
		MOV SI,OFFSET IN_NAME + 1
		MOV CL,[SI]
		MOV CH,0
		
SACC:	MOV AH,[BX] ;循环判断账号是否正确
		CMP AH,[DI]
		JNE NOTR
		ADD BX,1
		ADD DI,1
		LOOP SACC
		
		MOV AH,[BX]
		CMP AH,0
		JNE NOTR
		
SACCEND:NOP
		
		cli                       ;堆栈检查反跟踪
        push  P1                ;SPWD的地址压栈
		
		LEA BX,BPASS
		LEA DI,IN_PWD
		ADD DI,2
		MOV SI,OFFSET IN_PWD + 1
		MOV CL,[SI]
		MOV CH,0
		
		pop  ax
        mov  si,[esp-2]           ;把栈顶上面的字（SPWD的地址）取到
        sti
        jmp  si                  ;如果被跟踪，将不会转移到SPWD
		
SPWD:	MOV AH,[BX] ; 循环判断密码是否正确
		MOV AL,[DI];将输入的密码转换为密文进行比较
		XOR AL,'W'
		CMP AH,AL
		JNE NOTR
		ADD BX,1
		ADD DI,1
		LOOP SPWD
		
		MOV AH,[BX]
		CMP AH,0
		JNE NOTR
		
SPWDEND:JMP FAR PTR ISBOSS
		
NOTR:	WRITE REINPUT ;账号密码不对的情况
		POP CX
		DEC CX;密码三次不对，则默认进入用户模式
		CMP CX,0
		JZ	ISCUST
		PUSH CX
		JMP FAR PTR INPUT

ISCUST:	POP CX
		MOV	BX,OFFSET AUTH ;将判断的结果传入AUTH变量
		MOV AH,0
		MOV [BX],AH
		JMP SHORT FUN
		
ISBOSS:	MOV	BX,OFFSET AUTH ;将判断的结果传入AUTH变量
		MOV AH,1
		MOV [BX],AH
		JMP SHORT FUN
		
PASS: 	mov  bx,es:[1*4]             ;检查中断矢量表是否被调试工具阻止修改或恢复
		inc  bx
		jmp  bx                 ;正常修改了的化，这里将转移到TESTINT，否则就不知道转到哪了
		db   'Now,you see.'

FUN:	CALL MENU

;功能一
FUN1:	CMP	BYTE PTR CHOICE,'1'
		JNE FUN2
		
FUN1A:	WRITE REMIND3 ;提示用户输入商品的名称
		
		READ CO_NAME
		
		WRITE CHANGE
		
		MOV CX,N;商品数量
		LEA	BX,GA1;找到所有商品的存储地址
		LEA DI,CO_NAME+2;找到用户输入的商品所在的存储地址	
		CALL FIND
		
		CMP BYTE PTR SEEK,2
		JE	RESEA1
		
		CMP	BYTE PTR SEEK,0
		JE	INPUT
		
		CALL FOUND
		JMP FUN
		
RESEA1:	WRITE REMIND4
		JMP FUN1A
		
;功能二
FUN2:	CMP	BYTE PTR CHOICE,'2'
		JNE FUN3
		CMP BYTE PTR AUTH,0
		JE	INPUT
		CALL WAN2
		JMP FUN
		
;功能三
FUN3:	CMP	BYTE PTR CHOICE,'3'
		JNE FUN4
		CMP BYTE PTR AUTH,0
		JE	INPUT
		CALL WAN3
		JMP FUN
		
;功能四		
FUN4:	CMP	BYTE PTR CHOICE,'4'
		JNE FUN5
		CMP BYTE PTR AUTH,0
		JE	INPUT
		CALL WAN4
		JMP FUN
		
;功能五
FUN5:	CMP	BYTE PTR CHOICE,'5'
		JNE FUN6
		CMP BYTE PTR AUTH,0
		JE	INPUT
		CALL WAN5
		JMP FUN
		
;功能六
FUN6:	CMP	BYTE PTR CHOICE,'6'
		JNE FUN7
		JMP QUIT
		
;无效功能选择
FUN7:	JMP INPUT

NEWINT: iret
TESTINT:jmp FUN
		
QUIT:	cli                           ;还原中断矢量
		mov  ax,OLDINT1
		mov  es:[1*4],ax
		mov  ax,OLDINT1+2
		mov  es:[1*4+2],ax
		mov  ax,OLDINT3
		mov  es:[3*4],ax
		mov  ax,OLDINT3+2
		mov  es:[3*4+2],ax 
		sti
		
		MOV AH,4CH
		INT 21H

		
;显示功能菜单		
MENU	PROC;显示功能菜单
		PUSH DX
		WRITE LEAVES
		WRITE CHANGE
		
		WRITE SFCI
		
		MOV AH,AUTH
		CMP AH,0
		JE MENU1
		
		WRITE MCI
		
		WRITE CTEDOC
		
		WRITE RANKME
		
		WRITE OACI
		
MENU1:	WRITE ESYSTEM

		WRITE LEAVES
		
		WRITE CHANGE
		
		WRITE REMIND
		
		MOV AH,1
		INT 21H
		
		WRITE CHANGE
		
		MOV CHOICE,AL
		
		POP	DX
		RET
MENU	ENDP


;查找商品(仅仅实现查找)
FIND	PROC;查找商品信息
			;CX是传递参数，代表商品数量
			;BX是传递参数，代表所有商品的地址。
			;DI是传递参数，代表用户输入的商品名称的存储地址。
			;最后的BX，代表着的是查找到的商品地址
		PUSH DI
		PUSH SI
		PUSH BP
		PUSH AX
		PUSH CX
		
FJUDGE:	MOV AH,[DI] ;判断输入商品名称时是否只输入了回车
		CMP AH,0DH
		JE	O1
		
		PUSH CX
		PUSH BX
		MOVZX BP,BYTE PTR[DI-1];记录输入商品的名称的长度
		MOV SI,DI
		MOV CX,BP
		
SJUDGE:	MOV CX,BP
		MOV DI,SI
		
JUDGE:	MOV AH,[BX] ;开始判断
		CMP AH,BYTE PTR [DI]
		JNE NOMARRY
		INC BX
		INC DI
		LOOP JUDGE
		
		MOV AH,[BX]
		CMP AH,0
		JNE NOMARRY
		POP	BX;存储找到的商品地址
		POP CX
		JMP O2
		
NOMARRY:POP BX
		ADD BX,21
		POP CX
		DEC CX
		CMP CX,0
		JE	NOTHAVE
		PUSH CX
		PUSH BX
		JMP SJUDGE
		
		
NOTHAVE:JMP O3
		
O1:		MOV AH,0;输入回车
		MOV SEEK,AH
		JMP	O0
		
O2:		MOV	AH,1;找到商品
		MOV	SEEK,AH
		JMP O0
		
O3:		MOV	AH,2;无所查商品
		MOV	SEEK,AH
		JMP O0

O0:		POP CX
		POP AX
		POP BP
		POP SI
		POP DI
		
		RET
FIND	ENDP


;输出商品信息
FOUND	PROC;BX是传递参数，代表输出商品的地址
		PUSH DX
		PUSH AX
		PUSH CX
		PUSH BX

		MOV CX,10
OUTCO:	MOV DL,[BX]
		CMP DL,0
		JE	OUTNEXT
		MOV AH,2
		INT 21H
		INC BX
		LOOP OUTCO 
		
OUTNEXT:POP BX;注意上面入栈的顺序，BX一定要处于栈顶的位置
		PUSH BX
		
		CALL COMPRE;计算推荐度
;上划线		
		WRITE CHANGE
		
		WRITE LEAVES
		
		WRITE CHANGE
;输出折扣		
		ADD BX,10
		CALL OUT11
		WRITE CHANGE
		INC BX
		
		MOV	CX,4
;输出其他		
OUTMESS:CALL OUT21
		WRITE CHANGE
		ADD BX,2
		LOOP OUTMESS
;输出推荐度
		WRITE MESS6
		CALL OUT21
;下划线		
		WRITE CHANGE
		WRITE LEAVES
		WRITE CHANGE
		
		POP BX
		POP CX
		POP AX;;;;;
		POP DX
		RET
FOUND	ENDP


;显示10进制数字
OUTNUM	PROC;AX是传递参数，代表着需要显示的10进制数
		PUSH DX
		PUSH CX
		PUSH AX
		
		MOV CX,0
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
		
YESEND:	CMP CX,0
		JE	NOOUT
		POP DX
		MOV AH,2
		INT 21H
		LOOP YESEND
		JMP	NUMEND

NOOUT:	MOV DL,'0'
		MOV AH,2
		INT 21H
		
NUMEND:	NOP
		
		POP AX
		POP CX
		POP DX
		RET
OUTNUM	ENDP

;将字符转换成10进制数
INNUM PROC;DI是传递参数，代表着需要转换的字符串的,SI是修改后的数值
		PUSH AX
		PUSH DX
		PUSH CX
		PUSH DI
		
		MOV	BYTE PTR UPDATE,2
		XOR SI,SI
		MOVZX DX,BYTE PTR [DI+1];修改后的长度
		MOV CX,DX
		ADD DI,2;输入字符串的起始地址
		
		CMP DX,0
		JE ZERO
		
NOZERO1:MOVZX AX,BYTE PTR [DI]
		CMP AX,47
		JLE MISTAKE
		CMP AX,58
		JGE MISTAKE
		SUB AX,48
		DEC CX
NOZERO2:CMP CX,0
		JE	RIGHT
		IMUL AX,10
		LOOP NOZERO2
RIGHT:	ADD SI,AX
		DEC DX
		CMP DX,0
		JE INNUM1
		MOV CX,DX
		INC DI
		JMP NOZERO1	
		
ZERO:	MOV BYTE PTR UPDATE,0
		JMP INNUM1
		
MISTAKE:MOV BYTE PTR UPDATE,1
		WRITE LEAVES
		JMP INNUM1
		
INNUM1:	POP DI
		POP CX
		POP DX
		POP AX
		RET
INNUM ENDP

;计算推荐度(没有考虑除数为0的情况)
COMPRE	PROC;BX是传递参数，代表输出商品的地址
		PUSH AX
		PUSH DX
		PUSH CX
		PUSH DI
		PUSH SI
		
RECOMM:	MOV AX,[BX+13]
		MOVZX EAX,AX
		MOV EDX,EAX;EDX 售价
		;CMP EDX,0
		;JE	LEVELA
		MOV AL,[BX+10]
		MOV AH,0
		MOVZX EAX,AX;EAX 折扣*10
		MUL	EDX;EDX存储高位，EAX存储低位
		MOV ECX,EAX
		
		MOV AX,[BX+11];进价
		XOR AX,'B'
		MOVZX EAX,AX
		MOV EDX,1280
		MUL EDX;EDX存储高位，EAX存储低位
		DIV ECX;EAX为商，EDX为余数
		
		MOV EDI,EAX;进价*1280与实际售价*折扣*10的商
	
		MOV AX,[BX+15];进货量
		MOVZX EAX,AX
		MOV ECX,EAX
		MOV AX,[BX+17];销售量
		MOVZX EAX,AX
		MOV EDX,128
		MUL EDX;EDX存储高位，EAX存储低位
		DIV ECX;EAX为商，EDX为余数
		
		ADD EAX,EDI;商品推荐度存储于EDI,DS:01F3附近
		MOV [BX+19],AX
		
		POP SI
		POP DI
		POP CX
		POP DX
		POP AX
		RET
COMPRE	ENDP

;输出折扣
OUT1	PROC;BX为传递参数，代表当前信息的地址
		PUSH AX
		WRITE MESS1
		MOVZX AX,BYTE PTR [BX]
		CALL OUTNUM
		WRITE INTERVAL
		WRITE INTERVAL1
		POP AX
		RET
OUT1	ENDP

OUT11	PROC;BX为传递参数，代表当前信息的地址
		PUSH AX
		WRITE MESS1
		MOVZX AX,BYTE PTR [BX]
		CALL OUTNUM
		WRITE INTERVAL
		POP AX
		RET
OUT11	ENDP

;输出其他商品信息
;CX是传递信息，是序号
;BX为传递参数，代表当前信息的地址
OUT2	PROC
		PUSH AX
OUT2A:	CMP CX,4
		JNE OUT2B
		WRITE MESS2
		MOV AX,[BX]
		XOR AX,'B'
		JMP OUT2F
OUT2B:	CMP CX,3
		JNE OUT2C
		WRITE MESS3
		JMP OUT2E
OUT2C:	CMP CX,2
		JNE OUT2D
		WRITE MESS4
		JMP OUT2E

OUT2D:	CMP CX,1
		JNE OUT2E
		WRITE MESS5
		
OUT2E:	MOV AX,[BX]
OUT2F:	CALL OUTNUM
		WRITE INTERVAL
		WRITE INTERVAL1
		POP AX
		RET
OUT2	ENDP

OUT21	PROC
		PUSH AX
OUT21A:	CMP CX,4
		JNE OUT21B
		WRITE MESS2
		MOV AX,[BX]
		XOR AX,'B'
		JMP OUT21F
OUT21B:	CMP CX,3
		JNE OUT21C
		WRITE MESS3
		JMP OUT21E
OUT21C:	CMP CX,2
		JNE OUT21D
		WRITE MESS4
		JMP OUT21E

OUT21D:	CMP CX,1
		JNE OUT21E
		WRITE MESS5
		
OUT21E:	MOV AX,[BX]
OUT21F:	CALL OUTNUM
		WRITE INTERVAL
		POP AX
		RET
OUT21	ENDP

WAN2	PROC
		PUSHA

FUN2A:  WRITE REMIND3 ;提示用户输入商品的名称
		
		READ CO_NAME
		
		WRITE CHANGE
		
		MOV CX,N;商品数量
		LEA	BX,GA1;找到所有商品的存储地址
		LEA DI,CO_NAME+2;找到用户输入的商品所在的存储地址	
		CALL FIND
		
		CMP BYTE PTR SEEK,2
		JE	RESEA2
		
		CMP	BYTE PTR SEEK,0
		JE	ENDFI
		
		CALL FOUND
		MOV BP,BX
		ADD BX,10
		MOV DX,2
		MOV CX,5
		WRITE REMIND5
		
FUN2B:	CMP CX,5
		JE	FUN2E
		JMP FUN2F
FUN23:	READ NEW
		WRITE CHANGE
		LEA DI,NEW
		CALL INNUM
		CMP BYTE PTR UPDATE,0
		JE FUN2C
		CMP BYTE PTR UPDATE,1
		JE FUN2D
		CMP BYTE PTR UPDATE,2
		JE FUN22	
FUN2C:	NOP
		JMP FUN21
FUN2D:	WRITE REMIND6
		JMP FUN2B
FUN22:	CMP CX,5
		JE FUN2G
		;;;;;;进货价加密后存储
		CMP CX,4
		JE	RETURN
		;;;;;;
		MOV [BX],SI
FUN21:	CMP CX,5
		JE	FUN2H
		ADD BX,2
FUN24:	LOOP FUN2B
		MOV BX,BP
		CALL FOUND
		JMP ENDFI
		
RESEA2:	WRITE REMIND4
		JMP FUN2A
FUN2E:	CALL OUT1
		JMP FUN23
FUN2F:	CALL OUT2
		JMP FUN23
FUN2G:	MOV AX,SI
		MOV BYTE PTR DS:[BP+10],AL
		JMP FUN21
FUN2H:	INC	BX
		JMP FUN24	
		
ENDFI: 	POPA
		
		RET
		
RETURN:	XOR SI,'B'
		MOV [BX],SI
		JMP FUN21
		
WAN2	ENDP

		
CODE	ENDS
		END	START