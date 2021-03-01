
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h 
MACRO VISUALIZZA stringa
    MOV AH, 09H
    LEA DX, stringa
    INT 21H
ENDM

VISUALIZZA msg1  
MOV AH, 0AH
LEA DX, numeri
INT 21H
VISUALIZZA acapo

MOV CH, 0
MOV CL, numeri[1]  
MOV SI, 2

ciclo: SUB numeri[SI], '0'
       INC SI
       LOOP ciclo

MOV CH,0
MOV CL, numeri[1]       
MOV SI, 2 
MOV BL, 0
ciclo2: ADD BL, numeri[SI]
        INC SI
        LOOP ciclo2 
        
CMP BL, 50
JG stampa1
VISUALIZZA msg3 
JMP fine
stampa1: VISUALIZZA msg2

fine: MOV AH, 4CH
      INT 21H

;dichiarazione variabili
msg1 DB 'Inserire la stringa di numeri interi -> $'  
acapo DB 13,10, '$'
msg2 DB 'Somma maggiore di 50$'
msg3 DB 'Somma minore di 50$'
numeri DB 11, ? ,11 DUP('$')

ret




