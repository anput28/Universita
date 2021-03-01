; programma che inserire una stringa di max 20 caratteri, richiedere di insierire un carattere e verifica se il carattere inserito è presente
;due volte
org 100h 
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM


VISUALIZZA msg1
MOV AH, 0AH
LEA DX, stringa
INT 21H
VISUALIZZA acapo
VISUALIZZA msg4 
MOV AH, 01H
INT 21H  
MOV char, AL
VISUALIZZA acapo

MOV CH, 0
MOV CL, stringa[1]
MOV SI, 2

MOV AL, char
MOV char, 0
CICLO: CMP AL, stringa[SI]
       JE conta  
       JMP contin
conta: INC char
contin:INC SI
       LOOP CICLO
       
ADD char, '0'
CMP char, '0'
JE stampa1
JMP stampa2
stampa1: VISUALIZZA msg3
           JMP fine
stampa2: VISUALIZZA msg2    
         VISUALIZZA char
         VISUALIZZA msg5
         
fine:;termina programma
        MOV AH, 4CH
        INT 21H



;dichiarazione variabili
msg1 DB 'Inserire stringa: $' 
msg2 DB 'Carattere presente $'
msg5 DB ' volte$'
msg3 DB 'Carattere NON presente$'  
msg4 DB 'Inserire il carattere da cercare: $'
acapo DB 13,10,'$'
stringa DB 21, ?, 21 DUP('$')
char DB ?,'$'

ret




