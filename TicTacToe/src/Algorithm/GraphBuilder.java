package Algorithm;

import java.util.LinkedList;

import Rules.Game;

public class GraphBuilder {
	
	private final int maxn = 1000007;
	
    @SuppressWarnings("unchecked")
	private LinkedList<Integer>[] graph = new LinkedList[maxn];//Grafo NÓSxARESTA
	private LinkedList<Game> nodesPos = new LinkedList<>();//Lista com as coordenadas das peças
	private int[] nodeWeights = new int[maxn];
	private int[] depthNode = new int[maxn];//profundidades dos nós
	
	public GraphBuilder() {
		depthNode[0] = 0;
		for (int i = 0; i < graph.length; i++) {
            graph[i] = new LinkedList<>();
            //nodeWeights[i] = 0;
        }
	}
	public void setImageGraph(Game g) {
		nodesPos.add(g);		
	}
	public void createASon(int v, int u) {
		graph[v].push(u);
		depthNode[u] = depthNode[v] + 1;
	}
	public void createASon(int v, LinkedList<Integer> u) {
		for (Integer i : u) {
			graph[v].push(i);
			depthNode[i] = depthNode[v] + 1;
		}
	}
	public void setWeights(int node, int weights) {
		nodeWeights[node] = weights;
	}
	public int getWeights(int node) {
		return nodeWeights[node];
	}
	
	
}