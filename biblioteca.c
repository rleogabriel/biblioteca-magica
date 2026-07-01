#include "biblioteca.h"
#include <stdlib.h>
#include <string.h>
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
            break;
        } 
    }
    if(flag == 0){
        printf("\nO livro com o id: %d nao foi encontrado...\n\n", idBusca);
    }
}

void mostrarLivro(LivroMagico **biblioteca, int idBusca) {
    int i;
    int flag = 0;
    for (i = 0; i < MAX_LIVROS; i++) 
    {
        if (biblioteca[i] != NULL && biblioteca[i]->id == idBusca) {
            printf("\n");
            printf("======================================================\n");
            printf("             📖 INFORMACOES DO LIVRO 📖              \n");
            printf("======================================================\n");
            printf(" [ID]           : %04d\n", biblioteca[i]->id);
            printf(" [Titulo]       : %s\n", biblioteca[i]->titulo);
            printf(" [Autor]        : %s\n", biblioteca[i]->autor.nome);
            printf(" [Nasc. Autor]  : %02d/%02d/%04d\n", biblioteca[i]->autor.data_nascimento.dia, biblioteca[i]->autor.data_nascimento.mes, biblioteca[i]->autor.data_nascimento.ano);
            printf(" [Data Escrita] : %02d/%02d/%04d\n", biblioteca[i]->data_escrita.dia, biblioteca[i]->data_escrita.mes, biblioteca[i]->data_escrita.ano);
            printf("======================================================\n\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("\nO livro com o id: %d nao foi encontrado...\n\n", idBusca);
    }
}

void editarLivro(LivroMagico **biblioteca, int idBusca){
    int i, escolha;
    char nome[100];
    Data antiga;
    int flag = 0;
    for (i = 0; i < MAX_LIVROS; i++) 
    {
        if (biblioteca[i] != NULL && biblioteca[i]->id == idBusca) {
            printf("==========================================\n");
            printf("||          Alteracao de Dados          ||\n");
            printf("==========================================\n");
            printf("||                                      ||\n");
            printf("||  1. [Nome do Livro]                  ||\n");
            printf("||  2. [Nome do Autor]                  ||\n");
            printf("||  3. [Data de Nascimento do Autor]    ||\n");
            printf("||  4. [Data do Livro]                  ||\n");
            printf("||  5. [Voltar]                         ||\n");
            printf("||                                      ||\n");
            printf("==========================================\n");
            printf("Qual informacao deseja modificar meu Lorde?\n");
            scanf("%d", &escolha);

        switch (escolha)
    {
    case 1:
            strcpy(nome, biblioteca[i]->titulo);
            printf("Digite o nome do livro que deseja colocar:");
            scanf(" %[^\n]", biblioteca[i]->titulo);
            printf("\n");
            printf("======================================================\n");
            printf("             ♻ INFORMACOES ALTERADAS ♻               \n");
            printf("======================================================\n");
            printf(" [Titulo Antigo] : %s\n", nome);
            printf(" [Titulo Novo]   : %s\n", biblioteca[i]->titulo);
            printf("======================================================\n\n");
        break;
    case 2:
    strcpy(nome, biblioteca[i]->autor.nome);
            printf("Digite o nome do autor que deseja colocar:");
            scanf(" %[^\n]", biblioteca[i]->autor.nome);
            printf("\n");
            printf("======================================================\n");
            printf("             ♻ INFORMACOES ALTERADAS ♻               \n");
            printf("======================================================\n");
            printf(" [Autor Antigo] : %s\n", nome);
            printf(" [Autor Novo]   : %s\n", biblioteca[i]->autor.nome);
            printf("======================================================\n\n");
        break;
    case 3:
        antiga.dia = biblioteca[i]->autor.data_nascimento.dia;
        antiga.mes = biblioteca[i]->autor.data_nascimento.mes;
        antiga.ano = biblioteca[i]->autor.data_nascimento.ano;
            printf("Digite a nova data de nascimento do autor: (Formato: DD/MM/AAAA)");
            scanf("%d/%d/%d", &biblioteca[i]->autor.data_nascimento.dia, &biblioteca[i]->autor.data_nascimento.mes, &biblioteca[i]->autor.data_nascimento.ano);
            printf("\n");
            printf("======================================================\n");
            printf("             ♻ INFORMACOES ALTERADAS ♻               \n");
            printf("======================================================\n");
            printf(" [Data antiga] : %02d/%02d/%04d\n", antiga.dia, antiga.mes, antiga.ano);
            printf(" [Data Nova]   : %02d/%02d/%04d\n", biblioteca[i]->autor.data_nascimento.dia, biblioteca[i]->autor.data_nascimento.mes, biblioteca[i]->autor.data_nascimento.ano);
            printf("======================================================\n\n");
        break;
    case 4:
    antiga.dia = biblioteca[i]->data_escrita.dia;
        antiga.mes = biblioteca[i]->data_escrita.mes;
        antiga.ano = biblioteca[i]->data_escrita.ano;
            printf("Digite a nova data do livro (Formato: DD/MM/AAAA)");
            scanf("%d/%d/%d", &biblioteca[i]->data_escrita.dia, &biblioteca[i]->data_escrita.mes, &biblioteca[i]->data_escrita.ano);
            printf("\n");
            printf("======================================================\n");
            printf("             ♻ INFORMACOES ALTERADAS ♻               \n");
            printf("======================================================\n");
            printf(" [Data antiga] : %02d/%02d/%04d\n", antiga.dia, antiga.mes, antiga.ano);
            printf(" [Data Nova]   : %02d/%02d/%04d\n", biblioteca[i]->data_escrita.dia, biblioteca[i]->data_escrita.mes, biblioteca[i]->data_escrita.ano);
            printf("======================================================\n\n");
        break;
    case 5:
    return;
        break;
    }
    flag = 1; 
    break;
    }
    }
    if (flag == 0) {
        printf("\nO livro com o id: %d nao foi encontrado...\n\n", idBusca);
    }
}

