#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct formularioReclamacao{
    int numeroPoste; // numero do poste der luz
    int opcao;      // opção de reclamação
    struct formularioReclamacao *proximo, *anterior;
    char descricao[400], cpf[11], endereco[30], telefone[11]; // descrição da reclamação, cpf de quem fez a reclamação, endereço e telefone de quem fez a reclamação
    char nome[30];           // nome de quem fez a reclamação
} formularioReclamacao;

void inserirPoste(formularioReclamacao **primeiro, formularioReclamacao **final, int inicio, int fim);
formularioReclamacao *busca(int numeroBuscado, formularioReclamacao *primeiro);
void exibe(formularioReclamacao *primeiro);
void atualiza(int numeroPoste, formularioReclamacao *primeiro);
void delete (int number, formularioReclamacao **primeiro, formularioReclamacao **final);
//int rotasegura(formularioreclamacao *primeiro);

int main() {
    int qtdPostes, auxInserir = 1, auxWhile = 0, numeroPoste;
    formularioReclamacao *primeiro = NULL, *final;
    /*struct tm *data_hora;             // struct que armazena data e hora
    time_t segundos;                        // variável para aemazenar o tempo em segundos
    time(segundos);                         // obtendo o tempo em segundos
    data_hora = localtime(&segundos); // convertendo o tempo em segundos para o tempo local
    FILE *log;
    log = fopen("c:\\log.txt", "w+");
    if(log == NULL){
        printf("\nErro, arquivo de log nao pode ser aberto!");
        exit(1);
    }else{
        fflush(stdin);
        fputs("\nAbertura do programa!!\n", log);
        fprintf(log, "Programa iniciado as %d:%d:%d de %d/%d/%d\n", data_hora->tm_hour, data_hora->tm_min, data_hora->tm_sec, data_hora->tm_mday, data_hora->tm_mon+1, data_hora->tm_year+1900);
        fclose(log);
    }
     */
    while (auxWhile != 9){
        printf(" Digite 1 se deseja inserir postes:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar um poste pela posicao na lista:\n Digite 4 para atualizar um cadastro do poste:\n Digite 5 para deletar um poste:\n Digite 9 se deseja terminar o programa: \n");
        scanf("%d", &auxWhile);
        if (auxWhile == 1){
            printf("Quantos postes deseja inserir?\n");
            scanf("%d", &qtdPostes);
            if (qtdPostes < 9999 && (auxInserir < 9999)){
                qtdPostes = auxInserir + qtdPostes;
                inserirPoste( &primeiro, &final, auxInserir, qtdPostes);
                auxInserir = qtdPostes;
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
            delete (numeroPoste, &primeiro, &final);
        }
    }
    return 0;
}

void inserirPoste(formularioReclamacao **primeiro, formularioReclamacao **final, int inicio, int fim) {
    int m = inicio, k = fim;
    formularioReclamacao *p=NULL, *q=NULL;
    for (m; m < k; m++) {
        p = (formularioReclamacao *) malloc(sizeof(formularioReclamacao));
        p->numeroPoste=m;
        printf("Poste numero: %d\n", p->numeroPoste);
        fflush(stdin);
        printf("Escreva o nome de quem esta realizando a reclamacao:\n");
        fgets(p->nome, 30, stdin);
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

formularioReclamacao *busca(int numeroBuscado, formularioReclamacao *primeiro){
    formularioReclamacao *temp = primeiro;
    while (temp!= NULL){
        if (temp->numeroPoste == numeroBuscado){
            printf("\n Poste encontrado\n Nome de quem fez o cadastro: %s Opcao de reclamacao: %d\n Descricao do problema: %s\n\n", temp->nome, temp->opcao, temp->descricao);
            return temp;
        }
        temp = temp->proximo;
    }
        printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
        return NULL;
}

void exibe(formularioReclamacao *primeiro){
    formularioReclamacao *p = primeiro;
    while (p != NULL){
        printf("\nNumero do poste: %d", p->numeroPoste);
        printf("\nNome de quem fez a reclamacao: %s", p->nome);
        printf("Numero da reclamacao: %d", p->opcao);
        printf("\nDescricao do problema:\n ");
        printf("%s\n", p->descricao);
        p = p->proximo;
    }
}

void atualiza(int numeroPoste, formularioReclamacao *primeiro) {
    formularioReclamacao *p;
    p = busca(numeroPoste, primeiro);
    if (p != NULL) {
        fflush(stdin);
        printf("Escreva o nome de quem esta atualizando o cadastro:\n");
        fgets(p->nome, 30, stdin);
        printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
        printf("\n0 - Problema resolvido");
        printf("\n1 - Luz queimada");
        printf("\n2 - Luz piscando");
        printf("\n3 - Sem luz");
        scanf("%d", &p->opcao);
        if (p->opcao != 0) {
            printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
            fflush(stdin);
            fgets(p->descricao, 400, stdin);
        } else strcpy(p->descricao, "Sem reclamacoes");
    }
    else printf("Nao e possivel atualizar postes que nao estao na lista");
}

void delete(int number, formularioReclamacao **primeiro, formularioReclamacao **final) {
    formularioReclamacao *p, *q, *r;
    p = busca(number, *primeiro);
    if (p != NULL) {
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
}
