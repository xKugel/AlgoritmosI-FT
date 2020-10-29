#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ROBSON HENRIQUE FISCHER - 230599 */

int i; //mes
int j; //dia
int k; //diaSemana
int cont = 0; //quebra linha
int contF; //final do mes
int linha = 0; //verifica se precisa de uma linha a mais
int ano, mes, dia, bis;
int g, c, x, z, e, d, n;
int mesDias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char *argv[]) {

	//printf("Digite o ano: ");
	scanf("%d", &ano);


	//P A S C O A

	g = (ano % 19) + 1; //resto inteiro - AUREO
	c = (ano / 100) + 1; //SECULO
	x = ((3 * c) / 4) - 12; //CORRECAO 1
	z = (((8 * c) + 5) / 25) - 5; //CORRECAO 2
	e = ((11 * g) + 20 + z - x) % 30; //resto inteiro

	//EPACTA
	if(e == 25 && g > 11){
		e++;
	}
	else if(e == 24){
		e++;
	}

	//LUA CHEIA
	n = 44 - e;
	if(n < 21){
		n += 30;
	}

	//DOMINGO DE PASCOA
	d = ((5 * ano) / 4) - (x + 10);


	//DIA/MES PASCOA
	n = (n + 7) - ((d + n) % 7);

	if(n > 31){
		n = n - 31;
		//printf("Pascoa: %d de abril", n);
		mes = 4;
	}
	else{
		//printf("Pascoa: %d de marco", n);
		mes = 3;
	}

	// B I S S E X T O

	if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) {
    	//printf("\nAno bissexto.");
		bis = 1;
		mesDias[1] = 29;
    }
  	else {
    	//printf("\nAno nao bissexto.");
		bis = 0;
  	}


	//1   D E    J A N E I R O
	if(mes == 4){
		dia = 8 - ((n + bis + 31 + 28 + 31 ) % 7) ;
	}
	else if(mes == 3){
		dia = 8 - ((n + bis + 31 + 28) % 7) ;
	}
	if(dia > 6) dia -= 7;

	dia++;
	/*
	if(dia == 1){
		printf("\n1 de jan: domingo\n");
	}else if(dia == 2){
		printf("\n1 de jan: segunda\n");
	}else if(dia == 3){
		printf("\n1 de jan: terca\n");
	}else if(dia == 4){
		printf("\n1 de jan: quarta\n");
	}else if(dia == 5){
		printf("\n1 de jan: quinta\n");
	}else if(dia == 6){
		printf("\n1 de jan: sexta\n");
	}else if(dia == 7){
		printf("\n1 de jan: sabado\n");
	}*/




	/*CALEND�RIO*/

	printf("Calendario do ano %d\n", ano);

	printf("|-----------------------------|\n");
	for(i = 0; i < 12; i++){

	switch(i){
			case 0:
			printf("|Janeiro                      |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");
			printf("| ");

			for ( j = 1; j < dia; j++ ){
				printf(" -- ");
				cont++;
			}

			contF = cont;

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}


			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			for(j = (mesDias[i] + contF); j < 43; j++){
					if(cont > 6){
						printf("|\n| ", j);
						cont = 0;
					}else{
						printf(" -- ", j);
						cont++;
					}
			}
			printf("|\n");


			//printf("posicao calendario: %d", totalM);
			//printf("posicao calendario: %d", totalM);

			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;


		case 1:
			printf("|-----------------------------|\n");
			printf("|Fevereiro                    |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}



			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n"); linha = 1; break;
				case 1: printf(" --  --  --  --  --  -- |\n");break;
				case 2: printf(" --  --  --  --  -- |\n");break;
				case 3: printf(" --  --  --  -- |\n");linha = 1; break;
				case 4: printf(" --  --  -- |\n");break;
				case 5: printf(" --  -- |\n"); linha = 1; break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1 && bis == 0){
				printf("|  --  --  --  --  --  --  -- |\n");
			}



			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;



		case 2:
			printf("|-----------------------------|\n");
			printf("|Março                        |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}



			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n");break;
				case 1: printf(" --  --  --  --  --  -- |\n"); linha = 0; break;
				case 2: printf(" --  --  --  --  -- |\n"); linha = 0; break;
				case 3: printf(" --  --  --  -- |\n");break;
				case 4: printf(" --  --  -- |\n");break;
				case 5: printf(" --  -- |\n");break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}


			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;




		case 3:
			printf("|-----------------------------|\n");
			printf("|Abril                        |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n");break;
				case 1: printf(" --  --  --  --  --  -- |\n"); linha = 0; break;
				case 2: printf(" --  --  --  --  -- |\n");break;
				case 3: printf(" --  --  --  -- |\n"); linha = 1; break;
				case 4: printf(" --  --  -- |\n");break;
				case 5: printf(" --  -- |\n"); linha = 1; break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}



			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;


	case 4:
			printf("|-----------------------------|\n");
			printf("|Maio                         |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n");break;
				case 1: printf(" --  --  --  --  --  -- |\n"); linha = 0; break;
				case 2: printf(" --  --  --  --  -- |\n");break;
				case 3: printf(" --  --  --  -- |\n");break;
				case 4: printf(" --  --  -- |\n"); linha = 1; break;
				case 5: printf(" --  -- |\n");break;
				case 6: printf(" -- |\n"); linha = 1; break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}



			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;



		case 5:
			printf("|-----------------------------|\n");
			printf("|Junho                        |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n");break;
				case 1: printf(" --  --  --  --  --  -- |\n"); linha = 0; break;
				case 2: printf(" --  --  --  --  -- |\n");break;
				case 3: printf(" --  --  --  -- |\n"); linha = 1; break;
				case 4: printf(" --  --  -- |\n");break;
				case 5: printf(" --  -- |\n");break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}



			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;




			case 6:
			printf("|-----------------------------|\n");
			printf("|Julho                        |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n");break;
				case 1: printf(" --  --  --  --  --  -- |\n");break;
				case 2: printf(" --  --  --  --  -- |\n"); linha = 0; break;
				case 3: printf(" --  --  --  -- |\n"); break;
				case 4: printf(" --  --  -- |\n"); linha = 1; break;
				case 5: printf(" --  -- |\n");break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}


			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;



			case 7:
			printf("|-----------------------------|\n");
			printf("|Agosto                       |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n"); linha = 0; break;
				case 1: printf(" --  --  --  --  --  -- |\n");break;
				case 2: printf(" --  --  --  --  -- |\n"); linha = 0; break;
				case 3: printf(" --  --  --  -- |\n");break;
				case 4: printf(" --  --  -- |\n");break;
				case 5: printf(" --  -- |\n"); linha = 1; break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}

			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;



			case 8:
			printf("|-----------------------------|\n");
			printf("|Setembro                     |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n"); linha = 0; break;
				case 1: printf(" --  --  --  --  --  -- |\n");break;
				case 2: printf(" --  --  --  --  -- |\n"); linha = 1; break;
				case 3: printf(" --  --  --  -- |\n");break;
				case 4: printf(" --  --  -- |\n"); linha = 1; break;
				case 5: printf(" --  -- |\n");break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}


			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;



			case 9:
			printf("|-----------------------------|\n");
			printf("|Outubro                      |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n"); linha = 0; break;
				case 1: printf(" --  --  --  --  --  -- |\n");break;
				case 2: printf(" --  --  --  --  -- |\n");break;
				case 3: printf(" --  --  --  -- |\n"); linha = 1; break;
				case 4: printf(" --  --  -- |\n");break;
				case 5: printf(" --  -- |\n");break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}



			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;



			case 10:
			printf("|-----------------------------|\n");
			printf("|Novembro                     |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n"); linha = 0; break;
				case 1: printf(" --  --  --  --  --  -- |\n");break;
				case 2: printf(" --  --  --  --  -- |\n"); linha = 1; break;
				case 3: printf(" --  --  --  -- |\n");break;
				case 4: printf(" --  --  -- |\n");break;
				case 5: printf(" --  -- |\n"); linha = 1; break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}


			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;



			case 11:
			printf("|-----------------------------|\n");
			printf("|Dezembro                     |\n");
			printf("|-----------------------------|\n");
			printf("| dom seg ter qua qui sex sab |\n");

			//printf("dia: %d cont: %d", dia, cont);
			switch(dia){
				case 0: printf("| "); cont = 0; contF = 0; break;
				case 1: printf("|  -- "); cont = 1; contF = 1; break;
				case 2: printf("|  --  -- "); cont = 2; contF = 2; break;
				case 3: printf("|  --  --  -- "); cont = 3; contF = 3; break;
				case 4: printf("|  --  --  --  -- "); cont = 4; contF = 4; break;
				case 5: printf("|  --  --  --  --  -- "); cont = 5; contF = 5; break;
				case 6:	printf("|  --  --  --  --  --  -- "); cont = 6; contF = 6; break;
			}

			for(j = 1; j < mesDias[i] + 1; j++){
				if(cont > 6){
					printf("|\n|  %02d ", j);
					cont = 1;
				}else{
					printf(" %02d ", j);
					cont++;
				}
			}

			dia = cont;
			if(dia > 6){
				dia = 0;
			}

			switch(dia){
				case 0: printf("|\n|  --  --  --  --  --  --  -- |\n");break;
				case 1: printf(" --  --  --  --  --  -- |\n");  linha = 0; break;
				case 2: printf(" --  --  --  --  -- |\n");break;
				case 3: printf(" --  --  --  -- |\n"); linha = 1; break;
				case 4: printf(" --  --  -- |\n");break;
				case 5: printf(" --  -- |\n"); linha = 1; break;
				case 6: printf(" -- |\n");break;
			}

			if(linha == 1){
				printf("|  --  --  --  --  --  --  -- |\n");
			}

			/*printf("\n|-----------------------------|\n");
			printf("dia: %d\n", dia);*/
			break;







	}//fim switch




}//fim for 12
	printf("|-----------------------------|\n");
return 0;
}
