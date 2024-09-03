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
    printf("Soma dos números inteiros até %d é: %d\n", INDICE, SOMA);
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
    printf("Digite um número para verificar se pertence à sequência de Fibonacci: ");
    scanf("%d", &numero);
    if (pertenceFibonacci(numero)) {
        printf("O número %d pertence à sequência de Fibonacci.\n", numero);
    } else {
        printf("O número %d não pertence à sequência de Fibonacci.\n", numero);
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
    printf("Número de dias com faturamento acima da média: %d\n", diasAcimaDaMedia);
}

void calcularPercentual() {
    double sp = 67836.43;
    double rj = 36678.66;
    double mg = 29229.88;
    double es = 27165.48;
    double outros = 19849.53;
    double total = sp + rj + mg + es + outros;

    printf("Faturamento total da distribuidora: R$ %.2f\n", total);
    printf("\nPercentual de representação por estado:\n");
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
        printf("\nMenu de Opções:\n");
        printf("1. Calcular a soma dos números inteiros até um índice\n");
        printf("2. Verificar se um número pertence à sequência de Fibonacci\n");
        printf("3. Analisar faturamento diário\n");
        printf("4. Calcular percentual de representação por estado\n");
        printf("5. Inverter os caracteres de uma string\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
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
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}

