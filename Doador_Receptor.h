#ifndef DOADOR_RECEPTOR_H
#define DOADOR_RECEPTOR_H
#include "Paciente.h"
#include "Pessoas.h"
#include<iostream>
#include<cstring> 

/* 
Classe responsável
*/

class Doador_Receptor : public Paciente
{
private:
    std::string _tipo_sanguineo;
    int _quantidade_de_sangue;
public:
    Doador_Receptor(const char &genero, const std::string &nome,  const std::string &cpf, std::string telefone, std::string planosaude, const std::string &tipo_sanguineo, int quantidade_de_sangue);

    std::string get_tipo_sanguineo() const;
    int get_quantidade_de_sangue();
    void Adicionar_sangue();
    void Retirar_sangue();
};



#endif
