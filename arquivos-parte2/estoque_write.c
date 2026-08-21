#include <stdio.h>
#include "produto.h"

// Função utilitária para gerar ID automático
int gerar_id() {
    // time(NULL) retorna os segundos desde 1970 (timestamp).
    // cast para converter o formato time_t par int.
    //return (int) time(NULL);
}

int salvar_produto(const Produto *produto, const char *filename) {
    FILE *arquivo = fopen(filename, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }
    fwrite(produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
    return 0;
}

