package Rules;

public class Game {
	private char[][] mat = new char[3][3];
	private boolean[][] putSomeThing = new boolean[3][3];
	private char piece[] = {'x','o'};
	private boolean turn = false;
	private final int H_EMPTY = 32;
	
	public Game() {
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				mat[i][j] = ' ';
				putSomeThing[i][j] = false;
			}
		}
	}
	
	public boolean isDone() {
		return (old() || hasAWinnerF1() || hasAWinnerF2() || hasAWinnerF3());
	}
	public String wichOneWin() {
		if(hasAWinnerF1()) {
			int sum_case1 = (mat[0][0]+mat[0][1]+mat[0][2])/3;
			int sum_case2 = (mat[1][0]+mat[1][1]+mat[1][2])/3;
			int sum_case3 = (mat[2][0]+mat[2][1]+mat[2][2])/3;
			
			if((sum_case1==mat[0][0]&&sum_case1!=H_EMPTY)) {
				return String.valueOf(mat[0][0]);
			}else if((sum_case2==mat[1][0]&&sum_case2!=H_EMPTY)) {
				return String.valueOf(mat[1][0]);
			}else if((sum_case3==mat[2][0]&&sum_case3!=H_EMPTY)) {
				return String.valueOf(mat[2][0]);
			}
		}else if(hasAWinnerF2()) {
			int sum_case1 = (mat[0][0]+mat[1][0]+mat[2][0])/3;
			int sum_case2 = (mat[0][1]+mat[1][1]+mat[2][1])/3;
			int sum_case3 = (mat[0][2]+mat[1][2]+mat[2][2])/3;
			
			if((sum_case1==mat[0][0]&&sum_case1!=H_EMPTY)) {
				return String.valueOf(mat[0][0]);
			}else if((sum_case2==mat[0][1]&&sum_case2!=H_EMPTY)) {
				return String.valueOf(mat[0][1]);
			}else if((sum_case3==mat[0][2]&&sum_case3!=H_EMPTY)) {
				return String.valueOf(mat[0][2]);
			}
			
		}else if(hasAWinnerF3()) {
			int sum_case1 = (mat[0][0]+mat[1][1]+mat[2][2])/3;
			int sum_case2 = (mat[0][2]+mat[1][1]+mat[2][0])/3;
			
			if((sum_case1==mat[0][0]&&sum_case1!=H_EMPTY)) {
				return String.valueOf(mat[0][0]);
			}else if((sum_case2==mat[0][2]&&sum_case2!=H_EMPTY)) {
				return String.valueOf(mat[0][2]);
			}
		}else if(old()) {
			return "tied";
		}
		
		return "none";
	}
	
	private boolean old() {
		for (int i = 0; i < putSomeThing.length; i++) {
			for (int j = 0; j < putSomeThing[i].length; j++) {
				if(!putSomeThing[i][j]) return false;
			}
		}		
		return true;
	}
	
	private boolean hasAWinnerF1() {
		boolean ans = false;
		
		int sum_case1 = (mat[0][0]+mat[0][1]+mat[0][2])/3;
		int sum_case2 = (mat[1][0]+mat[1][1]+mat[1][2])/3;
		int sum_case3 = (mat[2][0]+mat[2][1]+mat[2][2])/3;
		
		//horizontal
		ans = ans || (sum_case1==mat[0][0]&&sum_case1!=H_EMPTY) || (sum_case2==mat[1][0]&&sum_case2!=H_EMPTY) || (sum_case3==mat[2][0]&&sum_case3!=H_EMPTY);
			
		return ans;
	}
	
	private boolean hasAWinnerF2() {
		boolean ans = false;
			
		int sum_case1 = (mat[0][0]+mat[1][0]+mat[2][0])/3;
		int sum_case2 = (mat[0][1]+mat[1][1]+mat[2][1])/3;
		int sum_case3 = (mat[0][2]+mat[1][2]+mat[2][2])/3;
		
		//vertical
		ans = ans || (sum_case1==mat[0][0]&&sum_case1!=H_EMPTY) || (sum_case2==mat[0][1]&&sum_case2!=H_EMPTY) || (sum_case3==mat[0][2]&&sum_case3!=H_EMPTY);
		
		return ans;
	}
	private boolean hasAWinnerF3() {
		boolean ans = false;
		
		int sum_case1 = (mat[0][0]+mat[1][1]+mat[2][2])/3;
		int sum_case2 = (mat[0][2]+mat[1][1]+mat[2][0])/3;
		
		//cruz
		ans = ans || (sum_case1==mat[0][0]&&sum_case1!=H_EMPTY) || (sum_case2==mat[2][0]&&sum_case2!=H_EMPTY);
		
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
	
	public boolean getTurn() {
		return turn;
	}
	
	private static int boolToInt(boolean b) {
	    return b ? 1 : 0;
	}
}
