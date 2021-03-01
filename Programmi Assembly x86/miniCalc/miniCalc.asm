org 100h 
MACRO VISUALIZZA str
    MOV AH,09H
    LEA DX, str
    INT 21H
ENDM

MACRO LEGGI num
    MOV AH, 01H
    INT 21H
    MOV num, AL
ENDM
;-----------------------------------;
VISUALIZZA msg1  
LEGGI num1
VISUALIZZA acapo
VISUALIZZA msg1
LEGGI num2
VISUALIZZA acapo 

SUB num1, '0'
SUB num2, '0'

RIPETI:     VISUALIZZA msg3
            VISUALIZZA acapo
            VISUALIZZA addizione
            VISUALIZZA acapo
            VISUALIZZA sottrazione
            VISUALIZZA acapo
            VISUALIZZA moltiplicazione
            VISUALIZZA acapo 
            VISUALIZZA scegli
            LEGGI scelta  
            VISUALIZZA acapo

            CMP scelta, '0'
            JE RIPETI
            CMP scelta, '5'
            JGE RIPETI
            CMP scelta, '1'
            JE  addiz
            CMP scelta, '2'
            JE sottr
            CMP scelta, '3'
            JE molt
            
addiz: MOV AL, num1
       ADD AL, num2
       MOV AH, 0
       DIV DIECI 
       MOV risu[0], AL
       MOV risu[1], AH 
       ADD risu[0], '0' 
       ADD risu[1], '0'
       JMP STAMPA

sottr: MOV AL, num1
       CMP AL, num2
       JGE lascia
       SUB num2, AL
       MOV AL, num2
       MOV risu[0], AL 
       ADD risu[0], '0'
       JMP STAMPA
lascia:SUB AL, num2
       MOV risu[0], AL
       ADD risu[0], '0'
       JMP STAMPA
       
molt: MOV AH,0
      MOV AL, num1
      MUL num2
      DIV DIECI
      MOV risu[0], AL
      MOV risu[1], AH 
      ADD risu[0], '0'
      ADD risu[1], '0'
      JMP STAMPA 
       
          
STAMPA: VISUALIZZA acapo
        VISUALIZZA msg2
        VISUALIZZA risu
   

;termine programma 
MOV AH, 4CH
INT 21H


;dichiarazione variabili
msg1 DB 'Inserire un numero -> $'
msg2 DB 'Risultato: $'
msg3 DB 'Scegli una operazione: $'
addizione DB '1) Addizione$'
sottrazione DB '2) Sottrazione$'
moltiplicazione DB '3) Moltiplicazione$'
scegli DB '-> $'
acapo DB 13,10,'$'
num1 DB ?
num2 DB ?
scelta DB ?  
risu DB 3 DUP('$')
DIECI DB 10


ret




