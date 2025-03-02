# Βήμα 1: Φόρτωση δεδομένων από το αρχείο 'mydata.mat'
import scipy.io
import numpy as np
mat_file = scipy.io.loadmat('mydata.mat')
X = np.array(mat_file['X'])

# Βήμα 2: Εφαρμογή DBSCAN στις δύο πρώτες διαστάσεις του πίνακα X
from sklearn.cluster import DBSCAN
dbscan = DBSCAN(eps=0.5, min_samples=15).fit(X)
IDX = dbscan.labels_

# Βήμα 3: Γράφημα διασποράς των δεδομένων
import matplotlib.pyplot as plt

plt.figure(1)
plt.scatter(X[:, 0], X[:, 1])
plt.title('Γράφημα Διασποράς των Δεδομένων')
plt.show()

# Βήμα 4: Γράφημα με τις συστάδες και τον θόρυβο
plt.figure(2)
plt.scatter(X[:, 0], X[:, 1], c=IDX, cmap='viridis')
plt.title('Συστάδες DBSCAN και Θόρυβος')
plt.show()