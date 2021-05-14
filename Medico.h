#ifndef MEDICO_H
#define MEDICO_H
#include <iostream>
#include <string>
#include "Pessoas.h"

class Medico: public Pessoas{
    private:
    std::string nome_med;
    std::string _especializacao;
    std::string _crm;
    int hora_entrada, hora_saida;

    
    public:
    Medico(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, const std::string &crm, std::string especializacao, int hora_entrada, int hora_saida);

    void horario_atendimento();
    virtual void exibirDados() override;
    void registrar_medico();
    void alterar_medico();
    std::string getnome_med() const;
    std::string get_especializacao();
    std::string get_crm() const;
    int get_horarioentrada();
    int get_horariosaida();

   
    


};

#endif
