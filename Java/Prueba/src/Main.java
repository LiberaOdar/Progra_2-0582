//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
import java.util.Scanner;
/**
 *
 * @author cueva.r
 */
public class Main {
    public static void main(String[] args) {
        int dni;
        String nombre;
        int notas[]= new int[10];
        Scanner lee=new Scanner(System.in);
        System.out.println("Hola mundo del Java ya llegue");
        System.out.println("Ingrese su dni:");
        dni=lee.nextInt();
        System.out.println("Ingrese su nombre:");
        nombre=lee.next();
        System.out.println(dni+" "+nombre);
        for(int i=0;i<5;i++){
            System.out.println("Ingresa tu nota "+(i+1)+":");
            notas[i]=lee.nextInt();
        }
        for(int i=0;i<5;i++){
            System.out.print(notas[i]+" ");
        }

    }

}
