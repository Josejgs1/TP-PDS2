CC=g++
CFLAGS=-std=c++11 -Wall

# Diretórios para objetos e binários
OBJDIR=obj
BINDIR=bin
SRCDIR=src
FILESDIR=files
INCLUDEDIR=include

# Diretórios e arquivos
OBJFILES=$(OBJDIR)/jogador.o $(OBJDIR)/jogoDaVelha.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/lig4.o $(OBJDIR)/reversi.o $(OBJDIR)/campoMinado.o $(OBJDIR)/main.o
BINFILE=$(BINDIR)/main

# Regras principais
all: $(BINDIR) $(FILESDIR) $(BINFILE)

$(BINFILE): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(BINFILE)

# Regras para arquivos .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

# Regra para garantir que as pastas existem
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

$(FILESDIR):
	mkdir -p $(FILESDIR)

# Limpeza
clean:
	rm -f $(BINFILE) $(OBJDIR)/*.o