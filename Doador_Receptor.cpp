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

    arquivo_saida.open("tipagem.txt");

    // tratamento de exceção caso o arquivo não abra
    if (!arquivo_saida.is_open())
    {
        throw "Arquivo inexistente";
    }
    
    
    int sangue[4];
    
    std::string::size_type sz;
    std::string palavra;
    std::vector<std::string>texto;

    // irá ler o arquivo e pegar os números, além de registar esses valores em uma variável
    while (!arquivo_saida.eof())
    {
        std::getline(arquivo_saida,palavra);

        texto.push_back(palavra);
        
   }

   for (int i = 0; i < 4; i++){

    sangue[i] = stoi(texto[i],&sz,10);
  
   }

  
    // vai adicionar o sangue referente ao tipo sanguíneo
    if(get_tipo_sanguineo() == "AB") sangue[0] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "A") sangue[1] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "B") sangue[2] += get_quantidade_de_sangue();
    else if(get_tipo_sanguineo() == "O") sangue[3] += get_quantidade_de_sangue();


    //fechando arquivo que retira as quantidades sanguíneas
    arquivo_saida.close();




    // arquivo que iremos registrar os dados já modificados do sangue
    std::ofstream arquivo_receptor;

    arquivo_receptor.open("tipagem.txt");


     if (!arquivo_receptor.is_open())
    {
        throw "Arquivo inexistente";
    }

    // vai registrar no arquivo de tipagem os novos valores modificados
    arquivo_receptor << sangue[0] <<",AB,"<<std::endl;
    arquivo_receptor << sangue [1] <<",A,"<<std::endl;
    arquivo_receptor << sangue[2] <<",B,"<<std::endl;
    arquivo_receptor << sangue[3] <<",O,"<<std::endl;   

    //fechando arquivo que recebe as quantidades sanguíneas
    arquivo_receptor.close(); 



 
    std::ofstream gravar_informacoes;

    // abrir o arquivo de doadores para poder ser registrado novos valores 
    gravar_informacoes.open("doadores.txt",std::ios::app);

    if (!gravar_informacoes.is_open())
    {
        throw "Arquivo inexistente";
    }
    
    // vai gravar as informações referente ao doador no arquivo de doadores
    gravar_informacoes << "\n"<< get_genero() << "," << get_nome() << ","  << get_cpf() << "," << get_telefone() << "," << get_planosaude() << "," << get_tipo_sanguineo() << "," << get_quantidade_de_sangue() << "," ;
    
    // fechando arquivo de informações
    gravar_informacoes.close();
  
} 

/*
    Essa função irá fazer a modificação nos arquivos referentes a quantidade de cada tipo de sangue e de registro de receptores
    Irá pegar a quantidade de sangue que tem já registrado de cada tipo sanguíneo e irá retirar, se for possível,
    sangue no tipo sanguíneo  referente ao do receptor, e também, irá fazer registro dos dados desse receptor

*/


void Doador_Receptor::Retirar_sangue(){
    
    // arquivo que irá pegar os valores de cada tipo de sangue
    std::ifstream arquivo_saida;


    arquivo_saida.open("tipagem.txt");
 

    // tratamento de exceção pra caso o arquivo não abra
    if (!arquivo_saida.is_open())
    {
        throw "Arquivo inexistente";
    }
  
    
    int sangue[4];
  
    std::string::size_type sz;
    std::string palavra;
    std::vector<std::string>texto;

    // irá ler o arquivo e pegar os números, além de registar esses valores em uma variável
    while (!arquivo_saida.eof())
    {
        std::getline(arquivo_saida,palavra);

        texto.push_back(palavra);
        
    }

    for (int i = 0; i < 4; i++){

        sangue[i] = stoi(texto[i],&sz,10);
  
    }

 
    // descobrir qual o tipo sanguíneo do receptor para modifcar no arquivo
    if(get_tipo_sanguineo() == "AB")
    {   
        // tratamento de exceção para caso a subtração do que há no banco de sangue e oque se quer retirar
        // for negativo (Não há como ter valor negativo nesse caso)
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
    // fechando arquivo que recebe os valores
    arquivo_saida.close();


    // arquivo que irá registrar os novos valores de cada tipo de sangue
    std::ofstream arquivo_receptor;

    arquivo_receptor.open("tipagem.txt");


    // tratamento de exceção
    if (!arquivo_receptor.is_open())
    {
        throw "Arquivo inexistente";
    }
   
    // registrando os valores antigos e oque foi modificado novamente no arquivo
    arquivo_receptor << sangue[0] <<",AB,"<<std::endl;
    arquivo_receptor << sangue [1] <<",A,"<<std::endl;
    arquivo_receptor << sangue[2] <<",B,"<<std::endl;
    arquivo_receptor << sangue[3] <<",O,"<<std::endl;    

    //fechando arquivo
    arquivo_receptor.close();


    // gravar as informações do receptor de sangue
    std::ofstream gravar_informacoes;

    gravar_informacoes.open("doadores.txt",std::ios::app);

    if (!gravar_informacoes.is_open())
    {
        throw "Arquivo inexistente";
    }

    gravar_informacoes <<"\n"<< get_genero() << "," << get_nome() << ","  << get_cpf() << "," << get_telefone() << "," << get_planosaude() << "," << get_tipo_sanguineo() << "," << get_quantidade_de_sangue() << "," ;
    
    //fechamento dos arquivos 
    gravar_informacoes.close();
   
    

} 
