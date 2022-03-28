#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct poste{
    struct poste *proximo, *anterior;
    int numeroPoste; // numero do poste der luz
    int opcao;       // opção de reclamação
    char descricao[400]; // descrição da reclamação
    char cpf[11];        // cpf de quem fez a reclamação
    char nome[30];       // nome de quem fez a reclamação
}poste;

typedef struct rua{
    int numeroRua;
    char nomeRua[50];
    struct poste *poste;
} rua;

void imprirString(char palavra[]);
void cadastrarRua(rua vet[], int inicio, int final);
int buscaNomeRua(rua v[], int tamanho);
void exibirRua(rua v[], int final);

void inserirPoste(poste **primeiro, poste **final, int inicio, int fim);
poste *busca(int numeroBuscado, poste *primeiro);
void exibe(poste *primeiro);
void atualiza(int numeroPoste, poste *primeiro);
void delete (int number, poste **primeiro, poste **final);

int main() {
    int qtdPostes, auxInserir = 1, auxWhile = 9, numeroPoste, auxWhile2=0, finalRua, insercaoRua=0, inicioRua=0, tempBuscaRua;
    poste *tempBusca=NULL;
    rua v[1000], primeiro[1000], final[1000];

    while(auxWhile2!=9) {
        printf("Digite 1 se deseja adicionar uma rua:\nDigite 2 para buscar uma rua pelo nome\n Digite 3 para exibir todas ruas\n Digite 4 para fazer operacoes em um poste");
        scanf("%d", &auxWhile2);
        if(auxWhile2==1){
            printf("Digite quantas ruas deseja inserir:\n");
            scanf("%d", &insercaoRua);
            finalRua=insercaoRua+inicioRua;
            cadastrarRua(v, inicioRua, finalRua);
            inicioRua=finalRua;
        }
        if(auxWhile2==2){
            tempBuscaRua=buscaNomeRua(v, finalRua);
            if(tempBuscaRua==-1)
                printf("Nao tem uma rua com esse nome");
            else
                printf("Rua numero: %d", tempBuscaRua);
        }

        if(auxWhile2==3){
            exibirRua(v, finalRua);
        }
        if(auxWhile2==4){
            auxWhile=0;
            printf("Digite qual a rua que deseja modificar os postes:\n ");
            scanf("%d", &tempBuscaRua);
        }
        while (auxWhile != 9) {
            printf("\n Digite 1 se deseja inserir postes:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar um poste pela posicao na lista:\n Digite 4 para atualizar um cadastro do poste:\n Digite 5 para deletar um poste:\n Digite 6 se deseja exibir o historico de operacoes realizadas:\n Digite 9 se deseja ir para a parte de rua\n");
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
        }
    }
    /*
 * int qtdPostes, auxInserir = 1, auxWhile = 0, numeroPoste;
rua *primeiro = NULL, *final, *tempBusca=NULL;
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
        printf("\n Poste encontrado\n Nome de quem fez o cadastro: %s CPF: %s \n setor: %s Telefone: %s \n Opcao de reclamacao: %d\n Descricao do problema: %s\n\n", tempBusca->nome, tempBusca->cpf, tempBusca->setor, tempBusca->telefone, tempBusca->opcao, tempBusca->descricao);
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
 */
    return 0;
}

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
        printf("\nNome de quem fez a reclamacao: %s", p->nome);
        printf("\nCPF de quem fez a reclamacao: %s", p->cpf);
        printf("\nDescricao do problema:\n ");
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

void cadastrarRua(rua vet[], int inicio, int final){
    int i=inicio, j=final;
    for (i; i < j; i++) {
        vet[i].numeroRua=i;
        printf("Rua numero: %d\n", i);
        printf("\nDigite a o nome da rua:");
        fflush(stdin);
        fgets(vet[i].nomeRua, 50, stdin);
    }
}


int buscaNomeRua(rua v[], int tamanho){
    int i=0, comp;
    char nome[50];
    printf("Digite o nome da rua que deseja buscar\n");
    fflush(stdin);
    fgets(nome, 50, stdin);
    while(i<=tamanho){
        i++;
        comp=strcmp(nome, v[i].nomeRua);
        if(comp==0)
            return i;
    }
    return -1;
}
void imprirString(char palavra[]){
    int i = 0;

    while(palavra[i] != '\0'){
        printf("%c", palavra[i]);
        i++;
    }
    printf("\n");
}

void exibirRua(rua v[], int final){
    int i=0;
    while(i<=final){
        printf("Rua numero: %d", &v[i].numeroRua);
        imprirString(v[i].nomeRua);
        i++;
    }
}
