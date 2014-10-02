import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Flow extends JFrame
{
    private JButton primero;
    private JButton anterior;
    private JButton siguiente;
    private JButton ultimo;
    
    public Flow()
    {
    	super("Ejemplo FlowLayout");
        this.setLayout(new FlowLayout());
        initComponentes();
        add(primero);
        add(anterior);
        add(siguiente);
        add(ultimo);
        setSize(350, 400);
        setVisible(true);
    }
    public void initComponentes()
    {
       primero = new JButton("Primero");
       anterior = new JButton("Anterior");
       siguiente = new JButton("Siguiente");
       ultimo = new JButton("Ultimo");
    }
    
    public static void main(String args[])
    {
        new Flow();
    }
}