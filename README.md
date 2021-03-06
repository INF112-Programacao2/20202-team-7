# Sistema de Gerenciamento de Hospital

## Objetivo:

O trabalho possui como objetivo a criação de um sistema que auxilia na gerência de um hospital, utilizando dos 4 pilares principais da POO: 

1. Abstração
2. Encapsulamento
3. Herança
4. Polimorfismo

O sistema será focado em auxiliar a secretária de um hospital, marcando/cancelando consultas para pacientes, saber os dados dos pacientes, saber o horário dos médicos e com a o setor de doação/uso de sangue do hospital. 

Além disso, também irá auxiliar o setor administrativo do hospital com os dados dos médicos que ali trabalham, com o manejo dos médicos, com os dados do banco de sangue e dos pacientes que doaram ou receberam sangue.

## Execução Do Programa

Para facilitar a execução do programa, utilizaremos do makefile para executar

### MakeFile
- A utilização do makefile tem como objetivo automatizar a execução. Na necessidade de evitar a digitação de vários parametros na hora da execução.
- Desta forma o usuário só necessita utilizar o nome make, na hora de executar que este iniciará a execução.

## Usuários:

- Secretária do Hospital
- Administração do Hospital

## User stories:

### Secretária:

- Como secretária de um hospital eu quero saber quais são os horários dos médicos que ali trabalham para saber quando poderei marcar a consulta de meu paciente
- Como secretária de um hospital eu quero marcar uma consulta para o paciente
- Como secretária de um hospital eu quero marcar para um paciente poder doar ou receber sangue
- Como secretária de um hospital eu quero poder consultar os dados de um determinado paciente já cadastrado para poder entrar em informação com ele caso precise

### Administração:

- Como administrador quero consultar os dados dos médicos que trabalham no hospital
- Como administrador quero alterar os médicos para um melhor manejo do hospital
- Como administrador quero saber qual a situação do nosso banco de sangue para saber a situação do hospital quanto a esse recurso
- Como administrador quero saber o perfil dos doadores/receptores , sabendo quanto foi doado ou retirado e qual o tipo sanguíneo, para um melhor manejo do banco de sangue

## CRC:

![Figura 1](/Images/CRC.jpeg)
