// Juan Felipe González Acuña **** 15/02/23
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Estructura para capturar los resultados Max y N
struct resultados{
  int max_valor;
  int size_array;
  int *int_array;
};

int main(){
//Semilla de numero randoms
     srand(time(NULL));
  resultados valores_internos;
  valores_internos.max_valor =0;
  valores_internos.size_array = 0;
//Se pregunta cuantos valores del conjunto
  cout << "cuantos valores necesita en el conjunto" << endl;
  cin >> valores_internos.size_array;
   int miarray[valores_internos.size_array];
   for(int i=0; i< valores_internos.size_array; i++){
     int num = (rand()%20);
     miarray[i] = num;
     }
  valores_internos.int_array = miarray;

// se empieza el menu
int menu;
  cout << "Escriba 1 si quiere ver solo un index del conjunto" << endl;
  cout << "Escriba 2 si quiere ver solo un histograma del conjunto" << endl;
  cout << "Escriba 3 si quiere ver todo a la vez" << endl;
  cout << "Escriba 4 para salir del programa" << endl;
  cin >> menu;
switch(menu){
    // se muestra unicamente el index y los valores randomizados
case 1 :
    cout << "index" << "  " << "valores" << endl;
     for (int i = 0; i < valores_internos.size_array; i++){
     cout << i << "      " <<  *(valores_internos.int_array + i) <<  endl;
  }
break;
    // se muestra unicamente el Histograma
case 2:
    cout << "Histograma: " << endl;
    for (int i = 0; i < valores_internos.size_array; i++){
     for (int j=0; j < *(valores_internos.int_array + i); j++){
                cout << "*";
     }
     cout << endl;
 }
break;
    // se muestra el index, los valores, el histograma y por medio de un if se muestra el maximo
case 3:
    int maximo;
  cout << "index" << "         " << "valores" << "              " << "histograma" << endl;
     for (int i = 0; i < valores_internos.size_array; i++){

     cout << i << "\t\t" <<  *(valores_internos.int_array + i) << "\t\t" ;

     for (int j=0; j < *(valores_internos.int_array + i); j++){
                cout << "*";
    // para mostrar el maximo
    
     if (*(valores_internos.int_array + i) > *(valores_internos.int_array) ){
         maximo = *(valores_internos.int_array + i);
     }
     }

     cout << endl;
 }
 cout << "El valor maximo es : " << maximo << endl;
     cout << endl;
break;
    // para salir del programa
case 4:
    cout << "adios ;)";
    return 0;
break;
}
  return main();
}
