#ifndef MEDICO_H
#define MEDICO_H
#include <iostream>
#include <string>
#include "Pessoas.h"

/* Criação da classe Médico, responsavel pelas funções previamente definidas no CRC, tais quais o registro e especificações referentes a equipe médica.
*/
class Medico: public Pessoas{
    private:
    std::string nome_med;
    std::string _especializacao;
    std::string _crm;
    int hora_entrada, hora_saida;
    /*Especificação dos atributos referentes unicamente à classe Medico.*/
    
    public:
    Medico(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, const std::string &crm, std::string especializacao, int hora_entrada, int hora_saida);
    /*Construtor que receberá dados da Classe pessoa e também da classe Médico.*/
    void horario_atendimento();
    virtual void exibirDados() override;
    void Mudar_Registro();
    void Mudar_Horario();
    std::string getnome_med() const; /* Função responsável por receber o nome do Médico.*/
    std::string get_especializacao();  /* Função responsável por receber a especializacao do Médico.*/
    std::string get_crm() const;/* Função responsável por receber o CRM (numero de inscrição no Conselho Regional de Medicina) do Médico.*/
    int get_horarioentrada(); /* Função responsável por receber o horario de entrada do Médico no hospital.*/
    int get_horariosaida(); /* Função responsável por receber o horario de saida do Médico no hospital.*/
    
   

};

#endif
