<!DOCTYPE html>
<html>
    <head>
        <title>Ejemplo Get y Post</title>
    </head>
    <body>
        <!-- Vulnerables a XSS: <script>alert('p')</script> -->
        <h1>M&eacute;todo GET</h1>
        <form action="MetodoGet" method="GET">
            <input type="text" name="textoget">
        </form>
        <h1>M&eacute;todo POST</h1>
        <form action="MetodoPost" method="POST">
            <input type="text" name="textopost">
        </form>
        <br/>
        <h3>Por Ortega Ortu&ntilde;o Eder | multiaportes.com</h3>
    </body>
</html>
