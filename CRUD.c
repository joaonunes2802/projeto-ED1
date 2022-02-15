#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int number;         //number of light pole
    int option;         //option of complaint
    struct no *next, *previous;
    char description[400]; //description of the complaint
    char name[];           // name of who made the complaint
} complaintForm;

complaintForm *create(complaintForm *p){
    complaintForm *q, *r, *s;
    complaintForm *first = NULL;
    int  aux = 1;
    while (aux != 0)
    {
        if (first == NULL)
        {
            first = p;
            printf("\nDigite o numero de endereco IP do poste de luz: ");
            scanf("%d", &first->number); // Use scanf("%d%*c, &p->number") as alternative to fflush(stdin)
            fflush(stdin);
            printf("\nDigite o seu nome: ");
            gets(first->name);
            printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
            prinft("\n0 - Sem reclamacoes");
            prinft("\n1 - Luz queimada");
            prinft("\n2 - Luz piscando");
            prinft("\n3 - Sem luz");
            scanf("%d", &first->option);
            if (first->option == 0){
                first->description = "Sem reclamacoes";
            }else{
                printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
                fgets(first->description, 400, stdin);
            }
            printf("\nDeseja cadastrar mais algum poste?");
            printf("\nDigite 1 - sim; 0 - nao: ");
            scanf("%d", &aux);
            if (aux == 0){
                first->next = NULL;       //grouding the list
                first->previous = NULL;
                return first;
            }
            else
            {
                first->previous = NULL;
                q = first;      //q is now the previous element in the next round
            }
        }
        else
        {
            r = (complaintForm *)malloc(sizeof(complaintForm));     //alocation of memory
            printf("\nDigite o numero de endereco IP do poste de luz: ");
            scanf("%d", &first->number); 
            fflush(stdin);
            printf("\nDigite o seu nome: ");
            gets(first->name);
            printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
            prinft("\n0 - Sem reclamacoes");
            prinft("\n1 - Luz queimada");
            prinft("\n2 - Luz piscando");
            prinft("\n3 - Sem luz");
            scanf("%d", &first->option);
            if (first->option == 0){
                first->description = "Sem reclamacoes";
            }else{
                printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
                fgets(first->description, 400, stdin);
            }
            q->next = r;        //the previous "q" points to next wich is r         
            q->previous = s;    //and points to previous, wich is s
            printf("\nDeseja cadastrar mais um aluno(a)?");
            printf("\nDigite 1 - sim; 0 - nao: ");
            scanf("%d", &aux);
            if (aux == 0)
            {
                r->next = NULL;
                return first;
            }
            else
            {
                s = q;      //the previous to q recieves q
                q = r;      //and q recieves the atual
            }
        }
    }
}

void inserction(complaintForm *p){
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
}

complaintForm *search(int number2, complaintForm *q)
{
    while (q != NULL)
    {
        if (q->number == number2)
        {
            return q;
        }
        q = q->next;
    }
}

void update(int number, complaintForm *p){
    complaintForm *q;
    q = search(number, p);
    printf("\nDigite o seu nome:  ");
    fgets(q->name, 50, stdin);
    printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
    prinft("\n0 - Problema resolvido");
    prinft("\n1 - Luz queimada");
    prinft("\n2 - Luz piscando");
    prinft("\n3 - Sem luz");
    scanf("%d", &q->option);
    if(q->option == 0){
        q->description = "Sem reclamacoes";
    }else{
        printf("\nDigite a sua reclamacao (maximo de 400 caracteres):  ");
        fgets(q->description, 400, stdin);
    }
}
void delete (int number, complaintForm *p){
    complaintForm *q;
    q = search(number, p);
    if(q->next == NULL){    //deleting the last one
        free(q);
        q = NULL;
    }else if(q == p){   //deleting the first one
        q->next->previous = NULL;
        free(q);
        q = NULL;
    }else{
        q->next->previous = q->previous;    //q next points to q previous
        q->previous->next = q->next;        // q previpus points to q next
        free(q);
        q = NULL;
    }
}

void show(complaintForm *r)
{
    while (r != NULL)
    {
        printf("\nNumero do poste: %d", r->number);
        printf("\nNome: %s", r->name);
        r = r->next;
    }
}

int main()
{
    complaintForm *lista;
    complaintForm *listaPronta = NULL, *alunoBuscado = NULL;
    int resposta = 0, aux = 1;
    int numberAluno;
    printf("\nDeseja cadastrar um aluno(a) na lista de chamada?");
    printf("\nDigite 1 - sim; 0 - nao: ");
    scanf("%d", &resposta);
    if (resposta == 1)
    {
        lista = (complaintForm *)malloc(sizeof(complaintForm));
        if (lista == NULL)
        {
            printf("\nErro, nao foi possivel alocar memoria para esse elemento!");
            exit(1);
        }
        listaPronta = create(lista);
    }
    printf("\nDeseja procurar um aluno(a) na lista de chamada?");
    printf("\nDigite 1 - sim; 0 - nao: ");
    scanf("%d", &resposta);
    if (resposta == 1)
    {
        while (aux != 0)
        {
            printf("\nDigite o numero da number do(a) aluno(a): ");
            scanf("%d", &numberAluno);
            alunoBuscado = search(numberAluno, listaPronta);
            if (alunoBuscado == NULL)
            {
                printf("\nAluno(a) nao encontrado na lista de chamada!");
            }
            else
            {
                printf("\nnumber do aluno: %d", alunoBuscado->number);
                printf("\nNome do aluno: %s", alunoBuscado->nome);
            }
            printf("\nDeseja procurar mais algum aluno(a)?");
            printf("\nDigite 1-sim, 0-nao: ");
            scanf("%d", &aux);
        }
    }
    printf("\nDeseja exibir a lista de chamada?");
    printf("\nDigite 1 - sim; 0 - nao: ");
    scanf("%d", &resposta);
    if (resposta == 1)
    {
        show(listaPronta);
    }
    return 0;
}