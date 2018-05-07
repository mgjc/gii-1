	.module cadenas

.globl menu
.globl jugador
.globl multijugador
.globl instrucciones
.globl configuracion
.globl dificultad
.globl codigo
.globl retrocede
.globl ganador
.globl perdedor
.globl limpia
.globl tab2
.globl tab3
.globl tab4
.globl ensenaSecuencia
.globl semilla

menu:	.ascii   "------------ MasterMind ------------"
      .byte 10
      .byte 10
      .ascii   " 1) Jugar"
      .byte 10
      .ascii   " 2) Configuracion"
      .byte 10
      .ascii   " 3) Instrucciones"
      .byte 10
      .ascii   " 4) Salir"
      .byte 10
      .byte 10
      .ascii   "  Opcion -> "
      .byte 0

multijugador:	.ascii "Escoge una opcion:"
					.byte 10
					.ascii "1) Multijugador"
					.byte 10
					.ascii "2) Contra la maquina"
					.byte 10
					.byte 0

jugador: .ascii "Jugador 2, introduce el codigo para que el jugador 1 lo adivine"
			.byte 10
			.byte 0

	instrucciones: .ascii   "Debes adivinar un codigo de 4 cifras sin repetir"
               .byte 10
               .ascii   "Sabras cuantas de tus cifras estan en el codigo"
               .ascii   " a adivinar y cuantas coinciden con dicho codigo."
               .byte 10
               .ascii   "Podras cambiar las vidas en la opcion Configuracion."
               .byte 10
               .byte 0


	configuracion: .ascii   "Aqui puedes cambiar las vidas que tienes."
               .byte 10
               .ascii   "Introduce un valor y pulsa ENTER."
               .byte 10
               .byte 0


	dificultad:   .ascii   "Elige una dificultad, facil o dificil (1/2)."
         .byte 10
         .byte 0
ensenaSecuencia:	.asciz "Secuencia generada: "
semilla:	.asciz "Introduce una semilla para generar el numero aleatorio: "

	codigo:  .ascii   "[ABCD]"
         .byte 9
         .byte 9
         .ascii   " ACIERTOS"
         .byte 9
         .byte 9
         .ascii   "COINCIDENCIAS"
         .byte 9
         .byte 9
			.ascii	"VIDAS"
         .byte 10
         .byte 0

	tab2: .byte 9
			.byte 9
			.byte 32
			.byte 32
			.byte 32
			.byte 32
			.byte 0
	
	tab3:	.byte 9
			.byte 9
			.byte 9
			.byte 32
			.byte 32
			.byte 32
			.byte 32
			.byte 32
			.byte 32
			.byte 0

	tab4:	.byte 9
			.byte 9
			.byte 9
			.byte 32
			.byte 32
			.byte 0

	retrocede:.asciz"\33[1D \33[1D"

	ganador:    .asciz   "Enhorabuena, has ganado\n"

	perdedor:   .asciz   "Lo siento, has perdido\n"

	limpia:  .asciz   "\33[2J\33[1;1H"
