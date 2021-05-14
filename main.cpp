#include <iostream>
#include <iomanip>
#include "Banco_de_Sangue.h"
#include "Pessoas.h"
#include "Paciente.h"

void Secretaria()
{

    char genero;
    std::string nome, sobrenome, cpf, tel, pl_saude;
    int ans;
    std::cout << std::setw(30) << "\t\t---------------------------------------------------" << std::endl;

    std::cout << "\t\tDIGITE 1 : Horario de atendimento dos medicos" << std::endl;
    std::cout << "\t\tDIGITE 2 : Agendar consulta" << std::endl;
    std::cout << "\t\tDIGITE 3 : Cancelar consulta" << std::endl;
    std::cout << "\t\tDIGITE 4 : Doar sangue" << std::endl;
    std::cout << "\t\tDIGITE 5 : Receber sangue" << std::endl;
    std::cout << "\t\tDIGITE 6 : Informacao dos pacientes agendados" << std::endl;
    std::cout << "\t\t";
    std::cin >> ans;
    //implementar as condicionais
    try{
        if(ans == 2){
            std::cout << "\t\tInsira os dados do paciente" << std::endl;
            std::cout << "\t\tSexo: ";
            std::cin >> genero;
            std::cin.ignore();
            std::cout << "\t\tNome: ";
            std::getline(std::cin, nome);
            std::cout << "\t\tCpf: ";
            std::cin >> cpf;
            std::cout << "\t\tTelefone: ";
            std::cin >> tel;
            std::cout << "\t\tConvenio: ";
            std::cin >> pl_saude;

            Paciente *_paciente = new Paciente(genero, nome, cpf, tel, pl_saude);
            _paciente->Marcar_Consulta();

            delete _paciente;
        }
        else if (ans == 3){

            std::cout << "\t\tInsira os dados do paciente que voce deseja excluir a consulta:" << std::endl;
            std::cout << "\t\tSexo: ";
            std::cin >> genero;
            std::cin.ignore();
            std::cout << "\t\tNome: ";
            std::getline(std::cin, nome);
            std::cout << "\t\tCpf: ";
            std::cin >> cpf;
            std::cout << "\t\tTelefone: ";
            std::cin >> tel;

            Paciente *_paciente = new Paciente(genero, nome, cpf, tel);  
            _paciente->Cancelar_Consulta();

            delete _paciente;
        }
    }
    catch(const char *e){
        std::cout << "erro: " << e << std::endl;
    }

}

void Administracao()
{
    int ans;
    std::cout << std::setw(30) << "\t\t---------------------------------------------------" << std::endl;

    std::cout << "\t\tDIGITE 1 : Informacoes sobre os medicos" << std::endl;
    std::cout << "\t\tDIGITE 2 : Alterar lista de medicos" << std::endl;
    std::cout << "\t\tDIGITE 3 : Informacoes sobre o banco de sangue" << std::endl;
    std::cout << "\t\tDIGITE 4 : Informacoes sobre os doadores/receptores de sangue" << std::endl;
    std::cout << "\t\t";
    std::cin >> ans;
    std::cout << std::endl;

    while (ans < 1 || ans > 4)
    {
        std::cout << "\t\tEntrada invalida. Digite novamente..." << std::endl;
        std::cout << "\t\t";
        std::cin >> ans;
    }
    //implementar condicionais para as outras classes
    try{
        if (ans == 3)
        {

            Banco_de_Sangue banco;
            banco.QuantidadeTipo();
            banco.QuantidadeTotal();
        }
        else if (ans == 4)
        {
            Banco_de_Sangue banco;
            banco.DadosBancoSangue();
        }
    }
    catch (const char *e){
        std::cout << "erro: " << e << std::endl;
    }
}
bool Senha(std::string *_senha)
{
    std::string senha;
    senha = "ufv";

    if (*_senha == senha)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    int ans;
    std::string senha;
    std::cout << std::setw(30) << "\t\t---------------------------------------------------";
    std::cout << std::setw(30) << "\n\t\t\tSISTEMA DE GERENCIAMENTO HOSPITALAR" << std::endl;
    std::cout << std::setw(30) << "\t\t---------------------------------------------------" << std::endl;

    std::cout << "\t\tDIGITE 1 : Ir para secao Secretaria" << std::endl;
    std::cout << "\t\tDIGITE 2 : Ir para a secao Administracao" << std::endl;
    std::cout << "\t\tDIGITE 3 : Sair" << std::endl;
    std::cout << "\t\t";
    std::cin >> ans;
    std::cout << std::endl;

    while (ans < 1 || ans > 3)
    {

        std::cout << "\t\tEntrada invalida. Digite novamente..." << std::endl;
        std::cout << "\t\t";
        std::cin >> ans;
    }
    if (ans == 1)
    {
        Secretaria();
    }
    else if (ans == 2)
    {

        std::cout << "\t\tDigite a senha:" << std::endl;
        std::cout << "\t\t";
        std::cin >> senha;

        if (Senha(&senha) == true)
        {

            std::cout << "\t\tAcesso permitido" << std::endl;
            Administracao();
        }
        else
        {

            std::cout << "\t\tAcesso negado" << std::endl;
            exit(1);
        }
    }
    else
    {
        exit(1);
    }

    

    return 0;
}