#include <iostream>
#include <fstream>
#include "Pessoas.h"
#include "Paciente.h"
#include "Medico.h"
#include <iomanip>
#include <string>
#include <cstring>

Paciente::Paciente(std::string nome, char genero, std::string cpf, std::string telefone, std::string planosaude):
    Pessoas(nome, genero, cpf, telefone){}

void Paciente::Marcar_Consulta(){
    std::string _nome;
    std::string _genero;
    std::string _cpf;
    std::string _telefone;
    int count = 0;
    
    std::ofstream pac;
    
    med.open("paciente.txt", std::ios::app);    
    
    if(!pac.is_open()){
        std::cerr <<  "File not found." << std::endl;
        exit(1);
    }
    std::cout << "-------------------------------AGENDAR CONSULTA-------------------------------" << std::endl;
    std::cout << "NOME: \n" << "GENERO: \n" << "ESPECIALIZACAO: \n" << "HORARIO ENTRADA: \n"  << "HORARIO SAIDA: \n" << std::endl;
    std::cin >> _nome >> _genero >> _cpf >>_telefone >>;
    pac << _nome <<  _genero << _cpf  << _telefone;
           
    
    pac.close();
}


