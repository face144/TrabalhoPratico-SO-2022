#ifndef SOBAY_BACKEND_SOBAY_H
#define SOBAY_BACKEND_SOBAY_H


/// \brief Inicializa o sistema SOBay.
/// FUnção de nível mais alto.
_Noreturn void Init();

/// \brief Cria as varaveis de ambiente necessárias.
/// \return Numero de variáveis de ambiente que não conseguiram ser criadas.
int SetEnvVars();

#endif //SOBAY_BACKEND_SOBAY_H
