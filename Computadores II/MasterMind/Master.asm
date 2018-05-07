fin		.equ 0xFF01
teclado	.equ 0xFF02
pantalla	.equ 0xFF00

.globl menu
.globl vidas

.globl imprime_cadena
.globl limpia_pantalla
.globl jugada
.globl configurar
.globl muestra_instrucciones

programa:

	ldu	#0xF000

mostrar.menu:

	clra
	clrb
	jsr	limpia_pantalla
	ldx	#menu
	jsr	imprime_cadena
	clra
	lda	teclado

	cmpa #'1
	beq jugar
	blo mostrar.menu
	cmpa #'2
	beq conf
	cmpa #'3
	beq inst
	cmpa #'4
	beq salir
	bhi mostrar.menu

jugar:
	jsr limpia_pantalla
	ldd vidas
	addb #23
	jsr jugada
	jmp mostrar.menu

conf:
	jsr limpia_pantalla
	jsr configurar
	jmp mostrar.menu

inst:
	jsr limpia_pantalla
	jsr muestra_instrucciones
	lda teclado
	clra
	jmp mostrar.menu

salir:

	lda #'\n
	sta pantalla
	clra
	sta fin

	.area FIJA(ABS)
	.org 0xFFFE
	.word programa
