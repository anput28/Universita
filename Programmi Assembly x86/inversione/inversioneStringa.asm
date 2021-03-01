;Inserire una stringa di caratteri e invertirla

org 100h  

MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM 

MACRO LEGGI s
    MOV AH, 0AH
    LEA DX, s
    INT 21H
ENDM

VISUALIZZA msg1
LEGGI stringa 

VISUALIZZA acapo 

MOV CX,0
MOV CL, stringa[1]
MOV SI, CX 
INC SI
MOV DI, 0 

CICLO: MOV AL, stringa[SI]
       MOV inversa[DI], AL
       INC DI
       DEC SI
LOOP CICLO

VISUALIZZA msg2
VISUALIZZA inversa 


;fine programma
MOV AH, 4CH
INT 21H


;dichiarazione variabili
msg1 DB 'Inserire una stringa: $' 
msg2 DB 'La stringa inversa: $'
acapo DB 13,10,'$'
stringa DB 21, ?, 21 DUP('$') 
inversa DB 21 DUP('$')

ret




