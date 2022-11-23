#ifndef __TIEMPO_H__
#define __TIEMPO_H__

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class Tiempo
{
public:
    vector<string> meses = {"Diciembre", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre"};
    vector<string> semana = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

    int hora;
    int minuto;
    int segundo;
    int dia;
    string mes;
    string dia_semana;

    // CONSTRUCTOR VACIO

    Tiempo()
    {
        actualidad();
    }

    // CONSTRUCTOR COPIA
    Tiempo(Tiempo *obj)
    {
        this->meses = obj->meses;
        this->semana = obj->semana;

        this->hora = obj->hora;
        this->minuto = obj->minuto;
        this->segundo = obj->dia;
        this->dia = obj->dia;
        this->mes = obj->mes;
        this->dia_semana = obj->dia_semana;
    }
    // DESTRUCTOR
    ~Tiempo() {}

    // FUNCION QUE DA LA HORA ACTUAL
    void actualidad()
    {
        time_t now = time(NULL);
        tm *tiempo = localtime(&now);
        hora = tiempo->tm_hour;
        minuto = tiempo->tm_min;
        segundo = tiempo->tm_sec;
        dia = tiempo->tm_mday;
        mes = meses[tiempo->tm_mon];
        dia_semana = semana[tiempo->tm_wday];
    }

    // SUMAR DIAS A LA FECHA ACTUAL
    Tiempo operator+(int i)
    {
        Tiempo aux(*this);

        time_t now = time(NULL);
        tm *tiempo = localtime(&now);

        if (mes == "Febrero")
        {
            aux.dia = 1 + (aux.dia + i) % 28;
            aux.dia_semana = aux.semana[(tiempo->tm_wday + i) % 7];

            if (dia + i > 28)
            {
                aux.mes = aux.meses[(tiempo->tm_mon + 1 + i / 29) % 12];
            }
        }
        else if (aux.mes == "Enero" || aux.mes == "Marzo" || aux.mes == "Mayo" || aux.mes == "Julio" || aux.mes == "Agosto" || aux.mes == "Octubre" || aux.mes == "Diciembre")
        {
            dia = 1 + (dia + i) % 31;
            dia_semana = aux.semana[(tiempo->tm_wday + i) % 7];

            if (dia + i > 31)
            {
                aux.mes = aux.meses[(tiempo->tm_mon + 1 + i / 32) % 12];
            }
        }
        else
        {
            dia = 1 + (dia + i) % 30;
            dia_semana = aux.semana[(tiempo->tm_wday + i) % 7];

            if (dia + i > 30)
            {
                aux.mes = aux.meses[(tiempo->tm_mon + 1 + i / 31) % 12];
            }
        }
        return aux;
    }
};
#endif // __TIEMPO_H__