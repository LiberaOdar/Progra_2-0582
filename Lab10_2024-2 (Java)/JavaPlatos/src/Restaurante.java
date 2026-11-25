import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Restaurante {
    private Scanner arch;
    private ArrayList<DetalleComanda> lcomandas;

    public Restaurante(String nombre)throws FileNotFoundException {
        lcomandas = new ArrayList<>();
        arch=new Scanner(new File(nombre));
    }

    // 142 B Cafe 2 grande
    public void carga(){
        while(arch.hasNext()){
            DetalleComanda aux;
            aux=new DetalleComanda();
            aux.leecomanda(arch);
            lcomandas.add(aux);
        }
    }

    public void imprime(){
        for(DetalleComanda aux:lcomandas){
            aux.imprimecomanda();
            System.out.println();
        }
    }

    public void elimina(int producto){
        //me falta el bypass
        lcomandas.removeIf(aux->aux.traeproteina()==producto);
    }

}
