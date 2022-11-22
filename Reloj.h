

#include <ctime>
using namespace std;

class Reloj
{
private:
    int hora;
    int minuto;
    int segundo;
    bool alarma;

public:
    Reloj();
    ~Reloj(){}

    void activar_alarma();

    void apagar_alarma();

    void mostrar_alarma();

};