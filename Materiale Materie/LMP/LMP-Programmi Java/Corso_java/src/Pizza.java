public class Pizza
{
    String impasto;
    String salsa;
    String formaggio;
    String extra;
    String extra2;

    //ho più costruttori con lo stesso nome ma con parametri diversi che li differenziano (Overloaded Constructors)

    //gli Overloaded Constructors sono costruttori con lo stesso nome (Pizza in questo caso) ma che vengono chiamati in base al tipo di parametro che viene messo tra le parentesi

    Pizza(String impasto)
    {
        this.impasto = impasto;
        System.out.println("ingredienti: " + impasto);
    }

    Pizza(String impasto, String salsa)
    {
        this.impasto = impasto;
        this.salsa = salsa;
        System.out.println("ingredienti: " + impasto + ", " + salsa);
    }

    Pizza(String impasto, String salsa, String formaggio)
    {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
        System.out.println("ingredienti: " + impasto+ ", " + salsa + ", " + formaggio);
    }

    Pizza(String impasto, String salsa, String formaggio, String extra)
    {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
        this.extra = extra;
        System.out.println("ingredienti: " + impasto+ ", " + salsa + ", " + formaggio + ", " + extra);
    }

    Pizza(String impasto, String salsa, String formaggio, String extra, String extra2)
    {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
        this.extra = extra;
        this.extra2 = extra2;
        System.out.println("ingredienti: " + impasto+ ", " + salsa + ", " + formaggio + ", " + extra + ", " + extra2);
    }
}
