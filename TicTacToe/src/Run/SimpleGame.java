package Run;

import java.util.Scanner;

import Algorithm.GraphBuilder;
import Algorithm.MinMax;
import Rules.*;

public class SimpleGame {
		
	public static void main(String[] args) throws IllegalMoveException {
		Scanner s = new Scanner(System.in);
		Game g = new Game();
		
		while(!g.isDone()) {
			if(g.getTurn()) {
				GraphBuilder gb = new GraphBuilder();
				//construir grafo
				//algoritmo
				MinMax mn = new MinMax(gb);
				
			}else {
				System.out.print("Informe a posição onde você deseja jogar: ");
				int x = s.nextInt();
				int y = s.nextInt();
				
				try {
					g.move(x, y);
				}catch (IllegalMoveException i){
					System.err.println("\n *Movimento Ilegal, casa já ocupada* \n");
				}
				
				g.printTicTacToe();
			}
		}
		System.out.println("Jogo finalizado");
		s.close();
	}
}
