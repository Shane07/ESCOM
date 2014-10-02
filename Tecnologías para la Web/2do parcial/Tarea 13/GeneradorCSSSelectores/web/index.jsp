<!DOCTYPE html>
<html>
    <head>
        <title>JSP Page</title>
    </head>
    <body>
        <script type="text/javascript">
            function generarSelUniv()
            {
                var s = '';
                s = 'Selector Universal: <textarea name="cssSelUniv"></textarea><br/><br/>';
                document.getElementById('seluniv').innerHTML = s;
            }
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
            function generarIDBefore()
            {
                var s = '';
                s = 'ID: <input type="text" name="beforeID"><br/>CSS before: <textarea name="cssIDBefore"></textarea><br/><br/>';
                document.getElementById('idbefore').innerHTML = s;
            }
            function generarIDAfter()
            {
                var s = '';
                s = 'ID: <input type="text" name="afterID"><br/>CSS after: <textarea name="cssIDAfter"></textarea><br/><br/>';
                document.getElementById('idafter').innerHTML = s;
            }
            function generarAtributo()
            {
                var s = '';
                s = 'Atributo: <input type="text" name="atributo"><br/>CSS atributo: <textarea name="cssAtributo"></textarea><br/><br/>';
                document.getElementById('atributo').innerHTML = s;
            }
            function generarSeleccion()
            {
                var s = '';
                s = 'CSS seleccion: <textarea name="cssSeleccion"></textarea><br/><br/>';
                document.getElementById('seleccion').innerHTML = s;
            }
            function generarCampos()
            {
                generarSelUniv();
                generarEHTML();
                generarID();
                generarCLASS();
                generarIDBefore();
                generarIDAfter();
                generarAtributo();
                generarSeleccion();
            }
        </script>
        
        <form action="GenerarHTMLCSS" method="POST">
            Cantidad elementos HTML: <input type="text" name="cantidadElementosHTML" id="cantidadElementosHTML"><br/>
            Cantidad ID: <input type="text" name="cantidadID" id="cantidadID"><br/>
            Cantidad CLASS: <input type="text" name="cantidadCLASS" id="cantidadCLASS"><br/>
            <input type="button" onclick="generarCampos()" value="Generar campos">

            <h3>Selector universal</h3>
            <div id="seluniv"></div><br/>
            <h3>Elementos HTML</h3>
            <div id="ehtml"></div><br/>
            <h3>ID</h3>
            <div id="id"></div><br/>
            <h3>Clases</h3>
            <div id="clase"></div><br/><br/>
            <h3>ID: before</h3> <!-- CSS: content: "TEXTO BEFORE"; ... -->
            <div id="idbefore"></div><br/><br/>
            <h3>ID: after</h3>
            <div id="idafter"></div><br/><br/>
            <h3>Atributo</h3>
            <div id="atributo"></div><br/><br/>
            <h3>Seleccion</h3>
            <div id="seleccion"></div><br/><br/>
            <input type="submit" value="Guardar">
        </form>
    </body>
</html>
