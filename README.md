Manoeuvre de création d'une action sur un bouton : 
    Clique droit sur un bouton 
    aller au slot : 
        - QAbtractButton : 
            clicked()
            clicked(bool)
            pressed()
            released()
            toggled(bool)
        - QWidget : 
            customContextMenuRequested(QPoint)
            windowIconChanged(QIcon)
            windowIconTextChanged(QString)
            windowTitleChanged(QString)
        - QObject : 
            destroyed()
            destroyed(QObject *)
            objectNameChanged(QString)



Avant de faire tout cela , il est conseillé de renommer tout ses
boutons pour se retrouver 

On effectue donc cela pour les actions générales (en haut de notre application)

Grâce a metoObject nos boutons sont déjà connectés, on a juste a créer les fonctions 
dans notre mainwindow.cpp 