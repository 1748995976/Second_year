.386
CODE SEGMENT USE16
	 ASSUME CS:CODE
START:
        MOV AX, 0
        MOV DS, AX
        MOV SI, 0
        MOV DX, [SI];偏移地址
        MOV CX, [SI+2];段地址

        MOV AL, 0
        MOV AH, 35H
        INT 21H;ES保存段地址，BX保存偏移地址
        MOV AH, 4CH
        INT 21H
CODE ENDS
END START