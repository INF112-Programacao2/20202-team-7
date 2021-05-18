#ifndef BANCO_DE_SANGUE_H
#define BANCO_DE_SANGUE_H

    /* Classe responável para emitir os dados sobre o banco de sangue do hospital, como
    quantidade de sangue total, quantidade de cada tipo e as informações sobre os
    doadores e receptores
    */
class Banco_de_Sangue
{
public:
    // Método que informa os dados dos doadores e receptores de sangue 
    void DadosBancoSangue();

    // Método que informa a quantidade total de sangue do hospital
    void QuantidadeTotal();

    //Método que informa a quantidade de cada tipo de sangue do hospital (A,AB,B ou O)
    void QuantidadeTipo();
    
    
};

#endif
