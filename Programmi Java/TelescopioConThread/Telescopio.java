public class Telescopio{

	public void osservazione(){
		System.out.println(Thread.currentThread().getName() + " sta osservando la cometa.");

		try{
			Thread.sleep(2000);
		}catch(InterruptedException e){
			e.printStackTrace();
		}

		System.out.println(Thread.currentThread().getName() + " ha terminato di osservare.");
	}
}