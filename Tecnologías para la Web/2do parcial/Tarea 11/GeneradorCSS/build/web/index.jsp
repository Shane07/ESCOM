<!DOCTYPE html>
<html>
    <head>
        <title>JSP Page</title>
    </head>
    <body>
        <script type="text/javascript">
            function generarEHTML()
            {
                var i, s = '';
                for(i = 0; i < document.getElementById('cantidadElementosHTML').value; i++)
                    s = s+'Elemento HTML: <input type="text" name="nombreEHTML'+i+'"><br/>CSS:<textarea name="cssEHTML'+i+'"></textarea><br/><br/>';
                document.getElementById('ehtml').innerHTML = s;
            }
            function generarID()
            {
                var i, s = '';
                for(i = 0; i < document.getElementById('cantidadID').value; i++)
                    s = s+'ID: <input type="text" name="nombreID'+i+'"><br/>CSS:<textarea name="cssID'+i+'"></textarea><br/><br/>';
                document.getElementById('id').innerHTML = s;
            }
            function generarCLASS()
            {
                var i, s = '';
                for(i = 0; i < document.getElementById('cantidadCLASS').value; i++)
                    s = s+'CLASS: <input type="text" name="nombreCLASS'+i+'"><br/>CSS:<textarea name="cssCLASS'+i+'"></textarea><br/><br/>';
                document.getElementById('clase').innerHTML = s;
            }
            function generarCampos()
            {
                generarEHTML();
                generarID();
                generarCLASS();
            }
        </script>
        
        <form action="GenerarHTMLCSS" method="POST">
            Cantidad elementos HTML: <input type="text" name="cantidadElementosHTML" id="cantidadElementosHTML"><br/>
            Cantidad ID: <input type="text" name="cantidadID" id="cantidadID"><br/>
            Cantidad CLASS: <input type="text" name="cantidadCLASS" id="cantidadCLASS"><br/>
            <input type="button" onclick="generarCampos()" value="Generar campos">

            <h3>Elementos HTML</h3>
            <div id="ehtml"></div><br/>
            <h3>ID</h3>
            <div id="id"></div><br/>
            <h3>Clases</h3>
            <div id="clase"></div><br/><br/>
            <input type="submit" value="Guardar">
        </form>
    </body>
</html>
