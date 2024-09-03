#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <json/json.h> // Inclua a biblioteca JSON para C++
#include <fstream>

using namespace std;

void calcularSoma() {
    int INDICE = 13, SOMA = 0, K = 0;
    while (K < INDICE) {
        K++;
        SOMA += K;
    }
    printf("Soma dos n�meros inteiros at� %d �: %d\n", INDICE, SOMA);
}

bool pertenceFibonacci(int num) {
    int a = 0, b = 1;
    if (num == a || num == b) return true;
    while (b < num) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return num == b;
}

void verificarFibonacci() {
    int numero;
    printf("Digite um n�mero para verificar se pertence � sequ�ncia de Fibonacci: ");
    scanf("%d", &numero);
    if (pertenceFibonacci(numero)) {
        printf("O n�mero %d pertence � sequ�ncia de Fibonacci.\n", numero);
    } else {
        printf("O n�mero %d n�o pertence � sequ�ncia de Fibonacci.\n", numero);
    }
}

void analisarFaturamento() {
    const char* jsonData = R"([
        {"dia": 1, "valor": 100.5},
        {"dia": 2, "valor": 200.0},
        {"dia": 3, "valor": 0.0},
        {"dia": 4, "valor": 150.75},
        {"dia": 5, "valor": 0.0},
        {"dia": 6, "valor": 250.0}
    ])";

    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    istringstream s(jsonData);
    string errs;

    if (!Json::parseFromStream(readerBuilder, s, &root, &errs)) {
        cerr << "Erro ao analisar JSON: " << errs << endl;
        return;
    }

    double menorValor = numeric_limits<double>::max();
    double maiorValor = numeric_limits<double>::min();
    double soma = 0.0;
    int diasComFaturamento = 0;

    for (const auto& item : root) {
        double valor = item["valor"].asDouble();
        if (valor > 0) {
            if (valor < menorValor) menorValor = valor;
            if (valor > maiorValor) maiorValor = valor;
            soma += valor;
            diasComFaturamento++;
        }
    }

    double mediaMensal = soma / diasComFaturamento;
    int diasAcimaDaMedia = 0;
    for (const auto& item : root) {
        double valor = item["valor"].asDouble();
        if (valor > mediaMensal) diasAcimaDaMedia++;
    }

    printf("Menor valor de faturamento: R$ %.2f\n", menorValor);
    printf("Maior valor de faturamento: R$ %.2f\n", maiorValor);
    printf("N�mero de dias com faturamento acima da m�dia: %d\n", diasAcimaDaMedia);
}

void calcularPercentual() {
    double sp = 67836.43;
    double rj = 36678.66;
    double mg = 29229.88;
    double es = 27165.48;
    double outros = 19849.53;
    double total = sp + rj + mg + es + outros;

    printf("Faturamento total da distribuidora: R$ %.2f\n", total);
    printf("\nPercentual de representa��o por estado:\n");
    printf("SP: %.2f%%\n", (sp / total) * 100);
    printf("RJ: %.2f%%\n", (rj / total) * 100);
    printf("MG: %.2f%%\n", (mg / total) * 100);
    printf("ES: %.2f%%\n", (es / total) * 100);
    printf("Outros: %.2f%%\n", (outros / total) * 100);
}

void inverterString() {
    char texto[100];
    printf("Digite uma string para inverter: ");
    cin.ignore(); 
    cin.getline(texto, 100);

    int inicio = 0;
    int fim = strlen(texto) - 1;

    while (inicio < fim) {
        swap(texto[inicio], texto[fim]);
        inicio++;
        fim--;
    }

    printf("String invertida: %s\n", texto);
}

int main() {
    int escolha;

    do {
        printf("\nMenu de Op��es:\n");
        printf("1. Calcular a soma dos n�meros inteiros at� um �ndice\n");
        printf("2. Verificar se um n�mero pertence � sequ�ncia de Fibonacci\n");
        printf("3. Analisar faturamento di�rio\n");
        printf("4. Calcular percentual de representa��o por estado\n");
        printf("5. Inverter os caracteres de uma string\n");
        printf("6. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                calcularSoma();
                break;
            case 2:
                verificarFibonacci();
                break;
            case 3:
                analisarFaturamento();
                break;
            case 4:
                calcularPercentual();
                break;
            case 5:
                inverterString();
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}

