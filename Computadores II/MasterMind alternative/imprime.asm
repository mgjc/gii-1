	.module imprime

pantalla	.equ	0xFF00

	.globl imprime_cadena

imprime_cadena:

	lda	,x+
	beq	acaba
	sta	pantalla
	bra	imprime_cadena

acaba:
	rts
