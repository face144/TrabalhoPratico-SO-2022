#include "SOBay.h"

int main(int argc, char* argv[], char* envp[]) {

    if (Login(argv[UsernameArg], argv[PasswordArg]) == 0) {
        Init();
    }

    return 0;
}
