#include <stdio.h>
#include <stdlib.h>

void cts(char *codigo, char nomearv[50]) {
    FILE *arv;
    arv = fopen(nomearv, "w");

    if (arv == NULL) {
        printf("\033[1;31mErro 001:");
        return;
    }

    printf("\033[1;32mEditor de Texto CTS\033[0m\n");
    printf("\033[1;34mDigite o texto abaixo. Pressione CTRL+D para salvar e sair.\033[0m\n\n");

    while (fgets(codigo, 999, stdin) != NULL) {
        fprintf(arv, "%s", codigo);
    }



    fclose(arv);
    printf("\n\033[1;32mArquivo  salvo com sucesso  \n");
}

void clear() {
            printf("\033[H\033[J");
}


int main() {
clear();


    char codigo[999];
    char nomearv[50];


    printf("\033[1;38;5;196mDigite o nome do arquivo:");
    scanf("%s", nomearv);

    cts(codigo, nomearv);



    return 0;
}
