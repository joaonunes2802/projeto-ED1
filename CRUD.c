#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct formularioReclamacao{
    int numeroPoste; // numero do poste der luz
    int opcao;      // opção de reclamação
    struct formularioReclamacao *proximo, *anterior;
    char descricao[400]; // descrição da reclamação
    char cpf[11]; //cpf de quem fez a reclamação
    char endereco[30]; // endereço
    char telefone[11]; //telefone de quem fez a reclamação
    char nome[30];  // nome de quem fez a reclamação
} formularioReclamacao;

void inserirPoste(formularioReclamacao **primeiro, formularioReclamacao **final, int inicio, int fim);
formularioReclamacao *busca(int numeroBuscado, formularioReclamacao *primeiro);
void exibe(formularioReclamacao *primeiro);
void atualiza(int numeroPoste, formularioReclamacao *primeiro);
void delete (int number, formularioReclamacao **primeiro, formularioReclamacao **final);
//int rotasegura(formularioreclamacao *primeiro);

int main() {
    int qtdPostes, auxInserir = 1, auxWhile = 0, numeroPoste;
    formularioReclamacao *primeiro = NULL, *final, *tempBusca=NULL;
    struct tm *data_hora;             // struct que armazena data e hora
    time_t segundos;                        // variável para aemazenar o tempo em segundos
    time(&segundos);                         // obtendo o tempo em segundos
    data_hora = localtime(&segundos); // convertendo o tempo em segundos para o tempo local
    FILE *log;
    if(log = fopen("log.txt", "r")){     //Testa se o arquivo já existe
        fclose(log);
    }else{
        log = fopen("log.txt", "w+");
        if (log == NULL)
        {
            printf("\nErro, arquivo de log nao pode ser aberto!");
            exit(0);
        }
        else
        {
            fflush(stdin);
            fputs("Abertura do programa!!", log);
            fprintf(log, "\nPrograma iniciado as %d:%d:%d de %d/%d/%d", data_hora->tm_hour, data_hora->tm_min, data_hora->tm_sec, data_hora->tm_mday, data_hora->tm_mon + 1, data_hora->tm_year + 1900);
            fclose(log);
        }
    }
    

    while (auxWhile != 9){
        printf("\n Digite 1 se deseja inserir postes:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar um poste pela posicao na lista:\n Digite 4 para atualizar um cadastro do poste:\n Digite 5 para deletar um poste:\n Digite 6 se deseja exibir o historico de operacoes realizadas:\n Digite 9 se deseja terminar o programa: \n");
        scanf("%d", &auxWhile);
        if (auxWhile == 1){
            printf("Quantos postes deseja inserir?\n");
            scanf("%d", &qtdPostes);
            if (qtdPostes < 9999 && (auxInserir < 9999)){
                qtdPostes = auxInserir + qtdPostes;
                inserirPoste( &primeiro, &final, auxInserir, qtdPostes);
                auxInserir = qtdPostes;
                fflush(stdin);
                log = fopen("log.txt", "a");
                if(log == NULL){
                    printf("\nErro, arquivo de log nao pode ser aberto!");
                    exit(0);
                }
                fprintf(log, "\nIsercao de novos postes as %d:%d:%d de %d/%d/%d", data_hora->tm_hour, data_hora->tm_min, data_hora->tm_sec, data_hora->tm_mday, data_hora->tm_mon+1, data_hora->tm_year+1900);
                fclose(log);
            }
            else
                printf("A lista nao comporta essa alocacao, ou por estar cheia, ou a quantidade de elementos a ser inserido era muito grande.\nLista limitada a 9.999 insercoes.\n");
        }
        else if (auxWhile == 2){
            exibe(primeiro);
        }
        else if (auxWhile == 3){
            printf("Digite numero do poste que deseja buscar\n");
            scanf("%d", &numeroPoste);
            tempBusca=busca(numeroPoste, primeiro);
            if(tempBusca!=NULL){
                printf("\n Poste encontrado\n Nome de quem fez o cadastro: %s CPF: %s \n Endereco: %s Telefone: %s \n Opcao de reclamacao: %d\n Descricao do problema: %s\n\n", tempBusca->nome, tempBusca->cpf, tempBusca->endereco, tempBusca->telefone, tempBusca->opcao, tempBusca->descricao);
            }
            else     printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
        }
        else if (auxWhile == 4){
            printf("Digite numero do poste que deseja atualizar na lista\n");
            scanf("%d", &numeroPoste);
            atualiza(numeroPoste, primeiro);
            log = fopen("log.txt", "a");
            if(log == NULL){
                printf("\nErro, nao foi possivel abrir o arquivo de log!\n");
                exit(0);
            }
            fprintf(log, "\nAtualizacao da lista de postes as %d:%d:%d de %d/%d/%d", data_hora->tm_hour, data_hora->tm_min, data_hora->tm_sec, data_hora->tm_mday, data_hora->tm_mon+1, data_hora->tm_year+1900);
            fclose(log);
        }
        else if (auxWhile == 5){
            printf("Digite numero do poste que deseja deletar da lista\n");
            scanf("%d", &numeroPoste);
            delete (numeroPoste, &primeiro, &final);
            log = fopen("log.txt", "a");
            if (log == NULL){
                printf("\nErro, nao foi possivel abrir o arquivo de log!\n");
                exit(0);
            }
            fprintf(log, "\nAcionamento da operacao de delete de um poste da lista as %d:%d:%d de %d/%d/%d", data_hora->tm_hour, data_hora->tm_min, data_hora->tm_sec, data_hora->tm_mday, data_hora->tm_mon+1, data_hora->tm_year+1900);
            fclose(log);
        }
        else if (auxWhile == 6){
            log = fopen("log.txt", "r");
            if (log == NULL){
                printf("\nErro, nao foi possivel abrir o arquivo de log!\n");
                exit(0);
            }
            char exibe[100];
            while(fgets(exibe, 100, log) != NULL){
                printf("%s", exibe);
            }
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
        printf("Escreva o CPF de quem esta realizando a reclamacao:\n");
        fflush(stdin);
        fgets(p->cpf, 11, stdin);
        printf("Escreva o endereco de quem esta realizando a reclamacao (digite no maximo 30 caracteres):\n");
        fflush(stdin);
        fgets(p->endereco, 30, stdin);
        printf("Escreva o telefone de quem esta realizando a reclamacao:\n");
        fflush(stdin);
        fgets(p->telefone, 11, stdin);
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

formularioReclamacao *busca(int numeroBuscado, formularioReclamacao *primeiro){
    formularioReclamacao *temp = primeiro;
    while (temp!= NULL){
        if (temp->numeroPoste == numeroBuscado){
            return temp;
        }
        temp = temp->proximo;
    }
    return NULL;
}

void exibe(formularioReclamacao *primeiro){
    formularioReclamacao *p = primeiro;
    while (p != NULL){
        printf("\nNumero do poste: %d", p->numeroPoste);
        printf("\nNome de quem fez a reclamacao: %s", p->nome);
        printf("CPF de quem fez a reclamacao: %s", p->cpf);
        printf("\nEndereco de quem fez a reclamacao: %s", p->endereco);
        printf("Telefone de quem fez a reclamacao: %s", p->telefone);
        printf("\nNumero da reclamacao: %d", p->opcao);
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
        printf("Escreva o seu CPF:\n");
        fflush(stdin);
        fgets(p->cpf, 11, stdin);
        printf("Escreva o seu endereco (digite no maximo 30 caracteres):\n");
        fflush(stdin);
        fgets(p->endereco, 30, stdin);
        printf("Escreva o seu telefone:\n");
        fflush(stdin);
        fgets(p->telefone, 11, stdin);
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

void delete(int number, formularioReclamacao **primeiro, formularioReclamacao **final) {
    formularioReclamacao *p, *q, *r;
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
