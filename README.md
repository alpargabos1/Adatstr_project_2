ADATSTRUKTÚRA 2. PROJEKT
(Imets Boldizsár) | Gábos Alpár | Kőműves Dávid-Márk

Egy autószerelő műhely foglalásrendszerét foglalja magába a program. Egy hónap bármelyik napján be tud a műhely fogadni négy autót, a felhasználóknak van esélyük a legközelebbi dátumra helyezni a foglalást, vagy egy kiválasztott dátumra, abban az esetben, hogyha még vannak helyek aznap. Az admin szerep arra szolgál, hogy minden foglalást megnézhessen a műhelyben dolgozó csapat bármely tagja, kitörölhessenek olyan napokat, amelyeken nem dolgoznak, illetve arra, hogy egymásnak új fiókokat készíthessenek.

A bináris kereső fát a foglalásokként implementáltuk, illetve az admin fiókok egy egyszeresen láncolt veremben vannak tárolva (más tanult adatstruktúra típus).

Az alapértelmezett, már létező, default Admin információ:   username: adminexample;
                                                            password: 12345
