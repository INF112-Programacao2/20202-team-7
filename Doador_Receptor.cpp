#include "Doador_Receptor.h"
#include "Pessoas.h"
#include "Paciente.h"
#include <iostream>
#include <fstream>
#include<vector>


Doador_Receptor::Doador_Receptor(std::string nome, char genero, std::string cpf, std::string telefone, std::string planosaude,std::string tipo_sanguineo,int quantidade_de_sangue):
    Pessoas(nome,genero,cpf,telefone),Paciente(planosaude), _tipo_sanguineo(tipo_sanguineo), _quantidade_de_sangue(quantidade_de_sangue) {}
void Doador_Receptor::Adicionar_sangue(){

    std::ifstream arquivo_saida;
    arquivo_saida.open("tipagem.txt");

    if (!arquivo_saida.is_open())
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


    


    std::ofstream gravar_informacoes;

    gravar_informacoes.open("doadores.txt");

    if (!gravar_informacoes.is_open())
    {
        throw "Arquivo inexistente";
    }


}    

void Doador_Receptor::Retirar_sangue(){

} 

int Doador_Receptor::get_quantidade_de_sangue(){
    return this->_quantidade_de_sangue;
}

std::string Doador_Receptor::get_tipo_sanguineo(){
    return this-> _tipo_sanguineo;
}