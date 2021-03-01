;conteggio dei multipli di 5 in un dato vettore

org 100h
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM 

MOV CH, 0
MOV CL, 7
MOV SI, 0

CICLO: MOV AH, 0
       MOV AL, array[SI]
       DIV CINQUE
       CMP AH, 0
       JE multiplo
       JMP continua  
multiplo: INC multipli
continua: INC SI
LOOP CICLO

ADD multipli, '0'

VISUALIZZA msg1
VISUALIZZA multipli

;termine programma
MOV AH, 4CH
INT 21H


;dichiarazione variabili
acapo DB 13,10,'$'
msg1 DB 'I multipli di 5 sono $'
array DB 87,35,23,65,50,27,15,61
CINQUE DB 5 
multipli DB 0, '$'

ret