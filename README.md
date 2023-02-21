# INDEXER - TRABALHO FINAL ED2

## INTEGRANTES DO GRUPO

- José Mande Chingulo
- Mateus Irineu Mallmann
- Matheus Alves Chaves

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
