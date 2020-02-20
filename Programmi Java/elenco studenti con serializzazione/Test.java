public class Test{
	public static void main(String args[]){
		//creo un elenco di studenti
		String nomi[] = {"Lucia", "Marco", "Alessandra", "Mario", "Paola", "Giovanni", "Rosa", "Filippo"};
		int eta[] = {19, 24, 20, 20, 18, 21, 22, 19};

		Studente studenti[] = new Studente[nomi.length];
		for(int i = 0; i < nomi.length; i++){
			studenti[i] = new Studente(nomi[i], eta[i]);
		}

		Esse3 scriviEsse3 = new Esse3("Password");
		for(int i = 0; i < studenti.length; i++){
			scriviEsse3.inserisciStudente(studenti[i]);
		}

		//salvo sul file
		scriviEsse3.salva();

		Esse3 leggiEsse3 = new Esse3("Password2");
		leggiEsse3 = scriviEsse3.carica();

		//stampo ciò che è stato caricato dal file
		leggiEsse3.stampaElenco();

	}
}