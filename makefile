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
