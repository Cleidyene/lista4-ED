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
    int index = key[i];
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

bool Trie::contains(std::string title){
std::string key = toSearchKey(title);
TrieNode* current = root;

for(int i = 0; i < key.size(); i++){
    int index = key[i];

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

