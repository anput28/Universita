import java.util.HashMap;
import java.util.Map;
import java.io.Serializable;
import java.io.ObjectInputStream;
import java.io.FileInputStream;
import java.io.ObjectOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileNotFoundException;

public class Esse3 implements Serializable {
	private static int generatoreCodice=0;
	private transient String password;
	private HashMap<Integer,Studente> a = new HashMap<Integer,Studente>();

	public Esse3(String psw){
		password=psw;
	}

	public void inserisciStudente(Studente b){
		Integer key = new Integer (generatoreCodice++);
		a.put(key,b);
	}

	public void salva(){
		//creo lo stream di output con il file Esse3.dat gestendo le opportune eccezioni
		ObjectOutputStream output = null;
		try{
			output = new ObjectOutputStream(new FileOutputStream("Esse3.dat"));
		}catch(FileNotFoundException fnfe){
			fnfe.printStackTrace();
		}catch(IOException e){
			e.printStackTrace();
		}

		//scrivo su file l'oggetto corrente e chiudo lo stream;
		try{
			output.writeObject(this);
			output.close();
		}catch(IOException e){
			e.printStackTrace();
		}	
	}

	public Esse3 carica(){

		//creo lo stream di input con il file Esse3.dat gestendo le opportune eccezioni
		ObjectInputStream input = null;
		try{
			input = new ObjectInputStream(new FileInputStream("Esse3.dat"));
		}catch(FileNotFoundException fnfe){
			fnfe.printStackTrace();
		}catch(IOException e){
			e.printStackTrace();
		}

		/*leggo l'oggetto corrente dal file, poichè il metodo readObject di ObjectInputStream restituisce un oggetto
		di tipo Object è necessario il cast alla classe corrente.*/
		Esse3 oggettoCorrente = null;
		try{
			oggettoCorrente = (Esse3) input.readObject();
			input.close();
		}catch(ClassNotFoundException cnfe){
			cnfe.printStackTrace();
		}catch(IOException e){
			e.printStackTrace();
		}

		return oggettoCorrente;
	}

	public void stampaElenco(){
		System.out.println("STUDENTI PRESENTI IN ESSE3:");
		for(Map.Entry<Integer, Studente> stampa: a.entrySet()){
			System.out.println(stampa.getKey() + ": "+stampa.getValue().getName());
		}
	}
}