import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.WindowConstants;
import javax.swing.BoxLayout;
import java.awt.Component;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.LinkedList;

public class JavaSwingForm implements ActionListener{
	private JFrame frame;

	private static final int LARGHEZZA = 500;
	private static final int LUNGHEZZA = 200;

	private JTextField testoMatricola;
	private JTextField testoCognome;
	private JTextField testoNome;
	private JButton inserisci;
	private JButton stampa;

	private LinkedList<Studente> lista;

	public JavaSwingForm(){
		lista = new LinkedList<>();
		frame = new JFrame();
		initialize();
	}

	private void initialize(){
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

		frame.setSize(LARGHEZZA, LUNGHEZZA);
		frame.setTitle("Form");
		frame.setLayout(new BorderLayout());

		JPanel pannello = new JPanel();
		pannello.setLayout(new GridLayout(2,2));

		//------------- PRIMA COLONNA - PRIMA RIGA SX -------------------
		JPanel primaColonna = new JPanel();
		primaColonna.setLayout(new GridLayout(3,2));

		JLabel matricola = new JLabel("Matricola");
		JPanel testo1 = new JPanel(new FlowLayout(FlowLayout.LEFT));
		testoMatricola = new JTextField(8);
		testo1.add(testoMatricola);

		JLabel cognome = new JLabel("Cognome");
		JPanel testo2 = new JPanel(new FlowLayout(FlowLayout.LEFT));
		testoCognome = new JTextField(10);
		testo2.add(testoCognome);
		

		JLabel nome = new JLabel("Nome");
		JPanel testo3 = new JPanel(new FlowLayout(FlowLayout.LEFT));
		testoNome = new JTextField(10);
		testo3.add(testoNome);
		

		primaColonna.add(matricola);
		primaColonna.add(testo1);
		primaColonna.add(cognome);
		primaColonna.add(testo2);
		primaColonna.add(nome);
		primaColonna.add(testo3);
		//--------------------------------------------
		//---------------PRIMA COLONNA - SECONDA RIGA SX ---------------
		JPanel bottone1 = new JPanel();
		bottone1.setLayout(new FlowLayout(FlowLayout.CENTER));

		inserisci = new JButton("inserisci studente");
		inserisci.addActionListener(this);
		bottone1.add(inserisci);
		//-----------------------------------------------------------------

		//----------------SECONDA COLONNA - PRIMA RIGA DX -----------------------
		JPanel secondaColonna = new JPanel();
		//-----------------------------------------------------------------------
		//---------------SECONDA COLONNA - SECONDA RIGA DX---------------
		JPanel bottone2 = new JPanel();
		bottone2.setLayout(new FlowLayout(FlowLayout.CENTER));

		stampa = new JButton("stampa");
		stampa.addActionListener(this);
		bottone2.add(stampa);
		//------------------------------------------------------

		pannello.add(primaColonna);
		pannello.add(secondaColonna);
		pannello.add(bottone1);
		pannello.add(bottone2);

		frame.add(pannello);
		frame.setResizable(false);
	}

	public void actionPerformed(ActionEvent e){

		if(e.getActionCommand().equals("inserisci studente")){
			String matrStudente = testoMatricola.getText();
			String cognomeStudente = testoCognome.getText();
			String nomStudente = testoNome.getText();

			int matricolaConvertita = Integer.parseInt(matrStudente);
			lista.add(new Studente(matricolaConvertita, cognomeStudente, nomStudente));

			testoMatricola.setText("");
			testoCognome.setText("");
			testoNome.setText("");
		}else if(e.getActionCommand().equals("stampa")){
			lista.forEach(elemento -> elemento.start());
		}
	}

	

	public static void main(String args[]){
		try{
			JavaSwingForm window = new JavaSwingForm();
			window.frame.setVisible(true);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}