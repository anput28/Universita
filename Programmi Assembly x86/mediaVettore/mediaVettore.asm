;media dei valori contenuti in un vettore

org 100h
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM

MACRO LEGGI num
    MOV AH, 0AH  
    LEA DX, num
    INT 21H
ENDM

VISUALIZZA msg1
LEGGI vettore
VISUALIZZA acapo  

;trasformo le stringhe in numeri veri e propri
MOV SI, 2
MOV CH, 0
MOV CL, vettore[1]
CICLO: SUB  vettore[SI], '0'
       INC SI
       LOOP CICLO
       
;sommo gli elementi del vettore
MOV SI, 2
MOV CH, 0
MOV CL, vettore[1]
MOV AX, 0
CICLO2: ADD AL, vettore[SI]
        INC SI
        LOOP CICLO2
        
;divido la somma per il numero di valori inseriti
DIV vettore[1]
MOV intero, AL
MOV resto, AH

ADD intero, '0'
ADD resto, '0'

VISUALIZZA msg2
VISUALIZZA intero
VISUALIZZA virgola
VISUALIZZA resto


 
;termine programma
MOV AH, 4CH
INT 21H

;dichiarazione variabili  
msg1 DB 'Inserire gli elementi del vettore -> $'
msg2 DB 'Media: $'  
acapo DB 13,10,'$'
virgola DB ',$'
vettore DB 11, ?, 11 DUP('$') 
intero DB ?,'$'
resto DB ?,'$'
ret




