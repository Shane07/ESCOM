#! /bin/bash
# Ortega Ortunio Eder - 2CM6

clear

echo "Lista de programas - Teoria Computacional"
echo "Ortega Ortunio Eder - 2CM6"
echo "www.multiaportes.com"
echo
#echo "1. Potencias alfabeto binario"
#echo "2. Potencias numeros primos alfabeto binario"
#echo "3. ASCII String numero primo"
#echo "4. "
#echo "5. "
echo "6. AFD 'ing'"
echo "7. AFD binario"
echo "8. AFD paridad de ceros y unos"
echo "9. AFND end_with '0,1'"
echo "10. AFND 'web' y 'ebay'"
#echo "11. AFND Planetas"
echo "12. Palindromos e, 0, 1"
echo "13. Regexp (0+1)*"
echo "14. Automata de pila"
echo "15. Maquina de Turing"
echo
read -p "Opcion: " OPC
read -p "Cadena / Cantidad (ejercicio 12): " CAD

if [ "$OPC" -eq 1 ]; then
	gcc -std=c99 -lgmp -lm -o a uno.c
	clear
	./a
elif [ "$OPC" -eq 2 ]; then
	gcc -std=c99 -lgmp -lm -o b dos.c
	clear
	./b
elif [ "$OPC" -eq 3 ]; then
	gcc -std=c99 -lgmp -lm -o c tres.c
	clear
	./c
elif [ "$OPC" -eq 6 ]; then
	read -p "Fichero: " FICH
	gcc -lallegro -lallegro_primitives -lallegro_dialog -lallegro_font -lallegro_ttf seis.c
	clear
	echo "Cadena"
	./a.out --cadena $CAD
	echo "Archivo"
	./a.out --archivo $FICH
elif [ "$OPC" -eq 7 ]; then
	read -p "Fichero: " FICH
	gcc -lallegro -lallegro_primitives -lallegro_dialog -lallegro_font -lallegro_ttf siete.c
	clear
	echo "Cadena"
	./a.out --cadena $CAD
	echo "Archivo"
	./a.out --archivo $FICH
elif [ "$OPC" -eq 8 ]; then
	read -p "Fichero: " FICH
	gcc -lallegro -lallegro_primitives -lallegro_dialog -lallegro_font -lallegro_ttf ocho.c
	clear
	echo "Cadena"
	./a.out --cadena $CAD
	echo "Archivo"
	./a.out --archivo $FICH
elif [ "$OPC" -eq 9 ]; then
	read -p "Fichero: " FICH
	gcc -lallegro -lallegro_primitives -lallegro_dialog -lallegro_font -lallegro_ttf nueve.c
	clear
	echo "Cadena"
	./a.out --cadena $CAD
	echo "Archivo"
	./a.out --archivo $FICH
elif [ "$OPC" -eq 10 ]; then
	read -p "Fichero: " FICH
	gcc -lallegro -lallegro_primitives -lallegro_dialog -lallegro_font -lallegro_ttf diez.c
	clear
	echo "Cadena"
	./a.out --cadena $CAD
	echo "Archivo"
	./a.out --archivo $FICH
elif [ "$OPC" -eq 12 ]; then
	gcc doce.c
	clear
	./a.out -n $CAD
elif [ "$OPC" -eq 13 ]; then
	gcc trece.c
	clear
	./a.out
elif [ "$OPC" -eq 14 ]; then
	read -p "Fichero: " FICH
	gcc catorce.c
	clear
	echo "Cadena"
	./a.out --cadena $CAD
	echo "Archivo"
	./a.out --archivo $FICH
elif [ "$OPC" -eq 15 ]; then
	read -p "Fichero: " FICH
	gcc quince.c
	clear
	echo "Cadena"
	./a.out --cadena $CAD
	echo "Archivo"
	./a.out --archivo $FICH
else
	clear
	echo "Opcion incorrecta"
fi

exit
