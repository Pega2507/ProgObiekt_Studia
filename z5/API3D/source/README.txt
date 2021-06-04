0. Paczka zawiera API do rysowania brył i łamanych w 3D za pomocą gnuplota oraz openGL (glut).

1. Pliki/Moduły API:
Draw3D_api_interface.hh -- klasa ujednolicająca interfejs rysowania
Dr3D_gnuplot_api.hh/cpp -- klasa realizująca powyższy interfejs rysowania w gnuplocie
OpenGL_API.hh/cpp       -- klasa realizująca powyższy interfejs rysowania w openGL

2. Pliki przykładów:
ex_gnuplot.cpp -- przykład rysowania w gnuplocie
ex_openGL1.cpp -- przykład rysowania w openGL (zadanie identyczne jak dla gnuplota)
ex_openGL2.cpp -- przykład pokazujący lepszą wydajność realizacji w openGL

3. Pliki Makefile uruchamiające przykład mają nazwy analogiczne do przykładu.
Uruchmienie Makefile:
make -f Make_gnuplot
make -f Make_openGL1
make -f Make_openGl2

4. Wymagania:
4.1. Dla realizacji w gnuplocie potzrebny jest gnuplot
(dla ubuntu [LTS 20.04])
sudo apt install gnuplot
4.2. Dla realizacji w openGl:
(cytat za autorem modułu)

	To successfully compile this program some additional libraries are needed:

	On ubuntu (LTS 20.04) run:
	1. sudo apt-get install build-essential
	2. sudo apt-get install freeglut3-dev

	On mint run: (might not work, didn't check it by myself) <--copied from Internet
	1. sudo apt-get install build-essential
	2. sudo apt-get install freeglut3-dev

	On fedora run: (might not work, didn't check it by myself) <--copied from Internet
	1. sudo dnf/yum install freeglut-devel

	On other linuxes or in case of any trouble try to search how to install libraries required to compile glut project ||
	There is also possibility that OpenGL won't be installed on some distributions, try then to find how to install OpenGL
	on your linux

5. Różnice pomiędzy ex_gnuplot a ex_openGL1:
Linia 2
Linia 6
Linia 16
Linia 17




