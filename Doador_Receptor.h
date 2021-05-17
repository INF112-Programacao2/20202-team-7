#ifndef DOADOR_RECEPTOR_H
#define DOADOR_RECEPTOR_H
#include "Paciente.h"
#include "Pessoas.h"
#include<iostream>
#include<cstring> 

/* 
    Classe responsável por pegar os dados de um doador ou receptor de sangue do hospital
    e fazer o registro de tais dados e modificar o banco de sangue
*/

class Doador_Receptor : public Paciente
{
private:
    std::string _tipo_sanguineo;
    int _quantidade_de_sangue;
public:

    // construtor que pegará os dados do doador ou do receptor 
    Doador_Receptor(const char &genero, const std::string &nome,  const std::string &cpf, std::string telefone, std::string planosaude, const std::string &tipo_sanguineo, int quantidade_de_sangue);

    std::string get_tipo_sanguineo() const;
    int get_quantidade_de_sangue();

    // Função que irá adicionar sangue no banco de sangue e registrar os dados da pessoa que doou o sangue
    void Adicionar_sangue();

    // Função que irá retirar sangue no banco de sangue e registrar os dados da pessoa que usou do sangue
    void Retirar_sangue();
};



#endif
