-- Es necesario dejar un espacio despues de ambos guiones para que sea un comentario valido
-- mysql -u root < archivo.sql

-- SCRIPT para el autocompletado

CREATE DATABASE BaseAutocompletado;

use BaseAutocompletado;

SET FOREIGN_KEY_CHECKS = 0;

-- tablas

CREATE TABLE Palabra(idPalabra INT NOT NULL AUTO_INCREMENT, texto VARCHAR(10) NOT NULL,
			PRIMARY KEY(idPalabra));

SET FOREIGN_KEY_CHECKS = 1;

GRANT ALL ON BaseAutocompletado.* TO admin@localhost IDENTIFIED BY 'adminAuto';

-- Insertando datos de ejemplo

INSERT INTO Palabra(texto) VALUES('Abe');
INSERT INTO Palabra(texto) VALUES('Abel');
INSERT INTO Palabra(texto) VALUES('Abigail');
INSERT INTO Palabra(texto) VALUES('Abner');
INSERT INTO Palabra(texto) VALUES('Abraham');
INSERT INTO Palabra(texto) VALUES('Marcus');
INSERT INTO Palabra(texto) VALUES('Marcy');
INSERT INTO Palabra(texto) VALUES('Marge');
INSERT INTO Palabra(texto) VALUES('Marie');
