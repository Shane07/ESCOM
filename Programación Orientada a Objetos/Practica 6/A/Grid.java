import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Grid extends JFrame
{
    private JButton botones[];
    private final String[] nombres = {"Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis"};
    private BorderLayout adminDis;
    private GridLayout cuadricula1;
    
    public Grid()
    {
        super("Ejemplo GridLayout");
        initComponentes();
        setSize(350, 400);
        setVisible(true);
    }
    public void initComponentes()
    {
       cuadricula1 = new GridLayout(2, 3, 10, 10);
       Container contenedor = getContentPane();
       contenedor.setLayout(cuadricula1);
       botones = new JButton[nombres.length];
       for(int k = 0; k < nombres.length; k++)
       {
           botones[k] = new JButton(nombres[k]);
           botones[k].setToolTipText("Botones de GridLayout "+nombres[k]);
       }
       contenedor.add(botones[0]);
       contenedor.add(botones[1]);
       contenedor.add(botones[2]);
       contenedor.add(botones[3]);
       contenedor.add(botones[4]);
       contenedor.add(botones[5]);
    }
    
    public static void main(String args[])
    {
        Grid a = new Grid();
        a.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}