
class Tabuleiro:
    tabuleiro = [[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]

    def adiciona(self, valor, p1, p2):
        if 0 < p1 <= 6 and 0 < p2 <=6:
            self.tabuleiro[p1-1][p2-1] = valor
        else:
            print "posicao inexistente!"

    def remove(self, p1, p2):
        if 0 < p1 <= 6 and 0 < p2 <=6:
            self.tabuleiro[p1-1][p2-1] = 0
        else:
            print "posicao inexistente!"
    
    def verifica(self, p1, p2):
        if 0 < p1 <= 6 and 0 < p2 <=6:
            return self.tabuleiro[p1-1][p2-1]
        else:
            print "posicao inexistente!"



