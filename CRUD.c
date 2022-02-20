#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct complaintForm{
    int numberPoste;             //number of light pole
    int option;                 //option of complaint
    struct complaintForm *next;
    char description[400];     //description of the complaint
    char name[];              // name of who made the complaint
} complaintForm;
int searchPoste(complaintForm *primeiro, int posteBuscado, int auxPoste);

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
                aux2 = searchPoste(*primeiro, (*p)->numberPoste, auxPoste);
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

complaintForm *search(int numeroBuscado, complaintForm *primeiro){
    complaintForm *temp = primeiro;
    while (temp->next != NULL){
        if (temp->numberPoste == numeroBuscado){
            return temp;
        }else{
            temp = temp->next;
        }
    }
    if((temp->next==NULL)&&(temp->numberPoste != numeroBuscado)){
        printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
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
int searchPoste(complaintForm *primeiro, int posteBuscado, int auxPoste) {
    int aux = 0, contador=0, w;
    complaintForm *temp;
    temp = primeiro;
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
    complaintForm *p=primeiro;
    while (p->next != NULL){
        printf("\nNumero do poste: %d", p->numberPoste);
        printf("\nNumero da reclamacao: %d", p->option);
        printf("\nNome de quem fez a reclamacao: %s", p->name);
        printf("\nDescricao do problema: ");
        printf("\n%s", p->description);
        p = p->next;
    }
}
void update(int numberPoste, complaintForm *primeiro){
    complaintForm *p;
    p = search(numberPoste, primeiro);
    printf("\nDigite o seu nome:  ");
    gets(p->name);
    printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
    printf("\n0 - Problema resolvido");
    printf("\n1 - Luz queimada");
    printf("\n2 - Luz piscando");
    printf("\n3 - Sem luz");
    scanf("%d", &p->option);
    if(p->option != 0){
        printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
        fflush(stdin);
        fgets(p->description, 400, stdin);
    }else{
        strcpy(p->description, "Sem reclamacoes");
    }
}

void *delete (int number, complaintForm *primeiro){
    complaintForm *p, *q, *r;
    p = search(number, primeiro);
    if(p->next == NULL){    //deleting the last one
        free(p);
        p = NULL;
        return primeiro;
    }else if(p == primeiro){   //deleting the first one
        q = p->next;
        free(p);
        p = q;
        primeiro = p;
        return primeiro;
    }
    else{
        q = primeiro;
        while(q->next->numberPoste != p->numberPoste){
            q = q->next;
        }
        r = p->next;
        free(p);
        p = NULL;
        q->next = r;
        return primeiro;
    }
}

int main() {
    int nInserir, auxInserir=1, auxWhile=0, db, auxPoste, numberPoste;
    complaintForm *p=NULL, *auxLink=NULL, *primeiro=NULL;
    while(auxWhile != 9){
        printf(" Digite 1 se deseja inserir alunos:\n Digite 2 se deseja exebir a lista: \n Digite 3 se deseja buscar um aluno pela matricula/ posicao;\n Digite 9 se deseja terminar o programa: \n");
        scanf("%d", &auxWhile);
        if (auxWhile == 1){
            printf("Quantos alunos deseja inserir?\n");
            scanf("%d", &nInserir);
            if(nInserir<9999&&(auxInserir < 9999)){
                nInserir= auxInserir + nInserir;
                inserirPoste(&p, &auxLink, &primeiro, auxInserir, nInserir, auxPoste);
                auxInserir = nInserir;
            }
            else
                printf("A lista nao comporta essa alocacao, ou por estar cheia, ou a quantidade de elementos a ser inserido era muito grande.\nLista limitada a 9.999 insercoes.\n");
        }
        else if(auxWhile == 2){
            show(primeiro);
        }
        else if(auxWhile == 3){
            printf("Digite numero do poste que deseja buscar");
            scanf("%d", &numberPoste);
            search(numberPoste, primeiro);
        }
        else if(auxWhile == 4){
            printf("Digite numero do poste que deseja buscar a fim de atualizar o mesmo na lista");
            scanf("%d", &numberPoste);
            update(numberPoste, primeiro);
        }
        else if(auxWhile == 5){
            printf("Digite numero do poste que deseja buscar a fim de deletar da lista");
            scanf("%d", &numberPoste);
            delete(numberPoste, primeiro);
        }
    }
    return 0;
}
