import java.awt.event.*;
import javax.swing.JOptionPane;

public class Manager implements ActionListener
{
    public void actionPerformed(ActionEvent z)
    {
        if(z.getActionCommand().equals("Boton 1"))
            JOptionPane.showMessageDialog(null, "Boton 1 seleccionado");
        else if(z.getActionCommand().equals("Boton 2"))
            JOptionPane.showMessageDialog(null, "Boton 2 seleccionado");
    }
}
