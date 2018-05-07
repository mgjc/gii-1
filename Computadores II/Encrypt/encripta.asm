	.module encripta

.globl pantalla
.globl encriptador
.globl teclado
.globl continuar
.globl imprime_cadena
.globl limpia
.globl auxiliar
.globl contador

encriptador:

	ldx #limpia
	jsr imprime_cadena

encript:
	cmpu #0xE000
	beq acaba_U
	pulu a
	cmpa #32
	beq guarda_s
	suba contador
	suba auxiliar
	inc auxiliar

guarda_s:
	pshs a
	bra encript

acaba_U:

	cmps #0xEFFE
	beq acaba_S
	puls a
	pshu a
	sta pantalla
	bra acaba_U

acaba_S:
	ldx #continuar
	jsr imprime_cadena
	lda teclado
	rts
