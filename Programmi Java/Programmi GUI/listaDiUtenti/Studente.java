public class Studente {
	private int matricola;
	private String cognome;
	private String nome;
	private static final String QUALIFICA = "STUDENTE"; 

	public Studente(int matricola, String cognome, String nome){
		this.matricola = matricola;
		this.cognome = cognome;
		this.nome = nome;
	}

	public void chiSono(){
		System.out.println("cognome: "+cognome+"\nnome: "+nome+"\nqualifica: "+QUALIFICA+"\nmatricola: "+matricola+"\n");
	}
}