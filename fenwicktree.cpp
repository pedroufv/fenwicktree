#include <iostream>

using namespace std;

double fenwick[12];

double get(int indice)
{
    double sum = 0;
    while (indice > 0){
        sum += fenwick[indice];
        indice -= (indice & -indice);
    }
    return sum;
}


void update(int indice ,double valor, int tamanho)
{
    while (indice <= tamanho){
        fenwick[indice] += valor;
        indice += (indice & -indice);
    }
}

int main()
{
    update(1, 100, 12);
    update(2, -200, 12);
    update(3, -300, 12);
    update(4, -400, 12);
    update(5, 800, 12);

    cout << get(5) << endl;

    update(6, 500, 12);
    update(7, 900, 12);
    update(8, -100, 12);
    update(9, -200, 12);

    cout << get(9) << endl;

    update(10, -300, 12);
    update(11, 400, 12);
    update(12, -100, 12);

    cout << get(12) << endl;
}