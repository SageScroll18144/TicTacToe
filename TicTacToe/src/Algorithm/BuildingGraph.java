package Algorithm;

import Rules.Game;
import Rules.IllegalMoveException;

public class BuildingGraph {

	private GraphBuilder gb;
	private final int depth = 3;
	private Game g;
	private char[][] mat;
	
	public BuildingGraph(GraphBuilder gb, Game g) {
		this.gb = gb;
		this.g = g;//modificar pra ser uma copia	
		mat = g.getBoard();	
	}
	
	public void build(int dp, int node) throws IllegalMoveException {
		if(g.isDone()||dp==depth) {
			int x = 0;
			String winner = g.wichOneWin();
			if(winner.equals("x")) x = -1;
			else if(winner.equals("o")) x = 1;
			else if(winner.equals("tied")) x = 0;
			
			gb.setWeights(node, x);
		}else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if(g.ItsAnEmptyHouse(i, j)) {
						g.move(i, j);
						int ln = gb.getHowManyNodes()-1;
						gb.createASon(node, ln);
						build(++dp, ln);
					}
				}
			}
		}
		
		
	}
	
	public GraphBuilder getGraph() {
		return this.gb;
	}
}
