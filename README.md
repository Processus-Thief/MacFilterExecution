# MacFilterExecution
Un simple script C qui permet de lancer un script bash contenu dans une partition chiffrée avec LUKS.

L'idée est de pouvoir exécuter un script bash sur un Raspberry unique (filtrage sur l'adresse mac de l'interface eth0), tout en conservant inconnu par l'utilisateur le script contenu dans la partition chiffrée.
Cela permet de pouvoir développer des script en bash ou en python et d'empêcher une reproduction des scripts sur d'autres équipements.


Le script encryptor.c permet de chiffrer/déchiffrer une chaine de caractère en modifiant les valeurs ascii de la chaines (+/-3).

Le script mac.c déchiffre la chaine de caractère qui contient l'adresse mac autorisée et la compare avec l'adresse mac de la machine actuelle.
Si elles correspondent, alors on déchiffre un fichier image créé avec dd et chiffrée avec cryptsetup (voir tutoriel ici : https://lestutosdeprocessus.fr/tips-tricks#cryptsetup) en déchiffrant à la volée la passphrase.
On monte ensuite le périphérique et on exécute un script contenu dans la partition. Ensuite le fichier image est démonté.
