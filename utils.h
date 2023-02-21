#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#ifndef INDEXER_UTILS_H
#define INDEXER_UTILS_H

#endif

typedef char *string;

void palavraParaMinusculo(char palavra[64]);

char **separacaoString(char *termo, const char delimitador);

double calcularTF(int qtd, int totalPalavras);

double calcularIDF(int totalArquivos, int totalArquivosPalavras);

double calcularTFIDF(int qtd, int totalPalavras, int totalArquivos, int totalArquivosPalavras);
