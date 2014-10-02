<!DOCTYPE html>
<html>
    <head>
        <title>JSP Page</title>
    </head>
    <body>
        <script type="text/javascript">
            var objeto;
            var caja;
            var cache = 0; // Hacer que el browser no tome el archivo CSS en cache

            function crearXMLHttpRequest()
            {
                if(window.ActiveXObject)
                {
                    objeto = new ActiveXObject("Microsoft.XMLHTTP");
                }
                else if(window.XMLHttpRequest)
                {
                    objeto = new XMLHttpRequest();
                }
            }
            function inicializar()
            {
                caja = document.getElementById("cCSS");

                if(caja.value.length > 0)
                {
                    crearXMLHttpRequest();
                    var url = "http://localhost:8080/AjaxCSS/GenerarCSS";//?codigoCSS="+document.getElementById("cCSS").value;
                    objeto.open("POST", url, true);
                    objeto.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
                    //objeto.onreadystatechange = callback;
                    //objeto.send();
                    objeto.send("codigoCSS="+document.getElementById("cCSS").value);
                }
            }
            function dibujarHTML()
            {
                cache++;
                document.getElementById("resultado").innerHTML = "<style type='text/css'>@import url('http://localhost:8080/AjaxCSS/multiaportes/estilos.css?actualizado="+cache+"')</style>"+document.getElementById("cHTML").value;
            }
            function generarCodigo()
            {
                crearXMLHttpRequest();
                inicializar();
                dibujarHTML();
            }
        </script>
        
        C&oacute;digo CSS<br/>
        <textarea name="codigoCSS" id="cCSS"></textarea><br/>
        C&oacute;digo HTML<br/>
        <textarea name="codigoHTML" id="cHTML"></textarea><br/>
        <input type="button" value="Generar" onclick="generarCodigo()">
        <br/>
        <hr/>
        <div id="resultado">
        </div>
    </body>
</html>
