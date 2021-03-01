;inserire da tastiera un numero tra 2 e 5 e calcolarne il fattoriale

org 100h 
MACRO VISUALIZZA stringa
    MOV AH,09H
    LEA DX, stringa
    INT 21H
ENDM

ripeti:     VISUALIZZA msg1
            ;inserisco il numero
            MOV AH,01H
            INT 21H
            MOV num, AL 
            SUB num, '0'
            VISUALIZZA acapo

            ;controllo che il numero sia compreso tra 2-5
            CMP num, 1
            JE ripeti
            CMP num, 6
            JGE ripeti
            
            ;calcolo il fattoriale
            MOV CH,0 
            MOV CL, num
            DEC CL
            
CICLO:      MOV AH,0
            MOV AL, CL
            MUL num
            MOV num, AL
            LOOP CICLO  
            
            ;spezzo il risultato che può essere a 2 o 3 cifre e lo metto in un array per avere i singoli numeri separati 
            ;in modo da poterli convertire in codici ASCII stampabili
            MOV AH,0
            MOV AL, num
            DIV DIECI 
            MOV risultato[2], AH
            MOV AH,0
            DIV DIECI
            MOV risultato[1], AH
            MOV risultato[0], AL
            
            ADD risultato[0], '0'
            ADD risultato[1], '0'
            ADD risultato[2], '0' 
            
            VISUALIZZA msg2 
            VISUALIZZA risultato
            
            ;termine programma 
            MOV AH,4CH
            INT 21H

;dichiarazione delle variabili
msg1 DB 'Inserire un numero tra 2 e 5 -> $'  
msg2 DB 'Risultato: $'
acapo DB 13,10,'$'
num DB ? 
risultato DB 4 DUP('$')
DIECI DB 10

ret




