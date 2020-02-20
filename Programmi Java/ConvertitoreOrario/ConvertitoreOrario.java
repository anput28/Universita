import java.util.Scanner;

public class ConvertitoreOrario{
	public static void main (String args[]){
		Scanner input = new Scanner(System.in);
		String risposta;

		do{

			try{
				System.out.println("Inserire un orario in formato 24 ore: ");
				risposta = input.next();
				Orario ora = new Orario(risposta);
				System.out.println(ora.converti12(risposta));
			}catch(FormatoOrarioException foe){
				System.out.println(foe.toString());
			}

			System.out.println("Di nuovo? (si/no)");
			risposta = input.next();
		}while(risposta.equals("si"));

		System.out.println("\nArrivederci!");
	}
}