package Rules;

public class Game {
	private char[][] mat = new char[3][3];
	private boolean[][] putSomeThing = new boolean[3][3];
	private char piece[] = {'x','o'};
	private boolean turn = false;
	
	public Game() {
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				mat[i][j] = ' ';
				putSomeThing[i][j] = false;
			}
		}
	}
	
	public boolean isDone() {
		return (old() || hasAWinner());
	}
	
	private boolean old() {
		for (int i = 0; i < putSomeThing.length; i++) {
			for (int j = 0; j < putSomeThing[i].length; j++) {
				if(!putSomeThing[i][j]) return false;
			}
		}		
		return true;
	}
	
	private boolean hasAWinner() {
		boolean ans = false;
		//horizontal
		ans = ans || ((mat[0][0]+mat[0][1]+mat[0][2])/3==mat[0][0]) || ((mat[1][0]+mat[1][1]+mat[1][2])/3==mat[1][0]) || ((mat[2][0]+mat[2][1]+mat[2][2])/3==mat[2][0]);
		//vertical
		ans = ans || ((mat[0][0]+mat[1][0]+mat[2][0])/3==mat[0][0]) || ((mat[0][1]+mat[1][1]+mat[2][1])/3==mat[0][1]) || ((mat[0][2]+mat[1][2]+mat[2][2])/3==mat[0][2]);
		//cruz
		ans = ans || ((mat[0][0]+mat[1][1]+mat[2][2])/3==mat[0][0]) || ((mat[0][2]+mat[1][1]+mat[2][0])/3==mat[2][0]);
		
		return ans;
	}
	
	public void printTicTacToe() {
		System.out.println("---------");
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				System.out.print("|"+mat[i][j]+"|");
			}
			System.out.println("\n---------");
		}			
		
	}
	
	public void move(int x, int y) throws IllegalMoveException {
		if(!putSomeThing[x-1][y-1]) {
			putSomeThing[x-1][y-1] = true;
			mat[x-1][y-1] = piece[boolToInt(turn)];
			turn = !turn;
		}else {
			throw new IllegalMoveException("Movimento Ilegal, casa já ocupada");
		}
	}
	
	private static int boolToInt(boolean b) {
	    return b ? 1 : 0;
	}
}
