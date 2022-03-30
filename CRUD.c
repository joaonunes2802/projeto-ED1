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
    int qtdPostes, auxInserir = 1, auxWhile = 9, numeroPoste, auxWhile2=9, finalRua, insercaoRua=0, inicioRua=0, tempBuscaRua, auxWHile3=0, auxWhile4=0;
    poste *tempBusca=NULL;
    rua *primeiro=NULL, *final=NULL, *ruaBusca=NULL;
    while(auxWHile3!=9) {
        printf("Digite 1 para ir para a parde do operador\nDigite 2 caso for um cliente:\nDigite 9 caso deseje fechar o programa\n");
        scanf("%d", &auxWHile3);
        if (auxWHile3 == 1) {
            auxWhile2 = 0;
            while (auxWhile2 != 9) {
                printf("Digite 1 se deseja adicionar uma rua:\nDigite 2 para exibir a lista de ruas\nDigite 3 para fazer operacoes em um poste de uma rua\nDigite 9 para voltar o programa\n");
                fflush(stdout);
                scanf("%d", &auxWhile2);
                if (auxWhile2 == 1) {
                    printf("Digite quantas ruas deseja inserir:\n");
                    fflush(stdout);
                    scanf("%d", &insercaoRua);
                    finalRua = insercaoRua + inicioRua;
                    cadastrarRua(&primeiro, &final, inicioRua, finalRua);
                    inicioRua = finalRua;
                }
                if (auxWhile2 == 2) {
                    exibirRua(primeiro);
                }
                if (auxWhile2 == 3) {
                    auxWhile = 0;
                    printf("Digite o numero da rua que deseja modificar os postes:\n ");
                    ruaBusca=NULL;
                    fflush(stdout);
                    while(ruaBusca==NULL) {
                        scanf("%d", &tempBuscaRua);
                        ruaBusca = buscaRua(tempBuscaRua, primeiro);
                        if (ruaBusca == NULL){
                            printf("\nErro, digite novamente!\n");
                        }
                    }
                }
                while (auxWhile != 9) {
                    printf("\nDigite 1 se deseja inserir postes:\nDigite 2 se deseja exebir a lista de postes:\nDigite 3 se deseja buscar um poste pelo seu numero:\nDigite 4 para atualizar um cadastro de um poste:\nDigite 5 para deletar um poste:\nDigite 9 se deseja ir para a parte de rua\n");
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
                        if (tempBusca != NULL){
                            printf("\nPoste encontrado\nNome de quem fez o cadastro: %sOpcao de reclamacao: %d\nDescricao do problema: %s\n\n",tempBusca->nome, tempBusca->opcao, tempBusca->descricao);
                            fflush(stdout);
                        } else{
                            printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
                        }
                        fflush(stdout);
                    } else if (auxWhile == 4) {
                        printf("Digite numero do poste que deseja atualizar\n");
                        fflush(stdout);
                        scanf("%d", &numeroPoste);
                        atualiza(numeroPoste, ruaBusca->poste->primeiro);
                    } else if (auxWhile == 5) {
                        printf("Digite numero do poste que deseja deletar\n");
                        fflush(stdout);
                        scanf("%d", &numeroPoste);
                        delete(numeroPoste, &ruaBusca->poste->primeiro, &ruaBusca->poste->final);
                    } else if (auxWhile == 9) {
                        auxWhile2 = 0;
                    }
                }
            }

        } else if (auxWHile3 == 2) {
            auxWhile=0;
            while (auxWhile4 != 9) {
                printf("Digite 1 para exibir a lista de ruas:\nDigite 2 para buscar uma rua e fazer operacoes na mesma envolvendo postes:\nDigite 9 para voltar o programa\n");
                    scanf("%d", &auxWhile4);
                    if(auxWhile4==1){
                        exibirRua(primeiro);
                    }
                    else if(auxWhile4==2){
                        auxWhile=0;
                        ruaBusca=NULL;
                        while(ruaBusca==NULL) {
                            scanf("%d", &tempBuscaRua);
                            ruaBusca = buscaRua(tempBuscaRua, primeiro);
                            while (auxWhile!=9){
                                printf("\nDigite 1 se deseja inserir postes:\nDigite 2 se deseja exebir a lista:\nDigite 3 se deseja buscar um poste pela posicao na lista:\nDigite 4 para atualizar um cadastro do poste:\nDigite 5 para deletar um poste:\nDigite 9 se deseja voltar o programa\n");
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
                                        printf("\nPoste encontrado\nNome de quem fez o cadastro: %sOpcao de reclamacao: %d\nDescricao do problema: %s\n",tempBusca->nome, tempBusca->opcao, tempBusca->descricao);
                                        fflush(stdout);
                                    } else{
                                        printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
                                    }
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
                                } else if (auxWhile == 9) {
                                    auxWhile4=0;
                                }
                            }
                        }
                    }
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
        printf("Descricao do problema:\n ");
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


void exibirRua(rua *v){
    while(v!=NULL){
        printf("Rua numero: %d; Nome: %s\n", v->numeroRua, v->nomeRua);
        fflush(stdout);
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
