#include "LoginHandler.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int ValidarLogin(const char* Username, const char* Password) {

    char* UsersPath = getenv("FUSERS");
    if (UsersPath == NULL)
        return 1;

    int fd = open(UsersPath, O_RDONLY);
    if (fd == -1)
        return 2;

    char* RequestedLogin = ConverterLogin(Username, Password);

    char StoredLogin[MaxChar];
    while ( read(fd, StoredLogin, sizeof(StoredLogin)) != 0 || // --> Diferente de 0 para EndOfFile
            read(fd, StoredLogin, sizeof(StoredLogin)) != 0 ) { // --> Diferente de -1 para Erros

        if (strcmp(RequestedLogin, StoredLogin) == 0) {
            close(fd);
            return 0;
        }


    }

    close(fd);
    free(RequestedLogin);
    printf("Erro: Não foi possível encontrar o login.");
    return 3;
}

char* ConverterLogin(const char* Username, const char* Password) {

    char* Login = malloc(sizeof(Username) + sizeof(Password) + sizeof(char));
    int index = 0;
    for (int i = 0; Username[i] != '\0'; ++i) {

        Login[index] = Username[i];
        index++;
    }

    Login[index] = LoginDelimiter;
    index++;


    for (int i = 0; Password[i] != '\0'; ++i) {

        Login[index] = Password[i];
        index++;

    }

    return Login;
}
