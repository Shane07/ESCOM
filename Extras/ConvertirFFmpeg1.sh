#! /bin/bash
# H@cK.32 - www.multiaportes.com

## Notas
#  -> Extraer extensiones sin repetir (sort unique): "find . -type f | perl -ne 'print $1 if m/\.([^.\/]+)$/' | sort -u"
#  -> '.' es el directorio actual y '..' es el directorio padre
#  -> IF: '-d':directorio, '-f':archivo, '-L':enlace simbolico, '-x':ejecutable, '-s':archivo no vacio
#  -> SED 's/regex_original/sustitucion' para sustituir cadenas dada una regex
#  -> Un validador de Regex es http://www.regexr.com/
#  -> Quitar de una a dos extensiones de archivo con TMP="${TMP%.*}"
#  -> SIGINT: Señal (aquello que comunica eventos a un programa) para interrumpir proceso (Ctrl+C)
#  -> SIGSEV: Señal para matar proceso cerrando cosas pendientes (default signal en 'kill')
#  -> SIGKILL: Señal para matar proceso a la fuerza (ultimo recurso: 'kill -9 PID'). Ningun programa puede ignorarla

## Trampas
trap "terminarScript" SIGINT SIGSEV

## Funciones adicionales
carpetaExiste()
{
	local DIRECTORIO=$1
	if [ ! -d "$DIRECTORIO" ];
	then
		mkdir "$DIRECTORIO"
	fi
	echo $DIRECTORIO
}
renombrarVideo()
{
	local TMP=$1
	if [[ $TMP == vlc* ]]; # Los archivos que empiezan con 'vlc' tienen dos extensiones
	then
		TMP="$(echo $1 | sed "s/^vlc-record.*s-//")"
		TMP="${TMP%.*}"
		TMP="${TMP%.*}"
	else
		TMP="${TMP%.*}"	
	fi
	echo $TMP
}
convertirVideo()
{
	local TEMP="$3"/"$4"/"$5""$2"
	local ENTRADA=$(printf "\"%s/%s/%s%s\"" "$3" "$6" "$5" "$1")
	local SALIDA=$(printf "\"%s_%s.avi\"" "$TEMP" "$CONT")
	local UNPUTOCOMANDOQUENOSEQUIEREJECUTARPORLASPUTASBUENAS=$(echo ffmpeg -i "$ENTRADA" -vcodec libxvid -b:v 1500k -an "$SALIDA")
	echo $UNPUTOCOMANDOQUENOSEQUIEREJECUTARPORLASPUTASBUENAS
	#read -p "Pausa # $CONT"
	eval $UNPUTOCOMANDOQUENOSEQUIEREJECUTARPORLASPUTASBUENAS
}
terminarScript()
{
	rm -rf echo "$CARPETA_RAIZ/$CARPETA_FINAL"
	echo "Script interrumpido..."
	exit
}

CARPETA_RAIZ="/home/xdd/Descargas"
CARPETA_ORIGINAL="AquiNoHayPr0n"
CARPETA_FINAL="AcaTampocoXD"

EXTENSIONES_VIDEO=("avi 3gp mp4")

cd "$CARPETA_RAIZ"
CARPETA_WORKSPACE=$(carpetaExiste $CARPETA_ORIGINAL)
CARPETA_DESTINO=$(carpetaExiste $CARPETA_FINAL)
cd "$CARPETA_WORKSPACE"

for CARPETA in */ # Para listar directorios
{
	let CONT=0;
	SUBCARPETA="$CARPETA_RAIZ"/"$CARPETA_FINAL"/"$CARPETA"
	CARPETA_NUEVA=$(carpetaExiste "$SUBCARPETA")
	echo -------------------
	echo $CARPETA
	cd "$CARPETA"
	for ARCHIVO in *.*
	{
		NUEVO_NOMBRE=$(renombrarVideo "$ARCHIVO") # Las comillas evitan que la cadena se corte hasta el primer espacio
		let CONT+=1
		convertirVideo "$ARCHIVO" "$NUEVO_NOMBRE" "$CARPETA_RAIZ" "$CARPETA_FINAL" "$CARPETA" "$CARPETA_ORIGINAL"
	}
	cd ..
}

exit
