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

def crearTabla(mat):
	tam = len(mat)
	w = []
	for i in range(tam):
		v = []
		for j in range(tam):
			v.append(["", 0, 0, 0, -1]) # NombreTabla, M, N, P, valorSuma
		w.append(v)
	return w
def descartarCeldas(tab, mat):
	contador = 1
	limite = len(tab)
	for i in range(limite):
		for j in range(contador):
			tab[i][j][0] = "#"
			tab[i][j][4] = 0
		contador += 1
def initPrimeraDiagonal(tab, mat):
	lim = len(tab)
	i = 0
	j = 1
	while i < lim and j < lim:
		tab[i][j][0] = mat[i][0] + mat[j][0]
		tab[i][j][1] = mat[i][1] # M
		tab[i][j][2] = mat[i][2] # N
		tab[i][j][3] = mat[j][2] # P
		tab[i][j][4] = tab[i][j][1] * tab[i][j][2] * tab[i][j][3]
		i += 1
		j += 1
def setMinimo(tab, mat, m, n):
	if tab[m][n][1] == 0 and tab[m][n][2] == 0 and tab[m][n][3] == 0:
		matrizSize_izquierda = (tab[m][n-1][1], tab[m][n-1][3])
		matrizSize_abajo = (tab[m+1][n][1], tab[m+1][n][3])
		multiplicacion_izquierda = matrizSize_izquierda[0] * matrizSize_izquierda[1] * mat[n][2]
		multiplicacion_abajo = mat[m][1] * matrizSize_abajo[0] * matrizSize_abajo[1]
		suma_izquierda = tab[m][n-1][4] + multiplicacion_izquierda
		suma_abajo = tab[m+1][n][4] + multiplicacion_abajo
		if suma_izquierda < suma_abajo:
			tab[m][n][0] = "("+tab[m][n-1][0]+")"+mat[n][0]
			tab[m][n][1] = matrizSize_izquierda[0]
			tab[m][n][2] = matrizSize_izquierda[1]
			tab[m][n][3] = mat[n][2]
		else:
			tab[m][n][0] = mat[m][0]+"("+tab[m+1][n][0]+")"
			tab[m][n][1] = mat[m][1]
			tab[m][n][2] = matrizSize_abajo[0]
			tab[m][n][3] = matrizSize_abajo[1]
		tab[m][n][4] = min(suma_izquierda, suma_abajo)
def algoritmo(tab, mat):
	initPrimeraDiagonal(tab, mat)
	limite = len(tab)
	for i in range(limite):
		m = 0
		n = i
		for j in range(i, limite):
			if tab[m][n][4] != 0:
				setMinimo(tab, mat, m, n)
			m += 1
			n += 1
def init(matrices):
	tabla = crearTabla(matrices)
	descartarCeldas(tabla, matrices)
	algoritmo(tabla, matrices)
	return tabla