#include "Banco_de_Sangue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void Banco_de_Sangue::DadosBancoSangue(){

    std::string nome,tipo_recptor,tipo_doador,sobrenome,_nome,_sobrenome;
    std::ifstream doa, rec;
    int x,y;

    doa.open("doadores.txt");

    // exceção
    if(!doa.is_open()){
        std::cout <<"Arquivo inexistente."<<std::endl; 
        exit(1);
    }
    std::cout <<std::setw(7)<<"Nro.:"<<std::setw(10)<<"TIPO:"<<std::setw(16)<<"DOADORES:"<<std::endl;

   while(!doa.eof()){

       doa>>x;
       doa.ignore();


       std::getline(doa, tipo_doador, ',');
   
   
       doa>>nome;
       std::getline(doa, sobrenome, ',');
      
  
      std::cout<<std::setw(5)<<x<<std::setw(10)<<tipo_doador<<std::setw(12)<<nome<<std::setw(10)<<sobrenome<<std::endl;
      doa.ignore();
   }
   doa.close();
   std::cout <<std::endl;

   rec.open("receptores.txt");

    if(!rec.is_open()){
        std::cout <<"Arquivo inexistente."<<std::endl; 
        exit(1);
    }
    std::cout <<std::setw(7)<<"Nro.:"<<std::setw(10)<<"TIPO:"<<std::setw(16)<<"RECEPTORES:"<<std::endl;

    while(!rec.eof()){

       rec>>y;
       rec.ignore();


       std::getline(rec, tipo_recptor, ',');
      

       rec>>_nome;
       std::getline(rec, _sobrenome, ',');
        
  
      std::cout<<std::setw(5)<<y<<std::setw(10)<<tipo_recptor<<std::setw(12)<<_nome<<std::setw(10)<<_sobrenome<<std::endl;
      rec.ignore();
   }
    rec.close();
    std::cout<<std::endl;
  
}

void Banco_de_Sangue::QuantidadeTotal(){

   std::ifstream tip;
   std::string tipo;
   int i=0, qtd_sangue, qtd_total[i], qtd_final =0;
   tip.open("tipagem.txt");

    // exceção
    if(!tip.is_open()){
       std::cout<<"Arquivo inexistente."<<std::endl; 
       exit(1);
   }

   while(!tip.eof()){
       tip>>qtd_sangue;
       tip.ignore();

        std::getline(tip, tipo, ',');
        qtd_total[i] =qtd_sangue;
        i++;
       
   }

   for(int j=0; j<i-1; j++){
       qtd_final+= qtd_total[j];
   }
    std::cout <<std::setw(6)<<"QUANTIDADE TOTAL DE SANGUE: "<< qtd_final <<" mL"<< std::endl;
    std::cout<<std::endl;
    
    tip.close();
       
}

void Banco_de_Sangue::QuantidadeTipo(){
    
   std::ifstream tip;
   std::string tipo;
   int i=0,qtd;
   tip.open("tipagem.txt");

    // exceção
   if(!tip.is_open()){
       std::cout<<"Arquivo inexistente."<<std::endl; 
   }
   std::cout <<std::setw(6)<<"QUANTIDADE:"<<std::setw(14)<<"TIPO:"<<std::endl;

    // 4 tipos de sangue
   while(i!=4){
       tip>>qtd;
       tip.ignore();

        std::getline(tip, tipo, ',');

         std::cout<<std::setw(5)<<qtd<<" mL"<<std::setw(15)<<tipo<<std::endl;
    i++;
   }
   std::cout<<std::endl;

   tip.close();
}