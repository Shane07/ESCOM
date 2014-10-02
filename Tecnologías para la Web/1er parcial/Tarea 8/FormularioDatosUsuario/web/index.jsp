<!DOCTYPE html>
<html>
    <head>
        <title>Ejemplo Get y Post</title>
        <style type="text/css">
            @import url("estilos.css");
        </style>
        <script type="text/javascript">
            function getFormulario()
            {
                var i, meses = new Array("Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre");
                document.write("<select name='dia'>");
                for(i = 1; i <= 31; i++)
                {
                    document.write("<option value='"+i+"'>"+i+"</option>");
                }
                document.write("</select>");
                
                document.write("<select name='mes'>");
                for(i = 0; i < meses.length; i++)
                {
                    document.write("<option value='"+meses[i]+"'>"+meses[i]+"</option>");
                }
                document.write("</select>");
                
                document.write("<select name='anio'>");
                for(i = 2014; i >= 1994; i--)
                {
                    document.write("<option value='"+i+"'>"+i+"</option>");
                }
                document.write("</select>");
            }
        </script>
    </head>
    <body>
        <h1>Validaci&oacute;n de datos</h1>
        <form action="Validacion" method="POST">
            Nombre: <input type="text" name="nombre">
            Apellido: <input type="text" name="apellido">
            <br/>
            Usuario: <input type="text" name="username">
            <br/>
            Contrase&ntilde;a: <input type="password" name="clave">
            <br>
            Sexo: <input type="radio" name="sexo" value="hombre">Hombre<input type="radio" name="sexo" value="mujer">Mujer
            <br/>
            Fecha de nacimiento: <script type="text/javascript">getFormulario()</script>
            <br/>
            <br/>
            <div id="btn"><input type="submit" name="enviar" value="Validar"></div>
        </form>
        <br/>
        <br/>
        <h6>Por Ortega Ortu&ntilde;o Eder | multiaportes.com</h6>
    </body>
</html>
