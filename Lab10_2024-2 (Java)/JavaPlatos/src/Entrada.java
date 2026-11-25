import java.util.Scanner;

public class Entrada extends Producto {
    private boolean picante;

    public Entrada() {
        picante=false;
    }

    public boolean isPicante() {
        return picante;
    }

    public void setPicante(boolean picante) {
        this.picante = picante;
    }
    //142 E Quesadillas 5.5 sin_picante
    @Override
    public void leer(Scanner arch) {
        String sabor;
        super.leer(arch);
        sabor=arch.next();
        if(sabor.compareTo("picante")==0)
            picante=true;
    }

    @Override
    public void imprimir() {
        super.imprimir();
        if(picante==true)
            System.out.println("Picante");
        else
            System.out.println("Sin picante");
    }

    @Override
    public int tipoproducto() {
        return 0;
    }
}
