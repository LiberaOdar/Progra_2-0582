import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {
    public static void main(String[] args)throws IOException {
        Restaurante res=new Restaurante("comandas2.txt");
        res.carga();
        res.elimina(1);
        res.imprime();
    }
}