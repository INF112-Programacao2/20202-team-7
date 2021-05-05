#ifndef MEDICO_H
#define MEDICO_H
#include <iostream>
#include <string>
#include "pessoas.h"

class Medico: public Pessoas{
    private:
    std::string _nome;
    std::string _especializacao;
    std::string _crm;
    std::string _horarioentrada;
    std::string _horariosaida;

    
    public:
    virtual std::string get_nome();
    virtual std::string get_cpf();
    virtual std::string get_telefone();
    virtual char get_genero(); 
    void exibirDados(); 
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
