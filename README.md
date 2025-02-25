# CSI2772-Bean-Cards-Game
Un jeu de cartes réalisé en tant que projet pour le cours de CSI 2772 (Concepts Avançés de Programmation en C++), Automne 2024

# Comment Run ce code

## Sur Linux (Préférablement Ubuntu)

```
./Run
```
Cette commande compilera et exécutera le programme.
Assurez-vous d'avoir `g++` installé.

### Alternative:
```
cd src
g++ *.cpp -o jeuDeCartes.exe
./jeuDeCartes.exe
```


| **Caractéristique**                    | **Classe**                                                                                      | **Interface**                                                                                        | **Classe Abstraite**                                                                                           | **Type Générique**                                                                                                      |
|----------------------------------------|-------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
| **Peut être instanciée ?**             | Oui                                                                                             | Non                                                                                                 | Non                                                                                                            | Oui (mais avec un type spécifique)                                                                                       |
| **Méthodes concrètes**                 | Oui                                                                                             | Non                                                                                                 | Oui                                                                                                            | Oui (les méthodes concrètes peuvent être définies dans des classes génériques)                                           |
| **Méthodes abstraites**                | Optionnel                                                                                        | Oui                                                                                                 | Oui                                                                                                            | Non (les génériques ne peuvent pas être abstraits en soi, mais peuvent être utilisés avec des méthodes abstraites)      |
| **Constructeurs**                      | Oui                                                                                             | Non                                                                                                 | Oui                                                                                                            | Oui (le type générique peut être passé au constructeur, mais doit être défini au moment de l'instanciation)            |
| **Héritage multiple**                  | Non (une classe peut hériter d’une seule classe)                                                  | Oui (une classe peut implémenter plusieurs interfaces)                                              | Non (une classe peut hériter d’une seule classe abstraite)                                                     | Oui (une classe générique peut implémenter plusieurs interfaces et étendre une seule classe)                             |
| **Utilisation principale**             | Modéliser des objets concrets                                                                   | Définir des contrats que les classes doivent respecter                                              | Fournir une base partielle de code à d’autres classes                                                          | Créer des classes et méthodes réutilisables pour n’importe quel type d’objet                                            |
| **Opérations possibles**              | Instancier la classe, créer des objets, accéder aux membres (attributs et méthodes), héritage, polymorphisme | Déclarer et implémenter des méthodes abstraites, implémenter une interface dans une classe, héritage multiple, instancier des sous-classes concrètes (mais pas la classe abstraite directement | Définir des méthodes abstraites et concrètes, instancier des sous-classes concrètes (mais pas la classe abstraite directement) | Définir des classes, interfaces ou méthodes génériques utilisant des paramètres de type, instancier des génériques avec des types spécifiques (par exemple, `Boite<String> maBoite = new Boite<>();`), restreindre les types génériques avec des bornes (par exemple, `T extends Number`) |
| **Opérations non possibles**          | Instancier une classe abstraite, utiliser des méthodes privées ou non accessibles dans une autre classe (selon la visibilité) | Instancier une interface, contenir des variables d'instance (mais les interfaces peuvent contenir des constantes) | Instancier une classe abstraite directement, omettre d’implémenter des méthodes abstraites dans les sous-classes concrètes | Utiliser des types primitifs directement dans les génériques (par exemple, `int`, `double`, doivent être `Integer`), accéder à l'information sur le type générique à l'exécution (à cause de l'effacement de type) |


