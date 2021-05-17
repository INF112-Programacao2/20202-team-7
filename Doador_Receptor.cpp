#include "Doador_Receptor.h"
#include "Pessoas.h"
#include "Paciente.h"
#include <iostream>
#include <fstream>
#include <string>
#include<vector>


Doador_Receptor::Doador_Receptor(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, std::string planosaude, const std::string &tipo_sanguineo,int quantidade_de_sangue):
   Paciente(genero, nome, cpf, telefone, planosaude), _tipo_sanguineo(tipo_sanguineo), _quantidade_de_sangue(quantidade_de_sangue) {}

int Doador_Receptor::get_quantidade_de_sangue(){
    return this->_quantidade_de_sangue;
}

std::string Doador_Receptor::get_tipo_sanguineo() const{
    return this-> _tipo_sanguineo;
}

void Doador_Receptor::Adicionar_sangue(){

    std::ifstream arquivo_saida;

    std::ofstream arquivo_receptor;

    arquivo_saida.open("tipagem.txt");

    arquivo_receptor.open("tipagem.txt");


    if (!arquivo_saida.is_open())
    {
        throw "Arquivo inexistente";
    }
     if (!arquivo_receptor.is_open())
    {
        throw "Arquivo inexistente";
    }

    std::vector<std::string> quant_sangue;
    char virgula = ',';
    int contador = 0;
    std::string palavra;

    while (!arquivo_saida.eof())
    {
        std::getline(arquivo_saida,palavra,virgula);
        if(contador%2 == 0){
            quant_sangue.push_back(palavra);
        }
        contador++;
    }

    int sangue[4];

    for (int i = 0; i < 4; i++)
    {
        sangue[i] = std::stoi(quant_sangue[i]);
    }

    if(get_tipo_sanguineo() == "AB") sangue[0] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "A") sangue[1] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "B") sangue[2] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "O") sangue[3] += get_quantidade_de_sangue();
   

    arquivo_receptor << sangue[0] <<",AB,"<<std::endl;
    arquivo_receptor << sangue [1] <<",A,"<<std::endl;
    arquivo_receptor << sangue[2] <<",B,"<<std::endl;
    arquivo_receptor << sangue[3] <<",O,"<<std::endl;    
 
    std::ofstream gravar_informacoes;

    gravar_informacoes.open("doadores.txt",std::ios::app);

    if (!gravar_informacoes.is_open())
    {
        throw "Arquivo inexistente";
    }

    gravar_informacoes << get_genero() << "," << get_nome() << ","  << get_cpf() << "," << get_telefone() << "," << get_planosaude() << "," << get_tipo_sanguineo() << "," << get_quantidade_de_sangue() << "," << std::endl;
    
    gravar_informacoes.close();
    arquivo_saida.close();
    arquivo_receptor.close();
}    

void Doador_Receptor::Retirar_sangue(){
      std::ifstream arquivo_saida;

    std::ofstream arquivo_receptor;

    arquivo_saida.open("tipagem.txt");

    arquivo_receptor.open("tipagem.txt");


    if (!arquivo_saida.is_open())
    {
        throw "Arquivo inexistente";
    }
     if (!arquivo_receptor.is_open())
    {
        throw "Arquivo inexistente";
    }

    std::vector<std::string> quant_sangue;
    char virgula = ',';
    int contador = 0;
    std::string palavra;

    while (!arquivo_saida.eof())
    {
        std::getline(arquivo_saida,palavra,virgula);
        if(contador%2 == 0){
            quant_sangue.push_back(palavra);
        }
        contador++;
    }

    int sangue[4];

    for (int i = 0; i < 4; i++)
    {
        sangue[i] = std::stoi(quant_sangue[i]);
    }

    if(get_tipo_sanguineo() == "AB")
    {
        if( (sangue[0] - get_quantidade_de_sangue()) < 0 ){
            throw "Impossivel retirar sangue. Valor requisitado acima do que contem no Bando de Sangue ";
        }else{
            sangue[0] -= get_quantidade_de_sangue();
        }
    }
    else if(get_tipo_sanguineo() == "A")
    {
        if( (sangue[1] - get_quantidade_de_sangue()) < 0 ){
            throw "Impossivel retirar sangue. Valor requisitado acima do que contem no Bando de Sangue ";
        }else{
            sangue[1] -= get_quantidade_de_sangue();
        }
    }
    else if(get_tipo_sanguineo() == "B")
    {
        if( (sangue[2] - get_quantidade_de_sangue()) < 0 ){
            throw "Impossivel retirar sangue. Valor requisitado acima do que contem no Bando de Sangue ";
        }else{
            sangue[2] -= get_quantidade_de_sangue();
        }
    } 
    else if(get_tipo_sanguineo() == "O")
    {
        if( (sangue[3] - get_quantidade_de_sangue()) < 0 ){
            throw "Impossivel retirar sangue. Valor requisitado acima do que contem no Bando de Sangue ";
        }else{
            sangue[3] -= get_quantidade_de_sangue();
        }
    } 
   

    arquivo_receptor << sangue[0] <<",AB,"<<std::endl;
    arquivo_receptor << sangue [1] <<",A,"<<std::endl;
    arquivo_receptor << sangue[2] <<",B,"<<std::endl;
    arquivo_receptor << sangue[3] <<",O,"<<std::endl;    
 
    std::ofstream gravar_informacoes;

    gravar_informacoes.open("doadores.txt",std::ios::app);

    if (!gravar_informacoes.is_open())
    {
        throw "Arquivo inexistente";
    }

    gravar_informacoes << get_genero() << "," << get_nome() << ","  << get_cpf() << "," << get_telefone() << "," << get_planosaude() << "," << get_tipo_sanguineo() << "," << get_quantidade_de_sangue() << "," << std::endl;
    
    gravar_informacoes.close();
    arquivo_saida.close();
    arquivo_receptor.close();

} 
