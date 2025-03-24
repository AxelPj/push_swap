# Libft - École 42

Bienvenue dans mon repository **Libft** ! Ce projet fait partie du cursus de l'École 42 et vise à construire une bibliothèque en C en réimplémentant certaines fonctions standard, ainsi qu'en ajoutant des fonctionnalités utiles pour les futurs projets. L'objectif est de développer une compréhension approfondie de la manipulation de la mémoire, des chaînes de caractères et de la modularité du code.

## Sommaire

- [À propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Structure du projet](#structure-du-projet)
- [Contributions](#contributions)

## À propos

Le projet **Libft** est conçu pour aider les étudiants à se familiariser avec des fonctions essentielles de la bibliothèque standard du C et à les recréer à partir de zéro. En réalisant ce projet, on apprend à manipuler des pointeurs, à gérer la mémoire efficacement, et à écrire du code modulaire qui pourra être réutilisé dans de futurs projets. Cette bibliothèque servira également de base pour des projets plus avancés dans le cursus 42.

## Fonctionnalités

La bibliothèque **Libft** comprend plusieurs catégories de fonctions :

### 1. Fonctions de la bibliothèque standard C
Les fonctions suivantes sont recréées pour comprendre leur fonctionnement interne :
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove` – Manipulation de la mémoire.
- `ft_strlen`, `ft_strdup`, `ft_strcpy`, `ft_strncpy` – Gestion des chaînes de caractères.
- `ft_strcat`, `ft_strncat`, `ft_strlcat` – Concatenation de chaînes.
- `ft_strchr`, `ft_strrchr`, `ft_strstr`, `ft_strnstr` – Recherche de sous-chaînes et de caractères.
- `ft_atoi`, `ft_itoa` – Conversion entre chaînes et nombres.
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` – Fonctions de vérification de caractères.
- `ft_toupper`, `ft_tolower` – Conversion de casse.

### 2. Fonctions de manipulation de listes chaînées
Création et manipulation de listes chaînées, avec les fonctions :
- `ft_lstnew` – Créer un nouvel élément de liste.
- `ft_lstdelone`, `ft_lstdel` – Suppression d'éléments de la liste.
- `ft_lstadd`, `ft_lstiter`, `ft_lstmap` – Ajout et application de fonctions aux éléments de la liste.

### 3. Fonctions additionnelles
Des fonctions utiles non présentes dans la bibliothèque standard :
- `ft_strtrim` – Suppression des espaces inutiles au début et à la fin d'une chaîne.
- `ft_split` – Découpe d'une chaîne en un tableau de chaînes, basé sur un séparateur.
- `ft_substr` – Extraction d'une sous-chaîne.
- `ft_strjoin` – Concatenation de deux chaînes dans une nouvelle chaîne.

## Installation

Pour cloner ce repository et compiler la bibliothèque :

```
git clone https://github.com/AxelPj/libft.git
cd libft
make
```

Cette commande génère un fichier libft.a, qui est la bibliothèque compilée que tu pourras inclure dans d'autres projets.

### Utilisation
Pour utiliser Libft dans vos propres projets, ajoutez simplement le fichier libft.a et l'inclusion des headers au moment de la compilation :

```
gcc -Wall -Wextra -Werror -L. -lft votre_fichier.c -o votre_programme
```
Dans le code source, incluez le fichier d'en-tête libft.h :

```
#include "libft.h"
```

## Structure du projet
Le projet est organisé de la manière suivante :

libft.h : Le fichier d'en-tête de la bibliothèque contenant les prototypes de toutes les fonctions.
src/ : Ce dossier contient les fichiers source (.c) de chaque fonction de la bibliothèque.
obj/ : Ce dossier est généré pour stocker les fichiers objet (.o) lors de la compilation.
Makefile : Fichier de construction pour compiler la bibliothèque facilement en exécutant make.

## Contributions
Les contributions sont les bienvenues ! Si vous souhaitez ajouter des fonctions supplémentaires ou améliorer le code existant, suivez ces étapes :

Forker ce repository.
Créer une branche pour vos modifications 
```(git checkout -b feature/nouvelle-fonctionnalité).```

Committer vos modifications 
```(git commit -m "Ajout d'une nouvelle fonctionnalité").```

Pousser votre branche 
```(git push origin feature/nouvelle-fonctionnalité).```

Créer une Pull Request pour examiner vos changements.
