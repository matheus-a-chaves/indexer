# INDEXER - TRABALHO FINAL ED2

## INTEGRANTES DO GRUPO

- José Mande Chingulo
- Mateus Irineu Mallmann
- Matheus Alves Chaves

DESCRIÇÃO do Programa 
    O nosso programa tem como função realizar uma contagem de palavras em documentos de  texto. Onde a partir dessa contagem, ele ainda permite uma busca pelo número de  ocorrências de uma palavra específica em um documento, ou a seleção de  documentos relevantes para um dado termo de busca.  O programa transforma todas as letras para minúsculas e ignora caracteres como números e pontuações na hora da execução.
    
O programa possui três opçøes de execução:
1 - O programa exibe o número de de ocorrências das N palavras mais frequentes no documento passado  como parâmetro, em ordem decrescente de ocorrências.
2 - O programa exibe a contagem de uma palavra específica no documento passado como parâmetro.
3 - O programa apresenta uma listagem dos documentos mais relevantes para um dado termo de busca. Para esse tipo de ecuxão, o programa utiliza o cálculo TF-IDF (Term Frequency-Inverse Document Frequency).

## 🚀 COMPILANDO

Rode os seguintes comandos :

Linux:

```
gcc -g main.c trie.c utils.c opcoes.c -o indexer -lm
```

## ☕ EXECUÇÃO

Caso queira ver quais palavras aparecem mais no arquivo:

```
./indexer --freq N nome_do_arquivo.txt
```

- N -> quantidade de palavras que serão rankeadas, substitua por um numero.

---

Caso procurar por uma palavra dentro do arquivo:

```
./indexer --freq-word PALAVRA nome_do_arquivo.txt
```

---

Caso queira o calculo de relevância de um termo comparando com varios arquivos:

```
./indexer --search 'termo desejado' nome_do_arquivo.txt nome_do_arquivo2.txt
```

- Colorcar o termo entre aspas simples.
