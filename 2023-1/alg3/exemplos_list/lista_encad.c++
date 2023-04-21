/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializa (void) 
{
    return NULL;
}

Lista* insere(Lista *l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void listar(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        printf("valor: %d\n", p->info);
}

int isvazia(Lista *l)
{
    return (l == NULL);
}

Lista* busca(Lista* l, int v) 
{
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) 
            return p;
    } 
    
    return NULL;
}

Lista* remover(Lista* l, int v) {
    Lista* ant = NULL;
    Lista* p = l;
    
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL) 
        return l;
    
    if (ant == NULL)
        l = p->prox;
    else
        ant->prox = p->prox;
        
    free(p);
    
    return l;
}

void liberar(Lista* l) 
{
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

int main()
{
    Lista* l;
    l = inicializa();
    
    for (int i = 0; i <= 8; i++) {
        l = insere(l, i);
    }
    
    listar(l);
    l = remover(l, 8);
    printf("\n Lista modificada \n");
    listar(l);
    
    Lista* buscaNaLista = busca(l, 2);
    printf("\n Info: %d", buscaNaLista->info);
    
    liberar(l);
    
    return 0;
}
