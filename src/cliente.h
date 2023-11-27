/**
 * @file cliente.h
 *
 * @author Sebastian Ponce
 * @author Iñaki Ahedo Madrid
 * @author Raymundo Díaz Tijera
 *
 */

#pragma once
#include <string>
#include <vector>
#include "transaccion.h"

using namespace std;

class Cliente{
    private:
        string nombre;
        double dinero; // se que es peligroso manejar dinero como doubles pero es lo que hay
        vector<Transaccion> transacciones;
    public:
        Cliente();
        Cliente(string, double);
        void transferencia(Transaccion);
        void remover();
        void setDinero(double);
        vector<Transaccion> getTransacciones();
        double getDinero();
};