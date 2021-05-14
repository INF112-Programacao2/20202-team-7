#ifndef PACIENTE_H
#define PACIENTE_H
#include "Pessoas.h"

class Paciente : public Pessoas
{
private:
    std::string _planosaude;
    
public:

   
    Paciente(char genero, std::string _nome, std::string cpf, std::string telefone, std::string planosaude);
    Paciente(char genero, std::string nome, std::string cpf, std::string telefone);

    void exibirDados();
    void Marcar_Consulta();
    void Cancelar_Consulta();
    std::string get_planosaude();  
   
};



#endif