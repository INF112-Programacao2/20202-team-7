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
        Pessoas(char genero, std::string nome, std::string cpf, std::string telefone);
        virtual void exibirDados() = 0;
        std::string get_nome();
        std::string get_cpf();
        std::string get_telefone();
        char get_genero();
        
};

#endif
