#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct poste{
    //struct poste *proximo, *anterior;
    int numeroPoste; // numero do poste der luz
    int opcao;       // opção de reclamação
    char nome[30];       // nome de quem fez a reclamação
}poste;

typedef struct rua{
    int numeroRua;
    char nomeRua[50];
    struct poste poste[10];
} rua;

void cadastrarRua(rua vet[], int inicio, int final);
int buscaNomeRua(rua v[], int tamanho);
void exibirRua(rua v[], int final);

void inserirPoste(poste **primeiro, poste **final, int inicio, int fim);
poste *busca(int numeroBuscado, poste *primeiro);
void exibe(poste *primeiro);
void atualiza(int numeroPoste, poste *primeiro);
void delete (int number, poste **primeiro, poste **final);

int main() {
    int qtdPostes, auxInserir = 1, auxWhile, numeroPoste, auxWhile2=0, finalRua, insercaoRua=0, inicioRua=0, tempBuscaRua;
    poste *tempBusca=NULL;
    rua v[1000], primeiro[1000], final[1000];

    while(auxWhile2!=5) {
        printf("\nDigite 1 se deseja adicionar uma rua;\nDigite 2 para buscar uma rua pelo nome;\nDigite 3 para exibir todas ruas;\nDigite 4 para fazer operacoes em um poste;\nDigite 5 se deseja encerrar o programa;\n");
        scanf("%d", &auxWhile2);
        if(auxWhile2==1){
            printf("Digite quantas ruas deseja inserir: \n");
            scanf("%d", &insercaoRua);
            finalRua=insercaoRua+inicioRua;
            cadastrarRua(v, inicioRua, finalRua);
            inicioRua=finalRua;
        }
        if(auxWhile2==2){
            tempBuscaRua = buscaNomeRua(v, finalRua);
            if(tempBuscaRua == -1){
                printf("\nNao tem uma rua com esse nome\n");
            }else{
                printf("\nRua encontrada! Seu numero eh: %d\n", tempBuscaRua + 1);
            }                
        }
        if(auxWhile2==3){
            exibirRua(v, finalRua);
        }
        if(auxWhile2==4){
            auxWhile=0;
            printf("Digite qual a rua que deseja modificar os postes:\n ");
            scanf("%d", &tempBuscaRua);
            /*while (auxWhile != 7)
            {
                printf("\n Digite 1 se deseja inserir postes:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar um poste pela posicao na lista:\n Digite 4 para atualizar um cadastro do poste:\n Digite 5 para deletar um poste:\n Digite 6 se deseja exibir o historico de operacoes realizadas:\n Digite 7 se deseja ir para a parte de rua\n");
                scanf("%d", &auxWhile);
                if (auxWhile == 1)
                {
                    printf("Quantos postes deseja inserir?\n");
                    scanf("%d", &qtdPostes);
                    if (qtdPostes < 9999 && (auxInserir < 9999))
                    {
                        qtdPostes = auxInserir + qtdPostes;
                        inserirPoste(&primeiro[tempBuscaRua].poste, &final[tempBuscaRua].poste, auxInserir, qtdPostes);
                        auxInserir = qtdPostes;
                        fflush(stdin);
                    }
                    else
                        printf("A lista nao comporta essa alocacao, ou por estar cheia, ou a quantidade de elementos a ser inserido era muito grande.\nLista limitada a 9.999 insercoes.\n");
                }
                else if (auxWhile == 2)
                {
                    exibe(primeiro[tempBuscaRua].poste);
                }
                else if (auxWhile == 3)
                {
                    printf("Digite numero do poste que deseja buscar\n");
                    scanf("%d", &numeroPoste);
                    tempBusca = busca(numeroPoste, primeiro[tempBuscaRua].poste);
                    if (tempBusca != NULL)
                    {
                        printf("\n Poste encontrado\n Nome de quem fez o cadastro: %s CPF: %s\n Opcao de reclamacao: %d\n Descricao do problema: %s\n\n",tempBusca->nome, tempBusca->opcao);
                    }
                    else
                        printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
                }
                else if (auxWhile == 4)
                {
                    printf("Digite numero do poste que deseja atualizar na lista\n");
                    scanf("%d", &numeroPoste);
                    atualiza(numeroPoste, primeiro[tempBuscaRua].poste);
                }
                else if (auxWhile == 5)
                {
                    printf("Digite numero do poste que deseja deletar da lista\n");
                    scanf("%d", &numeroPoste);
                    delete (numeroPoste, &primeiro[tempBuscaRua].poste, &final[tempBuscaRua].poste);
                }
                else if (auxWhile == 9)
                {
                    auxWhile2 = 0;
                }
            }*/
        }
        /*while (auxWhile != 7) {
            printf("\n Digite 1 se deseja inserir postes:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar um poste pela posicao na lista:\n Digite 4 para atualizar um cadastro do poste:\n Digite 5 para deletar um poste:\n Digite 6 se deseja exibir o historico de operacoes realizadas:\n Digite 7 se deseja ir para a parte de rua\n");
            scanf("%d", &auxWhile);
            if (auxWhile == 1) {
                printf("Quantos postes deseja inserir?\n");
                scanf("%d", &qtdPostes);
                if (qtdPostes < 9999 && (auxInserir < 9999)) {
                    qtdPostes = auxInserir + qtdPostes;
                    inserirPoste(&primeiro[tempBuscaRua].poste, &final[tempBuscaRua].poste,auxInserir, qtdPostes);
                    auxInserir = qtdPostes;
                    fflush(stdin);
                } else
                    printf("A lista nao comporta essa alocacao, ou por estar cheia, ou a quantidade de elementos a ser inserido era muito grande.\nLista limitada a 9.999 insercoes.\n");
            } else if (auxWhile == 2) {
                exibe(primeiro[tempBuscaRua].poste);
            } else if (auxWhile == 3) {
                printf("Digite numero do poste que deseja buscar\n");
                scanf("%d", &numeroPoste);
                tempBusca = busca(numeroPoste, primeiro[tempBuscaRua].poste);
                if (tempBusca != NULL) {
                    printf("\n Poste encontrado\n Nome de quem fez o cadastro: %s CPF: %s\n Opcao de reclamacao: %d\n Descricao do problema: %s\n\n",
                           tempBusca->nome, tempBusca->cpf, tempBusca->opcao, tempBusca->descricao);
                } else printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
            } else if (auxWhile == 4) {
                printf("Digite numero do poste que deseja atualizar na lista\n");
                scanf("%d", &numeroPoste);
                atualiza(numeroPoste, primeiro[tempBuscaRua].poste);
            } else if (auxWhile == 5) {
                printf("Digite numero do poste que deseja deletar da lista\n");
                scanf("%d", &numeroPoste);
                delete(numeroPoste, &primeiro[tempBuscaRua].poste, &final[tempBuscaRua].poste);
            }
            else if (auxWhile == 9){
                auxWhile2=0;
            }
        }*/
    }
    return 0;
}
/*
void inserirPoste(poste **primeiro, poste **final, int inicio, int fim) {
    int m = inicio, k = fim;
    poste *p=NULL, *q=NULL;
    for (m; m < k; m++) {
        p = (poste *) malloc(sizeof(poste));
        p->numeroPoste=m;
        printf("Poste numero: %d\n", p->numeroPoste);
        fflush(stdin);
        printf("Escreva o nome de quem esta realizando a reclamacao:\n");
        fgets(p->nome, 30, stdin);
        printf("Escreva o CPF de quem esta realizando a reclamacao:\n");
        fflush(stdin);
        fgets(p->cpf, 11, stdin);
        fflush(stdin);
        printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
        printf("\n0 - Sem reclamacoes");
        printf("\n1 - Luz queimada");
        printf("\n2 - Luz piscando");
        printf("\n3 - Sem luz\n");
        scanf("%d", &p->opcao);
        if (p->opcao == 0) strcpy(p->descricao, "Sem reclamacoes");
        else {
            printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
            fflush(stdin);
            fgets(p->descricao, 400, stdin);
        }
        p->proximo=NULL;
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
*/
/*
poste *busca(int numeroBuscado, poste *primeiro){
    poste *temp = primeiro;
    while (temp!= NULL){
        if (temp->numeroPoste == numeroBuscado){
            return temp;
        }
        temp = temp->proximo;
    }
    return NULL;
}*/
/*
void exibe(poste *primeiro){
    poste *p = primeiro;
    while (p != NULL){
        printf("\nNumero do poste: %d", p->numeroPoste);
        printf("\nNome de quem fez a reclamacao: %s", p->nome);
        printf("\nCPF de quem fez a reclamacao: %s", p->cpf);
        printf("\nDescricao do problema:\n ");
        printf("%s\n", p->descricao);
        p = p->proximo;
    }
}
*/
/*
void atualiza(int numeroPoste, poste *primeiro) {
    poste *p;
    p = busca(numeroPoste, primeiro);
    if (p != NULL) {
        fflush(stdin);
        printf("Escreva o nome de quem esta atualizando o cadastro:\n");
        fgets(p->nome, 30, stdin);
        printf("Escreva o seu CPF:\n");
        fflush(stdin);
        fgets(p->cpf, 11, stdin);
        printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
        printf("\n0 - Problema resolvido");
        printf("\n1 - Luz queimada");
        printf("\n2 - Luz piscando");
        printf("\n3 - Sem luz");
        scanf("%d", &p->opcao);
        if (p->opcao != 0) {
            printf("\nDigite a sua reclamacao (maximo de 400 caracteres):\n");
            fflush(stdin);
            fgets(p->descricao, 400, stdin);
        } else strcpy(p->descricao, "Sem reclamacoes");
    }
    else printf("Nao e possivel atualizar postes que nao estao na lista\n");
}
*/
/*
void delete(int number, poste **primeiro, poste **final) {
    poste *p, *q, *r;
    p = busca(number, *primeiro);
    if (p != NULL) {
        printf("Poste deletado\n");
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
}
*/

