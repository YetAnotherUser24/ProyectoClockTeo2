#include <iostream>
#include <ctime>
#include "time.h"

using namespace std;

int main()
{
    // consigue la fecha actual
    time_t ahora = time(NULL);

    tm *a;
    a->tm_hour = 0;
    tm *time = localtime(&ahora);
    cout << time->tm_hour;
    cout << endl;
    cout << time->tm_isdst;
    cout << endl;
    cout << time->tm_mday;
    cout << endl;
    cout << time->tm_min;
    cout << endl;
    cout << time->tm_mon + 1;
    cout << endl;
    cout << time->tm_sec;
    cout << endl;
    cout << time->tm_wday;
    cout << endl;
    cout << time->tm_yday;
    cout << endl;
    cout << time->tm_year + 1990;
    int p = 1;

    return 0;
}
