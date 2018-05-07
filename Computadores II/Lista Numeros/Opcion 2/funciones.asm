	.module funciones

pantalla	.equ	0xFF00
teclado		.equ	0xFF02


    ;importamos varibles y cadenas y damos la opcion a exportar las funciones
	.globl imprime
	.globl instrucciones
	.globl menu
	.globl lista
	.globl cantidad_elementos
	.globl temp
	.globl limite
	.globl elementos
	.globl mensaje_lista
	.globl introduce
	.globl mensaje_limite
	.globl pausa
	.globl saltos
	.globl temp1

;funcion que muestra una cadena de texto

imprime:

	lda	,x+
	beq	acaba
	sta	pantalla
	bra	imprime

acaba:
	rts
	

;subrutina que recoge numeros
	
lista:
    ldx #introduce
    jsr imprime
    
recoge:

    lda teclado
    cmpa #'0
    beq principal
    blo recoge
    cmpa #'9
    bhi recoge
    pshu a
    inc cantidad_elementos
    bra recoge

numero_doble:

    lda cantidad_elementos
    cmpa #10
    blo numero_doble_paso_2
    suba #10
    sta cantidad_elementos
    inc temp1
    bra numero_doble

numero_doble_paso_2:
    lda temp1
    adda #'0
    sta pantalla
    lda cantidad_elementos
    adda #'0
    sta pantalla
    
numero_doble_paso_3:

    lda temp1
    cmpa #0
    beq continuacion_1
    dec temp1
    lda cantidad_elementos
    adda #10
    sta cantidad_elementos
    bra numero_doble_paso_3

principal:
    lda #0
    sta temp
    sta saltos
    ldx #elementos
    jsr imprime
    lda cantidad_elementos
    cmpa #9
    bhi numero_doble
    adda #'0
    sta pantalla
    
continuacion_1:
    lda #'\n
    sta pantalla
    jsr muestra
    ldx #mensaje_limite
    jsr imprime
    lda teclado
    sta limite

bucle1:
    lda temp
    cmpa cantidad_elementos
    beq fin_bucle1
    pulu a
    cmpa limite
    bhs no_cuenta
    pshs a
    inc temp
    bra bucle1

no_cuenta:
    inc temp
    inc saltos
    bra bucle1

fin_bucle1:

    lda cantidad_elementos
    suba saltos
    sta cantidad_elementos
    sta temp

bucle2:
    lda temp
    cmpa #0
    beq continua
    puls a
    pshu a
    dec temp
    bra bucle2


numero_doble_2:

    lda cantidad_elementos
    cmpa #10
    blo numero_doble_paso_2_2
    suba #10
    sta cantidad_elementos
    inc temp1
    bra numero_doble_2

numero_doble_paso_2_2:
    lda temp1
    adda #'0
    sta pantalla
    lda cantidad_elementos
    adda #'0
    sta pantalla
    
numero_doble_paso_3_3:

    lda temp1
    cmpa #0
    beq continuacion_2
    dec temp1
    lda cantidad_elementos
    adda #10
    sta cantidad_elementos
    bra numero_doble_paso_3_3
    
continua:
    
    ldx #elementos
    jsr imprime
    lda cantidad_elementos
    cmpa #9
    bhi numero_doble_2
    adda #'0
    sta pantalla

continuacion_2:
    lda #'\n
    sta pantalla
    jsr muestra
   
limpia_pila:
    ;vaciamos la pila
    lda cantidad_elementos
    cmpa #0
    lbeq final
    pulu a
    dec cantidad_elementos
    bra limpia_pila

final:
    ;hacemos una pausa para que el usuario visualice el final del programa
    ldx #pausa
    jsr imprime
    lda teclado
    clra
    
    rts


;subrutina que muestra los elementos de la lista

muestra:
    ldx #mensaje_lista
    jsr imprime
    
bucle_cambiar:
    lda temp
    cmpa cantidad_elementos
    beq bucle_muestra
    pulu a
    pshs a
    inc temp
    bra bucle_cambiar

bucle_muestra:
    lda temp
    cmpa #0
    beq termina
    puls a
    sta pantalla
    pshu a
    dec temp
    bra bucle_muestra
    
termina:
    rts
