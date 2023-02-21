#include <assert.h>
#include <ctype.h>
#include "utils.h"

void palavraParaMinusculo(char palavra[64])
{
    int i = 0;
    int j = 0;
    char c;
    while ((c = palavra[i]) != '\0')
    {
        if (isalpha(c))
        {
            palavra[j] = tolower(c);
            j++;
        }
        i++;
    }
    palavra[j] = '\0';
}

char **separacaoString(char *termo, const char delimitador)
{
    char **result = NULL;
    size_t count = 0;
    char *token;

    while ((token = strsep(&termo, &delimitador)) != NULL)
    {
        if (*token != '\0')
        {
            result = realloc(result, sizeof(char *) * (++count));
            result[count - 1] = strdup(token);
        }
    }

    result = realloc(result, sizeof(char *) * (++count));
    result[count - 1] = NULL;

    return result;
}

double calcularTF(int qtd, int totalPalavras)
{
    if (totalPalavras == 0)
        return 0;

    return (double)qtd / (double)totalPalavras;
}

double calcularIDF(int totalArquivos, int totalArquivosPalavras)
{
    if (totalArquivosPalavras == 0)
    {
        return 0.0;
    }
    double x = (double)totalArquivos / totalArquivosPalavras;
    double idf = log10(x);
    return idf;
}

double calcularTFIDF(int qtd, int totalPalavras, int totalArquivos, int totalArquivosPalavras)
{
    double tf = calcularTF(qtd, totalPalavras);
    double idf = calcularIDF(totalArquivos, totalArquivosPalavras);
    return tf * idf;
}
