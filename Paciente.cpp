#include <iostream>
#include <fstream>
#include "Pessoas.h"
#include "Paciente.h"
#include "Medico.h"
#include <iomanip>
#include <string>
#include <cstring>

Paciente::Paciente(std::string nome, char genero, std::string cpf, std::string telefone, std::string planosaude):
    Pessoas(nome, genero, cpf, telefone, planosaude){}

void Paciente::Marcar_Consulta(){
    std::string _nome;
    std::string _genero;
    std::string _cpf;
    std::string _telefone;
    int count = 0;
    
    std::ofstream pac;
    
    pac.open("paciente.txt", std::ios::app);    
    
    if(!pac.is_open()){
        std::cerr <<  "File not found." << std::endl;
        exit(1);
    }
    std::cout << "-------------------------------AGENDAR CONSULTA-------------------------------" << std::endl;
    std::cout << "NOME: \n" << "GENERO: \n" << "ESPECIALIZACAO: \n" << "HORARIO ENTRADA: \n"  << "HORARIO SAIDA: \n" << std::endl;
    std::cin >> _nome >> _genero >> _cpf >>_telefone;
    pac << _nome <<  _genero << _cpf  << _telefone;           
    
    pac.close();
}

void Paciente::Cancelar_Consulta(){
    std::cout << "-------------------------------ALTERAR REGISTRO MEDICO-------------------------------" << std::endl;
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


}


