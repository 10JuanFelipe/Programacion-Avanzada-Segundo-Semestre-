

#include <iostream>

using namespace std;

/***********************************************************************************************

30/01/2023

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
	cout << "se ha registrado con exito" << " " << 	Juancho[x].nombre << endl;
	cout << "Su cedula : " << Juancho[x].CC << endl;
	cout << "Su correo : " << Juancho[x].Correo << endl;
	cout << "Su edad: " << Juancho[x].edad << endl;
	cout << "Su direccion : " << Juancho[x].Direccion << endl;
	cout << "Su peso : " << Juancho[x].Peso << endl;
	cout << "Numero de hijos : " << Juancho[x].hijos << endl;
	
}
 cout << "ACABO DE INSCRIBIR ";
}


Gimnasiotaller1.cpp
Mostrando Gimnasiotaller1.cpp 
