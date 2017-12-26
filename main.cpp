#include <bits/stdc++.h>

using namespace std;

struct tree{
    int key;
    struct tree *esq;
    struct tree *dir;
}typedef Tree;

Tree *insere(Tree *raiz, int key){

    if(raiz==NULL){
        Tree *r = new Tree();
        r->key = key; r->esq = r->dir = NULL;
        raiz = r;
        return raiz;
    }

    Tree *r2 = raiz;
    if(r2->key < key){
        r2->dir = insere(r2->dir,key);
    }else
        r2->esq = insere(r2->esq,key);
}

void infixa(Tree *r){
    if(r!=NULL){
        infixa(r->esq);
        printf("%d ",r->key);
        infixa(r->dir);
    }
}

void prefixa(Tree *r){
    if(r!=NULL){
        printf("%d ",r->key);
        prefixa(r->esq);
        prefixa(r->dir);
    }
}

void posfixa(Tree *r){
    if(r!=NULL){
        posfixa(r->esq);
        posfixa(r->dir);
        printf("%d ",r->key);
    }
}

Tree *deletar(Tree *raiz,int key){

    if(raiz==NULL)return NULL;

    if(raiz->key < key) raiz->dir = deletar(raiz->dir,key);

    else if(raiz->key > key) raiz->esq = deletar(raiz->esq,key);

    else if(raiz->esq==NULL && raiz->dir==NULL){
        free(raiz);raiz = NULL;

    }else if(raiz->esq==NULL && raiz->dir!=NULL){
        Tree *t = raiz; raiz = raiz->dir; free(t);
    }
    else if(raiz->esq!=NULL && raiz->dir==NULL){
        Tree *t=raiz; raiz = raiz->esq; free(t);
    }
    else if(raiz->esq!=NULL && raiz->dir!=NULL){

        Tree *r = raiz->esq;

        while(r->dir!=NULL)
            r = r->dir;

        raiz->key = r->key;r->key = key;
        raiz->esq = deletar(raiz->esq,key);
    }
    return raiz;
}

Tree *clearBuffer(Tree *raiz){

    if(raiz==NULL)return raiz;

    raiz->esq = clearBuffer(raiz->esq);
    raiz->dir = clearBuffer(raiz->dir);

    if(raiz->esq==NULL && raiz->dir==NULL){
        printf("\nchave deletada = %d\n",raiz->key);
        free(raiz);raiz = NULL;return raiz;
    }
}

int main()
{
    Tree *r = NULL;
    r = insere(r,30);
    r = insere(r,20);
    r = insere(r,50);
    r = insere(r,12);
    r = insere(r,28);
    r = insere(r,5);
    r = insere(r,3);
    r = insere(r,32);
    r = insere(r,31);
    r = insere(r,35);

    infixa(r);
    printf("\n");

    r = deletar(r,10);
    infixa(r);

    r = clearBuffer(r);
    printf("\nArvore apos rodar o clear buffer:\n");
    infixa(r);
    return 0;
}
