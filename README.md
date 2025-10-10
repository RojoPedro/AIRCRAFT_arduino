# ✈️ Flight Visualizer ESP32

Un progetto **Arduino** basato su **ESP32**, sviluppato su richiesta di **Alpi Aviation**.  
Il dispositivo è un **visualizzatore di volo digitale** pensato per essere installato sul **cruscotto di un superleggero**, e rappresenta il **primo assistente di volo digitale** disponibile per questo tipo di velivoli.

---

## 🚀 Descrizione del progetto

Il dispositivo comunica con la centralina di bordo e fornisce in tempo reale le principali informazioni di volo, offrendo al pilota un’interfaccia chiara e moderna.  
È progettato per migliorare l’esperienza di volo, ridurre il carico cognitivo e rendere più intuitiva la lettura dei dati.

---

## 🧭 Funzionalità principali

- **Visualizzazione dati di volo**  
  Mostra le informazioni fondamentali come:
  - Inclinazione flap  
  - Quota  
  - Livello carburante  
  - Stato del carrello  
  - Altri parametri di volo essenziali

- **Assistente vocale integrato**  
  Attivabile tramite la **pressione del dispositivo** (pulsante analogico), consente di ricevere notifiche vocali dei parametri più rilevanti.

- **Interfaccia grafica LVGL**  
  Tutta l’interfaccia utente è realizzata con **[LVGL](https://lvgl.io/)**, una libreria grafica open-source ottimizzata per microcontrollori embedded.

---

## ⚙️ Hardware e Software

- **Scheda principale:** ESP32  
- **Linguaggio:** Arduino C++  
- **Framework grafico:** LVGL  
- **Input:** Pulsante analogico (touch/pressione)  
- **Output:** Display TFT e audio assistente vocale  

---

## 🧩 Stato del progetto

Il progetto è attualmente in **fase di sviluppo prototipale**, con l’obiettivo di essere testato su velivoli Alpi Aviation per la validazione dei sistemi.

---

## 🛠️ Autori

Progetto sviluppato su richiesta di **Alpi Aviation**  
Sviluppo software e interfaccia a cura di:  
**[Inserisci il tuo nome o team qui]**

---

## 📄 Licenza

Questo progetto è distribuito sotto licenza **MIT**.  
Consulta il file [`LICENSE`](LICENSE) per i dettagli.

---

> “Portare la leggerezza del volo anche nei sistemi di bordo.”  
> — *Flight Visualizer Team*
