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
/*
    Essa função irá fazer a modificação nos arquivos referentes a quantidade de cada tipo de sangue e de registro de doadores
    Irá pegar a quantidade de sangue que tem já registrado de cada tipo sanguíneo e irá adicionar sangue no tipo sanguíneo 
    referente ao do doador, e também, irá fazer registro dos dados desse doador

*/
void Doador_Receptor::Adicionar_sangue(){

    // arquivo que iremos pegar os dados do sangue para ser modificados
    std::ifstream arquivo_saida;

    // arquivo que iremos registrar os dados já modificados do sangue
    std::ofstream arquivo_receptor;

    arquivo_saida.open("tipagem.txt");

    arquivo_receptor.open("tipagem.txt");

    // tratamento de exceção caso o arquivo não abra
    if (!arquivo_saida.is_open())
    {
        throw "Arquivo inexistente";
    }
     if (!arquivo_receptor.is_open())
    {
        throw "Arquivo inexistente";
    }

    
    char virgula = ',';
    int sangue[4];
    int cont = 0,quant_sangue;
    
    std::string palavra;

    // irá ler o arquivo e pegar os números, além de registar esses valores em uma variável
    while (!arquivo_saida.eof())
    {

        arquivo_saida>> quant_sangue;
        arquivo_saida.ignore();

        std::getline(arquivo_saida,palavra,virgula);

        sangue[cont] = quant_sangue;
        cont++;
        
   }

  

 
    // irá transformar a variável que armazena os valores da quantidade sangue de cada tipo sanguíneo de string para int
    // para dessa forma, poder ser modificada com sangue que está sendo audicionado 
    
   
    

    // vai adicionar o sangue referente ao tipo sanguíneo
    if(get_tipo_sanguineo() == "AB") sangue[0] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "A") sangue[1] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "B") sangue[2] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "O") sangue[3] += get_quantidade_de_sangue();
   
    // vai registrar no arquivo de tipagem os novos valores modificados
    arquivo_receptor << sangue[0] <<",AB,"<<std::endl;
    arquivo_receptor << sangue [1] <<",A,"<<std::endl;
    arquivo_receptor << sangue[2] <<",B,"<<std::endl;
    arquivo_receptor << sangue[3] <<",O,"<<std::endl;    
 
    std::ofstream gravar_informacoes;

    // abrir o arquivo de doadores para poder ser registrado novos valores 
    gravar_informacoes.open("doadores.txt",std::ios::app);

    if (!gravar_informacoes.is_open())
    {
        throw "Arquivo inexistente";
    }
    
    // vai gravar as informações referente ao doador no arquivo de doadores
    gravar_informacoes << get_genero() << "," << get_nome() << ","  << get_cpf() << "," << get_telefone() << "," << get_planosaude() << "," << get_tipo_sanguineo() << "," << get_quantidade_de_sangue() << "," << std::endl;
    
    // fechando todos os arquivos que foram abertos durante a execução do programa
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

    int quant_sangue;
    char virgula = ',';
    int cont = 0;
    std::string palavra;
    int sangue[4];

    while (!arquivo_saida.eof())
    {

        arquivo_saida>> quant_sangue;
        arquivo_saida.ignore();

        std::getline(arquivo_saida,palavra,virgula);

        sangue[cont] = quant_sangue;
        cont++;
        
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
