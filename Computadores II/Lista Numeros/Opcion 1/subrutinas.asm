	.module subrutinas

pantalla	.equ	0xFF00
teclado		.equ	0xFF02


    ;hacemos que las subrutinas puedan ser llamadas desde otro fichero
    ;hacemos que las variables y cadenas puedan ser usadas en este fichero
	.globl imprime_cadena
	.globl instrucc
	.globl instrucciones
	.globl limpia
	.globl menu
	.globl mostrar_menu
	.globl lista
	.globl total
	.globl contador
	.globl corte
	.globl mensaje_total1
	.globl mensaje_total2
	.globl mensaje_lista
	.globl introduce
	.globl pide_corte
	.globl pausa
	.globl resta
	.globl decenas

;subrutina que imprime una cadena de texto

imprime_cadena:

	lda	,x+
	beq	acaba
	sta	pantalla
	bra	imprime_cadena

acaba:
	rts


;subrutina para mostrar las instrucciones 

instrucc:

    ldx	#limpia
	jsr	imprime_cadena
	ldx	#instrucciones
	jsr	imprime_cadena
	lda	teclado
	clra
	rts


;subrutina para mostrar el menu

mostrar_menu:

	;limpiamos la pantalla
	ldx #limpia
	jsr imprime_cadena
	;mostramos el menu
	ldx	#menu
	jsr	imprime_cadena
	rts
	

;subrutina que recoge numeros
	
lista:
    ldx #introduce
    jsr imprime_cadena
    
recoge:

    lda teclado
    cmpa #'0
    beq continua
    blo recoge
    cmpa #'9
    bhi recoge
    pshu a
    inc total
    bra recoge
    
continua:
    lda #0
    sta contador
    sta resta
    ldx #mensaje_total1
    jsr imprime_cadena
    
crea_decenas_1:

    lda total
    cmpa #10
    blo prosigue1
    suba #10
    sta total
    inc decenas
    bra crea_decenas_1

prosigue1:
    lda decenas
    adda #'0
    sta pantalla
    lda total
    adda #'0
    sta pantalla
    
restaura_total_1:

    lda decenas
    cmpa #0
    beq prosigue2
    dec decenas
    lda total
    adda #10
    sta total
    bra restaura_total_1
    
prosigue2:
    ldx #mensaje_total2
    jsr imprime_cadena
    jsr muestra
    ldx #pide_corte
    jsr imprime_cadena
    lda teclado
    sta corte
    jsr elimina_superior
    
    ldx #mensaje_total1
    jsr imprime_cadena

crea_decenas_2:

    lda total
    cmpa #10
    blo prosigue3
    suba #10
    sta total
    inc decenas
    bra crea_decenas_2
    
prosigue3:

    lda decenas
    adda #'0
    sta pantalla
    lda total
    adda #'0
    sta pantalla

restaura_total_2:

    lda decenas
    cmpa #0
    beq prosigue4
    dec decenas
    lda total
    adda #10
    sta total
    bra restaura_total_2

prosigue4:

    ldx #mensaje_total2
    jsr imprime_cadena
    jsr muestra
    
    jsr vacia
    
    ldx #pausa
    jsr imprime_cadena
    lda teclado
    clra
    
    rts


;subrutina que muestra los elementos de la lista

muestra:
    ldx #mensaje_lista
    jsr imprime_cadena
    
cambia_de_pila:
    lda contador
    cmpa total
    beq cambia_y_muestra
    pulu a
    pshs a
    inc contador
    bra cambia_de_pila

cambia_y_muestra:
    lda contador
    cmpa #0
    beq termina
    puls a
    sta pantalla
    pshu a
    dec contador
    bra cambia_y_muestra
    
termina:
    rts
    

elimina_superior:

cambia_y_compara:
    lda contador
    cmpa total
    beq fin_cambia_y_compara
    pulu a
    cmpa corte
    bhs salta
    pshs a
    inc contador
    bra cambia_y_compara

salta:
    inc contador
    inc resta
    bra cambia_y_compara

fin_cambia_y_compara:

    lda total
    suba resta
    sta total
    sta contador

cambia_otra_vez:
    lda contador
    cmpa #0
    beq finaliza
    puls a
    pshu a
    dec contador
    bra cambia_otra_vez
finaliza:
    rts

;subrutina que vacia la lista

vacia:
    lda total
    cmpa #0
    beq final
    pulu a
    dec total
    bra vacia
    
final:    
    rts
