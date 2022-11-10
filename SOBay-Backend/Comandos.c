#include "Comandos.h"

#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include "malloc.h"

char** ReadCommand() {
    printf("->");
    fflush(stdout);
    fflush(stdin);
    char Input[100];
    fgets(Input, 100, stdin);
    Input[strlen(Input) - 1] = '\0';

    if (*Input == '\0') {
        return NULL;
    }

    char** Cmd;
    Cmd = malloc(sizeof(char*) * 5);
    int j = 0;
    int k = 1;
    for (int i = 0; i < Input[i] != '\0'; ++i) { // Todo: Fix condição

        if (Input[i] == ' ') {
            Cmd = realloc(Cmd, sizeof(char *) * (j + 2));
            k = 1;
            j++;

        } else if (Input[i] != '\n') {
            if (k == 1)
                Cmd[j] = calloc(1, sizeof(char));
            else
                Cmd[j] = realloc(Cmd[j], sizeof(char) * k);

            Cmd[j][k - 1] = Input[i];

            k++;

        } else {
            j++;
            (Cmd + j)[k - 1] = NULL;
        }

    }

    for (int i = 0; Cmd[i] != NULL; ++i) {
        // printf("%s\n", Cmd[i]);
    }

    return Cmd;
}

void CommandHandler() {

    char** Comando = NULL;
    Comando = ReadCommand();
    if (Comando == NULL || *Comando == NULL) {
        fflush(stdin);
        return;
    }

    Argc Argc = None;


    if (strcmp(*Comando, "users") == 0) {
        Argc = Users;

        if (ValidarComando(Comando, Argc) != 0)
            PrintArgcError(Argc);

    } else if (strcmp(*Comando, "list") == 0) {
        Argc = List;

        if (ValidarComando(Comando, Argc) != 0)
            PrintArgcError(Argc);

    } else if (strcmp(*Comando, "kick") == 0) {
        Argc = Kick;

        if (ValidarComando(Comando, Argc) != 0)
            PrintArgcError(Argc);

    } else if (strcmp(*Comando, "prom") == 0) {
        Argc = Prom;

        if (ValidarComando(Comando, Argc) != 0)
            PrintArgcError(Argc);

    } else if (strcmp(*Comando, "reprom") == 0) {
        Argc = Reprom;

        if (ValidarComando(Comando, Argc) != 0)
            PrintArgcError(Argc);

    } else if (strcmp(*Comando, "cancel") == 0) {
        Argc = Cancel;

        if (ValidarComando(Comando, Argc) != 0)
            PrintArgcError(Argc);

    }  else if (strcmp(*Comando, "close") == 0) {
        Argc = Close;

        if (ValidarComando(Comando, Argc) != 0)
            PrintArgcError(Argc);

        FreeCmdMemory(Comando);
        exit(0);
    } else {

        printf("Erro: Comando não reconhecido.\n");
    }

    FreeCmdMemory(Comando);
}

void FreeCmdMemory(char** Comando) {

    for (int i = 0; Comando[i] != NULL; ++i) {
        free(*(Comando + i));
        Comando[i] = NULL;
    }

    free(Comando);
    Comando = NULL;
}

int ValidarComando(char **Comando, const unsigned int Argc) {

    int i = 0;
    while (*(Comando + i) != NULL)
        i++;


    if (i != Argc)
        return -1;

    return 0;
}

void PrintArgcError(unsigned int Argc) {
    if (Argc != 1) {
        Argc--;
        printf("Erro: Esse comando deve ter %d argumentos.\n", Argc);

    } else
        printf("Erro: Esse comando deve ser usado sem argumentos.\n");
}

