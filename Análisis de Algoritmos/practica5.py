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
'''

from sys import stderr as error
import argparse as argumentos
import re as regexxx
from pprint import pprint as nicePrinter
from multiaportes.algoritmos.modulo_cinco import init as iniciarAlgoritmo

def separarTamanios(ts):
	nums = []
	for i in ts:
		tmp = i.split('x')
		for j in tmp:
			nums.append(j)
	# Siempre debe ser un número par la cantidad de números
	if len(nums) % 2 != 0:
		return False
	# Validar que sean iguales para hacer las multiplicaciones
	for i in range(1, len(nums)-1, 2):
		if nums[i] != nums[i+1]:
			return False
	return nums
def armarMegaTupla(nombres, tamanios):
	if len(nombres) != len(tamanios) / 2:
		return False
	numz = []
	j = 0
	for i in range(0, len(tamanios), 2):
		numz.append([nombres[j], int(tamanios[i]), int(tamanios[i+1])]) # NombreTabla, M, N
		j += 1
	return numz
def init(matrices, verbosidad):
	resultados = iniciarAlgoritmo(matrices)
	resumen = resultados[0][len(resultados)-1]
	if verbosidad:
		nicePrinter(resultados)
	print 'Matriz resultante "'+resumen[0]+'" con tamaño = '+str(resumen[1])+'x'+str(resumen[3])+' y '+str(resumen[4])+' productos'

parseador = argumentos.ArgumentParser(description='Práctica 5: Producto secuencia de matrices por EderOrtega', epilog='Ejemplo: ./practica5.py -n nombre1,nombre2,nombre3 -t 2x4,4x3,3x5 -v')
parseador.add_argument('-n', '--nombres', action='store', dest='nombresMatrices', help='Almacena los nombres que se darán a cada una de las matrices separadas por comas.', required=True)
parseador.add_argument('-t', '--tamanios', action='store', dest='tams', help='Permite establecer los tamaños para cada una de las matrices anteriores; la cantidad debe ser la misma y además debe estar en el formato <M>x<N>.', required=True)
parseador.add_argument('-v', '--verboso', action='store_true', dest='verbosidad', help='Indica si se debe mostrar la tabla de valores o solamente los resultados')
arr = parseador.parse_args()

if regexxx.compile('^(\w+\,)+\w+$').match(arr.nombresMatrices) and regexxx.compile('^(\d+x\d+\,)+\d+x\d+$').match(arr.tams):
	nombres = arr.nombresMatrices.split(',')
	tamanios = separarTamanios(arr.tams.split(','))
	if tamanios != False:
		megatupla = armarMegaTupla(nombres, tamanios)
		if megatupla != False:
			init(megatupla, arr.verbosidad)
		else:
			error.write('Error: La asignación de nombres y tamaños no es suficiente.\n')
	else:
		error.write('Error: no es posible realizar la multiplicación.\n')
else:
	error.write('Error: los argumentos no tienen un formato de entrada válido.\n')
print "Por Eder Ortega - multiaportes.com/algoritmos"
exit()