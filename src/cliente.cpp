/**
 * @file cliente.h
 *
 * @author Sebastian Ponce
 *
 */

#include "cliente.h"
#include <iostream>

Cliente::Cliente(){
    nombre = "";
    dinero = 0;
    transacciones = {};
}

Cliente::Cliente(string nom, double din){
    nombre = nom;
    dinero = din;
    transacciones = {};
}

void Cliente::transferencia(Transaccion transaccion){
    if (transaccion.getCantidad() > dinero){
        std::cout << "No se cuenta con suficiente dinero en la cuenta para realizar la transferencia" << std::endl;
    }
    else{
        dinero = dinero - transaccion.getCantidad();
        transacciones.push_back(transaccion);
        std::cout << "Se realizo la transacción con valor de " << transaccion.getCantidad() << " a nuestra tienda. Gracias!" << std::endl;
    }
}

void Cliente::remover(){
    Transaccion temp = transacciones.back();
    transacciones.pop_back();
    std::cout << "Se removio la transaccion con ID" <<temp.getID() << endl; 
}

vector<Transaccion> Cliente::getTransacciones(){
    return transacciones;
}

double Cliente::getDinero(){
    return dinero;
}

void Cliente::setDinero(double nuevo){
    dinero = nuevo;
}
