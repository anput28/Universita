import java.io.Serializable;

public class Studente implements Serializable{
	private String nome;
	private int eta;

	public Studente (String nome, int eta){
		this.nome=nome; 
		this.eta=eta;
	}

	public String getName(){
		return nome;
	}
}