void cadastrarRua(rua vet[], int inicio, int final){
    int i = 0, j = 0, nPostes = 0, iPoste = 0;
    i = inicio;
    j = final;
    for (i; i < j; i++){
        if(i == 0){
            for (iPoste = 0; iPoste <= 10; iPoste++){
                vet[i].poste[iPoste].numeroPoste = -1;
            }
            vet[i].numeroRua = i;
            printf("\nRua numero: %d\n", i + 1);
            printf("Digite a o nome da rua: ");
            fflush(stdin);
            fgets(vet[i].nomeRua, 50, stdin);
            printf("Digite quantos postes tem essa rua: ");
            scanf("%d", &nPostes);
            for (iPoste = 0; iPoste < nPostes; iPoste++){
                vet[i].poste[iPoste].numeroPoste = iPoste;
                printf("\nEscreva o nome de quem esta realizando o cadastro:\n");
                fflush(stdin);
                fgets(vet[i].poste[iPoste].nome, 30, stdin);
                printf("\nCaso deje realizar alguma reclamacao para o poste %d, digite o numero correspondente:", iPoste);
                printf("\n0 - Sem reclamacoes");
                printf("\n1 - Luz queimada");
                printf("\n2 - Luz piscando");
                printf("\n3 - Sem luz\n");
                scanf("%d", &vet[i].poste[iPoste].opcao);
            }
        }else{
            vet[i].numeroRua = i;
            printf("\nRua numero: %d\n", i + 1);
            printf("Digite a o nome da rua: ");
            fflush(stdin);
            fgets(vet[i].nomeRua, 50, stdin);
            printf("Digite quantos postes tem essa rua: ");
            scanf("%d", &nPostes);
            for(iPoste = 0; iPoste < nPostes; iPoste++){
                vet[i].poste[iPoste].numeroPoste = iPoste;
                printf("\nEscreva o nome de quem esta realizando o cadastro:\n");
                fflush(stdin);
                fgets(vet[i].poste[iPoste].nome, 30, stdin);
                printf("\nCaso deje realizar alguma reclamacao para o poste %d, digite o numero correspondente:", iPoste);
                printf("\n0 - Sem reclamacoes");
                printf("\n1 - Luz queimada");
                printf("\n2 - Luz piscando");
                printf("\n3 - Sem luz\n");
                scanf("%d", &vet[i].poste[iPoste].opcao);
            }
        } 
    }
}

int buscaNomeRua(rua v[], int tamanho){
    int i=0, comp;
    char nome[50];
    printf("Digite o nome da rua que deseja buscar\n");
    fflush(stdin);
    fgets(nome, 50, stdin);
    while(i <= tamanho){
        comp = strcmp(nome, v[i].nomeRua);
        if(comp == 0){
            return i;
        }
        i++;
    }
    return -1;
}

void exibirRua(rua v[], int final){
    int i=0, j = 0;
    while(i<final){
        printf("\nRua numero: %d; Nome: %s", i+1, v[i].nomeRua);
        while(v[i].poste[j].numeroPoste != - 1){
            printf("\nNumero do poste: %d", v[i].poste[j].numeroPoste);
            printf("\nOpcao de reclamacao registrada: %d", v[i].poste[j].opcao);
            printf("\nNome do autor da reclamacao: %s", v[i].poste[j].nome);
            j++;
        }
        i++;
    }
}
