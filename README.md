# ECN-frappologie
Une application de frappologie écrite par deux étudiants dans le cadre d'un projet d'école.

Cette application en ligne de commande vise les ordinateurs sous Windows.

## Fonctionnalités

Les fonctionnalités suivantes ont été développées :

- Capture et traitement des données d'enrôlement.
- Sauvegarde du modèle biométrique dans un stockage à long terme.
- Capture des données d'authentification et comparaison au modèle biométrique.

Nous avons plus précisément :

- Capture des données brutes de frappe : instant de frappe de chaque touche.
    
- Extraction des données utiles : durées entre deux touches.
    
- Création de la référence biométrique à partir des données dans le cas de création d'utilisateur : moyennes et écarts types sur le nombre de captures d'enrôlement des durées entre les touches.
    
- Sauvegarde du modèle biométrique dans un stockage à long terme : écriture des données dans un fichier.
    
- Comparaison des données avec la référence biométrique de l'utilisateur dans le cas d'une authentification : cette comparaison est effectuée pour chaque durée entre deux touches.
    
- La prise de décision, c'est-à-dire la confirmation ou le rejet de l'authentification de l'utilisateur, dans le cas d'une authentification : si l'une des comparaisons échoue, l'authentification est refusée.

## Limites

Le modèle de sécurité de notre logiciel est à compléter. En effet les données sont actuellement enregistrées en clair.

Une métrique plus adaptée existe peut-être.

La possibilité d'avoir plusieurs références pour un utilisateur pourrait être intéressante. En effet, il peut arriver qu'un même utilisateur ait plusieurs manières de frapper, pouvant dépendre notamment du clavier mais aussi des autres conditions de frappe.

La dynamique de frappe étant une donnée biométrique comportementale, elle est sujette au vieillissement. Il faudrait alors prendre en compte ce vieillissement de la donnée pour faire évoluer la référence.

La gestion des langues n'est pas optimale, avec actuellement des chaînes de caractères directement intégrées au code. De plus certaines sont en français et d'autres sont en anglais. Il faudrait donc faire évoluer la gestion du langage.

# Qu'est-ce que la frappologie ?
La frappologie, ou Dynamique De Frappe au clavier (DDF), est une modalité biométrique comportementale permettant l'identification et l'authentification d'un utilisateur. Elle fonctionne en analysant la manière dont l'utilisateur frappe un texte, libre ou statique, à l'aide de son clavier. 

<details>
  <summary>Plus de détails en cliquant ici</summary>

Elle a de multiples avantages par rapport à d'autres méthodes :

- *Bas coût.* Elle ne nécessite pas de matériel autre que celui généralement utilisé avec un ordinateur
- *Non intrusif.* Pour l'utilisateur, son utilisation est quasi identique à celle d'un mot de passe classique. La différence pouvant le plus se faire ressentir est sûrement l'impossibilité d'auto remplissage, éliminée pour le meilleur et pour le pire.
- *Intégration à l'authentification multifacteur* Elle peut facilement être utilisée en complément de la méthode classique de mot de passe.
- *Faiblement contraint.* Son initialisation peut être relativement peu contraignante selon le nombre de données d'enrôlement. Son utilisation n'augmente pas réellement les contraintes d'une authentification par mot de passe classique.


Vous pouvez trouver plus d'informations sur la frappologie dans la thèse de Giot "Contributions à la dynamique de frappe au clavier :
multibiométrie, biométrie douce et mise à jour de la référence".

## Quelques définitions
### Identification et authentification
L'identification est l'acte de se présenter comme étant telle ou telle personne. Elle n'implique pas une authentification, définie ci-après. Dans le cadre de la DDF, l'identification correspond à la comparaison entre l'utilisateur qui tente de s'identifier et une base de données. C'est une comparaison "1:n".

L'authentification est l'acte de vérifier que quelqu'un est celui qu'il prétend être. C'est là que la sécurité intervient. Elle correspond à la comparaison de données fournies par la personne à des données (théoriquement) uniquement détenues par la personne authentique. Ces données peuvent se répartir en quatre catégories : mémoriel (ce qu'il sait, par exemple un mot de passe), matériel (ce qu'il possède, par exemple son téléphone), corporel (ce qu'il est, par exemple son empreinte digitale), et réactionnel (ce qu'il fait, par exemple sa signature). La DDF est une méthode d'authentification utilisant le facteur réactionnel. L'authentification est une comparaison "1:1".

Les deux modalités précédentes sont souvent enchaînées, l'authentification nécessitant une identification préalable. Par exemple, la plupart de nos ordinateurs nous demandent de sélectionner un utilisateur (ou d'entrer son nom), ce qui est la phase d'identification, puis on demande un mot de passe (ou une empreinte digitale, ou autre), ce qui est la phase d'authentification. Dans le cadre de notre projet, nous avons utilisé ce même principe : l'utilisateur se déclare, puis on procède à une authentification en comparant avec les données à notre disposition le concernant.


### Texte statique et texte libre
Le texte statique, à la différence du texte libre, est un texte connu à l'avance par le système. Dans ce cas, l'utilisateur devra taper un texte donné par le système et donc connu par celui-ci. Dans le cas du texte libre, l'utilisateur peut taper ce qu'il veut. L'utilisation de texte libre est nécessaire à une authentification continue. Cependant, implémenter une méthode d'authentification en texte libre s'avère être beaucoup plus compliqué et nécessite beaucoup plus de données qu'une méthode en texte statique.

### Mot de passe partagé
Le mot de passe partagé est un mot de passe connu de tous les utilisateurs, à l'inverse du mot de passe individuel. Dans le 1^er cas, tous les utilisateurs tapent le même mot de passe (ou texte) pour s'authentifier, alors que dans le second cas, chaque utilisateur tape son propre mot de passe (ou texte). Si ces mots de passe sont gardés secrets, ils peuvent permettre une forme d'authentification multifacteur (mémorielle et réactionnelle).
</details>
