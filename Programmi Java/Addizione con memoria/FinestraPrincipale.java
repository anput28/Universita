import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.FlowLayout;

public class FinestraPrincipale extends JFrame implements ActionListener{
	private static final int LARGHEZZA = 500;
	private static final int LUNGHEZZA = 300;

	private JTextField testo;
	private JLabel risultato;

	private int totale = 0;

	public FinestraPrincipale(){
		addWindowListener(new GestoreFinestra());

		setTitle("Addizione");
		setSize(LARGHEZZA, LUNGHEZZA);
		setLayout(new GridLayout(3,1));

		//-------------PRIMO PANNELLO-------------------------------
		JPanel pannello1 = new JPanel();
		pannello1.setLayout(new GridLayout(2,1));

		JLabel label = new JLabel("Inserire un numero alla volta.");
		pannello1.add(label);

		testo = new JTextField();
		pannello1.add(testo);
		//------------------------------------------------------------

		//-------------SECONDO PANNELLO-------------------------------
		JPanel pannello2 = new JPanel();
		pannello2.setLayout(new FlowLayout());

		JLabel label2 = new JLabel("Risultato:");
		risultato = new JLabel();

		pannello2.add(label2);
		pannello2.add(risultato);
		//------------------------------------------------------------

		//-------------TERZO PANNELLO-------------------------------
		JPanel pannello3 = new JPanel();
		pannello3.setLayout(new FlowLayout());

		JButton somma = new JButton("Somma");
		somma.addActionListener(this);
		pannello3.add(somma);

		JButton cancella = new JButton("Cancella");
		cancella.addActionListener(this);
		pannello3.add(cancella);
		//------------------------------------------------------------

		add(pannello1);
		add(pannello2);
		add(pannello3);
	}

	public void actionPerformed(ActionEvent e){
		String evento = e.getActionCommand();
		if(evento.equals("Cancella")){
			testo.setText("");
			totale = 0;
			risultato.setText(Integer.toString(totale));
		}else if(evento.equals("Somma")){
			try{
				if(controllaFormato(testo.getText())){
					somma(daStringAInt(testo.getText()));
					testo.setText("");
					risultato.setText(Integer.toString(totale));
				}
			}catch(NumberFormatException nfe){
				testo.setText("ERRORE! Numero non valido.");
			}
		}
	}

	private boolean controllaFormato(String numero) throws NumberFormatException{
		numero = numero.trim();
		boolean ok = true;
		for(int i = 0; i < numero.length(); i++){
			if(Character.isDigit(numero.charAt(i)) != true){
				ok = false;
				throw new NumberFormatException();
			}
		}

		return ok;
	}

	private void somma(int numero){
		totale += numero;
	}

	private int daStringAInt(String numero){
		return Integer.parseInt(numero.trim());
	}
}