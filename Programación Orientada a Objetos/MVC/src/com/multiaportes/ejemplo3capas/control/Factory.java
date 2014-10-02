package com.multiaportes.ejemplo3capas.control;

import java.util.ArrayList;
import com.multiaportes.ejemplo3capas.modelo.Persona;
import javax.swing.JOptionPane;

public class Factory
{
    ArrayList<Persona> personas;
    
    public Factory()
    {
        personas = new ArrayList<>();
    }
    
    public void crear(String n, String p, String m)
    {
        Persona pr = new Persona(n,p,m);
        personas.add(pr);
    }
    
    public void eliminar(int indice)
    {
        personas.remove(indice);
    }
    
    public Persona buscar(String nombre)
    {
        for(int z = 0; z < personas.size(); z++)
            if(personas.get(z).getNombre().equals(nombre))
                return personas.get(z);
            else
                JOptionPane.showMessageDialog(null, "Not found");
        return null;
    }
}
