	.module	random

	.globl	cifra1
	.globl	cifra2
	.globl	cifra3
	.globl	cifra4
	.globl	numero1
	.globl	numero2
	.globl	numero3
	.globl	numero4
	.globl	aciertos
	.globl	coincidencias
	.globl	random
	.globl	cambiaNumeros
	.globl	comparaNumeros
	.globl	semilla

random:

	ldb	#5
	mul
	addd	#7
	stb	semilla
	andb	#0b00000111
	incb
	addb	#'0
	stb	cifra1
	lda	semilla

	ldb	#5
	mul
	addb	#7
	stb	semilla
	andb	#0b00000111
	incb
	addb	#'0
	stb	cifra2
	lda	semilla

	ldb	#5
	mul
	addb	#7
	stb	semilla
	andb	#0b00000111
	incb
	addb	#'0
	stb	cifra3
	lda	semilla

	ldb	#5
	mul
	addb	#7
	stb	semilla
	andb	#0b00000111
	incb
	addb	#'0
	stb	cifra4

	clra
	clrb
	rts

cambiaNumeros:
	lda	cifra1
	cmpa	#'7
	beq	salta11
	cmpa	#'8
	beq	salta12
	bne	sigue2

salta11:
	lda	#'3
	sta	cifra1
	bra	sigue2
salta12:
	lda	#'4
	sta	cifra1

sigue2:
	lda	cifra2
	cmpa	#'7
	beq	salta21
	cmpa	#'8
	beq	salta22
	bne	sigue3

salta21:
	lda	#'3
	sta	cifra2
	bra	sigue3
salta22:
	lda	#'4
	sta	cifra2

sigue3:
	lda	cifra3
	cmpa	#'7
	beq	salta31
	cmpa	#'8
	beq	salta32
	bne	sigue4

salta31:
	lda	#'3
	sta	cifra3
	bra	sigue4
salta32:
	lda	#'4
	sta	cifra3

sigue4:
	lda	cifra4
	cmpa	#'7
	beq	salta41
	cmpa	#'8
	beq	salta42
	bne	acabar

salta41:
	lda	#'3
	sta	cifra4
	bra	acabar
salta42:
	lda	#'4
	sta	cifra4

acabar:
	rts

comparaNumeros:

	lda	numero1
	cmpa	cifra1
	beq	coincide.Primero
	cmpa	cifra2
	beq	acierta.Primero
	cmpa	cifra3
	beq	acierta.Primero
	cmpa	cifra4
	beq	acierta.Primero
	bne	Compara.DosNumeros

coincide.Primero:
	inc	coincidencias
acierta.Primero:
	inc	aciertos

Compara.DosNumeros:

	lda	numero2
	cmpa	cifra1
	beq	acierta.Segundo
	cmpa	cifra2
	beq	coincide.Segundo
	cmpa	cifra3
	beq	acierta.Segundo
	cmpa	cifra4
	beq	acierta.Segundo
	bne	Compara.TresNumeros

coincide.Segundo:
	inc	coincidencias
acierta.Segundo:
	inc	aciertos

Compara.TresNumeros:

	lda	numero3
	cmpa	cifra1
	beq	acierta.Tercero
	cmpa	cifra2
	beq	acierta.Tercero
	cmpa	cifra3
	beq	coincide.Tercero
	cmpa	cifra4
	beq	acierta.Tercero
	bne	Compara.CuatroNumeros

coincide.Tercero:
	inc	coincidencias
acierta.Tercero:
	inc	aciertos

Compara.CuatroNumeros:

	lda	numero4
	cmpa	cifra1
	beq	acierta.Cuarto
	cmpa	cifra2
	beq	acierta.Cuarto
	cmpa	cifra3
	beq	acierta.Cuarto
	cmpa	cifra4
	beq	coincide.Cuarto
	bne	acaba.Comparacion

coincide.Cuarto:
	inc	coincidencias
acierta.Cuarto:
	inc	aciertos

acaba.Comparacion:
	rts
