# Documentação



## Iniciando o programa para Gerenciamento de Hospital

-  Para executar o programa abra o arquivo HospitalManagement.exe 
-  Logo após a inicialização, o usuário deverá escolher uma opção de acordo com o menu apresentado de forma numerica.
-  Em seguida irá apresentar a opção escolhida. 

## Pessoas
- Nesta classe tem como construtor as informações referentes ao paciente, horario e qual especialidade queira marcar.
```c++
Pessoas::Pessoas(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone):
    _genero (genero), _nome(nome), _cpf (cpf), _telefone(telefone) {}
``` 
- Essa classe será utilizada em todas dependencias dos arquivos (classes) ´.cpp`, pois ela é a classe hieraquica maior.
- O construtor acima é responsavel por instanciar todas as váriaveis. Como pode ser observado no .h abaixo:
```c++
class Pessoas{
    protected:
        std::string _nome;
        std::string _cpf;
        std::string _telefone;
        char _genero;

    public:
        Pessoas(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone);
        virtual void exibirDados() = 0;
        std::string get_nome() const;
        std::string get_cpf() const;
        std::string get_telefone();
        char get_genero() const;
        
};
```
- Acima você tem as váriveis protected, que serão as variaveis que não podem ser alteradas em outras funções. Por elas serem as informações básicas dos pacientes.

```c++
std::string Pessoas::get_nome() const{
    return this->_nome;
}

std::string Pessoas::get_cpf() const{
    return this->_cpf;
}

std::string Pessoas::get_telefone(){
    return this->_telefone;
}

char Pessoas::get_genero() const{
    return this->_genero;
}
``` 
- Essas funções são responsáveis por apontar para qual variavel devemos armazenar essas informações. Por isso do atributo get. 

## Pacientes/Consultas
- Nesta classe o usuário devera inserir os dados do paciente, como: Nome, CPF, Gênero, Telefone, Convênio:
```c++
Paciente::Paciente(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, std::string planosaude):
    Pessoas(genero, nome, cpf, telefone),_planosaude(planosaude){}
    //construtor da classe paciente.

std::string Paciente::get_planosaude(){
    return this->_planosaude; //armazena o plano de saude dentro da váriavel global
}
```
- Pode-se perceber que abaixo do chamado da classe Paciente, temos chamado também a classe Pessoas, na qual estarão todas as informações salvas a respeito do paciente.
- Esse construtor deriva das variaveis do arquivo .h, que está representado abaixo:
```c++
#include "Pessoas.h"

/* Criação da classe Paciente, responsavel pelas funções previamente definidas no CRC, tais quais o marcação de consulta, verificação de plano e regisstro do paciênte.
*/

class Paciente : public Pessoas
{
private:
    std::string _planosaude;
    /*Especificação dos atributos referentes unicamente à classe Paciente.*/

public:

     /*Construtor que receberá dados da Classe pessoa e também da classe Paciente.*/
    Paciente(const char &genero, const std::string &_nome, const std::string &cpf, const std::string telefone, std::string planosaude);
    
    void exibirDados(); // exibirá os dados referente ao paciente escolhido
    void Marcar_Consulta(); // responsável por agendar a consulta de acordo com o horairo.
    void Cancelar_Consulta(); // responsavel por desmarcar a consulta.
    std::string get_planosaude();  //responsavel somente por armazanar o plano de saude.
   
};
```
- Como visto acima há o chamamento da biblioteca ```Pessoas.h```, pois nela sera armazenada essas informações, como nome, cpf, telefone e outros.
- A função abaixo é responsável por exibir os dados salvos até então presentes no arquivo ```paciente.txt```, como está comentado. 
- Enquanto não houver o fim do arquivo o codigo abaixo não parará de executar, onde pode ser visto em ```while(!pac.eof()) ``` 
```c++
void Paciente::exibirDados(){
    
    std::ifstream pac;   //ponteiro para abertura e leitura de arquivo.
    std::string genero, nome, cpf, tel, pl_saude; //strings utilizadas para armazenar as informações na memoria volatil. 
    pac.open("paciente.txt");  //abertura do arquivo.

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

    pac.close(); //fecha o arquivo

}
```
- No próximo método da classe tem a função de preencher o horario e especialização a qual deseja: 
```c++
void Paciente::Marcar_Consulta(){
    
    std::ofstream pac; //abertura e escrita do arquvio.
    
    pac.open("paciente.txt", std::ios::app);    //abrindo o arquivo na ultima posição para poder continuar a escrita e não apagar ele por completo.
    
    if(!pac.is_open()){
       throw "Arquivo inexistente."; //caso o arquivo não existe
    }
   
    pac << get_genero() << "," << get_nome() << "," << get_cpf()  << "," << get_telefone() << "," << get_planosaude() << "," << std::endl;  //inserção de informações no arquivo.
   
    pac.close(); //fecha o arquivo e salva
}
```

## Medicos
- O usuário responsavel pela administração do Hospital, deverá inserir os seguintes dados: Gênero, Nome, CPF, Telefone, CRM, Especialização e por fim Horários (entrada e saída respectivamente). 

## Banco de Sangue
- O usuário que for inserir os dados a respeito da inserção de bolsas sanguíneas, deverá preencher dados a respeito do Gênero, Nome, CPF, Convenio, Tipo Sanguíneo e quantidade doada e armazenada na bolsa.
- Na área do banco de sangue poderá visualizar a quantidade disponível e poderá também alterar a quantidade.
