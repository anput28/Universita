;programma che calcola la distanza di hamming tra due byte

org 100h 
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM

VISUALIZZA msg1
MOV AH, 0AH
LEA DX, primo
INT 21H
VISUALIZZA acapo
VISUALIZZA msg2
MOV AH, 0AH
LEA DX, secondo
INT 21H
VISUALIZZA acapo

MOV SI, 2
MOV CH, 0
MOV CL, 8
CICLO: MOV AL, primo[SI]
       CMP AL, secondo[SI]
       JE conta
       JMP salta
 conta: INC hamming
 salta: INC SI
        LOOP CICLO
 
 ADD hamming, '0'
 
 VISUALIZZA msg3
 VISUALIZZA hamming

;dichiarazione variabili
msg1 DB 'Inserire il primo byte -> $'
msg2 DB 'Inserire il secondo byte -> $' 
msg3 DB 'Distanza di Hamming : $'
acapo DB 13,10,'$'
primo DB 9, ?, 9 DUP('$')
secondo DB 9, ?, 9 DUP('$')
hamming DB 0 , '$'

ret




