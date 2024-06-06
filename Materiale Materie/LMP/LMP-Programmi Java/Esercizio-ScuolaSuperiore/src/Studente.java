public class Studente
{
    String nome;
    String cognome;
    String data_nascita;
    String luogo_nascita;
    int anno_iscrizione;

    Studente(String nome, String cognome, String data_nascita, String luogo_nascita, int anno_iscrizione)
    {
        this.nome = nome;
        this.cognome = cognome;
        this.data_nascita = data_nascita;
        this.luogo_nascita = luogo_nascita;
        this.anno_iscrizione = anno_iscrizione;
    }

    public String toString()
    {
        String stampa_stud = this.nome + "\n" + this.cognome + "\n" + this.data_nascita + "\n" + this.luogo_nascita + "\n" + this.anno_iscrizione + "\n";
        return stampa_stud;
    }

}
