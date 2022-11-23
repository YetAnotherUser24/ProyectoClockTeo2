#include "Reloj.h"
#include "Tiempo.h"

int main()
{

    auto RelojBv = new Reloj;

    RelojBv->activar_alarma(18, 10, 10);
    while (!RelojBv->get_status())
    {
        RelojBv->activar_alarma();
    }
    RelojBv->apagar_alarma();
    RelojBv->mostrar_alarma();
    return 0;
}