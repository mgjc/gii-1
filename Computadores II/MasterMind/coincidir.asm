	.module coincidir

	.globl coincidir
	.globl coincidencias
	.globl aciertos
	.globl Q
	.globl W
	.globl E
	.globl R
	.globl H
	.globl J
	.globl K
	.globl L

coincidir:

	ldd L

sigue.D:
	cmpd R
	bne sigue.C
	inc aciertos
	inc coincidencias
	jmp sigue2.D

sigue.C:
	cmpd E
	bne sigue.B
	inc aciertos
	jmp sigue2.D

sigue.B:
	cmpd W
	bne sigue.A
	inc aciertos
	jmp sigue2.D

sigue.A:
	cmpd Q
	bne sigue2.D
	inc aciertos

;;;


sigue2.D:
	ldd K
	cmpd R
	bne sigue2.C
	inc aciertos
	jmp sigue3.D

sigue2.C:
	cmpd E
	bne sigue2.B
	inc aciertos
	inc coincidencias
	jmp sigue3.D

sigue2.B:
	cmpd W
	bne sigue2.A
	inc aciertos
	jmp sigue3.D

sigue2.A:
	cmpd Q
	bne sigue3.D
	inc aciertos

;;;


sigue3.D:
	ldd J
	cmpd R
	bne sigue3.C
	inc aciertos
	jmp sigue4.D

sigue3.C:
	cmpd E
	bne sigue3.B
	inc aciertos
	jmp sigue4.D

sigue3.B:
	cmpd W
	bne sigue3.A
	inc aciertos
	inc coincidencias
	jmp sigue4.D

sigue3.A:
	cmpd Q
	bne sigue4.D
	inc aciertos

;;;


sigue4.D:
	ldd H
	cmpd R
	bne sigue4.C
	inc aciertos
	jmp sal

sigue4.C:
	cmpd E
	bne sigue4.B
	inc aciertos
	jmp sal

sigue4.B:
	cmpd W
	bne sigue4.A
	inc aciertos
	jmp sal

sigue4.A:
	cmpd Q
	bne sal
	inc aciertos
	inc coincidencias

sal:
	rts
