//Victor Krieger Almeida
//Grafos sem Peso.

#include <iostream>
#include <string>

using namespace std;
const unsigned int MAXNOS = 100;


class GrafoSemPeso
{
    private:
    bool adj[MAXNOS][MAXNOS];
    int N;
    
    public:
    GrafoSemPeso(int num_nos);
    void une(int a, int b);
    void remv(int a ,int b);
    bool adjacente(int a, int b);
    void imprime();
};

GrafoSemPeso::GrafoSemPeso(int num_nos){
    N = num_nos;
    int i , j;
    
    for(i=0; i <num_nos; i++)
        for(j = 0; j < num_nos; j++)
            adj[i][j] = false;
}

void GrafoSemPeso::une(int a, int b)
{
    if(a>= 0 && a < N && b >= 0 && b < N)
        adj[a][b] = true;
    else
        cout << endl << "pelo menos 1 no eh invalido!" << endl;
}

void GrafoSemPeso::remv(int a, int b){
     if(a>= 0 && a < N && b >= 0 && b < N)
        adj[a][b] = false;
    else
        cout << endl << "pelo menos 1 no eh invalido!" << endl;
}

bool GrafoSemPeso::adjacente(int a, int b){
      if(a>= 0 && a < N && b >= 0 && b < N)
        return adj[a][b];
    else
        cout << endl << "pelo menos 1 no eh invalido!" << endl;
}

void GrafoSemPeso::imprime()
{
    int i , j;
    cout<< endl << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "| |";
    
    for( i = 0; i < N; i++)
        cout << i << " ";
        
    for(i = 0; i < N; i++){
        cout<<endl << i << " ";
        for(j=0;j<N;j++)
            cout << adj[i][j] << " ";
    }
    cout << endl;
}
    
int main()
{
    string msg[] = {"nao", "sim"};
    GrafoSemPeso meuGrafo(5);
    
    meuGrafo.imprime();
    meuGrafo.une(0,3);
    meuGrafo.une(1,2);
    meuGrafo.imprime();
    
    meuGrafo.une(0,2);
    meuGrafo.une(2,3);
    meuGrafo.une(3,4);
    meuGrafo.une(4,1);
    meuGrafo.une(3,1);
    
    meuGrafo.imprime();
    
    cout << endl << "1---3" << msg[meuGrafo.adjacente(1,3)];
    cout << endl << "3---1" << msg[meuGrafo.adjacente(3,1)];
    cout << endl << "4---1" << msg[meuGrafo.adjacente(4,1)];
    
    meuGrafo.remv(2,3);
    meuGrafo.imprime();
    
    return 0;
    
    
}