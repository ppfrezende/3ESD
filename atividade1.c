#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int faixa;
char *nome;
float tempo;
char *compositor;
}tMusica;

typedef struct{
int numero;
char *nome;
char *banda;
char *gravadora;
int ano_grav;
int num_faixas;
tMusica relacao_music;

}tCd;

void lerCd (tCd *cd, int n){
  printf("Digite o numero do CD: ");
  scanf("%d",&cd[n].numero);
  printf("Digite o nome do CD: ");
  scanf("%s",cd[n].nome);
  printf("Digite a banda do CD: ");
  scanf("%s",cd[n].banda);
  printf("Digite a gravadora do CD: ");
  scanf("%s",cd[n].gravadora);
  printf("Digite o ano de gravacao do CD: ");
  scanf("%d",&cd[n].ano_grav);
  printf("Digite o numero de faixas do CD: ");
  scanf("%d",&cd[n].num_faixas);
  
  printf("\n*** CD registrado ***\n\n");
}

void preencheAcervo (tCd *cd){
	int i, qtd;
	
	printf ("\n Qual a quantidade de CDs?\n");
	scanf("%d", &qtd);
	  
	cd = (tCd*)malloc(qtd*sizeof(tCd));
	
	for (i=0; i < qtd; i++) {
  		lerCd (cd, i);
  	}
  	return;
}

void exibeAcervo (tCd *acervo) {
	int i;
	
	for (i=0; i < sizeof(acervo); i++) {
  		printf("\n Numero do CD: %d", acervo[i].numero);
		printf("\n Nome do CD: %c", acervo[i].nome);
		printf("\n Banda do CD: %c", acervo[i].banda);
		printf("\n Gravadora do CD: %c", acervo[i].gravadora);
		printf("\n Ano de gravacao do CD: %d", acervo[i].ano_grav);
		printf("\n Numero de faixas do CD: %d", acervo[i].num_faixas);
  	}
}

void exibeDecSessenta (tCd *acervo) {
	int i;
	int anoMin = 1960;
	int anoMax = 1969;
	int cont = 0;
	
	for (i=0; i < sizeof(acervo); i++) {
  		if ((acervo->ano_grav >= anoMin) || (acervo->ano_grav <= anoMax)) {
  			cont++;
  			printf("\n CD numero: %d", acervo[i].numero);
		}
  	}
  	if (cont == 0) {
  		printf("\n Nenhum CD anos 60 encontrado!");
	}
}

void maiorNumTrilhas (tCd *acervo) {
	int i;
	int maior = 0;
	
	for (i=0; i < sizeof(acervo); i++) {
  		if (acervo->num_faixas >= maior) {
  			maior = acervo[i].numero;
		}
  	}
  	printf("\n O CD com maior numero de trilhas e': %d", maior);
}

void acervoCompositor (tCd *acervo, tCd *novoAcervoCompositor, char *compositor) {
	int i, j = 0;
	int cont = 0;
	
	for (i=0; i < sizeof(acervo); i++) {
  		if ((strcmp ((acervo->relacao_music.compositor), compositor)) == 0) {
  			novoAcervoCompositor[j] = acervo[i];
  			cont++;
		}
  	}
  	if (cont != 0) {
  		printf("\n\n Compositor não encontrado no acervo!");	
	}
}

int verificaQtdFaixas (tCd *acervo) {
	int i, j;
	int cont = 0;
	
	for (i=0, j=sizeof(acervo); i < j; i++, j--) {
  		if (acervo[i].num_faixas != acervo[j].num_faixas) {
  			return 0;
		}
  	}
  	return 1;
}

void destruirAcervo (tCd *acervo) {
	free(acervo);
}

int main(void) {
	char *nomeCompositor[30];
	tCd *acervo;
	tCd *novoAcervo;
	
	preencheAcervo(acervo);
	exibeAcervo(acervo);
	exibeDecSessenta(acervo);
	maiorNumTrilhas(acervo);
	
	printf("\n Qual nome do compositor?");
	scanf("%s", nomeCompositor);
	acervoCompositor(acervo, novoAcervo, nomeCompositor);
	verificaQtdFaixas(acervo);
	destruirAcervo(acervo);
}

