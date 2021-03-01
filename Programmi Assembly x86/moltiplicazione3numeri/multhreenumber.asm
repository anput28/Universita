;inserire 3 numeri nel vettore e moltiplicarli
org 100h
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM

MACRO LEGGI n
    MOV AH,01H
    INT 21H
    MOV n, AL
ENDM

VISUALIZZA msg1
LEGGI numeri[0] 
VISUALIZZA acapo
VISUALIZZA msg1
LEGGI numeri[1]
VISUALIZZA acapo
VISUALIZZA msg1
LEGGI numeri[2]

SUB numeri[0], '0'  
SUB numeri[1], '0'
SUB numeri[2], '0'

MOV AH,0
MOV AL, numeri[1]
MUL numeri[0] 
MUL numeri[2]  

MOV DX,0
DIV DIECI
MOV numeri[2], DL
MOV AH,0
DIV DIECI2
MOV numeri[1], AH
MOV numeri[0], AL

ADD numeri[0], '0'  
ADD numeri[1], '0'
ADD numeri[2], '0' 

VISUALIZZA acapo
VISUALIZZA msg2 
VISUALIZZA numeri


;termine programma
MOV AH, 4CH
INT 21H

;dichiarazione variabili
msg1 DB 'Inserire un numero -> $' 
msg2 DB 'Risultato: $'
acapo DB 13,10,'$'
numeri DB 4 DUP('$')
DIECI2 DB 10
DIECI Dw 10

ret




