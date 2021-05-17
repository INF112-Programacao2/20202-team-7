#ifndef PACIENTE_H
#define PACIENTE_H
#include "Pessoas.h"

class Paciente : public Pessoas
{
private:
    std::string _planosaude;
    
public:

   
    Paciente(const char &genero, const std::string &_nome, const std::string &cpf, const std::string telefone, std::string planosaude);

    void exibirDados();
    void Marcar_Consulta();
    void Cancelar_Consulta();
    std::string get_planosaude();  
   
};



#endif