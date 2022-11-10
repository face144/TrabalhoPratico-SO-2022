#include "Promotor.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int ExecutarPromotores(Prom* ArrayRef) {
    char* PromotersPath = getenv("FPROMOTERS");

    // Failsafe
    if (PromotersPath == NULL) {
        ArrayRef = NULL;
        return 1;
    }

    // Failsafe
    int fd = open(PromotersPath, O_RDONLY);
    if (fd == -1) {
        ArrayRef = NULL;
        return 2;
    }

    char LineBuffer[MAX_CHAR];
    ssize_t RdCode;
    int i = 0;
    ArrayRef = calloc(0, sizeof(Prom)); // Allocar memoria
    do {

        RdCode = read(fd, LineBuffer, MAX_CHAR);
        if (RdCode == -1)
            break;

        int PID = fork();

        // Todo: Testar isto
        if (PID > 0) { // Filho

            // Todo: Mudar o stdout

            char* Args[] = {LineBuffer, NULL};
            execvp(Args[0], Args);

        } else if (PID == 0) { // Pai

            ArrayRef = realloc(ArrayRef, sizeof(Prom));
            Prom Temp;
            Temp.PID = PID;
            Temp.FilePath = LineBuffer;
            ArrayRef[i] = Temp;
            i++;
        }

    } while (RdCode > 0);

    close(fd);

    return 0;
}
