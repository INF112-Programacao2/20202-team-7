#include <iostream>
#include "Banco_de_Sangue.h"
#include "Medico.h"

int main(){

    Banco_de_Sangue sangue;
    sangue.DadosBancoSangue();
    sangue.QuantidadeTipo();
    sangue.QuantidadeTotal();

    return 0;
}