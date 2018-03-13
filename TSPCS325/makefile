CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -O3 

OBJS = main.o graphFileIO.o greedyOddMatching.o mstPrim.o vertex.o eulerTour.o

SRCS = main.cpp graphFileIO.cpp greedyOddMatching.cpp mstPrim.cpp vertex.cpp eulerTour.cpp

HEADERS = graphFileIO.h greedyOddMatching.h mstPrim.h vertex.h eulerTour.h

main: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJ}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o main