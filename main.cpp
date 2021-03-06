#include <iostream>
#include <iomanip>
#include "Banco_de_Sangue.h"
#include "Pessoas.h"
#include "Paciente.h"
#include "Medico.h"
#include "Doador_Receptor.h"

void Secretaria()
{

    char genero, r;
    std::string nome, cpf, tel, pl_saude, tipo_sangue, crm, especilizacao;
    int ans, qtd_sangue, horario_entrada, horario_saida;
    bool sangue;
    std::cout << std::setw(30) << "\t\t---------------------------------------------------" << std::endl;

    std::cout << "\t\tDIGITE 1 : Horario de atendimento dos medicos" << std::endl;
    std::cout << "\t\tDIGITE 2 : Agendar consulta" << std::endl;
    std::cout << "\t\tDIGITE 3 : Doar sangue" << std::endl;
    std::cout << "\t\tDIGITE 4 : Receber sangue" << std::endl;
    std::cout << "\t\tDIGITE 5 : Informacao dos pacientes agendados" << std::endl;
    std::cout << "\t\tEntrada:";
    std::cin >> ans;

  while (ans < 1 || ans > 5)
    {
        
        std::cout << "\t\tEntrada invalida. Digite novamente..." << std::endl;
        std::cout << "\t\tEntrada:";
        std::cin >> ans;
    }
    
    try{
        if(ans == 1){
            
            genero = 'c';
            nome = "default";
            cpf = "default";
            tel = "default";
            especilizacao = "default";
            pl_saude = "default";
            tipo_sangue = "default";
            
            Medico *med = new Medico(genero, nome, cpf, tel, crm, especilizacao, 0, 0);
            med->horario_atendimento();

            delete med;

        }
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
        else if(ans == 3){

            std::cout << "\t\tInsira os dados do doador" << std::endl;
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
            std::cout << "\t\tTipo sanguineo: ";
            std::cin >> tipo_sangue;
        
            while(tipo_sangue != "AB" && tipo_sangue != "A" && tipo_sangue != "B" && tipo_sangue != "O"){
                std::cout << "Tipo sanguineo invalido. Digite novamente..." << std::endl;
                std::cin >> tipo_sangue;
              
            }

            std::cout << "\t\tQuantidade de sangue doada (valores entre 420mL e 470mL): ";
            std::cin >> qtd_sangue; 

            Doador_Receptor *doador = new Doador_Receptor(genero, nome, cpf, tel, pl_saude, tipo_sangue, qtd_sangue);
            doador->Adicionar_sangue();

            delete doador;

        }
        else if(ans == 4){

            std::cout << "\t\tInsira os dados do receptor" << std::endl;
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
            std::cout << "\t\tTipo sanguineo: ";
            std::cin >> tipo_sangue;
            std::cout << "\t\tQuantidade de sangue para ser recebida: ";
            std::cin >> qtd_sangue; 

            Doador_Receptor *receptor = new Doador_Receptor(genero, nome, cpf, tel, pl_saude, tipo_sangue, qtd_sangue);
            receptor->Retirar_sangue();

            delete receptor;

        }
        else if ( ans == 5){

            genero = 'c';
            nome = "default";
            cpf = "default";
            tel = "default";
            pl_saude = "default";

            Paciente *pac = new Paciente(genero, nome, cpf, tel, pl_saude);
            pac->exibirDados();

            delete pac;  
    
        }
    }
    catch(const char *e){
        std::cout << "erro: " << e << std::endl;
        }
    }

void Administracao()
{

    char genero, t, r;
    std::string nome, cpf, tel, crm, especializacao;
    int x, y;
    int ans;
    std::cout << std::setw(30) << "\t\t---------------------------------------------------" << std::endl;

    std::cout << "\t\tDIGITE 1 : Informacoes sobre os medicos" << std::endl;
    std::cout << "\t\tDIGITE 2 : Alterar registro de medicos" << std::endl;
    std::cout << "\t\tDIGITE 3 : Informacoes sobre o banco de sangue" << std::endl;
    std::cout << "\t\tDIGITE 4 : Informacoes sobre os doadores/receptores de sangue" << std::endl;
    std::cout << "\t\tEntrada:";
    std::cin >> ans;
    std::cout << std::endl;

    while (ans < 1 || ans > 4)
    {
        std::cout << "\t\tEntrada invalida. Digite novamente..." << std::endl;
        std::cout << "\t\tEntrada:";
        std::cin >> ans;
    }

    try{

        if(ans == 1){

            genero = 'c';
            nome = "default";
            cpf = "default";
            tel = "default";
            crm = "default";
            especializacao = "default";
            x = 0, y = 0;

            Medico *med = new Medico(genero, nome, cpf, tel, crm, especializacao, x, y);
            med->exibirDados();

            delete med;
    
        }
        else if(ans == 2){

            std::cout << "\t\tInsira os dados do medico que deseja adicionar" << std::endl;
            std::cout << "\t\tSexo: ";
            std::cin >> genero;
            std::cin.ignore();
            std::cout << "\t\tNome: ";
            std::getline(std::cin, nome);
            std::cout << "\t\tCPF: ";
            std::cin >> cpf;
            std::cout << "\t\tCRM: ";
            std::cin >> tel;
            std::cout << "\t\tTelefone: ";
            std::cin >> crm;
            std::cout << "\t\tEspecializacao: ";
            std::cin >> especializacao;
            std::cout << "\t\tHorarios de atendimento: ";
            std::cin >> x >> t >> y;

            Medico *med = new Medico(genero, nome, cpf, tel, crm, especializacao, x, y);
            med->Mudar_Registro();
            med->Mudar_Horario();

            delete med;
          
        }       
        else if (ans == 3)
        {

            Banco_de_Sangue banco;
            banco.QuantidadeTipo();
            banco.QuantidadeTotal();

        }
        else if ( ans == 4)
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

    char r;
    while(r != 's'){

    int ans;
    std::string senha;
    std::cout << std::setw(30) << "\t\t---------------------------------------------------";
    std::cout << std::setw(30) << "\n\t\t\tSISTEMA DE GERENCIAMENTO HOSPITALAR" << std::endl;
    std::cout << std::setw(30) << "\t\t---------------------------------------------------" << std::endl;

    std::cout << "\t\tDIGITE 1 : Ir para secao Secretaria" << std::endl;
    std::cout << "\t\tDIGITE 2 : Ir para a secao Administracao" << std::endl;
    std::cout << "\t\tDIGITE 3 : Sair" << std::endl;
    std::cout << "\t\tEntrada:";
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
        std::cout<<"\t\tSair? (s/n)" << std::endl;
        std::cout << "\t\tEntrada:";
        std::cin >> r;
    }
    else if (ans == 2)
    {

        std::cout << "\t\tDigite a senha:" << std::endl;
        std::cout << "\t\tEntrada:";
        std::cin >> senha;

        if (Senha(&senha) == true)
        {

            std::cout << "\t\tAcesso permitido" << std::endl;
            Administracao();
        }
        else
        {   
            while(Senha(&senha) != true){
                std::cout << "\t\tAcesso negado. Digite novamente..." << std::endl;
                std::cout << "\t\tEntrada:";
                std::cin >> senha;
            }
            Administracao();
     
        }
        std::cout<<"\t\tSair? (s/n)" << std::endl;
        std::cout << "\t\tEntrada:";
        std::cin >> r;
    }
    else
    {
        exit(1);
    }
}
    return 0;
}