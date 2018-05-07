fin	.equ 0xFF01
teclado	.equ 0xFF02
pantalla .equ 0xFF00

	.globl teclado
	.globl pantalla
	.globl menu
	.globl limpia
	.globl imprime_cadena
	.globl introduce_cadena
	.globl encriptador
	.globl desencriptador
	.globl comprueba2
	.globl comprueba3
	.globl auxiliar
	.globl intr
	.globl mensaje1
	.globl mensaje2

programa:
	lds #0xF000
	ldu #0xE000

muestra_menu:
	clra
	lda #1
	sta auxiliar
	ldx #limpia
	jsr imprime_cadena
	ldx #menu
	jsr imprime_cadena
	lda teclado
	cmpa #'1
	beq introduce
	blo muestra_menu
	cmpa #'2
	beq encripta
	cmpa #'3
	beq desencripta
	cmpa #'4
	beq acabar
	bhi muestra_menu

introduce:
	lda #1
	sta comprueba2
	cmpu #0xE000
	bne vaciaU
	ldx #limpia
	jsr imprime_cadena
	ldx #intr
	jsr imprime_cadena
	jsr introduce_cadena
	jmp muestra_menu

vaciaU:
	pulu a
	cmpu #0xE000
	bne vaciaU
	bra introduce

encripta:
	clra
	cmpa comprueba2
	beq muestra_menu
	lda #1
	sta auxiliar
	ldx #mensaje1
	jsr imprime_cadena
	clra
	jsr encriptador
	lda #1
	sta comprueba3
	clra
	sta comprueba2
	jmp muestra_menu

desencripta:
	clra
	cmpa comprueba3
	beq muestra_menu
	ldx #mensaje2
	jsr imprime_cadena
	clra
	jsr desencriptador
	ldb #'3
	stb pantalla
	stb pantalla
	stb pantalla

	clra
	sta comprueba3
	inca
	sta comprueba2
	clra
	jmp muestra_menu

acabar:

	clra
	sta fin

	.area FIJA (ABS)
	.org 0xFFFE
	.word programa
