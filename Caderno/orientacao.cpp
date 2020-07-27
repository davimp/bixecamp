#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

/* Apelidos para acessarmos a estrutura */
#define f first;
#define s second;

/* Calculando a determinante dos tres pontos */
int orientação(pii p1, pii p2, pii p1) {

    int val = (p2.f - p1.f) * (p3.s - p2.s) -
              (p2.s - p1.s) * (p3.f - p2.f);

    return val;
}
