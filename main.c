#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "biblioteca.h"

LivroMagico *biblioteca[MAX_LIVROS];

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Erro: Forneca o nome do arquivo de dados. Ex: ./programa biblioteca.txt\n");
        return 1;
    }
    
    char *nomeArquivo = argv[1];
    
    inicializarVetor(biblioteca);

    int idBusca;
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

            case 2:
                printf("--- DELETANDO LIVRO ---\n");
                printf("Digite o ID do livro que deseja excluir: ");
                scanf("%d", &idBusca);
                deletarLivro(biblioteca, idBusca);
                break;

            case 3:
                printf("--- INSPECIONANDO LIVRO ---\n");
                printf("Digite o ID do livro que deseja buscar: ");
                mostrarLivro(biblioteca, idBusca);
                break;

            case 4:
                printf("--- EDITANDO LIVRO ---\n");
                printf("Digite o ID do livro que deseja alterar: ");
                editarLivro(biblioteca, idBusca);
                break;

            case 5:
                printf("--- LISTA DE TITULOS MAGICOS ---\n");
                listarTitulos(biblioteca);
                break;
        }

    } while (opcao != 6);

    return 0;
}