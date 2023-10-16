#include <stdio.h>
#include <stdlib.h>

typedef struct nos
{
    int info;
    struct nos *fd;
    struct nos *fe;
} NoArv;

typedef struct Arv
{
    NoArv *raiz;
} Arv;

int vaziaArv(Arv *base)
{
    if(base->raiz == NULL)
    {
        return 1;
    }
    return 0;
}
void CriaArv()
{
    Arv *aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}
NoArv *auxinsere(NoArv *no, int num)
{
    int flag;
    NoArv *pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = num;
    novo->fd = NULL;
    novo->fe = NULL;
    if(no == NULL)
    {
        return novo;
    }
    else
    {
        pai = no;
        flag = 0;
        while(flag == 0)
        {
            if(pai->info < num)
            {
                if(pai->fd == NULL)
                {
                    pai->fd = novo;
                    flag =1;
                }
                else
                {
                    pai= pai->fd;
                }
            }
                else
                {
                    if(pai->info>num)
                    {
                        if(pai->fe == NULL)
                        {
                            pai->fe = novo;
                            flag = 1;
                        }
                        else
                        {
                            pai=pai->fe;
                        }
                    }
                }
            }
        }
    return no;
    }


void insere(Arv* arvore, int num)
{
    arvore->raiz = auxinsere(arvore->raiz, num);
}

NoArv *busca(NoArv *no, int valor) {
    if (no == NULL || no->info == valor) {
        return no;
    }

    if (valor < no->info) {
        return busca(no->fe, valor);
    }

    return busca(no->fd, valor);
}

// Função para buscar um valor na árvore
NoArv *buscarNaArvore(Arv *arvore, int valor) {
    return busca(arvore->raiz, valor);
}







int main()
{
    printf("Hello world!\n");
    return 0;
}
