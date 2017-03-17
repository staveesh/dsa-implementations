#include <bits/stdc++.h>

using namespace std;

struct trie{
	int words;
	int prefixes;
	struct trie* edges[26];
};
void initialize(struct trie* vertex){
	vertex->words = 0;
	vertex->prefixes = 0;
	for(int i = 0; i < 26; i++)
		vertex->edges[i] = NULL;
}
void addWord(struct trie vertex, string word){
	if(word.empty())
		vertex.words += 1;
	else{
		vertex.prefixes += 1;
		char k = word.at(0);
		if(!vertex.edges[k]){
			edges[k] = (struct trie*)malloc(sizeof(trie));
			initialize(edges[k]);
		}
		string sub = word.substr(1);
		addWord(edges[k],sub);
	}
}
int main(){

	return 0;
}