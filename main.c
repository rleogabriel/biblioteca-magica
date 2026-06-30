#include <stdio.h>
#include "biblioteca.h"

LivroMagico *biblioteca[MAX_LIVROS];

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Erro: Forneca o nome do arquivo de dados. Ex: ./programa biblioteca.txt\n");
        return 1;
    }
    
    char *nomeArquivo = argv[1];
    
    inicializarVetor(biblioteca);

    int opcao;
    do {
        menu();
        scanf("%d%*c", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("--- CADASTRANDO NOVO LIVRO ---\n");
                cadastrarLivro(biblioteca);
                break;
        }

    } while (opcao != 6);

    return 0;
}