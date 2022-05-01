struct vertice{
    char nombre;//nombre del vertice
    struct vertice *sgte;
    struct arista *ady;//puntero hacia la primera arista del vertice
};
struct arista{
    struct vertice *destino;//puntero al nodo de llegada
    struct arista *sgte;
};
typedef struct vertice *Tvertice;//Tipo Vertice
typedef struct arista *Tarista; //Tipo Arista