import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Color;

public class FinestraDiario extends JFrame implements ActionListener{
	private static final int LARGHEZZA = 800;
	private static final int LUNGHEZZA = 500;
	private static final int RIGHE = 15;
	private static final int NUM_CARATTERI = 50;

	private JTextArea areaTesto;
	private JPanel pannello;

	private String appunto1 = "";
	private String appunto2 = "";

	public FinestraDiario(){
		addWindowListener(new GestoreFinestraPrincipale());

		setTitle("Diario");
		setSize(LARGHEZZA, LUNGHEZZA);
		setLayout(new BorderLayout());
		getContentPane().setBackground(Color.gray);

		JPanel pannelloTesto = new JPanel();
		pannelloTesto.setBackground(Color.cyan);

		areaTesto = new JTextArea(RIGHE, NUM_CARATTERI);
		areaTesto.setLineWrap(true);
		pannelloTesto.add(areaTesto, "North");
		add(pannelloTesto);

		creaPannello();
		add(pannello, "South");
	}

	private void creaPannello(){
		pannello = new JPanel();
		pannello.setLayout(new FlowLayout());

		JButton salva1 = new JButton("Salva appunto 1");
		salva1.addActionListener(this);
		pannello.add(salva1);

		JButton salva2 = new JButton("Salva appunto 2");
		salva2.addActionListener(this);
		pannello.add(salva2);

		JButton carica1 = new JButton("Carica appunto 1");
		carica1.addActionListener(this);
		pannello.add(carica1);

		JButton carica2 = new JButton("Carica appunto 2");
		carica2.addActionListener(this);
		pannello.add(carica2);

		JButton cancella = new JButton("Cancella");
		cancella.addActionListener(this);
		pannello.add(cancella);
	}

	public void actionPerformed(ActionEvent e){
		String evento = e.getActionCommand();

		if(evento.equals("Salva appunto 1")){
			appunto1 = areaTesto.getText();
		}else if(evento.equals("Salva appunto 2")){
			appunto2 = areaTesto.getText();
		}else if(evento.equals("Carica appunto 1")){
			areaTesto.setText(appunto1);
		}else if(evento.equals("Carica appunto 2")){
			areaTesto.setText(appunto2);
		}else if(evento.equals("Cancella")){
			areaTesto.setText("");
		}
	} 
}