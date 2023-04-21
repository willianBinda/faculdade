/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct lista2 {
    int info;
    struct lista2* ant;
    struct lista2* prox;
};
typedef struct lista2 Lista2;

Lista2* inicializa (void) 
{
    return NULL;
}

Lista2* insere(Lista2* l, int v) 
{
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    
    if (l != NULL)
        l->ant = novo;
    
    return novo;
}

Lista2* busca(Lista2* l, int v) 
{
    Lista2* p;
    for (p = l; p != NULL; p = p->prox)
        if (p->info == v)
            return p;
    
    return NULL;
}

Lista2* remover(Lista2* l, int v) 
{
    Lista2* p = busca(l, v);
    if (p == NULL)
        return l;
        
    if (l == p)
        l = p->prox;
    else
        p->ant->prox = p->prox;
    
    if (p->prox != NULL)
        p->prox->ant = p->ant;
    
    free(p);
    return l;
}

void listar(Lista2* l) 
{
    Lista2* p;
    for (p = l; p != NULL; p = p->prox)
        printf("valor: %d\n", p->info);
} 

int main()
{
   Lista2* l;
   l = inicializa();
   
   for (int i = 0; i <=5; i++) {
       l = insere(l, i);
   }
   
   listar(l);
   l = remover(l, 5);
   printf("\nLista modificada\n");
   listar(l);

    return 0;
}
