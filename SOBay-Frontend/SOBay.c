#include <unistd.h>
#include "SOBay.h"

#include "Comandos.h"
#include "stdio.h"

int Login(const char *Username, const char *Password) {
    // Todo: Ligar o pipe ao backend para validar informação de login

    if (Username == NULL || Password == NULL) {
        printf("Aviso: Utilizador ou palavra passe inválidos. A assumir login de debug.\n");
        Username = "user";
        Password = "passwd";
        // sleep(1);
    }


    printf("Nome de utilizador: %s\n", Username);
    printf("Palavra passe: %s\n", Password);
    printf("Meta 1 -> A ignorar validação das credenciais.\n");
    return 0;
}

void Init() {

    while (1)
        CommandHandler();

}
