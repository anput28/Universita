;inserire da tastiera due array di 4 elementi binari, effettuare l'operazione di AND e stampare il risultato

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
LEGGI nibble1
VISUALIZZA acapo 
VISUALIZZA msg1
LEGGI nibble2
VISUALIZZA acapo 

;effettuo la AND
MOV SI, 2 
MOV DI,0
MOV CH,0
MOV CL, 4
CICLO:      CMP nibble1[SI], '0'                         
            JE zero                                   
            CMP nibble2[SI], '0' 
            JE zero
            JMP uno
 zero:      MOV risu[DI], '0'
            JMP continua
 uno:       MOV risu[DI], '1'
 continua: INC SI 
           INC DI
 LOOP CICLO
 
 VISUALIZZA msg2
 VISUALIZZA risu
 
 ;termine programma 
 MOV AH, 4CH
 INT 21H     

;dichiarazione variabili
msg1 DB 'Inserire quattro bit -> $' 
msg2 DB 'Risultato: $'
acapo DB 13,10,'$'
nibble1 DB 5,?,5 DUP('$')  
nibble2 DB 5,?,5 DUP('$')  
risu DB 5 DUP('$')

ret




