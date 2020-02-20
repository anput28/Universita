import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class DistruttoreFinestra extends WindowAdapter{

	public void windowClosing(WindowEvent e){
		System.out.println("Sto chiudendo il programma");
		System.exit(0);
	}
}