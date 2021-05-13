#include "Banco_de_Sangue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void Banco_de_Sangue::DadosBancoSangue()
{

    std::string sexo_d, nome, tipo_recptor, tipo_doador, cpf_d, tel_d, plsaude_d, sexo_r, _nome, cpf_r, tel_r, plsaude_r;
    std::ifstream doa, rec;
    int qtd_doada, qtd_recebida;

    doa.open("doadores.txt");

   
    if (!doa.is_open())
    {
        throw "Arquivo inexistente.";

    }
    std::cout << "\t\t" << std::right << "SEXO:" << std::setw(11) << "DOADORES:" << std::setw(15) << "CPF:" << std::setw(17) << "TELEFONE:" << std::setw(12) << "CONVENIO:" << std::setw(8) << "TIPO:" << std::setw(18) << "QUANTIDADE/mL:" << std::endl;

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

        std::cout << "\t\t" << std::left << std::setw(7) << sexo_d <<std::setw(20) << nome << std::setw(12) << cpf_d << std::setw(12) << tel_d << std::setw(12) << plsaude_d << std::setw(9) << tipo_doador << qtd_doada << std::endl;
        doa.ignore();
    }
    std::cout << std::endl;
    doa.close();

    rec.open("receptores.txt");

  
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

    std::ifstream tip;
    std::string tipo;
    int i = 0, qtd_sangue, qtd_total[i], qtd_final = 0;
    tip.open("tipagem.txt");

  
    if (!tip.is_open())
    {
        throw "Arquivo inexistente.";
   
    }

    while (!tip.eof())
    {
        tip >> qtd_sangue;
        tip.ignore();

        std::getline(tip, tipo, ',');
        qtd_total[i] = qtd_sangue;
        i++;
    }

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

    std::ifstream tip;
    std::string tipo;
    int i = 0, qtd;
    tip.open("tipagem.txt");

  
    if (!tip.is_open())
    {
        throw "Arquivo inexistente.";
    }
    std::cout << "\t\t" << std::right << "QUANTIDADE/mL:" << std::setw(10) << "TIPO:" << std::endl;

    // 4 tipos de sangue
    while (i != 4)
    {
        tip >> qtd;
        tip.ignore();

        std::getline(tip, tipo, ',');

        std::cout << "\t\t" << std::left << std::setw(19) << qtd << tipo << std::endl;
        i++;
    }
    std::cout << std::endl;

    tip.close();
}