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
- Como bem comentado, as funções estão bem definidas dentro do ```.h```, onde os atributos private só podem ser utilizados na classe ```Medicos.cpp```. E em public estão as funções que serão utilizadas no arquivo ```Medico.cpp```
- Abaixo estão os métodos utilizados para as funções, por primeiro temos o horario de atendimento, função utilizada para delimitar o horario de entrada e saida do hospital.
```c++
/*Função que receberá o horario de saida do Médico.*/
void Medico::horario_atendimento(){

    std::ifstream hor; /* Arquivo do qual sera retirado os horarios de atendimento da equipe médica.*/
    std::string nome, especializaca o;
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
- O método ainda tem presente a função mudar horario, na qual acessa o arquivo ```medicos.txt``` e altera essas informções.
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
- A função da instância Banco de Sangue é responsável por absorver todas as informações dos pacientes, que está na instância Pessoas, ou seja, as informações passam por instâncias superiores para gravar as informações.
```c++
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
``` 
- Essa função acima é capaz de tabelar a quantidade de sangue disponivel, do individuo que está fazendo a doação e correlacionar com quem está precisando de receber, ou seja, conecta as duas informações.

```c++
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

    
    int sangue[4];
    int cont = 0;
    std::string::size_type sz;
    std::string palavra;

    // irá ler o arquivo e pegar os números, além de registar esses valores em uma variável
    while (!arquivo_saida.eof())
    {
        std::getline(arquivo_saida,palavra);

        sangue[cont] = std::stoi(palavra,&sz,10);
        cont++;
        
   }

  
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
    gravar_informacoes << "\n"<< get_genero() << "," << get_nome() << ","  << get_cpf() << "," << get_telefone() << "," << get_planosaude() << "," << get_tipo_sanguineo() << "," << get_quantidade_de_sangue() << "," << std::endl;
    
    // fechando todos os arquivos que foram abertos durante a execução do programa
    gravar_informacoes.close();
    arquivo_saida.close();
    arquivo_receptor.close();
} 

/*
    Essa função irá fazer a modificação nos arquivos referentes a quantidade de cada tipo de sangue e de registro de receptores
    Irá pegar a quantidade de sangue que tem já registrado de cada tipo sanguíneo e irá retirar, se for possível,
    sangue no tipo sanguíneo  referente ao do receptor, e também, irá fazer registro dos dados desse receptor

*/
```
- A função acima tem como objetivo somar a quantidade de sangue disponível, conforme for carregando dados nela.

```c++

void Doador_Receptor::Retirar_sangue(){
    
    // arquivo que irá pegar os valores de cada tipo de sangue
    std::ifstream arquivo_saida;
    // arquivo que irá registrar os novos valores de cada tipo de sangue
    std::ofstream arquivo_receptor;

    arquivo_saida.open("tipagem.txt");
    arquivo_receptor.open("tipagem.txt");

    // tratamento de exceção pra caso o arquivo não abra
    if (!arquivo_saida.is_open())
    {
        throw "Arquivo inexistente";
    }
     if (!arquivo_receptor.is_open())
    {
        throw "Arquivo inexistente";
    }
    
    int sangue[4];
    int cont = 0;
    std::string::size_type sz;
    std::string palavra;

    // irá ler o arquivo e pegar os números, além de registar esses valores em uma variável
    while (!arquivo_saida.eof())
    {
        std::getline(arquivo_saida,palavra);

        sangue[cont] = std::stoi(palavra,&sz,10);
        cont++;
        
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
   
    // registrando os valores antigos e oque foi modificado novamente no arquivo
    arquivo_receptor << sangue[0] <<",AB,"<<std::endl;
    arquivo_receptor << sangue [1] <<",A,"<<std::endl;
    arquivo_receptor << sangue[2] <<",B,"<<std::endl;
    arquivo_receptor << sangue[3] <<",O,"<<std::endl;    
 

    // gravar as informações do receptor de sangue
    std::ofstream gravar_informacoes;

    gravar_informacoes.open("doadores.txt",std::ios::app);

    if (!gravar_informacoes.is_open())
    {
        throw "Arquivo inexistente";
    }

    gravar_informacoes <<"\n"<< get_genero() << "," << get_nome() << ","  << get_cpf() << "," << get_telefone() << "," << get_planosaude() << "," << get_tipo_sanguineo() << "," << get_quantidade_de_sangue() << "," << std::endl;
    
    //fechamento dos arquivos 
    gravar_informacoes.close();
    arquivo_saida.close();
    arquivo_receptor.close();

} 
```
- A função acima propõe o oposto da ```Adicionar_Sangue```, na qual ela retira a quantidade de sangue do estoque, dependendo da necessidade do hospital.

## MakeFile
- A utilização do makefile tem como objetivo automatizar a execução. Na necessidade de evitar a digitação de vários parametros na hora da execução.
```make
all: make
	./Executar

make: main.o Paciente.o Doador_Receptor.o Banco_de_sangue.o Medico.o Pessoas.o
	g++ main.o Paciente.o Doador_Receptor.o Banco_de_sangue.o Medico.o Pessoas.o -o Executar
	
main.o: main.cpp
	g++ -c main.cpp

Paciente.o: Paciente.cpp Paciente.h
	g++ -c Paciente.cpp

Doador_Receptor.o: Doador_Receptor.cpp Doador_Receptor.h
	g++ -c Doador_Receptor.cpp

Banco_de_sangue.o: Banco_de_sangue.cpp Banco_de_Sangue.h
	g++ -c Banco_de_sangue.cpp

Medico.o: Medico.cpp Medico.h
	g++ -c Medico.cpp

Pessoas.o: Pessoas.cpp Pessoas.h
	g++ -c Pessoas.cpp

clean:
	rm -rf *o make
```

- O codigo acima mostra como foi feito o make, utilizamos arquivos ``.o`` para unir o ``.cpp``, ao arquivo ``.h``. 
- Desta forma o usuário só necessita utilizar o nome make, na hora de executar que este iniciará a execução.



