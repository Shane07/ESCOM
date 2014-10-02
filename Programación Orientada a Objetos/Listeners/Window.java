import java.awt.FlowLayout;
import java.awt.GridLayout;
import javax.swing.*;

public class Window extends JFrame
{
    private JButton b1, b2;
    private Manager m;
    private int tmp = 2;
    
    public Window()
    {
        init();
        this.setTitle("Ejemplo escuchas/listeners Java");
        this.setSize(640, 480);
        this.setLocation(600, 300);
        this.setResizable(false);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setVisible(true);
    }
    
    void init()
    {
        b1 = new JButton("Boton 1");
        b2 = new JButton("Boton 2");
        m = new Manager();
        
        if(tmp == 0)
            this.setLayout(new FlowLayout());
        else if(tmp == 1)
            this.setLayout(new GridLayout());
        else if(tmp == 2)
        {
            this.setLayout(null);
            b1.setBounds(200, 100, 170, 70);
            b2.setBounds(400, 350, 170, 70);
        }
        
        b1.addActionListener(m);
        b2.addActionListener(m);
        this.add(b1);
        this.add(b2);
    }
}