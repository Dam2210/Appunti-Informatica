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

        B prova = new B();
        System.out.println(prova.nome1);

    }
}
