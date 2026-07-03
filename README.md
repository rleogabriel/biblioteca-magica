# Biblioteca Mágica

Mini Projeto 03 desenvolvido em linguagem C para a disciplina de programação.

O projeto simula o backend de um jogo de RPG, responsável pelo gerenciamento do inventário de uma Biblioteca Mágica. O sistema permite cadastrar, listar, mostrar, editar e deletar livros mágicos, utilizando structs, ponteiros, alocação dinâmica e manipulação de arquivos.

## Integrantes

- Leandro Gabriel
- Pedro Facundo
- Rodrigo Rodrigues

## Link do Repositório

[GitHub do Projeto](https://github.com/rleogabriel/biblioteca-magica)

## Vídeo de Apresentação

O vídeo de apresentação demonstra o funcionamento do sistema, incluindo o uso do menu, cadastro, listagem, edição, exclusão, salvamento e carregamento dos livros cadastrados.

[Assistir vídeo de apresentação no YouTube](https://youtu.be/xQJhtpNVRdE)

## Funcionalidades

O sistema possui as seguintes funcionalidades principais:

1. Cadastrar livro mágico
2. Deletar livro pelo ID
3. Mostrar informações completas de um livro pelo ID
4. Editar informações de um livro pelo ID
5. Listar títulos dos livros cadastrados
6. Salvar e sair do sistema

Além das funcionalidades obrigatórias, o projeto também possui um sistema de **raridade dos livros**, permitindo classificar cada livro mágico de acordo com sua importância dentro do inventário.

## Estruturas utilizadas

O projeto utiliza as seguintes estruturas principais:

- `Data`: armazena dia, mês e ano.
- `Autor`: armazena o nome do autor e sua data de nascimento.
- `LivroMagico`: armazena ID, título, autor, data de escrita e raridade do livro.

## Organização do Projeto

```text
biblioteca-magica/
│
├── main.c
├── biblioteca.c
├── biblioteca.h
├── biblioteca.txt
├── README.md
├── .gitignore
└── .gitattributes
```

### Descrição dos arquivos

- `main.c`: contém a função principal do programa, responsável por iniciar o sistema, receber o arquivo por parâmetro e controlar o menu principal.
- `biblioteca.h`: contém as definições das structs, constantes e protótipos das funções.
- `biblioteca.c`: contém a implementação das funções de cadastro, listagem, edição, exclusão, salvamento, carregamento e criptografia.
- `biblioteca.txt`: arquivo utilizado para armazenar os dados dos livros cadastrados.
- `README.md`: arquivo de documentação do projeto.

## Como compilar

No terminal, dentro da pasta do projeto, execute:

```bash
gcc main.c biblioteca.c -o programa_biblioteca
```

## Como executar

Após compilar, execute o programa passando o nome do arquivo de dados como parâmetro:

```bash
./programa_biblioteca biblioteca.txt
```

O arquivo `biblioteca.txt` é utilizado para salvar e carregar os livros cadastrados.

## Exemplo de uso

Ao executar o programa, será exibido um menu com as opções disponíveis:

```text
1. Cadastrar novo livro mágico
2. Deletar livro
3. Mostrar livro
4. Editar livro
5. Listar títulos
6. Salvar e sair
```

O usuário deve escolher uma opção e seguir as instruções exibidas no terminal.

## Salvamento e carregamento

O sistema salva os livros cadastrados no arquivo informado na execução do programa.

Exemplo:

```bash
./programa_biblioteca biblioteca.txt
```

Ao iniciar, o programa tenta carregar os dados existentes no arquivo `biblioteca.txt`.

Ao escolher a opção de sair, o programa salva automaticamente os dados atuais no mesmo arquivo.

## Criptografia

Antes de salvar os dados no arquivo, o título de cada livro é criptografado utilizando o método de complemento de 255.

A lógica utilizada é:

```text
caractere criptografado = 255 - caractere original
```

A mesma operação é usada para descriptografar o título quando os dados são carregados novamente para a memória.

## Conceitos aplicados

Neste projeto foram utilizados os seguintes conceitos da linguagem C:

- Structs
- Ponteiros
- Vetor de ponteiros
- Alocação dinâmica com `malloc`
- Liberação de memória com `free`
- Manipulação de arquivos com `fopen`, `fprintf`, `fscanf` e `fclose`
- Passagem de parâmetros pela função `main`
- Criptografia simples de strings
- Organização do código em arquivos `.c` e `.h`

## Observações

- A identificação dos livros é feita pelo `id`, e não pela posição no vetor.
- O vetor principal possui 100 posições.
- Cada posição pode conter um ponteiro para um `LivroMagico` ou `NULL`, indicando que o espaço está vazio.
- Ao deletar um livro, a memória é liberada e a posição volta a receber `NULL`.
- Ao encerrar o programa, a memória alocada dinamicamente é liberada.