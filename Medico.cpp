#include <iostream>
#include <fstream>
#include "Medico.h"
#include <iomanip>
#include <string>

Medico::Medico(std::string nome, char genero, std::string cpf, std::string telefone, std::string especializacao, std::string crm, std::string horarioentrada, std::string horariosaida):
    Pessoas(nome, genero, cpf, telefone), _especializacao(especializacao), _crm(crm), _horarioentrada(horarioentrada), _horariosaida(horariosaida){}

void Medico::registrar_medico(){
    std::string _nome;
    std::string _especializacao;
    std::string _crm;
    std::string _horarioentrada;
    std::string _horariosaida;
    int count = 0;
    
    std::ofstream med;
    
    med.open("medicos.txt", std::ios::app);    
    
    if(!med.is_open()){
        std::cerr <<  "File not found." << std::endl;
        exit(1);
    }
    std::cout << "-------------------------------ADICIONAR MEDICO--------------------" << std::endl;
    std::cout << "NOME: \n" << "CRM: \n" << "ESPECIALIZACAO: \n" << "HORARIO ENTRADA: \n"  << "HORARIO SAIDA: \n" << std::endl;
    std::cin >> _nome >> _crm >> _especializacao >>_horarioentrada >>_horariosaida;
    med << _nome <<  _crm << _especializacao  << _horarioentrada << _horariosaida;
           
    
    med.close();
}

void Medico::alterar_medico(){
    std::cout << "-------------------------------ALTERAR REGISTRO MEDICO--------------------" << std::endl;
    std::cout << "Selecione a operação administrativa que deseja fazer: \n";
    std::cout <<  "1 - Mudar horário de um médico. \n";
    std::cout <<  "2 - Remover medico da equipe. \n";   
    
    std::string _nome;
    std::string _especializacao;
    std::string _crm;
    std::string _horarioentrada;
    std::string _horariosaida;
    int resposta = 0;
    int x;
    
    std::cin >> resposta;
    if(resposta = 1){
        std::ifstream med;
         
        if(!med.is_open()){
        std::cout << "Arquivo inexistente." <<std::endl; 
        exit(1);
        
        std::cout  << std::setw(7) << "Nome: " << std::setw(6) << "CRM: " << std::setw(6) << "Especializacao: " << std::setw(9) << "Horario entrada:" << std::setw(3) << "Horario saida: " << std::setw(3) << std::endl;
        //while(!med.eof()){
            med >> x;
            med.ignore();
            std::getline(med, _nome,',');
            std::getline(med, _crm,',');
            std::getline(med, _especializacao,',');
            std::getline(med, _horarioentrada, ',');
            std::getline(med, _horariosaida, ',');
            med.ignore();
            std::cout  << std::setw(7) << x << std::setw(7) << _nome  << std::setw(6) << _crm << std::setw(6) << _especializacao << std::setw(9) << _horarioentrada << std::setw(3) << _horariosaida << std::setw(3) << std::endl;

        }

    if(resposta = 2){

    }
}

void Medico::get_especializacao(){
    return this->_especializacao;
}

void Medico::get_crm(){
    return this->_crm;
}

void Medico::get_horarioentrada(){
    return this->_horarioentrada;
}

void Medico::get_horariosaida(){
    return this->_horariosaida;
}

Medico::~Medico(){

}
