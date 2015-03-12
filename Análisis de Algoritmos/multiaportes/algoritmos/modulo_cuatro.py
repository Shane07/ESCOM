# coding=utf-8
'''
	=== Instituto Politécnico Nacional
	=== Escuela Superior de Cómputo

	*** Análisis de Algoritmos - 2CM3
	>>> Ortega Ortuño Eder (@Stederr)
	<<< www.multiaportes.com/algoritmos

	Nota: el código de esta licencia se distribuye bajo la especificada
	en el repositorio de github.com/multiaportes/ESCOM

	Nota2: ¿Por qué no implementar las sumas y restas de matrices
	como el sourcecode de acá?: https://github.com/MartinThoma/matrix-multiplication/blob/master/Python/strassen-algorithm.py
'''
from sys import stderr as error
from os import path as ruta_archivo
from itertools import repeat
import re as regexxx
from math import floor as redondeobajo, log as logaritmo

def leerMatrices(archivos):
	matrices = ([],[])
	p = 0
	comp = regexxx.compile('^(\d+|\,)+[^\,]$') # Cada línea debe cumplir el formato de números separados por comas y evitar una coma al final
	for matriz in archivos:
		fichero = open(matriz, 'r')
		lineas = fichero.readlines()
		for arreglo in lineas:
			validante = arreglo.rstrip('\n') # Elimina los saltos de linea
			if comp.match(validante):
				matrices[p].append(validante.split(',')) # Crea una nueva lista separándola por el caracter coma
			else:
				return False
		p += 1
		fichero.close()
	return matrices

def validarProducto(matrices):
	return True if len(matrices[0][0]) == len(matrices[1]) else False

def checarTamaniosArrays(matrices):
	for matriz in matrices:
		for arreglo in matriz:
			if len(arreglo) != len(matriz[0]):
				return False
	return True

def rellenarCeros(matrices):
	# A[mxn] y B[nxp]
	m = len(matrices[0])
	n = len(matrices[0][0])
	p = len(matrices[1][0])
	maximo = max([m,n,p])
	p = 2 ** int(redondeobajo(logaritmo(n, 2))+1) # Potencia de 2 más próxima a 'n' para llenar de ceros

	for matriz in matrices:
		for arreglo in matriz:
			w = p - len(arreglo)
			for c in range(w):
				arreglo.append('0')
		w = p - len(matriz)
		for d in range(w):
			matriz.append(list(repeat('0', p)))

def programa(args):
	if ruta_archivo.exists(args.archivo1) and ruta_archivo.exists(args.archivo2):
		matrices = leerMatrices((args.archivo1, args.archivo2))
		if not matrices:
			error.write('Error: los datos introducidos no son válidos (hay otros caracteres o comas al final)\n')
		else:
			if validarProducto(matrices):
				if checarTamaniosArrays(matrices):
					rellenarCeros(matrices)
					seleccionarAlgoritmo(matrices, args.modo)
				else:
					error.write('Error: algún elemento de las matrices tiene un tamaño diferente\n')
			else:
				error.write('Error: no se puede realizar el producto de las matrices\n')
	else:
		error.write('Error: no existen los archivos especificados\n')

def getSubmatriz(w, l):
	submatriz = []
	tam = len(w) / 2
	if l == 'L1':
		mitad = w[:tam]
		tam_ = len(mitad[0]) / 2
		for m in mitad:
			submatriz.append(m[:tam_])
	elif l == 'L2':
		mitad = w[:tam]
		tam_ = len(mitad[0]) / 2
		for m in mitad:
			submatriz.append(m[tam_:])
	elif l == 'L3':
		mitad = w[tam:]
		tam_ = len(mitad[0]) / 2
		for m in mitad:
			submatriz.append(m[:tam_])
	elif l == 'L4':
		mitad = w[tam:]
		tam_ = len(mitad[0]) / 2
		for m in mitad:
			submatriz.append(m[tam_:])
	print submatriz
	return submatriz

def algoritmo(x, y, nn, m):
	if len(x) == 1 and len(y) == 1:
		print "\t"+x[0][0]+" * "+y[0][0]+" = "+str(int(x[0][0]) * int(y[0][0]))
		return int(x[0][0]) * int(y[0][0])
	else:
		# Almacenar submatrices
		tmp = (x, y)
		divisiones = ('L1', 'L2', 'L3', 'L4')
		submatrices = [[], []] # Submatrices de A, submatrices de B
		p = 0
		for i in tmp:
			for j in divisiones:
				submatrices[p].append(getSubmatriz(tmp[p], j))
			p += 1

		# Multiplicar y sumar de acuerdo al algoritmo tradicional
		subproblemas = []
		n = len(x[0])
		c1 = algoritmo(submatrices[0][0], submatrices[1][0], n/2, m) + algoritmo(submatrices[0][1], submatrices[1][2], n/2, m)
		c2 = algoritmo(submatrices[0][0], submatrices[1][1], n/2, m) + algoritmo(submatrices[0][1], submatrices[1][3], n/2, m)
		c3 = algoritmo(submatrices[0][2], submatrices[1][0], n/2, m) + algoritmo(submatrices[0][3], submatrices[1][2], n/2, m)
		c4 = algoritmo(submatrices[0][2], submatrices[1][1], n/2, m) + algoritmo(submatrices[0][3], submatrices[1][3], n/2, m)
		
		print "C1: "+str(c1)
		print "C2: "+str(c2)
		print "C3: "+str(c3)
		print "C4: "+str(c4)
		print '_______________________'

		return [[c1,c2],[c3,c4]]

def seleccionarAlgoritmo(m, modo):
	if modo == 'c':
		algoritmo(m[0], m[1], len(m[0]), modo)
	elif modo == 'S':
		print 'Strassen: algoritmo en desarrollo'

'''
def acomodarMatriz(mm):
	z = len(mm)
	m_ok = []
	for i in mm:
		m_ok.append()
'''