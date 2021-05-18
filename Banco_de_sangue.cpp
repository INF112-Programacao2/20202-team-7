#include "Banco_de_Sangue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void Banco_de_Sangue::DadosBancoSangue()
{
    // São criadas variáveis que irão ser relacionadas a cada tipo de informação presente no arquivo
    std::string sexo_d, nome, tipo_recptor, tipo_doador, cpf_d, tel_d, plsaude_d, sexo_r, _nome, cpf_r, tel_r, plsaude_r;
    // Classes de fluxos de arquivos que irão operar o txt
    std::ifstream doa, rec;
    int qtd_doada, qtd_recebida;

    // É feita a abertura do arquivo que contém os dados dos doadores
    doa.open("doadores.txt");

   //Exceção caso o arquivo não exista
    if (!doa.is_open())
    {
        throw "Arquivo inexistente.";

    }
    std::cout << "\t\t" << std::right << "SEXO:" << std::setw(11) << "DOADORES:" << std::setw(15) << "CPF:" << std::setw(17) << "TELEFONE:" << std::setw(12) << "CONVENIO:" << std::setw(8) << "TIPO:" << std::setw(18) << "QUANTIDADE/mL:" << std::endl;

    // É feita a leitura do arquivo, inicializando cada variável criada com os valores presentes nos arquivos
    while (!doa.eof())
    {
        std::getline(doa, sexo_d, ',');

        std::getline(doa, nome, ',');

        std::getline(doa, cpf_d, ',');

        std::getline(doa, tel_d, ',');

        std::getline(doa, plsaude_d, ',');

        std::getline(doa, tipo_doador, ',');

        doa >> qtd_doada;
        doa.ignore();

        // É feita a impressão dos dados. Utilizou-se os manipuladores std::left e std::setw() para configurar a formatação da saída
        std::cout << "\t\t" << std::left << std::setw(7) << sexo_d <<std::setw(20) << nome << std::setw(12) << cpf_d << std::setw(12) << tel_d << std::setw(12) << plsaude_d << std::setw(9) << tipo_doador << qtd_doada << std::endl;
        doa.ignore();
    }
    std::cout << std::endl;
    doa.close();

    // É feita a abertura do arquivo que contém os dados de receptores
    rec.open("receptores.txt");

    // Exceção caso o arquivo não exista
    if (!rec.is_open())
    {
        throw "Arquivo inexistente.";        
    }

    std::cout << "\t\t" << std::right << "SEXO:" << std::setw(13) << "RECEPTORES:" << std::setw(13) << "CPF:" << std::setw(17) << "TELEFONE:" << std::setw(12) << "CONVENIO:" << std::setw(8) << "TIPO:" << std::setw(18) << "QUANTIDADE/mL:" << std::endl;

    while (!rec.eof())
    {
        std::getline(rec, sexo_r, ',');

        std::getline(rec, _nome, ',');

        std::getline(rec, cpf_r, ',');

        std::getline(rec, tel_r, ',');

        std::getline(rec, plsaude_r, ',');

        std::getline(rec, tipo_recptor, ',');

        rec >> qtd_recebida;
        rec.ignore();

        std::cout << "\t\t"<< std::left << std::setw(7) << sexo_r << std::setw(20) << _nome << std::setw(12) << cpf_r << std::setw(12) << tel_r << std::setw(12) << plsaude_r << std::setw(9) << tipo_recptor << qtd_recebida << std::endl;
        rec.ignore();
    }

    std::cout << std::endl;
    rec.close();
}

void Banco_de_Sangue::QuantidadeTotal()
{
    // Classe de fluxo de arquivo que irá operar o txt
    std::ifstream tip;
    std::string tipo;

    // São criadas variáveis que irão ser relacionadas a cada tipo de informação presente no arquivo
    int i = 0, qtd_sangue, qtd_total[i], qtd_final = 0;

    // Abertura do arquivo
    tip.open("tipagem.txt");

    
    // Exceção caso o arquivo não exista
    if (!tip.is_open())
    {
        throw "Arquivo inexistente.";  
    }

    // É feita a leitura do arquivo
    while (!tip.eof())
    {
        tip >> qtd_sangue;
        tip.ignore();

        std::getline(tip, tipo, ',');
        // Armazena em um vetor a quantidade de sangue de cada tipo
        qtd_total[i] = qtd_sangue;
        i++;
    }

    // É feito um loop para adicionar a quantidade total na variável qtd_final
    for (int j = 0; j < i - 1; j++)
    {
        qtd_final += qtd_total[j];
    }
    std::cout <<"\t\tQUANTIDADE TOTAL DE SANGUE: " << qtd_final << " mL" << std::endl;
    std::cout << std::endl;

    tip.close();
}

void Banco_de_Sangue::QuantidadeTipo()
{
    // Classe de fluxo de arquivo que irá operar o txt
    std::ifstream tip;
    std::string tipo;
    int i = 0, qtd;

    // É feita a abertura do arquivo que contém os tipos e quantidades de sangue
    tip.open("tipagem.txt");

  
    // Exceção caso o arquivo não exista
    if (!tip.is_open())
    {
        throw "Arquivo inexistente.";
    }
    std::cout << "\t\t" << std::right << "QUANTIDADE/mL:" << std::setw(10) << "TIPO:" << std::endl;

    /* Como são 4 tipos de sangue, o loop irá ler o arquivo ate que o iterador
        i seja diferente de 4
    */
    while (i != 4)
    {
        tip >> qtd;
        tip.ignore();

    
        std::getline(tip, tipo, ',');
        
        // Será impresso a quantidade de sangue e o tipo 
        std::cout << "\t\t" << std::left << std::setw(19) << qtd << tipo << std::endl;
        i++;
    }
    std::cout << std::endl;

    tip.close();
}