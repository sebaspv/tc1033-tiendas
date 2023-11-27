/**
 * @file transaccion.h
 *
 * @author Sebastian Ponce
 * @author Iñaki Ahedo Madrid
 * @author Raymundo Díaz Tijera
 *
 */

#pragma once
#include <string>

using namespace std;
class Transaccion{
    private:
        int id;
        string tipo;
        string fecha;
        double cantidad;
    public:
        Transaccion(string, double);
        Transaccion();
        void getDetalles();
        double getCantidad();
        int getID();
};