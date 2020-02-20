import java.util.ArrayList;
import java.util.Iterator;

public class Cesto<F extends Frutta> {
	private ArrayList<F> al;

	public Cesto(){
		al = new ArrayList<>();
	}

	public int getPeso(){
		int pesoTotale = 0;
		Iterator<F> iter = al.iterator();
		while(iter.hasNext()){
			pesoTotale += iter.next().getPeso();
		}

		return pesoTotale;
	}

	public void aggiungi(F f){
		try{
			int nuovoPeso = getPeso() + f.getPeso();
			if(getPeso() > 5000){
				throw new OverWeightException();
			}
			al.add(f);
			System.out.println(f.getClass().getName()+" da "+f.getPeso()+" grammi aggiunta al cesto.");
		}catch(OverWeightException o){
			System.out.println(o.toString());
		}
	}

}