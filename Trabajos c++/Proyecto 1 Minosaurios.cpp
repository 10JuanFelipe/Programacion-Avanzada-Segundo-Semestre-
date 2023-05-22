/*
AUTORES: Juan Andrés Torres
         Juan Felipe  Gonzalez
         Juliana Rubio


Objetivos:Desarrollar un programa que cumpla con las siguientes especificaciones para la empresa Minosaurios Tec:

-Registrar empleados 
-Despedir empleados y generar su carta de renuncia
-Modificar el número de télefono de un empleado

Para lograr esto, el equipo hizo uso de los conocimientos adquiridos durante las clases de programación avanzada


Valores agragados: Nuestro equpo quiso resaltar y agregar funciones extras en la aplicación presentada, como:
-Persistencia con la información registrada por el usuario en el programa (si el programa se cierra, la información queda guardada).
-Una interfaz amigable. 
- Optimizar recursos (tiempo, memoria RAM, entre otros) a través de vectores,.
  */







#include <iostream>
#include <fstream>
#include <vector>
#include<string.h>

using namespace std;

// Se crea una estructura de tipo empleado
struct empleado{
//Se declaran las variables que se requieren manipular en la consola
  int codigo;
  char nombre[50];
  char apellido[50];
  int celular;

};

//Declaración de funciones
void crear_archivos();
int menu();
empleado pedir_datos();
void mostrar_empleados(vector <empleado> &empleados, string registrados_despedidos);//muestra empleados registrados o despedidos en orden alfabético
void registrar_empleados(empleado datos_trabajador, vector <empleado> &empleados);//registra a un nuevo empleado
void cambiar_celular_empleado(int codigo_cel, vector <empleado> &empleados);//cambia el celular de un empleado
void despedir_empleado(int codigo, vector <empleado> &empleados, vector <empleado> &empleados_despedidos);//borra a un empleado del archivo de empleados, lo añade al de empleados despedidos y le hace una carta de despido
void leer_empleados(string nombre_archivo, vector<empleado> &empleado_leido);//lee a los empleados del archivo deseado y los guarda en un vector
void dinosaurio();


int main() {

  dinosaurio();
//Se declaran dos vectores. uno de empleados registrados y otro de empleados despedidos
  vector <empleado> empleados_registrados;
  vector <empleado> empleados_despedidos;

  crear_archivos();//Función para crear los archivos necesarios en el caso de que no hayan sido creados antes
  
//Se hace uso de la funcion leer_empleados para leer los archivos de empleados y de empleados despedidos.
//Los empleados leidos de cada archivo quedan guardados cada uno en su respectivo vector, de esta forma, no se tiene que estar leyendo constantemente el archivo mientras se tenga el programa abierto.
  leer_empleados("Empleados.bin", empleados_registrados);
  leer_empleados("Empleados_despedidos.bin", empleados_despedidos);
  
  int op;

  do{//ciclo del menú
    
   //se abre el menu con su respectiva funcion   
  op = menu();
    
  switch (op){
    
    case 1:
      //Se le pregunta al usuario el numero de empleados a registrar
      int num;
      empleado empleado_nuevo;
      
      cout << "Cuantos empleados nuevos desea ingresar?\n--> ";
      cin >> num;
     //Se recorre en un for con el limite del numero de empleados a registrar 
      for(int i = 0; i < num; i++){
        cout << "----------Empleado "<<i+1<<"----------"<<endl;
        //Se piden los datos del nuevo empleado con su respectiva funcion
        empleado_nuevo = pedir_datos();
        //Se registran los empleados en un archivo de tipo binario con el uso de la funcion "registrar_empleados"
        //Se envían como parametros los datos recién pedidos del empleado y el vector de empleados leidos del archivo.
        registrar_empleados(empleado_nuevo, empleados_registrados);
      }
      
      break;
    case 2:
      //Se muestrn los empleados que han sido registrados con la funcion "mostrar_empleados"
      //Los parametros enviados son el vector de empleados leídos del archivo y un string a usar cuando muestre los datos.
        mostrar_empleados(empleados_registrados, "registrados");
      
      break;
    case 3:
      //Se pide el codigo del empleado al que se le va a cambiar el celular por medio de la funcion "cambiar_celular_empleado"
        int codigo_cel;
      
        cout << "\nCodigo del empleado al que desea cambiarle el celular: ";
        cin >> codigo_cel;

      //La función recibe como parametros el código ingresado y el vector de empleados leídos del archivo.
        cambiar_celular_empleado(codigo_cel, empleados_registrados);
      
     break;
    case 4:
      //Se pide el codigo del empleado que se desea despedir. Se despide por medio de la funcion "despedir_empleado"
        int codigo;
        cout << "\nCodigo del empleado que desea despedir: ";
        cin >> codigo;
      //La función recibe como parametros el código ingresado, el vector de empleados y el vector de empleados despedidos leídos del archivo.
        despedir_empleado(codigo, empleados_registrados, empleados_despedidos);
      
      break;
    case 5:
      //Se muestran los empleados despedidos por medio de la funcion mostrar empleados, pero en este caso se envían como parametros el vector de empleados despedidos leído del archivo y un string que se usará para mostrar los datos.
        mostrar_empleados(empleados_despedidos, "despedidos");
        
      break;
    case 0:
      //Sale del programa
      break;

    default:
    cout<<"Opción invalida\n";
    }
    }while(op != 0);//Mientras no se escoja la opción de salir del programa
  
  return 0;
  }

