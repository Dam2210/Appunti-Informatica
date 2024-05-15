package Pacchetto1;

public class Insegnate2 extends Persona
{

    Insegnate2(String nome, String cognome)
    {
        super(nome, cognome);
    }

    @Override
    public void saluta()
    {
        System.out.println("Buongiorno ragazzi!");
    }
}
