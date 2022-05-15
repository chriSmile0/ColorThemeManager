Pour l'installation il n'y a rien de spécial a faire.

Sur chaque bouton il y'a le titre de ce qu'il fait 

Les fonctions implémentées (a 100%) sont les suivantes : 
    - Création d'un thème :
        L'utilisateur rentre à la suite une liste de couleur source et cible
        afin de crée son propre thème
    - Importation d'un fichier couleur :
        Met le fichier en question dans un dossier colorfile 
    - Calcul d'un thème :
        En fonction du fichier sélectionné le programme va automatiquement
            Écrire un fichier xml avec pour source toutes les couleurs du fichier
            couleur et laissera vide les cibles
    - Ajouter une nouvelle paire de couleurs :
        Ajoute une couleur a un thème
    - Afficher une liste de paires de couleurs :
        L'utilisateur rentrera un nombre de couleurs.
        Il lui sera affiché les n premières couleurs de son choix
    - Modifier les couleurs :
        Parmi toutes les couleurs du fichier xml séléctionnables,
        l'utilisateur en choisi une et il pourra la modifier en changeant la source et la cible. Si jamais il ne veut changer que la source et que la cible on lui affiche avant la sélection la couleur qui correspond à son choix
    - Appliquer le thème sur un fichier/dossier : 
        Cette fonctionnalité fonctionne pour le fichier mais pas pour le dossier.
        Mais tout d'abord lors du clic on verra que l'on doit choisir entre fichiers et dossier. Car à la base j'avais prévu de pouvoir sélectionné une liste de fichiers dans un dossier.

Au niveau de l'ergonomie je dirais que je m'en sors plutôt pas mal. Je trouve mon intetface simple mais efficace. Même si c'est pour les programmeurs et non pas pour le grand public donc l'attrait compte assez peu mais plus simple mieux c'est.

Pour l'icône sur mes thèmes c'est du pixabay donc de l'image libre de droit 

Je pense avoir faire 60% du travail car il me manque pas de choses quand on y pense.
Il y'a aussi sûrement un gros travail de refactoring a faire sur mon code.