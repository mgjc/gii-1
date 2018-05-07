	.module desencriptador

	.globl pantalla
	.globl desencriptador
	.globl continuar
	.globl imprime_cadena
	.globl teclado
	.globl limpia
	.globl auxiliar
	.globl contador

desencriptador:

	ldx #limpia
	jsr imprime_cadena

desencript:

	cmpu #0xE000
	beq acaba_u
	pulu a
	cmpa #32
	beq guarda_S
	adda contador
	adda auxiliar
	inc auxiliar

guarda_S:
	pshs a
	bra desencript

acaba_u:

	cmps #0xEFFF
	beq acabar_s
	puls a
	sta pantalla
	pshu a
	bra acaba_u

acabar_s:
	ldx #continuar
	jsr imprime_cadena
	lda teclado
	puls a
	clra
	rts
