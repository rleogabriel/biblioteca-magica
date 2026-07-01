#include "biblioteca.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void menu(LivroMagico **biblioteca) {
    int i, ocupados = 0;
    for(i = 0; i < MAX_LIVROS; i++) {
        if(biblioteca[i] != NULL) ocupados++;
    }

    printf("\n");
    printf(AMARELO "=====================================================\n" RESET);
    printf(AMARELO "||" CIANO "             * INVENTARIO MAGICO *               " AMARELO "||\n" RESET);
    printf(AMARELO "||" CIANO "           Biblioteca Magica de RPG              " AMARELO "||\n" RESET);
    printf(AMARELO "=====================================================\n" RESET);
    printf(AMARELO "||  Status do Grimorio: " CIANO "[%02d/%02d slots]             " AMARELO "||\n" RESET, ocupados, MAX_LIVROS);
    printf(AMARELO "||                                                 ||\n" RESET);
    printf(AMARELO "||" RESET "  1. [Cadastrar] Novo Livro Magico               " AMARELO "||\n" RESET);
    printf(AMARELO "||" RESET "  2. [Deletar]   Incinerar Registro de Livro     " AMARELO "||\n" RESET);
    printf(AMARELO "||" RESET "  3. [Mostrar]   Inspecionar Detalhes do Livro   " AMARELO "||\n" RESET);
    printf(AMARELO "||" RESET "  4. [Editar]    Alterar Atributos do Livro      " AMARELO "||\n" RESET);
    printf(AMARELO "||" RESET "  5. [Listar]    Ver Catalogo de Titulos         " AMARELO "||\n" RESET);
    printf(AMARELO "||" VERMELHO "  6. [Sair]      Salvar e Fechar o Inventario    " AMARELO "||\n" RESET);
    printf(AMARELO "||                                                 ||\n" RESET);
    printf(AMARELO "=====================================================\n" RESET);
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
    int i, j;
    int idTemporario;
    int flag = 0;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        if(biblioteca[i] == NULL){
            biblioteca[i] = (LivroMagico*) malloc(sizeof(LivroMagico));
            flag = 1;
            break;
        } 
    }
    if(flag == 0) {
        printf(VERMELHO "Inventario Cheio\n" RESET);
        return;
    }
    printf("\n");

        printf("ID do Livro: ");
        scanf("%d%*c", &idTemporario);

    for (j = 0; j < MAX_LIVROS; j++) {
        if (biblioteca[j] != NULL && j != i && biblioteca[j]->id == idTemporario) {
            printf(VERMELHO "Erro: Ja existe um livro registrado com o ID %d!\n" RESET, idTemporario);
            free(biblioteca[i]);
            biblioteca[i] = NULL;
            return; 
        }
    }
    biblioteca[i]->id = idTemporario;

    printf("Titulo do Livro: ");
        scanf(" %99[^\n]", biblioteca[i]->titulo);

    printf("Nome do Autor: ");
        scanf(" %99[^\n]", biblioteca[i]->autor.nome);

    printf("Data de Nascimento do Autor (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &biblioteca[i]->autor.data_nascimento.dia, &biblioteca[i]->autor.data_nascimento.mes, &biblioteca[i]->autor.data_nascimento.ano);

    printf("Data de Escrita do Livro (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &biblioteca[i]->data_escrita.dia, &biblioteca[i]->data_escrita.mes, &biblioteca[i]->data_escrita.ano);

printf("Raridade do Livro: ");
        scanf(" %29[^\n]", biblioteca[i]->raridade);
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
            printf(VERDE "Livro Deletado com Sucesso!\n" RESET);
            break;
        } 
    }
    if(flag == 0){
        printf(VERMELHO "\nO livro com o id: %d nao foi encontrado...\n\n" RESET, idBusca);
    }
}

