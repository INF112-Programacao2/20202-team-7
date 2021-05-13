#ifndef PACIENTE_H
#define PACIENTE_H
#include "Pessoas.h"

class Paciente : public Pessoas
{
private:
    std::string _nome;
    std::string _cpf;
    std::string _telefone;
    std::string _planosaude;
    
public:
    Paciente(std::string nome, char genero, std::string cpf, std::string telefone, std::string planosaude);
    void Exibir_Dados();
    void Marcar_Consulta();
    void Cancelar_Consulta();  
    ~Paciente();
};



#endif