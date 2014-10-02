/*
 * Descripcion: esta clase permite trabajar con puntos de un sistema coordenado
 * @author: Eder Ortega Ortuño - 2CV7
 */

public class Punto
{
	// Atributos
	private double coordX, coordY;
	
	// Constructores
	/*
	 * Constructor por default
	 */
	public Punto()
	{
		coordX = 100.0;
		coordY = 100.0;
	}
	
	/*
	 * Constructor por parámetros
	 * @param: coordX coordenada X
	 * @param: coordY coordenada Y
	 */
	public Punto(double x, double y)
	{
		coordX = x;
		coordY = y;
	}
	
	// Métodos (set, get, etc.)
	/*
	 * Establecer posición en X
	 * @param: x coordenada X
	 */
	public void setX(double x)
	{
		coordX = x;
	}
	/*
	 * Establecer posición en Y
	 * @param: y coordenada Y
	 */
	public void setY(double y)
	{
		coordY = y;
	}
	/*
	 * Obtener el valor actual en X
	 * @return: coordX coordenada X
	 */
	public double getX()
	{
		return coordX;
	}
	/*
	 * Obtener el valor actual en Y
	 * @return: coordY coordenada Y
	 */
	public double getY()
	{
		return coordY;
	}
}
