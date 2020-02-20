import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Arrays;

public class CrivelloErastotene{
	public static void main(String args[]){
		int capienza;

		Scanner input = new Scanner(System.in);

		System.out.println("Inserire il numero entro il quale si vogliono trovare i numeri primi -> ");
		capienza = input.nextInt();

		ArrayList<Integer> erastotene = new ArrayList<>(capienza-1);

		//inizializzo l'array list
		for(int i = 2; i <= capienza; i++){
			erastotene.add(i);
		}

		//applico l'algoritmo
		Iterator<Integer> iter = erastotene.listIterator();
		for(int i = 2; i <= capienza; i++){
			while(iter.hasNext()){
				int num = iter.next();
				if(i != num && num % i == 0){
					iter.remove();

				}
			}
		}

		erastotene.trimToSize();
		
		//stampa	
		System.out.println(Arrays.toString(erastotene.toArray()));		
	}
}