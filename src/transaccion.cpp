/**
 * @file transaccion.cpp
 *
 * @author Sebastian Ponce
 *
 */

#include "transaccion.h"
#include <chrono>
#include <random>
#include <iostream>
#include <cstdlib>

Transaccion::Transaccion(){
    std::random_device rd; // te da IDs
    tipo = "";
    id = rand() % 1000;
    time_t final = chrono::system_clock::to_time_t(chrono::system_clock::now()); // se ve horrible, pero te da la fecha actual
    fecha = ctime(&final);
    cantidad = 0;
}

Transaccion::Transaccion(string tip, double cant){
    std::random_device rd;
    id = rand() % 1000;
    tipo = tip;
    cantidad = cant;
    time_t final = chrono::system_clock::to_time_t(chrono::system_clock::now());
    fecha = ctime(&final);
}

void Transaccion::getDetalles(){
    std::cout << "Transacción ID " << id << std::endl;
    std::cout << "Con valor de " << cantidad << " " << "en la fecha " << fecha << endl;
}

double Transaccion::getCantidad(){
    return cantidad;
}

int Transaccion::getID(){
    return id;
}
