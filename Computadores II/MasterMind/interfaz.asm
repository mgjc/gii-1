	.module interfaz

pantalla .equ 0xFF00

	.globl interfaz
	.globl aciertos
	.globl coincidencias
	.globl imprime_cadena
	.globl tab2
	.globl tab3
	.globl tab4
	.globl vidas
	.globl cont

cont: .byte 0

interfaz:

	ldx #tab2
	jsr imprime_cadena
	ldb aciertos
	addb #'0
	stb pantalla

	ldx #tab3
	jsr imprime_cadena
	ldb coincidencias
	addb #'0
	stb pantalla

	ldx #tab4
	jsr imprime_cadena

	ldb vidas

bucle:
	subb #10
	bmi sal
	inc cont
	bra bucle

sal:
	addb #10
	lda cont
	adda #'0
	addb #'0
	sta pantalla
	stb pantalla

	ldb #'\n
	stb pantalla

	rts
