#include "menu.h"
#include "Grafo.h"
#include <iostream>
#include <conio.h>
using namespace std;
int main(void){
    Grafo grafo1;
    grafo1.p=NULL;
    int op;     // opcion del menu
    system("color 8B");
    do{
        menu();
        cin>>op;
        switch(op){
            case 1: grafo1.insertar_vertice();break;
            case 2: grafo1.insertar_arista();break;
            case 3: grafo1.eliminar_vertice();break;
            case 4: grafo1.eliminar_arista();break;
            case 5: grafo1.mostrar_grafo();break;
            case 6: grafo1.mostrar_aristas();break;
            case 7: grafo1.adyacencia();break;
            case 8: grafo1.grado();break;
            case 9: cout<<"GRACIAS POR USAR EL PROGRAMA";break;
            default: cout<<"OPCION NO VALIDA!";break;
        }
        cout<<endl<<endl;
        getch();system("cls");
    }while(op!=9);
    getch();
    return 0;
}
