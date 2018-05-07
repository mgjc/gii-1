fin     	.equ 	0xFF01
teclado		.equ	0xFF02
pantalla 	.equ 	0xFF00
    ;declaracion de subrutinas y variables
    .globl imprime
	.globl menu
	.globl lista
	.globl instrucciones

programa:	
    ;iniciar las pilas
	lds #0xA000
	ldu #0xB000
	

escoge:
    lda #'\n
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
	;muestra el menu
	ldx	#menu
	jsr	imprime
	;pide al usuario una opcion
	lda teclado
	;la opcion esta dentro de un rango?
	cmpa #'1
	beq	empezar
	;igual a 1: empieza a jugar
	;menor que 1: fuera de rango
	blo	escoge
	cmpa #'2
	beq	instrucc
	;igual a 2: muestra las instrucciones
	cmpa #'3
	;igual a 3: acaba
	;superior a 3: muestra el menu de nuevo
	bhi escoge
	bra	finaliza_programa

instrucc:
	lda #'\n
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
    sta pantalla
	ldx	#instrucciones
	jsr	imprime
	lda	teclado
	lbra escoge

empezar:
    jsr lista
	lbra escoge
	
finaliza_programa:
    lda #'\n
    sta pantalla	
	clra
	sta fin

 	.area FIJA (ABS)
	.org 	0xFFFE	; Vector de RESET
	.word 	programa
