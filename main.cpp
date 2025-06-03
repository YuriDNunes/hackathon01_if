#include <iostream>
#include <cstdlib>
#include <ctime>
// Yuri Nunes, Pedro Victor, Flávio Lima, Davison, Victor Emanuel

using namespace std;

void imprimirCabecalho(string cabecalho[]) {
    for (int k = 0; k < 8; k++) {
        printf("%10s", cabecalho[k].c_str());
    }
    printf("\n");
}


int main() {
    const int numBairros = 5;
    const int numDias = 7;

    int temperatura [numBairros][numDias];
    int poluicao [numBairros][numDias];
    int trafego [numBairros][numDias];

    srand(time(0));

    //Preencher matriz temperatura
    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            temperatura[i][j] = rand() % 36 + 5;
        }
    }

    //Preencher matriz poluicao
    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            poluicao[i][j] = rand() % 401 + 200;
        }
    }

    //Preencher matriz trafego
    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            trafego[i][j] = rand() % 101;
        }
    }

    string cabecalho[8] = {"Bairro", "Dia 1", "Dia 2", "Dia 3", "Dia 4", "Dia 5", "Dia 6", "Dia 7"};

    //Imprimindo matriz Temperatura
    printf("Temperatura (ºC):\n");
    imprimirCabecalho(cabecalho);
    for (int i = 0; i < numBairros; i++) {
        printf("%7d", i + 1);
        for (int j = 0; j < numDias; j++) {
            printf("%10d", temperatura[i][j]);
        }
        printf("\n");
    }

    //Imprimindo matriz poluicao
    printf("Nível de poluição (ppm de CO₂):\n");
    imprimirCabecalho(cabecalho);
    for (int i = 0; i < numBairros; i++) {
        printf("%8d", i + 1);
        for (int j = 0; j < numDias; j++) {
            printf("%10d", poluicao[i][j]);
        }
        printf("\n");
    }

    //Imprimindo matriz trafego
    printf("Tráfego (em %%):\n");
    imprimirCabecalho(cabecalho);
    for (int i = 0; i < numBairros; i++) {
        printf("%7d", i + 1);
        for (int j = 0; j < numDias; j++) {
            printf("%10d", trafego[i][j]);
        }
        printf("\n");
    }

    //Armazenar e somar temperaturas em 1 vetor
    double mediaTemperatura [5] = {0};
    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            mediaTemperatura[i] += temperatura[i][j];
        }
    }

    //Calcular media das temperturas somadas
    for (int i = 0; i < numBairros; i++) {
        mediaTemperatura[i] = mediaTemperatura[i] / numDias;
    }

    //Verificar qual o bairro mais quente
    int indiceMaisQuente = 0;
    for (int i = 0; i < numBairros; i++) {
        if (mediaTemperatura[i] > mediaTemperatura[indiceMaisQuente]) {
            indiceMaisQuente = i;
        }
    }
    /*
    printf("Bairro mais quente foi o: %d\n",indiceMaisQuente + 1);
    */

    //Verificar o dia com mais poluiçao
    int indiceBairroMaiorPoluicao = 0;
    int  indiceDiaMaiorPoluicao = 0;
    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            if (poluicao[i][j] > poluicao[indiceBairroMaiorPoluicao][indiceDiaMaiorPoluicao]) {
                indiceBairroMaiorPoluicao = i;
                indiceDiaMaiorPoluicao = j;
            }
        }
    }

    /*
    printf("O bairro: %d com maior poluição foi no dia: %d",indiceBairroMaiorPoluicao + 1,indiceDiaMaiorPoluicao + 1);
    */

    //Armazenar e somar o trafego em 1 vetor
    double mediaTrafego[5] = {0};
    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            mediaTrafego[i] += trafego[i][j];
        }
    }

    //Calcular media dao trafego somado
    for (int i = 0; i < numBairros; i++) {
        mediaTrafego[i] = mediaTrafego[i] / numDias;
    }
/*
    //imprimir a media
    printf("Bairros: Medias do trafego:\n");
    for (int i = 0; i < numBairros; i++) {
        printf("%4d ",i + 1);
        printf("   %.1f\n", mediaTrafego[i]);
    }
*/

    //Somar os valores da matriz trafego
    int somaTrafego[5] = {0};
    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            somaTrafego[i] += trafego[i][j];
        }
    }

    int indiceMaiorTrafego = 0;
    for (int i = 0; i < numBairros; i++) {
        if (somaTrafego[i] > somaTrafego[indiceMaiorTrafego]) {
            indiceMaiorTrafego = i;
        }
    }

    string diaDaSemana[numDias] = {"Domingo","Segunda-Feira","Terça-Feira","Quarta-Feira","Quinta-Feira","Sexta-Feira","Sabado"};

    /*
    printf("Bairro com maior trafego: %d total de trafego: %d%%\n",indiceMaiorTrafego + 1,somaTrafego[indiceMaiorTrafego]);
    */
    printf("\n========== Relatório de Análise da Semana ==========\n\n");
    printf("1. Média semanal de temperatura:\n");
        for (int i = 0; i < numBairros; i++) {
            printf("- Bairro %d:  %.1f graus\n",i+1,mediaTemperatura[i]);
        }
    printf("\n2. Bairro mais quente da semana: Bairro %d, com %.1f graus\n",indiceMaisQuente + 1, mediaTemperatura[indiceMaisQuente]);

    printf("\n3.Dia com maior nivel de poluição: %s no bairro %d com %d ppm CO2\n",diaDaSemana[indiceDiaMaiorPoluicao].c_str(), indiceBairroMaiorPoluicao + 1,poluicao[indiceBairroMaiorPoluicao][indiceDiaMaiorPoluicao]);

    printf("\n4. Média semanal de temperatura:\n");
    for (int i = 0; i < numBairros; i++) {
        printf("- Bairro %d:  %.1f%%\n",i+1,mediaTrafego[i]);
    }

    printf("\n5. Bairro com maior trafego registrado: Bairro %d, com %d%% de tráfego acumulado.",indiceMaiorTrafego + 1, somaTrafego[indiceMaiorTrafego]);
}