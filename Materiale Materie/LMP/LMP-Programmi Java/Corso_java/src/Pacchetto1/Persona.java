package Pacchetto1;

public class Persona
{
    private String nome;
    private String cognome;

    Persona(String nome, String cognome)
    {
        this.nome = nome;
        this.cognome = cognome;
        //this.setNome(nome); //posso anche usare il metodo setters
        //this.setCognome(cognome); //posso anche usare il metodo setters
    }

    public String getNome() //metodo getters per nome
    {
        return nome;
    }

    public String getCognome() //metodo getters per cognome
    {
        return cognome;
    }

    public void setNome(String nome) //metodo setters per nome
    {
        this.nome = nome;
    }

    public void setCognome(String cognome) //metodo setters per nome
    {
        this.cognome = cognome;
    }

    public void copy(Persona persona) //creo un metodo per copiare l'oggetto persona in una casella di memoria diverso
    {
        this.setNome(persona.getNome());
        this.setCognome(persona.getCognome());
    }

    Persona(Persona persona)
    {
        this.copy(persona);
    }

    public void saluta()
    {
        System.out.println("Ciao");
    }
}