void mostrarLivro(LivroMagico **biblioteca, int idBusca) {
    int i;
    int flag = 0;
    for (i = 0; i < MAX_LIVROS; i++) 
    {
        if (biblioteca[i] != NULL && biblioteca[i]->id == idBusca) {
            printf("\n");
            printf(CIANO "======================================================\n" RESET);
            printf(CIANO "                 INFORMACOES DO LIVRO                 \n" RESET);
            printf(CIANO "======================================================\n" RESET);
            printf(AMARELO " [ID]           : " RESET "%04d\n", biblioteca[i]->id);
            printf(AMARELO " [Titulo]       : " RESET "%s\n", biblioteca[i]->titulo);
            printf(AMARELO " [Autor]        : " RESET "%s\n", biblioteca[i]->autor.nome);
            printf(AMARELO " [Nasc. Autor]  : " RESET "%02d/%02d/%04d\n", biblioteca[i]->autor.data_nascimento.dia, biblioteca[i]->autor.data_nascimento.mes, biblioteca[i]->autor.data_nascimento.ano);
            printf(AMARELO " [Data Escrita] : " RESET "%02d/%02d/%04d\n", biblioteca[i]->data_escrita.dia, biblioteca[i]->data_escrita.mes, biblioteca[i]->data_escrita.ano);
            printf(AMARELO " [Raridade]     : " RESET "%s\n", biblioteca[i]->raridade);
            printf(CIANO "======================================================\n\n" RESET);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf(VERMELHO "\nO livro com o id: %d nao foi encontrado...\n\n" RESET, idBusca);
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
            printf(AMARELO "==========================================\n" RESET);
            printf(AMARELO "||          Alteracao de Dados          ||\n" RESET);
            printf(AMARELO "==========================================\n" RESET);
            printf(AMARELO "||                                      ||\n" RESET);
            printf(AMARELO "||" RESET "  1. [Nome do Livro]                  " AMARELO "||\n" RESET);
            printf(AMARELO "||" RESET "  2. [Nome do Autor]                  " AMARELO "||\n" RESET);
            printf(AMARELO "||" RESET "  3. [Data de Nascimento do Autor]    " AMARELO "||\n" RESET);
            printf(AMARELO "||" RESET "  4. [Data do Livro]                  " AMARELO "||\n" RESET);
            printf(AMARELO "||" RESET "  5. [Raridade do Livro]              " AMARELO "||\n" RESET);
            printf(AMARELO "||" VERMELHO "  6. [Voltar]                      " AMARELO "||\n" RESET);
            printf(AMARELO "||                                      ||\n" RESET);
            printf(AMARELO "==========================================\n" RESET);
            printf("Qual informacao deseja modificar meu Lorde?\n");
            scanf("%d", &escolha);

        switch (escolha)
    {
    case 1:
            strcpy(nome, biblioteca[i]->titulo);
            printf("Digite o nome do livro que deseja colocar:");
            scanf(" %99[^\n]", biblioteca[i]->titulo);
            printf("\n");
            printf(VERDE "======================================================\n" RESET);
            printf(VERDE "                INFORMACOES ALTERADAS                 \n" RESET);
            printf(VERDE "======================================================\n" RESET);
            printf(AMARELO " [Titulo Antigo] : " RESET "%s\n", nome);
            printf(AMARELO " [Titulo Novo]   : " RESET "%s\n", biblioteca[i]->titulo);
            printf(VERDE "======================================================\n\n" RESET);
        break;
    case 2:
            strcpy(nome, biblioteca[i]->autor.nome);
            printf("Digite o nome do autor que deseja colocar:");
            scanf(" %99[^\n]", biblioteca[i]->autor.nome);
            printf("\n");
            printf(VERDE "======================================================\n" RESET);
            printf(VERDE "                INFORMACOES ALTERADAS                 \n" RESET);
            printf(VERDE "======================================================\n" RESET);
            printf(AMARELO " [Autor Antigo] : " RESET "%s\n", nome);
            printf(AMARELO " [Autor Novo]   : " RESET "%s\n", biblioteca[i]->autor.nome);
            printf(VERDE "======================================================\n\n" RESET);
        break;
    case 3:
        antiga.dia = biblioteca[i]->autor.data_nascimento.dia;
        antiga.mes = biblioteca[i]->autor.data_nascimento.mes;
        antiga.ano = biblioteca[i]->autor.data_nascimento.ano;
            printf("Digite a nova data de nascimento do autor: (Formato: DD/MM/AAAA)");
            scanf("%d/%d/%d", &biblioteca[i]->autor.data_nascimento.dia, &biblioteca[i]->autor.data_nascimento.mes, &biblioteca[i]->autor.data_nascimento.ano);
            printf("\n");
            printf(VERDE "======================================================\n" RESET);
            printf(VERDE "                INFORMACOES ALTERADAS                 \n" RESET);
            printf(VERDE "======================================================\n" RESET);
            printf(AMARELO " [Data antiga] : " RESET "%02d/%02d/%04d\n", antiga.dia, antiga.mes, antiga.ano);
            printf(AMARELO " [Data Nova]   : " RESET "%02d/%02d/%04d\n", biblioteca[i]->autor.data_nascimento.dia, biblioteca[i]->autor.data_nascimento.mes, biblioteca[i]->autor.data_nascimento.ano);
            printf(VERDE "======================================================\n\n" RESET);
        break;
    case 4:
        antiga.dia = biblioteca[i]->data_escrita.dia;
        antiga.mes = biblioteca[i]->data_escrita.mes;
        antiga.ano = biblioteca[i]->data_escrita.ano;
            printf("Digite a nova data do livro (Formato: DD/MM/AAAA)");
            scanf("%d/%d/%d", &biblioteca[i]->data_escrita.dia, &biblioteca[i]->data_escrita.mes, &biblioteca[i]->data_escrita.ano);
            printf("\n");
            printf(VERDE "======================================================\n" RESET);
            printf(VERDE "                INFORMACOES ALTERADAS                 \n" RESET);
            printf(VERDE "======================================================\n" RESET);
            printf(AMARELO " [Data antiga] : " RESET "%02d/%02d/%04d\n", antiga.dia, antiga.mes, antiga.ano);
            printf(AMARELO " [Data Nova]   : " RESET "%02d/%02d/%04d\n", biblioteca[i]->data_escrita.dia, biblioteca[i]->data_escrita.mes, biblioteca[i]->data_escrita.ano);
            printf(VERDE "======================================================\n\n" RESET);
        break;
        case 5:
            strcpy(nome, biblioteca[i]->raridade);
            printf("Digite a raridade do livro que deseja colocar:");
            scanf(" %29[^\n]", biblioteca[i]->raridade);
            printf("\n");
            printf(VERDE "======================================================\n" RESET);
            printf(VERDE "                INFORMACOES ALTERADAS                 \n" RESET);
            printf(VERDE "======================================================\n" RESET);
            printf(AMARELO " [Raridade Antiga] : " RESET "%s\n", nome);
            printf(AMARELO " [Raridade Nova]   : " RESET "%s\n", biblioteca[i]->raridade);
            printf(VERDE "======================================================\n\n" RESET);
        break;

        case 6:
            return;

        default:
            printf(VERMELHO "Opcao invalida!\n" RESET);
        break;
    }
    flag = 1; 
    break;
    }
    }
    if (flag == 0) {
        printf(VERMELHO "\nO livro com o id: %d nao foi encontrado...\n\n" RESET, idBusca);
    }
}

