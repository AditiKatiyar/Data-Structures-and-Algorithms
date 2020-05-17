/*
 * Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 
 * or a combination of them as their prime factors.
 *
 * Example:
 *
 * Input :
 * Prime numbers : [2,3,5]
 * k : 5
 *
 * If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be:
 *
 * Output:
 * {2,3,4,5,6}
 *
 * Explanation :
 * 4 = p1 * p1 ( 2 * 2 )
 * 6 = p1 * p2 ( 2 * 3 )
 *
 * Note: The sequence should be sorted in ascending order
 */

import java.util.*;

public class SequenceWithGivenPrimes {
    public static ArrayList<Integer> solve(int A, int B, int C, int D) {
        // maintain a priority queue for all the possible elements
        PriorityQueue<Integer> q = new PriorityQueue<Integer>(); 

        // list of all the unique primes A, B & C. e.g. if A=2, B=2, C=2, then there would be just one prime to generate 
        // numbers, i.e., 2 only
        ArrayList<Integer> list = new ArrayList<>();
        if (A != B && A != C) {
            list.add(A);
            q.add(A);
        }
        if (B != C) {
            list.add(B);
            q.add(B);
        }
        list.add(C);
        q.add(C);
        
        int len = list.size();
        
        ArrayList<Integer> ans = new ArrayList<>();
        while (D > 0) {
            D--;
            Integer num = q.poll(); // peek() will just return the top element. poll() return as well as remives top element.
            ans.add(num);
            for (int i=0 ; i<len ; i++) { // generate numbers
                int x = num * list.get(i);
                if (!q.contains(x)) { // check if the generated number is already in the priority queue.
                    q.add(x);
                }
            }
        }
        
        return ans;
    }

    public static void main(String[] args) {
    	Scanner s = new Scanner(System.in);
    	int p1 = s.nextInt();
    	int p2 = s.nextInt();
    	int p3 = s.nextInt();
    	int k = s.nextInt();
    	ArrayList<Integer> ans = solve(p1, p2, p3, k);
    	for (int i=0 ; i<ans.size() ; i++) {
    		System.out.print(ans.get(i) + " ");
    	}
    	System.out.println();
    }
}
