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

import argparse as argumentos
import multiaportes.algoritmos.modulo_cuatro as mmdyv

parseador = argumentos.ArgumentParser(description='Práctica 4: Multiplicación de matrices mediante DyV por EderOrtega', epilog='Ejemplo: ./practica4.py -a archivo1 -b archivo2 -m clasico')
parseador.add_argument('-a', '--archivo1', action='store', dest='archivo1', help='Archivo que contiene la matriz A', required=True)
parseador.add_argument('-b', '--archivo2', action='store', dest='archivo2', help='Archivo que contiene la matriz B', required=True)
parseador.add_argument('-m', '--modo', action='store', default='c', dest='modo', choices=['c', 'S'],help='Indica si el algoritmo se ejecutará por el algoritmo [c]lásico o por el algoritmo de [S]trassen')
arr = parseador.parse_args()
mmdyv.programa(arr)
print "Por Eder Ortega - multiaportes.com/algoritmos"
exit()