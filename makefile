all:
	g++ -o main parameters.h GenerateData.cpp kNN.cpp  main.cpp 

clean:
	rm main
