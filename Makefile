CC=g++
CFLAGS=-std=c++14 -Wall

# Diretórios para objetos e binários
OBJDIR=obj
BINDIR=bin
SRCDIR=src
FILESDIR=files
INCLUDEDIR=include
TESTDIR=tests

# Diretório do doctest
DOCTESTDIR=$(FILESDIR)

# Diretórios e arquivos
OBJFILES=$(OBJDIR)/jogador.o $(OBJDIR)/jogoDaVelha.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/lig4.o $(OBJDIR)/reversi.o $(OBJDIR)/campoMinado.o $(OBJDIR)/main.o
BINFILE=$(BINDIR)/main
TESTOBJFILES=$(OBJDIR)/testeCampoMinado.o
TESTBINFILE=$(BINDIR)/test

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

# Regra para compilar os testes
$(TESTBINFILE): $(TESTOBJFILES) $(OBJDIR)/jogador.o $(OBJDIR)/campoMinado.o $(OBJDIR)/jogoDeTabuleiro.o
	$(CC) $(CFLAGS) $(TESTOBJFILES) $(OBJDIR)/jogador.o $(OBJDIR)/campoMinado.o $(OBJDIR)/jogoDeTabuleiro.o -o $(TESTBINFILE) -I$(DOCTESTDIR)

$(OBJDIR)/testeCampoMinado.o: $(TESTDIR)/testeCampoMinado.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(DOCTESTDIR) -c $< -o $@

# Regra para executar os testes
test: $(TESTBINFILE)
	./$(TESTBINFILE)

# Limpeza
clean:
	rm -f $(BINFILE) $(OBJDIR)/*.o $(TESTBINFILE)
