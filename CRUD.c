#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct poste{
    struct poste *proximo, *anterior, *primeiro, *final;
    int numeroPoste; // numero do poste da luz
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

void cadastrarRua(rua **primeiro, rua **final, int inicio, int fim);
void atualizaRua(int numeroRua, rua *primeiro);
rua *buscaRua(int numeroBuscado, rua *primeiro);
void exibirRua(rua *v);
void exibirRuaPostes(rua *primeiro);

void inserirPoste(rua **busca, int inicio, int fim, char nome[][30]);
void inserirPosteOperador(rua **busca, int inicio, int fim, char nome[][30]);
poste *buscaPoste(int numeroBuscado, poste *primeiro);
void exibePoste(poste *primeiro);
void atualizaPoste(int numeroPoste, poste *primeiro, char nome[][30]);
void deletePoste (int number, poste **primeiro, poste **final);

int main() {
    int qtdPostes, auxInserir = 1, auxWhile = 9, numeroPoste, auxWhile2=9, finalRua, insercaoRua=0, inicioRua=0, tempBuscaRua, auxWHile3=0, auxWhile4=0;
    char nomeCliente[30];
    poste *tempBusca=NULL;
    rua *primeiro=NULL, *final=NULL, *ruaBusca=NULL;
    printf("Instrucoes de uso:\nO programa e dividido em duas partes: a parte do operador e a do clientes\nO operador simula um agente da prefeitura que sera responsavel pelo cadastro de ruas, mas tambem de cadastrar postes na mesma\nNo cadastro de rua devera ser informado o nome da mesma\nO cadastro de poste pelo o operador e feita de maneira automatica, ele apenas tem que digitar quantos postes vai inserir naquela determinada rua, sendo que partiremos do pressuposto que por ser um poste novo, cadastrado pelo operador, ele estara sem defeitos/reclamacoes\nNa parte do cliente, nao vai ser permitido ao mesmo a insercao de ruas, passando essa tarefa apenas a operadores\nMas sera possivel ao cliente poder inserir postes, que talvez o operador nao tenha inserido, fazer reclamacoes, excluir postes, ou atualizar as caracteristicas dos mesmos\nAs funcoes acima o operador tambem pode fazer, e no caso de haver postes com supostas reclamacoes, em uma aplicacao pratica, o mesmo iria ate o lugar, conferiria a demanda e realizaria o conserto das irregularidades\nO projeto visa a melhora da qualidade de vida dos moradores da cidade, a facilitacao na comunicacao entre os agentes da prefeitura e os moradores, alem de possibilitar um maior controle da demanda e auxiliar outros servicos publicos, como a seguranca\nBom uso da aplicacao!!!\n\n\n");
    while(auxWHile3!=9) {
        printf("Digite 1 para ir para a pare dos operadores\nDigite 2 para ir para a parte dos cliente:\nDigite 9 caso deseje fechar o programa\n");
        scanf("%d", &auxWHile3);
        if (auxWHile3 == 1) {
            auxWhile2 = 0;
            while (auxWhile2 != 9) {
                printf("Digite 1 se deseja adicionar uma rua:\nDigite 2 para exibir a lista de ruas\nDigite 3 para exibir todas as ruas os postes em cada uma delas\nDigite 4 para mudar o nome de uma rua:\nDigite 5 para fazer operacoes em um poste de uma rua\nDigite 9 para voltar o programa\n");
                scanf("%d", &auxWhile2);
                if (auxWhile2 == 1) {
                    printf("Digite quantas ruas deseja inserir:\n");
                    scanf("%d", &insercaoRua);
                    finalRua = insercaoRua + inicioRua;
                    cadastrarRua(&primeiro, &final, inicioRua, finalRua);
                    inicioRua = finalRua;
                }
                else if (auxWhile2 == 2) {
                    exibirRua(primeiro);
                }
                else if(auxWhile2==3){
                    exibirRuaPostes(primeiro);
                }
                else if(auxWhile2==4){
                    if(primeiro!=NULL) {
                        printf("Digite o numero da rua que deseja modificar o nome:\n");
                        scanf("%d", &tempBuscaRua);
                        atualizaRua(tempBuscaRua, primeiro);
                    }
                    else printf("Nao ha ruas para serem atualizadas\n");
                }
                else if (auxWhile2 == 5) {
                    if(primeiro!=NULL) {
                        auxWhile = 0;
                        printf("Digite o numero da rua que deseja modificar os postes:\n ");
                        ruaBusca=NULL;
                        while (ruaBusca == NULL) {
                            scanf("%d", &tempBuscaRua);
                            ruaBusca = buscaRua(tempBuscaRua, primeiro);
                            if (ruaBusca == NULL) {
                                printf("\nErro, digite novamente!\n");
                            }
                        }
                    }
                    else
                        printf("Nao ha ruas cadastradas\n");
                }
                while (auxWhile != 9) {
                    printf("\nDigite 1 se deseja inserir postes:\nDigite 2 se deseja exebir a lista de postes:\nDigite 3 se deseja buscar um poste pelo seu numero:\nDigite 4 para atualizar um cadastro de um poste:\nDigite 5 para deletar um poste:\nDigite 9 se deseja ir para a parte de rua\n");
                    scanf("%d", &auxWhile);
                    strcpy( nomeCliente, "Operador");
                    if (auxWhile == 1) {
                        printf("Quantos postes deseja inserir?\n");
                        scanf("%d", &qtdPostes);
                        qtdPostes = auxInserir + qtdPostes;
                        inserirPosteOperador(&ruaBusca, auxInserir, qtdPostes, &nomeCliente);
                        auxInserir = qtdPostes;
                        fflush(stdin);
                    }
                    if(ruaBusca->poste!=NULL) {
                        if (auxWhile == 2) {
                            exibePoste(ruaBusca->poste->primeiro);
                        } else if (auxWhile == 3) {
                            printf("Digite numero do poste que deseja buscar\n");
                            scanf("%d", &numeroPoste);
                            tempBusca = buscaPoste(numeroPoste, ruaBusca->poste->primeiro);
                            if (tempBusca != NULL) {
                                printf("\nPoste encontrado\nNome de quem fez o cadastro: %sOpcao de reclamacao: %d\nDescricao do problema: %s\n\n",
                                       tempBusca->nome, tempBusca->opcao, tempBusca->descricao);
                            } else {
                                printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
                            }
                        } else if (auxWhile == 4) {
                            printf("Digite numero do poste que deseja atualizar\n");
                            scanf("%d", &numeroPoste);
                            atualizaPoste(numeroPoste, ruaBusca->poste->primeiro, &nomeCliente);
                        } else if (auxWhile == 5) {
                            printf("Digite numero do poste que deseja deletar\n");
                            scanf("%d", &numeroPoste);
                            deletePoste(numeroPoste, &ruaBusca->poste->primeiro, &ruaBusca->poste->final);
                        } else if (auxWhile == 9) {
                            auxWhile2 = 0;
                        }
                    }
                    else
                        printf("A lista de poste para essa rua se encontra vazia");
                }
            }
        } else if (auxWHile3 == 2) {
            auxWhile=0;
            while (auxWhile4 != 9) {
                printf("Digite 1 para exibir a lista de ruas:\nDigite 2 para exibir todas as ruas e os postes em cada uma delas\nDigite 3 para buscar uma rua e fazer operacoes na mesma envolvendo postes:\nDigite 9 para voltar o programa\n");
                scanf("%d", &auxWhile4);
                if(auxWhile4==1){
                    exibirRua(primeiro);
                }
                else if(auxWhile4==2){
                    exibirRuaPostes(primeiro);
                }
                else if(auxWhile4==3){
                    auxWhile=0;
                    ruaBusca=NULL;
                    while(ruaBusca==NULL) {
                        scanf("%d", &tempBuscaRua);
                        ruaBusca = buscaRua(tempBuscaRua, primeiro);
                        while (auxWhile!=9) {
                            printf("\nDigite 1 se deseja inserir postes:\nDigite 2 se deseja exebir a lista:\nDigite 3 se deseja buscar um poste pela posicao na lista:\nDigite 4 para atualizar um cadastro do poste:\nDigite 5 para deletar um poste:\nDigite 9 se deseja voltar o programa\n");
                            scanf("%d", &auxWhile);
                            if (auxWhile == 1) {
                                printf("Quantos postes deseja inserir?\n");
                                scanf("%d", &qtdPostes);
                                qtdPostes = auxInserir + qtdPostes;
                                fflush(stdin);
                                printf("Escreva o nome de quem esta realizando a reclamacao:\n");
                                fgets(nomeCliente, 30, stdin);
                                inserirPoste(&ruaBusca, auxInserir, qtdPostes, &nomeCliente);
                                auxInserir = qtdPostes;
                                fflush(stdin);
                            }
                            if (ruaBusca->poste != NULL) {
                                if (auxWhile == 2) {
                                    exibePoste(ruaBusca->poste->primeiro);
                                } else if (auxWhile == 3) {
                                    printf("Digite numero do poste que deseja buscar\n");
                                    scanf("%d", &numeroPoste);
                                    tempBusca = buscaPoste(numeroPoste, ruaBusca->poste->primeiro);
                                    if (tempBusca != NULL) {
                                        printf("\nPoste encontrado\nNome de quem fez o cadastro: %sOpcao de reclamacao: %d\nDescricao do problema: %s\n",
                                               tempBusca->nome, tempBusca->opcao, tempBusca->descricao);
                                    } else {
                                        printf("\nErro, poste nao econtrado, pois nao esta na lista!\n");
                                    }
                                } else if (auxWhile == 4) {
                                    fflush(stdin);
                                    printf("Escreva o nome de quem esta atualizando o cadastro:\n");
                                    fgets(nomeCliente, 30, stdin);
                                    printf("Digite numero do poste que deseja atualizar na lista\n");
                                    scanf("%d", &numeroPoste);
                                    atualizaPoste(numeroPoste, ruaBusca->poste->primeiro, &nomeCliente);
                                } else if (auxWhile == 5) {
                                    printf("Digite numero do poste que deseja deletar da lista\n");
                                    scanf("%d", &numeroPoste);
                                    deletePoste(numeroPoste, &ruaBusca->poste->primeiro, &ruaBusca->poste->final);
                                } else if (auxWhile == 9) {
                                    auxWhile4 = 0;
                                }
                            }
                            else
                                printf("A lista de poste para essa rua se encontra vazia");
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void cadastrarRua(rua **primeiro, rua **final, int inicio, int fim){
    int m = inicio, k = fim;
    rua *p=NULL, *q=NULL;
    for (m; m < k; m++) {
        p = (rua *) malloc(sizeof(rua));
        p->numeroRua=m;
        printf("Rua numero: %d\n", p->numeroRua);
        fflush(stdin);
        printf("Escreva o nome da rua:\n");
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

void atualizaRua(int numeroBuscado, rua *primeiro){
    rua *tempAux=NULL;
    tempAux= buscaRua(numeroBuscado, primeiro);
    printf("Digite o novo para a rua %d\n", tempAux->numeroRua);
    fflush(stdin);
    printf("Escreva o nome da rua:\n");
    fgets(tempAux->nomeRua, 30, stdin);
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

void exibirRua(rua *v){
    int numeroRua=0;
    if(v==NULL)
        printf("Nao ha ruas cadastradas, espere o operador fazer o cadastro das mesmas\n");
    while(v!=NULL){
        printf("Rua numero: %d; Nome: %s\n", v->numeroRua, v->nomeRua);
        v=v->proximo;
        numeroRua++;
    }
    printf("Quantidade de ruas: %d\n", numeroRua);
}

void exibirRuaPostes(rua *primeiro){
    poste *temp=NULL;
    int numeroRua=0, numeroPoste=0;
    if(primeiro!=NULL) {
        while (primeiro != NULL) {
            printf("Rua numero: %d; Nome rua: %s\n", primeiro->numeroRua, primeiro->nomeRua);
            if(primeiro->poste!=NULL){
                temp=primeiro->poste->primeiro;
                while(temp!=NULL){
                    printf("Poste numero: %d; Nome do cadastro: %s;\n Descricao da reclmacao: %s\n", temp->numeroPoste, temp->nome, temp->descricao);
                    temp=temp->proximo;
                    numeroPoste++;
                }
            }
            else printf("Nao ha poste nessa rua\n");
            primeiro=primeiro->proximo;
            numeroRua++;
        }
        printf("Quantidade de rua: %d; Quantidade de postes: %d;\n", numeroRua, numeroPoste);
    }
    else printf("Nao ha ruas cadastradas\n");
}

void inserirPoste(rua **busca, int inicio, int fim, char nome[][30]) {
    int m = inicio, k = fim;
    poste *p=NULL, *q=NULL;
    for (m; m < k; m++) {
        p = (poste *) malloc(sizeof(poste));
        p->primeiro=NULL;
        p->final=NULL;
        p->numeroPoste=m;
        printf("Poste numero: %d\n", p->numeroPoste);
        fflush(stdin);
        strcpy( p->nome, *nome);
        printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
        printf("\n0 - Sem reclamacoes");
        printf("\n1 - Luz queimada");
        printf("\n2 - Luz piscando");
        printf("\n3 - Sem luz\n");
        scanf("%d", &p->opcao);
        if (p->opcao == 0) strcpy(p->descricao, "Sem reclamacoes\n");
        else {
            printf("\nDigite a sua reclamacao (maximo de 400 caracteres):\n");
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

void inserirPosteOperador(rua **busca, int inicio, int fim, char nome[][30]) {
    int m = inicio, k = fim;
    poste *p=NULL, *q=NULL;
    for (m; m < k; m++) {
        p = (poste *) malloc(sizeof(poste));
        p->primeiro=NULL;
        p->final=NULL;
        p->numeroPoste=m;
        printf("Poste numero: %d\n", p->numeroPoste);
        fflush(stdin);
        strcpy( p->nome, *nome);
        p->opcao=0;
        strcpy(p->descricao, "Sem reclamacoes\n");
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

poste *buscaPoste(int numeroBuscado, poste *primeiro){
    poste *temp = primeiro;
    while (temp!= NULL){
        if (temp->numeroPoste == numeroBuscado){
            return temp;
        }
        temp = temp->proximo;
    }
    return NULL;
}

void exibePoste(poste *primeiro){
    poste *p = primeiro;
    int numeroPoste=0;
    while (p != NULL){
        printf("\nNumero do poste: %d", p->numeroPoste);
        printf("\nNome de quem fez a reclamacao: %s", p->nome);
        printf("\nDescricao do problema:\n ");
        printf("%s\n", p->descricao);
        p = p->proximo;
        numeroPoste++;
    }
    printf("Quantidade de postes nessa rua: %d\n", numeroPoste);
}

void atualizaPoste(int numeroPoste, poste *primeiro, char nome[][30]) {
    poste *p;
    p = buscaPoste(numeroPoste, primeiro);
    if (p != NULL) {
        strcpy( p->nome, *nome);
        printf("\nCaso deje realizar alguma reclamacao, digite o numero correspondente:");
        printf("\n0 - Problema resolvido");
        printf("\n1 - Luz queimada");
        printf("\n2 - Luz piscando");
        printf("\n3 - Sem luz\n");
        scanf("%d", &p->opcao);
        if (p->opcao != 0) {
            printf("\nDigite a sua reclamacao (maximo de 400 caracteres):\n");
            fflush(stdin);
            fgets(p->descricao, 400, stdin);
        } else strcpy(p->descricao, "Sem reclamacoes\n");
    }
    else printf("Nao e possivel atualizar postes que nao estao na lista\n");
}

void deletePoste(int number, poste **primeiro, poste **final) {
    poste *p, *q, *r;
    p = buscaPoste(number, *primeiro);
    if (p != NULL) {
        printf("Poste deletado\n");
        if (p == *primeiro) {
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
