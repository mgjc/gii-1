fin     	.equ 	0xFF01
teclado		.equ	0xFF02
pantalla 	.equ 	0xFF00
    ;hacemos que las diferentes subrutinas se puedan ejecutar en este fichero
    .globl imprime_cadena
    .globl instrucc
	.globl mostrar_menu
	.globl lista

programa:	
    ;iniciamos las pilas
	lds #0xD000
	ldu #0xE000
	

elige:
    ;llamamos a la subrutina mostrar_menu
    jsr mostrar_menu
	;recogemos una opcion por teclado
	lda teclado
	;comparamos si la opcion esta dentro de un rango
	cmpa #'1
	beq	opcion1
	;si el caracter introducido tiene un codigo ascii inferior al codigo ascii
	;del 1 volvera a mostrar el menu borrando la pantalla previamente
	blo	elige
	cmpa #'2
	beq	opcion2
	cmpa #'3
	;si el caracter introducido tiene un codigo ascii superior al codigo ascii
	;del 3 volvera a mostrar el menu borrando la pantalla previamente
	bhi elige
	bra	opcion3

opcion2:
	jsr instrucc
	bra	elige

opcion1:
    jsr lista
	bra elige
	
opcion3:
    lda #'\n
    sta pantalla	
	clra
	sta fin

 	.area FIJA (ABS)
	.org 	0xFFFE	; Vector de RESET
	.word 	programa
