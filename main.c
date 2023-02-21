#include <stdio.h>
#include <string.h>
#include "trie.h"
#include "utils.h"
#include "opcoes.h"

int main(int argc, string argv[])
{

    if (strcmp(argv[1], "--freq") == 0)
    {
        frequecianPalavras(argv);
    }
    else if (strcmp(argv[1], "--freq-word") == 0)
    {
        frequeciaPalavra(argv[3], argv[2]);
    }
    else if (strcmp(argv[1], "--search") == 0)
    {
        search(argc, argv);
    }
    else
    {
        printf("Erro na entrada dos parametros\n");
    }
}
