public class Persona
{
    /*
        Sezione 1

        //Questi sono gli attributi:
        String nome = "Damiano";
        String cognome = "Folco";
        int eta = 21;
        String colorePreferito = "Rosso";

        //Questi sono i metodi:
        void saluta()
        {
            System.out.println("Ciao sono " + nome);
        }

        void cammina()
        {
            System.out.println("Sto camminando...");
        }
    */



    //----------------------------------------------------------------------------------------------------------------------------


    /*
       Sezione 2

    */
    String nome; //le variabili fuori dai metodi sono variabili globali
    String cognome;
    int eta;
    String colorePreferito;

    //Qui creo il costruttore che definisce i dati, passati tramite parametri, agli oggetti di tipo Persona che crei in Main.java
    Persona(String nome, String cognome, int eta, String colorePreferito) // quando scrivo new Persona() attivo questo metodo o meglio costruttore con dentro tutti i parametri che devo riempire
    {
        //uso la parola chiave this, in questi casi, per associare i parametri in entrata della funzione ai relativi attributi di Persona
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
        this.colorePreferito = colorePreferito;
    }

    void saluta() //questo è un metodo
    {
        //int prova = 5; - le variabili dentro i metodi sono variabili locali
        System.out.println("ciao sono " + this.nome); //accedo alla variabile globale nome da dentro al metodo senza problemi
    }

    void addizione(int a, int b)
    {
        int ris = a + b; //ho creato una variabile con scope locale ris
        this.stampa(ris); //se passo per parametro la variabile locale al metodo stampa allora funziona
        // il metodo stampa viene richiamato automaticamente in questo caso appena scriviamo persona1.addizione(3, 2)
    }

    void stampa(int num) //parametro passato tramite il metodo addizione
    {
        //System.out.println(ris); //qui la variabile ris non può essere richiamata in quanto ha uno scope locale nel metodo addizione
        System.out.println("parametro passato: " + num); //stampo la variabile locale del metodo addizione
    }

    public String toString()
    {
        String stringa = this.nome + "\n" + this.cognome + "\n" + this.eta + "\n"+ this.colorePreferito;
        return stringa;
    }
}















