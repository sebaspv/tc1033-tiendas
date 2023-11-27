/**
 * @file transaccion.h
 *
 * @author Sebastian Ponce
 * @author Iñaki Ahedo Madrid
 * @author Raymundo Díaz Tijera
 *
 */

#include <iostream>
#include <vector>
#include "transaccion.cpp"
#include "cliente.cpp"
#include <string>
#include <iomanip>

using namespace std;
int main(){
    cout << fixed;
    cout << setprecision(2); // hace que los flotantes se redondeen a 2 decimales
    cout << "Bienvenido al sistema de compra en linea de nuestra empresa" << endl;
    cout << "Cual es tu nombre? ";
    string nombre; cin >> nombre;
    cout << "Cual es el balance de tu cuenta bancaria (dinero)? ";
    int dinero; 
    cin >> dinero;
    Cliente cliente(nombre, (double)dinero);
    if (dinero < 0){
        cout << "No hay dinero negativo! Checa tus detalles bancarios :)" << endl;
        return 0;
    }
    cout << "Si deseas añadir una transacción, presiona 0.\nSi deseas observar las transferencias hasta ahora, presiona 1.\nSi deseas remover la última transferencia, presiona 2.\nSi deseas salir del programa, escribe cualquier otro número.\n";
    while (true){
        int opcion;
        cout << "Cuentas con " << cliente.getDinero() << endl;
        cout << "Opción:\n";
        cin >> opcion;
        if (opcion == 0){
            string tipo;
            cout << "Dame tu concepto de transferencia: ";
            cin >> tipo;
            cout << "Dame la cantidad de dinero a transferir: ";
            double cantidad;
            cin >> cantidad;
            cliente.transferencia(Transaccion(tipo, cantidad));
        }
        else if (opcion == 2){
            double refund = cliente.getTransacciones().back().getCantidad();
            cliente.setDinero(cliente.getDinero() + refund);
            cliente.remover();
        }
        else if (opcion == 1){
            for (auto a: cliente.getTransacciones()){
                a.getDetalles();
            }
        }
        else{
            cout << "Gracias por usar nuestro software :)!" << endl;
            break;
        }
        
    }
    double cantidad = 123.0;
    Transaccion ola("Videojuego", cantidad);
    ola.getDetalles();
    return 0;
}