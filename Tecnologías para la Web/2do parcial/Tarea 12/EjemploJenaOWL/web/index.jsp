<!DOCTYPE html>
<html>
    <head>
        <title>JSP Page</title>
    </head>
    <body>
        <style type="text/css">
            body
            {
                background-color: #FF0;                
            }
            #f
            {
                margin-top: 15%;
                margin-left: 18%;
                padding: 10px;
                width: 60%;
                height: 60px;
                font-size: 30px;
                color: #000;
                border: 1px dashed #000;
            }
        </style>
        
        <script type="text/javascript">
            function quitarTextoDefault(caja)
            {
                if(caja.value == 'Nombre del archivo')
                    caja.value = '';
            }
            function ponerTextoDefault(caja)
            {
                if(caja.value == '')
                    caja.value = caja.defaultValue;
            }
        </script>
        <form action="GenerarOWL" method="GET">
            <input type="text" name="archivo" id="f" value="Nombre del archivo" onclick="quitarTextoDefault(this)" onblur="ponerTextoDefault(this)">
        </form>
    </body>
</html>
