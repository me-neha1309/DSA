#include <bits/stdc++.h>
using namespace std;

struct Trienode{
    char data;
    int wc;
    Trienode *child[26];
};

Trienode nodepool[100000]; //pool of 100k trienodes
Trienode *root;            //root of trienode
int poolcount;             //always points to next free Trienode

void init(){                // initializer function
    poolcount = 0;
    root = &nodepool[poolcount++];
    root->data = '/';
    for(int i=0; i<26; i++)
        root->child[i] = NULL;
} 

Trienode *getNode(char c){
    Trienode *newnode = &nodepool[poolcount++];
    newnode->data = c;
    for(int i=0; i<26; i++)
        newnode->child[i] = NULL;
    newnode->wc = 0;
    return newnode;
}

void insert(char *s){
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; i++){
        index = s[i] - 'a';
        if(curr->child[index]==NULL)
            curr->child[index] = getNode(s[i]);
        curr->child[index]->wc+=1;
        curr = curr->child[index];
    }
}

bool search(char *s){
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; i++){
        index = s[i] - 'a';
        if(curr->child[index]==NULL || curr->child[index]->wc==0)
            return false;
        curr = curr->child[index];
    }
    return true;
}

void Triedelete(char *s){
    if(search(s)){
        Trienode *curr = root;
        int index;
        for(int i=0; s[i]!='\0'; i++){
            index = s[i] - 'a';
            curr->child[index]->wc-=1;
            curr = curr->child[index];
        }
    }
}

int countPrefix(string s){
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; i++){
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc==0)
            return 0;

        curr = curr->child[index];
    }
    return curr->wc;
}

int main(){
    init();
    char a[5] = {'a', 'r', 'm', 'y'};
    char b[5] = {'a', 'r', 'm'};
    char c[5] = {'a', 'r', 'm', 's'};
    char d[5] = {'a', 'r', 'y'};
    char e[5] = {'a', 'm', 'y'};
    char f[5] = {'a', 'p', 'i'};

    insert(a); insert(b); insert(c); insert(d); insert(e); insert(f);

    cout<<"No. of strings with the given prefix 'a' "<<countPrefix("a")<<endl;
    cout<<"No. of strings with the given prefix 'ar' "<<countPrefix("ar")<<endl;
    cout<<"No. of strings with the given prefix 'arm' "<<countPrefix("arm")<<endl;
    cout<<"No. of strings with the given prefix 'army' "<<countPrefix("army")<<endl;
    cout<<"No. of strings with the given prefix 'armi' "<<countPrefix("armi")<<endl;
    cout<<"No. of strings with the given prefix 'ary' "<<countPrefix("ary")<<endl;

    cout<<"Deletion started..........."<<endl;
    Triedelete(a);
    Triedelete(d);

    cout<<"Done"<<endl;

    cout<<"No. of strings with the given prefix 'a' "<<countPrefix("a")<<endl;
    cout<<"No. of strings with the given prefix 'ar' "<<countPrefix("ar")<<endl;
    cout<<"No. of strings with the given prefix 'arm' "<<countPrefix("arm")<<endl;
    cout<<"No. of strings with the given prefix 'army' "<<countPrefix("army")<<endl;
    cout<<"No. of strings with the given prefix 'armi' "<<countPrefix("armi")<<endl;
    cout<<"No. of strings with the given prefix 'ary' "<<countPrefix("ary")<<endl;


}
