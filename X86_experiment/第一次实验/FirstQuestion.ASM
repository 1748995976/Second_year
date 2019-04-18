.386
STACK	SEGMENT USE16 STACK
        
STACK 	ENDS

DATA	SEGMENT USE16

DATA	ENDS

CODE	SEGMENT USE16
		ASSUME  CS:CODE, SS:STACK, DS:DATA, ES:DATA
START:  mov AH, 0110011B
        mov BH, 1011010B
        add AH, BH
		mov AH, 0110011B
		sub AH, BH
        mov AH, -0101001B
        mov BH, -1011101B
        add AH, BH
		mov AH, -0101001B
		sub AH, BH
		mov AH, 1100101B
		mov BH, -1011101B
		add AH, BH
		mov AH, 1100101B
		sub AH, BH
        mov AH, 4CH
        int 21H
CODE 	ENDS
        END START