;conteggio cifre pari e somma delle stesse

org 100h 

MACRO VISUALIZZA stringa
    MOV AH, 09H
    LEA DX, stringa
    INT 21H
ENDM

MACRO LEGGI num
    MOV AH, 0AH
    LEA DX, num
    INT 21H
ENDM

VISUALIZZA msg1
LEGGI array

MOV SI, 2 
MOV CX, 0
MOV CL, array[1]

CONVERTI: SUB array[SI], '0'
          INC SI
          LOOP CONVERTI
          
MOV SI,2
MOV CX, 0
MOV CL, array[1] 
MOV sommaPari, 0

CICLO: MOV AX,0
       MOV AL, array[SI]
       DIV DUE
       CMP AH, 0
       JE numPari
       JMP continua
numPari: MOV DL, array[SI] 
      ADD sommaPari, DL
      INC contPari
continua: INC SI
LOOP CICLO 

MOV AX,0
MOV AL, sommaPari
DIV DIECI

ADD AH, '0'
ADD AL, '0'
MOV somma[0], AL
MOV somma[1], AH            


VISUALIZZA acapo
VISUALIZZA msg2
VISUALIZZA contPari
VISUALIZZA acapo
VISUALIZZA msg3
VISUALIZZA somma


;termine programma
MOV AH, 4CH
INT 21H

;dichiarazione variabili
msg1 DB 'Inserire un sequenza di cifre: $'
msg2 DB 'I numeri pari sono -> $'
msg3 DB 'Somma numeri pari -> $'
acapo DB 13,10,'$'
array DB 11, ?, 11 DUP('$')
contPari DB '0', '$' 
sommaPari DB ? 
somma DB ?,?,'$'
DUE DB 2
DIECI DB 10
ret




