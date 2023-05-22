// Clase principal: Vehiculo
class Vehiculo {
    private String marca;
    private String modelo;
    private int año;

    // Constructor
    public Vehiculo(String marca, String modelo, int año) {
        this.marca = marca;
        this.modelo = modelo;
        this.año = año;
    }

    // Métodos getter
    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public int getAño() {
        return año;
    }

    // Método para obtener información del vehículo
    public String getInfoVehiculo() {
        return "Marca: " + marca + ", Modelo: " + modelo + ", Año: " + año;
    }
}

// Clase derivada: Automovil
class Automovil extends Vehiculo {
    private int puertas;

    // Constructor
    public Automovil(String marca, String modelo, int año, int puertas) {
        super(marca, modelo, año);
        this.puertas = puertas;
    }

    // Método getter
    public int getPuertas() {
        return puertas;
    }

    // Método para obtener información del automóvil
    @Override
    public String getInfoVehiculo() {
        return super.getInfoVehiculo() + ", Puertas: " + puertas;
    }
}

// Clase derivada: Motocicleta
class Motocicleta extends Vehiculo {
    private int cilindrada;

    // Constructor
    public Motocicleta(String marca, String modelo, int año, int cilindrada) {
        super(marca, modelo, año);
        this.cilindrada = cilindrada;
    }

    // Método getter
    public int getCilindrada() {
        return cilindrada;
    }

    // Método para obtener información de la motocicleta
    @Override
    public String getInfoVehiculo() {
        return super.getInfoVehiculo() + ", Cilindrada: " + cilindrada;
    }
}

// Clase principal del programa
public class TallerHerenciaJava {
    public static void main(String[] args) {
        // Crear objetos de automóvil y motocicleta
        Automovil auto = new Automovil("Toyota", "Corolla", 2021, 4);
        Motocicleta moto = new Motocicleta("Honda", "CBR500R", 2022, 500);

        // Obtener información de los vehículos
        System.out.println("Información del automóvil:");
        System.out.println(auto.getInfoVehiculo());

        System.out.println("\nInformación de la motocicleta:");
        System.out.println(moto.getInfoVehiculo());
    }
}
