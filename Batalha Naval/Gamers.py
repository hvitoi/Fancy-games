from Tabuleiro import Tabuleiro
class Gamers:

    __nome = ""
    tabuleiro = Tabuleiro()
    def __init__(self, nome):
        self.__nome = nome

    def getNome(self):
        return self.__nome

    def atirar(self, oponente, p1, p2):
        alvo = oponente.tabuleiro.verifica(p1, p2)

        if alvo==0:
            print "agua"
        else:
            if alvo.afundado():
                print "Destruido"
            else:
                alvo.afundar();
                print alvo.__class__.__name__