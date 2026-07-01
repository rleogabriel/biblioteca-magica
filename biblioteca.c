#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>

void menu() {
    printf("\n");
    printf("=====================================================\n");
    printf("||             * INVENTARIO MAGICO *               ||\n");
    printf("||           Biblioteca Magica de RPG              ||\n");
    printf("=====================================================\n");
    printf("||                                                 ||\n");
    printf("||  1. [Cadastrar] Novo Livro Magico               ||\n");
    printf("||  2. [Deletar]   Incinerar Registro de Livro     ||\n");
    printf("||  3. [Mostrar]   Inspecionar Detalhes do Livro   ||\n");
    printf("||  4. [Editar]    Alterar Atributos do Livro      ||\n");
    printf("||  5. [Listar]    Ver Catalogo de Titulos         ||\n");
    printf("||  6. [Sair]      Salvar e Fechar o Inventario    ||\n");
    printf("||                                                 ||\n");
    printf("=====================================================\n");
    printf("O que deseja fazer, Mestre? Escolha uma opcao: ");
}

void inicializarVetor(LivroMagico **biblioteca){
    int i;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        biblioteca[i] = NULL;
    }
}

void cadastrarLivro(LivroMagico **biblioteca){
    int i;
    int flag = 0;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        if(biblioteca[i] == NULL){
            biblioteca[i] = (LivroMagico*) malloc(sizeof(LivroMagico));
            flag = 1;
        } 
    }
    if(flag == 0) {
        printf("Inventario Cheio");
        return;
    }
    printf("\n");

    printf("ID do Livro: ");
        scanf("%d%*c", &biblioteca[i]->id);

    printf("Titulo do Livro: ");
        scanf(" %[^\n]", biblioteca[i]->titulo);

    printf("Nome do Autor: ");
        scanf(" %[^\n]", biblioteca[i]->autor.nome);

    printf("Data de Nascimento do Autor (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &biblioteca[i]->autor.data_nascimento.dia, &biblioteca[i]->autor.data_nascimento.mes, &biblioteca[i]->autor.data_nascimento.ano);

    printf("Data de Escrita do Livro (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &biblioteca[i]->data_escrita.dia, &biblioteca[i]->data_escrita.mes, &biblioteca[i]->data_escrita.ano);
}

void deletarLivro(LivroMagico **biblioteca, int idBusca){
    int i;
    int flag = 0;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        if(biblioteca[i] != NULL && biblioteca[i]->id == idBusca){
            free(biblioteca[i]);
            biblioteca[i] = NULL; 
            flag = 1;
            printf("Livro Deletado com Sucesso!\n");
        } 
    }
    if(flag == 0){
        printf("ID Nao Encontrado...\n");
    }
}

