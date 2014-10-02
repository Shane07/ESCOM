import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Border extends JFrame
{
    private JButton botones[];
    private final String[] nombres = {"Norte", "Sur", "Este", "Oeste", "Centro"};
    private BorderLayout adminDis;
    
    public Border()
    {
        super("Ejemplo BorderLayout");
        initComponentes();
        setSize(350, 400);
        setVisible(true);
    }
    public void initComponentes()
    {
       adminDis = new BorderLayout(5, 5); // Espacios de 5px
       Container contenedor = getContentPane();
       contenedor.setLayout(adminDis);
       botones = new JButton[nombres.length];
       for(int k = 0; k < nombres.length; k++)
       {
           botones[k] = new JButton(nombres[k]);
           botones[k].setToolTipText("Botones de BorderLayout "+nombres[k]);
       }
       contenedor.add(botones[0], BorderLayout.NORTH);
       contenedor.add(botones[1], BorderLayout.SOUTH);
       contenedor.add(botones[2], BorderLayout.EAST);
       contenedor.add(botones[3], BorderLayout.WEST);
       contenedor.add(botones[4], BorderLayout.CENTER);
    }
    
    public static void main(String args[])
    {
        Border a = new Border();
        a.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}