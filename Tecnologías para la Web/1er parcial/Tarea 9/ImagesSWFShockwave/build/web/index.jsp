<!DOCTYPE html>
<html>
    <head>
        <title>JSP Page</title>
    </head>
    <body>
        <form action="makeMediaPage" method="POST">
            <strong>Nombre del fichero:</strong>
            <input type="text" name="fichero">
            <br/><strong>Tipo:</strong>
            <input type="radio" name="tipoArchivo" value="img" checked>Imagen
            <input type="radio" name="tipoArchivo" value="app">Applet
            <input type="radio" name="tipoArchivo" value="fla">Flash
            <input type="radio" name="tipoArchivo" value="shw">Shockwave
        </form>
    </body>
</html>
