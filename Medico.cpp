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

std::string Medico::get_crm() const{
    return this->_crm;
}

std::string Medico::get_especializacao(){
    return this->_especializacao;
}

int Medico::get_horarioentrada(){
    return this->hora_entrada;
}

int Medico::get_horariosaida(){
    return this->hora_saida;
}

void Medico::horario_atendimento(){

    std::ifstream hor;
    std::string nome, especializacao;
    int hora_entrada, hora_saida;

    hor.open("horario.txt");

    if(!hor.is_open()){
        throw "Arquivo inexistente.";
    }

    while(!hor.eof()){

        std::getline(hor, nome, ',');

        std::getline(hor, especializacao, ',');

        hor >> hora_entrada;
        hor.ignore();

        hor >> hora_saida;
        hor.ignore();

    
    std::cout << "\t\t" << std::right << "NOME:" << std::setw(15) << "ESPECIALIZACAO:" << std::setw(17) << "HORARIOS:" << std::endl;
    std::cout << "\t\t" << std::left << std::setw(7) << nome <<std::setw(12) << especializacao << std::setw(12) << hora_entrada << "-" << hora_saida << std::endl;

    hor.ignore();
    }   
    hor.close();
}

void Medico::exibirDados(){
    std::ifstream med;
    std::string genero, nome, cpf, tel, crm, especializacao;
    int hora_entrada, hora_saida;

    med.open("medicos.txt");

    if(!med.is_open()){
        throw "Arquivo inexistente.";
    }

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

    
    std::cout << "\t\t" << std::right << "SEXO" << std::setw(11) << "NOME:" << std::setw(15) << "CPF:" << std::setw(17) << "TELEFONE:" << std::setw(12) << "CRM:" << std::setw(15) << "ESPECIALIZACAO:" << std::setw(17) << "HORARIOS:" << std::endl;
    std::cout << "\t\t" << std::left << std::setw(7) << genero << std::setw(20) << nome <<std::setw(12) << cpf << std::setw(12) << tel << std::setw(12) << crm << std::setw(9) << especializacao << std::setw(12) << hora_entrada << "-" << hora_saida << std::endl;

    med.ignore();

    }

    med.close();
}

void Medico::Mudar_Registro(){
   
    std::ofstream med;
    
    med.open("medicos.txt", std::ios::app);    
    
    if(!med.is_open()){
       throw "Arquivo inexistente.";
    }

    med << get_genero() << "," << get_nome() << "," << get_cpf() << ", " << get_crm() << "," << get_telefone() << "," << get_especializacao() << "," << get_horarioentrada() << "," << get_horariosaida() << "," << std::endl;
    med.close();

}





