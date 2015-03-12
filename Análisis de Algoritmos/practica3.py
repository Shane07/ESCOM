#!/usr/bin/env python2
# coding=utf-8
'''
	=== Instituto Politécnico Nacional
	=== Escuela Superior de Cómputo

	*** Análisis de Algoritmos - 2CM3
	>>> Ortega Ortuño Eder (@Stederr)
	<<< www.multiaportes.com/algoritmos

	Nota: el código de esta licencia se distribuye bajo la especificada
	en el repositorio de github.com/multiaportes/ESCOM

	Nota 2: Este es mi primer script en Python xD
'''

from sys import stderr as error
from sys import setrecursionlimit as nivelrecursividad
import argparse as argumentos
import re as regexxx
import multiaportes.algoritmos.modulo_tres as pbdyv

'''
	Bugs conocidos: debido a que la constante M especificada para obtener subcadenas nunca cambia,
	entonces si se intenta dividir alguna subcadena en cuartas partes y ésta
	tiene un tamaño menor a cuatro, entraremos en un bucle sin fin y terminaremos
	pronto con los límites de recursión impuestos por el sistema.
	Solución temporal: rechazar los números menores a 8 carácteres si se piensan dividir
	utilizando DyV por cuartas partes.
'''

def programa(args):
	grupo = pbdyv.rellenarCeros(args.num1, args.num2)
	if(len(grupo[0]) == len(grupo[1])): # Ambos deberían tener el mismo tamaño siempre
		print 'Resultado: ' +str(pbdyv.algoritmo(grupo[0], grupo[1], len(grupo[0]), int(args.modo)))
	else:
		error.write("Error: hay un fallo en el algoritmo\n")

parseador = argumentos.ArgumentParser(description='Práctica 3: Multiplicación de números binarios mediante DyV por EderOrtega', epilog='Ejemplo: ./practica3.py -n1 1001 -n2 1010 -m 4')
parseador.add_argument('-n1', '--numero1', action='store', dest='num1', help='Almacena el primer número binario', required=True)
parseador.add_argument('-n2', '--numero2', action='store', dest='num2', help='Almacena el segundo número binario', required=True)
parseador.add_argument('-m', '--modo', action='store', default='2', dest='modo', choices=['2', '4'],help='Indica si el algoritmo se ejecutará por mitades o cuartos')
arr = parseador.parse_args()

comp = regexxx.compile('^(0|1)+$')
if comp.match(arr.num1) and comp.match(arr.num2):
	if arr.modo == '4':
		if len(arr.num1) >= 8 and len(arr.num2) >= 8:
			programa(arr)
		else:
			error.write('Bug: no es posible calcular ciertos números con división en cuartos; intenta con la división en medios\n')
	elif arr.modo == '2':
		programa(arr)
else:
	error.write('Error: los números no son válidos\n')
print "Por Eder Ortega - multiaportes.com/algoritmos"
exit()