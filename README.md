Pour l'importation d'un fichier couleur, on enregistre le fichier couleur
dans notre lib comme l'importation d'un thème

Pour créer le thème on regarde nos fichiers couleurs, on choisit le fichier couleur
et on calcule le thème en fonction de ce dernier 
Comment ?
    Nos fichiers couleur sont des fichiers textes avec des # avant la couleur
    Il suffit de détecter tout les # pour créer notre thème.

Dans ce commit vous trouverez : 
    - L'importation d'un thème fonctionnel , c'est à dire l'enregistrement 
        de cet thème dans un dossier themes dans l'application
    - L'importation d'un fichier couleur : 
        Lors de la vérification que c'est bien un fichier couleur on regarde juste
        si il contient un # suivi de 8 caractères dont 4 chiffres et certaines lettres
    - Le calcul d'un thème c'est à dire remplir les sources d'un thème sans remplir les cibles
        on en ayant les cibles comme la source (j'y réfléchis)
    - La création d'un thème par l'insertion soit même de tout les codes RGBA 

    - Sauvegarder tout les thèmes (en attente)  
    - Chargement Session Précédente (en attente)

Dans le prochain commit on y trouvera : 
    - Fenêtre responsive car pour le moment elle a une taille fixe
    - Le chargement de tout les thèmes qui sont dans notre dossier thèmes

Attention il se peut qu'il y est des commits 'fix' car il y'a que sur git que 
je peux voir mes erreurs d'include qui ne sont pas affiché dans Qt de manière très clair.