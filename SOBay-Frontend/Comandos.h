#ifndef SOBAY_FRONTEND_COMANDOS_H
#define SOBAY_FRONTEND_COMANDOS_H

/// Número de argumentos para cada comando
typedef enum Argc {
    None = 0,
    Sell = 6,
    List = 1,
    Licat = 2,
    Lisel = 2,
    Lival = 2,
    Litime = 2,
    Time = 1,
    Buy = 3,
    Cash = 1,
    Add = 2,
    Exit = 1,
} Argc;

/// @brief Transforma comandos de uma string unidimensional para um
/// array bi-dimensional em que cada indice é um parametro do comando.
/// @warning Usa memória dinâmica. Deve ser usada a função
/// "FreeCmdMemory()" para libertar a memória.
/// @return Array de strings para cada argumento do comando.
char** ReadCommand();

/// @brief Liberta a memória de um array de ponteiros para strings.
/// @param Comando O array de strings onde são armazenados os comandos.
/// Deve ser recebido pela funçã́o "ReadCommand()".
void FreeCmdMemory(char** Comando);

/// @brief Verifica se um comando tem o número correto de argumentos
/// @param Comando O comando a validar
/// @param Argc Número correto de argumentos
/// @return Retorna -1 se for inválido, 0 caso contrário.
int ValidarComando(char **Comando, unsigned int Argc);

/// @brief Apresenta no ecra uma mensagem de erro.
/// Deve ser usada apenas quando o comando introduzido
/// pelo utilizador tem um número incorreto de argumentos.
/// @param Argc Número de argumentos que deviam ter sido introduzidos.
void PrintArgcError(unsigned int Argc);

/// @brief Gestor dos Comandos. Função de alto nível.
void CommandHandler(); // Functiona

#endif //SOBAY_FRONTEND_COMANDOS_H
