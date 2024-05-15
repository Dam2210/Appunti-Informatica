package Pacchetto1;

public class Studente2 extends Persona
{
    Studente2(String nome, String cognome)
    {
        super(nome, cognome);
    }

    @Override
    public void saluta()
    {
        System.out.println("Buongiorno prof!");
    }
}
