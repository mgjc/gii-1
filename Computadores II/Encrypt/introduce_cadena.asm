	.module introduce

.globl introduce_cadena
.globl teclado
.globl pantalla
.globl contador

introduce_cadena:
	clra
	lda teclado
	cmpa #'\n
	beq acaba_leer
	cmpa #32
	beq recoge_caracter
	cmpa #'0
	blo introduce_cadena
	cmpa #'9
	blo recoge_caracter
	bhi comprueba_caracter

comprueba_caracter:
	cmpa #'a
	blo introduce_cadena
	cmpa #'z
	blo recoge_caracter
	bhi comprueba_CARACTER

comprueba_CARACTER:
	cmpa #'A
	blo introduce_cadena
	cmpa #'Z
	bhi introduce_cadena

recoge_caracter:
	inc contador
	pshu a
	bra introduce_cadena

acaba_leer:
	rts
