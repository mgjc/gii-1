	.module cadenas

.globl menu
.globl limpia
.globl comprueba2
.globl comprueba3
.globl auxiliar
.globl continuar
.globl intr
.globl mensaje1
.globl mensaje2
.globl contador

menu: .ascii "1) Introduce un mensaje\n"
      .ascii "2) Encriptar mensaje y mostrarlo\n"
      .ascii "3) Desencripta mensaje y mostrarlo\n"
      .ascii "4) Salir\n\n"
      .asciz "Opcion: "
continuar:  .byte 10
				.asciz "Presiona cualquier tecla para continuar\n"
intr:	.asciz "Introduce una cadena para encriptarla\n"
mensaje1: .asciz "Mensaje encriptado: "
mensaje2: .asciz "Mensaje desencriptado: "
limpia: .asciz "\33[2J\33[1;1H"
comprueba2: .byte 0
comprueba3: .byte 0
auxiliar: .byte 1
contador: .byte 0
