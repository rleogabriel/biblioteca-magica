#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

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

#endif