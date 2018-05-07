	.module instrucciones

	.globl imprime_cadena
	.globl instrucciones
	.globl muestra_instrucciones

muestra_instrucciones:
	pshs a
	ldx #instrucciones
	jsr imprime_cadena
	puls a
	rts
