import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.FlowLayout;
import java.awt.Color;

public class FinestraPrincipale extends JFrame implements ActionListener{
	private static final int LARGHEZZA = 400;
	private static final int LUNGHEZZA = 200;

	private JTextField testo;
	private JLabel label;
	private JButton avvia;
	private JButton inverti;
	private JButton stop;

	//variabile che rappresenta il verso del conteggio: true = conteggio crescente, false = conteggio decrescente
	private boolean stato = true; 
	private Object lock; //per il thread

	public FinestraPrincipale(Object l){
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		setSize(LARGHEZZA, LUNGHEZZA);
		setTitle("Conteggio");
		setResizable(false);
		setLayout(new BorderLayout());

		JPanel grid = new JPanel(new GridLayout(3,1));

		JPanel vuoto = new JPanel();

		JPanel flow = new JPanel(new FlowLayout());
		label = new JLabel("Conteggio crescente:");
		testo = new JTextField(10);
		testo.setEditable(false);
		testo.setBackground(Color.white);

		flow.add(label);
		flow.add(testo);
		
		JPanel flow2 = new JPanel(new FlowLayout());
		avvia = new JButton("Avvia");
		avvia.addActionListener(this);
		flow2.add(avvia);

		inverti = new JButton("Inverti");
		inverti.addActionListener(this);
		inverti.setEnabled(false);
		flow2.add(inverti);

		stop = new JButton("Stop");
		stop.addActionListener(this);
		stop.setEnabled(false);
		flow2.add(stop);

		grid.add(vuoto);
		grid.add(flow);
		grid.add(flow2);

		add(grid, "Center");

		lock = l;
	}

	public void setNumero(int numero){
		testo.setText(Integer.toString(numero));
	}


	public void actionPerformed(ActionEvent e){
		String evento = e.getActionCommand();

		//Quando si cliccla su avvia viene attivato il thread per iniziare ad effettuare un conteggio crescente
		
		if(evento.equals("Avvia")){
			avvia.setEnabled(false);
			avvia.setText("Riprendi");	
			inverti.setEnabled(true);
			stop.setEnabled(true);

			synchronized(lock){
				lock.notify();
			}

		/*Quando si clicca su inverti viene chiamato il metodo statico del thread per cambiare la variabile di classe che segnala
		se il thread deve essere messo in attesa oppure no.*/
		}else if(evento.equals("Inverti")){
			if(stato){
				label.setText("Conteggio decrescente: ");
				Conteggio.cambiaStato(false);
				stato = false;
			}else{
				Conteggio.cambiaStato(true);
				label.setText("Conteggio crescente: ");
				stato = true;
			}
		}else if(evento.equals("Stop")){
			avvia.setEnabled(true);
			
			Conteggio.fermati(true);
		}else if(evento.equals("Riprendi")){
			Conteggio.fermati(false);
			synchronized(lock){
				lock.notify();
			}
		}
	}
}