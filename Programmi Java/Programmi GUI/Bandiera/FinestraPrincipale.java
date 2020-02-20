import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.FlowLayout;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class FinestraPrincipale extends JFrame implements ActionListener{
	private static final int LARGHEZZA = 500;
	private static final int LUNGHEZZA = 300;

	private JPanel nero;
	private JPanel rosso;
	private JPanel giallo;

	public FinestraPrincipale(){
		addWindowListener(new DistruttoreFinestra());
		setSize(LARGHEZZA, LUNGHEZZA);
		setTitle("Finestra");
		setLayout(new BorderLayout());

		JPanel principale = new JPanel();
		principale.setLayout(new GridLayout(3,1));

		nero = new JPanel();
		principale.add(nero);

		rosso = new JPanel();
		principale.add(rosso);

		giallo = new JPanel();
		principale.add(giallo);

		add(principale, "Center");

		JPanel pannelloBottoni = new JPanel();
		pannelloBottoni.setLayout(new FlowLayout());

		JButton b1 = new JButton("Nero");
		b1.addActionListener(this);
		pannelloBottoni.add(b1);

		JButton b2 = new JButton("Rosso");
		b2.addActionListener(this);
		pannelloBottoni.add(b2);

		JButton b3 = new JButton("Giallo");
		b3.addActionListener(this);
		pannelloBottoni.add(b3);

		add(pannelloBottoni, "South");
	}

	public void actionPerformed(ActionEvent e){
		String evento = e.getActionCommand();

		if(evento.equals("Nero")){
			nero.setBackground(Color.black);
		}else if(evento.equals("Rosso")){
			rosso.setBackground(Color.red);
		}else if(evento.equals("Giallo")){
			giallo.setBackground(Color.yellow);
		}
	}

}