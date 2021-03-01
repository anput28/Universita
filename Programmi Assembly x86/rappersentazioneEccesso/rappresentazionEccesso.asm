
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
MACRO VISUALIZZA str
    MOV AH, 09H
    LEA DX, str
    INT 21H
ENDM 

        VISUALIZZA msg1
        MOV AH, 0AH
        LEA DX, num
        INT 21H 
        CMP num[2], '-'
        JE salta
        JMP converti
    salta: MOV BL, num[2]
           MOV segno, BL 
           MOV BL, num[3]
           MOV num[2], BL
           SUB num[2], '0'
           MOV BL, num[2]
           SUB eccesso, BL
           JMP ok
    converti: SUB num[2], '0' 
           MOV BL, num[2]
            ADD eccesso, BL
            ;inizio conversione
        ok: MOV CH, 0
            MOV CL, 8 
            MOV SI, 7
            MOV AL, eccesso
      CICLO:MOV AH,0
            DIV DUE
            CMP AH, 0 
            JE zero
            JMP uno
     zero: MOV binario[SI], 0
           JMP continu
     uno:  MOV binario[SI], 1
     continu: DEC SI 
           LOOP CICLO
           
          MOV CH, 0
          MOV CL, 8
          MOV SI, 0
          CICLO2: ADD binario[SI], '0'
                  INC SI
                  LOOP CICLO2 
         
         VISUALIZZA acapo
         VISUALIZZA msg2
         VISUALIZZA binario[2]
;FINE
    MOV AH, 4CH
    INT 21H
        
;variabili
msg1 DB 'Inserire il numero da rappresentare-> $'   
msg2 DB 'Rappresentazione per eccesso: $'
acapo DB 13,10,'$'
binario DB 9 DUP('$')
eccesso DB 127     
num DB 3, ?,3 DUP('$')  
segno DB ?,'$' 
DUE DB 2
 
      
ret




