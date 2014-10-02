/*
	CECyT No. 3
	Programación de Sistemas
	Ortega Ortuño Eder - 6IM5
*/

// Ejercicio 4 - Uso de la función split, generar gráficas en un applet

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class GraficasSplit extends JApplet
{
	private String cadena;
	private String separados[];
	private int l, cont;
	private Color c;
	
	private int generaraleatorio(int lim)
	{
		double azar;
		
		azar = Math.random(); // Devuelve un valor entre 0,0 y 1,0
		
		lim = (int)(azar * lim); // Hacer un casting de double a entero
		
		return lim;
	}
	
	public void init()
	{
		int veces = 0;
		do
		{
			cadena = JOptionPane.showInputDialog("Introduce los valores separados por comas");
			if(cadena == null)
			{
				JOptionPane.showMessageDialog(null, "No has introducido valor alguno");
				veces++;
			}
			else
			{
				break;
			}
		}
		while(veces > 0);
		
		separados = cadena.split(",");
		
		l = (separados.length) - 1; // Se resta una unidad porque la longitud se empieza a numerar desde 1
	}
	
	public void paint(Graphics xD)
	{
		int xA, yA, marca = 20, xr = 80, tam = 130; // XApplet, YApplet, marca en Y, ancho de la barra
		int valores[] = new int[l + 1];
		String m; // Marca en el eje Y
		
		super.paint(xD);
		
		for(cont = 0; cont <= l; cont++)
		{
			valores[cont] = Integer.parseInt(separados[cont]);
		}
		
		// Obtener tamaño del applet con uso del referenciador 'this'
		Dimension dim = this.getSize();
		xA = dim.width;
		yA = dim.height;
		
		// Dibujar ejes X e Y
		xD.drawLine(0, yA - 100, xA, yA - 100); // x1, y1, x2, y2 - Dibujar eje X
		xD.drawLine(100, 0, 100, yA); // Dibujar eje Y
		
		// Imprimir el tamaño del applet
		String w = Integer.toString(xA);
		String h = Integer.toString(yA);
		xD.drawString("Tamaño del applet: " + w + "x" + h, (xA / 2) - 100, yA - 45);
		
		for(cont = 0; cont <= l + 1; cont++)
		{
			if(cont == 0)
			{
				continue;
			}
			c = new Color(generaraleatorio(255), generaraleatorio(255), generaraleatorio(255));
			xD.setColor(c);
			xD.fillRect(100 + (xr * (cont - 1)), yA - (100 + valores[cont-1]), xr, valores[cont-1]); // x, y, ancho, alto
			xD.setColor(Color.BLACK);
			xD.drawString(separados[cont-1] + " px", tam + (xr * (cont - 1)), yA - 85);
		}
		
		for(cont = yA - 120; cont >= 20; cont -= 20)
		{
			xD.setColor(Color.BLACK);
			xD.drawLine(90, cont, 110, cont);
			m = Integer.toString(marca);
			xD.drawString(m, 65, cont + 5);
			marca += 20;
		}
	}
}