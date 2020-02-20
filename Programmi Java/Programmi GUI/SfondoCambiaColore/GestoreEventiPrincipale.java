import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class GestoreEventiPrincipale extends WindowAdapter{
	public void windowClosing(WindowEvent e){
		FinestraConferma conferma = new FinestraConferma();
		conferma.setVisible(true);
	}
}