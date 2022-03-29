package Algorithm;

import java.util.LinkedList;

import Rules.Game;

@SuppressWarnings("unused")
public class MinMax {
	
	public LinkedList<Integer>[] graph;	
	private GraphBuilder gb;
	private final int inf = 1000000007;

	public MinMax(GraphBuilder gb) {
		this.gb = gb;
		graph = gb.getGraph();	
	}
	private int algorithm(int node, int depth, boolean isMaximizing) {
		if(depth == 0){return gb.getWeights(node);}
		if(isMaximizing){
			int value = -inf;
			for (Integer child : graph[node]) {
				value = Math.max(value, algorithm(child, (depth-1), false));	
			}
			gb.setWeights(node, value);
			return value;
		}else{
			int value = inf;
			for (Integer child : graph[node]) {
				value = Math.min(value, algorithm(child, (depth-1), true));	
			}
			gb.setWeights(node, value);
			return value;
		}
		
	}
	public Game bestPlaying(int node, int depth, boolean isMaximizing) {

		double search = algorithm(node, depth, isMaximizing);

		//Zero-based
		LinkedList<Integer> son = gb.getSon(0);
		
		int x=0;

		for(int s : son){
			if(gb.getWeights(s)==search){
				x = s;
				break;
			}
		}
		return gb.getBoard(x);
	}
}
