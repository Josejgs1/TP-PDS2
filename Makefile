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
DOCTESTDIR=.

# Diretórios e arquivos
OBJFILES=$(OBJDIR)/jogador.o $(OBJDIR)/jogoDaVelha.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/lig4.o $(OBJDIR)/reversi.o $(OBJDIR)/campoMinado.o $(OBJDIR)/main.o
BINFILE=$(BINDIR)/main

# Arquivos de teste
TESTOBJFILES_LIG4=$(OBJDIR)/testeLig4.o
TESTOBJFILES_CAMPO_MINADO=$(OBJDIR)/testeCampoMinado.o
TESTOBJFILES_JOGO_DA_VELHA=$(OBJDIR)/testeJogoDaVelha.o
TESTOBJFILES_REVERSI=$(OBJDIR)/testeReversi.o

TESTBINFILE_LIG4=$(BINDIR)/testLig4
TESTBINFILE_CAMPO_MINADO=$(BINDIR)/testCampoMinado
TESTBINFILE_JOGO_DA_VELHA=$(BINDIR)/testJogoDaVelha
TESTBINFILE_REVERSI=$(BINDIR)/testeReversi

# Regras principais
all: $(BINDIR) $(FILESDIR) $(BINFILE)

$(BINFILE): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(BINFILE)

# Regras para arquivos .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

# Regras para garantir que as pastas existem
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

$(FILESDIR):
	mkdir -p $(FILESDIR)

# Regras para compilar os testes
$(TESTBINFILE_LIG4): $(TESTOBJFILES_LIG4) $(OBJDIR)/jogador.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/lig4.o
	$(CC) $(CFLAGS) $(TESTOBJFILES_LIG4) $(OBJDIR)/jogador.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/lig4.o -o $(TESTBINFILE_LIG4) -I$(INCLUDEDIR) -I$(DOCTESTDIR)

$(TESTBINFILE_CAMPO_MINADO): $(TESTOBJFILES_CAMPO_MINADO) $(OBJDIR)/jogador.o $(OBJDIR)/campoMinado.o $(OBJDIR)/jogoDeTabuleiro.o
	$(CC) $(CFLAGS) $(TESTOBJFILES_CAMPO_MINADO) $(OBJDIR)/jogador.o $(OBJDIR)/campoMinado.o $(OBJDIR)/jogoDeTabuleiro.o -o $(TESTBINFILE_CAMPO_MINADO) -I$(INCLUDEDIR) -I$(DOCTESTDIR)

$(TESTBINFILE_JOGO_DA_VELHA): $(TESTOBJFILES_JOGO_DA_VELHA) $(OBJDIR)/jogador.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/jogoDaVelha.o
	$(CC) $(CFLAGS) $(TESTOBJFILES_JOGO_DA_VELHA) $(OBJDIR)/jogador.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/jogoDaVelha.o -o $(TESTBINFILE_JOGO_DA_VELHA) -I$(INCLUDEDIR) -I$(DOCTESTDIR)

$(TESTBINFILE_REVERSI): $(TESTOBJFILES_REVERSI) $(OBJDIR)/jogador.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/reversi.o
	$(CC) $(CFLAGS) $(TESTOBJFILES_REVERSI) $(OBJDIR)/jogador.o $(OBJDIR)/jogoDeTabuleiro.o $(OBJDIR)/reversi.o -o $(TESTBINFILE_REVERSI) -I$(INCLUDEDIR) -I$(DOCTESTDIR)

$(OBJDIR)/testeLig4.o: $(TESTDIR)/testeLig4.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(DOCTESTDIR) -c $< -o $@

$(OBJDIR)/testeCampoMinado.o: $(TESTDIR)/testeCampoMinado.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(DOCTESTDIR) -c $< -o $@

$(OBJDIR)/testeJogoDaVelha.o: $(TESTDIR)/testeJogoDaVelha.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(DOCTESTDIR) -c $< -o $@

$(OBJDIR)/reversi.o: $(TESTDIR)/reversi.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(DOCTESTDIR) -c $< -o $@

# Regras para executar os testes
test_lig4: $(TESTBINFILE_LIG4)
	./$(TESTBINFILE_LIG4)

test_campo_minado: $(TESTBINFILE_CAMPO_MINADO)
	./$(TESTBINFILE_CAMPO_MINADO)

test_jogo_da_velha: $(TESTBINFILE_JOGO_DA_VELHA)
	./$(TESTBINFILE_JOGO_DA_VELHA)

test_reversi: $(TESTBINFILE_REVERSI)
	./$(TESTBINFILE_REVERSI)

# Limpeza
clean:
	rm -f $(BINFILE) $(OBJDIR)/*.o $(TESTBINFILE_LIG4) $(TESTBINFILE_CAMPO_MINADO) $(TESTBINFILE_JOGO_DA_VELHA) $(TESTBINFILE_REVERSI)
