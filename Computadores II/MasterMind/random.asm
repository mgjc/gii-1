	.module random

	.globl random

	pantalla .equ 0xFF00

	.globl Q
	.globl W
	.globl E
	.globl R
	.globl dif
	.globl imprime_cadena
	.globl ensenaSecuencia

random:

;A
	ldb #17
	mul
	addd #3
	tfr d,y
	clra
	andb #0b00000111
	addd #'0
	addd #1
	std Q
	tfr y,d
	exg a,b
;B
	ldb #17
	mul
	addd #3
	tfr d,y
	clra
	andb #0b00000111
	addd #'0
	addd #1
	std W
	tfr y,d
	exg a,b
;C
	ldb #17
	mul
	addd #3
	tfr d,y
	clra
	andb #0b00000111
	addd #'0
	addd #1
	std E
	tfr y,d
	exg a,b
;D	
	ldb #17
	mul
	addd #3
	tfr d,y
	clra
	andb #0b00000111
	addd #'0
	addd #1
	std R
	tfr y,d

	lda dif
	cmpa #'1
	beq sigueI
	jmp sal

sigueI:

	ldd Q
	cmpd #'6
	bhi haz.algoQ
	ldd W
	cmpd #'6
	bhi haz.algoW
	ldd E
	cmpd #'6
	bhi haz.algoE
	ldd R
	cmpd #'6
	bhi haz.algoR
	jmp asegurate

haz.algoQ:
	ldb #'1
	std Q
	bra sigueI
haz.algoW:
	ldb #'1
	std W
	bra sigueI
haz.algoE:
	ldb #'1
	std E
	bra sigueI
haz.algoR:
	ldb #'1
	std R
	bra sigueI

asegurate:
	ldd Q
	cmpd W
	beq aumenta.Q
	cmpd E
	beq aumenta.Q
	cmpd R
	beq aumenta.Q
	ldd W
	cmpd E
	beq aumenta.W
	cmpd R
	beq aumenta.W
	ldd E
	cmpd R
	beq aumenta.E
	jmp sal

aumenta.Q:
	incb
	std Q
	bra asegurate

aumenta.W:
	incb
	std W
	bra asegurate

aumenta.E:
	incb
	std E
	bra asegurate

haz.ocho.A:
	ldd #'2
	std Q

sal:
	lda #'\n
	sta pantalla
	sta pantalla
	sta pantalla
	ldx #ensenaSecuencia
	jsr imprime_cadena
	ldd Q
	stb pantalla
	ldd W
	stb pantalla
	ldd E
	stb pantalla
	ldd R
	stb pantalla
	rts
