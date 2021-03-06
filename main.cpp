// Practica 3
//Curso C++ FOD
// Realizado por Alejandro Monge Brenes
// Programa para el control del consumo energético

//El objetivo del programa es permitir al usuario registrar el inventario de dispositivos que hay en la casa. Una vez que se tiene el inventario, se debe introducir la cantidad de horas que estuvo encendido cada dispositivo para luego calcular el total de consumo que tuvo la casa durante el mes.
 

#include <iostream>
#include <string>
using namespace std;
 
struct tipoDatos
{
    string nombreFich;        // Nombre del fichero
    long tamaño;            // El tamaño en bytes
    long horas;              //cantidad de horas funcionando
};
 
int numeroFichas=0;  // Número de fichas que ya tenemos
int i;               // Para bucles
int opcion;          // La opcion del menu que elija el usuario
 
string textoTemporal; // Para pedir datos al usuario
int numeroTemporal;
 
int main()
{
    tipoDatos *fichas = new tipoDatos[1000];
 
    do
    {
        // Menu principal
        cout << endl;
        cout << "PROGRAMA DE REGISTRO ENERGÉTICO" << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir Dispositivo" << endl;
        cout << "2.- Mostrar todos los dispositivos" << endl;
        cout << "3.- Mostrar Dispositivos de ALTO CONSUMO" << endl;
        cout << "4.- Consumo total por dispositivo" << endl;
        cout << "5.- Salir" << endl;
 
        cin >> opcion;
 
        // Hacemos una cosa u otra según la opción escogida
        switch(opcion)
        {
            case 1: // Añadir un dato nuevo
                if (numeroFichas < 1000)   // Si queda hueco
                {
                    cout << "Digite el nombre del Dispositivo: ";
                    cin >> fichas[numeroFichas].nombreFich;
                    cout << "Digite el consumo en Watts (W): ";
                    cin >> fichas[numeroFichas].tamaño;
                    cout << "Digite cantidad de horas funcionando: ";
                    cin >> fichas[numeroFichas].horas;
                    numeroFichas++;  // Y tenemos una ficha más
                }
                else   // Si no hay hueco para más fichas, avisamos
                    cout << "Máximo de fichas alcanzado (1000)!" << endl;
                break;
 
            case 2: // Mostrar todos
                for (i=0; i<numeroFichas; i++)
                    cout << "Dispositivo: " << fichas[i].nombreFich
                        << "; Consumo: " << fichas[i].tamaño
                        << " Watts" 
                        << "; horas: " << fichas[i].horas << endl;
                break;
 
            case 3: // Mostrar según el tamaño
                cout << "¿A partir de cuál Consumo desea saber?  Digite la potencia máxima esperada "; 
                cin >> numeroTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].tamaño >= numeroTemporal)
                        cout << "Dispositivo: " << fichas[i].nombreFich
                            << "; Consumo: " << fichas[i].tamaño
                            << " Watts" << endl;
                break;
 
            case 4: // Ver todos los datos (pocos) de un fichero
                cout << "¿De cual Dispositivo quiere saber? Digite el nombre"<< endl;
                cin >> textoTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].nombreFich == textoTemporal)
                        cout <<  fichas[i].tamaño * fichas[i].horas << " Watts/hora"<< endl;
                break;
 
            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;
 
            default: // Otra opcion: no válida
                cout << "Opción desconocida!" << endl;
                break;
        }
    } while (opcion != 5);  // Si la opcion es 5, terminamos
 
    return 0;
}