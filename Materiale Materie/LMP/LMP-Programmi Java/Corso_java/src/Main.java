
import java.util.ArrayList; // con questo comando importo la libreria per le ArryList
import java.util.Scanner; // con questo comando importo la librearia per creare l'ogetto Scanner per l'input da tastiera

public class Main
{
    public static void main(String[] args) {
        // SEZIONE 1

        //System.out.println("Hello World"); //stampo Hello World
        //int x; //dichiaro la variabile intera x
        //x = 45; //assegno ad x il valore 45
        //x = x - 5; //assegno a x il valore della sottrazione 45-5

        //int y = 34; //inizializzo (dichiaro e assegno) y

        //String z = "ciao"; //inizializzo la variabile z assegnandogli la stringa "ciao"

        //double w = 3.7; //inizializzo la variabile w che contiene un numero con la virgola

        //System.out.println(x);
        //System.out.println(y);
        //System.out.println(z);
        //System.out.println(w);


        // -------------------------------------------------------------------------------------------------------


        /*
        SEZIONE 2

        Tipi di dati primitive e reference:

        1. boolean |true : false | 1bit
        2. byte | -128 : 127 | 1 byte
        3. short | -32768 : 32767 | 2 bytes
        4. int | -2 miliardi : 2 miliardi | 4 bytes
        5. long | -9 quintilioni : 9 quintilioni | 8 bytes

        6. float | numero con 6-7 cifre decimali 5.123456f | 4 bytes
        7. double | numero con 15 cifre decimali 5.123456789012345 | 8 bytes

        8. char | singolo carattere/lettera/ASCII 'f' | 2 bytes
        9. String | sequenza di caratteri "ciao sono Damiano" | variabile

        Differenze tra primitive e reference (iniziale e attributi disponibili)
        */

        /*
        boolean IlBoolean = true; //tipo di dato booleano che può essere true o false
        System.out.println(IlBoolean);
        byte IlByte = -128; //oppure fino a 127
        short LoShort = -32768; //oppure fino a 32767
        int IlInt = 2000000000; // oppure fino a - 2000000000
        long IlLong = 1234567898890398489L; //serve la L/l alla fine del numero per il long
        float IlFloat = 5.123456789F; //serve la F/f alla fine del numero per il float
        double IlDouble = 7.13284374738784;
        char IlChar = 'f';
        //Queste sopra sono primitive e non hanno funzioni che si possono utilizzare
        String LaStringa = "ciao sono Damiano"; //String è una reference che ha delle funzioni che possiamo usare (tipo .toUpperCase())
        System.out.println(LaStringa);
        System.out.println(LaStringa.toUpperCase()); //.toUpperCase() è una funzione delle stringe per metterle tutto in maiuscolo
        */


        // ------------------------------------------------------------------------------------------------------------------------------------


        /*
        SEZIONE 3

        in questa sezione stampo a schermo i dati che digita l'utente dopo aver importato la libreria java.util.Scanner all'inizio
        del programma.
        */

        /*
        Scanner scanner = new Scanner(System.in); //qui genero un oggetto di tipo scanner che servirà per gli input da tastiera

        System.out.println("Qual'è il tuo nome?:"); //creo domande per l'utente che vengono visualizzate a schermo
        String nome = scanner.nextLine(); //associa a nome quello che digita l'utente

        System.out.println("Qual'è il tuo cognome?:"); //associa a cognome quello che digita l'utente
        String cognome = scanner.nextLine();

        System.out.println("Qual'è la tua età?:");
        int eta = scanner.nextInt(); //associa a età quello che digita l'utente (usare nextInt invece che nextLine)
        scanner.nextLine(); //nextInt non manda a capo e quindi il programma finisce senza farci inserire la città, aggiungendo nextLine risolviamo il problema

        System.out.println("Qual'è il tua città?:");
        String city = scanner.nextLine(); //associa a city quello che digita l'utente

        System.out.println("Ciao " + nome + " " + cognome); //stampo una concatenazione
        System.out.println("Hai " + eta + " anni " + "e vivi a " + city);
        */


        // -----------------------------------------------------------------------------------------------------------------


        /*
            SEZIONE 4

            in questa sezione vediamo:

            operatori aritmetici: + - / * %
            shorthand
            incremento e decremento
            esempi di espressioni
        */

        /*
        int x =  10;
        int y = 3;
        int z = 0;

        int add = x + y;
        System.out.println(add);

        int sott = x - y;
        System.out.println(sott);

        int mol = x * y;
        System.out.println(mol);

        int div = x / y;
        System.out.println(div);

        int resto = x % y; // % = modulo cioè il resto della divisione
        System.out.println(resto);

        x = x + 3; //aggiungo ad x 3 quindi 10 + 3 = 13
        System.out.println("x: " + x);

        x += 3; //fa la stessa cosa di prima quindi se ho aggiunto 3 abbiamo 13 + 3 = 16 questa è la shorthand e vale anche per tutti gli operatori: + - * / %
        System.out.println("x: " + x);

        x++; //con questo x++ incremento di uno la variabile x
        System.out.println("x incrementata: " + x);

        x--; //con questo x-- decremento di uno x
        System.out.println("x decrementata: " + x);

        x = 11;

        int ris_espressione = ((y + x) * y + (4 - 2)) * z; //questo è il risultato di un espressione
        System.out.println("risultato espressione: " + ris_espressione);
        */


        // -------------------------------------------------------------------------------------------------------


        /*
        SEZIONE 5

        in questa sezione vediamo la classe math e alcune sue funzioni come:
         - abs
         - min
         - max
         - pow
         - sqrt

         attributi: PI
        */
        /*
        System.out.println(Math.abs(-55)); // Math.abs da il valore assoluto di un numero.
        System.out.println(Math.min(55, 21)); //Math.min trova il minimo tra due valori.
        System.out.println(Math.max(55, 21)); //Math.max trova il massimo tra due valori
        System.out.println(Math.pow(5, 2)); //Math.pow fa la potenza del primo valore elevato al secondo valore, in questo caso 5 alla 2a
        System.out.println(Math.sqrt(25)); //Math.sqrt fa la radice quadrata del numero tra le parentesi.
        System.out.println(Math.PI); // Math.PI prende il pi greco
        */


        //-------------------------------------------------------------------------------------------------------------------------------------------


        /*
         SEZIONE 6

         Operatori di comparazione:
         >
         >=
         <
         <=
         ==
         !=
        */
        /*
        int x = 10;
        int y = 21;
        boolean ris1 = x > y;

        System.out.println("ris1: " + x + " > "+ y + ": " + ris1);

        boolean ris2 = 10 >= 10;
        System.out.println("ris2: 10 >= 10: " + ris2);

        boolean ris3 = 9 < 10;
        System.out.println("ris3: 9 < 10: " + ris3);

        boolean ris4 = 10 <= 10;
        System.out.println("ris4: 10 <=  10: " + ris4);

        boolean ris5 = 10 == 10;
        System.out.println("ris5: 10 è uguale (==) a 10: " + ris5);

        boolean ris6 = ris2 == ris3;
        System.out.println("ris6: ris2 è uguale (==) a ris3: " + ris6);

        boolean ris7 = ris1 != ris3;
        System.out.println("ris7: ris1 è diverso (!=) da ris3: " + ris7);

        boolean ris8 = 5 != 5;
        System.out.println("ris8: 5 è diverso (!=) da 3: " + ris8);
        */


        //---------------------------------------------------------------------------------------------------------------------


        /*
        SEZIONE 7

        Operatori Logici: AND(&&), OR(||), NOT(!)
        */
        /*
        boolean x = (3 < 10) && (6 % 2 == 0) && (3 != 20); // con l'AND (&&) verifichiamo se sono vere tutte le condizioni (contemporaneamente)
        System.out.println(x);

        boolean y = (3 > 10) || (6 % 2 == 0) || (20 != 20); // con l'OR (||) verifichiamo se è vera almeno una delle condizioni
        System.out.println(y);

        System.out.println(!y); // il NOT(!) nega un risultato se prima era true ora è false

        boolean z = !(3 < 10 && 3 % 2 == 0) || (5 < 10 && 5 % 2 == 0); // gli operatori possono essere utilizzati insieme
        System.out.println(z);
        */


        //----------------------------------------------------------------------------------------------------------------------------------------------------


        /*
         SEZIONE 8

         Condizioni con IF:
         - IF
         - ELSE
         - ELSE IF
         - IF annidati
         - ternary operator
        */
        /*
        if(3 < 10) //se 3 è minore di 10
        {
            System.out.println("vero");
        }

        boolean isOnline = false;

        if(isOnline) //se isOnline è true (!isOnline = se isOnline è false)
        {
            System.out.println("é online");
        }
        else //altrimenti fai questo
        {
            System.out.println("é offline");
        }

        String nome = "Damiano";

        if(nome == "Damiano")
        {
            System.out.println("il nome è: " + nome);
        }
        else if (nome == "Marco")
        {
            System.out.println("il nome è: " + nome);
        }
        else
        {
            System.out.println("il nome non è ne Damiano ne Marco");
        }

        int num = 11;

        if(num < 10) //può essere sostituito con if((num < 10) && (num % 2 = 0)) senza usare if annidati
        {
            System.out.println(num + " è minore di 10");
            if(num % 2 == 0)
            {
                System.out.println(num + " è anche pari");
            }
            else
            {
                System.out.println(num + " è anche dispari");
            }
        }
        else
        {
            System.out.println(num + " è maggiore di 10");
        }

        System.out.println("----------------------------------------------------------------");

        String x = num < 10 ? num + " si è minore di 10" : num + " no non è minore di 10";
        //Questo è il ternary operator, un modo per fare un if veloce e semplice, assegnare il tipo dell'output alla variabile x
        //in questo caso x è String, poi esegue la domanda posta e assegna ad x il valore del ramo true (cioè "si è minore di 10")
        //oppure del ramo false (cioè "no non è minore di 10").

        System.out.println(x);
        */


        //---------------------------------------------------------------------------------------------------------


        /*
        SEZIONE 9

        SWITCH
        */
        /*
        String nome = "Damiano";

        switch (nome) //lo switch funziona su per giù come un if solo che ha vari casi ed è più efficiente con condizioni simili
        {
            case "Damiano": //se il nome è Damiano
                System.out.println("ciao Damiano <3");
                break; //fondamentale per uscire dallo switch e quindi dal caso scelto. Metterlo sempre.
            case "Marco": //se il nome è Marco
                System.out.println("ciao Marco :)");
                break;
            case "Anna": //se il nome è Anna
                System.out.println("ciao Anna ;)");
                break;
            case "Simone": //se il nome è Simone
                System.out.println("ciao Simone :3");
                break;
            case "Edoardo": //se il nome è Edoardo
                System.out.println("ciao Edoardo :/");
                break;
            default: //caso di default che funziona con nomi diversi dai vari casi
                System.out.println("ciao chiunque tu sia :()");
        }
        */


        //-------------------------------------------------------------------------------------------------------------


        /*
        SEZIONE 10

        Ciclo While:
        - Cos'è un ciclo
        - A cosa serve un ciclo
        - Ciclo While
        - Ciclo Do While
        */
        /*
        int i = 0;
        while(i < 5) //nel While se è verificata la condizione si entra nel ciclo altrimenti no
        {

            System.out.println("i:" + i);
            i++;
        }

        int c = 0;

        do //nel DoWhile si entra almeno una volta nel ciclo, viene eseguito prima il do e poi la condizione nel while
        {
            System.out.println("c:" + c);
            c++;
        }
        while(c < 5);
        */


        //-------------------------------------------------------------------------------------------------------------------------------


        /*
        SEZIONE 11

        Ciclo For:
        - Ciclo For
        - For annidati
        - versione enhanced/foreach
        - break e continue
        */
        /*
        for(int i = 0; i < 5; i++)
        {
            System.out.println("i:" + i);
            for(int j = 0; j < 5; j++)
            {
                System.out.println("j:" + j);
            }
        }

        System.out.println("-----------------------------------------------------------------------------------------------------------");

        int[] numeri = {10, 20, 30, 40, 50}; //questo è un  array

        int c = 0;
        for(int num : numeri) //for versione enhanced/foreach
        {
            c++;
            System.out.println(num + " - contatore di numeri:" + c);
        }

        System.out.println("-----------------------------------------------------------------------------------------------------------");

        for(int t = 0; t < 7; t++)
        {
            if(t == 3)
            {
                continue; //quando t diventa 3 salta il passaggio e passa a t = 4
            }

            if(t == 6)
            {
                break; //quando t diventa 6 il ciclo si interrompe ed esce.
            }
            System.out.println("il valore di t è:" + t);
        }
        */


        //-----------------------------------------------------------------------------------------------------------------------------


        /*
        SEZIONE 12

        Array:
        - Cosa sono gli Array
        - Creare un array vuoto
        - Associare elementi all'array
        - Array.tostring
        - lunghezza array
        - modificare elementi
        - mostrare elementi
        - ciclare array con for e foreach
        */

        /*
        int x = 3; //numero utilizzato per la lunghezza dell'array
        int[] numeri = new int[x]; //ho creato un array vuoto di lunghezza 3

        numeri[0] = 10; //metto in posizione 0 dell'array il numero 10
        numeri[1] = 20; //metto in posizione 1 dell'array il numero 20
        numeri[2] = 30; //metto in posizione 2 dell'array il numero 30

        System.out.println("Questo è l'array numeri");
        for(int i = 0; i < numeri.length; i++) //utilizzo un for che non supera la lunghezza dell'array
        {
            System.out.println("posizione " + i + " dell'array: " + numeri[i]); //stampo i numeri dell'array con la corrispondente posizione
        }

        System.out.println("la lunghezza dell'array è: " + numeri.length); // .lenght è la funzione che restituisce la lunghezza di un array

        System.out.println("-------------------------------------------------------------------------------------");

        numeri[1] = 100; //assegno alla posizione 1 dell'array 100, dove prima c'era 20
        numeri[2] = 1000; //assegno alla posizione 2 dell'array 1000, dove prima c'era 30

        System.out.println("il nuovo array è:");
        for(int i = 0; i < numeri.length; i++) //utilizzo un for che non supera la lunghezza dell'array
        {
            System.out.println("posizione " + i + " del nuovo array: " + numeri[i]); //stampo i numeri del nuovo array con la corrispondente posizione
        }

        System.out.println("-------------------------------------------------------------------------------------");
        int[] numeri2 = {2, 4, 6, 8, 10}; //questo è un altro modo per inizializzare un array e riempirlo di elementi senza specificare la lunghezza
        System.out.println("l'ultimo elemento del secondo array è: " + numeri2[numeri2.length - 1]); //con numeri2[numeri2.lenght - 1] prendo l'ultimo elemento dell'array numeri2
        System.out.println("lunghezza del secondo array: " + numeri2.length);
        System.out.println(" ");

        System.out.println("Questo è l'array numeri2:");
        for(int i = 0; i < numeri2.length; i++)
        {
            System.out.println("in posizione " + i + " dell'array numeri2 abbiamo: " + numeri2[i]);
        }

        System.out.println(" ");

        System.out.println("Questo è l'array numeri2 stampato con foreach:");

        int c = 0;
        for(int num : numeri2) //uso il for in versione foreach che è più semplice per stampare i numeri nell'array numeri2
        {
            System.out.println("in posizione " + c + " dell'array numeri2 abbiamo: " + num);
            c++;
        }
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 13

         Array 2D:
         - Cosa sono gli array 2D
         - Creare un array 2D in entrambi i modi
         - accedere agli elementi dell'array
         - ciclare con cicli for
        */
        /*
        String[][] classi = new String[3][3]; //creo un array a due dimensioni con nome classi. ci sono 3 classi e ogni classe ha 3 persone

        //prima classe
        classi[0][0] = "Alessio"; //primo elemento della prima classe
        classi[0][1] = "Anna"; //secondo elemento della prima classe
        classi[0][2] = "Armando"; //terzo elemento della prima classe

        //seconda classe
        classi[1][0] = "Benedetto"; //primo elemento della seconda classe
        classi[1][1] = "Barbara"; //secondo elemento della seconda classe
        classi[1][2] = "Bartolomeo"; //terzo elemento della seconda classe

        //terza classe
        classi[2][0] = "Damiano"; //primo elemento della terza classe
        classi[2][1] = "Daniela"; //secondo elemento della terza classe
        classi[2][2] = "Davide"; //terzo elemento della terza classe

        for(int i = 0; i < classi.length; i++) //contatore per le righe di classi
        {
            System.out.println("classe " + i + ":" );
            for(int j = 0; j < classi[i].length; j++) //contatore per le colonne di classi
            {
                System.out.println(i + " " + j + " - " + classi[i][j]);
            }
            System.out.println(" ");
        }

        System.out.println("----------------------------------------------------- Stampa a matrice ---------------------------------------------------------------------------");
        System.out.println(" ");

        for(int i = 0; i < classi.length; i++) //contatore per le righe di classi
        {
            System.out.print("classe "+ i + " ---> ");
            for(int j = 0; j < classi[i].length; j++) //contatore per le colonne di classi
            {
                System.out.print(classi[i][j] + " ");
            }
            System.out.println(" ");
        }

        //creo un array a 2 dimensioni in un altro modo

        String nomi[][] =
                {
                        {"A", "B", "C"},
                        {"D", "E", "F"},
                        {"G", "H", "I"},
                };

        System.out.println("------------------------------------------ Array nomi -----------------------------------------------------------------");
        for(int i = 0; i < nomi.length; i++) //contatore per le righe di classi
        {
            System.out.print("riga "+ i + " ---> ");
            for(int j = 0; j < nomi[i].length; j++) //contatore per le colonne di classi
            {
                System.out.print(nomi[i][j] + " ");
            }
            System.out.println(" ");
        }

        System.out.println("------------------------------------------ Array classi con foreach-----------------------------------------------------------------");

        for(String[] classe : classi)
        {

            for(String studente : classe)
            {
                System.out.print(studente + " ");
            }
            System.out.println();
        }
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 14

         Metodi Stringhe:
         - equals, equalsIgnoreCase, lenght, charAt
         - indexOf, isEmpty, toUpperCase, toLowerCase
         - trim, replace
        */
        /*
        String nome = "Damiano";

        boolean ris0 = nome.equals("Damiano"); // .equals restituisce true o false in base al valore messo nelle parentesi, confronta il valore della variabile con quello tra le parentesi e vede se sono uguali
        System.out.println(".equals = " + ris0); // .equals è case sensitive

        boolean ris1 = nome.equalsIgnoreCase("DamIano"); // .equalsIgnoreCase funziona come .equals ma non è case sensitive
        System.out.println(".equalsIgnoreCase = " + ris1);

        int ris2 = nome.length(); // .lenght restituisce la lunghezza della variabile
        System.out.println("la lunghezza del nome " + nome + " è: " + ris2);

        int x = 3; // posizione messa tra le parentesi
        char ris3 = nome.charAt(x); // .charAt restituisce il carattere della stringa nella posizione messa tra le parentesi
        System.out.println("il carattere in posizione " + x + " è: " + ris3);

        char carattere = 'm';
        int ris4 = nome.indexOf(carattere); // .indexOf restituisce la posizone del carattere messo tra le parentesi nella stringa
        System.out.println("la posizione del carattere " + carattere + " nel nome " + nome + " è: " + ris4);

        String nome2 = "";
        boolean ris5 = nome2.isEmpty(); // .isEmpty verifica se la stringa è vuota o meno("")
        System.out.println("il nome è vuoto?: " + ris5);

        String ris6 = nome.toUpperCase(); // .toUpperCase rende la stringa con caratteri tutti maiuscoli
        System.out.println("nome tutto in maiuscolo: " + ris6);

        String ris7 = nome.toLowerCase(); // .toLowerCase rende la stringa con caratteri tutti minuscoli
        System.out.println("nome tutto in minuscolo: " + ris7);

        String nome3 = "                        ciao sono Damiano                                ";
        String ris8 = nome3.trim(); // .trim elimina gli spazi all'inizio e alla fine della stringa
        System.out.println("stringa senza spazi: " + ris8);

        String ris9 = nome.replace('a', 'b'); // .replace sostituisce le occorrenze di un carattere con un altro.
        System.out.println("nome con le b al posto delle a: " + ris9);
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 15

        Wrapper Class
        - le Wrapper class permettono di utilizzare dati primitivi come reference
        - boolean ---> Boolean
        - char ---> Character
        - int ---> Integer
        - double ---> Double

       attraverso questi dati che sono diventati reference possiamo usare delle funzioni e dei metodi che prima con le primitive
       non potevamo usare (es: .lenght)
       */
        /*
        Boolean vero = true;
        Character carattere = 'a';
        Integer numero = 5;
        Double virgola = 5.23;
        String stringa = "ciao a tutti";

        boolean a = true;
        char b = 'a';
        int c = 5;
        double d = 5.23;

        if(virgola == d)
        {
            System.out.println("Si, uguali");
        }
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 16

         ArrayList
         - Le ArrayList sono array ridimensionabili, accettano però solo reference (Wrapper Class)
         - Creare un ArrayList
         - Aggiungere elementi add()
         - Mandare a schermo elementi get()
         - Modificare elementi set()
         - Rimuovere elementi remove(), clear()
         - ArrayList 2D
        */
        /*
        ArrayList<String> persone = new ArrayList<String>(); //creo l'oggetto ArrayList vuoto con nome persone e con elementi di tipo stringa al suo interno

        persone.add("Damiano"); //aggiungo elementi all'ArrayList
        persone.add("Marco");
        persone.add("Anna");

        System.out.println(persone.get(1)); //con .get(1) prendo l'elemento in posizione 1 nell'ArrayList in questo caso sarà Marco

        System.out.println("-----------------------------ArrayList con Simone al posto di Marco-----------------------------------------");

        persone.set(1, "Simone"); //modifico l'elemento nella posizione 1 (cioè Marco) con il nome Simone

        for (int i = 0; i < persone.size(); i++) // .size è il metodo delle ArrayList che funziona come .lenght e serve per sarpere la lunghezza dell'ArrayList
        {
            System.out.println(i + ": " + persone.get(i)); //stampo tutti gli elementi nell'ArrayList
        }

        persone.remove(1); //rimuovo l'elemento nella posizione 1 nell'ArrayList

        System.out.println("------------------------------ArrayList senza Simone----------------------------------------");

        for (int i = 0; i < persone.size(); i++) // .size è il metodo delle ArrayList che funziona come .lenght e serve per sarpere la lunghezza dell'ArrayList
        {
            System.out.println(i + ": " + persone.get(i)); //stampo tutti gli elementi nell'ArrayList
        }

        System.out.println("------------------------------ArrayList con Input----------------------------------------");

        persone.clear(); //rimuovo tutti gli elementi nell'ArrayList

        for (int i = 0; i < persone.size(); i++) // .size è il metodo delle ArrayList che funziona come .lenght e serve per sarpere la lunghezza dell'ArrayList
        {
            System.out.println(i + ": " + persone.get(i)); //stampo tutti gli elementi nell'ArrayList
        }

        ArrayList<Integer> num = new ArrayList<Integer>(); //Per l'ArrayList num utilizzo la Wrapper Class Integer, con le primitive come int, char ecc non funziona

        Scanner scanner = new Scanner(System.in); //oggetto per far inserire all'utente i dati

        for (int i = 0; i < 4; i++) {
            System.out.println("inserisci un numero nell'ArrayList: ");
            int numero = scanner.nextInt(); //input dell'utente
            scanner.nextLine(); //linea necessaria per passare al prossimo intero
            num.add(numero); //aggiungo all'ArrayList num il numero inserito dall'utente
        }

        System.out.println("------------------------------ArrayList num riempito con i dati dell'utente----------------------------------------");

        for (int i = 0; i < num.size(); i++) {
            System.out.println(i + ": " + num.get(i)); // stampo i numeri inseriti dall'utente
        }

        System.out.println("------------------------------ArrayList 2D----------------------------------------");

        ArrayList<ArrayList<String>> classi = new ArrayList<ArrayList<String>>(); // Creo ArrayList 2D

        ArrayList<String> classe1 = new ArrayList<String>();
        classe1.add("Damiano");
        classe1.add("Marco");

        ArrayList<String> classe2 = new ArrayList<String>();
        classe2.add("Silvia");
        classe2.add("Dalila");

        classi.add(classe1); //aggiungo all'ArrayList classi l'ArrayList classe1
        classi.add(classe2); //aggiungo all'ArrayList classi l'ArrayList classe2

        System.out.println("ArrayList classi 2D con classe1 e classe2 al suo interno:");

        for(int i = 0; i < classi.size(); i++)
        {
            System.out.println();
            for(int j = 0; j < classi.get(i).size(); j++)
            {
                System.out.print(classi.get(i).get(j) + " ");
            }
        }
        System.out.println();
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 17

         Metodi
         - Cosa sono i metodi
         - Creiamo un semplice metodo void
         - Parametri dei metodi
         - il return
        */
        /*
        faiPasta();

        cucinaPietanza("carne");

        Add(3, 5);

        int totale = Add2(7, 2);

        System.out.println("il totale è: " + totale);
    } //fine main

    static void faiPasta() //il metodo deve stare fuori dal main che a sua volta è un metodo, void si usa nelle funzioni che non ritoranano valori di nessun tipo
    {
        System.out.println("Sto cucinando pasta");
    }

    static void cucinaPietanza(String cibo) //cibo è l'argomento del metodo e in questo caso è di tipo stringa, lo dovrò passare nelle parentesi quando richiamerò il metodo
    {
        System.out.println("sto cucinando " + cibo);
    }

    static void Add(int a, int b)
    {
        int add = a + b;
        System.out.println("l'addizione tra " + a + " e " + b + " è: " + add);
    }

    static int Add2(int a, int b) //con int al posto di void dichiaro che questa funzione ritorna un int
    {
        int add = a + b;
        return add; //ritorno il valore che sta in add
    }
    */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 18

         Overloads Methods
         - Cosa sono: stesso metodo ripetuto più volte ma con un diverso tipo o con diversi argomenti (parametri)
         - Creiamo diversi metodi con num param differenti
         - Creiamo diversi metodi con tipi dato differenti
        */
        /*
        //viene richiamato 3 volte il metodo add() solo con parametri diversi (signature) e quindi corrispondono tutte a un metodo diverso.
        int doppioInt = add(2, 3);
        int triploInt = add(5, 10, 9);
        double doppioDouble = add(2.5, 6.3);

        System.out.println("doppioInt: " + doppioInt);
        System.out.println("triploInt: " + triploInt);
        System.out.println("doppioDouble: " + doppioDouble);

    } // fine main

    static int add(int a, int b) //con int al posto di void dichiaro che questa funzione ritorna un int
    {
        int ris = a + b;
        return ris; //ritorno il valore che sta in ris
    }

    static int add(int a, int b, int c) //con int al posto di void dichiaro che questa funzione ritorna un int
    {
        int ris = a + b + c;
        return ris; //ritorno il valore che sta in ris
    }

    static double add(double a, double b) //con int al posto di void dichiaro che questa funzione ritorna un int
    {
        double ris = a + b;
        return ris; //ritorno il valore che sta in ris
    }
    */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 19

         Introduzione Object Oriented Programming(OOP)
         - Cos'è la programmazione ad oggetti
         - Classi, metodi e attributi
         - Classe con file esterno
         - Cosa sono gli oggetti e le istanze di classe
         - Usare attributi e metodi
        //vedi la classe Persona.java
        //USO LA SEZIONE 1 DELLA CLASSE Persona.java, CHE HO CREATO, IN QUESTA SEZIONE
        */
        /*
        Persona persona1 = new Persona(); //creo l'ggetto persona1 di tipo Persona cioè la classe che ho creato in precedenza
        Persona persona2 = new Persona(); //questa persona2 sarà una copia di persona1 in quanto utilizza attributi e metodi della stessa classe cioè Persona
        //persona1 e persona2 sono due oggetti distinti anche se utilizzano la stessa classe con gli stessi metodi e attributi

        System.out.println("nome persona1: " + persona1.nome);
        System.out.println("nome persona2: " + persona2.nome);
        persona1.saluta();
        persona2.cammina();
        */



        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 20

         Costruttori
         - Cos'è un costruttore
         - Creiamone uno
         - Parola chiave 'this'
         //vedi Persona.java
         //Tutte queste cose le trovi aggiunte e spiegate sulla classe Persona.java
        */
        /*
        Persona persona1 = new Persona("Damiano", "Folco", 21, "Rosso"); //valori tra parentesi passati tramite costruttore
        Persona persona2 = new Persona("Mario", "Rossi", 20, "Giallo");

        System.out.println("----- persona1 -----");
        System.out.println("nome - " + persona1.nome);
        System.out.println("cognome - " + persona1.cognome);
        System.out.println("eta - " + persona1.eta);
        System.out.println("colorePreferito - " + persona1.colorePreferito);
        System.out.println();

        System.out.println("----- persona2 -----");
        System.out.println("nome - " + persona2.nome);
        System.out.println("cognome - " + persona2.cognome);
        System.out.println("eta - " + persona2.eta);
        System.out.println("colorePreferito - " + persona2.colorePreferito);
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 21

         Scope delle variabili
         - Cos'è lo scope di una variabile - raggio d'azione in cui una variabile è disponibile nel codice
         - Scope locale
         - Scope globale
         //tutto spiegato nella classe Persona.Java
        */
        /*
        Persona persona1 = new Persona("Damiano", "Folco", 21, "Rosso");

        persona1.saluta();
        persona1.addizione(2, 3);
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 21

         Overloaded Constructors
         - Cosa sono?
         - Creare class pizza
         - Creare multipli costruttori
         //vedi la classe Pizza.java
         //creo la classe Pizza.java in cui ho più costruttori con lo stesso nome ma con parametri diversi che li differenziano (Overloaded Constructors)
        */
        /*
        Pizza pizza1 = new Pizza("integrale", "pomodoro", "mozzarella", "ananas");
        Pizza pizza2 = new Pizza("5 cereali");
        Pizza pizza3 = new Pizza("normale", "pomodoro", "mozzarella");
        */


        //----------------------------------------------------------------------------------------------------------------------------


        /*
         Sezione 22
        */

    }
}









