#include <iostream>
#include <fstream>
using namespace std;

struct matrice{
    int m, n;
    int **M;
}X, A, B;

void createM(ifstream &Fi, matrice &C){
    Fi >> C.m >> C.n;
    C.M = new int*[C.m];
    for(int i=0; i<C.m; i++)
    C.M[i] = new int[C.n];

    for(int i=0; i<C.m; i++)
    for(int j=0; j<C.n; j++)
    Fi >> C.M[i][j];
}

void deleteM(matrice &C){
    for(int i=0; i<C.m; i++)
    delete[] C.M[i];
    delete[] C.M;
}

matrice sum(matrice &A, matrice &B){
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

matrice sub(matrice &A, matrice &B){
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
        X.M[i][j] = A.M[i][j]-B.M[i][j];

        return X;
    }
}

matrice multiply(int x, matrice &A){
    matrice X;
    X.m = A.m;
    X.n = A.n;
    X.M = new int*[X.m];
    for(int i=0; i<X.m; i++)
    X.M[i] = new int[X.n];

    for(int i=0; i<X.m; i++)
    for(int j=0; j<X.n; j++)
    X.M[i][j] = A.M[i][j]*x;

    return X;
}

matrice multiplyM(matrice &A, matrice &B){
    if(A.n != B.m){
        cout << "Inmultire imposibila" << endl;
        exit(1);
    }
    matrice X;
    X.m = A.m;        
    X.n = B.n;        
    X.M = new int*[X.m];
    for(int i=0; i<X.m; i++)
        X.M[i] = new int[X.n];
 
    for(int i=0; i<X.m; i++){
        for(int j=0; j<X.n; j++){ 
            X.M[i][j] = 0;
            for(int k=0; k<A.n; k++)
                X.M[i][j] += A.M[i][k] * B.M[k][j];
        }
    }
    return X;
}

void showMatrice(matrice &A){
    for(int i=0; i<A.m; i++){
        for(int j=0; j<A.n; j++)
            cout << A.M[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    deleteM(A);
}

int main(){
    ifstream Fi("matrice.txt");
    createMatrice(Fi, A);
    createMatrice(Fi, B);
    cout << "A:" << endl;
    showMatrice(A);
    cout << "B:" << endl;
    showMatrice(B);
    cout << "a)" << endl;
    cout << "A+B" << endl;  
    showMatrice(sum(A, B));
    cout << "B+C" << endl;
    showMatrice(sum(B, C));
    cout << "A+B+C" << endl;
    showMatrice(sum(sum(A, B), C));
    cout << "b)" << endl;
    cout << "2A+B" << endl;
    showMatrice(sum(multiply(2, A), B);
    cout << "3B+4C" << endl; 
    showMatrice(sum(multiply(3, B), multiply(4, C));
    cout << "2A-3B" << endl; 
    showMatrice(sub(multiply(2, A), multiply(3, B));
    cout << "c)" << endl;
    count << "4A" << endl; showMatrice(multiply(4, A));
    cout << "2B" << endl; 
    showMatrice(multiply(2, B));
    cout << "4C" << endl;
    showMatrice(multiply(4, C));
    cout << "5A" << endl; 
    showMatrice(multiply(5, A));
    count << "6B" << endl; 
    showMatrice(multiply(6, B));
    count << "3C" << endl; 
    showMatrice(multiply(3, C));
    cout << "d)" << endl;
    cout << "A-B+C" << endl; 
    showMatrice(sum(sub(A, B), C));
    count << "A+B-C" << endl; 
    showMatrice(sub(sum(A, B), C));
    cout << "A-C+B" << endl;
    showMatrice(sum(sub(A, C), B));
    cout<< "A+B-2C" << endl;
    showMatrice(sub(sum(A, B), multiply (2, C));
    cout << "3A+B+C" << endl;
    showMatrice(sum(sum(multiply(3, A), B), C));
    count << "4A-B+C" << endl;
    showMatrice(sum(sub(multiply(4, A), B), C));
    count << "2A+4B" << endl;
    showMatrice(sum(multiply(2, A), multiply(4, B)));
    cout << "3A-B+2C" << endl;
    showMatrice(sum(sub(multiply(3, A), B), multiply(2, C);
    6A+2B showMatrice(sum(multiply(6, A), multiply(2, B)));
    8A-3C showMatrice(sub(multiply(6, A), multiply(2, B)));
    2A+B-4C showMatrice(sub(sum(multiply(2, A), B), multiply(4, C)));
    2A-3B+C showMatrice(sum(sub(multiply(2, A), multiply(3, B)), C));
    cout << "f)" << endl;
    A*B showMatrice(multiplyM(A, B));
    B*A showMatrice(multiplyM(B, A));
    A*C showMatrice(multiplyM(A, C));
    C*A showMatrice(multiplyM(C, A));
    B*C showMatrice(multiplyM(B, C));
    C*B showMatrice(multiplyM(C, B));
    A*B*C showMatrice(multiply(multiplyM(A, B), C));
    B*A*C showMatrice(multiply(multiplyM(B, A), C));
    C*A*B showMatrice(multiply(multiplyM(C, A), B));

    deleteM(A);
    deleteM(B);
    return 0;
}