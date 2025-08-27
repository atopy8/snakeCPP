# Snake Game C++ 🐍

Un jeu Snake moderne développé en **C++** avec la bibliothèque **SFML 3.0**.

## Description

Ce projet implémente le jeu classique Snake avec une architecture orientée objet propre et une documentation complète générée avec Doxygen. Le serpent évolue dans une grille, mange des nourritures pour grandir et doit éviter les collisions.

## Fonctionnalités

- **Interface graphique** moderne avec SFML
- **Menu principal** interactif
- **Système de collision** avancé
- **Gestion des nourritures** multiples
- **Architecture modulaire** avec séparation des responsabilités
- **Documentation complète** avec Doxygen

## Architecture

### Classes principales

| Classe | Responsabilité |
|--------|----------------|
| `Game` | Orchestration générale du jeu |
| `Snake` | Gestion du serpent (mouvement, croissance) |
| `SnakeBit` | Segment individuel du serpent |
| `Food` | Gestion des nourritures (position, collision) |
| `GameScreen` | Interface du menu principal |
| `GameParameters` | Configuration globale du jeu |

### Structures de données

- **`Position`** : Coordonnées (x, y) dans la grille
- **`SnakeDirection`** : Énumération des directions possibles

## Compilation et exécution

### Prérequis

- **C++17** ou plus récent
- **SFML 3.0**
- **CMake** (optionnel)
- **Doxygen** (pour la documentation)

### Compilation

```bash
# Avec CMake (si disponible)
mkdir build && cd build
cmake .. && make
```

### Exécution

```bash
cd build
make run
```

## Contrôles

### Menu principal
- **W/S** : Navigation verticale
- **Entrée** : Sélection d'option
- **Échap** : Quitter

/!\ les seules options fonctionnelle sont Quit et Start Game.

### En jeu
- **W** : Haut
- **A** : Gauche  
- **S** : Bas
- **D** : Droite
- **Échap** : Quitter

## Documentation

### Génération avec Doxygen

```bash
# Générer la documentation HTML
doxygen Doxyfile

# Ouvrir la documentation
open docs/html/index.html
```

La documentation complète inclut :
- **Diagrammes de classes** 
- **Documentation des méthodes**
- **Exemples d'utilisation**
- **Graphiques de dépendances**

### Structure de la documentation

```
docs/
├── html/           # Documentation HTML
├── latex/          # Documentation PDF (optionnel)
└── diagrams/       # Diagrammes générés
```

## Structure du projet

```
snake-cpp/
├── include/            # Fichiers d'en-tête (.hpp)
│   ├── Game.hpp
│   ├── Snake.hpp
│   ├── SnakeBit.hpp
│   ├── Food.hpp
│   ├── GameScreen.hpp
│   ├── GameParameters.hpp
│   ├── Position.hpp
│   └── SnakeDirection.hpp
├── src/                # Fichiers source (.cpp)
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Snake.cpp
│   ├── SnakeBit.cpp
│   ├── Food.cpp
│   └── GameScreen.cpp
├── assets/             # Ressources (polices, images)
│   └── ARIAL.TTF
├── docs/               # Documentation générée
├── Doxyfile           # Configuration Doxygen
└── README.md          # Ce fichier
```

## Configuration

Les paramètres de jeu peuvent être modifiés dans `GameParameters.hpp` :

```cpp
unsigned int widthWindow  = 1920u;  ///< Largeur de la fenêtre en pixels
unsigned int heightWindow = 1080u;  ///< Hauteur de la fenêtre en pixels

unsigned int nbLin        = 22u;    ///< Nombre de lignes de la grille
unsigned int nbCol        = 40u;    ///< Nombre de colonnes de la grille
unsigned int nbFood       = 10u;    ///< Nombre de nourritures simultanées

unsigned int updateSpeed  = 100000u;  ///< Vitesse de mise à jour (en microsecondes)
```

## Problèmes connus

- La police `ARIAL.TTF` doit être présente dans `assets/`
- SFML 3.0 requis (syntaxe différente de SFML 2.x)
- Gestion mémoire à optimiser (utiliser smart pointers)

## Améliorations futures

- [ ] **Score et high-score**
- [ ] **Niveaux de difficulté**
- [ ] **Sons et musique**
- [ ] **Modification des paramètres sur l'écran d'accueil**
- [ ] **Gestion RAII** (smart pointers)

## Développement

### Convention de code

- **PascalCase** pour les classes et méthodes
- **CamelCase** pour les variables locales  
- **UPPER_CASE** pour les constantes
- **Documentation Doxygen** obligatoire pour l'API publique

## Licence

Projet éducatif - Libre d'utilisation et modification.

## Contact

Pour toute question concernant l'implémentation ou la documentation, n'hésitez pas à ouvrir une issue.

---
*Documentation générée automatiquement avec Doxygen*
