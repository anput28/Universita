;generazione di segnali di clock (massimo 20 bit)

org 100h  
;macro per la scrittura a video
MACRO VISUALIZZA stringa
    MOV AH, 09H
    LEA DX, stringa
    INT 21H
ENDM 

;macro per la lettura dell'input
MACRO LEGGI n
    MOV AH, 01H
    INT 21H 
    SUB AL, '0'
    MOV n, AL
ENDM 


VISUALIZZA msg1 
LEGGI clock1[0]
;calcolo meta' primo numero 
MOV AH, 0
DIV DUE 
MOV clock1[1], AL 

VISUALIZZA acapo
VISUALIZZA msg2
LEGGI clock2[0]
;calcolo meta' secondo numero 
MOV AH, 0
DIV DUE 
MOV clock2[1], AL
  
VISUALIZZA acapo
VISUALIZZA msg3
LEGGI clock3[0]
;calcolo meta' terzo numero 
MOV AH, 0
DIV DUE 
MOV clock3[1], AL 

;--------------------------------;
;generazione impulsi PRIMO clock
MOV SI, 1
MOV CH, 0
MOV CL, 20 
    
MOV DL, clock1[1]
MOV DH, 1
CICLO1:     CMP DH, clock1[0]
            JLE control
            MOV DH,1
            JMP CICLO1
control:    CMP DH, DL
            JLE uno
            JMP zero
uno:        MOV AL, 1
            MOV clock1[SI], AL
            JMP continua
zero:       MOV AL, 0
            MOV clock1[SI], AL
            JMP continua
continua:   INC SI
            INC DH
LOOP CICLO1 

;--------------------------------;
;generazione impulsi SECONDO clock
MOV SI, 1
MOV CH, 0
MOV CL, 20 
    
MOV DL, clock2[1]
MOV DH, 1
CICLO2:     CMP DH, clock2[0]
            JLE control2
            MOV DH,1
            JMP CICLO2
control2:    CMP DH, DL
            JLE uno2
            JMP zero2
uno2:        MOV AL, 1
            MOV clock2[SI], AL
            JMP continua2
zero2:       MOV AL, 0
            MOV clock2[SI], AL
            JMP continua2
continua2:   INC SI
            INC DH
LOOP CICLO2 

;--------------------------------;
;generazione impulsi TERZO clock
MOV SI, 1
MOV CH, 0
MOV CL, 20 
    
MOV DL, clock3[1]
MOV DH, 1
CICLO3:     CMP DH, clock3[0]
            JLE control3
            MOV DH,1
            JMP CICLO3
control3:    CMP DH, DL
            JLE uno3
            JMP zero3
uno3:        MOV AL, 1
            MOV clock3[SI], AL
            JMP continua3
zero3:       MOV AL, 0
            MOV clock3[SI], AL
            JMP continua3
continua3:   INC SI
            INC DH
LOOP CICLO3

;-------------------------------;
;conversione dei vettori in numeri ASCII

;PRIMO CLOCK
MOV CH,0
MOV CL, 20
MOV SI,1

CONV1: ADD clock1[SI],'0'
       INC SI
LOOP CONV1

;SECONDO CLOCK
MOV CH,0
MOV CL, 20
MOV SI,1

CONV2: ADD clock2[SI], '0'
       INC SI
LOOP CONV2
  
;TERZO CLOCK
MOV CH,0
MOV CL, 20
MOV SI,1

CONV3: ADD clock3[SI], '0'
       INC SI
LOOP CONV3 

VISUALIZZA acapo
VISUALIZZA primo
VISUALIZZA clock1+1  
VISUALIZZA acapo
VISUALIZZA secondo
VISUALIZZA clock2+1
VISUALIZZA acapo
VISUALIZZA terzo
VISUALIZZA clock3+1

;termine programma 
MOV AH, 4CH
INT 21H


;dichiarazione variabili 
msg1 DB 'Inserire durata primo ciclo di clock -> $' 
msg2 DB 'Inserire durata secondo ciclo di clock -> $' 
msg3 DB 'Inserire durata terzo ciclo di clock -> $' 
primo DB 'PRIMO CLOCK -> $' 
secondo DB 'SECONDO CLOCK -> $' 
terzo DB 'TERZO CLOCK -> $'
acapo DB 13,10,'$'
clock1 DB ?,?,20 DUP('$')
clock2 DB ?,?,20 DUP('$')
clock3 DB ?,?,20 DUP('$')
DUE DB 2


ret




