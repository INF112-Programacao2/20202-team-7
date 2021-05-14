#include "Pessoas.h"
#include <string>


Pessoas::Pessoas(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone):
    _genero (genero), _nome(nome), _cpf (cpf), _telefone(telefone) {}


std::string Pessoas::get_nome() const{
    return this->_nome;
}

std::string Pessoas::get_cpf() const{
    return this->_cpf;
}

std::string Pessoas::get_telefone(){
    return this->_telefone;
}

char Pessoas::get_genero() const{
    return this->_genero;
}
