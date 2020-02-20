public class Test{
	public static void main(String args[]){
		Object lock = new Object(); //rappresenta il lock del thread

		FinestraPrincipale window = new FinestraPrincipale(lock);
		window.setVisible(true);

		Conteggio thread1 = new Conteggio(window, 0, lock);
		thread1.start();
	}
}