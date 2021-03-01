;programma in cui viene generato un numero random a 2 cifre e bisogna indovinarlo. 

org 100h
MACRO VISUALIZZA stringa
    MOV AH,09H
    LEA DX, stringa
    INT 21H
ENDM 

MACRO LEGGI num
    MOV AH,0AH
    LEA DX, num
    INT 21H
ENDM

VISUALIZZA msg1
LEGGI numero                ;scelta del numero 
VISUALIZZA acapo

;generazione numero random
MOV AH, 2CH                         ;codice che restituisce la l'ora del sistema : CH = ora, CL = minuti, DH = secondi e DL = 1/100 di secondo
INT 21H
MOV AH,0
MOV AL, DL                          ;utilizzo il numero contenuto in DL come nuemero random 

DIV DIECI                          ;lo divido per 10 per poterlo mettere in un vettore al fine di confrontarlo con il numero dell'utente
ADD AH, '0'
ADD AL, '0' 
CMP AH, '0'
JE salta
MOV random[0], AH                   ;inverto apposta le unità con le decine per aggiungere un altro fattore che cambia il numero al fine
MOV random[1], AL                   ;di renderlo più pseudo-casuale possibile
JMP continua                  
salta: MOV random[0], AL 


continua:   VISUALIZZA acapo
            VISUALIZZA msg4  
            VISUALIZZA random 
            VISUALIZZA acapo

;confronto i due numeri
MOV SI, 2
MOV DI,0
MOV CH,0
MOV CL, 2

CICLO: MOV AL, numero[SI] 
       CMP AL, random[DI]
       JE verifica
       JMP peccato
 verifica: INC SI 
           INC DI
       LOOP CICLO
       
 VISUALIZZA msg2 
 JMP FINE 
 
 peccato: VISUALIZZA msg3

        ;termine programma
FINE:   MOV AH,4CH
        INT 21H

;dichiarazione variabili
msg1 DB 'Inserire un numero -> $'
msg2 DB 'Complimenti! Hai indovinato il numero$' 
msg3 DB 'Peccato, non hai indovinato$'
msg4 DB 'Numero generato -> $' 
acapo DB 13,10,'$'
numero DB 3,?,3 DUP('$')
random DB 3 DUP('$')
CENTO DB 100 
DIECI DB 10
ret




