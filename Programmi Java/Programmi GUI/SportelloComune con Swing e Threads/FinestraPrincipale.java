import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.WindowConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.FlowLayout;

public class FinestraPrincipale extends JFrame implements ActionListener{
	private static final int LARGHEZZA = 400;
	private static final int LUNGHEZZA = 200;
	private Object trigger, trigger2;

	private JTextField testoConsegna;
	private JTextField testoStampa;
	private JButton apri;

	public FinestraPrincipale (Object o, Object o2){
		trigger = o;
		trigger2 = o2;

		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setTitle("Sportello");
		setSize(LARGHEZZA, LUNGHEZZA);
		setLayout(new BorderLayout());

		JPanel superiore = new JPanel();
		JPanel superioreConsegna = new JPanel();
		superioreConsegna.setLayout(new FlowLayout());

		JLabel labelConsegna = new JLabel("Consegna modulo a: ");
		superioreConsegna.add(labelConsegna);

		testoConsegna = new JTextField(15);
		superioreConsegna.add(testoConsegna);

		JPanel superioreStampa = new JPanel();
		superioreStampa.setLayout(new FlowLayout());

		JLabel labelStampa = new JLabel("stampa carta di: ");
		superioreStampa.add(labelStampa);

		testoStampa = new JTextField(15);
		superioreStampa.add(testoStampa);

		superiore.add(superioreConsegna);
		superiore.add(superioreStampa);

		JPanel inferiore = new JPanel();
		inferiore.setLayout(new FlowLayout());

		apri = new JButton("Apri sportello");
		apri.addActionListener(this);
		inferiore.add(apri);

		JButton consegna = new JButton("Consegna modulo");
		consegna.addActionListener(this);
		inferiore.add(consegna);

		JButton stampa = new JButton("Stampa carta");
		stampa.addActionListener(this);
		inferiore.add(stampa);

		add(superiore);
		add(inferiore, "South");
	}

	public synchronized void setAttesaConsegnaModulo(){
		testoConsegna.setText(Thread.currentThread().getName());
		try{
			synchronized(trigger){
				trigger.wait();
			}
		}catch(InterruptedException e){
			e.printStackTrace();
		}
	}

	public synchronized void setAttesaStampaCarta(){
		testoStampa.setText(Thread.currentThread().getName());
	}

	public void actionPerformed(ActionEvent e){
		String evento = e.getActionCommand();
		if(evento.equals("Apri sportello")){
			synchronized(trigger){
				trigger.notifyAll();
			}
			apri.setEnabled(false);
		}else if(evento.equals("Consegna modulo")){
			synchronized(trigger){
				trigger.notify();
			}
		}else if(evento.equals("Stampa carta")){
			synchronized(trigger2){
				trigger2.notify();
			}
		}
	}
}