# LINK DO GITHUB : 
https://github.com/rleogabriel/biblioteca-magica

# 📖 Inventário da Biblioteca Mágica (RPG Backend)

Este projeto é um sistema em **C** desenvolvido para atuar como o backend do inventário de uma Biblioteca Mágica em um jogo de RPG. O sistema gerencia, cadastra e armazena os atributos de diversos tomos e livros arcanos coletados pelo jogador durante a campanha.

O grande diferencial deste grimório é o seu sistema de **"Save Game" persistente**, garantindo que nenhum item se perca ao fechar o jogo, lendo e gravando os dados diretamente no disco, além de possuir um feitiço de **criptografia** para proteger os títulos dos livros no arquivo de salvamento.

---

## ⚙️ Tecnologias e Conceitos Aplicados

O projeto foi construído respeitando as seguintes estruturas da linguagem C:
* **Structs:** Modelagem de entidades complexas (`Data`, `Autor` e `LivroMagico`).
* **Vetor de Ponteiros:** Gerenciamento central do inventário através de um vetor de 100 posições (`MAX_LIVROS`).
* **Alocação Dinâmica:** Uso de `malloc` e `free` para instanciar apenas os slots de memória necessários, otimizando recursos.
* **Manipulação de Arquivos (I/O):** Leitura (`r`) e escrita (`w`) para a persistência dos dados do jogador.
* **Criptografia Simétrica:** Implementação de cifra utilizando o método de *Complemento de 255* para ofuscar as strings de título no arquivo de texto.

---

## 🛠️ Funcionalidades do Sistema

Através de uma interface temática executada no terminal, o jogador tem acesso às seguintes opções:

1. **Cadastrar Livro:** Aloca dinamicamente um novo espaço e armazena dados como ID, Título, Autor e Datas (Nascimento/Escrita).
2. **Deletar Livro:** Busca um livro pelo seu ID exclusivo, libera a memória (`free`) e limpa a prateleira.
3. **Mostrar Livro:** Exibe de forma formatada e detalhada todas as informações de um item específico.
4. **Editar Livro:** Permite a transmutação (alteração) de dados individuais de um registro já existente.
5. **Listar Títulos:** Itera o inventário imprimindo todos os IDs e Títulos atualmente armazenados.
6. **Sair e Salvar:** Grava o progresso no arquivo `.txt` informado via linha de comando, aplicando a criptografia antes de encerrar.

---

link do github: 

## 🚀 Como Compilar e Executar

Este programa exige a passagem do nome do arquivo de *save* via **Parâmetro de Linha de Comando** na execução.

### 1. Compilação
Recomenda-se compilar os módulos `.c` juntos utilizando o `gcc`:
```bash
gcc main.c biblioteca.c -o programa_biblioteca