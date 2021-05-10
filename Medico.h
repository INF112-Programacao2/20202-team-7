#ifndef MEDICO_H
#define MEDICO_H
#include <iostream>
#include <string>
#include "Pessoas.h"

class Medico: public Pessoas{
    private:
    std::string _especializacao;
    std::string _crm;
    std::string _horarioentrada;
    std::string _horariosaida;

    
    public:
    virtual std::string get_nome() override;
    virtual std::string get_cpf() override;
    virtual std::string get_telefone() override;
    virtual char get_genero() override;
    virtual void exibirDados() override;
    void registrar_medico();
    void alterar_medico();
    void get_especializacao();
    void get_crm();
    void get_horarioentrada();
    void get_horariosaida();

   
    Medico(std::string nome, char genero, std::string cpf, std::string telefone, std::string especializacao, std::string crm, std::string horarioentrada, std::string horariosaida);
    ~Medico();


};

#endif
