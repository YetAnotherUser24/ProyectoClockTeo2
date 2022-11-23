#include "windows.h"
#include "Tiempo.h"
using namespace std;

class Reloj
{
private:
    int hora;
    int minuto;
    int segundo;
    bool alarma;
    Tiempo *RealTime = new Tiempo;

public:
    // Constructor Vacio
    Reloj()
    {
        this->hora = RealTime->hora;
        this->minuto = RealTime->minuto;
        this->segundo = RealTime->segundo;
        alarma = false;
    }

    // Destructor
    ~Reloj() {}

    // Activar alarma
    int activar_alarma(int _hora = -1, int _minuto = -1, int _segundo = -1)
    {

        RealTime->actualidad();
        if (!(_hora + _minuto + _segundo == -3))
        {
            this->hora = _hora;
            this->minuto = _minuto;
            this->segundo = _segundo;
        }

        long int segundosA = this->hora * 3600 + this->minuto * 60 + this->segundo;
        long int segundosR = RealTime->hora * 3600 + RealTime->minuto * 60 + RealTime->segundo;

        if (segundosR >= segundosA)
        {
            system("doin-the-kirby.wav");
            alarma = true;
        }
        return 0;
    }

    void apagar_alarma()
    {
        alarma = false;
    }

    void mostrar_alarma()
    {
        cout << "\nALARMA PROGRAMADA PARA LAS:";
        cout << "\n--------------------------\n";
        cout << this->hora << " Horas\n";
        cout << this->minuto << " Minutos\n";
        cout << this->segundo << " Segundos\n";
        cout << "El dia: " << (*RealTime + 1).dia_semana << (*RealTime + 1).dia << " de " << (*RealTime + 1).mes;
    }

    bool get_status()
    {
        return alarma;
    }
};
