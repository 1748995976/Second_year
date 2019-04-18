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

		pusha;����16λ�洢����ջ

cycle_begin:
		mov ebp,p;bp������Ʒ�׵�ַ
		mov cx,word ptr N;��Ʒ����cx

cycle:
		mov ax,ds:[ebp+12];������
		mov bx,ds:[ebp+14];���ۼ�
		mov si,128
		mul si;�����۳�128
		div bx;���ó����ۼ�
		push ax
		mov si,10
		movsx bx,byte ptr ds:[ebp+10];�ۿ�
		pop ax
		mul si;�����۳�128�������ۼ۳�10
		div bx;�ϲ����ó����ۿ�
		push ax;��ջ
		mov ax,ds:[ebp+18];��������
		mov bx,ds:[ebp+16];��������
		mov si,128
		mul si;����������128
		div bx;���ó�����������
		pop bx;��ջ��bx
		add ax,bx;�Ƽ������
		mov ds:[ebp+20],ax;���Ƽ��ȷ�����Ʒ��Ϣ֮��
		push ax
output:	
		;mov dl,0ah;����س�
		;mov ah,2
		;int 21h
		pop ax
		;call F2T10;���������Ʒ���Ƽ���
		
cycle_judge:
		;ѭ�������ж�
		add bp,byte ptr 22
		dec cx;cx��Ϊ�����ѭ����ֱ��N����Ʒ�Ƽ��ȶ��������
		jnz cycle

		popa;�ָ��ֳ�
		ret;����
func3_calculation endp

func4_rank proc p1:dword,p3:dword
		
		pusha;����16λ�洢����ջ
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
		mov ebx,p1;bx��������Ʒ�׵�ַ
		mov eax,p1
		mov cx,N;cx����Ʒ����
		mov di,N
		mov dx,1;dx�浱ǰ����

cycle4_small:
		push edx
		mov edx,[ebx+20];ax�浱ǰ�Ƚ�����
		cmp edx,ds:[eax+20]
		pop edx;
		jb dx4_plus

cycle4_small_back:
		add eax,22
		dec cx
		jnz cycle4_small

cycle4_big:
		;mov ax,dx;��ʾ����
		;call F2T10
		pushad;����32λ�洢����ջ
		mov eax,p3
		sub eax,2
		mov si,N
		sub si,di
		movsx esi,si
		mov word ptr ds:[eax+2*esi+2],dx
		popad;����32λ�洢����ջ
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

		pusha;����16λ�洢����ջ

		invoke prints,str6

cycle5_begin1:
		mov ebx,p1;ebx����Ʒ���׵�ַ
		mov esi,dword ptr 0;esiѭ����������
		mov edi,p3;di����Ʒ�Ƽ��������׵�ַ
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

		popa;�ָ��ֳ�
		ret;����
func5_output endp
end 
		
