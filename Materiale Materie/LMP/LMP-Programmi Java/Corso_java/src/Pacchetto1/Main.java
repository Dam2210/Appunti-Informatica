package Pacchetto1;
import Pacchetto2.*;

public class Main
{
    public static void main(String[] args)
    {
        /*
         Sezione 28
         Modificatori di accesso
         - i modificatori di accesso servono per aggiungere un livello di sicurezza aggiuntivo
         - creare 2 package con 2 classi

                       class  package  subclass  world
         public         si      si      si         si  --> vedi la classe B nel Pacchetto2
         protected      si      si      si         no  --> vedi la classe A nel Pacchetto1
         default        si      si      no         no  --> vedi la classe B nel Pacchetto2
         private        si      no      no         no  --> vedi la classe A nel Pacchetto1
        */
        /*
        B prova = new B();
        System.out.println(prova.nome1);
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 29
         Incapsulamento/Encapsulation
         Incapsulamento = processo in cui nascondiamo attributi di una classe all'esterno mettendoli private
                          diventano accessibili solo tramite dei metodi (getters/setters)
         Creiamo classe Persona
         aggiungiamo attributi private
         definiamo getters e setters nella classe Persona
        */
        /*
        Persona persona1 = new Persona("Damiano", "Folco");
        System.out.println(persona1.getNome() +  " " + persona1.getCognome()); //uso il metodo getters per mandare a schermo

        persona1.setNome("Anna"); //cambio nome a persona1 tramite il metodo setters
        System.out.println(persona1.getNome()); //uso il metodo getters per mandare a schermo

        persona1.setCognome("Neri"); //cambio cognome a persona1 tramite il metodo setters
        System.out.println(persona1.getCognome()); //uso il metodo getters per mandare a schermo
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 30
         Copiare oggetti
         - Tramite metodo
         - Tramite costruttore
        */
        /*
        Persona persona1 = new Persona("Damiano", "Folco");
        //Persona persona2 = new Persona("Anna", "Neri");
        Persona persona2 = new Persona(persona1); //con questo copio la persona1 in persona2 tramite il metodo nella classe Persona

        //persona2 = persona1; //questa non è una copia ma due oggetti che puntano agli stessi dati

        //persona2.copy(persona1); //con questo posso copiare in persona2 persona1

        System.out.println(persona1); //manda a schermo la cella di memoria occupata dall'oggetto persona1
        System.out.println(persona2); //manda a schermo la cella di memoria occupata dall'oggetto persona2
        System.out.println();
        System.out.println(persona1.getNome());
        System.out.println(persona1.getCognome());
        System.out.println();
        System.out.println(persona2.getNome());
        System.out.println(persona2.getCognome());
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 31
         Interfacce: simile ad una classe astratta ma aggiunge funzionalità extra alle classi create
         Creo 3 nuove classi: Leone, Pesce e Gazzella
         Creo inoltre 2 interfacce: Preda e Predatore
         vedi tutti questi nuovi elementi per i chiarimenti su cosa fanno
        */

        Leone leone = new Leone();
        Gazzella gazzella = new Gazzella();
        Pesce pesceGrosso = new Pesce();
        Pesce pescePiccolo = new Pesce();

        leone.caccia();
        gazzella.scappa();
        pesceGrosso.caccia();
        pescePiccolo.scappa();


    }
}
