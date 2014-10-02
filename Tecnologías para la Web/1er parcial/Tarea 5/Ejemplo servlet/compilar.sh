#!/bin/bash

# Es necesario compilar con este JAR para detectar los javax.servlet.*
javac -cp .:/usr/share/java/tomcat7/servlet-api.jar EjemploServlet.java