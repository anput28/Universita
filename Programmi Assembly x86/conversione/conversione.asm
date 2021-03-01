;convertire un nibble in un numero decimale

org 100h 
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM

MACRO LEGGI num 
    MOV AH, 0AH
    LEA DX, num
    INT 21H
ENDM 

VISUALIZZA msg1
LEGGI nibble 

MOV SI, 2
MOV CH, 0
MOV CL, nibble[1]
CICLO: SUB nibble[SI], '0'
       INC SI 
       LOOP CICLO
       
       MOV SI, 2
            
       CMP nibble[SI], 1
       JE convert1 
       JMP salta1 
            
convert1: MOV DI, 3
          DEC DI
          MOV AH, 0
          MOV AL, 2 
          MOV BL, 2
 conti:   MUL BL 
          DEC DI
          CMP DI, 0
          JNE conti
          MOV uno, AL

salta1: INC SI
       
       CMP nibble[SI], 1
       JE convert2 
       JMP salta2
       
convert2: MOV AH, 0
          MOV AL, 2
          MUL AL 
          MOV due, AL
          
 salta2:INC SI
        CMP nibble[SI], 1
        JE convert3
        JMP salta3
 
convert3: MOV AL,2
          MOV tre, AL
          
 salta3:  INC SI
          CMP nibble[SI], 1
          JE convert4
          JMP salta4 
          
 convert4: MOV AL, 1
           MOV quattro, AL
           
 salta4: MOV AL, uno
         ADD AL, due
         ADD AL, tre
         ADD AL, quattro
         
         MOV AH, 0
         DIV DIECI
         MOV risu[0], AL
         MOV risu[1], AH
         
         ADD risu[0], '0'
         ADD risu[1], '0'
         
         VISUALIZZA acapo
         VISUALIZZA msg2
         VISUALIZZA risu 
 
;termina
MOV AH, 4CH
INT 21H
         
         
         

;dichiarazione variabili
msg1 DB 'Inserire 4 bit -> $'
msg2 DB 'Conversione -> $' 
acapo DB 13,10,'$'
nibble DB 5, ?, 5 DUP('$') 
risu DB 3 DUP('$') 
uno DB 0
due DB 0
tre DB 0
quattro DB 0 
DIECI DB 10
ret




