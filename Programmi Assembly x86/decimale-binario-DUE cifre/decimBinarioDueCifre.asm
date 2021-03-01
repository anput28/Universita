
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h 
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM

MOV SI, 7 
MOV CH, 0
MOV CL, 8

MOV AL, num
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
  MOV CL, 8
  MOV SI, 7
  CICLO2: ADD binario[SI], '0'
          DEC SI
          LOOP CICLO2

  VISUALIZZA msg2
  VISUALIZZA binario

MOV AH, 4CH
INT 21H

;dichiarazione variabili  
msg2 DB 'Numero in binario -> $'
num DB 45
binario DB 9 DUP('$')  
DUE DB 2

ret




