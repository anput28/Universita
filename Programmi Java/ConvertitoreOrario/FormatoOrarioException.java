public class FormatoOrarioException extends Exception{
	private String orario;

	public FormatoOrarioException(String orario){
		this.orario = orario;
	}

	public String toString(){
		return "L'orario "+orario+" non esiste.\nRiprova.";
	}
}