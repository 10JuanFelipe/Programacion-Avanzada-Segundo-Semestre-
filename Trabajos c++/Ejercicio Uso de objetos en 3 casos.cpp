/*****************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

class Pitagoras {
    private:
    int cateto1, cateto2, hipotenusa;
    public:
    Pitagoras(int cateto1 , int cateto2){
       
        hipotenusa = sqrt(cateto1*cateto1 + cateto2*cateto2);
    }
    float resultado() {
        return hipotenusa;
    }
};

class Farenheit {
    private:
    int gradosc, gradosf;
    public:
    Farenheit(int gradosc){
        gradosf = (gradosc * 1.8) + 32;
    };
    float resultado1(){
    return gradosf;
    };
};

class Metros {
    private:
    float pies, metros;
    public:
    Metros(int pies){
        metros = pies/3.281 ;
    };
    float resultado2(){
    return metros;
    };
};
int main()
{

int banderita;
while (banderita != 4){
cout << " Que quiere hacer hoy ?? " << endl;
cout << " Digite 1 si quiere hacer Pitagoras" << endl;
cout <<  " Digite 2 si quiere pasar de grados celcius a farenheit" << endl;
cout << " Digite 3 si quiere pasar de pies a metros" << endl;
cout << " Digite 4 si quiere salir" << endl;
cin >> banderita;
switch(banderita) {
    case 1:{
       
    int cateto1, cateto2;
    cout << "Valor del primer cateto " << endl;
    cin >> cateto1;
    cout << "Valor del segundo cateto " << endl;
    cin >> cateto2;
    Pitagoras b(cateto1, cateto2);
    cout << "La hipotenusa vale : " << b.resultado() << endl;
    }
    break;
    case 2:{
       
    int gradosc;
    cout << "Digite valor de grados celcius" << endl;
    cin >> gradosc;
    Farenheit c(gradosc);
    cout << "Su valor en grados farenheit es : " << c.resultado1() << endl;
    }
    break;
    case 3:{
    int pies;
    cout << "Digite su valor en pies" << endl;
    cin >> pies;
    Metros d(pies);
    cout << "Su valor en metros es : " << d.resultado2() << endl;
    }
    break;
   
}
}
}
