#include <iostream>
#include <cmath>

using namespace std;

bool local_valido(int tabela[9][9], int linha, int coluna, int n) {
    for (int i = 0; i < 9; i++) {
        if (tabela[linha][i] == n) {
            return false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (tabela[i][coluna] == n) {
            return false;
        }
    }

    int comeco_linha = (linha / 3) * 3;
    int comeco_coluna = (coluna / 3) * 3;

    for (int i = comeco_linha; i < comeco_linha + 3; i++) {
        for (int j = comeco_coluna; j < comeco_coluna + 3; j++) {
            if (tabela[i][j] == n) {
                return false;
            }
        }
    }

    // Caso o número não seja encontrado, então é válido
    return true;
}

bool lugar_vazio(int tabela[9][9], int& linha, int& coluna) {
    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            if (tabela[linha][coluna] == 0) {
                return true;
            }
        }
    }

    return false;
}

bool resolve_sudocu(int tabela[9][9]) {
    int linha, coluna;

    if (!lugar_vazio(tabela, linha, coluna)) {
        return true;
    }

    for (int n = 1; n <= 9; n++) {
        if (local_valido(tabela, linha, coluna, n)) {
            tabela[linha][coluna] = n;

            if (resolve_sudocu(tabela)) {
                return true;
            }

            tabela[linha][coluna] = 0;
        }
    }

    return false;
}

void imprime_tabela(int tabela[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << tabela[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    int tabela[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        
    };

    if (resolve_sudocu(tabela)) {
        cout << "Solucao encontrada:" << endl;
        imprime_tabela(tabela);
    } else {
        cout << "Nao ha solucao para o Sudoku informado." << endl;
    }

    return 0;
}
