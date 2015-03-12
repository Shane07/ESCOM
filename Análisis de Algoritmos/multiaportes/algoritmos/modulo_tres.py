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

from math import floor as redondeobajo, log as logaritmo

def getCeros(tmp, potencia_prox):
	ceros = ''
	w = potencia_prox - len(tmp)
	for c in range(w):
		ceros += '0'
	return ceros + tmp

def separar(cadena):
	separada = []
	for c in cadena:
		separada.append(c)
	return separada

def rellenarCeros(binario1, binario2):
	ceros = ''
	n = len(binario1 if len(binario1) >= len(binario2) else binario2) # Obtener el tamaño de arreglo más grande para igualarlos al final
	p = 2 ** int(redondeobajo(logaritmo(n, 2))+1) # Potencia de 2 más próxima a 'n' para llenar de ceros
	return [separar(getCeros(binario1, p)), separar(getCeros(binario2, p))]

def casoBase(a, b):
	return True if len(a) == 1 and len(b) == 1 else False

def getSubcadena(cadena, posicion, modo):
	if modo == 2:
		if posicion == 'IZQ':
			return cadena[:len(cadena)/2] # Desde cero a la mitad
		elif posicion == 'DER':
			return cadena[len(cadena)/2:] # Desde la mitad hasta el final
	elif modo == 4:
		if posicion == 'L1':
			return cadena[:len(cadena)/4]
		elif posicion == 'L2':
			return cadena[len(cadena)/4:len(cadena)/2]
		elif posicion == 'L3':
			return cadena[len(cadena)/2:len(cadena)*3/4]
		elif posicion == 'L4':
			return cadena[len(cadena)*3/4:]

def getFormula(sp, n, m):
	if m == 2:
		return (2 ** n) * sp[0] + (2 ** int(n/2)) * sp[1] + (2 ** int(n/2)) * sp[2] + sp[3]
	elif m == 4:
		return (2 ** int(6*n/4)) * sp[0] + (2 ** int(5*n/4)) * sp[1] + (2 ** n) * sp[2] + (2 ** int(3*n/4)) * sp[3] + (2 ** int(5*n/4)) * sp[4] + (2 ** n) * sp[5] + (2 ** int(3*n/4)) * sp[6] + (2 ** int(n/2)) * sp[7] + (2 ** n) * sp[8] + (2 ** int(3*n/4)) * sp[9] + (2 ** int(n/2)) * sp[10] + (2 ** int(n/4)) * sp[11] + (2 ** int(3*n/4)) * sp[12] + (2 ** int(n/2)) * sp[13] + (2 ** int(n/4)) * sp[14] + sp[15]

def algoritmo(x, y, n, m):
	if(casoBase(x, y)):
		return int(x[0]) * int(y[0])
	else:
		# Almacenar subcadenas
		tmp = (x, y)
		divisiones = (('IZQ', 'DER'), ('L1', 'L2', 'L3', 'L4')) # Tupla: no es posible modificarla; 'L' significa lados para la división en cuartos
		subcadenas = [[], []] # Cadenas divididas de A, Cadenas divididas de B
		div = 0 if m == 2 else 1
		p = 0
		for i in tmp:
			for j in divisiones[div]:
				subcadenas[p].append(getSubcadena(tmp[p], j, m))
			p += 1

		# Combinar subcadenas (combina izq->der): 4 combinaciones si modo == 2 y 16 combinaciones si modo == 4
		subproblemas = []
		for i in subcadenas[0]:
			for j in subcadenas[1]:
				subproblemas.append(algoritmo(i, j, len(x)/2, m))
	return getFormula(subproblemas, len(x), m)
