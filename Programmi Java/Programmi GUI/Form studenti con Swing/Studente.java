public class Studente extends Thread{
	private int matricola;
	private String cognome;
	private String nome;
	private static final String QUALIFICA = "STUDENTE";


	public Studente(int m, String c, String n){
		matricola = m;
		cognome = c;
		nome = n;
	}

	public void chiSono(){
		System.out.println("Cognome: "+cognome+"\nNome: "+nome+"\nQualifica: "+QUALIFICA+"\nMatricola: "+matricola+"\n");
	}

	public void run(){
		chiSono();
	}
}