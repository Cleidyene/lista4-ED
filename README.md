# Trabalho 4 — Sistema de Autocomplete de Jogos com Trie

## Descrição

Sistema de autocomplete de jogos implementado em C++ utilizando a estrutura de dados **Trie**. Dado um prefixo e um inteiro `k`, o sistema retorna até `k` jogos cujo título começa com esse prefixo, ordenados por popularidade. Em caso de empate, a ordenação é feita pela chave de busca do título, em ordem alfabética.

## Organização dos arquivos

```
main.cpp          — programa principal; lê argumentos e executa a busca
Game.hpp / .cpp   — classe Game (título | descrição | popularidade)
Trie.hpp / .cpp   — classes TrieNode e Trie com seus respectivos métodos
GamesDatabase.hpp — declaração do array de jogos e numberOfGames
GamesDatabase.cpp — definição da lista inicial de jogos
```

## Compilação

O programa pode ser executado através do comando:

```
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```

## Execução

Para executar, utilize o comando: 

```
./app k prefixo
```

Onde `k` é número máximo de sugestões a retornar e `prefixo` é o prefixo usado na busca (entre aspas se contiver espaços)

## Exemplos de uso

```bash
./app 3 ha
```
Halo The Master Chief Collection | The Master Chief s iconic journey includes six games built for PC and collected in a single integrated experience Whether you re a long time fan or meeting Spartan 117 for the first time The Master Chief Collection is the definitive Halo gaming experience | 192219
Halo Infinite | The legendary Halo series returns with the most expansive Master Chief campaign yet and a ground breaking free to play multiplayer experience | 160647


```bash
./app 3 zelda
```
# No results found

./app 0 ha
# No results found
```

A busca é case-insensitive e ignora espaços em branco, portanto os prefixos `"ha"`, `"HA"` e `"Ha"` são equivalentes, assim como `"halflife"`, `"half life"` e `"HALF L"`.
