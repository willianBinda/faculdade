
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class No
{
public:
    int data;
    No *esquerda, *direita, *pais;
    No(int data)
    {
        this->data = data;
        esquerda = direita = pais = NULL;
    }
};

class Arvore
{
public:
    No *raiz;
    No *pais;
    Arvore()
    {
        raiz = pais = NULL;
    }

    void inserir_na_arv(int num)
    {
        raiz = insert(raiz, num);
    }

    No *insert(No *novo_no, int num)
    {
        if (novo_no == nullptr)
        {
            return new No(num);
        }
        if (num < novo_no->data)
        {
            novo_no->esquerda = insert(novo_no->esquerda, num);
        }
        else if (num > novo_no->data)
        {
            novo_no->direita = insert(novo_no->direita, num);
        }
        return novo_no;
    }
};

bool buscar_no(No *raiz, int num);
int altura(No *raiz);
int get_col(int h);
void imprimir_no(int **M, No *raiz, int col, int linha, int altura);
void imprimir_arvore(Arvore arvore);
int calc_altura(No *raiz);
void pre_ordem(No *raiz);
void em_ordem(No *raiz);
void pos_ordem(No *raiz);
int qtde_Nos(No *raiz);
int qtde_folhas(No *raiz);
int qtde_sub_arvores(No *raiz);

int main()
{
    Arvore minhaArvore;
    do
    {
        int op;
        cout << "Ecolha uma opção:\n";
        cout << "(0)Sair\n";
        cout << "(1)Inserir nó\n";
        cout << "(2)Exibir árvore\n";
        cout << "(3)Buscar nó\n";
        cout << "(4)Exibir árvore em pré-ordem\n";
        cout << "(5)Exibir árvore em em ordem\n";
        cout << "(6)Exibir árvore em pós-ordem\n";
        cout << "(7)Altura da árvore\n";
        cout << "(8)Total de nós da árvore\n";
        cout << "(9)Total de folhas da árvore\n";
        cout << "(10)Total de sub-árvores\n\n";
        cin >> op;
        if (op == 1)
        {
            do
            {
                int num;
                cout << "Digite 1000 para sair do laço de inserção\n";
                cout << "Digite um numero: ";
                cin >> num;
                if (num == 1000)
                {
                    cout << endl;
                    break;
                }
                else
                {
                    minhaArvore.inserir_na_arv(num);
                }

            } while (true);
        }
        else if (op == 2)
        {
            cout << "\n";
            cout << "--------------------\n";
            imprimir_arvore(minhaArvore);
            cout << "--------------------\n";
            cout << "\n";
        }
        else if (op == 3)
        {
            int num;
            cout << "Digite um numero: ";
            cin >> num;
            cout << "--------------------\n";
            if (buscar_no(minhaArvore.raiz, num))
            {
                cout << "Numero encontrado\n";
            }
            else
            {
                cout << "Numero não encontrado\n";
            }
            cout << "--------------------\n\n";
        }
        else if (op == 4)
        {
            cout << "--------------------\n";
            cout << "Arvore pre-ordem\n";
            pre_ordem(minhaArvore.raiz);
            cout << "\n--------------------";
            cout << "\n\n";
        }
        else if (op == 5)
        {
            cout << "--------------------\n";
            cout << "Arvore em ordem\n";
            em_ordem(minhaArvore.raiz);
            cout << "\n--------------------";
            cout << "\n\n";
        }
        else if (op == 6)
        {
            cout << "--------------------\n";
            cout << "Arvore pos-ordem\n";
            pos_ordem(minhaArvore.raiz);
            cout << "\n--------------------";
            cout << "\n\n";
        }
        else if (op == 7)
        {
            cout << "--------------------\n";
            cout << "Altura da árvore: " << calc_altura(minhaArvore.raiz) << endl;
            cout << "--------------------";
            cout << "\n\n";
        }
        else if (op == 8)
        {
            cout << "--------------------\n";
            cout << "Total de nos da arvore: " << qtde_Nos(minhaArvore.raiz) << endl;
            cout << "--------------------";
            cout << "\n\n";
        }
        else if (op == 9)
        {
            cout << "--------------------\n";
            cout << "Total de folhas da arvore: " << qtde_folhas(minhaArvore.raiz) << endl;
            cout << "--------------------";
            cout << "\n\n";
        }
        else if (op == 10)
        {
            cout << "--------------------\n";
            cout << "Total de sub-arvores: " << qtde_sub_arvores(minhaArvore.raiz) << endl;
            cout << "--------------------";
            cout << "\n\n";
        }
        else if (op == 0)
        {
            break;
        }
        else
        {
            cout << "Opção invalida\n";
            continue;
        }
    } while (1);

    return 0;
}

