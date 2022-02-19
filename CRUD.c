#include <stdio.h>
#include <stdlib.h>

typedef struct complaintForm{
    int numberPoste;         //number of light pole
    int option;         //option of complaint
    struct complaintForm *next;
    char name[50];        //name of who made the complaint
    char description[400]; //description of the complaint
} complaintForm;
int searchNumero(complaintForm *primeiro, int posteBuscado, int auxPoste);

void inserirPoste(complaintForm **p, complaintForm **primeiro, complaintForm **auxLink, int inicio, int final, int auxPoste){
    int aux, aux2, m=inicio, k=final;
    for(m; m<k; m++) {
        *p = (complaintForm*) malloc(sizeof(complaintForm));
        printf("Digite o numero do poste a ser inserido complaintForm sistema, entre 1 e 9999: se ja houver um poste com esse numero, digite novamente:\n");
        aux=0;
        while(aux==0){
            (*p)->numberPoste=-1;
            while(((*p)->numberPoste<0)||((*p)->numberPoste>9999)) {
                scanf("%d", &(*p)->numberPoste);
            }
            if(*primeiro!=NULL){
                aux2 = searchNumero(*primeiro, (*p)->numberPoste, auxPoste);
                if(aux2 != 1)
                    aux=1;
                else
                    aux=0;
            }
            else
                aux=1;
        }
        fflush(stdin);
        printf("Escreva o nome de quem esta realizando a reclamacao:\n");
        fgets((*p)->name, 30, stdin);
        (*p)->next = NULL;
        if (*primeiro == NULL) {
            *primeiro = *p;
        } else {
            (*auxLink)->next = *p;
        }
        *auxLink=*p;
    }
}
complaintForm *search(complaintForm *primeiro, int numberPoste){
    complaintForm *temp=primeiro;
    while (temp->next != NULL){
        if (temp->numberPoste == numberPoste){
            return temp;
        }
        else
            temp = temp->next;
    }
    if((temp->next==NULL)&&(temp->numberPoste != numberPoste)){
        temp=NULL;
        return temp;
    }
}

/*void inserction(complaintForm *p){
    complaintForm *aux;
    printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
    prinft("\n0 - Sem reclamacoes");
    prinft("\n1 - Luz queimada");
    prinft("\n2 - Luz piscando");
    prinft("\n3 - Sem luz");
    scanf("%d", &aux->option);
    if(aux->option == 0){
        aux->description = "Sem reclamacoes";
    }else{
        printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
        fgets(aux->description, 400, stdin);
    }
    aux->next = p->next;
    p->next = aux;
    aux->previous = p;
    aux->next->previous = aux;
}*/
int searchNumero(complaintForm *primeiro, int posteBuscado, int auxPoste) {
    int aux = 0, contador=0, w;
    complaintForm *temp=primeiro;
    while ((temp != NULL) && (aux == 0)) {
        if((temp)->numberPoste == posteBuscado){
            aux=1;
        }
        else{
            temp=(temp)->next;
            contador++;
        }
    }
    contador++;
    if(aux==1){
        if (auxPoste == 1){
            printf("O aluno foi achado, espaco indisponivel para insercao\n  Posicao na lista: %d\n  Matricula %d\n  Nome: %s\n", contador, posteBuscado);
        }
        w=1;
        return w;
    }
    else {
        if (auxPoste == 1) {
            printf("Essa matricula nao esta na lista ainda, espaco disponivel para insercao\n");
        }
        w=5;
        return w;
    }
}

void show(complaintForm *primeiro){
    complaintForm *r=primeiro;
    while (r != NULL){
        printf("\nNumero do poste: %d", r->numberPoste);
        printf("\nNome: %s", r->name);
        r = r->next;
    }
}
void update(complaintForm *primeiro,int numberPoste){
    complaintForm *q;
    q = search(primeiro, numberPoste);
    printf("\nDigite o seu nome:  ");
    fgets(q->name, 50, stdin);
    printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
    printf("\n0 - Problema resolvido");
    printf("\n1 - Luz queimada");
    printf("\n2 - Luz piscando");
    printf("\n3 - Sem luz");
    scanf("%d", &q->option);
    if(q->option != 0){
        printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
        fflush(stdin);
        fgets(q->description, 400, stdin);
    }
}

void delete (complaintForm *primeiro, int numberPoste){
    complaintForm *q, *temp=NULL;
    q = search(primeiro, numberPoste);
    if(q->next == NULL){    //deleting the last one
        free(q);
        q = NULL;
    }else if(q == primeiro){   //deleting the first one
        q->next = NULL;
        free(q);
        q = NULL;
    }
    else{
        while(q->next!=NULL){
            temp=q;
            q=q->next;
            q->next=temp;
        }
        free(temp);
    }
}

int main() {
    int nInserir, auxInserir = 1, auxWhile = 0, auxPoste, numberPoste;
    complaintForm *p = NULL, *auxLink = NULL, *primeiro = NULL;
    while (auxWhile != 9) {
        printf(" Digite 1 se deseja inserir alunos:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar o poste pelo number id do mesmo;\n Digite 4 se deseja buscar um poste pela posicao na lista\n Digite 5 se deseja atualizar a lista\n Digite 6 se deseja remover\n Digite 9 se deseja terminar o programa: \n");
        scanf("%d", &auxWhile);
        if (auxWhile == 1) {
            printf("Quantos alunos deseja inserir?\n");
            scanf("%d", &nInserir);
            if (nInserir < 9999 && (auxInserir < 9999)) {
                auxPoste = 0;
                nInserir = auxInserir + nInserir;
                inserirPoste(&p, &primeiro, &auxLink, auxInserir, nInserir, auxPoste);
                auxInserir = nInserir;
            } else
                printf("A lista nao comporta essa alocacao, ou por estar cheia, ou a quantidade de elementos a ser inserido era muito grande.\nLista limitada a 9.999 insercoes.\n");
        } else if (auxWhile == 2) {
            show(primeiro);
        } else if (auxWhile == 3) {
            auxPoste = 1;
            printf("Digite numero do poste que deseja buscar");
            scanf("%d", &numberPoste);
            searchNumero(primeiro, numberPoste, auxPoste);
        } else if (auxWhile == 4) {
            printf("Digite a posicao do poste que deseja buscar");
            scanf("%d", &numberPoste);
            search(primeiro, numberPoste);
        } else if (auxWhile == 5) {
            printf("Digite numero do poste que deseja buscar a fim de atualizar o mesmo na lista");
            scanf("%d", &numberPoste);
            update(primeiro, numberPoste);
        } else if (auxWhile == 6) {
            printf("Digite numero do poste que deseja buscar a fim de deletar da lista");
            scanf("%d", &numberPoste);
            delete(primeiro, numberPoste);
        }
    }
    return 0;
}
