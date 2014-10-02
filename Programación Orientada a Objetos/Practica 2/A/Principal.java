public class Principal
{
	public static void main(String args[])
	{
		Punto p, q, r;
		Figura fg[] = new Figura[4];
		
		p = new Punto();
		q = new Punto(10.24, 7.68);
		r = new Punto(19.20, 10.80);
		
		fg[0] = new Figura();
		fg[1] = new Figura(p, 12.80);
		fg[2] = new Figura(p, q);
		fg[3] = new Figura(p, q, r);
		
		for(int k = 0; k < fg.length; k++)
			fg[k].printInfo();
	}
}