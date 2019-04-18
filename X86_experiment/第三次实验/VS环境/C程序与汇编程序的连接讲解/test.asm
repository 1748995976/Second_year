.386
.model flat,c
stack segment stack  use16
	db 500 dup(0)
stack ends      
N    EQU   2
stack segment stack  use16
     db 200 dup(0)
stack ends     

.code 
printv PROTO C, v:DWORD
prints PROTO C, s:DWORD
printAGood PROTO C,ga1:dword,index:dword
func3_calculation proc p:dword

		pusha;所有16位存储器进栈

cycle_begin:
		mov ebp,p;bp保存商品首地址
		mov cx,word ptr N;商品数给cx

cycle:
		mov ax,ds:[ebp+12];进货价
		mov bx,ds:[ebp+14];销售价
		mov si,128
		mul si;进货价乘128
		div bx;所得除销售价
		push ax
		mov si,10
		movsx bx,byte ptr ds:[ebp+10];折扣
		pop ax
		mul si;进货价乘128除以销售价乘10
		div bx;上步所得除以折扣
		push ax;入栈
		mov ax,ds:[ebp+18];进货总数
		mov bx,ds:[ebp+16];已售数量
		mov si,128
		mul si;进货总数乘128
		div bx;所得除以已售数量
		pop bx;退栈到bx
		add ax,bx;推荐度相加
		mov ds:[ebp+20],ax;将推荐度放在商品信息之后
		push ax
output:	
		;mov dl,0ah;输出回车
		;mov ah,2
		;int 21h
		pop ax
		;call F2T10;输出所有商品的推荐度
		
cycle_judge:
		;循环继续判断
		add bp,byte ptr 22
		dec cx;cx不为零继续循环，直到N个商品推荐度都计算完毕
		jnz cycle

		popa;恢复现场
		ret;返回
func3_calculation endp

func4_rank proc p1:dword,p3:dword
		
		pusha;所有16位存储器进栈
		mov eax,word ptr N
		imul eax,word ptr 2
		mov ebx,p3
		mov esi,0
zero4:
		mov [ebx+esi],byte ptr 0
		inc esi
		cmp esi,eax
		jnz zero4

cycle4_begin:
		mov ebx,p1;bx存所有商品首地址
		mov eax,p1
		mov cx,N;cx存商品总数
		mov di,N
		mov dx,1;dx存当前排名

cycle4_small:
		push edx
		mov edx,[ebx+20];ax存当前比较主数
		cmp edx,ds:[eax+20]
		pop edx;
		jb dx4_plus

cycle4_small_back:
		add eax,22
		dec cx
		jnz cycle4_small

cycle4_big:
		;mov ax,dx;显示排名
		;call F2T10
		pushad;所有32位存储器进栈
		mov eax,p3
		sub eax,2
		mov si,N
		sub si,di
		movsx esi,si
		mov word ptr ds:[eax+2*esi+2],dx
		popad;所有32位存储器出栈
		mov eax,p1
		add ebx,22
		mov dx,1
		dec di
		mov cx,N
		jnz cycle4_small
		jmp cycle4_over
dx4_plus:
		inc dx
		jmp cycle4_small_back
cycle4_over:
		popa
		ret
func4_rank endp

func5_output proc p1:dword,p3:dword,str6:dword

		pusha;所有16位存储器进栈

		invoke prints,str6

cycle5_begin1:
		mov ebx,p1;ebx存商品名首地址
		mov esi,dword ptr 0;esi循环变量置零
		mov edi,p3;di存商品推荐度排名首地址
cycle5_1:
		invoke printAGood,ebx,esi
		mov ax,word ptr [edi+esi*2]
		movsx eax,ax
		invoke printv,eax
		add ebx,22
		inc esi
		cmp esi,dword ptr N
		jnz cycle5_1

func5_over:

		popa;恢复现场
		ret;返回
func5_output endp
end 
		
