#ifndef SOBAY_BACKEND_PROMOTOR_H
#define SOBAY_BACKEND_PROMOTOR_H

#define MAX_CHAR 50

struct Promotor {

    char* FilePath;
    int PID;
};
typedef struct Promotor Prom;

/// \brief Executa todos os promotores
/// \return Número de promotores inválidos (falharam execução)
int ExecutarPromotores(Prom* ArrayRef);

#endif //SOBAY_BACKEND_PROMOTOR_H
