	.module jugar

	.globl jugada

fin		.equ 0xFF01
teclado	.equ 0xFF02
pantalla	.equ 0xFF00

	.globl aciertos
	.globl coincidencias
	.globl vidas
	.globl numeros
	.globl dificultad
	.globl codigo
	.globl retrocede
	.globl ganador
	.globl perdedor
	.globl dif
	.globl cont

	.globl H
	.globl J
	.globl K
	.globl L

	temp:			.byte 0
	temporal:	.word 0
	vid:			.byte 0

	.globl limpia_pantalla
	.globl generador
	.globl imprime_cadena
	.globl coincidir
	.globl interfaz

jugada:
	jsr generador
	jsr limpia_pantalla
	ldx #codigo
	jsr imprime_cadena
	ldb vidas
	stb vid

inicio.juego:

	ldb vidas
	cmpb #0
	beq mensaje.perdedor
	dec vidas
	lda #4
	sta numeros
	clra
	sta aciertos
	sta cont
	sta coincidencias
	lda #32
	sta pantalla

leer.numero:

	ldb teclado
	cmpb #'0
	bls prueba.leer
	lda dif
	cmpa #'1
	beq slow
	jmp hard

mensaje.perdedor:
	jmp juego.perdedor
prueba.leer:
	jmp vuelve.leer

slow:
	cmpb #'6
	bhi prueba.leer
	jmp continua
	
hard:
	cmpb #'8
	bhi prueba.leer

continua:

	dec numeros
	lda numeros
	cmpa #3
	bne compara.dos
	clra
	std H
	jmp leer.numero

compara.dos:
	cmpa #2
	bne compara.uno
	clra
	cmpd H
	beq prevuelve.leer
	std J
	jmp leer.numero

compara.uno:
	cmpa #1
	bne compara.cero
	clra
	cmpd H
	beq prevuelve.leer
	cmpd J
	beq prevuelve.leer
	std K
	jmp leer.numero

compara.cero:
	clra
	cmpd H
	beq prevuelve.leer
	cmpd J
	beq prevuelve.leer
	cmpd K
	beq prevuelve.leer
	std L
	jsr coincidir
	jsr interfaz
	lda coincidencias
	cmpa #4
	beq juego.ganador
	jmp inicio.juego

vuelve.leer:

	ldx #retrocede
	jsr imprime_cadena
	jmp leer.numero

prevuelve.leer:

	inc numeros
	jmp vuelve.leer

juego.ganador:
	ldx #ganador
	jsr imprime_cadena
	jmp acabar

juego.perdedor:
	ldx #perdedor
	jsr imprime_cadena

acabar:
	ldb vid
	stb vidas
	lda teclado
	clra
	rts
