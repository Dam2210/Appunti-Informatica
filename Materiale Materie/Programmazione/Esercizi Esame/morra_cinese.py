import random

print("Ciao, oggi giochiamo a morra cinese")

computer = random.randint(0,2)

if computer == 0: 
    computer = "s"
elif computer == 1: 
    computer = "f"
else: 
    computer = "c"

utente = input("Inserisci c per carta, s per sasso ed f per forbice: ")

if utente != "s" and utente != "f" and utente != "c":
    print("La lettera non corrisponde a nulla")
elif utente == computer:
    print("computer:", computer, "-", "utente:", utente)
    print("parità!")
elif utente == "s" and computer == "f" or utente == "f" and computer == "c" or utente == "c" and computer == "s":
    print("computer:", computer, "-", "utente:", utente)
    print("Hai vinto!")
else:
    print("computer:", computer, "-", "utente:", utente)
    print("Ha vinto il computer!")