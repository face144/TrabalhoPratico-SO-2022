#include "Itens.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int LerItensDoFicheiro(Item *Buffer) {
    char* ItemsPath = getenv("FITEMS");
    if (ItemsPath == NULL)
        return 0;

    int fd = open(ItemsPath, O_RDONLY);
    if (fd == -1)
        return 0;

    char* Line = calloc(MAXCHAR, sizeof(char));
    Buffer = calloc(0, sizeof(Item));
    int i = 0;
    while (1) {

        ssize_t Code = read(fd, Line, sizeof(Line));
        if (Code <= 0)
            break;

        Buffer = realloc(Buffer, sizeof(Item) * 1 + 1);
        char** LineFormatada = FormatarStringItem(Line);

        Item Temp;
        Temp.Id = atoi(*LineFormatada);
        Temp.Nome = *(LineFormatada + 1);
        Temp.Categoria = *(LineFormatada + 2);
        Temp.PrecoAtual = atoi(*(LineFormatada + 3));
        Temp.PrecoCompeJa = atoi(*(LineFormatada + 4));
        Temp.Duracao = atoi(*(LineFormatada + 5));
        Temp.UserVendedor = *(LineFormatada + 6);
        Temp.UserPrecoAtual = *(LineFormatada + 7);


        Buffer[i] = Temp;

        i++;
    }
}

char** FormatarStringItem(const char *String) {

    if (String == NULL || strlen(String) == 0)
        return NULL;

    char** FormatedString = calloc(1, sizeof(char*) );

    unsigned int CharIndex = 0;
    for (int i = 0; String[i] != '\0'; ++i) {

        if (String[i] == ' ') {
            FormatedString = realloc(FormatedString, sizeof(char*) );
            CharIndex = 0;

        } else {
            if (CharIndex == 0)
                FormatedString[i] = calloc(1, sizeof(char));

            else
                FormatedString[i] = realloc(FormatedString[i], sizeof(char) * CharIndex + 1);

            FormatedString[i][CharIndex] = String[i];
            CharIndex++;
        }
    }

    return FormatedString;
}
