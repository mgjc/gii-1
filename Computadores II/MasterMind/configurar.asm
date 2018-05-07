		.module	configurar

		.globl	configurar


fin		.equ	0xFF01
teclado	.equ	0xFF02
pantalla	.equ	0xFF00

	
		.globl	configuracion
		.globl	imprime_cadena
		.globl 	vidas
		.globl	limpia_pantalla
		.globl	retrocede
		
		temp: .byte 0
	contador:.byte 9

configurar:
		jsr limpia_pantalla
		ldx	#configuracion
		jsr	imprime_cadena

leer.decenas: 
		
		lda	teclado
		cmpa	#'0
		bls	retro.d
		cmpa	#'9
		bhi	retro.d


leer.unidades:

		ldb	teclado
		cmpb	#'0
		blo	retro.u
		cmpb	#'9
		bhi	retro.u

prosigue:
		suba #'0
		sta temp

bucle:
		addb temp
		stb vidas
		lda contador
		deca
		sta contador
		bmi acaba
		ldb vidas
		bra bucle

acaba:
		subb #'0
		stb vidas

		rts

retro.d:
	ldx #retrocede
	jsr imprime_cadena
	jmp leer.decenas

retro.u:
	cmpb #'\n
	beq prosigue.nuevo
	ldx #retrocede
	jsr imprime_cadena
	jmp leer.unidades

prosigue.nuevo:
	suba #'0
	sta vidas
	rts
