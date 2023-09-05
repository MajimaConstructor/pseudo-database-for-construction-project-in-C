#include <stdio.h>
#include <stdlib.h>

#define MAX_SENHA 50
#define MAX_TENTATIVAS 3

int main(){

    int senha_correta = 0;
    char senha[MAX_SENHA];

    int i = 0;
    char nome[50];
    int cpf;
    int tel;
    int caso;
    char dec1;
    char dec2;
    char dec3;
    int tentativas = 0;

    while(tentativas < MAX_TENTATIVAS){
    printf("Digite a senha: ");
    fgets(senha, MAX_SENHA, stdin);

    if(senha[strlen(senha) - 1] == '\n'){
        senha[strlen(senha)-1] = '\0';
    }
    if(strcmp(senha, "suasenha") == 0) {
        senha_correta = 1;
        printf("Senha correta! Acesso concedido.\n");
        break;
    } else {
        printf("Senha incorreta! Acesso negado.\n");
        tentativas++;
    }
}

    if (!senha_correta) {
        printf("Acesso negado. Tentativas esgotadas.\n");
        return 1;
    }

    FILE *banco;

    printf("Banco de Dados:\n");
    printf("1 - cadastro\t2 - calculo de area\t3 - calculo de orcamento\t4 - impressao\t5 - sair\n");
    scanf("%d", &caso);
    getchar();

    switch(caso){
    case 1:
        do{
                fflush(stdin);

        printf("Digite o nome do cliente: ");
        fgets(nome, 50, stdin);

        printf("Digite o cpf do cliente: ");
        scanf("%d", &cpf);
        getchar();

        printf("Digite o telefone do cliente: ");
        scanf("%d", &tel);
        getchar();

        printf("Deseja salvar a operacao? (s/n) ");
        scanf("%c", &dec1);
        getchar();


        if(dec1 == 's' || dec1 == 'S'){
               FILE * banco = fopen("banco.txt", "a");
            fprintf(banco, "nome: %s\n", nome);
            fprintf(banco, "cpf: %d\n", cpf);
            fprintf(banco, "telefone: %d\n", tel);
            fclose(banco);
        }else{
            printf("nao foi salva a operacao. \n");
        }

        printf("Deseja continuar a operacao? (s/n) ");
        scanf("%c", &dec2);
        getchar();
            }while(&dec2 == 's' || &dec2 == 'S');

            break;

    case 2:
        for(i = 0; i < 5; i++){
                float b;
                float h;
            printf("Digite o tamanho da base: ");
            scanf("%f", &b);

            printf("digite o tamanho da altura: ");
            scanf("%f", &h);

            double a = b * h;

            banco = fopen("banco.txt", "a");
            fprintf(banco, "Area %i: %.2f\n", i+1, a);
            fclose(banco);
            getchar();
        }
        break;

    case 3:
        for(i = 0; i < 1; i++){
            float materiaisquad;
            float area;
            float customaterial;
            float resultado;

            printf("Digite o tamanho da area total que deseja construir: ");
            scanf("%f", &area);
            fflush(stdin);

            printf("Digite quantos quilogramas de material sera utilizado por metro quadrado: ");
            scanf("%f", &materiaisquad);
            fflush(stdin);

            printf("Digite o custo dos materiais que serao utilizados: ");
            scanf("%f", &customaterial);
            fflush(stdin);

            resultado = area * materiaisquad * customaterial;

            FILE * banco = fopen("banco.txt", "a");
            fprintf(banco, "custo de construcao do quarto %i: %.2f\n", i+1, resultado);
            fclose(banco);
        }
        break;

    case 4:
        banco = fopen("banco.txt", "r");

    if (banco == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        char linha[100];
        while (fgets(linha, sizeof(linha), banco) != NULL) {
            printf("%s", linha);
        }
        fclose(banco);
    }
        break;

    case 5:
        return 0;
    break;
    }

    fprintf(banco,"Teste de Bancos\n");
    fclose(banco);
    return 0;
}
