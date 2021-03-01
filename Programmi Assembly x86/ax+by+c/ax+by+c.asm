;calcolare l'espressione ax+by+c inserendo tutti e 5 i numeri da tastiera

org 100h
MACRO VISUALIZZA stringa
    MOV AH, 09H
    LEA DX, stringa
    INT 21H
ENDM

MACRO LEGGI num
    MOV AH, 01H
    INT 21H
    MOV num, AL
ENDM

MOV SI,0
MOV CH,0
MOV CL,5

CICLO: VISUALIZZA msg1
       LEGGI numeri[SI]
       SUB numeri[SI], '0'
       INC SI
       VISUALIZZA acapo
       LOOP CICLO        
 
;calcolo prima a * x
MOV AH,0
MOV AL, numeri[0]
MUL numeri[1]
MOV numeri[0], AL ;sposto il risultato di a*x nel primo elemento del vettore 'numeri'

;calcolo b*y
MOV AH,0
MOV AL, numeri[2]
MUL numeri[3]
MOV numeri[1], AL ;sposto il risultato di b*y nel secondo elemento del vettore 'numeri'

;sommo ax + by + c
MOV AL, numeri[1]
ADD numeri[0], AL

MOV AL, numeri[4]
ADD AL, numeri[0] ;a questo punto il risultato di ax+by+c è contenuto in AL

MOV AH,0
DIV DIECI

MOV risultato[2], AH 
MOV AH, 0
DIV DIECI

MOV risultato[1], AH
MOV risultato[0], AL

ADD risultato[0], '0'
ADD risultato[1], '0'  
ADD risultato[2], '0'

VISUALIZZA msg2
VISUALIZZA risultato

;termine programma
MOV AH, 4CH
INT 21H

;dichiarazione variabili
msg1 DB 'Inserire un numero -> $'
msg2 DB 'Risultato: $'
acapo DB 13,10,'$'
numeri DB 6 DUP('$') 
risultato DB 4 DUP('$') 
DIECI DB 10

ret




