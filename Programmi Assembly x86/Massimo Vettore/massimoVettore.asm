;massimo e minimo di un array di numeri

org 100h 

MACRO VISUALIZZA stringa
    MOV AH, 09H
    LEA DX, stringa
    INT 21H
ENDM

MACRO LEGGI n
    MOV AH, 01h  
    INT 21H
    MOV n, AL
    SUB n, '0'
ENDM

MOV SI, 0        ;inizializzo indice dell'array
MOV CX, 0        ;azzero il contatore
MOV CL, array[0] ;imposto il contatore al primo elemento dell'array, che rappresenta la grandezza   

;inserimento elementi nel vettore
INSERT: VISUALIZZA msg0 
        LEGGI array[SI]
        INC SI 
        VISUALIZZA acapo
        LOOP INSERT
         
MOV SI, 1   ;riporto l'indice a zero
MOV CL, 9  ;
MOV BL, array[0] ;BL rappresenta il minimo e lo inizializzo al primo elemento di array
MOV BH, array[0] ;BH rappresenta il massimo e lo inizializzo al primo elemento di array

;inizio a confrontare gli elementi dell'array
CICLO: CMP array[SI], BL
       JL minore
       CMP array[SI], BH
       JG maggiore 
       JMP continua
minore: MOV BL, array[SI]
        JMP continua
maggiore: MOV BH, array[SI]        
continua: INC SI
LOOP CICLO

MOV min, BL
MOV max, BH

ADD min, '0'
ADD max, '0'

VISUALIZZA msg1
VISUALIZZA max 
VISUALIZZA acapo
VISUALIZZA msg2
VISUALIZZA min

;termine del programma
MOV AH, 4CH
INT 21H  
       
;dichiarazione di variabili
msg0 DB 'Inserire elemento: $'
msg1 DB 'Massimo -> $'
msg2 DB 'Minimo -> $'
max DB ?, '$'
min DB ?, '$'
array DB 10,9 DUP(0)
acapo DB 13,10,'$'
ret




