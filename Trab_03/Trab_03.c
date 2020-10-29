#include <stdio.h>
// Aqui comecei a assinatura de todas funções que eu ia usar
// Começando pelos de Cálculo que são dados no enunciado.
int calcSeculo(int ano);
int getAureo(int ano);
int getX(int seculo);
int getZ(int seculo);
int epacta(int g, int x, int z);
int getD(int ano, int x);
int getN(int e);
// Aqui 2 que se repetem todo mẽs, que é a linha pontilhada, e a linha com dias da semana.
void dashes();
void comecaSemana();
// Função resposável por escrever o mês, de acordo com o dia de inicio dele,
// e a quantidade de dias.
int processaMes(int primeiroDiaSemana, int quantidadeDeDias);
int convertePrimeiroDiaDoAno(int dia);



int main () {
  int ano;
  scanf("%i", &ano);
  int seculo = calcSeculo(ano);
  int g = getAureo(ano);
  int x = getX(seculo);
  int z = getZ(seculo);
  int e = epacta(g, x, z);
  int n = getN(e);
  int d = getD(ano, x);

  int diasPosComecoMarco = (n + 7) - ((d+n)%7);
  int diasJaneiroEFevereiro = ano%4 == 0 ? 60 : 59;
  int primeiroDiaDaSemana = convertePrimeiroDiaDoAno(((diasJaneiroEFevereiro + diasPosComecoMarco) % 7));
  printf("Calendario do ano %i\n", ano);
  dashes();
  int iterator = 0;
  while (iterator <= 11) {
    switch (iterator) {
      case 0:
      printf("|Janeiro                      |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 31);
      break;
      case 1:
      printf("|Fevereiro                    |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, ano%4>0 ? 28 : 29);
      break;
      case 2:
      printf("|Março                        |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 31);
      break;
      case 3:
      printf("|Abril                        |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 30);
      break;
      case 4:
      printf("|Maio                         |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 31);
      break;
      case 5:
      printf("|Junho                        |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 30);
      break;
      case 6:
      printf("|Julho                        |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 31);
      break;
      case 7:
      printf("|Agosto                       |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 31);
      break;
      case 8:
      printf("|Setembro                     |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 30);
      break;
      case 9:
      printf("|Outubro                      |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 31);
      break;
      case 10:
      printf("|Novembro                     |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 30);
      break;
      case 11:
      printf("|Dezembro                     |\n");
      primeiroDiaDaSemana = processaMes(primeiroDiaDaSemana, 31);
      break;
    }

   iterator++;
  }



  return 0;
}
// Processo o mes e escrevo ele, e retorno o primeiro da semana do proximo Mês.
int processaMes(int primeiroDiaSemana, int quantidadeDeDias) {
  dashes();
  comecaSemana();
  // Inicio o primeiro dia do mes.
  int diaDoMes = 1;
  // Crio a variavel do primeiro dia do proximo mes.
  int primeiroDiaProximoMes;
  for(int semanaDoMes = 1; semanaDoMes <= 6 ; semanaDoMes++) {
    for(int diaDaSemana = 1; diaDaSemana <= 7; diaDaSemana++) {
      // Se for o primeiro dia da semana, printo a barra
      if(diaDaSemana == 1) {
        printf("| ");
      }
      // Se for a primeira semana e o dia da semana é menor que o primeiro dia da semana no mês
      // ou o mês tiver acabado, eu printo traços, se não printo o dia do mês.
      if ((semanaDoMes == 1 && diaDaSemana < primeiroDiaSemana) || diaDoMes > quantidadeDeDias) {
        printf(" -- ");
      } else {
        // Se o dia for menor que 10, incremento um 0 antes.
        if (diaDoMes < 10) {
          printf(" 0%i ", diaDoMes );
        } else {
          printf(" %i ", diaDoMes );
        }
        // Quando é o ultimo dia do mês, eu pego o dia da semana atual somo um, e obtenho
        // o primeiro dia do proximo mes.
        if (diaDoMes == quantidadeDeDias) {
          primeiroDiaProximoMes = diaDaSemana + 1 > 7 ? 1 : diaDaSemana + 1;
        }
        diaDoMes += 1;
      }
      if(diaDaSemana == 7) {
        printf("|\n" );
      }
    }
  }
  dashes();
  return primeiroDiaProximoMes;
}

int calcSeculo(int ano) {
  return (ano/100) + 1;
}

int getAureo(int ano) {
  return (ano%19) + 1;
}

int getX(int seculo) {
  return ((3*seculo)/4) - 12;
}

int getZ(int seculo) {
  return ((((8*seculo) + 5)/25)-5);
}

int epacta(int g, int x, int z) {
  int e = ((11*g) + 20 + z - x)%30;
  return (e == 25 && g > 11) || e == 24 ? e + 1 : e;
}

int getN(int e){
  int n = 44 - e;
  return n < 21 ? n + 30 : n;
}

int getD(int ano, int x) {
  return ((5*ano)/ 4) - (x +10);
}
// Printa os dias da Semana.
void comecaSemana() {
  printf("| dom seg ter qua qui sex sab |\n");
}

// Printa uma linha
void dashes () {
  printf("|-----------------------------|\n");
}
// Professor, eu tô muito cansado pra fazer a função que converte esses números,
// em dias válidos para semana que eu to usando pra processar o Mes, então eu fiz
// esse switch, me perdoa se vc queria uma função mais matematica. Eu falhei.
int convertePrimeiroDiaDoAno(int dia) {
  switch (dia) {
    case 1:
    return dia;
    break;
    case 2:
    return 7;
    break;
    case 3:
    return 6;
    break;
    case 4:
    return 5;
    break;
    case 5:
    return 4;
    break;
    case 6:
    return 3;
    break;
    case 0:
    return 2;
    break;
  }
}
