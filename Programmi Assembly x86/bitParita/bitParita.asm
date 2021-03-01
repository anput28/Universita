;programma per determina la parità (pari) di una stringa di bit

org 100h 
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM

VISUALIZZA msg1
MOV AH, 0AH
LEA DX, bit
INT 21H

MOV SI, 2
MOV CH, 0
MOV CL, bit[1]
CICLO: CMP bit[SI], '1'
       JE conta
       JMP salta
 conta: INC cont
 salta: INC SI
        LOOP CICLO
        
 MOV AL, cont
 MOV AH,0
 MOV BL, 2
 DIV BL
 CMP AH, 0
 JE uno
 JMP zero
 uno: MOV parita, '1'
      JMP stampa
 zero:MOV parita, '0' 
 
 stampa: VISUALIZZA acapo
         VISUALIZZA msg2
         VISUALIZZA parita
         
MOV AH, 4CH
INT 21H

;dichiarazione variabili
msg1 DB 'Inserire una stringa di max 8 bit -> $'
msg2 DB 'Il bit di parita vale -> $'  
acapo DB 13,10,'$'
bit DB 9, ?, 9 DUP('$') 
cont DB ?
parita DB ?, '$'

ret




