package multiaportes;

import java.sql.Connection;
import java.util.ArrayList;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class ServicioAutocompletado{
	Connection con = null;
	
	public ServicioAutocompletado(){
		iniciarConexion();
	}
	
	//Inicia la conexión con la base de datos
	private void iniciarConexion(){
		try{
			Class.forName("com.mysql.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost/BaseAutocompletado", "admin", "adminAuto");
		}catch(SQLException e){
			System.err.println("Error SQL al intentar conectar con la base de datos");
			e.printStackTrace();
		}catch(ClassNotFoundException ee){
			System.err.println("No se pudo cargar la clase " + ee);
		}
	}

	//Cerrando la conexión con la base de datos
	public void cerrarConexion(){
		try{
			con.close();
		}catch(SQLException e){
			System.err.println("No se pudo cerrar la conexión con la base de datos");
			e.printStackTrace();
		}
	}
	
	//Obteniendo la lista de palabras
	public ArrayList obtListaPalabras(){
		Statement s;
		ResultSet rs;
		ArrayList palabras = new ArrayList();
		try{
			s = con.createStatement();
			rs = s.executeQuery(" SELECT Palabra.texto FROM Palabra");

			while(rs.next()){
				palabras.add(rs.getString("Palabra.texto"));
			}
		}catch(SQLException e){
			System.out.println("Problemas SQL en obtListaPalabras de servicioAutocompletado");
			e.printStackTrace();
		}catch(Exception ee){
			System.out.println("Problemas en obtListaPalabras de servicioAutocompletado");
			ee.printStackTrace();	
		}
		return palabras;
	}	
}