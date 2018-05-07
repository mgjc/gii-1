	.module limpia

	.globl limpia
	.globl imprime_cadena
	.globl limpia_pantalla

limpia_pantalla:
	ldx #limpia
	jsr imprime_cadena
	rts
