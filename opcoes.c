#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opcoes.h"
#include "trie.h"

void frequecianPalavras(string vet[])
{
    node *trie = novoNo();
    int qtd = strtol(vet[2], NULL, 10);
    PalavrasFiltradas *ranking = (PalavrasFiltradas *)malloc(sizeof(PalavrasFiltradas) * (qtd));
    geraTrieArquivo(vet[3], trie, qtd, ranking);
    printf("%d termos com mais relevancia no arquivo:\n\n", qtd);
    for (int i = 0; i < qtd; i++)
    {
        printf("%dº | %s | %.0f vezes\n", i + 1, ranking[i].word, ranking[i].count);
    }
}

void frequeciaPalavra(string nomeArquivo, string termoBusca)
{

    FILE *arquivo;
    char buffer[512];
    char *palavra;
    node *trie = novoNo();
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(0);
    }
    else
    {
        while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
        {
            buffer[strcspn(buffer, "\n")] = '\0';
            for (palavra = strtok(buffer, " "); palavra != NULL; palavra = strtok(NULL, " "))
            {
                palavraParaMinusculo(palavra);
                inserirTrie(palavra, trie);
            }
        }
    }
    int frequeciaEncontrada;

    if (pesquisaComContagem(termoBusca, trie, &frequeciaEncontrada))
    {
        printf("A palavra '%s' apareceu %d vezes nesse arquivo!\n", termoBusca, frequeciaEncontrada);
    }
    else
    {
        printf("Palavra '%s' não existe no arquivo!\n", termoBusca);
    }
    fclose(arquivo);
}

void search(int cont_args, string vet[])
{
    int qtdArquivos = (cont_args - 3);
    int qtd_termos = 0;
    node **trieBusca = malloc(sizeof(node) * qtdArquivos);

    PalavrasFiltradas *relavanciaArq;
    relavanciaArq = (PalavrasFiltradas *)malloc(sizeof(PalavrasFiltradas) * (qtdArquivos));

    char **termos;
    termos = separacaoString(vet[2], ' ');
    for (int i = 0; *(termos + i); i++)
        qtd_termos++;

    int palavrasTermo = 1;
    for (int i = 0; *(termos + i); i++)
    {
        palavrasTermo++;
    }

    int **arquivosPalavras = malloc(sizeof(int *) * qtdArquivos);
    for (int i = 0; i < qtdArquivos + 2; i++)
    {
        arquivosPalavras[i] = malloc(sizeof(int *) * palavrasTermo);
    }

    for (int i = 0; i < qtdArquivos; i++)
    {
        trieBusca[i] = novoNo();
        FILE *f;
        f = fopen(vet[i + 3], "r");
        if (f == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(0);
        }
        else
        {
            char *palavra;
            char buffer[512];
            while (fgets(buffer, sizeof(buffer), f) != NULL)
            {
                palavra = strtok(buffer, " ");
                while (palavra != NULL)
                {
                    palavraParaMinusculo(palavra);
                    inserirTrie(palavra, trieBusca[i]);
                    palavra = strtok(NULL, " ");
                }
            }
        }

        if (termos != NULL)
        {
            for (int j = 0; termos[j] != NULL; j++)
            {
                int value;
                pesquisaComContagem(termos[j], trieBusca[i], &value);
                if (value > 0)
                {
                    arquivosPalavras[i][j]++;
                }
            }
        }
        strcpy(relavanciaArq[i].word, vet[i + 3]);
    }

    for (int i = 0; i < qtdArquivos; i++)
    {
        int qtdPalavras = contadorPalavrasTotal(trieBusca[i]);
        relavanciaArq[i].count = 0;
        if (termos)
        {
            for (int j = 0; *(termos + j); j++)
            {
                int count = contadorPalavras(trieBusca[i], *(termos + j));
                relavanciaArq[i].count += calcularTFIDF(count, qtdPalavras, qtdArquivos,
                                                        arquivosPalavras[i][j]);
            }
        }
        relavanciaArq[i].count =
            ((double)relavanciaArq[i].count / qtd_termos) * 100;
    }

    for (int i = 0; i < qtdArquivos; i++)
    {
        printf("O calculo de relevancia TFIDF do arquivo '%s' é de:  %f%% \n", relavanciaArq[i].word,
               relavanciaArq[i].count);
    }
}