#include "trie.h"

#define converterIndex(c) ((int)c - (int)'a')

node *novoNo(void)
{
    node *pNode = NULL;
    pNode = (node *)malloc(sizeof(node));
    if (pNode)
    {
        int i;
        pNode->isFinalWord = false;
        for (i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

bool pesquisaComContagem(string palavra, node *trie, int *repeat)
{
    int tamanhoPalavra = strlen(palavra);
    int index;
    node *noTrie = trie;

    for (int altura = 0; altura < tamanhoPalavra; altura++)
    {
        index = converterIndex(palavra[altura]);
        if (!noTrie->children[index])
        {
            return false;
        }
        noTrie = noTrie->children[index];
    }

    *repeat = noTrie->count;
    return noTrie->isFinalWord;
}

int contadorPalavrasTotal(node *trieBusca)
{
    int total = 0;
    if (trieBusca->isFinalWord)
    {
        total += trieBusca->count;
    }
    for (int i = 0; i < 26; i++)
    {
        node *child = trieBusca->children[i];
        if (child != NULL)
        {
            total += contadorPalavrasTotal(child);
        }
    }
    return total;
}

int contadorPalavras(node *trieBusca, char *termo)
{
    if (trieBusca == NULL)
        return 0;
    node *atual = trieBusca;

    while (*termo)
    {
        atual = atual->children[*termo - 'a'];
        if (atual == NULL)
            return 0;
        termo++;
    }
    return atual->count;
}

void inserirTrie(string palavra, node *trie)
{
    int tamanhoPalavra = strlen(palavra);
    int index;

    node *noTrie = trie;

    for (int altura = 0; altura < tamanhoPalavra; altura++)
    {
        index = converterIndex(palavra[altura]);
        if (!noTrie->children[index])
        {
            noTrie->children[index] = novoNo();
        }
        noTrie = noTrie->children[index];
    }

    if (!noTrie->isFinalWord)
    {
        noTrie->isFinalWord = true;
        noTrie->count = 1;
    }
    else
    {
        noTrie->count++;
    }
}
void geraTrieArquivo(string nomeArquivo, node *trieBusca, int n, PalavrasFiltradas *tops)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    char buffer[512];
    while (fscanf(arquivo, "%s", buffer) != EOF)
    {
        if (strlen(buffer) < 2)
        {
            continue;
        }

        palavraParaMinusculo(buffer);
        inserirTrie(buffer, trieBusca);

        if (strlen(buffer) >= 2)
        {
            int count = contadorPalavras(trieBusca, buffer);

            for (int i = 0; i < n; i++)
            {
                if (count <= tops[i].count)
                {
                    continue;
                }

                tops[i].count = count;
                strcpy(tops[i].word, buffer);
                break;
            }
        }
    }

    fclose(arquivo);
}
