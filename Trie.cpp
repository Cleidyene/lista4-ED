#include "Trie.hpp"

TrieNode::TrieNode(){
    for(int i = 0; i < ALPHABET_SIZE; i++){
        children[i] = nullptr;
    }

    isEndOfTitle = false;
    game = nullptr;
}

TrieNode::~TrieNode(){
}

Trie::Trie(){
    root = new TrieNode();
}

Trie::~Trie(){
}

std::string Trie::toSearchKey(std::string text){
    std::string resultado = "";
    for (size_t i = 0; i < text.size(); ++i) {
        char c = text[i];
        if(c == ' '){
            continue;
        }

        if(c >= 65 && c <= 90){
            c = c + 32;
        }

        resultado += c;
}

return resultado;
}

bool Trie::insert(Game* game){
std::string key = toSearchKey(game->getTitle());
TrieNode* current = root;

for(int i = 0; i < key.size(); i++){
    int index = charToIndex(key[i]);
    if(current->children[index] == nullptr){
        TrieNode* no = new TrieNode();
        current->children[index] = no;
    }
    current = current->children[index];
}
current->isEndOfTitle = true;
current->game = game;


return true;
}

int Trie::chartoindex(char c)
{
    if (c >= 97 && c <= 122)
    {
        return c - 97;
    }
    if (c >= 48 && c <= 57)
    {

        return 26 + (c - 48);
    }
    return -1;
}

bool Trie::contains(std::string title){
std::string key = toSearchKey(title);
TrieNode* current = root;

for(int i = 0; i < key.size(); i++){
    int index = charToIndex(key[i]);

    if(current->children[index] == nullptr){
        return false;
    }
    current = current->children[index];
}

if(current->isEndOfTitle == false){
    return false;
}

return true;
}

void Trie::merge(std::vector<Game *> &games, int left, int mid, int right)
{
    int size = right - left + 1;
    Game **temp = new Game *[size];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        int popA = games[i]->getPopularity();
        int popB = games[j]->getPopularity();

        bool comesfirst;
        if (popA != popB)
        {
            comesfirst = popA > popB;
        }
        else
        {
            std::string keyA = toSearchKey(games[i]->getTitle());
            std::string keyB = toSearchKey(games[j]->getTitle());
            comesfirst = keyA <= keyB;
        }

        if (comesfirst)
        {
            temp[k++] = games[i++];
        }
        else
        {
            temp[k++] = games[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = games[i++];
    }
    while (j <= right)
    {
        temp[k++] = games[j++];
    }

    for (int k = 0; k < size; k++)
        games[left + k] = temp[k];

    delete[] temp;
}

void Trie::mergeSort(std::vector<Game *> &games, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(games, left, mid);
    mergeSort(games, mid + 1, right);
    merge(games, left, mid, right);
}

void Trie::sortResults(std::vector<Game *> &games)
{
    int n = (int)games.size() - 1;
    mergeSort(games, 0, n);
}

void Trie::collectGames(TrieNode *node, std::vector<Game *> &results)
{
    if (node == nullptr)
        return;

    if (node->isEndOfTitle && node->game != nullptr)
    {
        results.push_back(node->game);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] != nullptr)
        {
            collectGames(node->children[i], results);
        }
    }
}

std::vector<Game *> Trie::autocomplete(std::string prefix, int k)
{
    std::vector<Game *> results;

    if (k <= 0)
        return results;

    std::string key = toSearchKey(prefix);
    TrieNode *current = root;

    for (int i = 0; i < (int)key.size(); i++){
        int index = charToIndex(key[i]);

    if (current->children[idx] == nullptr){
        return results;
    }

    current = current->children[idx];
}

    collectGames(current, results);
    sortResults(results);

    if ((int)results.size() > k)
    {
        results.resize(k);
    }

    return results;
}

