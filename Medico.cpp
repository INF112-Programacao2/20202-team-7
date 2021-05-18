#include <iostream>
#include <fstream>
#include "Medico.h"
#include <iomanip>
#include <string>

Medico::Medico(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, const std::string &crm, std::string especializacao, int horario_entrada, int horario_saida):
    Pessoas(genero, nome, cpf, telefone), _crm(crm), _especializacao(especializacao), hora_entrada(horario_entrada), hora_saida(horario_saida){}

std::string Medico::getnome_med() const{
    return this->nome_med;
}
/*Função que receberá o nome do Médico.*/

std::string Medico::get_crm() const{
    return this->_crm;
}
/*Função que receberá o CRM do Médico.*/

std::string Medico::get_especializacao(){
    return this->_especializacao;
}
/*Função que receberá a Especialização do Médico.*/
int Medico::get_horarioentrada(){
    return this->hora_entrada;
}
/*Função que receberá o horario de entrada do Médico.*/
int Medico::get_horariosaida(){
    return this->hora_saida;
}
/*Função que receberá o horario de saida do Médico.*/
void Medico::horario_atendimento(){

    std::ifstream hor; /* Arquivo do qual sera retirado os horarios de atendimento da equipe médica.*/
    std::string nome, especializacao;
    int hora_entrada, hora_saida;

    hor.open("horario.txt"); /*Abertura do arquivo.*/

    if(!hor.is_open()){
        throw "Arquivo inexistente.";  /*Tratamento de exceção caso não ocorra a abertura correta do arquivo.*/
    }

    std::cout << "\t\t" << std::right << "NOME:" << std::setw(30) << "ESPECIALIZACAO:" << std::setw(17) << "HORARIOS:" << std::endl;
    while(!hor.eof()){

        std::getline(hor, nome, ',');

        std::getline(hor, especializacao, ',');

        hor >> hora_entrada;
        hor.ignore();

        hor >> hora_saida;
        hor.ignore();
        /*leitura dos referidos dados do médico, tais quais nome, especialização, horario entrada e saida.*/

    std::cout << "\t\t" << std::left << std::setw(20) << nome <<std::setw(23) << especializacao << std::left << hora_entrada << "-" << hora_saida << std::endl;
    hor.ignore();

    }   
    hor.close(); /*Fechamento do arquivo.*/
}

void Medico::exibirDados(){
    /*Função responsável por exibir os dados adquiridos via abertura do arquivo na função anterior.*/
    
    std::ifstream med;
    std::string genero, nome, cpf, tel, crm, especializacao;
    int hora_entrada, hora_saida;

    med.open("medicos.txt");

    if(!med.is_open()){
        throw "Arquivo inexistente."; /*Tratamento de exceção caso não ocorra a abertura correta do arquivo.*/
    }

    std::cout << "\t\t" << std::right << "SEXO:" << std::setw(7) << "NOME:" << std::setw(24) << "TELEFONE:" << std::setw(7) << "CRM:" << std::setw(12) << "CPF:" << std::setw(29) << "ESPECIALIZACAO:" << std::setw(13) << "HORARIOS:" << std::endl;
    while(!med.eof()){

        std::getline(med, genero, ',');

        std::getline(med, nome, ',');

        std::getline(med, crm, ',');

        std::getline(med, cpf, ',');

        std::getline(med, tel, ',');

        std::getline(med, especializacao, ',');

        med >> hora_entrada;
        med.ignore();

        med >> hora_saida;
        med.ignore();

    
    std::cout << "\t\t" << std::left << std::setw(7) << genero << std::setw(20) << nome <<std::setw(12) << cpf << std::setw(12) << tel << std::setw(18) << crm << std::setw(19) << especializacao << hora_entrada << "-" << hora_saida << std::endl;
    /*Impressão dos dados adquiridos mediante metodos pre-estabelecidos.*/
    med.ignore();

    }

    med.close(); /* Fechamento do arquivo.*/
}

void Medico::Mudar_Registro(){
   /* Função responsável por alterar os registro de um médico, seguindo a respectiva ordem: genero(M ou F), Nome, CPF, CRM, Telefone, Especialização, horarios de entrada e saida.*/
    std::ofstream med; 
    
    med.open("medicos.txt", std::ios::app);    
    
    if(!med.is_open()){
       throw "Arquivo inexistente.";
    }

    med << get_genero() << "," << get_nome() << "," << get_cpf() << ", " << get_crm() << "," << get_telefone() << "," << get_especializacao() << "," << get_horarioentrada() << "," << get_horariosaida() << "," << std::endl;
    med.close(); /* Fechamento do arquivo.*/

}
