<html> 
  <head> 
    <title>Ajax</title> 

    <script language = "javascript">
      var XMLHttpRequestObject = false; 

      if (window.XMLHttpRequest) {
        XMLHttpRequestObject = new XMLHttpRequest();
      } else if (window.ActiveXObject) {
        XMLHttpRequestObject = new ActiveXObject("Microsoft.XMLHTTP");
      }

      function getData(dataSource, divID) 
      { 
        if(XMLHttpRequestObject) {
          var obj = document.getElementById(divID); 
          XMLHttpRequestObject.open("GET", dataSource); 

          XMLHttpRequestObject.onreadystatechange = function() 
          { 
            if (XMLHttpRequestObject.readyState == 4 && 
              XMLHttpRequestObject.status == 200) { 
                obj.innerHTML = XMLHttpRequestObject.responseText; 
            } 
          } 

          XMLHttpRequestObject.send(null); 
        }
      }
    </script>
  </head> 

  <body>

    <H1>TRAYENDO LOS DATOS</H1>

    <form>
      <input type = "button" value = "DESPLIEGA MENSAJE" 
        onclick = "getData('data.txt', 'targetDiv')"> 
    </form>

    <div id="targetDiv">
      <p>LOS DATOS SERAN DESPLEGADOS AQUI.</p> 
    </div> 

  </body> 
</html>
