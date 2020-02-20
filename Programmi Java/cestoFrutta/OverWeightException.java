public class OverWeightException extends Exception{
	public OverWeightException(){
		super("Problema con il peso del cesto");
	}

	public String toString(){
		return getMessage()+": l'inserimento provoca un peso eccessivo del cesto che non puo' superare 5 kg.";
	}
}