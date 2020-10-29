#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
  char nome[100];
  float salarioBase, comissao;
};

int comparaSalarioENome(const void *f1, const void *f2);
float getSalario(struct funcionario *f);
void ordenaEPrinta(struct funcionario *funcionarios, int contador);


// função pra pegar o salario total do funcionario
float getSalario(struct funcionario *f) {
  return f->comissao + f->salarioBase;
}

// função de comparação especifica para minha necessidade que vai ser usada no qsort.
int comparaSalarioENome(const void *f1, const void *f2){
  struct funcionario *ff1 = (struct funcionario *)f1;
  struct funcionario *ff2 = (struct funcionario *)f2;
  // Aqui ordena pelo salario de forma crescente.
  int valor =  getSalario(ff1) - getSalario(ff2);
  // se os salarios farem iguais, compara pelo nome, menor que zero caso o primeiro nome seja menor que o segundo,
  // maior se o o contrario e zero caso sejam iguais.
  // (como o retorno é numero funciona bem na func. de comparação do qsort)
  if (valor == 0) {
    // função que compara os nomes de forma a ver char por char, qual tem o primeiro
    return strcmp(ff1->nome, ff2->nome);
  }
  return valor;
}

void ordenaEPrinta(struct funcionario *funcionarios, int contador) {
  // Função de ordenação que recebe como parametro o array a ser ordenado, o numero de elementos, o tamanho dos elementos
  // e um ponteiro pra uma função de comparação que é chamada varias vezes para ordenar o Array principal.
  qsort(funcionarios, contador, sizeof(struct funcionario), comparaSalarioENome);
  printf("Folha de Pagamento\n");
  float salarioAtual = getSalario(&funcionarios[0]);
  // Uma vez que o array foi ordenado eu só percorro ele exibindo o salario do mes, e caso o salario atual for diferente
  // do proximo salario, eu redefino o salario atual, e reexibo o header de salario dos funcionarios.
  for(int iii = 0; iii < contador; iii++){
    if(iii == 0 || salarioAtual != getSalario(&funcionarios[iii])) {
      salarioAtual = getSalario(&funcionarios[iii]);
      printf("\nSalario no Mes: R$ %.2f\n", salarioAtual);
    }
    if(salarioAtual == getSalario(&funcionarios[iii])){
      printf("- %s\n", funcionarios[iii].nome);
    }
  }
}

int main () {
  struct funcionario* funcionarios;
  funcionarios = (struct funcionario*) malloc(100*sizeof(struct funcionario));
  int contador = 0;
  // Leitura dos dados dos funcionarios
  while(contador < 100) {
    fgets(funcionarios[contador].nome, 101, stdin);
    // removo o '\n' do fim da String e coloco '\0', removo quebra de linha e coloca um fim de linha.
    if ((strlen(funcionarios[contador].nome) > 0) && (funcionarios[contador].nome[strlen (funcionarios[contador].nome) - 1] == '\n')) {
      funcionarios[contador].nome[strlen (funcionarios[contador].nome) - 1] = '\0';
    }
    // Se o nome inputado for começado por "FIM" sai do loop
    if(funcionarios[contador].nome[0] == 70 && funcionarios[contador].nome[1] == 73 && funcionarios[contador].nome[2] == 77) {
      break;
    }
    float v1, v2;
    scanf("%f\n%f", &v1, &v2);
    funcionarios[contador].salarioBase = v1;
    funcionarios[contador].comissao = v2;
    // Precisei por esse getchar aqui, n sei pq pra ser sincero, mas deve ter algum input bisonho perdido.
    getchar();
    contador +=1;
  }
  // Chama o metodo de ordenação e exibição, separei pra facilitar meus testes, não tinha muita necessidade eu acho.
  ordenaEPrinta(funcionarios, contador);

  return 0;
}
