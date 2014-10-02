<!DOCTYPE html>
<html>
    <head>
        <title>JSP Page</title>
    </head>
    <body>
        <form action="propiedadesFrame" method="POST">
            <select name="frames" onChange="this.form.submit()">
                <option value="-1">----------------------</option>
                <option value="1">Frame a la izquierda</option>
                <option value="2">Frame a la derecha</option>
                <option value="3">Frame arriba</option>
                <option value="4">Frame abajo</option>
                <option value="5">Frame inferior anidado izquierdo</option>
                <option value="6">Frame inferior anidado derecho</option>
                <option value="7">Frame izquierdo anidado superior</option>
                <option value="8">Frame izquierdo anidado inferior</option>
                <option value="9">Frame derecho anidado inferior</option>
                <option value="10">Frame derecho anidado superior</option>
                <option value="11">Frame superior e inferior</option>
                <option value="12">Frame superior anidado izquierdo</option>
                <option value="13">Frame superior anidado derecho</option>
            </select>
        </form>
    </body>
</html>
