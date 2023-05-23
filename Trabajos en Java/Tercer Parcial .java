import java.io.*;
import java.util.ArrayList;
import java.util.List;

// Clase abstracta ConjuntoDeDatos
abstract class ConjuntoDeDatos {
    protected String nombre;
    protected int tamaño;

    public ConjuntoDeDatos(String nombre, int tamaño) {
        this.nombre = nombre;
        this.tamaño = tamaño;
    }

    public abstract String describir();
}

// Clase ConjuntoDeDatosTabular que hereda de ConjuntoDeDatos
class ConjuntoDeDatosTabular extends ConjuntoDeDatos {
    private int numeroDeColumnas;
    private int numeroDeFilas;

    public ConjuntoDeDatosTabular(String nombre, int tamaño, int numeroDeColumnas, int numeroDeFilas) {
        super(nombre, tamaño);
        this.numeroDeColumnas = numeroDeColumnas;
        this.numeroDeFilas = numeroDeFilas;
    }

    @Override
    public String describir() {
        return "Nombre: " + nombre + "\n" +
                "Tamaño: " + tamaño + "\n" +
                "Tipo: Tabular" + "\n" +
                "Filas: " + numeroDeFilas + "\n" +
                "Columnas: " + numeroDeColumnas;
    }
}

// Clase ConjuntoDeDatosImagen que hereda de ConjuntoDeDatos
class ConjuntoDeDatosImagen extends ConjuntoDeDatos {
    private int ancho;
    private int alto;

    public ConjuntoDeDatosImagen(String nombre, int tamaño, int ancho, int alto) {
        super(nombre, tamaño);
        this.ancho = ancho;
        this.alto = alto;
    }

    @Override
    public String describir() {
        return "Nombre: " + nombre + "\n" +
                "Tamaño: " + tamaño + "\n" +
                "Tipo: Imagen" + "\n" +
                "Ancho: " + ancho + "\n" +
                "Alto: " + alto;
    }
}

// Clase AnalizadorDeDatos
class AnalizadorDeDatos {
    private List<ConjuntoDeDatos> conjuntosDeDatos;

    public AnalizadorDeDatos() {
        conjuntosDeDatos = new ArrayList<>();
    }

    public void añadirConjuntoDeDatos(ConjuntoDeDatos conjuntoDeDatos) {
        conjuntosDeDatos.add(conjuntoDeDatos);
    }

    public void eliminarConjuntoDeDatos(String nombre) {
        conjuntosDeDatos.removeIf(conjunto -> conjunto.nombre.equals(nombre));
    }

    public List<String> describirConjuntosDeDatos() {
        List<String> descripciones = new ArrayList<>();
        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {
            descripciones.add(conjunto.describir());
        }
        return descripciones;
    }
}

// Clase ContadorConjuntosDeDatos
class ContadorConjuntosDeDatos {

    public void contarTipos(List<ConjuntoDeDatos> conjuntosDeDatos) {
        int total = conjuntosDeDatos.size();
        int contadorImagenes = 0;
        int contadorTabulares = 0;

        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {
            if (conjunto instanceof ConjuntoDeDatosImagen) {
                contadorImagenes++;
            } else if (conjunto instanceof ConjuntoDeDatosTabular) {
                contadorTabulares++;
            }
        }

        double porcentajeImagenes = (double) contadorImagenes / total * 100;
        double porcentajeTabulares = (double) contadorTabulares / total * 100;

        System.out.printf("Cantidad de ConjuntoDeDatosImagen: %d (%.2f%%)\n", contadorImagenes, porcentajeImagenes);
        System.out.printf("Cantidad de ConjuntoDeDatosTabular: %d (%.2f%%)\n", contadorTabulares, porcentajeTabulares);
    }
}

// Función para deserializar una lista de objetos tipo ConjuntoDeDatos desde un archivo
public static List<ConjuntoDeDatos> deserializarConjuntosDeDatos(String rutaArchivo) {
    List<ConjuntoDeDatos> conjuntosDeDatos = new ArrayList<>();

    try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(rutaArchivo))) {
        conjuntosDeDatos = (List<ConjuntoDeDatos>) inputStream.readObject();
    } catch (IOException | ClassNotFoundException e) {
        System.out.println("Error al deserializar el archivo: " + e.getMessage());
    }

    return conjuntosDeDatos;
}

public class Main {

    public static void main(String[] args) {
        AnalizadorDeDatos analizador = new AnalizadorDeDatos();

        // Crear instancias de ConjuntoDeDatosTabular y ConjuntoDeDatosImagen
        ConjuntoDeDatos conjuntoTabular = new ConjuntoDeDatosTabular("Datos de estudiantes", 1000, 5, 200);
        ConjuntoDeDatos conjuntoImagen1 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);
        ConjuntoDeDatos conjuntoImagen2 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);

        // Agregar conjuntos de datos al analizador
        analizador.añadirConjuntoDeDatos(conjuntoTabular);
        analizador.añadirConjuntoDeDatos(conjuntoImagen1);
        analizador.añadirConjuntoDeDatos(conjuntoImagen2);

        // Obtener descripciones de los conjuntos de datos
        List<String> descripciones = analizador.describirConjuntosDeDatos();

        // Imprimir descripciones
        for (String descripcion : descripciones) {
            System.out.println(descripcion);
            System.out.println("------------------------------");
        }

        // Contar la cantidad de ConjuntoDeDatosImagen y ConjuntoDeDatosTabular
        ContadorConjuntosDeDatos contador = new ContadorConjuntosDeDatos();
        contador.contarTipos(analizador.conjuntosDeDatos);

        // Deserializar conjuntos de datos desde un archivo
        String rutaArchivo = "conjuntos_de_datos.ser";
        List<ConjuntoDeDatos> conjuntosDeserializados = deserializarConjuntosDeDatos(rutaArchivo);
        System.out.println("\nConjuntos de datos deserializados:");
        for (ConjuntoDeDatos conjunto : conjuntosDeserializados) {
            System.out.println(conjunto.describir());
            System.out.println("------------------------------");
        }
    }
}
