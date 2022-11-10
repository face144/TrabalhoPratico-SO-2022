#ifndef SOBAY_BACKEND_ITENS_H
#define SOBAY_BACKEND_ITENS_H

#define MAXCHAR 50

struct Item {

    unsigned int Id;
    char* Nome;
    char* Categoria;
    unsigned int PrecoAtual;
    unsigned int PrecoCompeJa;
    unsigned Duracao;
    char* UserVendedor;
    char* UserPrecoAtual;

};
typedef struct Item Item;

int LerItensDoFicheiro(Item* Buffer); // Todo: Testar

char** FormatarStringItem(const char* String); // Todo: Testar

void AdicionarNovoItem();

#endif //SOBAY_BACKEND_ITENS_H
