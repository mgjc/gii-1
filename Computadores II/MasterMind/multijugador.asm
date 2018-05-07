	.module multijugador

	.globl multiplayer

pantalla .equ 0xFF00
teclado .equ 0xFF02

	.globl dif
	.globl Q
	.globl W
	.globl E
	.globl R
	.globl imprime_cadena
	.globl jugador
	.globl limpia_pantalla
	.globl retrocede

temp:	.byte 0

multiplayer:

	jsr limpia_pantalla
	ldx #jugador
	jsr imprime_cadena
	lda #'1
	cmpa dif
	beq pasa.facil
	lda #'8
	sta temp
	bra lee.Q

pasa.facil:
	lda #'6
	sta temp

lee.Q:
	clra
	ldb teclado
	cmpb #'1
	blo vuelve.LeerQ
	cmpb temp
	bhi vuelve.LeerQ
	std Q

lee.W:
	clra
	ldb teclado
	cmpb #'1
	blo vuelve.LeerW
	cmpb temp
	bhi vuelve.LeerW
	cmpd Q
	beq vuelve.LeerW
	std W
lee.E:
	clra
	ldb teclado
	cmpb #'1
	blo vuelve.LeerE
	cmpb temp
	bhi vuelve.LeerE
	cmpd Q
	beq vuelve.LeerE
	cmpd W
	beq vuelve.LeerE
	std E
lee.R:
	clra
	ldb teclado
	cmpb #'1
	blo vuelve.LeerR
	cmpb temp
	bhi vuelve.LeerR
	cmpd Q
	beq vuelve.LeerR
	cmpd W
	beq vuelve.LeerR
	cmpd E
	beq vuelve.LeerR
	std R
	jmp sal

vuelve.LeerQ:
	ldx #retrocede
	jsr imprime_cadena
	jmp lee.Q

vuelve.LeerW:
	ldx #retrocede
	jsr imprime_cadena
	jmp lee.W

vuelve.LeerE:
	ldx #retrocede
	jsr imprime_cadena
	jmp lee.E

vuelve.LeerR:
	ldx #retrocede
	jsr imprime_cadena
	jmp lee.R

sal:
	rts
