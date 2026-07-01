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
    carregarBiblioteca(biblioteca, nomeArquivo);

    int idBusca;
    int opcao;
    do {
        menu(biblioteca);
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
                scanf("%d", &idBusca);
                mostrarLivro(biblioteca, idBusca);
                break;

            case 4:
                printf("--- EDITANDO LIVRO ---\n");
                printf("Digite o ID do livro que deseja alterar: ");
                scanf("%d", &idBusca);
                editarLivro(biblioteca, idBusca);
                break;

            case 5:
                printf("--- LISTA DE TITULOS MAGICOS ---\n");
                listarTitulos(biblioteca);
                break;

            case 6:
                printf("Salvando o progresso no pergaminho '%s'...\n", nomeArquivo);
                salvarBiblioteca(biblioteca, nomeArquivo);
                printf("Fechando os portoes da Biblioteca Magica. Ate logo!\n");
                break;

            default:
                printf("Opcao invalida! Os sabios nao reconhecem este comando. Tente novamente.\n");
                break;
        }

    } while (opcao != 6);

    liberarBiblioteca(biblioteca);
    return 0;
}