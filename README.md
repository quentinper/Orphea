# Projet Orphéa

Dans le cadre du projet Orchestrion (SAE – BUT3 GEII 2025/2026), dont l’objectif est de concevoir un instrument de musique type Orchestrion en mobilisant les compétences acquises tout au long de la formation, nous avons choisi de réaliser un clavier automatisé, capable de jouer de la musique selon trois modes de fonctionnement.  

Ce projet servira de démonstrateur pour la promotion de la filière lors des journées portes ouvertes et des salons.

---

## Présentation du projet

### Caractéristiques principales

- 3 modes de jeu : manuel, semi-automatique, automatique  
- Banque de sons personnalisable via librairie personnalisable
- Système modulaire d’effets audio carte option  
- Fonctionnement secteur et batterie (autonomie ~ADU)
- Ecran Oled IHM avec l'utilisateur 
- IHM Wifi IHM pour la maintenance 

---

### Suivi de l'avancement du projet

Ce référer au document suivant : 

`Avancement_du_projet_xx.xx.xxxx.pdf`

Seul la dernière version à jour est valable. 

---

## Équipe projet

- Quentin PERBOST  
- William LECOËNT  
- Lorenzo SALVATORE

---




## Arborescence du projet

```bash
└── 020925_AA_Orphéa_équipé
    ├── 030925_AA_Orphéa
    │   ├── 030925_--_Datasheet
    │   ├── 030925_--_Document_Avant_Projet
    │   ├── 030925_--_Document_Conception
    │   ├── 030925_--_Document_Fabrication
    │   ├── 030925_--_Document_Vérification
    │   └── 030925_--_Document_Maintenance
    ├── 040925_AA_Tremolo
    │   ├── 040925_--_Datasheet
    │   ├── 040925_--_Document_Conception
    │   ├── 040925_--_Document_Fabrication
    │   ├── 040925_--_Document_Vérification
    │   └── 040925_--_Document_Maintenance
    ├── 050925_AA_Temoin
    │   ├── 050925_--_Datasheet
    │   ├── 050925_--_Document_Conception
    │   ├── 050925_--_Document_Fabrication
    │   ├── 050925_--_Document_Vérification
    │   └── 050925_--_Document_Maintenance
    ├── 060925_AA_Phaser
    │   ├── 060925_--_Datasheet
    │   ├── 060925_--_Document_Conception
    │   ├── 060925_--_Document_Fabrication
    │   ├── 060925_--_Document_Vérification
    │   └── 060925_--_Document_Maintenance
    ├── 070925_AA_Distorsion
    │   ├── 070925_--_Datasheet
    │   ├── 070925_--_Document_Conception
    │   ├── 070925_--_Document_Fabrication
    │   ├── 070925_--_Document_Vérification
    │   └── 070925_--_Document_Maintenance
    └── 080925_AA_Programmation
        ├── 080925_--_Document_Conception
        └── 080925_--_Document_Vérification


```
### Gconf du projet
Afin d’assurer une organisation cohérente et une traçabilité complète des documents du projet, nous utilisons un système de gestion Gconf.
Chaque fichier est nommé selon une nomenclature normalisée permettant d’identifier rapidement le produit, le type de document et sa révision.
## Structure de nommage

Chaque fichier associé à un produit suit strictement le format standardisé suivant :

`NuméroProduit_TypeDocument_IndiceRevision_NomDuFichier.extension`

### Exemple d'application
Prenons le fichier : **`030925_30_--_Schéma_Cablage.pdf`**

Ce nom indique les informations suivantes :

| Segment | Valeur | Signification |
| :--- | :--- | :--- |
| **NuméroProduit** | `030925` | Code produit (ex: Orphéa) |
| **TypeDocument** | `30` | Typologie (ex: Schéma de câblage) |
| **IndiceRevision** | `--` | Indice d'évolution (ex: Version initiale) |
| **NomDuFichier** | `Schéma_Cablage` | Description libre du contenu |

#### Type de CTD
| Numéro CTD | Description |
|----------|-------------|
| 00 | Tableur de Gconf |
| 01 | Dossier de planification |
| 02 | Cahier des charges |
| 03 | Analyse fonctionnelle |
| 04 | Bibliographie |
| 05 | Planning |
| 06 | Synoptique|
| 20 | Procédure de Test |
| 25 | Procédure de Maintenance |
| 30 | Schéma électrique |
| 40 | Vue PCB |
| 50 | CAO 3D |
| 60 | Fichier de fabrication CAO 3D |
| 70 | Mise en plan CAO 3D  |
| 80 | Procédure de Vérification Vierge  |
| 83 | Procédure de Vérification Complétée  |
| 90 | Programmation  |
| 100 | Notice de conception  |
| 110 | Notice d'assemblage  |
| 120 | Notice de fabrication  |
| 130 | Algorigramme  |
| 140 | Notice de Compilation  |
| 150 | Diagramme de classe  |
### Gestion des Révisions

L'indice de révision assure le suivi chronologique des modifications apportées aux documents. Il suit une progression séquentielle stricte, débutant par un double tiret pour la création, suivi d'une incrémentation alphabétique.

**Séquence logique :**
`--` (Initiale) → `A` → `B` → `C` ... → `Z`

#### Tableau d'évolution (Exemple)

| Nom du fichier | Indice | Version correspondante |
| :--- | :---: | :--- |
| `030925_30_--_Schéma_Cablage.pdf` | **--** | **Version 0** (Version Initiale) |
| `030925_30_-A_Schéma_Cablage.pdf` | **A** | **Version 1** (Première évolution) |
| `030925_30_-B_Schéma_Cablage.pdf` | **B** | **Version 2** (Seconde évolution) |
| `...` | ... | ... |
| `030925_30_-Z_Schéma_Cablage.pdf` | **Z** | **Version 26** |


# Licence 
CC BY-NC-SA 4.0 International License

**THE PROJECT IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND**

--- 