//Función para crear archivos
void crear_archivos(){
//Se crean unos archivo en modo de lectura ofstream, para solo salida de datos "empleados.bin" y "Empleados_despedidos.bin". Se confirma que es de tipo binario, y se agrega el "app" para que no se pierdan datos cada vez que se abre el archivo (solo escribiendo en la parte del final).
  ofstream empleados("Empleados.bin", ios::binary | ios::app);
  ofstream empleados_despedidos("Empleados_despedidos.bin", ios::binary | ios::app);
//Se cierran estos archivos
  empleados.close();
  empleados_despedidos.close();
}


//Función menú
int menu () {
  int op;
  //Se le comunica al usuario las diferentes opciones que le proporciona el programa (de 0 a 5)
  cout<< "\n                 MENÚ                       \n \n";

  cout<<"1 ---> Registrar empleados\n";
  cout<<"2 ---> Mostrar los empleados registrados\n";
  cout<<"3 ---> Cambiar el número de celular de un empleado\n";
  cout<<"4 ---> Despedir a un empleado\n";
  cout<<"5 ---> Mostrar empleados que han sido despedidos\n";
  cout<<"0 ---> Salir\n\n";
  cout<<"---> ";
  cin>>op;
  
  return op; //retorna la opción elegida
}
//Funcion para pedir los datos de los empleados a inscribir
empleado pedir_datos(){

  empleado empleados;
     //Se pregunta en la consola cada una de las variables que hacen parte de la estructura empleado, y se ingresan en la variable de tipo empleado : "empleados"

    cout << "Codigo: ";
    cin >> empleados.codigo;
    cout << "Nombre: ";
    cin >> empleados.nombre;
    cout << "Apellido: ";
    cin >> empleados.apellido;
    cout << "Celular: ";
    cin >> empleados.celular;
    cout<<endl;
     //Para evitar incovenientes a la hora de organizar los datos de forma alfabetica, se vuelven todas las letras del nombre y del apellido del empleado ingresado en mayusculas por medio de la funcion touppper.
    for (int i = 0; i < 50; i++) {
    empleados.nombre[i] = toupper(empleados.nombre[i]);
    empleados.apellido[i] = toupper(empleados.apellido[i]);
  }

    return empleados;//retorna la variable tipo empleado
}
    //Funcion para mostrar los empleados ya registrados
