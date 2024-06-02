#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

typedef struct nos {
    int info;
    struct nos *fd;
    struct nos *fe;
} NoArv;

typedef struct Arv {
    NoArv *raiz;
} Arv;

int vaziaArv(Arv *base) {
    if (base->raiz == NULL) {
        return 1;
    }
    return 0;
}

int vaziaArv(Arv *base) {
    if (base->raiz == NULL) {
        return 0;
    }
    return 1;
}

Arv* CriaArv() {
    Arv *aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

NoArv *auxinsere(NoArv *no, int num) {
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
                    flag = 1;
                }
                else
                {
                    pai = pai->fd;
                }
            }
            else
            {
                if(pai->info > num)
                {
                    if(pai->fe == NULL)
                    {
                        pai->fe = novo;
                        flag = 1;
                    }
                    else
                    {
                        pai = pai->fe;
                    }
                }
            }
        }
        return no;
    }
}

void insere(Arv* arvore, int num) {
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

int quant_nos(NoArv *raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1 + quant_nos(raiz->fd) + quant_nos(raiz->fe);
    }
}

int menor_no(NoArv *pai, int valor){
 int menor=-1;
 while(pai!=NULL)
 {
     menor=pai->info;
     pai=pai->fe;;
 }
 return menor;
}

void imprime(NoArv *pai){
    if(pai!=NULL){
        printf("%d",pai->info);
        imprime(pai->fe);
        imprime(pai->fd);
    }
}
int main() {
    Arv *arvore = CriaArv();
    int op, valor;
    char continuar;
    setlocale(LC_ALL,"portuguese");

    do {
        printf("\t\n|BEM-VINDO AO PROGRAMA DE ÁRVORES|\n");
        printf("1. Adicionar um número na árvore\n");
        printf("2. Buscar um número na árvore\n");
        printf("3. Nos da árvore\n");
        printf("4. Achar o menor numero da arvore\n");
        printf("5. Imprimir a arvore\n");
        printf("6. Sair\n");
        printf("> ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("Insira o número: ");
            scanf("%d", &valor);
            insere(arvore, valor);
            break;

        case 2:
            printf("Qual o numero da busca?\n >");
            scanf("%d",&valor);
            NoArv *busca = buscarNaArvore(arvore,valor);
            if (busca != NULL) {
                printf("Valor %d encontrado na árvore!\n", valor);
            } else {
                printf("Valor %d não encontrado na árvore.\n", valor);
            }

            break;

        case 3:
            printf("Quantidade de nós: %d\n", quant_nos(arvore->raiz));
            break;

        case 4:
            printf("O menor numero da arvore é %d", menor_no(arvore->raiz,valor));
            break;

        case 5:
            printf("A árvore é:\n");
            imprime(arvore->raiz);
            break;

        case 6:

            printf("\nSaindo...");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 4);

    return 0;
}


