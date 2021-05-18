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
- O metodo Médicos, deverá inserir os seguintes dados: Gênero, Nome, CPF, Telefone, CRM, Especialização e por fim Horários (entrada e saída respectivamente). Como representado pelo construtor:
```c++
Medico::Medico(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, const std::string &crm, std::string especializacao, int horario_entrada, int horario_saida):
    Pessoas(genero, nome, cpf, telefone), _crm(crm), _especializacao(especializacao), hora_entrada(horario_entrada), hora_saida(horario_saida){}
```
- Esses construtor deriva do arquivo ```Medico.h``` onde lá estão instanciadas as variáveis:
```c++
#include "Pessoas.h"

/* Criação da classe Médico, responsavel pelas funções previamente definidas no CRC, tais quais o registro e especificações referentes a equipe médica.
*/
class Medico: public Pessoas{
    private:
    std::string nome_med;
    std::string _especializacao;
    std::string _crm;
    int hora_entrada, hora_saida;
    /*Especificação dos atributos referentes unicamente à classe Medico.*/
    
    public:
    Medico(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, const std::string &crm, std::string especializacao, int hora_entrada, int hora_saida);
    /*Construtor que receberá dados da Classe pessoa e também da classe Médico.*/
    void horario_atendimento();
    virtual void exibirDados() override;
    void Mudar_Registro();
    std::string getnome_med() const; /* Função responsável por receber o nome do Médico.*/
    std::string get_especializacao();  /* Função responsável por receber a especializacao do Médico.*/
    std::string get_crm() const;/* Função responsável por receber o CRM (numero de inscrição no Conselho Regional de Medicina) do Médico.*/
    int get_horarioentrada(); /* Função responsável por receber o horario de entrada do Médico no hospital.*/
    int get_horariosaida(); /* Função responsável por receber o horario de saida do Médico no hospital.*/
};
```
- Como bem comentado, as funções estão bem definidas dentro do ```.h```, onde os atributos private só podem ser utilizados na classe ```Medicos.cpp```. E em public estão as funções que serão utilizadas no arquivo ```Medico.cpp``
- Abaixo estão os métodos utilizados para as funções, por primeiro temos o horario de atendimento, função utilizada para delimitar o horario de entrada e saida do hospital.
```c++
/*Função que receberá o horario de saida do Médico.*/
void Medico::horario_atendimento(){

    std::ifstream hor; /* Arquivo do qual sera retirado os horarios de atendimento da equipe médica.*/
    std::string nome, especializacao;
    int hora_entrada, hora_saida;

    hor.open("horario.txt"); /*Abertura do arquivo.*/

    if(!hor.is_open()){
        throw "Arquivo inexistente.";  /*Tratamento de exceção caso não ocorra a abertura correta do arquivo.*/
    }

    std::cout << "\t\t" << std::right << "NOME:" << std::setw(30) << "ESPECIALIZACAO:" << std::setw(17) << "HORARIOS:" << std::endl;
    while(!hor.eof()){

        std::getline(hor, nome, ',');

        std::getline(hor, especializacao, ',');

        hor >> hora_entrada;
        hor.ignore();

        hor >> hora_saida;
        hor.ignore();
        /*leitura dos referidos dados do médico, tais quais nome, especialização, horario entrada e saida.*/

    std::cout << "\t\t" << std::left << std::setw(20) << nome <<std::setw(23) << especializacao << std::left << hora_entrada << "-" << hora_saida << std::endl;
    hor.ignore();

    }   
    hor.close(); /*Fechamento do arquivo.*/
}
```
- Como comentado dentro da funções está explicitado qual é a utlização de cada linha ou conjunto de variavéis.
- O método ainda tem presente a função mudar horario, na qual acessa o arquivo ````medicos.txt``` e altera essas informções.
```c++
void Medico::exibirDados(){
    /*Função responsável por exibir os dados adquiridos via abertura do arquivo na função anterior.*/
    
    std::ifstream med;
    std::string genero, nome, cpf, tel, crm, especializacao;
    int hora_entrada, hora_saida;

    med.open("medicos.txt");

    if(!med.is_open()){
        throw "Arquivo inexistente."; /*Tratamento de exceção caso não ocorra a abertura correta do arquivo.*/
    }

    std::cout << "\t\t" << std::right << "SEXO:" << std::setw(7) << "NOME:" << std::setw(24) << "TELEFONE:" << std::setw(7) << "CRM:" << std::setw(12) << "CPF:" << std::setw(29) << "ESPECIALIZACAO:" << std::setw(13) << "HORARIOS:" << std::endl;
    while(!med.eof()){

        std::getline(med, genero, ',');

        std::getline(med, nome, ',');

        std::getline(med, crm, ',');

        std::getline(med, cpf, ',');

        std::getline(med, tel, ',');

        std::getline(med, especializacao, ',');

        med >> hora_entrada;
        med.ignore();

        med >> hora_saida;
        med.ignore();

    
    std::cout << "\t\t" << std::left << std::setw(7) << genero << std::setw(20) << nome <<std::setw(12) << cpf << std::setw(12) << tel << std::setw(18) << crm << std::setw(19) << especializacao << hora_entrada << "-" << hora_saida << std::endl;
    /*Impressão dos dados adquiridos mediante metodos pre-estabelecidos.*/
    med.ignore();

    }

    med.close(); /* Fechamento do arquivo.*/
}
```
- Ainda presente na classe Medicos, temos a mudança de horario e de registro, na qual o horario altera somente o horario e o registro muda mais informações como sexo, CPF, Nome e outros:
```c++
void Medico::Mudar_Registro(){
   /* Função responsável por alterar os registro de um médico, seguindo a respectiva ordem: genero(M ou F), Nome, CPF, CRM, Telefone, Especialização, horarios de entrada e saida.*/
    std::ofstream med; 
    
    med.open("medicos.txt", std::ios::app);    

    if(!med.is_open()){
       throw "Arquivo inexistente.";
    }


    med << get_genero() << "," << get_nome() << "," << get_cpf() << ", " << get_crm() << "," << get_telefone() << "," << get_especializacao() << "," << get_horarioentrada() << "," << get_horariosaida() << "," << std::endl;
    med.close(); /* Fechamento do arquivo.*/
}

void Medico::Mudar_Horario(){
   /* Função responsável por alterar os horários dos médicos, seguindo a respectiva ordem: Nome, Especialização, horarios de entrada e saida.*/
    std::ofstream med_novo; 
    med_novo.open("horario.txt", std::ios::app);

     if(!med_novo.is_open()){
       throw "Arquivo inexistente.";
    }

    med_novo << get_nome() << "," << get_especializacao() << "," << get_horarioentrada() << "," << get_horariosaida() << "," << std::endl;
    med_novo.close();/* Fechamento do arquivo.*/

}
```

## Banco de Sangue
- O usuário que for inserir os dados a respeito da inserção de bolsas sanguíneas, deverá preencher dados a respeito do Gênero, Nome, CPF, Convenio, Tipo Sanguíneo e quantidade doada e armazenada na bolsa.
- Na área do banco de sangue poderá visualizar a quantidade disponível e poderá também alterar a quantidade.
