import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE&&&&&&
 * 
 * @author 김명우
 *
 */
public class mwkim_20190101_02 {

	static void changing(int change, int[] board, int[] maxBoard, int[] minBoard, int maxValue) {
		if(change <= 0) {
			if(Integer.parseInt(Arrays.toString(board)) < maxValue) {
				
			}
			else
				return;
		}
		
		
		
		
	}
	
	static void swap(int[] board, int idx1, int idx2) {
		int tmp = board[idx1];
		board[idx1] = board[idx2];
		board[idx2] = tmp;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int testCase = sc.nextInt();
		for(int test = 1; test <= testCase; test++) {
			String num = sc.next();
			int[] board = new int[num.length()];
			int change = sc.nextInt();
			List<Integer> reverseArr = new ArrayList<Integer>();
			int[] maxBoard = new int[change];
			int[] minBoard = new int[change];
			
			for(int i = 0; i < num.length(); i++) {
				board[i] = Character.digit(num.charAt(i), 10);
				reverseArr.add(board[i]);
			}
			
			Collections.reverse(reverseArr);
			for(int i = 0; i < reverseArr.size(); i++) {
				if(i < change)
					maxBoard[i] = reverseArr.get(i);
				if(reverseArr.size() - change <= i)
					minBoard[i] = reverseArr.get(i);
			}
			
			System.out.println("#" + test + " " + reverseArr.toString());
		}
	}

}
