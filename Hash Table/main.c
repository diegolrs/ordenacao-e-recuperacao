#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define null NULL
#define true 1
#define false 0
#define bool int

#define ERROR -1

#define N 101

typedef struct endereco Endereco;
typedef struct hash Hash;

struct endereco
{
    int cep;
    char rua[100];
    Endereco *next;
};

Endereco* buildEndereco(int cep, char* rua)
{
    Endereco* e = (Endereco*) malloc(sizeof(Endereco));

    if(e == null)
        return null;

    e->cep = cep;
    strcpy(e->rua, rua);
    e->next = null;

    return e;
}

struct hash
{
    Endereco *v[N];
};

static int hashNumber(int mat)
{
    //return (mat%(N*2));
    return (mat%(N));
}

Hash* buildHash()
{
    Hash* h = (Hash*) malloc(sizeof(Hash));

    for(int i = 0; i < N; i++)
    {
        h->v[i] = null;
    }

    return h;
}

Hash* freeHash(Hash* h)
{
    for(int i = 0; i < N; i++)
        free(h->v[i]);

    free(h);
}

Endereco* insert(Endereco* e, Hash* h)
{
    int index = hashNumber(e->cep);

    e->next = h->v[index];
    h->v[index] = e;

    return e;
}

Endereco* search(Hash* h, int cep)
{
    if(h == null)
        return null;

    int k = hashNumber(cep);
    Endereco* e = h->v[k];

    while(e != null)
    {
        if(e->cep == cep)
            break;
        else
            e = e->next;
    }

    return e;
}


int main()
{
    Hash* h = buildHash();

    Endereco* e = buildEndereco(10, "leoniza");
    insert(e, h);

    e = search(h, 10);
    printf("%d", e->cep);

    freeHash(h);
    return 0;
}
