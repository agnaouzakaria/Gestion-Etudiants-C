# 🎓 Gestion d'Étudiants - Liste Doublement Chaînée

Ce projet est une application console développée en **Langage C** permettant de gérer une base de données d'étudiants en utilisant une structure de données avancée : la **Liste Doublement Chaînée**.

## 🛠️ Fonctionnalités
- **Initialisation** : Création d'une liste vide structurée.
- **Gestion des Noeuds** : Création dynamique de noeuds contenant (Apogée, Nom, Prénom, Filière).
- **Insertions Flexibles** : Ajout au début, à la fin ou dans une liste vide.
- **Suppression Ciblée** : Suppression d'un étudiant par sa position avec libération de la mémoire.
- **Affichage Optimisé** : Visualisation claire de la liste des étudiants.

## 💻 Concepts Techniques Utilisés
- **Allocation Dynamique** : Utilisation de `malloc()` et `free()`.
- **Pointeurs** : Manipulation complexe de pointeurs (suivant/précédent).
- **Structures de Données** : Implémentation d'une `struct` personnalisée.

## 🚀 Comment exécuter le projet
1. Clonez le projet.
2. Compilez le fichier : 
   ```bash
   gcc student_management.c -o gestion_etudiant
