#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct formularioReclamacao{
    int numeroPoste; // number of light pole
    int opcao;      // opcao of complaint
    struct formularioReclamacao *proximo;
    char descricao[400]; // descricao of the complaint
    char nome[];           // nome of who made the complaint
} formularioReclamacao;

void inserirPoste(formularioReclamacao **p, formularioReclamacao **primeiro, formularioReclamacao **auxLink, int inicio, int final);
formularioReclamacao *busca(int numeroBuscado, formularioReclamacao *primeiro);
void exibe(formularioReclamacao *primeiro);
void atualiza(int numeroPoste, formularioReclamacao *primeiro);
formularioReclamacao *delete (int number, formularioReclamacao *primeiro);

int main() {
    int nInserir, auxInserir = 1, auxWhile = 0, numeroPoste;
    formularioReclamacao *p = NULL, *auxLink = NULL, *primeiro = NULL;
    while (auxWhile != 9){
        printf(" Digite 1 se deseja inserir postes:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar um poste pela posicao na lista:\n Digite 4 para atualizar um cadastro do poste:\n Digite 5 para deletar um poste:\n Digite 9 se deseja terminar o programa: \n");
        scanf("%d", &auxWhile);
        if (auxWhile == 1){
            printf("Quantos alunos deseja inserir?\n");
            scanf("%d", &nInserir);
            if (nInserir < 9999 && (auxInserir < 9999)){
                nInserir = auxInserir + nInserir;
                inserirPoste(&p, &primeiro, &auxLink, auxInserir, nInserir);
                auxInserir = nInserir;
            }
            else
                printf("A lista nao comporta essa alocacao, ou por estar cheia, ou a quantidade de elementos a ser inserido era muito grande.\nLista limitada a 9.999 insercoes.\n");
        }
        else if (auxWhile == 2){
            exibe(primeiro);
        }
        else if (auxWhile == 3){
            printf("Digite numero do poste que deseja buscar");
            scanf("%d", &numeroPoste);
            busca(numeroPoste, primeiro);
        }
        else if (auxWhile == 4){
            printf("Digite numero do poste que deseja buscar a fim de atualizar o mesmo na lista");
            scanf("%d", &numeroPoste);
            atualiza(numeroPoste, primeiro);
        }
        else if (auxWhile == 5){
            printf("Digite numero do poste que deseja buscar a fim de deletar da lista");
            scanf("%d", &numeroPoste);
            delete (numeroPoste, primeiro);
        }
    }
    return 0;
}

void inserirPoste(formularioReclamacao **p, formularioReclamacao **primeiro, formularioReclamacao **auxLink, int inicio, int final) {
    int aux, aux2, m = inicio, k = final;
    formularioReclamacao *temp;
    for (m; m < k; m++) {
        *p = (formularioReclamacao *) malloc(sizeof(formularioReclamacao));
        printf("Digite o numero do poste a ser inserido no formulario Reclamacao, sistema entre 1 e 9999: se ja houver um poste com esse numero, digite novamente:\n");
        (*p)->numeroPoste = -1;
        aux2=1;
        aux=0;
        scanf("%d", &(*p)->numeroPoste);
        /*while (aux == 0) {
            scanf("%d", &(*p)->numeroPoste);
            if (*primeiro != NULL) {
                temp = *primeiro;
                while (temp->proximo != *p) {
                    if (temp->numeroPoste == ((*p)->numeroPoste)) aux2 =0;
                    temp = temp->proximo;
                }
                if((temp->proximo==NULL)&&(aux2==0)) aux=1;
            }
            else aux=1;
        }*/
        fflush(stdin);
        printf("Escreva o nome de quem esta realizando a reclamacao:\n");
        fgets((*p)->nome, 30, stdin);
        printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
        printf("\n0 - Sem reclamacoes");
        printf("\n1 - Luz queimada");
        printf("\n2 - Luz piscando");
        printf("\n3 - Sem luz");
        scanf("%d", &(*p)->opcao);
        if ((*p)->opcao == 0) strcpy((*p)->descricao, "Sem reclamacoes");
        else {
            printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
            fgets((*p)->descricao, 400, stdin);
        }
        (*p)->proximo = NULL;
        if (*primeiro == NULL) *primeiro = *p;
        else (*auxLink)->proximo = *p;
        *auxLink = *p;
    }
}

formularioReclamacao *busca(int numeroBuscado, formularioReclamacao *primeiro){
    formularioReclamacao *temp = primeiro;
    while (temp->proximo != NULL){
        if (temp->numeroPoste == numeroBuscado) return temp;
        else temp = temp->proximo;
    }
    if ((temp->proximo == NULL) && (temp->numeroPoste != numeroBuscado)){
        printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
        return NULL;
    }
}

void exibe(formularioReclamacao *primeiro){
    formularioReclamacao *p = primeiro;
    while (p != NULL){
        printf("\nNumero do poste: %d", p->numeroPoste);
        printf("\nNumero da reclamacao: %d", p->opcao);
        printf("\nNome de quem fez a reclamacao: %s", p->nome);
        printf("\nDescricao do problema: ");
        printf("\n%s", p->descricao);
        p = p->proximo;
    }
}

void atualiza(int numeroPoste, formularioReclamacao *primeiro){
    formularioReclamacao *p;
    p = busca(numeroPoste, primeiro);
    printf("\nDigite o seu nome:  ");
    gets(p->nome);
    printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
    printf("\n0 - Problema resolvido");
    printf("\n1 - Luz queimada");
    printf("\n2 - Luz piscando");
    printf("\n3 - Sem luz");
    scanf("%d", &p->opcao);
    if (p->opcao != 0){
        printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
        fflush(stdin);
        fgets(p->descricao, 400, stdin);
    }
    else strcpy(p->descricao, "Sem reclamacoes");
}

formularioReclamacao *delete (int number, formularioReclamacao *primeiro){
    formularioReclamacao *p, *q, *r;
    p = busca(number, primeiro);
    if (p->proximo == NULL) { // deleting the last one
        free(p);
        p = NULL;
        return primeiro;
    }
    else if (p == primeiro) { // deleting the first one
        q = p->proximo;
        free(p);
        p = q;
        primeiro = p;
        return primeiro;
    }
    else{
        q = primeiro;
        while (q->proximo->numeroPoste != p->numeroPoste) q = q->proximo;
        r = p->proximo;
        free(p);
        p = NULL;
        q->proximo = r;
        return primeiro;
    }
}
