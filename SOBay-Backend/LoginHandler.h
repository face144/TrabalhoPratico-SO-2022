#ifndef SOBAY_BACKEND_LOGINHANDLER_H
#define SOBAY_BACKEND_LOGINHANDLER_H

#define LoginDelimiter ' '
#define MaxChar 50

/// \brief Verifica se o login existe / está correto.
/// \param Username Nome de utilizador.
/// \param Password Palavra passe.
/// \return 0 se o login for válido.
int ValidarLogin(const char* Username, const char* Password); // Funciona bem

/// \brief Converto o login para o formato do ficheiro de texto.
/// \param Nome de utilizador.
/// \param Password Palavra passe.
/// \return String do login convertida.
char* ConverterLogin(const char* Username, const char* Password); // Funciona bem

#endif //SOBAY_BACKEND_LOGINHANDLER_H
