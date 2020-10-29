#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//criacao struct funcionario
typedef struct funcionario {
    char nome[100];
    float salarioBase;
    float comissao;
} Funcionario;

//funcao de comparacao entre structs
int compare(const void *v1, const void *v2) {

    const Funcionario *f1 = v1;

    const Funcionario *f2 = v2;

    float salario1 = (f1->salarioBase)+(f1->comissao);

    float salario2 = (f2->salarioBase)+(f2->comissao);

    if (salario1 > salario2) return(+1);

    else if (salario1 < salario2) return(-1);

    else if (strcmp(f1->nome, f2->nome) > 0) return(+1);

    else if (strcmp(f1->nome, f2->nome) < 0) return(-1);

    else return(0);
}

int main() {

    int qtddFuncionarios = 0;

    float auxSalario = 0; //auxiliar de comparacao entre salarios

    Funcionario funcionarios[100];

    for(int i=0; i<=100; i++) {

        if(i>0) getchar();

        fgets(funcionarios[i].nome, 101, stdin);

        if(strcmp(funcionarios[i].nome,"FIM\n") == 0) break;

        else {
          if ((funcionarios[i].nome[strlen (funcionarios[i].nome) - 1] == '\n'))
            funcionarios[i].nome[strlen (funcionarios[i].nome) - 1] = '\0';
        }

        scanf("%f", &funcionarios[i].salarioBase);

        scanf("%f", &funcionarios[i].comissao);

        qtddFuncionarios++;
    }

    qsort(funcionarios, qtddFuncionarios, sizeof(Funcionario), compare);

    printf("Folha de Pagamento\n");

    for(int i=0; i<qtddFuncionarios; i++){
      // printf("%s\n", funcionarios[i].nome );
        float salario = funcionarios[i].salarioBase + funcionarios[i].comissao;

        if(auxSalario != salario) {

            printf("\nSalario no Mes: R$ %.2f\n", salario);
            auxSalario = salario;
        }

        printf("- %s\n", funcionarios[i].nome);
    }

    return 0;
}
