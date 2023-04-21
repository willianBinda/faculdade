#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string> // Necessário para usar strings
#include <typeinfo>
using namespace std;

struct lista
{
    string nome;
    int telefone;
    string endereco;
    string empresa;
    struct lista *prox;
};

typedef struct lista Lista;

Lista *inicializa(void)
{
    return NULL;
}

Lista *insere(Lista *l)
{
    string nome;
    int telefone;
    string endereco;
    string empresa;
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    cout << "\nDigite seu nome: ";
    cin >> nome;
    cout << "Digite seu telefone (somente numeros): ";
    cin >> telefone;
    cout << "Digite seu endereço: ";
    cin >> endereco;
    cout << "Digite sua empresa: ";
    cin >> empresa;
    cout<<"\n";

    novo->nome = nome;
    novo->telefone = telefone;
    novo->endereco = endereco;
    novo->empresa = empresa;

    novo->prox = l;
    return novo;
}

void listar(Lista *l)
{
    Lista *p;
    if(!l){
        cout<<"\n\tLista vazia\t\n";
        cout<<"-----------------------------\n";
        cout<<"-----------------------------\n";

    }else{
        cout << "\n\tListando\t\n";
        for (p = l; p != NULL; p = p->prox)
        {
            cout<<"-----------------------------\n";
            cout <<"\tnome: " << p->nome << "\t\n";
            cout << "\ttelefone: " << p->telefone << "\t\n";
            cout << "\tendereco: " << p->endereco << "\t\n";
            cout << "\tempresa: " << p->empresa << "\t\n";
            if(p->prox==NULL){
                cout<<"-----------------------------\n";
            }else{
                continue;
            }

        }
    }
}
void liberar(Lista *l)
{
    Lista *p = l;
    cout << "Liberando\n";
    while (p != NULL)
    {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

int main()
{
    Lista *l;
    l = inicializa();

    do
    {
        int op;
        printf("Ecolha uma opção: \n(0)Exit\n(1)Listar a agenda\n(2)inserir mais informações na agenda\n");
        scanf("%d", &op);
        if (op == 1)
        {
            listar(l);
            continue;
        }
        else if (op == 2)
        {
            // insere
            l = insere(l);
            continue;
        }
        else if (op == 0)
        {
            liberar(l);
            break;
        }
        else
        {
            printf("Opção invalida\n\n");
            continue;
        }

        return 0;
    } while (1);
}