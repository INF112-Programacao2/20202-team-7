#ifndef PACIENTE_H
#define PACIENTE_H
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



#endif