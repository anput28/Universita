import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;

public class FinestraConferma extends JFrame implements ActionListener{
	public static final int LARGHEZZA = 300;
	public static final int LUNGHEZZA = 200;

	public FinestraConferma(){
		setTitle("Conferma");
		setSize(LARGHEZZA, LUNGHEZZA);
		setLayout(new BorderLayout());

		JLabel label = new JLabel("Sicuro di voler uscire?");
		add(label);

		JPanel pannello = new JPanel();
		pannello.setLayout(new FlowLayout());

		JButton si = new JButton("Si");
		si.addActionListener(this);
		pannello.add(si);

		JButton no = new JButton("No");
		no.addActionListener(this);
		pannello.add(no);

		add(pannello, "South");
	}

	public void actionPerformed(ActionEvent e){
		if(e.getActionCommand().equals("Si")){
			System.exit(0);
		}else if(e.getActionCommand().equals("No")){
			dispose();
		}
	}
}