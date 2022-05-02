#include<iostream>
using namespace std;

int A[100];

int subMax(int tam){
    int i,j,cont,sm,imax,jmax;

    sm=A[0];
    for ( i = 0; i < tam; i++)
    {
        cont = 0;
        for ( j = i; j < tam; j++)
        {
            cont=cont+A[j];
            if (cont>sm)
            {
                sm=cont;
                imax=i;
                jmax=j;
                cout<<"sm= "<<sm<<" ti= "<<i<<" tj= "<<j;
            }
        }
            
        
    }
    
}

int main(){


}