void mostrar_empleados(vector <empleado> &empleados, string registrados_despedidos){

  
//Los empleados que han sido guardados en el vector empleado, son mostrados en la consola

  empleado aux;//aux para ordenamiento por burbuja
  if(empleados.size() > 0){//Si hay algún valor en el vector parametro
    
     for(int i = 0; i < empleados.size(); i++){
      for(int j = i + 1; j < empleados.size(); j++) {//Ordenamiento por burbuja para mostrar los datos en orden alfabetico
        if(strcmp(empleados[j].nombre, empleados[i].nombre) < 0){
          aux = empleados[i];
          empleados[i] = empleados[j];
          empleados[j] = aux;
        }
      }
     }
        cout <<endl<< "Empleados "<<registrados_despedidos<<":"<< endl;
       //Con un for de tamaño empleados.size se muestran todos los datos de los empleados que han sido registrados, estos datos se encuentran en el vector enviado como parametro a la función.
        for(int i = 0; i < empleados.size(); i++){
            cout << "-----------------------------" << endl;
            cout << "Código: " << empleados[i].codigo << endl;
            cout << "Nombre: " << empleados[i].nombre << endl;
            cout << "Apellidos: " << empleados[i].apellido << endl;
            cout << "Celular: " << empleados[i].celular << endl;
        }
       cout << "-----------------------------" << endl;
    }
    else{
      //Si no hay nada en el vector se muestra en la consola que no hay empleados registrados o despedidos (dependiendo del parametro) aún.
        cout <<endl<<"No hay empleados "<< registrados_despedidos << "." << endl;
    }
  
}
//Función para registrar empleados
void registrar_empleados(empleado datos_trabajador, vector <empleado> &empleados){

  //Se hace uso de un booleano que se volverá "true" si el empleado ingresado ya se encuentra registrado en el archivo
    bool repetido = false;

    int i;
    //Por medio de un for se recorren los empleados
    for(i = 0; i < empleados.size(); i++){
      //Se revisa si hay usuarios repetidos comparando las posiciones del vector empleados (que guarda los trabajadores registrados) con los datos almacenados en la variable datos_trabajador (el nuevo trabajador que se quiere ingresar).
      if(empleados[i].codigo == datos_trabajador.codigo){//Si hay un código igualen el archivo
        repetido = true;
        break;
      }
      else if(empleados[i].celular == datos_trabajador.celular){//Si hay un celular igual en el archivo
        repetido = true;
        break;
      }
      else if(strcmp(empleados[i].nombre, datos_trabajador.nombre) == 0 && strcmp(empleados[i].apellido, datos_trabajador.apellido) == 0){//Si hay un nombre y apellido iguales en el archivo
        repetido = true;
        break;
    }
    }
   //Si el booleano de repetidos es "true" se le muestra al usuario en la consola qué empleado es el que repite datos con el empleado ingresado
 if(repetido == true){
            cout << "----REGISTRO INCOMPLETO----"<<endl<<endl;
            cout << "Se encontro el siguiente empleado con los mismos datos: "<<endl;
            cout << "-----------------------------" << endl;
            cout << "Código: " << empleados[i].codigo << endl;
            cout << "Nombre: " << empleados[i].nombre << endl;
            cout << "Apellidos: " << empleados[i].apellido << endl;
            cout << "Celular: " << empleados[i].celular << endl;
            cout << "-----------------------------"<<endl;
      }
  else{
   //Si los datos no se encuentran repetidos se guarda el empleado ingresado en el archivo: "Empleados.bin".
    ofstream fichero_empleados;
    fichero_empleados.open("Empleados.bin", ios::binary | ios::app);
      
    if(fichero_empleados.is_open()){
      //Si se abrio de manera exitosa el fichero se van a escribir los datos del empleado, tanto en el vector de empleados_registrados como en el fichero.
      //el size_of especifica el numero de bits que se van a escribir en el archivo
      fichero_empleados.write((char*)&datos_trabajador,sizeof(empleado));
      empleados.push_back(datos_trabajador);//Se agregando los datos de: "datos_trabajador" al final del vector empleados (parametro).
  }
    else{
     cout <<"\nError abriendo el archivo\n";
  }
    //Se cierra el archivo
    fichero_empleados.close();
}
 }


