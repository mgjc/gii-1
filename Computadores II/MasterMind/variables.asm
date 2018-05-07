	.module variables

 .globl Q
 .globl W
 .globl E
 .globl R
 .globl H
 .globl J
 .globl K
 .globl L

 .globl coincidencias
 .globl aciertos
 .globl vidas
 .globl numeros
 .globl dif

	Q: .word 0
	W: .word 0
	E: .word 0
	R: .word 0

	H: .word 0
	J: .word 0
	K: .word 0
	L: .word 0

	coincidencias: .byte 0
	aciertos:      .byte 0
	vidas:         .byte 14
	numeros:       .byte 0
	dif:				.byte 0
