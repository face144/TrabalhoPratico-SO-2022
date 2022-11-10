#ifndef SOBAY_FRONTEND_INTERFACE_H
#define SOBAY_FRONTEND_INTERFACE_H

/// @brief Interface de comunicação entre o cliente e o servidor.
/// Sentido da comunicação: Cliente -> Servidor.

void Sell(char* NomeItem, char* Categoria, unsigned int PrecoBase, unsigned int PrecoCompreJa, unsigned int Duracao);

typedef struct Item {

    unsigned int Id;
    char* Nome;
    char* Categoria;
    unsigned int PrecoBase;
    unsigned int PrecoCompreJa;
    unsigned int Duracao;

} Item;

/// \brief Receber todos os produtos atualmente à venda.
/// \return Array com os itens desejados.
Item* List();

/// \brief Listar todos os itens de um vendedor.
/// \param Username Nome de utilizador do vendedor.
/// \return Array com os itens desejados.
Item* Lisel(char* Username);

/// \brief Listar todos os itens com preço até um determinado valor.
/// \param PrecoMax Preço máximo.
/// \return Array com os itens desejados.
Item* Lival(unsigned int PrecoMax);

/// \brief Listar todos os itens com prazo até a uma determinada hora.
/// \param Prazo Prazo.
/// \return Array com os itens desejados.
Item* Litime(unsigned int Prazo);


#endif //SOBAY_FRONTEND_INTERFACE_H
