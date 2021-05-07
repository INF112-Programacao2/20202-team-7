#ifndef DOADOR_RECEPTOR_H
#define DOADOR_RECEPTOR_H
#include "Paciente.h"
#include<iostream>
#include<cstring> 
class Doador_Receptor : public Paciente
{
private:
    std::string tipo_sanguineo;
    int quantidade_de_sangue;
public:
    Doador_Receptor(std::string nome, char genero, std::string cpf, std::string telefone, std::string planosaude,std::string tipo_sanguineo,int quantidade_de_sangue);
    ~Doador_Receptor();
    void Adicionar_sangue();
    void Retirar_sangue();
};



#endif
