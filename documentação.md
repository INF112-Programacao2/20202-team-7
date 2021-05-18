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
- Essa classe será utilizada em todas dependencias dos arquivos, pois ela é a classe hieraquica maior.
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
- Nesta classe o usuário devera inserir os dados do paciente, como: Nome, CPF, Gênero, Telefone, Convênio.
```c++
Paciente::Paciente(const char &genero, const std::string &nome, const std::string &cpf, std::string telefone, std::string planosaude):
    Pessoas(genero, nome, cpf, telefone),_planosaude(planosaude){}
    //construtor da classe paciente.

std::string Paciente::get_planosaude(){
    return this->_planosaude; //armazena o plano de saude dentro da váriavel global
}
```
- Pode-se perceber que abaixo do chamado da classe paciente, temos chamado também a Classe Pessoas, na qual estarão todas as informações salvas a respeito do paciente.


- No próximo passo o usuário deverá preencher o horario e especialização a qual deseja.
- Caso deseja desmarcar uma consulta, esta deverá preencher novamente os dados do paciente, juntamente com os dados do médico.

## Medicos
- O usuário responsavel pela administração do Hospital, deverá inserir os seguintes dados: Gênero, Nome, CPF, Telefone, CRM, Especialização e por fim Horários (entrada e saída respectivamente). 

## Banco de Sangue
- O usuário que for inserir os dados a respeito da inserção de bolsas sanguíneas, deverá preencher dados a respeito do Gênero, Nome, CPF, Convenio, Tipo Sanguíneo e quantidade doada e armazenada na bolsa.
- Na área do banco de sangue poderá visualizar a quantidade disponível e poderá também alterar a quantidade.
