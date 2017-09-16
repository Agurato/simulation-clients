# Simulation de clients entrants dans une banque (Atelier C++ M2)

Simulation d'arrivées de clients dans une banque, qui doivent être servis par un caissier ou attendre dans une file d'attente

## Hypothèses
- Simulation par événements discrets (DES)
- Clients:
  - Honnêtes: ils ne doublent pas les autres
  - Paresseux: ils choisissent la plus petite file
  - Patient: ils ne quittent jamais leur file
- Caissiers:
  - Parfait: ils ne prennent pas de pause
- Aléatoire:
  - Temps d'arrivées des clients et temps de services des caissiers suivent une distribution de Poisson ([https://depinfo.u-cergy.fr/~pl/docs/Poisson.h](https://depinfo.u-cergy.fr/~pl/docs/Poisson.h))

## Scénarios

### Scénario 1: Arrivée d'un client
- Création client
- Si un caissier est libre
  - Le 1er caissier libre sert le client
- Sinon
  - Le client rejoint la plus petite file d'attente
- Créer événement de la prochaine arrivée

### Scénario 2: Libération d'un caissier (le caissier vient de finir de servir le client)
- Supprimer le client
- Si la file d'attente pour le caissier n'est pas vide
  - Le 1er client quitte la file et le caissier le sert
Sinon
  - Le caissier attend qu'un client arrive
