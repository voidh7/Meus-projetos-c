#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char username[20] ="user2025";



int clear(){
        system("clear");
        return 0;
}

int ajuda(){

printf(" CUKI TERMINAL \n \n ");

printf("CMDS \n \n ");


printf(" myusername \n");
 printf("  mostra o seu username atual \n \n");

printf(" clear \n");
printf("   limpa o teminal \n \n");

return 0;

}


int cmdcuki(char cmd[50]) {
    if (strcmp(cmd, "myusername") == 0) {
        printf("%s\n", username);
    }

    else if (strcmp(cmd, "clear") == 0) {
       clear();
    }
    else if(strcmp(cmd,"/ajuda") ==0){
 ajuda();
    }
else if(strcmp(cmd,"ls")== 0){
        system("ls");
}
    else {
        printf("Comando desconhecido: %s\n", cmd);
    }

    return 0;
}

int main() {
clear();


    printf("    ================== \n");
    printf("     cuki terminal \n");
    printf("    ================== \n");
for(int i=0; i<90; i++){
    char cmd[50];
    printf("> ");

    scanf("%s", cmd);
    cmdcuki(cmd);
    }

    return 0;
}
