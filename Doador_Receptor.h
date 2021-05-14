#ifndef DOADOR_RECEPTOR_H
#define DOADOR_RECEPTOR_H
#include "Paciente.h"
#include "Pessoas.h"
#include<iostream>
#include<cstring> 
class Doador_Receptor : public Paciente
{
private:
    std::string _tipo_sanguineo;
    int _quantidade_de_sangue;
public:
    Doador_Receptor(char genero, std::string nome, std::string cpf, std::string telefone, std::string planosaude,std::string tipo_sanguineo,int quantidade_de_sangue);
    ~Doador_Receptor();
    std::string get_tipo_sanguineo();
    int get_quantidade_de_sangue();
    void Adicionar_sangue();
    void Retirar_sangue();
};



#endif
