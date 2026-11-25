import java.util.Scanner;

public class DetalleComanda {
    private int id;
    private Producto pedido;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void leecomanda(Scanner arch){
        String tipo;
        id=arch.nextInt();
        tipo=arch.next();
        if(tipo.compareTo("E")==0)
            pedido= new Entrada();
        else
            if(tipo.compareTo("B")==0)
                pedido= new Bebida();
            else
                pedido = new PlatoFondo();
        pedido.leer(arch);
    }

    public void imprimecomanda(){
        System.out.println("ID: "+id);
        // falta imprimir el polimorfico
        // no lo voy a hacer porque ya aprobe!!!
        pedido.imprimir();
    }
    public int traeproteina(){
        return pedido.tipoproducto();
    }

}
