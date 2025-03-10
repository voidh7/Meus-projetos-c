#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void br() {
    printf("Baixando recursos do VTERMINAL...\n");
    system("pkg install micro -y");
    system("pkg install wget -y");
}

void Vcmd(char cmd[]) {
    if (strcmp(cmd, "/help") == 0) {
        printf("\t\tHELP V TERMINAL\n");
        printf("Comandos disponíveis:\n");
        printf("/help - Exibe esta mensagem de ajuda\n");
        printf("/clear - Limpa a tela\n");
        printf("/exit - Sai do terminal\n");
        printf("/time - Exibe a hora atual\n");
        printf("/list - Lista arquivos no diretório atual\n");
        printf("/mkdir [nome] - Cria um diretório\n");
        printf("/rmdir [nome] - Remove um diretório\n");
        printf("/touch [arquivo] - Cria um arquivo vazio\n");
        printf("/rm [arquivo] - Remove um arquivo\n");
        printf("/copy [origem] [destino] - Copia um arquivo\n");
        printf("/move [origem] [destino] - Move um arquivo\n");
        printf("/read [arquivo] - Exibe o conteúdo de um arquivo\n");
        printf("/write [arquivo] - Escreve em um arquivo\n");
        printf("/download [url] - Baixa um arquivo da web\n");
        printf("/calc [expressão] - Calcula uma expressão matemática\n");
        printf("/ip - Exibe o endereço IP da máquina\n");
        printf("/ping [host] - Testa a conectividade com um host\n");
        printf("/sysinfo - Exibe informações do sistema\n");
        printf("/shutdown - Desliga a máquina\n");
        printf("/reboot - Reinicia a máquina\n");
    } else if (strcmp(cmd, "/clear") == 0) {
        system("clear");
    } else if (strcmp(cmd, "/exit") == 0) {
        exit(0);
    } else if (strcmp(cmd, "/time") == 0) {
        system("date");
    } else if (strcmp(cmd, "/list") == 0) {
        system("ls");
    } else if (strncmp(cmd, "/mkdir", 6) == 0) {
        char dirname[100];
        sscanf(cmd, "/mkdir %s", dirname);
        char command[150];
        sprintf(command, "mkdir %s", dirname);
        system(command);
    } else if (strncmp(cmd, "/rmdir", 6) == 0) {
        char dirname[100];
        sscanf(cmd, "/rmdir %s", dirname);
        char command[150];
        sprintf(command, "rmdir %s", dirname);
        system(command);
    } else if (strncmp(cmd, "/touch", 6) == 0) {
        char filename[100];
        sscanf(cmd, "/touch %s", filename);
        char command[150];
        sprintf(command, "touch %s", filename);
        system(command);
    } else if (strncmp(cmd, "/rm", 3) == 0) {
        char filename[100];
        sscanf(cmd, "/rm %s", filename);
        char command[150];
        sprintf(command, "rm %s", filename);
        system(command);
    } else if (strncmp(cmd, "/copy", 5) == 0) {
        char source[100], dest[100];
        sscanf(cmd, "/copy %s %s", source, dest);
        char command[150];
        sprintf(command, "cp %s %s", source, dest);
        system(command);
    } else if (strncmp(cmd, "/move", 5) == 0) {
        char source[100], dest[100];
        sscanf(cmd, "/move %s %s", source, dest);
        char command[150];
        sprintf(command, "mv %s %s", source, dest);
        system(command);
    } else if (strncmp(cmd, "/read", 5) == 0) {
        char filename[100];
        sscanf(cmd, "/read %s", filename);
        char command[150];
        sprintf(command, "cat %s", filename);
        system(command);
    } else if (strncmp(cmd, "/write", 6) == 0) {
        char filename[100];
        sscanf(cmd, "/write %s", filename);
        printf("Digite o conteúdo (Ctrl+D para finalizar):\n");
        char command[150];
        sprintf(command, "cat > %s", filename);
        system(command);
    } else if (strncmp(cmd, "/download", 9) == 0) {
        char url[100];
        sscanf(cmd, "/download %s", url);
        char command[150];
        sprintf(command, "wget %s", url);
        system(command);
    } else if (strncmp(cmd, "/calc", 5) == 0) {
        char expression[100];
        sscanf(cmd, "/calc %s", expression);
        char command[150];
        sprintf(command, "echo 'scale=2; %s' | bc", expression);
        system(command);
    } else if (strcmp(cmd, "/ip") == 0) {
        system("ifconfig | grep 'inet '");
    } else if (strncmp(cmd, "/ping", 5) == 0) {
        char host[100];
        sscanf(cmd, "/ping %s", host);
        char command[150];
        sprintf(command, "ping %s", host);
        system(command);
    } else if (strcmp(cmd, "/sysinfo") == 0) {
        system("uname -a");
    } else if (strcmp(cmd, "/shutdown") == 0) {
        system("shutdown now");
    } else if (strcmp(cmd, "/reboot") == 0) {
        system("reboot");
    } else if (strcmp(cmd, "/help -amoracoin") == 0) {
        printf(" \t \t  \n  V TERMINAL AMORACOIN \n");
        printf(" \t \n /infoamoraocoin  \n ");
        printf(" \t \n /login [amoracoin]  ");
    } else {
        printf("Comando não reconhecido. Digite /help para ver a lista de comandos.\n");
    }
}

int main() {
    br();
    printf("V TERMINAL 1.0\n");

    char cmd[100];
    while (1) {
        printf("> ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = 0;
        Vcmd(cmd);
    }

    return 0;
}
