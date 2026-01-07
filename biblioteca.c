#include <stdio.h>
#include <string.h>

#define TAMANHO_ACERVO 20

struct Livro {
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

void cadastrarLivros(struct Livro acervo[], int tamanho);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int tamanho);

int main() {
    struct Livro acervo[TAMANHO_ACERVO];
    int opcao, codigoBusca;
    int i;

    for (i = 0; i < TAMANHO_ACERVO; i++) {
        acervo[i].codigo = 0;
    }

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano de publicacao\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
        case 1:
            cadastrarLivros(acervo, TAMANHO_ACERVO);
            break;
        case 2:
            imprimirLivros(acervo, TAMANHO_ACERVO);
            break;
        case 3:
            printf("Digite o codigo do livro que deseja pesquisar: ");
            scanf("%d", &codigoBusca);
            fflush(stdin);
            pesquisarLivro(acervo, TAMANHO_ACERVO, codigoBusca);
            break;
        case 4:
            ordenarLivros(acervo, TAMANHO_ACERVO);
            break;
        }
    } while (opcao != 5);

    return 0;
}

void cadastrarLivros(struct Livro acervo[], int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("\nCadastro do livro %d:\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &acervo[i].codigo);
        fflush(stdin);

        printf("Titulo: ");
        fgets(acervo[i].titulo, 50, stdin);

        printf("Autor: ");
        fgets(acervo[i].autor, 30, stdin);

        printf("Area: ");
        fgets(acervo[i].area, 30, stdin);

        printf("Ano: ");
        scanf("%d", &acervo[i].ano);
        fflush(stdin);

        printf("Editora: ");
        fgets(acervo[i].editora, 30, stdin);
    }
}

void imprimirLivros(struct Livro acervo[], int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if (acervo[i].codigo != 0) {
            printf("\nLivro %d:\n", i + 1);
            printf("Codigo: %d\n", acervo[i].codigo);
            printf("Titulo: %s", acervo[i].titulo);
            printf("Autor: %s", acervo[i].autor);
            printf("Area: %s", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
        }
    }
}

void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca) {
    int i = 0;
    int encontrado = 0;

    while (i < tamanho) {
        if (acervo[i].codigo == codigoBusca) {
            printf("\nLivro encontrado:\n");
            printf("Codigo: %d\n", acervo[i].codigo);
            printf("Titulo: %s", acervo[i].titulo);
            printf("Autor: %s", acervo[i].autor);
            printf("Area: %s", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            encontrado = 1;
            break;
        }
        i++;
    }

    if (!encontrado) {
        printf("\nLivro nao encontrado!\n");
    }
}

void ordenarLivros(struct Livro acervo[], int tamanho) {
    int i, j;
    struct Livro temp;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1; j++) {
            if (acervo[j].ano > acervo[j + 1].ano) {
                temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
            }
        }
    }

    printf("\nLivros ordenados por ano com sucesso!\n");
}
