
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h  
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM

VISUALIZZA msg1
MOV AH, 01H
INT 21H 
SUB AL, '0' 
MOV SI, 3  
MOV CH, 0
MOV CL, 4

CICLO: MOV AH, 0
       DIV DUE
       CMP AH, 0 
       JE zero
       JMP uno
 zero: MOV binario[SI], 0
       JMP continu
 uno:  MOV binario[SI], 1
 continu: DEC SI 
       LOOP CICLO
        
esci: 
  MOV CH, 0
  MOV CL, 4
  MOV SI, 3
  CICLO2: ADD binario[SI], '0'
          DEC SI
          LOOP CICLO2
  
  VISUALIZZA acapo
  VISUALIZZA msg2
  VISUALIZZA binario

MOV AH, 4CH
INT 21H

;dichiarazione variabili
msg1 DB 'Inserire un numero-> $'   
msg2 DB 'Numero in binario -> $'
acapo DB 13,10,'$'
binario DB 5 DUP('$')  
DUE DB 2

ret




