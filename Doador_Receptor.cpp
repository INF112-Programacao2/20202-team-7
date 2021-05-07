#include "Doador_Receptor.h"
#include <iostream>
#include <fstream>


Doador_Receptor::Doador_Receptor(std::string nome, char genero, std::string cpf, std::string telefone, std::string planosaude,std::string tipo_sanguineo,int quantidade_de_sangue):
    Pessoas(nome,genero,cpf,telefone), Paciente(planosaude), tipo_sanguineo(tipo_sanguineo), quantidade_de_sangue(quantidade_de_sangue) {}

void Doador_Receptor::Adicionar_sangue(){

}    

void Doador_Receptor::Retirar_sangue(){

} 
