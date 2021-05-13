#include "Pessoas.h"
#include <string>


Pessoas::Pessoas(std::string nome, char genero, std::string cpf, std::string telefone):
    _nome(nome), _genero (genero), _cpf (cpf), _telefone(telefone) {}


std::string Pessoas::get_nome(){
    return this->_nome;
}

std::string Pessoas::get_cpf(){
    return this->_cpf;
}

std::string Pessoas::get_telefone(){
    return this->_telefone;
}

char Pessoas::get_genero(){
    return this->_genero;
}
