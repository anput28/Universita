public class Orario{
	private String ora;

	public Orario(String ora) throws FormatoOrarioException{
		if(checkFormato(ora)){
			this.ora = ora;
		}
	}

	private boolean checkFormato(String ora) throws FormatoOrarioException{
		boolean ok = false;

		if(ora.length() == 5){
			if((Character.isDigit(ora.charAt(0))) && (Character.isDigit(ora.charAt(1))) && (Character.isDigit(ora.charAt(3))) && (Character.isDigit(ora.charAt(4)))){
				if(ora.charAt(2) == ':'){
					if(checkOrarioReale(ora)){
						ok = true;
					}else{
						throw new FormatoOrarioException(ora);
					}
				}else{
					throw new FormatoOrarioException(ora);
				}
			}else{
				throw new FormatoOrarioException(ora);
			}
		}else{
			throw new FormatoOrarioException(ora);
		}

		return ok;
	}

	private boolean checkOrarioReale(String ora){
		boolean ok = false;
		Integer n[] = new Integer[2];
		n = oreMinuti(ora);

		if(n[0] >= 0 && n[0] < 24 && n[1] >= 0 && n[1] < 60){
			ok = true;
		}

		return ok;
	}

	private Integer[] oreMinuti(String ora){
		String numeri[] = new String[2];
		numeri = ora.split(":");
		Integer n[] = new Integer[2];
		n[0] = new Integer(Integer.parseInt(numeri[0]));
		n[1] = new Integer(Integer.parseInt(numeri[1]));

		return n;
	}

	public String converti12(String ora){
		String ore, minuti;
		String momento;

		Integer num[] = new Integer[2];
		num = oreMinuti(ora);

		if(num[0] <= 12){
			ore = num[0].toString();
			momento = "AM";
		}else{
			num[0] -= 12;
			ore = num[0].toString();
			momento = "PM";
		}

		minuti = num[1].toString();

		return ore+" : "+minuti+" "+momento;
	}


}