void cambiar_celular_empleado(int codigo_cel, vector <empleado> &empleados){

  //llama a estructura empleados
  empleado empleados_leidos;

//Bool que será "true" cuando se encuentre el empleado del código ingresado
    bool encontrado = false;
    for(int i = 0; i < empleados.size(); i++){
      
      if(empleados[i].codigo == codigo_cel){ //compara el código de cada elemento del vector empleados con el código ingresado por el usuario
        cout << "--------------------------------------------" << endl;
        cout << "Numero de celular actual: "<< empleados[i].celular<<endl;
        cout << "--------------------------------------------" << endl;
        cout << "Nuevo numero: ";
        cin >> empleados[i].celular;
        cout << "--------------------------------------------" << endl;
        encontrado = true;
        //Cuando encuentra al empleado, cambia el número de celular de ese elemento del vector
        break;
      } 
    } 
  //Si no se encuentra el codigo del empleado ingresado, entonces:
    if(encontrado == false){
      cout <<endl<<"*Empleado no encontrado*"<<endl;
    }
    else{//Si encuentra al empleado, se escribirá de nuevo el archivo con los cambios 
      ofstream fichero_empleados;
      fichero_empleados.open("Empleados.bin", ios::binary);//no se utiliza app ya que el archivo se re-escribirá desde cero.
      
      if(fichero_empleados.is_open()){
    
          for(int i = 0; i < empleados.size(); i++){
            //Se ingresan todos los elementos del vector empleados
             fichero_empleados.write((char*)&empleados[i],sizeof(empleado));
      }
        cout << "**Cambio exitoso**" << endl;
      }
      else{
        cout <<"\nError abriendo el archivo\n";
      }
    
      fichero_empleados.close();
}
}


