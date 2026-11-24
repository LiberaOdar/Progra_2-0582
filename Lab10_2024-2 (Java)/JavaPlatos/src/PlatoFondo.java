import java.util.Scanner;

public class PlatoFondo extends Producto{
    private int proteina;

    public PlatoFondo(){
        proteina=0;
    }

    public int getProteina() {
        return proteina;
    }

    public void setProteina(int proteina) {
        this.proteina = proteina;
    }
    //169 P Pasta_Alfredo 10 4
    @Override
    public void leer(Scanner arch) {
        super.leer(arch);
        proteina=arch.nextInt();
    }

    @Override
    public void imprimir() {
        super.imprimir();
        if(proteina==1)
            System.out.println("Pollo");
        if(proteina==2)
            System.out.println("Carne");
        if(proteina==3)
            System.out.println("Pescado");
        if(proteina==4)
            System.out.println("Lacteos");
    }
}
