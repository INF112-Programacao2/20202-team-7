#ifndef PESSOAS_H
#define PESSOAS_H
#define QUANTIDADE_DE_PESSOAS 1000
#include <string>

class Pessoas{
    protected:
        std::string *_nome;
        std::string *_cpf;
        std::string *_telefone;
        char *_genero;

    public:
        Pessoas(std::string *nome, char *genero, std::string *cpf, std::string *telefone);
        void exibirDados() = 0;
        std::string get_nome(int n);
        std::string get_cpf(int n);
        std::string get_telefone(int n);
        char get_genero(int n);
        ~Pessoas();
};

#endif
