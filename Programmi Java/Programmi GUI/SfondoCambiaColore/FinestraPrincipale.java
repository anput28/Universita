import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import javax.swing.WindowConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;
import java.awt.Container;

public class FinestraPrincipale extends JFrame implements ActionListener{
	public static final int LARGHEZZA = 800;
	public static final int LUNGHEZZA = 500;

	public FinestraPrincipale(){
		setTitle("Finestra Principale");
		setSize(LARGHEZZA, LUNGHEZZA);
		setLayout(new BorderLayout());

		setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
		addWindowListener(new GestoreEventiPrincipale());

		JPanel pannello1 = new JPanel();
		pannello1.setLayout(new FlowLayout());

		JButton b1 = new JButton("Rosso");
		b1.addActionListener(this);
		pannello1.add(b1);

		JButton b2 = new JButton("Blue");
		b2.addActionListener(this);
		pannello1.add(b2);

		add(pannello1, "South");
	}

	public void actionPerformed(ActionEvent e){
		Container c = getContentPane();
		if(e.getActionCommand().equals("Rosso")){
			c.setBackground(Color.RED);
		}else if(e.getActionCommand().equals("Blue")){
			c.setBackground(Color.BLUE);
		}
	}

}