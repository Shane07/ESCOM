#! /bin/bash
# H@cK.32 - www.multiaportes.com

## Funciones adicionales
generarArchivo()
{
	if [ -f "$1" ];
	then
		rm "$1"
	fi

	touch "$1"

	for VIDEO in *.3gp
	{
		if [[ $VIDEO =~ ^2014 ]];
		then
			mv "$VIDEO" "video-$VIDEO"
			echo -e "video-$VIDEO\t" >> "$1"
		else
			echo -e "$VIDEO\t" >> "$1"
		fi
	}

	sort "$1" -o "$1" # Ordenar archivos igual que Nautilus default
}
convertir()
{
	# Si el archivo existe...
	let LN=0
	while read LINEA
	do
		let LN+=1
	done < "$1";

	for VID in `seq 1 $LN` # 'seq' imprime una secuencia de numeros
	do
		ARCHIVO=$(awk -v fila=$VID 'FNR == fila {print ""$1" "$2}' "$1") # '-v' permite setear variables
		INICIO=$(awk -v fila=$VID 'FNR == fila {print $3}' "$1")
		DURACION=$(awk -v fila=$VID 'FNR == fila {print $4}' "$1")
		SALIDA="${ARCHIVO%.*}"
		SALIDA="$SALIDA.avi"
		if [[ $INICIO == "ignorar" ]];
		then
			ffmpeg -i "$ARCHIVO" -vcodec libxvid -c:v copy -an "$SALIDA"
		else
			INICIO="00:$INICIO"
			DURACION="00:$DURACION"
			ffmpeg -i "$ARCHIVO" -vcodec libxvid -c:v copy -ss $INICIO -t $DURACION -an "$SALIDA"
		fi
	done
}

if [[ $1 == "--archivo" ]]; #Dobles corchetes son built-in de Bash (añadidos) y permiten funcionalidades extendidas como el comparador de Regex
then
	if [ -z $2 ]; # Si la variable no esta definida
	then
		echo "Archivo no especificado" >&2 # Imprimir a stderr
	else
		generarArchivo "$2"
	fi
elif [[ $1 == "--iniciar" ]];
then
	if [ -z $2 ];
	then
		echo "Archivo no especificado" >&2
	else
		convertir "$2"
	fi
else
	echo "Uso: ./conv2.sh {--archivo <archivo> | --iniciar <archivo>}"
fi
exit