void despedir_empleado(int codigo, vector <empleado> &empleados, vector <empleado> &empleados_despedidos){

//Se pasa como parámetro el código del empleado, el vector de empleados y de los empleados despedidos
  empleado empleados_leidos;



    bool empleado_encontrado = false;//será true cuando se encuentre al empleado del código ingresado
    
    for(int i = 0; i < empleados.size(); i++){
      if(empleados[i].codigo == codigo){//Si el código del empleado es igual al ingresado por el usuario
          empleados_leidos = empleados[i];//guarda el empleado ingresado en la variable empleados_leídos
          empleados.erase(empleados.begin() + i);//Borra ese empleado del vector empleados_registrados (que es el que se pasa como parametro)
          empleados_despedidos.push_back(empleados[i]); //Guarda al empleado despedido en el vector empleados_despedidos
          empleado_encontrado = true; //Se declara que SÍ se encontró el empleado
        break;
      }
    }
    if(empleado_encontrado == true){

      //En caso de haber sido encontrado, entonces se escribe de nuevo el archico de empleados actualizado
      //funciona de la mísma forma que la función de cambiar celular.
  ofstream fichero_empleados;
  fichero_empleados.open("Empleados.bin", ios::binary);
  
  if(fichero_empleados.is_open()){

      for(int i = 0; i < empleados.size(); i++){
         fichero_empleados.write((char*)&empleados[i],sizeof(empleado));//Reescribe empleados sin incluir el despedido
  }
    cout << endl<<"**Empleado despedido exitosamente**"<<endl<<endl;
  }
  else{
    cout <<"\nError abriendo el archivo\n";
  }
      
//Se agrega el empleado despedido al archivo Empleados_despedidos.bin
  ofstream fichero_empleados_despedidos;
  fichero_empleados_despedidos.open("Empleados_despedidos.bin", ios::binary | ios::app);
  
  if(fichero_empleados_despedidos.is_open()){
     fichero_empleados_despedidos.write((char*)&empleados_leidos,sizeof(empleado));
    
  }
  else{
    cout <<"\nError abriendo el archivo\n";
  }
    //A continuación, se hará una carta de despido de tipo texto para el empleado 
  string carta = "Carta_Despido_";
  string nombre = empleados_leidos.nombre;// Así la carta tendrá en nombre del empleado
  string ext = ".txt";
  string cartadespido = carta + nombre + ext;//Concatenar el título de la carta
  ofstream carta_despido;
  carta_despido.open(cartadespido);//abre un archivo de nombre cartadespido (que es una variable tipo string)

  if(carta_despido.is_open()){

  carta_despido << "Querido/a "<<nombre<<",\n"<<endl;
  carta_despido << "Lamentablemente, nos vemos en la necesidad de informarte que, a partir de la fecha, tus servicios en Minosaurios Tec. han sido terminados.\n\nTe agradecemos por el tiempo que has dedicado a la empresa y esperamos que tengas éxito en tus futuros emprendimientos. Te recordamos que tus beneficios y prestaciones serán entregados de acuerdo con las políticas de la empresa.\n\nPor favor, ponte en contacto con nuestro departamento de Recursos Humanos para coordinar la entrega de tus documentos y pertenencias de la empresa.\n\nAtentamente,\n\nJohn Corredor\nGerente\n\nMinosaurios Tec."<<endl;
  
    }
  else{
    cout << "\n*Error abriendo archivo de carta de despido*\n";
  }
  
//Se cierran todos los ficheros
  fichero_empleados.close();
  fichero_empleados_despedidos.close();
  carta_despido.close();
      
   }
      //En caso de que no se haya encontrado al empleado
    else{
      cout << endl<<"**Empleado no encontrado -- Digite el codigo correctamente**"<<endl<<endl;
    }
}


void leer_empleados(string nombre_archivo, vector<empleado> &empleados){
//Funcion que recibe como parametro el nombre del archivo a leer y el vector en el que se va a guardar el archivo
  
  empleados.clear(); //Se limpia el vector

  empleado empleados_leidos; //se crea variable tipo empleado

  ifstream fichero_empleados_lectura; //Se abre el archivo para lectura
  fichero_empleados_lectura.open(nombre_archivo, ios::binary);

  if(fichero_empleados_lectura.is_open()){

    fichero_empleados_lectura.seekg(0, ios::beg);//empieza a leer al inicio del archivo
    while(fichero_empleados_lectura.read((char*)&empleados_leidos,sizeof(empleado))){
      if(fichero_empleados_lectura.good()){ //Si la lectura es exitosa, entonces se añade la información leída al vector empleados (parametro)
      empleados.push_back(empleados_leidos);
        }
    }
    }

  else{
    cout <<"\nError abriendo el archivo\n";
  }

  fichero_empleados_lectura.close();//se cierra el archivo
}

void dinosaurio(){
cout << "                     ---MINOSAURIOS TEC---\n\n";
cout << "                       . - ~ ~ ~ - .\n";
cout << "       ..     _      .-~               ~-.\n";
cout << "      //|     \\ `..~                      `.\n";
cout << "     || |      }  }              /       \\  \\ \n";
cout << " (\\   \\\\ \\~^..'                 |         }  \\ \n";
cout << "  \\`.-~  o      /       }       |        /    \\ \n";
cout << "  (__          |       /        |       /      `.\n";
cout << "   `- - ~ ~ -._|      /_ - ~ ~ ^|      /- _      `.\n";
cout << "               |     /          |     /     ~-.     ~-\n";
cout << "               |_____|          |_____|         ~ - . _ _~_-_\n";

  getchar();
}
