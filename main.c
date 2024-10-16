#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para inverter uma string
void inverterString(char *str, char *strInvertida) {
    int tamanho = strlen(str);
    for (int i = 0, j = tamanho - 1; i <= j; i++, j--) {
        strInvertida[i] = str[j];
        strInvertida[j] = str[i];
    }
    strInvertida[tamanho] = '\0';
}

int main() {
    // Alocação de memória para as strings
    char **strs = (char **) malloc(3 * sizeof(char *));
    char **strsInvertidas = (char **) malloc(3 * sizeof(char *));
    if (strs == NULL || strsInvertidas == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    for (int k = 0; k < 3; k++) {
        // Alocação de memória para cada string
        strs[k] = (char *) malloc(100 * sizeof(char));
        if (strs[k] == NULL) {
            printf("Erro ao alocar memória\n");
            return 1;
        }

        // Leitura da string do usuário
        printf("Digite a string %d: ", k + 1);
        scanf("%s", strs[k]);

        // Alocação de memória para a string invertida
        int tamanho = strlen(strs[k]);
        strsInvertidas[k] = (char *) malloc((tamanho + 1) * sizeof(char));
        if (strsInvertidas[k] == NULL) {
            printf("Erro ao alocar memória\n");
            return 1;
        }

        // Inversão da string
        inverterString(strs[k], strsInvertidas[k]);
    }

    // Abertura do arquivo para escrita
    FILE *arquivo = fopen("output.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    // Escrita das strings no arquivo
    for (int k = 0; k < 3; k++) {
        fprintf(arquivo, "%s %s\n", strs[k], strsInvertidas[k]);
    }
    fclose(arquivo);

    for (int k = 0; k < 3; k++) {
        free(strs[k]);
        free(strsInvertidas[k]);
    }
    free(strs);
    free(strsInvertidas);

    printf("Strings gravadas no arquivo output.txt\n");

    return 0;
}