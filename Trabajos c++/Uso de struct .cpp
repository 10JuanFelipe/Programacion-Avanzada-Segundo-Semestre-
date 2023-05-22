// Primera parte 

// Juan Felipe González Acuña
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main(){

    int miarray [10];
    int *pointer = miarray;

    srand(time(NULL));
    int num;
     cout << "Valores" << "\t\t" << "Posicion en memoria" << endl;
    for (int i = 0 ; i < 10; i ++){
        num = (rand()%25);
        miarray[i] = num;
        cout << *(pointer + i) << "\t\t" << &miarray[i] << endl;

    }
    return 0;
}
 // segunda parte
 
#include <iostream>
#include <fstream>
using namespace std;

/***********************************************************************************************

Juan Felipe Gonzalez Acuña

se tiene un gym que requiere un sistema informatico para captuar los datos de sus clientes

se tiene un struct para le tipo de dato que capture a los demas

se presenta que por cada  dato se pregunta y se guarda

***********************************************************************************************/



struct cliente{
	string nombre;
	int edad;
	int CC;
	float Peso;
	string Genero;
	string Correo;
	int Movil;
	int hijos;
	string  Direccion;
};


int main(){

    fstream mifile;
    mifile.open("registro_taller_1_clientes.txt", ios::app3
                );

    if (mifile.is_open()){



	int cant;
	cout << "cuanta gente tiene que inscribir??";
	cin >> cant;
	cliente Juancho[cant];
	for (int x=0; x<cant; x++){

	cout << "Escriba su nombre"<< endl;
	cin >> Juancho[x].nombre;
	cout << "Su edad" << endl;
	cin >> Juancho[x].edad;
	cout << "Cedula De Ciudadania"<< endl;
	cin >> Juancho[x].CC;
	cout << "Su peso" << endl;
	cin >> Juancho[x].Peso;
	cout << "Escriba su genero"<< endl;
	cin >> Juancho[x].Genero;
	cout << "Escriba su correo" << endl;
	cin >> Juancho[x].Correo;
	cout << "Escriba su movil" << endl;
	cin >> Juancho[x].Movil;
	cout << "Escriba su numero de hijos" << endl;
	cin >> Juancho[x].hijos;
	cout << "Su direccion" << endl;
	cin >> Juancho[x].Direccion;
	mifile << "se ha registrado con exito" << " " << 	Juancho[x].nombre << endl;
	mifile << "Su cedula : " << Juancho[x].CC << endl;
	mifile << "Su correo : " << Juancho[x].Correo << endl;
	mifile << "Su edad: " << Juancho[x].edad << endl;
	mifile << "Su direccion : " << Juancho[x].Direccion << endl;
	mifile << "Su peso : " << Juancho[x].Peso << endl;
	mifile << "Numero de hijos : " << Juancho[x].hijos << endl;


 cout << "ACABO DE INSCRIBIR ";



	}
 return 0;

    }
}

 
 
