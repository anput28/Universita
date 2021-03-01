;riceve una stringa in input, sposta le minuscole in un altro array e se ci sono numeri
;li somma e stampa il risultato

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

MOV CH, 0
MOV CL, stringa[1]
MOV SI, 2     ;indice stringa
MOV DI, 0     ;indice minuscole
MOV BL, 'a'

CICLO: CMP stringa[SI], BL
       JGE copia
       JMP control
copia: MOV AL, stringa[SI]
       MOV minuscole[DI], AL
       INC DI
       JMP salta
control: CMP stringa[SI], '9'
         JG salta
         CMP stringa[SI], '0'
         JL salta
         MOV AL, stringa[SI]
         SUB AL, '0'
         ADD numeri, AL
salta:   INC SI
LOOP CICLO

MOV AH, 0
MOV AL, numeri
DIV DIECI

MOV arrNum[0], AL
MOV arrNum[1], AH
ADD arrnum[0], '0' 
ADD arrnum[1], '0'

VISUALIZZA acapo 
VISUALIZZA msg2
VISUALIZZA minuscole   
VISUALIZZA acapo 
VISUALIZZA msg3
VISUALIZZA arrNum

;termine programma
MOV AH, 4CH
INT 21H

;dichiarazione variabili
msg1 DB 'Inserire una stringa di caratteri random -> $'
msg2 DB 'Minuscole concatenate: $' 
msg3 DB 'Somma delle cifre: $'
acapo DB 13,10,'$'
stringa DB 21, ?, 21 DUP('$') 
minuscole DB 20 DUP('$')
numeri DB 0 
arrNum DB 3 DUP('$')
DIECI DB 10
ret