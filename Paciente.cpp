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
    //construtor da classe paciente.

std::string Paciente::get_planosaude(){
    return this->_planosaude; //armazena o plano de saude dentro da váriavel global
}

void Paciente::exibirDados(){
    
    std::ifstream pac;   //ponteiro para abertura e leitura de arquivo
    std::string genero, nome, cpf, tel, pl_saude; //strings utilizadas para armazenar as informações 
    pac.open("paciente.txt");  //abertura do arquivo

    if(!pac.is_open()){
        throw "Arquivo inexistente.";   //caso o arquivo não exista retorna essa mensagem.
    }

    std::cout << "\t\t" << std::right << "SEXO:" << std::setw(7) << "NOME:" << std::setw(19) << "CPF:" << std::setw(20) << "TELEFONE:" << std::setw(12) << "CONVENIO:" << std::endl; //inserção das informações
    while(!pac.eof()){

        std::getline(pac, genero, ',');  

        std::getline(pac, nome, ',');

        std::getline(pac, cpf, ',');

        std::getline(pac, tel, ',');

        std::getline(pac, pl_saude, ',');
        //transfere as informações do arquivo para as strings. 

    std::cout << "\t\t" << std::left << std::setw(7) << genero <<std::setw(20) << nome << std::setw(15) << cpf << std::setw(12) << tel << std::setw(12) << pl_saude << std::endl;
    pac.ignore(); //retorna as informações solicitadas.
    
    }
    std::cout << std::endl;
    pac.close(); //fecha o arquivo

}

void Paciente::Marcar_Consulta(){
    
    std::ofstream pac; //abertura e escrita do arquvio.
    
    pac.open("paciente.txt", std::ios::app);    //abrindo o arquivo na ultima posição para poder continuar a escrita e não apagar ele por completo.
    
    if(!pac.is_open()){
       throw "Arquivo inexistente."; //caso o arquivo não existe
    }
   
    pac << get_genero() << "," << get_nome() << "," << get_cpf()  << "," << get_telefone() << "," << get_planosaude() << "," << std::endl;  //inserção de informações no arquivo.
   
    pac.close(); //fecha o arquivo e salva
}






