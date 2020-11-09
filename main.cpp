#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
    string nombre;
    string apellido;
    string email;
    string github;
    string fecha;
    string hora;
    bool repetir;
    bool a1;
    bool enClase;
    bool expo;
    int numExp;
    int nivel;
    int year;
    int mes;
    int tUsuarios;
    //ctime tiempoAct;

    ifstream fin("../alumnos.tsv");//Declaramos fin como variable de entrada
    ofstream fout("../salida.txt");//Declaramos fout como variable de salida
    ofstream fbin("../alumnos.bec",ios::out | ios::binary);//Variable binaria
    //fin>>fecha;//leemos un campo para saber si estamos en fin de archivo

    void expPar(){
        try{
            cout<<"Las personas con expediente par son: "<< endl;
            fout<<"Las personas con expediente par son: "<<endl;
            while (!fin.eof()){
                fin>>fecha>>hora>>email>>nombre>>apellido>>repetir>>numExp>>github>>nivel>>expo>>a1>>mes>>year>>enClase;
                if(numExp%2==0){
                    cout<<nombre<<" "<<apellido<<" "<<numExp<<endl;
                    fout<<nombre<<" "<<apellido<<" "<<numExp<<endl;
                    fbin.write(reinterpret_cast<const char *>(&nombre), sizeof(string));
                    fbin.write(reinterpret_cast<const char *>(&apellido), sizeof(string));
                    fbin.write(reinterpret_cast<const char *>(&numExp), sizeof(int));
                }
            }
        }
        catch(...) {//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
            fbin.close();
            fin.close();
            fout.close();
            cout << "FIN DE ARCHIVO" << endl;
        }
    }

void expImPar(){
    try{
        cout<<"Las personas con expediente impar son: "<< endl;
        fout<<"Las personas con expediente impar son: "<<endl;
        while (!fin.eof()){
            fin>>fecha>>hora>>email>>nombre>>apellido>>repetir>>numExp>>github>>nivel>>expo>>a1>>mes>>year>>enClase;
            if(numExp%2!=0){
                cout<<nombre<<" "<<apellido<<" "<<numExp<<endl;
                fout<<nombre<<" "<<apellido<<" "<<numExp<<endl;
                fbin.write(reinterpret_cast<const char *>(&nombre), sizeof(string));
                fbin.write(reinterpret_cast<const char *>(&apellido), sizeof(string));
                fbin.write(reinterpret_cast<const char *>(&numExp), sizeof(int));
            }
        }
    }
    catch(...) {//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
        fbin.close();
        fin.close();
        fout.close();
        cout << "FIN DE ARCHIVO" << endl;
    }
}

void masViejo(){//no funciona
        try{
            int anoActual;
            int mayor = anoActual - year;
            cout<<"Introduzca el año actual"<<endl;
            cin>>anoActual;
            while(!fin.eof()){
                fin>>fecha>>hora>>email>>nombre>>apellido>>repetir>>numExp>>github>>nivel>>expo>>a1>>mes>>year>>enClase;
                if(mayor < anoActual){
                    mayor = anoActual;
                    cout<<"El mayor o mayores es: "<< nombre<< " "<< apellido<<endl;
                }
            }
        }
        catch(...) {//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
            fbin.close();
            fin.close();
            fout.close();
            cout << "FIN DE ARCHIVO" << endl;
        }
    }

void clase(){//no muestra los nombres
        try{
            int clase;
            int hyflex;
            while(!fin.eof()){
                fin>>fecha>>hora>>email>>nombre>>apellido>>repetir>>numExp>>github>>nivel>>expo>>a1>>mes>>year>>enClase;
                if(enClase == 0){
                    clase++;
                }
                else{
                    hyflex++;
                }
            }
            cout<<"Alumnos que están en clase: "<< clase<<endl;
            fout<<"Alumnos que están en clase: "<< clase<<endl;
            cout<<"Alumnos que están en hyflex: "<< hyflex<<endl;
            fout<<"Alumnos que están en hyflex: "<< hyflex<<endl;
        }
        catch(...) {//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
            fbin.close();
            fin.close();
            fout.close();
            cout << "FIN DE ARCHIVO" << endl;
        }
    }

void pEntrega(){
        try{
            int entrega;
            int nAlumnos;
            while(!fin.eof()){
                fin>>fecha>>hora>>email>>nombre>>apellido>>repetir>>numExp>>github>>nivel>>expo>>a1>>mes>>year>>enClase;
                if(a1 == 1){
                    entrega++;
                }
                nAlumnos++;
            }
            cout<<"Ha entregado la actividad un "<< entrega*100/nAlumnos <<"% de la clase"<<endl;
            fout<<"Ha entregado la actividad un "<< entrega*100/nAlumnos <<"% de la clase"<<endl;
        }
        catch(...) {//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
            fbin.close();
            fin.close();
            fout.close();
            cout << "FIN DE ARCHIVO" << endl;
        }
    }


void cumpleMes(){
        try{
            int mesActual;
            cout<<"Introduzca el mes a comprobar"<<endl;
            cin>>mesActual;
            cout<<"Los alumnos que cumplen años este mes son: "<<endl;
            fout<<"Los alumnos que cumplen años este mes son: "<<endl;
            while(!fin.eof()) {
                fin>>fecha>>hora>>email>>nombre>>apellido>>repetir>>numExp>>github>>nivel>>expo>>a1>>mes>>year>>enClase;
                if (mes == mesActual) {
                    cout << nombre << " " << apellido << " " << numExp << endl;
                    fout << nombre << " " << apellido << " " << numExp << endl;
                    fbin.write(reinterpret_cast<const char *>(&nombre), sizeof(string));
                    fbin.write(reinterpret_cast<const char *>(&apellido), sizeof(string));
                    fbin.write(reinterpret_cast<const char *>(&numExp), sizeof(int));
                }
            }
        }
        catch(...) {//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
            fbin.close();
            fin.close();
            fout.close();
            cout << "FIN DE ARCHIVO" << endl;
        }
    }

int main(){
        int op;
        do{
           cout<<"\n[1] Mostrar el alumno más viejo (no funciona) \n[2] Los alumnos que cumplen años este mes \n[3] Alumnos con expediente par \n[4] Listado de alumnos con expediente impar \n[5] Porcentaje de alumnos que han entregado la actividad 1 \n[6] Número de asistentes presenciales y en hyflex \n";
           cin>>op;
           switch(op) {
               case 1:
                   masViejo();
                   break;
               case 2:
                   cumpleMes();
                   break;
               case 3:
                   expPar();
                   break;
               case 4:
                   expImPar();
                   break;
               case 5:
                   pEntrega();
                   break;
               case 6:
                   clase();
                   break;
           }

        }
        while(op!=0);
    }