#include "SOBay.h"

#include "Comandos.h"
#include <stdio.h>
#include <stdlib.h>

_Noreturn void Init() {

    if (SetEnvVars() != 0) {
        printf("SISTEMA: Erro a criar variàveis de ambiente. A abortar execução.");
        exit(1);
    }



    while (1)
        CommandHandler();

}

int SetEnvVars() {
    int cnt = 0;

    putenv("HEARTBEAT");
    cnt += setenv("HEARTBEAT", "1", 0);

    putenv("FPROMOTERS");
    cnt += setenv("FPROMOTERS", "../BaseDeDados-Teste/Promotores.txt", 1);

    putenv("FUSERS");
    cnt += setenv("FUSERS", "../BaseDeDados-Teste/Users.txt", 1);

    putenv("FITEMS");
    cnt += setenv("FITEMS", "../BaseDeDados-Teste/Items.txt", 1);


    return abs(cnt);
}
