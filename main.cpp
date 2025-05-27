#include <iostream>
#include <cstdlib>
#include <ctime>

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

    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            temperatura[i][j] = rand() % 36 + 5;
        }
    }

    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            poluicao[i][j] = rand() % 401 + 200;
        }
    }

    for (int i = 0; i < numBairros; i++) {
        for (int j = 0; j < numDias; j++) {
            trafego[i][j] = rand() % 101;
        }
    }

    string cabecalho[8] = {"Bairro", "Dia 1", "Dia 2", "Dia 3", "Dia 4", "Dia 5", "Dia 6", "Dia 7"};

    printf("Temperatura (ºC):\n");

    imprimirCabecalho(cabecalho);

    for (int i = 0; i < numBairros; i++) {
        printf("%7d", i + 1);
        for (int j = 0; j < numDias; j++) {
            printf("%10d", temperatura[i][j]);
        }
        printf("\n");
    }

    printf("Nível de poluição (ppm de CO₂):\n");

    imprimirCabecalho(cabecalho);

    for (int i = 0; i < numBairros; i++) {
        printf("%8d", i + 1);
        for (int j = 0; j < numDias; j++) {
            printf("%10d", poluicao[i][j]);
        }
        printf("\n");
    }

    printf("Tráfego (em %%):\n");

    imprimirCabecalho(cabecalho);

    for (int i = 0; i < numBairros; i++) {
        printf("%7d", i + 1);
        for (int j = 0; j < numDias; j++) {
            printf("%10d%%", trafego[i][j]);
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

    //imprimir a media
    printf("Bairros: Medias de temperaturas:\n");
    for (int i = 0; i < numBairros; i++) {
        printf("%4d ",i + 1);
        printf("   %.1f\n", mediaTemperatura[i]);
    }

}
