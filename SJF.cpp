#include <iostream>
using namespace std;
struct PCB
{
    int pid, burst, wait, turnaround;
};
void pline(int);
void pline(int x)
{
    int i;
    for (i = 0; i < x; i++)
    {
        cout << "-";
    }
    cout << endl;
}
int main()
{
    struct PCB p[10], temp;
    int i, j, n, sum = 0, w_total = 0, t_total = 0;
    float w_avg = 0, t_avg = 0.0;
    cout << endl
         << "Bienvenido al programa de Shortest Job First" << endl;
    cout << "Ingrese el total de procesos : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Ingrese la duracion del proceso " << i + 1 << ": ";
        cin >> p[i].burst;
        p[i].pid = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (p[j].burst > p[j + 1].burst)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        p[i].wait = sum;
        sum += p[i].burst;
        p[i].turnaround = sum;
    }
    pline(35);
    cout << "PID\tBurst\tWait\tTurnaround";
    pline(35);
    for (i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].burst << "\t" << p[i].wait << "\t" << p[i].turnaround << endl;
        w_total += p[i].wait;
        t_total += p[i].turnaround;
    }
    w_avg = w_total / (float)n;
    t_avg = t_total / (float)n;
    cout << endl
         << "Tiempo total de espera: " << w_total << endl;
    cout << "Tiempo promedio de espera: " << w_avg << endl;
    cout << "Tiempo total de respuesta: " << t_total << endl;
    cout << "Tiempo promedio de respuesta: " << t_avg << endl;
    return 0;
}
