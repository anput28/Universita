public class testOsservazioneCometa{
	public static void main(String args[]){
		//nomi da associare ai thread
		String nomi[] = {"Uno", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci"};

		//oggetto telescopio condiviso dai vari thread
		Telescopio tele = new Telescopio();

		//array di thread in cui ogni thread rappresenta una persona
		PersonaThread persone[] = new PersonaThread[nomi.length];

		//instaziazione di tutti i thread
		for(int i = 0; i < persone.length; i++){
			persone[i] = new PersonaThread(tele, nomi[i]);
		}

		//impostazione nello stato di Runnable di tutti i thread
		for(int i = 0; i < persone.length; i++){
			persone[i].start();
		}
	}
}