import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.WindowConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.FlowLayout;
import java.util.ArrayList;

public class JavaSwingForm implements ActionListener{
	private JFrame frame;
	private static final int LARGHEZZA = 500;
	private static final int LUNGHEZZA = 300;

	private JPanel pannello1;
	private JPanel pannello2;
	private JPanel pannello3;
	private JPanel pannello4;
	private JTextField testoMatricola;
	private JTextField testoCognome;
	private JTextField testoNome;
	private JButton inserisci;
	private JButton stampa;

	private ArrayList<Studente> studenti = new ArrayList<>();

	public JavaSwingForm(){
		initialize();
	}

	private void initialize(){
		frame = new JFrame();
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

		frame.setSize(LARGHEZZA, LUNGHEZZA);
		frame.setLayout(new BorderLayout());

		JPanel pannello = new JPanel();
		pannello.setLayout(new FlowLayout());

		//---------------------GRID 1-------------------------------------------
		JPanel grid1 = new JPanel();
		GridLayout g1 = new GridLayout(4,1);
		g1.setVgap(30);
		grid1.setLayout(g1);
		

		JLabel matricola = new JLabel("Matricola");
		grid1.add(matricola);

		JLabel cognome = new JLabel("Cognome");
		grid1.add(cognome);

		JLabel nome = new JLabel("Nome");
		grid1.add(nome);

		inserisci = new JButton("inserisci studente");
		inserisci.addActionListener(this);
		grid1.add(inserisci);
		//------------------------------------------------------------------------
		//---------------------GRID 2----------------------------------------------
		JPanel grid2 = new JPanel();
		GridLayout g2 = new GridLayout(4,1);
		g2.setVgap(30);
		grid2.setLayout(g2);

		testoMatricola = new JTextField(8);
		grid2.add(testoMatricola);

		testoCognome = new JTextField(12);
		grid2.add(testoCognome);

		testoNome = new JTextField(12);
		grid2.add(testoNome);

		stampa = new JButton("stampa");
		stampa.addActionListener(this);
		grid2.add(stampa);
		//-------------------------------------------------------------------------

		pannello.add(grid1);
		pannello.add(grid2);
		frame.add(pannello);
		frame.setResizable(false);
	}

	public void actionPerformed(ActionEvent e){
		String evento = e.getActionCommand();
		if(evento.equals("inserisci studente")){
			if(controllaFormato(testoMatricola.getText())){
				int matrStudente = daStringAInt(testoMatricola.getText());
				String nomeStudente = testoNome.getText();
				String cognomeStudente = testoCognome.getText();

				if(nomeStudente.equals("") || cognomeStudente.equals("")){
					testoNome.setText("ERRORE! Inserire il nome");
					testoCognome.setText("ERRORE! Inserire il cognome");
				}else{
					Studente s = new Studente(matrStudente, cognomeStudente, nomeStudente);

					studenti.add(s);
					testoMatricola.setText("");
					testoCognome.setText("");
					testoNome.setText("");
				}
			}else{
				testoMatricola.setText("ERRORE!");
			}
		}else if (evento.equals("stampa")){
			studenti.forEach(s -> s.chiSono());
		}
	}

	private boolean controllaFormato(String numero){
		boolean ok = true;

		if(numero.equals("")){
			ok = false;
		}else{
			for(int i = 0; i < numero.length(); i++){
				Character c = numero.charAt(i);
				if(Character.isDigit(c) != true){
					ok = false;
				}
			}
		}

		return ok;
	}

	private int daStringAInt(String numero){
		return Integer.parseInt(numero);
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