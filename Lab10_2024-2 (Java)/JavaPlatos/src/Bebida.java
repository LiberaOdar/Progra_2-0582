import java.util.Scanner;

public class Bebida extends Producto {
    private String tamano;

    public String getTamano() {
        return tamano;
    }

    public void setTamano(String tamano) {
        this.tamano = tamano;
    }
    //142 B Agua_Mineral 2.5 pequeno
    @Override
    public void leer(Scanner arch) {
        super.leer(arch);
        tamano =arch.next();
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println(tamano);
    }

    @Override
    public int tipoproducto() {
        return 0;
    }
}
