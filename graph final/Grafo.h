#include "struct.h"
#include <iostream>
using namespace std;
class Grafo{
public: Tvertice p;
public:
	void insertar_vertice();
    void agrega_arista(Tvertice &aux, Tvertice &aux2, Tarista &nuevo);
    void insertar_arista();
    void vaciar_aristas(Tvertice &aux);
    void eliminar_vertice();
    void eliminar_arista();
    void mostrar_grafo();
    void mostrar_aristas();
    void adyacencia();
    void grado();
};
void Grafo::insertar_vertice(){
    Tvertice t,nuevo=new struct vertice;
    cout<<"INGRESE EL NOMBRE DEL VERTICE: ";
    cin>>nuevo->nombre;
    nuevo->sgte = NULL;
    nuevo->ady=NULL;
    if(p==NULL){
        p = nuevo;
        cout<<"\nPRIMER VERTICE INGRESADO!";
    }
    else{
        t = p;
        while(t->sgte!=NULL){
            t = t->sgte;
        }
        t->sgte = nuevo;
        cout<<"\nVERTICE INGRESADO!";
    }
}

void Grafo::agrega_arista(Tvertice &aux, Tvertice &aux2, Tarista &nuevo){
    Tarista q;
    if(aux->ady==NULL){
        aux->ady=nuevo;
        nuevo->destino=aux2;
        cout<<"\nPRIMERA ARISTA INGRESADA!";
    }else{
        q=aux->ady;
        while(q->sgte!=NULL){
            q=q->sgte;
        }
        nuevo->destino=aux2;
        q->sgte=nuevo;
        cout<<"\nARISTA INGRESADA!";
    }
}

void Grafo::insertar_arista(){
    char ini, fin;
    Tarista nuevo=new struct arista;
    Tvertice aux, aux2;
    if(p==NULL){
        cout<<"GRAFO VACIO!";
        return;
    }
    nuevo->sgte=NULL;
    cout<<"INGRESE VERTICE INICIAL: ";
    cin>>ini;
    cout<<"INGRESE VERTICE FINAL: ";
    cin>>fin;
    aux=p;
    aux2=p;
    while(aux2!=NULL){
        if(aux2->nombre==fin){
            break;
        }
        aux2=aux2->sgte;
    }
    while(aux!=NULL){
        if(aux->nombre==ini){
            agrega_arista(aux,aux2, nuevo);
            return;
        }
        aux=aux->sgte;
    }
}

void Grafo::vaciar_aristas(Tvertice &aux) {
    Tarista q,r;
    q=aux->ady;
    while(q->sgte!=NULL){
        r=q;
        q=q->sgte;
        delete(r);
    }
}

void Grafo::eliminar_vertice() {
    char var;
    Tvertice aux,ant;
    aux=p;
    cout<<"ELIMINAR UN VERTICE"<<endl;
    if(p==NULL){
        cout<<"GRAFO VACIO!";
        return;
    }
    cout<<"INGRESE NOMBRE DEL VERTICE:";
    cin>>var;
    while(aux!=NULL){
        if(aux->nombre==var){
            if(aux->ady!=NULL){
                vaciar_aristas(aux);
            }
            if(aux==p){
                p=p->sgte;
                delete(aux);
                cout<<"VERTICE ELIMINADO!";
                return;
            }
            else{
                ant->sgte = aux->sgte;
                delete(aux);
                cout<<"VERTICE ELIMINADO!";
                return;
            }
        }
        else{
            ant=aux;
            aux=aux->sgte;
        }
    }
}

void Grafo::eliminar_arista() {
    char ini, fin;
    Tvertice aux, aux2;
    Tarista q,r;
    cout<<"\n ELIMINAR ARISTA"<<endl;
    cout<<"INGRESE VERTICE DE ORIGEN:";
    cin>>ini;
    cout<<"INGRESE VERTICE DESTINO:";
    cin>>fin;
    aux=p;
    aux2=p;
    while(aux2!=NULL){
        if(aux2->nombre==fin){
            break;
        }
        else{
            aux2=aux2->sgte;
        }
    }
    while(aux!=NULL){
        if(aux->nombre==ini){
            q=aux->ady;
            while(q!=NULL){
                if(q->destino==aux2){
                    if(q==aux->ady){
                        aux->ady=aux->ady->sgte;
                    }
                    else{
                        r->sgte=q->sgte;
                    }
                    delete(q);
                    cout<<"ARISTA  "<<aux->nombre<<"----->"<<aux2->nombre<<" ELIMINADA!"<<endl;
                    return;
                }
            }
            r=q;
            q=q->sgte;
        }
        aux = aux->sgte;
    }
}

