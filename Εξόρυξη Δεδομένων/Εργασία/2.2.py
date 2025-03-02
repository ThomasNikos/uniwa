# Βήμα 1: Φόρτωση δεδομένων Iris και χρήση των διαστάσεων [2,3]
from sklearn.datasets import load_iris
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import DBSCAN
from scipy.stats import zscore

# Φόρτωση δεδομένων Iris
meas = load_iris().data
X = meas[:, [2, 3]]

# Βήμα 2: Εφαρμογή DBSCAN στις δύο πρώτες διαστάσεις του πίνακα X με eps=0.1 και MinPts=5
dbscan = DBSCAN(eps=0.1, min_samples=5).fit(X)
IDX = dbscan.labels_

# Βήμα 3: Γράφημα διασποράς των δεδομένων
plt.figure(1)
plt.scatter(X[:, 0], X[:, 1])
plt.title('Γράφημα Διασποράς των Δεδομένων Iris')
plt.show()

# Βήμα 4: Γράφημα με τις συστάδες και τον θόρυβο
plt.figure(2)
plt.scatter(X[:, 0], X[:, 1], c=IDX, cmap='viridis')
plt.title('Συστάδες DBSCAN και Θόρυβος')
plt.show()

# Βήμα 5: Κανονικοποίηση των δεδομένων με zscore
xV1 = zscore(X[:, 0])
xV2 = zscore(X[:, 1])
Xnew = np.transpose(np.array([xV1, xV2]))

# Εφαρμογή DBSCAN στα κανονικοποιημένα δεδομένα
dbscan = DBSCAN(eps=0.1, min_samples=5).fit(Xnew)
IDX = dbscan.labels_

# Γράφημα με τις συστάδες μετά την κανονικοποίηση
plt.figure(3)
plt.scatter(Xnew[:, 0], Xnew[:, 1], c=IDX, cmap='viridis')
plt.title('Συστάδες DBSCAN μετά από Κανονικοποίηση')
plt.show()

# Σχόλιο: Η κανονικοποίηση με zscore συχνά βελτιώνει την απόδοση του DBSCAN,
# ιδιαίτερα όταν οι διαστάσεις έχουν διαφορετικές κλίμακες ή κατανομές.