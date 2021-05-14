#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include<sstream>
#include "Pessoas.h"
#include "Paciente.h"


Paciente::Paciente(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, std::string planosaude):
    Pessoas(genero, nome, cpf, telefone),_planosaude(planosaude){}


Paciente::Paciente(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone):
    Pessoas(genero, nome, cpf, telefone) {}


std::string Paciente::get_planosaude(){
    return this->_planosaude;
}

void Paciente::exibirDados(){
    
    std::ifstream pac;
    std::string genero, nome, cpf, tel, pl_saude;
    pac.open("pacientes.txt");

    if(!pac.is_open()){
        throw "Arquivo inexistente.";
    }

    while(!pac.eof()){

        std::getline(pac, genero, ',');

        std::getline(pac, nome, ',');

        std::getline(pac, cpf, ',');

        std::getline(pac, tel, ',');

        std::getline(pac, pl_saude, ',');

    
    std::cout << "\t\t" << std::right << "SEXO:" << std::setw(11) << "NOME:" << std::setw(15) << "CPF:" << std::setw(17) << "TELEFONE:" << std::setw(12) << "CONVENIO:" << std::endl;
    std::cout << "\t\t" << std::left << std::setw(7) << genero <<std::setw(20) << nome << std::setw(12) << cpf << std::setw(12) << tel << std::setw(12) << pl_saude << std::setw(9) << std::endl;
    pac.ignore();

    }

    pac.close();

}

void Paciente::Marcar_Consulta(){
    
    std::ofstream pac;
    
    pac.open("paciente.txt", std::ios::app);    
    
    if(!pac.is_open()){
       throw "Arquivo inexistente.";
    }
   
    pac << get_genero() << "," << get_nome() << "," << get_cpf()  << "," << get_telefone() << "," << get_planosaude() << "," << std::endl;  
   
    pac.close();
}

void Paciente::Cancelar_Consulta(){

    std::string temp;
    std::ifstream pac;
    pac.open("paciente.txt", std::fstream::in);

    std::stringstream sstr;
    std::cin.ignore();

  
    pac.close();

}






