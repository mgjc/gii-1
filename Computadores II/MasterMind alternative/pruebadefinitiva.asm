fin     		.equ 	0xFF01
teclado		.equ	0xFF02
pantalla 	.equ 	0xFF00

		.globl 	menu
  		.globl 	imprime_cadena
		.globl   instrucciones
		.globl	dificultad
		.globl	configuravidas
		.globl	vidas
		.globl	limpia
		.globl	jugando
		.globl	vidas
		.globl	cifra1
		.globl 	cifra2
		.globl	cifra3
		.globl	cifra4
		.globl 	iguales
		.globl	dificult
		.globl	semilla
		.globl	introSemilla
		.globl	numero1
		.globl	numero2
		.globl	numero3
		.globl	numero4
		.globl	generando
		.globl	random
		.globl	presiona
		.globl	temp
		.globl	aciertos
		.globl	coincidencias
		.globl	ganador
		.globl	perdedor
		.globl	cambiaNumeros
		.globl	comparaNumeros
		.globl	mensajeVidas
		.globl	mensajeCoincidencias
		.globl	mensajeAciertos

programa:	

	lds #0xF000
	ldx #limpia
	jsr imprime_cadena

elige:
	
	ldx	#menu
	jsr	imprime_cadena
	lda 	teclado

	cmpa	#'1
	beq	jugar
	blo	programa
	cmpa	#'2
	beq	instruccion
	cmpa	#'3
	beq	configvidas
	cmpa	#'4
	bhi 	programa
	jmp	acabar

instruccion:
	ldx	#limpia
	jsr	imprime_cadena
	ldx	#instrucciones
	jsr	imprime_cadena
	lda	teclado
	clra
	jmp	programa

configvidas:
	ldx	#limpia
	jsr	imprime_cadena
	ldx	#configuravidas
	jsr	imprime_cadena
	clra
	lda	teclado
	cmpa	#'0
	bls	configvidas
	cmpa	#'9
	bhi	configvidas
	sta	vidas
	sta	temp
	jmp	programa

jugar:
	ldx	#limpia
	jsr	imprime_cadena
	ldx	#dificultad
	jsr	imprime_cadena
	lda	teclado
	sta	dificult
	cmpa	#'1
	blo	jugar
	beq	Semilla
	cmpa	#'2
	bhi	jugar

Semilla:
	ldx	#limpia
	jsr	imprime_cadena
	ldx	#introSemilla
	jsr	imprime_cadena
	lda	teclado
	cmpa	#'0
	blo	Semilla
	cmpa	#'9
	bhi	Semilla
	sta	semilla
	suba	#'0
	jsr	random
	lda	dificult
	cmpa	#'2
	beq	genera
	jsr	cambiaNumeros

genera:
	ldx	#generando
	jsr	imprime_cadena
	lda	cifra1
	sta	pantalla
	lda	cifra2
	sta	pantalla
	lda	cifra3
	sta	pantalla
	lda	cifra4
	sta	pantalla
	lda	#')
	sta	pantalla
	lda	#'\n
	sta	pantalla
	lda	#presiona
	jsr	imprime_cadena
	lda	dificult
	cmpa	#'2
	lbeq	jugardificil

jugarfacil:
	clra
	sta	aciertos
	sta	coincidencias
	lda	vidas
	cmpa	#'0
	lbeq	finalPerdedor
	dec	vidas
	ldx	#jugando
	jsr	imprime_cadena

	lda	teclado
	sta	numero1
	lda	teclado
	sta	numero2
	lda	teclado
	sta	numero3
	lda	teclado
	sta	numero4
	
	lda	numero1
	jsr	rango1
	cmpa	numero2
	lbeq	error1
	cmpa	numero3
	lbeq	error1
	cmpa	numero4
	lbeq	error1

	lda	numero2
	jsr	rango1
	cmpa	numero3
	lbeq	error1
	cmpa	numero4
	lbeq	error1
	
	lda	numero3
	jsr	rango1
	cmpa	numero4
	lbeq	error1
	
	lda	numero4
	jsr	rango1

	jsr	comparaNumeros
	ldx	#mensajeAciertos
	jsr	imprime_cadena
	lda	aciertos
	adda	#'0
	sta	pantalla
	ldx	#mensajeCoincidencias
	jsr	imprime_cadena
	lda	coincidencias
	adda	#'0
	sta	pantalla
	ldx	#mensajeVidas
	jsr	imprime_cadena
	lda	vidas
	sta	pantalla
	lda	#'\n
	sta	pantalla
	clra
	lda	coincidencias
	cmpa	#4
	beq	finalGanador
	jmp	jugarfacil

finalPerdedor:
	ldx	#perdedor
	jsr	imprime_cadena
	ldx	#presiona
	jsr	imprime_cadena
	lda	teclado
	lda	temp
	sta	vidas
	jmp	programa

finalGanador:
	ldx	#ganador
	jsr	imprime_cadena
	ldx	#presiona
	jsr	imprime_cadena
	lda	teclado
	lda	temp
	sta	vidas
	jmp	programa

rango:
	cmpa	#'8
	bhi	mensaje_de_error
	cmpa	#'0
	bls	mensaje_de_error	
	rts	

rango1:
	cmpa	#'6
	bhi	error1
	cmpa	#'0
	bls	error1
	rts

mensaje_de_error:	
	lda	#'\n
	sta	pantalla
	inc	vidas
	ldx	#iguales
	jsr	imprime_cadena
	jmp	jugardificil

error1:
	lda	#'\n
	sta	pantalla
	inc	vidas
	ldx	#iguales
	jsr	imprime_cadena
	jmp	jugarfacil

jugardificil:
	clra
	sta	aciertos
	sta	coincidencias
	lda	vidas
	cmpa	#'0
	beq	finalPerdedor
	dec	vidas
	ldx	#jugando
	jsr	imprime_cadena
	clra
	lda	teclado
	sta	numero1
	lda	teclado
	sta	numero2
	lda	teclado
	sta	numero3
	lda	teclado
	sta	numero4

	lda	numero1
	jsr	rango	
	cmpa	numero2
	lbeq	mensaje_de_error
	cmpa	numero3
	lbeq	mensaje_de_error
	cmpa	numero4
	lbeq	mensaje_de_error
	
	lda	numero2
	jsr	rango	
	cmpa	numero3
	lbeq	mensaje_de_error
	cmpa	numero4
	lbeq	mensaje_de_error

	lda	numero3
	jsr	rango	
	cmpa	numero4
	lbeq	mensaje_de_error
	
	lda	numero4
	jsr	rango
	
	jsr	comparaNumeros
	ldx	#mensajeAciertos
	jsr	imprime_cadena
	lda	aciertos
	adda	#'0
	sta	pantalla
	ldx	#mensajeCoincidencias
	jsr	imprime_cadena
	lda	coincidencias
	adda	#'0
	sta	pantalla
	ldx	#mensajeVidas
	jsr	imprime_cadena
	clra
	lda	vidas
	sta	pantalla
	lda	#'\n
	sta	pantalla
	clra
	lda	coincidencias
	cmpa	#4
	lbeq	finalGanador
	jmp	jugardificil
	
acabar: 	
	clra
	sta 	fin

 	.area FIJA (ABS)
	.org 	0xFFFE	; Vector de RESET
	.word 	programa
