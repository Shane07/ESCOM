<!DOCTYPE html>
<html>
    <head>
        <title>JSP Page</title>
    </head>
    <body>
        <form action="PedirDatos" method="POST" id="makeTabla">
            Filas: <input type="text" name="filas"> Columnas: <input type="text" name="columnas"><br/>
            Ancho de tabla: <input type="text" name="anchoTabla">  P&iacute;xeles<input type="radio" name="escalaAncho" value="px" checked> Porcentaje <input type="radio" name="escalaAncho" value="porcent"><br/>
            Grosor de borde: <input type="text" name="grosorBorde"><br/>
            Relleno de celda: <input type="text" name="rellenoCelda"><br/>
            Espacio entre celdas: <input type="text" name="espacioCelda"><br/>
            Encabezado: Ninguno <input type="radio" name="encabezado" value="none" checked> Izquierda <input type="radio" name="encabezado" value="izq"> Superior <input type="radio" name="encabezado" value="sup"> Ambos <input type="radio" name="encabezado" value="both"> <br/>
            <br/>Accesibilidad<br/>
            Texto: <input type="text" name="textoAcces"><br/>
            Resumen: <textarea name="summaryAcces" cols="30" rows="4" name="summaryAcces" form="makeTabla"></textarea><br/>
            <br/><input type="submit" name="enviar" value="Subir">
        </form>
    </body>
</html>
