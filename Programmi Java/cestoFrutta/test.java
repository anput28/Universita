import java.util.ArrayList;
public class test{
	public static void main(String args[]){
		Mela m1 = new Mela(180);
		Mela m2 = new Mela(220);
		Mela m3 = new Mela(160);

		Arancia a1 = new Arancia(420);
		Arancia a2 = new Arancia(600);

		Pesca p1 = new Pesca(180);
		Pesca p2 = new Pesca(210);
		Pesca p3 = new Pesca(220);

		Cesto<Mela> c1 = new Cesto<>();
		Cesto<Arancia> c2 = new Cesto<>();

		c1.aggiungi(m1);
		c1.aggiungi(m2);
		c1.aggiungi(m2);
		System.out.println(c1.getPeso());
	}
}