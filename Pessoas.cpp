#include "Pessoas.h"
#include <string>


Pessoas::Pessoas(std::string *nome, char *genero, std::string *cpf, std::string *telefone){
    _nome = new std::string[QUANTIDADE_DE_PESSOAS];
    _genero = new char[QUANTIDADE_DE_PESSOAS];
    _cpf = new std::string[QUANTIDADE_DE_PESSOAS];
    _telefone = new std::string[QUANTIDADE_DE_PESSOAS];

    for(int i = 0; i < QUANTIDADE_DE_PESSOAS; i++){
        _nome[i] = nome[i];
        _genero[i] = genero[i];
        _cpf[i] = cpf[i];
        _telefone[i] = telefone[i];
    }
}

std::string Pessoas::get_nome(int n){
    return this->_nome[n];
}

std::string Pessoas::get_cpf(int n){
    return this->_cpf[n];
}

std::string Pessoas::get_telefone(int n){
    return this->_telefone[n];
}

char Pessoas::get_genero(int n){
    return this->_genero[n];
}

Pessoas::~Pessoas(){
    delete[] _nome;
    delete[] _genero;
    delete[] _cpf;
    delete[] _telefone;
}