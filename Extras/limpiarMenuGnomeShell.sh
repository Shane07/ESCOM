#!/bin/bash
if [[ $EUID == 0 ]];
then
	if [[ $1 == "--archivo" ]];
	then
		if [[ -n $2 ]]; # Se especifica un fichero
		then
			if [[ -f $2 ]]; # El fichero existe
			then
				while read LINEA
				do
					rm -f "/usr/share/applications/$LINEA"
				done < $2 # Archivo a leer
				echo "Tarea completada!"
				echo "By H@cK.32 - multiaportes.com"
			else
				echo "[Error]: El archivo no existe" >&2
			fi
		else
			echo "[Error]: No has especificado un archivo" >&2
		fi
	else
		echo "Uso: ./limpiarMenu.sh --archivo <fichero>"
	fi
else
	echo "[Error]: No puedes ejecutar el script a menos que seas root" >&2
fi
exit
