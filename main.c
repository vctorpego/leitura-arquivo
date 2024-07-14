#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 50

typedef struct Heroi {
	char nome[MAX_TAM];
	char individualidade[MAX_TAM];
	float peso;
	float altura;
	int rank;	
} Heroi;

typedef struct Vilao {
	char nome[MAX_TAM];
	char individualidade[MAX_TAM];
	float peso;
	float altura;
	int nivel;
} Vilao;

typedef struct Pais {
    char nome[MAX_TAM];
    char arquivo_herois[MAX_TAM];
    char arquivo_viloes[MAX_TAM];
    int num_herois;
    Heroi herois[MAX_TAM];
    int num_viloes;
    Vilao viloes[MAX_TAM];
} Pais;

void printarPaises(Pais *pais) {
    printf("%s\t\t", pais->nome);
    printf("%s\t\t", pais->arquivo_herois);
    printf("%s\n", pais->arquivo_viloes);
}

void printarHerois(Heroi *heroi) {
	printf("%s\t\t", heroi->nome);
	printf("%s\t\t", heroi->individualidade);
	printf("%.2f\t\t", heroi->peso);
	printf("%.2f\t\t", heroi->altura);
	printf("%d\n", heroi->rank);
}

void printarViloes(Vilao *vilao) {
	printf("%s\t\t", vilao->nome);
	printf("%s\t\t", vilao->individualidade);
	printf("%.2f\t\t", vilao->peso);
	printf("%.2f\t\t", vilao->altura);
	printf("%d\n", vilao->nivel);
}

int lerPaises(Pais *pais) {
	char str[50];
	int i = 0;
	FILE *arquivo = fopen("paises.txt", "r");
	if (!arquivo) {
		printf("\nErro ao abrir o arquivo!\n");
	} else {
		while (!feof(arquivo)) {
			fscanf(arquivo, "%s", str);
			strcpy(pais[i].nome, str);
			fscanf(arquivo, "%s", str);
			strcpy(pais[i].arquivo_herois, str);
			fscanf(arquivo, "%s", str);
			strcpy(pais[i].arquivo_viloes, str);
			i++;
		}
		fclose(arquivo);
	}
	return i;
}

int lerHeroisDeCadaPais(Pais *pais) {
	int i = 0;
	FILE *arquivo = fopen(pais->arquivo_herois, "r");
	if (!arquivo) {
		printf("\nErro ao abrir o arquivo!\n");
	} else {
		while (!feof(arquivo) && i < MAX_TAM) {
			fscanf(arquivo, "%s", pais->herois[i].nome);
			fscanf(arquivo, "%s", pais->herois[i].individualidade);
			fscanf(arquivo, "%f", &pais->herois[i].peso);
			fscanf(arquivo, "%f", &pais->herois[i].altura);
			fscanf(arquivo, "%d", &pais->herois[i].rank);
			i++;
		}
		fclose(arquivo);
	}
	return i;	
}

int lerViloesDeCadaPais(Pais *pais) {
    int i = 0;
    FILE *arquivo = fopen(pais->arquivo_viloes, "r");
    if (!arquivo) {
        printf("\nErro ao abrir o arquivo!\n");
    } else {
        while (!feof(arquivo) && i < MAX_TAM) {
            fscanf(arquivo, "%s", pais->viloes[i].nome);
            fscanf(arquivo, "%s", pais->viloes[i].individualidade);
            fscanf(arquivo, "%f", &pais->viloes[i].peso);
            fscanf(arquivo, "%f", &pais->viloes[i].altura);
            fscanf(arquivo, "%d", &pais->viloes[i].nivel);
            i++;
        }
        fclose(arquivo);
    }
    return i;
}

void paisesComMaisHeroisQueViloes(Pais *pais, int qtd_paises) {
    int i;
    
    // Verifica se o país tem mais heróis do que vilões
    for (i = 0; i < qtd_paises; i++) {	
        if (pais[i].num_herois > pais[i].num_viloes) {
            printarPaises(&pais[i]);
    	}
    }
}

void heroisDeMaiorRankPorPais(Pais *pais, int qtd_paises) {
    int i, j, max_rank;
    Heroi *heroi;
    
    for (i = 0; i < qtd_paises; i++) {
        heroi = &pais[i].herois[0];
        max_rank = heroi->rank;
        
        for (j = 0; j < pais[i].num_herois; j++) {
            heroi = &pais[i].herois[j];
            // Encontra o maior valor de rank entre os heróis de cada país
            if (heroi->rank > max_rank) {
                max_rank = heroi->rank;
            }
        }
        
        for (j = 0; j < pais[i].num_herois; j++) {
            heroi = &pais[i].herois[j];
            // Imprime o herói com o maior rank de cada país
            if (heroi->rank == max_rank) {
                printarHerois(heroi);
            }
        }
    }
}

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

void viloesComMenorIMC(Pais *pais, int qtd_paises) {
    int i, j;
    float imc, menor_imc;
    Vilao *vilao;
	
    menor_imc = calcularIMC(pais[0].viloes[0].peso, pais[0].viloes[0].altura);
    
    for (i = 0; i < qtd_paises; i++) {
        for (j = 0; j < pais[i].num_viloes; j++) {
            vilao = &pais[i].viloes[j];
            imc = calcularIMC(vilao->peso, vilao->altura);

            // Atualiza o menor IMC
                menor_imc = imc;
        }
    }

    printf("O menor IMC encontrado foi: %.2f\n", menor_imc);

    for (i = 0; i < qtd_paises; i++) {
        for (j = 0; j < pais[i].num_viloes; j++) {
            vilao = &pais[i].viloes[j];
            imc = calcularIMC(vilao->peso, vilao->altura);
			
			// Imprime o vilão com o menor IMC
            if (imc == menor_imc) {
                printarViloes(vilao);
            }
        }
    }
}

void heroisComIndividualidadeLetraM(Pais *pais, int qtd_paises) {
    int i, j;
    Heroi *heroi;
    
    for (i = 0; i < qtd_paises; i++) {
        for (j = 0; j < pais[i].num_herois; j++) {
            heroi = &pais[i].herois[j];
            
            // Verifica se a individualidade contém a letra 'm' ou 'M'
            if (strstr(heroi->individualidade, "m") != NULL || strstr(heroi->individualidade, "M") != NULL) {
				printarHerois(heroi); 
            }
        }
    }
}

int main(int argc, char *argv[]) {
	Pais paises[MAX_TAM];
    int i, qtd_paises;
    
    qtd_paises = lerPaises(paises);
    
    for (i = 0; i < qtd_paises; i++) {
        paises[i].num_herois = lerHeroisDeCadaPais(&paises[i]);
        paises[i].num_viloes = lerViloesDeCadaPais(&paises[i]);
    }
	
	printf("\n--- Os paises com mais herois que viloes --- \n");
    paisesComMaisHeroisQueViloes(paises, qtd_paises);
    
    printf("\n--- Herois com maior rank por pais ---\n");
    heroisDeMaiorRankPorPais(paises, qtd_paises);
    
    printf("\n--- Viloes com o menor IMC ---\n");
    viloesComMenorIMC(paises, qtd_paises);
    
    printf("\n--- Herois com individualidades que tem a letra M ---\n");
	heroisComIndividualidadeLetraM(paises, qtd_paises);
	
	return 0;
}