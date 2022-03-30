#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct poste{
    struct poste *proximo, *anterior, *primeiro, *final;
    int numeroPoste; // numero do poste der luz
    int opcao;       // opção de reclamação
    char descricao[400]; // descrição da reclamação
    char nome[30];       // nome de quem fez a reclamação
}poste;

typedef struct rua{
    int numeroRua;
    char nomeRua[50];
    struct poste *poste;
    struct rua *proximo, *anterior;
} rua;

void imprirString(char palavra[]);
void cadastrarRua(rua **primeiro, rua **final, int inicio, int fim);
void exibirRua(rua *v);
rua *buscaRua(int numeroBuscado, rua *primeiro);

void inserirPoste(rua **busca, int inicio, int fim);
poste *busca(int numeroBuscado, poste *primeiro);
void exibe(poste *primeiro);
void atualiza(int numeroPoste, poste *primeiro);
void delete (int number, poste **primeiro, poste **final);

int main() {
    int qtdPostes, auxInserir = 1, auxWhile = 9, numeroPoste, auxWhile2=0, finalRua, insercaoRua=0, inicioRua=0, tempBuscaRua;
    poste *tempBusca=NULL;
    rua *primeiro=NULL, *final=NULL, *ruaBusca=NULL;
    while(auxWhile2!=9) {
        printf("Digite 1 se deseja adicionar uma rua:\nDigite 2 para buscar uma rua pelo nome\n Digite 3 para fazer operacoes em um poste");
        fflush(stdout);
        scanf("%d", &auxWhile2);
        if(auxWhile2==1){
            printf("Digite quantas ruas deseja inserir:\n");
            fflush(stdout);
            scanf("%d", &insercaoRua);
            finalRua=insercaoRua+inicioRua;
            cadastrarRua(&primeiro, &final, inicioRua, finalRua);
            inicioRua=finalRua;
        }
        if(auxWhile2==2){
            exibirRua(primeiro);
        }
        if(auxWhile2==3){
            auxWhile=0;
            printf("Digite qual a rua que deseja modificar os postes:\n ");
            fflush(stdout);
            scanf("%d", &tempBuscaRua);
            ruaBusca=buscaRua(tempBuscaRua, primeiro);
        }
        while (auxWhile != 9) {
            printf("\n Digite 1 se deseja inserir postes:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar um poste pela posicao na lista:\n Digite 4 para atualizar um cadastro do poste:\n Digite 5 para deletar um poste:\n Digite 6 se deseja exibir o historico de operacoes realizadas:\n Digite 9 se deseja ir para a parte de rua\n");
            fflush(stdout);
            scanf("%d", &auxWhile);
            if (auxWhile == 1) {
                printf("Quantos postes deseja inserir?\n");
                fflush(stdout);
                scanf("%d", &qtdPostes);
                if (qtdPostes < 9999 && (auxInserir < 9999)) {
                    qtdPostes = auxInserir + qtdPostes;
                    inserirPoste(&ruaBusca, auxInserir, qtdPostes);
                    auxInserir = qtdPostes;
                    fflush(stdin);
                } else
                    printf("A lista nao comporta essa alocacao, ou por estar cheia, ou a quantidade de elementos a ser inserido era muito grande.\nLista limitada a 9.999 insercoes.\n");
                fflush(stdout);
            } else if (auxWhile == 2) {
                exibe(ruaBusca->poste->primeiro);
            } else if (auxWhile == 3) {
                printf("Digite numero do poste que deseja buscar\n");
                fflush(stdout);
                scanf("%d", &numeroPoste);
                tempBusca = busca(numeroPoste, ruaBusca->poste->primeiro);
                if (tempBusca != NULL) {
                    printf("\n Poste encontrado\n Nome de quem fez o cadastro: %s \n Opcao de reclamacao: %d\n Descricao do problema: %s\n\n",
                           tempBusca->nome, tempBusca->opcao, tempBusca->descricao);
                    fflush(stdout);
                } else printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
                fflush(stdout);
            } else if (auxWhile == 4) {
                printf("Digite numero do poste que deseja atualizar na lista\n");
                fflush(stdout);
                scanf("%d", &numeroPoste);
                atualiza(numeroPoste, ruaBusca->poste->primeiro);
            } else if (auxWhile == 5) {
                printf("Digite numero do poste que deseja deletar da lista\n");
                fflush(stdout);
                scanf("%d", &numeroPoste);
                delete(numeroPoste, &ruaBusca->poste->primeiro, &ruaBusca->poste->final);
            }
            else if (auxWhile == 9){
                auxWhile2=0;
            }
        }
    }
    return 0;
}

