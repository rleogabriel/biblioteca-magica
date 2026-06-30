#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#define MAX_LIVROS 100

// Structs

typedef struct {
	int dia;
    int mes;
    int ano;
} Data;

typedef struct {
	char nome[100];
    Data data_nascimento;
} Autor;

typedef struct {
	int id;
    char titulo[100];
    Autor autor;
    Data data_escrita;
} LivroMagico;

// Protótipos das funções

void menu();
void inicializarVetor(LivroMagico **biblioteca);
void cadastrarLivro(LivroMagico **biblioteca);
void deletarLivro(LivroMagico **biblioteca, int id);
void mostrarLivro(LivroMagico **biblioteca, int id);
void editarLivro(LivroMagico **biblioteca, int id);
void listarTitulos(LivroMagico **biblioteca);
void salvarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo);
void carregarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo);
void criptografar(char* str);
void descriptografar(char* str);

#endif