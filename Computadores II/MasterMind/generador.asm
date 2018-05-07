	.module generadorDeCodigo

teclado .equ 0xFF02
pantalla .equ 0xFF00

	.globl generador
	.globl random
	.globl dif
	.globl multijugador
	.globl imprime_cadena
	.globl dificultad
	.globl multiplayer
	.globl limpia_pantalla
	.globl vidas
	.globl semilla

generador:

	ldx #dificultad
	jsr imprime_cadena
	ldb teclado
	cmpb #'1
	blo generador
	cmpb #'2
	bhi generador
	stb dif

opcion:

	jsr limpia_pantalla
	ldx #multijugador
	jsr imprime_cadena
	ldb teclado
	cmpb #'1
	beq multi
	blo opcion
	cmpb #'2
	bhi opcion
	beq rand

multi:
	jsr multiplayer
	jmp sal

rand:
	jsr limpia_pantalla
	ldx #semilla
	jsr imprime_cadena
	lda teclado
	cmpa #'0
	blo rand
	cmpa #'9
	bhi rand
	adda vidas
	jsr random

sal:
	rts