void inserirPoste(rua **busca, int inicio, int fim) {
    int m = inicio, k = fim;
    poste *p=NULL, *q=NULL;
    for (m; m < k; m++) {
        p = (poste *) malloc(sizeof(poste));
        p->primeiro=NULL;
        p->final=NULL;
        p->numeroPoste=m;
        printf("Poste numero: %d\n", p->numeroPoste);
        fflush(stdin);
        fflush(stdout);
        printf("Escreva o nome de quem esta realizando a reclamacao:\n");
        fflush(stdout);
        fgets(p->nome, 30, stdin);
        printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
        fflush(stdout);
        printf("\n0 - Sem reclamacoes");
        fflush(stdout);
        printf("\n1 - Luz queimada");
        fflush(stdout);
        printf("\n2 - Luz piscando");
        fflush(stdout);
        printf("\n3 - Sem luz\n");
        scanf("%d", &p->opcao);
        fflush(stdout);
        if (p->opcao == 0) strcpy(p->descricao, "Sem reclamacoes");
        else {
            printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
            fflush(stdout);
            fflush(stdin);
            fgets(p->descricao, 400, stdin);
        }
        p->proximo=NULL;
        p->anterior=NULL;
        if((*busca)->poste==NULL){
            (*busca)->poste=p;
            (*busca)->poste->primeiro=p;
            (*busca)->poste->final=(*busca)->poste->primeiro;
            p->anterior=NULL;
        }
        else {
            q = ((*busca)->poste)->final;
            ((*busca)->poste)->final=p;
            (*busca)->poste->final->anterior=q;
            q->proximo=((*busca)->poste)->final;
        }
    }
}

poste *busca(int numeroBuscado, poste *primeiro){
    poste *temp = primeiro;
    while (temp!= NULL){
        if (temp->numeroPoste == numeroBuscado){
            return temp;
        }
        temp = temp->proximo;
    }
    return NULL;
}

void exibe(poste *primeiro){
    poste *p = primeiro;
    while (p != NULL){
        printf("\nNumero do poste: %d", p->numeroPoste);
        fflush(stdout);
        printf("\nNome de quem fez a reclamacao: %s", p->nome);
        fflush(stdout);
        printf("\nDescricao do problema:\n ");
        fflush(stdout);
        printf("%s\n", p->descricao);
        p = p->proximo;
    }
}

void atualiza(int numeroPoste, poste *primeiro) {
    poste *p;
    p = busca(numeroPoste, primeiro);
    if (p != NULL) {
        fflush(stdin);
        printf("Escreva o nome de quem esta atualizando o cadastro:\n");
        fflush(stdout);
        fgets(p->nome, 30, stdin);
        printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
        fflush(stdout);
        printf("\n0 - Problema resolvido");
        fflush(stdout);
        printf("\n1 - Luz queimada");
        fflush(stdout);
        printf("\n2 - Luz piscando");
        fflush(stdout);
        printf("\n3 - Sem luz");
        fflush(stdout);
        scanf("%d", &p->opcao);
        if (p->opcao != 0) {
            printf("\nDigite a sua reclamacao (maximo de 400 caracteres):\n");
            fflush(stdout);
            fflush(stdin);
            fgets(p->descricao, 400, stdin);
        } else strcpy(p->descricao, "Sem reclamacoes");
        fflush(stdout);
    }
    else printf("Nao e possivel atualizar postes que nao estao na lista\n");
    fflush(stdout);
}

void delete(int number, poste **primeiro, poste **final) {
    poste *p, *q, *r;
    p = busca(number, *primeiro);
    if (p != NULL) {
        printf("Poste deletado\n");
        fflush(stdout);
        if (p == *primeiro) { // deleting the first one
            q = p->proximo;
            free(p);
            p = q;
            *primeiro = p;
        } else if (p == *final) {
            q = *primeiro;
            while (q->proximo->numeroPoste != p->numeroPoste) q = q->proximo;
            free(p);
            *final = q;
            (*final)->proximo = NULL;
        } else {
            q = *primeiro;
            while (q->proximo->numeroPoste != p->numeroPoste) q = q->proximo;
            r = p->proximo;
            free(p);
            p = NULL;
            q->proximo = r;
        }
    }
    else printf("Poste nao se encontra na lista, nao foi possivel deletar\n");
    fflush(stdout);
}

void cadastrarRua(rua **primeiro, rua **final, int inicio, int fim){
    int m = inicio, k = fim;
    rua *p=NULL, *q=NULL;
    for (m; m < k; m++) {
        p = (rua *) malloc(sizeof(rua));
        p->numeroRua=m;
        printf("Rua numero: %d\n", p->numeroRua);
        fflush(stdout);
        fflush(stdin);
        printf("Escreva o nome da rua:\n");
        fflush(stdout);
        fgets(p->nomeRua, 30, stdin);
        p->proximo=NULL;
        p->poste=NULL;
        if(*primeiro==NULL){
            *primeiro=p;
            *final=*primeiro;
            p->anterior=NULL;
        }
        else {
            q = *final;
            *final=p;
            (*final)->anterior=q;
            q->proximo=*final;
        }
    }
}

void imprirString(char palavra[]){
    int i = 0;

    while(palavra[i] != '\0'){
        printf("%c", palavra[i]);
        fflush(stdout);
        i++;
    }
    printf("\n");
}

void exibirRua(rua *v){
    while(v!=NULL){
        printf("Rua numero: %d", v->numeroRua);
        fflush(stdout);
        imprirString(v->nomeRua);
        v=v->proximo;
    }
}

rua *buscaRua(int numeroBuscado, rua *primeiro){
    rua *temp = primeiro;
    while (temp!= NULL){
        if (temp->numeroRua == numeroBuscado){
            return temp;
        }
        temp = temp->proximo;
    }
    return NULL;
}
