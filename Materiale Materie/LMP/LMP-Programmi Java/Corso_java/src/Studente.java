public class Studente extends Persona
{
    String materiaPreferita;


    Studente(String nome, String cognome, String materiaPreferita)
    {
        super(nome, cognome); //super serve per far capire che ci riferiamo agli attributi della classe citata sopra, Persona in questo caso
        this.materiaPreferita = materiaPreferita;
    }

    void studia()
    {
        System.out.println("sto studiando...");
    }

    @Override
    void saluta()
    {
        System.out.println("Buongiorno prof!");
    }
}
