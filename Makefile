CC = gcc
OPTIONS = -W -Wall -std=c89 -pedantic -O3 `pkg-config --libs-only-l MLV` `pkg-config --libs-only-other --libs-only-L MLV`
MLV_LIB_LIEN = `pkg-config --libs-only-l MLV`
SRC= src/

main : $(SRC)aff_jeux.o $(SRC)main.o
	$(CC) $(OPTION) $(SRC)aff_jeux.o $(SRC)main.o -o main $(MLV_LIB_LIEN)

main.o : $(SRC)main.c
	$(CC) $(OPTION) -c $(SRC)main.c $(MLV_LIB_LIEN)

aff_jeux.o : $(SRC)aff_jeux.c $(SRC)aff_jeux.h
	$(CC) $(OPTION) -c aff_jeux.c $(MLV_LIB_LIEN)

clean :
	rm -rf $(SRC)*.o*
	rm -rf $(SRC)*~*
	rm -rf main
	rm -rf *~*
