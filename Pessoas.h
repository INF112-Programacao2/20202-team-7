#ifndef PESSOAS_H
#define PESSOAS_H
#include <string>

class Pessoas{
    protected:
        std::string _nome;
        std::string _cpf;
        std::string _telefone;
        char _genero;

    public:
        Pessoas(std::string nome, char genero, std::string cpf, std::string telefone);
        virtual void exibirDados() = 0;
        virtual std::string get_nome() = 0;
        virtual std::string get_cpf() = 0;
        virtual std::string get_telefone() = 0;
        virtual char get_genero() = 0;
        ~Pessoas();
};

#endif
