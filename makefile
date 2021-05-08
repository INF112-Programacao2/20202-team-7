all: make

make: Paciente.o Doador_Receptor.o Banco_de_sangue.o Medico.o Pessoas.o
	g++ Paciente.o Doador_Receptor.o Banco_de_sangue.o Medico.o Pessoas.o

Paciente.o: Paciente.cpp
	g++ -c Paciente.cpp

Doador_Receptor.o: Doador_Receptor.cpp
	g++ -c Doador_Receptor.cpp

Banco_de_sangue.o: Banco_de_sangue.cpp
	g++ -c Banco_de_sangue.cpp

Medico.o: Medico.cpp
	g++ -c Medico.cpp

Pessoas.o: Pessoas.cpp
	g++ -c Pessoas.cpp
clean:
	rm -rf *o make
