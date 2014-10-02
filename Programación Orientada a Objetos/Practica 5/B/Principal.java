import java.util.Calendar;
import javax.swing.JOptionPane;

public class Principal
{
	static final int cantidadProductos = 6;
	
    static Electrodomestico k[] = new Electrodomestico[3];
    static Vivere r[] = new Vivere[3];
    static int productos[] = new int[cantidadProductos];
    static boolean nombres[] = new boolean[cantidadProductos];
    static boolean compra = false;
    
    public static void main(String args[])
    {
    	Calendar caducidad = Calendar.getInstance();
    	
        k[0] = new Electrodomestico(1, 15, "LG", "Television LED 32inch", 7600.0f);
        k[0].setGarantia(18);
        k[1] = new Electrodomestico(2, 8, "Mabe", "Lavadora blanca 13Kg", 5400.0f);
        k[1].setGarantia(24);
        k[2] = new Electrodomestico(3, 20, "Samsung", "Laptop Pantalla Touch 13inch", 6200.0f);
        
        caducidad.set(2016, Calendar.APRIL, 7);
        r[0] = new Vivere(4, 200, "Gamesa", "Galletas de animalitos", 35.5f, caducidad);
        caducidad.set(2014, Calendar.JANUARY, 2);
        r[1] = new Vivere(4, 560, "Alpura", "Leche deslactosada", 14.5f, caducidad);
        caducidad.set(2015, Calendar.OCTOBER, 8);
        r[2] = new Vivere(4, 175, "Ricolino", "Paleta Payaso", 7.0f, caducidad);
        
        for(int q = 0; q < productos.length; q++)
        {
        	nombres[q] = false;
         	productos[q] = 0;
        }
        
        menu();
    }
    private static void menu()
    {
    	int principal, tipo, producto, cantidad;
    	float subtotal, total = 0.0f;
    	String lista = "";
    	
    	while(true)
    	{
    		principal = JOptionPane.showOptionDialog(null, "Elige una opcion:\n", "Inicio", JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, new Object[]{"Productos", "Carro de compras", "Salir"}, "Salir");
    		if(principal == 0)
    		{
    			tipo = JOptionPane.showOptionDialog(null, "Selecciona el tipo de producto:\n", "Seleccionar tipo de producto", JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, new Object[]{"Electrodomesticos", "Viveres"}, null);
    			if(tipo == 0)
    			{
    				producto = JOptionPane.showOptionDialog(null, "Selecciona el electrodomestico:\n", "Seleccionar electrodomestico", JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, new Object[]{"Television", "Lavadora", "Laptop"}, null);
    				switch(producto)
    				{
	    				case 0:
	    					try
	    					{
	    						cantidad = Integer.parseInt(JOptionPane.showInputDialog(null, k[producto].getInfo()+"\nIntroduce la cantidad:\n", "Caracteristicas de "+k[producto].getNombre(), JOptionPane.INFORMATION_MESSAGE));
	    						if(k[producto].venderProd(cantidad) && cantidad > 0)
	    						{
	    							nombres[0] = true;
	    							productos[0] = productos[0] + cantidad;
	    							compra = true;
	    						}
	    						else
	    							JOptionPane.showMessageDialog(null, "No hay suficientes productos en stock", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					catch(java.lang.NumberFormatException excepcion)
	    					{
	    						JOptionPane.showMessageDialog(null, "No es una cantidad valida", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					break;
	    				case 1:
	    					try
	    					{
	    						cantidad = Integer.parseInt(JOptionPane.showInputDialog(null, k[producto].getInfo()+"\nIntroduce la cantidad:\n", "Caracteristicas de "+k[producto].getNombre(), JOptionPane.INFORMATION_MESSAGE));
	    						if(k[producto].venderProd(cantidad) && cantidad > 0)
	    						{
	    							nombres[1] = true;
	    							productos[1] = productos[1] + cantidad;
	    							compra = true;
	    						}
	    						else
	    							JOptionPane.showMessageDialog(null, "No hay suficientes productos en stock", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					catch(java.lang.NumberFormatException excepcion)
	    					{
	    						JOptionPane.showMessageDialog(null, "No es una cantidad valida", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					break;
	    				case 2:
	    					try
	    					{
	    						cantidad = Integer.parseInt(JOptionPane.showInputDialog(null, k[producto].getInfo()+"\nIntroduce la cantidad:\n", "Caracteristicas de "+k[producto].getNombre(), JOptionPane.INFORMATION_MESSAGE));
	    						if(k[producto].venderProd(cantidad) && cantidad > 0)
	    						{
	    							nombres[2] = true;
	    							productos[2] = productos[2] + cantidad;
	    							compra = true;
	    						}
	    						else
	    							JOptionPane.showMessageDialog(null, "No hay suficientes productos en stock", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					catch(java.lang.NumberFormatException excepcion)
	    					{
	    						JOptionPane.showMessageDialog(null, "No es una cantidad valida", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					break;
    				}
    			}
    			else if(tipo == 1)
    			{
    				producto = JOptionPane.showOptionDialog(null, "Selecciona el vivere:\n", "Seleccionar vivere", JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, new Object[]{"Galletas", "Leche", "Paleta"}, null);
    				switch(producto)
    				{
	    				case 0:
	    					try
	    					{
	    						cantidad = Integer.parseInt(JOptionPane.showInputDialog(null, r[producto].getInfo()+"\nIntroduce la cantidad:\n", "Caracteristicas de "+r[producto].getNombre(), JOptionPane.INFORMATION_MESSAGE));
	    						if(r[producto].venderProd(cantidad) && cantidad > 0)
	    						{
	    							nombres[3] = true;
	    							productos[3] = productos[3] + cantidad;
	    							compra = true;
	    						}
	    						else
	    							JOptionPane.showMessageDialog(null, "No hay suficientes productos en stock", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					catch(java.lang.NumberFormatException excepcion)
	    					{
	    						JOptionPane.showMessageDialog(null, "No es una cantidad valida", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					break;
	    				case 1:
	    					try
	    					{
	    						cantidad = Integer.parseInt(JOptionPane.showInputDialog(null, r[producto].getInfo()+"\nIntroduce la cantidad:\n", "Caracteristicas de "+r[producto].getNombre(), JOptionPane.INFORMATION_MESSAGE));
	    						if(r[producto].venderProd(cantidad) && cantidad > 0)
	    						{
	    							nombres[4] = true;
	    							productos[4] = productos[4] + cantidad;
	    							compra = true;
	    						}
	    						else
	    							JOptionPane.showMessageDialog(null, "No hay suficientes productos en stock", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					catch(java.lang.NumberFormatException excepcion)
	    					{
	    						JOptionPane.showMessageDialog(null, "No es una cantidad valida", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					break;
	    				case 2:
	    					try
	    					{
	    						cantidad = Integer.parseInt(JOptionPane.showInputDialog(null, r[producto].getInfo()+"\nIntroduce la cantidad:\n", "Caracteristicas de "+r[producto].getNombre(), JOptionPane.INFORMATION_MESSAGE));
	    						if(r[producto].venderProd(cantidad) && cantidad > 0)
	    						{
	    							nombres[5] = true;
	    							productos[5] = productos[5] + cantidad;
	    							compra = true;
	    						}
	    						else
	    							JOptionPane.showMessageDialog(null, "No hay suficientes productos en stock", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					catch(java.lang.NumberFormatException excepcion)
	    					{
	    						JOptionPane.showMessageDialog(null, "No es una cantidad valida", "Error en la compra", JOptionPane.ERROR_MESSAGE);
	    					}
	    					break;
    				}
    			}
    		}
    		if(principal == 1)
    		{
    			if(!compra)
    				JOptionPane.showMessageDialog(null, "El carro de compras esta vacio\n", "Carro de compras", JOptionPane.WARNING_MESSAGE);
    			else
    			{
	    			for(int q = 0; q < cantidadProductos; q++)
	    			{
	    				subtotal = 0.0f;
	    				if(nombres[q] == true && q < 3)
	    				{
	    					subtotal = productos[q]*k[q].getPrecio();
	    					lista = lista+"- "+k[q].getNombre()+":\ncantidad = "+productos[q]+" | subtotal = $"+subtotal+"\n";
	    				}
	    				else if(nombres[q] == true && q >= 3)
	    				{
	    					subtotal = productos[q]*r[q-3].getPrecio();
	    					lista = lista+"- "+r[q-3].getNombre()+":\ncantidad = "+productos[q]+" | subtotal = $"+subtotal+"\n";
	    				}
	    				total = total + subtotal;
	    			}
	    			JOptionPane.showMessageDialog(null, lista+"\nTotal: $"+total, "Carro de compras", JOptionPane.WARNING_MESSAGE);
	    			lista = "";
	    			total = 0.0f;
    			}
    		}
    		if(principal == 2)
    		{
    			JOptionPane.showMessageDialog(null, "Has finalizado tu sesion de compra.", "Compra finalizada", JOptionPane.WARNING_MESSAGE);
    			break;
    		}
    	}
    }
}