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
        Pessoas(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone);
        virtual void exibirDados() = 0;
        std::string get_nome() const;
        std::string get_cpf() const;
        std::string get_telefone();
        char get_genero() const;
        
};

#endif
