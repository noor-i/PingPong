CXX = g++
CXXFLAGS = -std=c++11
LIB = -lraylib

play: main.o Ball.o Screen.o Paddle.o PaddleCPU.o
	$(CXX) $(CXXFLAGS) $(LIB) main.o Ball.o Screen.o Paddle.o PaddleCPU.o -o play

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Ball.o: Ball.cpp Ball.h
	$(CXX) $(CXXFLAGS) -c Ball.cpp

Screen.o: Screen.cpp Screen.h
	$(CXX) $(CXXFLAGS) -c Screen.cpp

Paddle.o: Paddle.cpp Paddle.h
	$(CXX) $(CXXFLAGS) -c Paddle.cpp

PaddleCPU.o: PaddleCPU.cpp PaddleCPU.h
	$(CXX) $(CXXFLAGS) -c PaddleCPU.cpp

clean:
	rm -f *.o play
