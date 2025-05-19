flags = -Wall -g
# replace clang with gcc and clang++ with g++ for the GNU Compiler Collection
cc = clang $(flags)
cpc = clang++ $(flags)
ifeq ($(OS), Windows_NT)
	e = .exe
	del = del /Q
else
	e = 
	del = rm -f
endif

all:

exampleC: exampleC.o libmenuC.o
	$(cc) -o exampleC$(e) exampleC.o libmenuC.o
exampleCPP: exampleCPP.o libmenuCPP.o
	$(cpc) -o exampleCPP$(e) exampleCPP.o libmenuCPP.o

exampleC.o:
	$(cc) -c example/main.c -o exampleC.o
exampleCPP.o:
	$(cc) -c example/main.cpp -o exampleCPP.o

exampleSubMenuC: exampleSubMenuC.o libmenuC.o
	$(cc) -o exampleSubMenuC$(e) exampleSubMenuC.o libmenuC.o
exampleSubMenuCPP: exampleSubMenuCPP.o libmenuCPP.o
	$(cpc) -o exampleSubMenuCPP$(e) exampleSubMenuCPP.o libmenuCPP.o

exampleSubMenuC.o:
	$(cc) -c exampleSubMenu/main.c -o exampleSubMenuC.o
exampleSubMenuCPP.o:
	$(cc) -c exampleSubMenu/main.cpp -o exampleSubMenuCPP.o

exampleSelMenuC: exampleSelMenuC.o libmenuC.o
	$(cc) -o exampleSelMenuC$(e) exampleSelMenuC.o libmenuC.o
exampleSelMenuCPP: exampleSelMenuCPP.o libmenuCPP.o
	$(cpc) -o exampleSelMenuCPP$(e) exampleSelMenuCPP.o libmenuCPP.o

exampleSelMenuC.o:
	$(cc) -c exampleSelMenu/main.c -o exampleSelMenuC.o
exampleSelMenuCPP.o:
	$(cc) -c exampleSelMenu/main.cpp -o exampleSelMenuCPP.o

GCTest: GCTest.o libmenuC.o
	$(cc) -o GCTest$(e) GCTest.o libmenuC.o

GCTest.o:
	$(cc) -c GCTest.c -o GCTest.o

libmenuC.o:
	$(cc) -c ../libmenu.c -o libmenuC.o
libmenuCPP.o:
	$(cc) -c ../libmenu.cpp -o libmenuCPP.o

clean:
	$(del) *.o