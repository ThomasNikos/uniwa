# Special Topics in Software Engineering

## 📝 Επισκόπηση Έργου

Αυτή η τριών επιπέδων εμπορική εφαρμογή αναπτύχθηκε στο πλαίσιο του μαθήματος **Ειδικά Θέματα Τεχνολογίας Λογισμικού** του **Τμήματος Μηχανικών Πληροφορικής και Υπολογιστών** του **Πανεπιστημίου Δυτικής Αττικής**. Η εφαρμογή επιδεικνύει βασικές λειτουργίες **CRUD (Create, Read, Update, Delete)** και ακολουθεί σύγχρονες αρχές ανάπτυξης λογισμικού, με έμφαση σε καθαρή αρχιτεκτονική, RESTful υπηρεσίες και ενσωμάτωση ORM.

## 🚀 Χαρακτηριστικά
- **Αρχιτεκτονική Τριών Επιπέδων**: Front-end, Business Logic και Βάση Δεδομένων.
- **[RESTful API](https://restfulapi.net/)**: Επικοινωνία μεταξύ front-end και back-end.
- **Role-based Access Control (RBAC)**: Έλεγχος πρόσβασης με βάση ρόλους χρηστών.
- **[ORM](https://en.wikipedia.org/wiki/Object-relational_mapping)**: Χρήση για αλληλεπίδραση με τη βάση δεδομένων.
- **Διαχείριση Sprints**: Χρήση του **[Trello](https://trello.com/)** ✔️ για agile ανάπτυξη.
- **Automated Integration Tests**: Βασικά αυτοματοποιημένα integration tests για έλεγχο λειτουργικότητας.
- **Responsive Design**: Με τη χρήση του **[Tailwind CSS](https://tailwindcss.com/)** ✔️ για ένα σύγχρονο και ευέλικτο UI.
- **Front-end με [SvelteKit](https://kit.svelte.dev/)** ✔️: Γρήγορη και αποδοτική ανάπτυξη του front-end με **SvelteKit**.

## 🛠️ Τεχνολογίες

### Front-end:
- **Framework**: [SvelteKit](https://kit.svelte.dev/) ✔️
- **Styling**: [Tailwind CSS](https://tailwindcss.com/) ✔️
- **Άλλες επιλογές**: Server-side ή Single Page Application (SPA) με **[React](https://reactjs.org/)**, **[Vue.js](https://vuejs.org/)**, ή **[Angular](https://angular.io/)**.

### Back-end:
- Ανάπτυξη με χρήση αντικειμενοστραφούς γλώσσας προγραμματισμού.
- Χρήση **[Dependency Injection](https://en.wikipedia.org/wiki/Dependency_injection)** για τη διαχείριση εξαρτήσεων.
- ORM για την επικοινωνία με τη βάση δεδομένων (π.χ. **[Hibernate](https://hibernate.org/)**, **[Entity Framework](https://learn.microsoft.com/en-us/ef/)**).

### Βάση Δεδομένων:
Επιλογή σχεσιακής βάσης δεδομένων, όπως:
- **[MySQL](https://www.mysql.com/)** ✔️
- **[PostgreSQL](https://www.postgresql.org/)**
- **[MariaDB](https://mariadb.org/)**
- **[SQL Server](https://www.microsoft.com/en-us/sql-server)**

## 🔧 Απαιτήσεις

Για να τρέξετε την εφαρμογή, θα χρειαστείτε:
- **[JDK 11+](https://openjdk.org/projects/jdk/11/)** (για το back-end)
- **[Node.js](https://nodejs.org/)** για το SvelteKit front-end
- Εγκατεστημένη σχεσιακή βάση δεδομένων (π.χ. **[MySQL](https://www.mysql.com/)** ✔️)
- **[Trello](https://trello.com/)** ✔️ για τη διαχείριση έργου

## 🚀 Οδηγίες Εγκατάστασης

1. **Κλώνος του αποθετηρίου**:
    ```bash
    gh repo clone uniwa-software/Special_Topics_in_Software_Engineering
    ```
2. **Εγκατάσταση εξαρτήσεων**:
    - Για το front-end:
      ```bash
      cd frontend
      npm install
      ```
    - Για το back-end:
      ```bash
      cd backend
      ./gradlew build
      ```
3. **Διαμόρφωση της βάσης δεδομένων**:
   - Εκτελέστε το σχήμα SQL που βρίσκεται στο `database/schema.sql` για να διαμορφώσετε τη βάση δεδομένων.
4. **Εκκίνηση του server**:
    - Για το front-end (SvelteKit):
      ```bash
      npm run dev
      ```
    - Για το back-end:
      ```bash
      ./gradlew bootRun
      ```

## 📂 Δομή του Έργου

```
├── backend/     # Κώδικας για το backend (Express.js ή άλλο backend)
│ ├── app.js     # Το βασικό αρχείο για το Express server
│ ├── package.json     # Εξαρτήσεις και σενάρια για το backend
│ └── (Άλλα αρχεία backend)
├── frontend/     # SvelteKit εφαρμογή (frontend)
│ ├── src/     # Πηγαίος κώδικας για το SvelteKit
│ ├── public/     # Στατικά αρχεία για το frontend
│ ├── app.css     # Tailwind CSS για το στυλ του frontend
│ ├── package.json     # Εξαρτήσεις για το SvelteKit
│ └── (Άλλα αρχεία frontend)
├── database/     # Αρχεία για τη βάση δεδομένων
│ └── schema.sql     # Σχήμα SQL για τη βάση δεδομένων MySQL
├── postcss.config.cjs     # Ρυθμίσεις για το PostCSS 
├── tailwind.config.js     # Ρυθμίσεις για το Tailwind CSS
 └── package.json     # Εξαρτήσεις για το frontend
```

## 🛠️ Εργαλεία Ανάπτυξης
- **[Git](https://git-scm.com/)** για έλεγχο εκδόσεων
- **[GitHub](https://github.com/)** ✔️ για αποθήκευση κώδικα
- **[Trello](https://trello.com/)** ✔️ για διαχείριση sprints και εργασιών

## 📝 Άδεια Χρήσης
Αυτό το έργο διατίθεται υπό τους όρους της άδειας **[MIT](https://opensource.org/licenses/MIT)**. Ανατρέξτε στο αρχείο `LICENSE` για περισσότερες πληροφορίες.

## 📱 Connect with Us

Μπορείτε να συνδεθείτε με τους συνεισφέροντες του έργου στο LinkedIn:

- **Νίκος Θωμάς**: [LinkedIn Profile](https://www.linkedin.com/in/nikos-thomas-5687b5263)
- **Φίλιππος Παπαγεωργίου**: [LinkedIn Profile](https://www.linkedin.com/in/filipe-papageorgiou-55491b27b/)
