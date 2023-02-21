#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

typedef char *string;

typedef struct node
{
    struct node *children[26];
    int count;
    bool isFinalWord;
} node;

typedef struct PalavrasFiltradas
{
    double count;
    char word[64];
} PalavrasFiltradas;

node *novoNo(void);

void inserirTrie(string palavra, node *trie);

bool pesquisaComContagem(string palavra, node *trie, int *repeat);

void geraTrieArquivo(string nome, node *trieBusca, int n, PalavrasFiltradas *tops);

int contadorPalavras(node *trieBusca, char *termo);

int contadorPalavrasTotal(node *head);
