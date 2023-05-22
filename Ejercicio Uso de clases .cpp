#include <iostream>
#include <string>
using namespace std;
/******************************************************************************
*******************************************************************************/
const double PI = 3.1416;

class Circulo {
public:
    Circulo(double radio) : radio(radio) {}

    double calcularArea() {
        return PI * radio * radio;
    }

    double calcularPerimetro() {
        return 2 * PI * radio;
    }

    double calcularDiametro() {
        return 2 * radio;
    }

private:
    double radio;
};

class TrianguloRectangulo {
public:
    TrianguloRectangulo(double cateto1, double cateto2) : cateto1(cateto1), cateto2(cateto2) {}

    double calcularHipotenusa() {
        return sqrt(cateto1 * cateto1 + cateto2 * cateto2);
    }

    double calcularPerimetro() {
        return cateto1 + cateto2 + calcularHipotenusa();
    }

    double calcularAltura() {
        return cateto2;
    }

private:
    double cateto1;
    double cateto2;

    double sqrt(double num) {
        double epsilon = 1e-6;
        double x = num;
        double y = 1.0;

        while (x - y > epsilon) {
            x = (x + y) / 2;
            y = num / x;
        }

        return x;
    }
};

int main() {
    double radio, cateto1, cateto2;

    cout << "Ingrese el radio del círculo: ";
    cin >> radio;

    Circulo circulo(radio);
    cout << "Área del círculo: " << circulo.calcularArea() << endl;
    cout << "Perímetro del círculo: " << circulo.calcularPerimetro() << endl;
    cout << "Diámetro del círculo: " << circulo.calcularDiametro() << endl;

    cout << "Ingrese el primer cateto del triángulo rectángulo: ";
    cin >> cateto1;
    cout << "Ingrese el segundo cateto del triángulo rectángulo: ";
    cin >> cateto2;

    TrianguloRectangulo triangulo(cateto1, cateto2);
    cout << "Hipotenusa del triángulo rectángulo: " << triangulo.calcularHipotenusa() << endl;
    cout << "Perímetro del triángulo rectángulo: " << triangulo.calcularPerimetro() << endl;
    cout << "Altura del triángulo rectángulo: " << triangulo.calcularAltura() << endl;

    return 0;
}


/******************************************************************************
*******************************************************************************/









class Persona {
public:
    Persona(string nombre) : nombre(nombre) {}

    void presentarse() {
        cout << "Soy una persona llamada " << nombre << "." << endl;
    }

protected:
    string nombre;
};

class Profesor : public Persona {
public:
    Profesor(string nombre, string materia) : Persona(nombre), materia(materia) {}

    void presentarse() {
        Persona::presentarse();
        cout << "Soy un profesor y enseño " << materia << "." << endl;
    }

private:
    string materia;
};

class Estudiante : public Persona {
public:
    Estudiante(string nombre, int grado) : Persona(nombre), grado(grado) {}

    void presentarse() {
        Persona::presentarse();
        cout << "Estoy en el grado " << grado << "." << endl;
    }

    bool puedeInscribirseEnProgramacion() {
        return grado >= 9;
    }

private:
    int grado;
};

int main() {
    string nombrePersona, nombreProfesor, materiaProfesor, nombreEstudiante;
    int gradoEstudiante;

    cout << "Ingresa el nombre de la persona: ";
    getline(cin, nombrePersona);

    cout << "Ingresa el nombre del profesor: ";
    getline(cin, nombreProfesor);

    cout << "Ingresa la materia del profesor: ";
    getline(cin, materiaProfesor);

    cout << "Ingresa el nombre del estudiante: ";
    getline(cin, nombreEstudiante);

    cout << "Ingresa el grado del estudiante: ";
    cin >> gradoEstudiante;

    Persona persona(nombrePersona);
    Profesor profesor(nombreProfesor, materiaProfesor);
    Estudiante estudiante(nombreEstudiante, gradoEstudiante);

    persona.presentarse();
    profesor.presentarse();
    estudiante.presentarse();

    if (estudiante.puedeInscribirseEnProgramacion()) {
        cout << "El estudiante puede inscribirse en el curso de programación." << endl;
    } else {
        cout << "El estudiante no puede inscribirse en el curso de programación." << endl;
    }

    return 0;
}
