#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    int endwith=0;
    int prefix=0;

    bool containsKey(char c)
    {
        return (links[c-'a']!=NULL);
    }
    Node* putNode(char c, Node* node)
    {
        link[c-'a']=node;
    }
    Node* getNode(char c)
    {
        return link[c-'a'];
    }
    void increasePrefix()
    {
        prefix++;
    }
    void increaseEndwith()
    {
        endwith++;
    }
    int showPrefix()
    {
        return prefix;
    }
    int showEndwith()
    {
        return endwith;
    }
    void deletePrefix()
    {
        prefix--;
    }
    void deleteEndwith()
    {
        endwith--;
    }
};
class Trie{
    private: Node* root;

    public:

    Trie(){
        // Write your code here.
        root= new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->putNode(word[i], new Node());
            }
            node = node->getNode();
            node->increasePrefix();
        }
        node->increaseEndwith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->getNode();
        }
        return node->showEndwith();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->getNode();
        }
        return node->showPrefix();
    }

    void erase(string &word){
        // Write your code here.
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return;
            }
            node = node->getNode();
            node->deletePrefix();
        }
        node->deleteEndwith();
    }
};