void Grafo::mostrar_grafo(){
    Tvertice vertex;
    Tarista edge;
    vertex=p;
    if (vertex==NULL){
        cout<<"\n\tGRAFO VACIO!"<<endl;
    }else{
        cout<<"VERTICE|LISTA DE ADYACENCIA"<<endl;
        while(vertex!=NULL){
            cout<<"     "<<vertex->nombre<<"|";
            if(vertex->ady!=NULL){
                edge=vertex->ady;
                while(edge!=NULL){
                    cout<<" "<<edge->destino->nombre;
                    edge=edge->sgte;
                }
            }
            vertex=vertex->sgte;
            cout<<endl;
        }
    }
}

void Grafo::mostrar_aristas(){
    Tvertice aux;
    Tarista edge;
    char var;
    cout<<"MOSTRAR ARISTAS DE VERTICE"<<endl;
    cout<<"INGRESE VERTICE: ";
    cin>>var;
    aux=p;
    while(aux!=NULL){
        if(aux->nombre==var){
            if(aux->ady==NULL){
                cout<<"EL VERTICE NO TIENE ADYACENTES!";
                return;
            }else{
                cout<<"VERTICE|LISTA DE ADYACENCIA\n";
                cout<<"   "<<aux->nombre<<"|";
                edge=aux->ady;
                while(edge!=NULL){
                    cout<<edge->destino->nombre<<" ";
                    edge=edge->sgte;
                }
                cout<<endl;
                return;
            }
        }
        else{
            aux=aux->sgte;
        }
    }
}
void Grafo::adyacencia() {
    Tvertice vertex;
    Tarista edge;
    bool band=false;
    char ini,fin;
    cout<<"MOSTRAR SI LOS VERTICES SON ADYACENTES"<<endl;
    cout<<"INGRESE EL VERTICE DE ORIGEN: ";
    cin>>ini;
    cout<<"INGRESE EL VERTICE DE DESTINO: ";
    cin>>fin;
    vertex=p;
    while(vertex!=NULL){
        if(vertex->nombre==ini){
            if(vertex->ady==NULL){
                cout<<"\nLOS VERTICES NO SON ADYACENTES"<<endl;
                cout<<"\nEL VERTICE NO TIENE ADYACENTES!"<<endl;
                band=true;
                return;
            }else{
                edge=vertex->ady;
                while(edge!=NULL){
                    if (edge->destino->nombre==fin){
                        cout<<"\nLOS VERTICES SON ADYACENTES"<<endl;
                        band=true;
                        return;
                    }
                    edge=edge->sgte;
                }
                cout<<endl;
                if (band==false){
                    cout<<"\nLOS VERTICES NO SON ADYACENTES"<<endl;
                }
                return;
            }
        }
        else{
            vertex=vertex->sgte;
        }

    }
}
void Grafo::grado() {
    Tvertice aux;
    Tarista edge;
    char var;
    int cont=0;
    cout<<"MOSTRAR ARISTAS DE VERTICE"<<endl;
    cout<<"INGRESE VERTICE: ";
    cin>>var;
    aux=p;
    while(aux!=NULL){
        if(aux->nombre==var){
            if(aux->ady==NULL){
                cout<<"EL VERTICE NO TIENE ADYACENTES!";
                return;
            }else{
                edge=aux->ady;
                while(edge!=NULL){
                    cont++;
                    edge=edge->sgte;
                }
                cout<<endl;
                cout <<"EL GRADO DEL GRAFO ES:"<< cont<<endl;
                return;
            }
        }
        else
            aux=aux->sgte;
    }
}
