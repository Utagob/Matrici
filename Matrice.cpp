#include <iostream>
#include <fstream>
using namespace std;

struct matrice{
    int m, n;
    int **M;
}X, A, B;

void createMatrice(ifstream &Fi, matrice &C){
    Fi >> C.m >> C.n;
    C.M = new int*[C.m];
    for(int i=0; i<C.m; i++)
    C.M[i] = new int[C.n];

    for(int i=0; i<C.m; i++)
    for(int j=0; j<C.n; j++)
    Fi >> C.M[i][j];
}

void deleteMatrice(matrice &C){
    for(int i=0; i<C.m; i++)
    delete[] C.M[i];
    delete[] C.M;
}

matrice add(matrice &A, matrice &B){
    if(A.m != B.m || A.n != B.n) cout << "Matricilie sunt de marimi diferite";
    else{
        matrice X;
        X.m = A.m;
        X.n = A.n;
        X.M = new int*[X.m];
        for(int i=0; i<X.m; i++)
        X.M[i] = new int[X.n];

        for(int i=0; i<X.m; i++)
        for(int j=0; j<X.n; j++)
        X.M[i][j] = A.M[i][j]+B.M[i][j];

        return X;
    }
}

void showMatrice(matrice &A){
    for(int i=0; i<A.m; i++){
        for(int j=0; j<A.n; j++)
            cout << A.M[i][j] << " ";
        cout << endl;
    }
}

int main(){
    ifstream Fi("matrice.txt");
    createMatrice(Fi, A);
    createMatrice(Fi, B);
    cout << "A:" << endl;
    showMatrice(A);
    cout << endl;
    cout << "B:" << endl;
    showMatrice(B);
    cout << endl;
    X = add(A, B);
    showMatrice(X);
    deleteMatrice(A);
    deleteMatrice(B);
    deleteMatrice(X);
    return 0;
}