void listarTitulos(LivroMagico **biblioteca){
    int i;
    int contador = 0;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        if (biblioteca[i] != NULL){
            printf(AMARELO "[Id]:" RESET " %d    " AMARELO "[Titulo]:" RESET " %s\n", biblioteca[i]->id, biblioteca[i]->titulo);
            contador++;
        }
    }
    printf(VERDE "Numero total de livros : %d\n" RESET, contador);
}

void criptografar(char* str){
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = (char)(255 - (unsigned char)str[i]);
    }
}

void descriptografar(char* str){
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = (char)(255 - (unsigned char)str[i]);
    }
}

void salvarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo){
    int i;
    FILE * arq = NULL;
    arq = fopen(nomeArquivo, "w");

    if(arq==NULL) {
		printf(VERMELHO "OH NAO! Houve um problema ao abrir o pergaminho meu rei!\n" RESET);
		return;
	}

    for (i = 0; i < MAX_LIVROS; i++)
    {
        if (biblioteca[i] != NULL){
            criptografar(biblioteca[i]->titulo);
            fprintf(arq, "%d\n", biblioteca[i]->id);
            fprintf(arq, "%s\n", biblioteca[i]->titulo);
            fprintf(arq, "%s\n", biblioteca[i]->autor.nome);
            
            fprintf(arq, "%d %d %d\n", 
                    biblioteca[i]->autor.data_nascimento.dia, 
                    biblioteca[i]->autor.data_nascimento.mes, 
                    biblioteca[i]->autor.data_nascimento.ano);
                    
            fprintf(arq, "%d %d %d\n", 
                    biblioteca[i]->data_escrita.dia, 
                    biblioteca[i]->data_escrita.mes, 
                    biblioteca[i]->data_escrita.ano);

            fprintf(arq, "%s\n", biblioteca[i]->raridade);

            descriptografar(biblioteca[i]->titulo);
        }
    }
    fclose(arq);
    printf(VERDE "\n Progresso salvo com sucesso no pergaminho : '%s'!\n" RESET, nomeArquivo);
}

void carregarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf(AMARELO "\nNenhum pergaminho de save encontrado. Iniciando um novo jogo!\n" RESET);
        return; 
    }

    int i = 0;
    int idTemp;

    while (i < MAX_LIVROS && fscanf(arq, "%d\n", &idTemp) == 1) {
        
        biblioteca[i] = (LivroMagico*) malloc(sizeof(LivroMagico));
        biblioteca[i]->id = idTemp;
        
        fscanf(arq, " %[^\n]\n", biblioteca[i]->titulo);
        fscanf(arq, " %[^\n]\n", biblioteca[i]->autor.nome);
        
        fscanf(arq, "%d %d %d\n", &biblioteca[i]->autor.data_nascimento.dia, &biblioteca[i]->autor.data_nascimento.mes, &biblioteca[i]->autor.data_nascimento.ano);
                                  
        fscanf(arq, "%d %d %d\n", &biblioteca[i]->data_escrita.dia, &biblioteca[i]->data_escrita.mes, &biblioteca[i]->data_escrita.ano);

         fscanf(arq, " %[^\n]\n", biblioteca[i]->raridade);

        descriptografar(biblioteca[i]->titulo);
        i++;
    }
    
    fclose(arq);
    printf(VERDE "\n Pergaminho carregado com sucesso! %d livro(s) restaurado(s)!\n " RESET, i);
}

void liberarBiblioteca(LivroMagico **biblioteca) {
    int i;
    for (i = 0; i < MAX_LIVROS; i++) {
        if (biblioteca[i] != NULL) {
            free(biblioteca[i]);
            biblioteca[i] = NULL;
        }
    }
}