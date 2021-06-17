TRGDIR=./
OBJ=./obj
CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -I inc
LIBS= -lglut -lGLU -lGL

__start__: ${TRGDIR}dron.out
	${TRGDIR}dron.out

${OBJ}:
	mkdir ${OBJ}

${TRGDIR}dron.out: ${OBJ} ${OBJ}/main.o ${OBJ}/OpenGL_API.o ${OBJ}/Uklad.o \
			${OBJ}/Kostka.o ${OBJ}/Graniastoslup.o ${OBJ}/Dron.o ${OBJ}/Plaska_powierzchnia.o ${OBJ}/Plaskowyz.o ${OBJ}/Wzgorze.o \
			${OBJ}/Plaskowyz_prostopadloscienny.o ${OBJ}/Scena.o
	g++ -o ${TRGDIR}dron.out ${OBJ}/main.o ${OBJ}/OpenGL_API.o ${OBJ}/Uklad.o \
			${OBJ}/Kostka.o ${OBJ}/Graniastoslup.o ${OBJ}/Dron.o ${OBJ}/Plaska_powierzchnia.o ${OBJ}/Plaskowyz.o ${OBJ}/Wzgorze.o \
			${OBJ}/Plaskowyz_prostopadloscienny.o ${OBJ}/Scena.o ${LIBS} -lpthread

${OBJ}/main.o: src/main.cpp inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/OpenGL_API.o: src/OpenGL_API.cpp inc/OpenGL_API.hh
	g++ ${CPPFLAGS} -o ${OBJ}/OpenGL_API.o src/OpenGL_API.cpp

inc/OpenGL_API.hh: inc/Draw3D_api_interface.hh
	touch inc/OpenGL_API.hh

${OBJ}/Uklad.o: src/Uklad.cpp inc/Uklad.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Uklad.o src/Uklad.cpp

${OBJ}/Kostka.o: src/Kostka.cpp inc/Kostka.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Kostka.o src/Kostka.cpp

${OBJ}/Graniastoslup.o: src/Graniastoslup.cpp inc/Graniastoslup.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Graniastoslup.o src/Graniastoslup.cpp

${OBJ}/Dron.o: src/Dron.cpp inc/Dron.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dron.o src/Dron.cpp

${OBJ}/Plaska_powierzchnia.o: src/Plaska_powierzchnia.cpp inc/Plaska_powierzchnia.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Plaska_powierzchnia.o src/Plaska_powierzchnia.cpp

${OBJ}/Plaskowyz.o: src/Plaskowyz.cpp inc/Plaskowyz.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Plaskowyz.o src/Plaskowyz.cpp

${OBJ}/Wzgorze.o: src/Wzgorze.cpp inc/Wzgorze.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Wzgorze.o src/Wzgorze.cpp

${OBJ}/Plaskowyz_prostopadloscienny.o: src/Plaskowyz_prostopadloscienny.cpp inc/Plaskowyz_prostopadloscienny.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Plaskowyz_prostopadloscienny.o src/Plaskowyz_prostopadloscienny.cpp

${OBJ}/Scena.o: src/Scena.cpp inc/Scena.hh inc/Wektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Scena.o src/Scena.cpp

clean:
	rm -rf ${OBJ} ${TRGDIR}dron.out

clear:
	rm -rf ${OBJ} ${TRGDIR}dron.out