bool buscar_no(No *raiz, int num)
{
    // if(raiz==nullptr){
    //     cout<<"o numero é o raiz\n";
    //     return false;
    // }

    if (raiz == nullptr || raiz->data == num)
    {
        return (raiz != nullptr);
    }

    if (raiz->data < num)
    {
        return buscar_no(raiz->direita, num);
    }

    return buscar_no(raiz->esquerda, num);
}

int altura(No *raiz)
{
    if (raiz == NULL)
        return 0;
    return max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
}

int get_col(int h)
{
    if (h == 1)
        return 1;
    return get_col(h - 1) + get_col(h - 1) + 1;
}

void imprimir_no(int **M, No *raiz, int col, int linha, int altura)
{
    if (raiz == NULL)
        return;
    M[linha][col] = raiz->data;
    imprimir_no(M, raiz->esquerda, col - pow(2, altura - 2), linha + 1, altura - 1);
    imprimir_no(M, raiz->direita, col + pow(2, altura - 2), linha + 1, altura - 1);
}

void imprimir_arvore(Arvore arvore)
{
    int h = altura(arvore.raiz);
    int col = get_col(h);
    int **M = new int *[h];
    for (int i = 0; i < h; i++)
    {
        M[i] = new int[col];
    }

    imprimir_no(M, arvore.raiz, col / 2, 0, h);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (M[i][j] == 0)
                cout << " "
                     << " ";
            else
                cout << M[i][j] << " ";
        }

        cout << endl;
    }
}
int calc_altura(No *raiz)
{

    if (raiz == nullptr)
    {
        return -1;
    }
    else
    {
        int altura_esquerda = calc_altura(raiz->esquerda);
        int altura_direita = calc_altura(raiz->direita);
        return 1 + max(altura_esquerda, altura_direita);
    }
}

void pre_ordem(No *raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    cout << raiz->data << " ";
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void em_ordem(No *raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    em_ordem(raiz->esquerda);
    cout << raiz->data << " ";
    em_ordem(raiz->direita);
}

void pos_ordem(No *raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    cout << raiz->data << " ";
}

int qtde_Nos(No *raiz)
{
    if (raiz == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + qtde_Nos(raiz->esquerda) + qtde_Nos(raiz->direita);
    }
}

int qtde_folhas(No *raiz)
{
    if (raiz == nullptr)
    {
        return 0;
    }
    else if (raiz->esquerda == nullptr && raiz->direita == nullptr)
    {
        return 1;
    }
    else
    {
        int count = 0;
        count += qtde_folhas(raiz->esquerda);
        count += qtde_folhas(raiz->direita);
        return count;
    }
}

int qtde_sub_arvores(No *raiz)
{
    if (raiz == nullptr)
    {
        return 0;
    }
    if (raiz->esquerda == nullptr && raiz->direita == nullptr)
    {
        return 0;
    }
    int sub_arv_esquerda = qtde_sub_arvores(raiz->esquerda);
    int sub_arv_direita = qtde_sub_arvores(raiz->direita);
    return sub_arv_esquerda + sub_arv_direita + 1;
}
