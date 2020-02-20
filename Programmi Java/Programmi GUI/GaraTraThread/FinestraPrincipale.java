import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.WindowConstants;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class FinestraPrincipale extends JFrame implements ActionListener{
	private static final int LARGHEZZA = 500;
	private static final int LUNGHEZZA = 300;
	private boolean running;

	private JTextField testoRosso;
	private JTextField testoBlu;
	private JButton avvia;
	private JButton stop;

	public FinestraPrincipale(){
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setTitle("ThreadRace");
		setSize(LARGHEZZA, LUNGHEZZA);
		setLayout(new BorderLayout());

		JPanel principale = new JPanel();
		principale.setLayout(new GridLayout(1,1));

		JPanel pannelloRosso = new JPanel();
		pannelloRosso.setBackground(Color.red);
		pannelloRosso.setLayout(new FlowLayout());

		JLabel rosso = new JLabel("Rosso:");
		pannelloRosso.add(rosso);

		testoRosso = new JTextField(12);
		pannelloRosso.add(testoRosso);

		JPanel pannelloBlu = new JPanel();
		pannelloBlu.setBackground(Color.blue);
		pannelloBlu.setLayout(new FlowLayout());

		JLabel blu = new JLabel("Blu:");
		pannelloBlu.add(blu);

		testoBlu = new JTextField(12);
		pannelloBlu.add(testoBlu);

		JPanel pannelloPulsanti = new JPanel();
		pannelloPulsanti.setLayout(new FlowLayout());

		avvia = new JButton("Avvia");
		avvia.addActionListener(this);
		pannelloPulsanti.add(avvia);

		stop = new JButton("Stop");
		stop.addActionListener(this);
		pannelloPulsanti.add(stop);

		principale.add(pannelloRosso);
		principale.add(pannelloBlu);
		add(principale);
		add(pannelloPulsanti, "South");
	}

	class PrimoThread implements Runnable{
		public void run(){
			int cont = 0;
			while(running){
				testoRosso.setText(Integer.toString(cont++));
			}
		}
	}

	class SecondoThread implements Runnable{
		public void run(){
			int cont = 0;
			while(running){
				testoBlu.setText(Integer.toString(cont++));
			}
		}
	}

	public void actionPerformed(ActionEvent e){
		String evento = e.getActionCommand();
		Thread t1 = new Thread(new PrimoThread());
		Thread t2 = new Thread(new SecondoThread());

		if(evento.equals("Avvia")){
			running = true;
			t1.start();
			t2.start();
		}else if(evento.equals("Stop")){
			running = false;

		}
	}
}