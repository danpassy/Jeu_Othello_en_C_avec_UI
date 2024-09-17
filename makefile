# Variables
CC = gcc
CFLAGS = -DDEBUG -g -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`
EXEC = othello

# Les fichiers sources .c
SRC = $(wildcard *.c)
# Les fichiers objets .o
OBJ = $(SRC:.c=.o)

# Cible par défaut
all: $(EXEC)

# Création de l'exécutable
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# Règle générique pour convertir un .c en .o
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

# Nettoyer les fichiers objets
clean:
	rm -rf *.o

# Nettoyer tout
mrproper: clean
	rm -rf $(EXEC)

