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

all: example exampleSubMenu exampleSelMenu GCTest clean

example: example.o libmenu.o
	$(cc) -o example$(e) example.o libmenu.o

example.o:
	$(cc) -c example.c -o example.o

exampleSubMenu: exampleSubMenu.o libmenu.o
	$(cc) -o exampleSubMenu$(e) exampleSubMenu.o libmenu.o

exampleSubMenu.o:
	$(cc) -c exampleSubMenu.c -o exampleSubMenu.o

exampleSelMenu: exampleSelMenu.o libmenu.o
	$(cc) -o exampleSelMenu$(e) exampleSelMenu.o libmenu.o

exampleSelMenu.o:
	$(cc) -c exampleSelMenu.c -o exampleSelMenu.o

GCTest: GCTest.o libmenu.o
	$(cc) -o GCTest$(e) GCTest.o libmenu.o

GCTest.o:
	$(cc) -c GCTest.c -o GCTest.o

libmenu.o:
	$(cc) -c ../libmenu.c -o libmenu.o

clean:
	$(del) *.o