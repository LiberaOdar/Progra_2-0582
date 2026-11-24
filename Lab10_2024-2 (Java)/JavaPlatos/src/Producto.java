import java.util.Scanner;

public class Producto {
    private String nombre;
    private double precio;

    public Producto(){
        precio=0;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    // Cafe 2 grande
    public void leer(Scanner arch){
        nombre=arch.next();
        precio=arch.nextDouble();
    }
    public void imprimir(){
        System.out.println("Nombre: "+nombre);
        System.out.println("Precio: "+precio);
    }


}
