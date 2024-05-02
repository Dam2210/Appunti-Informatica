public class Insegnante extends Persona
{
    String materia;

    Insegnante(String nome, String cognome, String materia)
    {
        super(nome, cognome); //super serve per far capire che ci riferiamo agli attributi della classe citata sopra, Persona in questo caso
        this.materia = materia;
    }

    void insegna()
    {
        System.out.println("sto insegnando...");
    }

    @Override
    void saluta()
    {
        System.out.println("Buongiorno ragazzi!");
    }
}
