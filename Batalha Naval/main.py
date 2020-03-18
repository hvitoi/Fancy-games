from Armas import Aviao
from Armas import Navio
from Armas import Submarino
from Gamers import Gamers

j1 = Gamers("Fernandeta")
j2 = Gamers("Henriqueta")

j1.tabuleiro.adiciona(Submarino(), 1, 3)
j1.tabuleiro.adiciona(Aviao(), 1, 2)
j1.tabuleiro.adiciona(Aviao(), 3, 3)
j1.tabuleiro.adiciona(Navio(), 5, 3)
j1.tabuleiro.adiciona(Navio(), 5, 6)

j2.tabuleiro.adiciona(Submarino(), 1, 3)
j2.tabuleiro.adiciona(Aviao(), 1, 4)
j2.tabuleiro.adiciona(Aviao(), 5, 4)
j2.tabuleiro.adiciona(Navio(), 2, 1)
j2.tabuleiro.adiciona(Navio(), 2, 5)

j1.atirar(j2, 1, 2)
j1.atirar(j2, 1, 4)
j1.atirar(j2, 1, 4)
