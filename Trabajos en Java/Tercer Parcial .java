import java.util.ArrayList;

abstract class ConjuntoDeDatos {
    protected String nombre;
    protected int tamaño;

    public ConjuntoDeDatos(String nombre, int tamaño) {
        this.nombre = nombre;
        this.tamaño = tamaño;
    }

    public abstract String describir();
}

class ConjuntoDeDatosTabular extends ConjuntoDeDatos {
    private int numeroDeFilas;
    private int numeroDeColumnas;

    public ConjuntoDeDatosTabular(String nombre, int tamaño, int numeroDeFilas, int numeroDeColumnas) {
        super(nombre, tamaño);
        this.numeroDeFilas = numeroDeFilas;
        this.numeroDeColumnas = numeroDeColumnas;
    }

    @Override
    public String describir() {
        return "Nombre: " + nombre + "\nTamaño: " + tamaño + "\nTipo: Tabular\nFilas: " + numeroDeFilas + "\nColumnas: " + numeroDeColumnas;
    }
}

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
        return "Nombre: " + nombre + "\nTamaño: " + tamaño + "\nTipo: Imagen\nAncho: " + ancho + "\nAlto: " + alto;
    }
}

class AnalizadorDeDatos {
    private ArrayList<ConjuntoDeDatos> conjuntosDeDatos;

    public AnalizadorDeDatos() {
        conjuntosDeDatos = new ArrayList<>();
    }

    public void añadirConjuntoDeDatos(ConjuntoDeDatos conjuntoDeDatos) {
        conjuntosDeDatos.add(conjuntoDeDatos);
    }

    public void eliminarConjuntoDeDatos(String nombre) {
        for (int i = 0; i < conjuntosDeDatos.size(); i++) {
            if (conjuntosDeDatos.get(i).nombre.equals(nombre)) {
                conjuntosDeDatos.remove(i);
                break;
            }
        }
    }

    public ArrayList<String> describirConjuntosDeDatos() {
        ArrayList<String> descripciones = new ArrayList<>();
        for (ConjuntoDeDatos conjuntoDeDatos : conjuntosDeDatos) {
            descripciones.add(conjuntoDeDatos.describir());
        }
        return descripciones;
    }
}

public class Main {
    public static void main(String[] args) {
        ConjuntoDeDatosTabular conjunto1 = new ConjuntoDeDatosTabular("Datos de estudiantes", 1000, 200, 5);
        ConjuntoDeDatosImagen conjunto2 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);
        ConjuntoDeDatosImagen conjunto3 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);

        AnalizadorDeDatos analizador = new AnalizadorDeDatos();
        analizador.añadirConjuntoDeDatos(conjunto1);
        analizador.añadirConjuntoDeDatos(conjunto2);
        analizador.añadirConjuntoDeDatos(conjunto3);

        ArrayList<String> descripciones = analizador.describirConjuntosDeDatos();
        for (String descripcion : descripciones) {
            System.out.println(descripcion);
            System.out.println("--------------------------");
        }
    }
}
