# Βήμα 1. Φόρτωση του συνόλου παρατηρήσεων Iris
from sklearn.datasets import load_iris
meas = load_iris().data

# Βήμα 2. Εκτέλεση του αλγορίθμου k-means με την Ευκλείδεια απόσταση
from sklearn.cluster import KMeans

# Χρησιμοποιούνται οι 2 τελευταίες διαστάσεις του πίνακα
X = meas[:, [2, 3]]
k = 3  # Oρίζεται ότι τα δεδομένα θα οργανωθούν σε 3 συστάδες
kmeans = KMeans(n_clusters=k).fit(X)  # Εφαρμογή του k-means
IDX = kmeans.labels_
C = kmeans.cluster_centers_

# Βήμα 3. Παρουσίαση των δεδομένων σε γράφημα
import matplotlib.pyplot as plt
plt.figure(1)
# Παρουσιάζεται η κλάση που ανήκει η κάθε παρατήρηση `
plt.plot(X[IDX==0][:,0], X[IDX==0][:,1], 'limegreen', marker='o', linewidth=0, label='C1')
plt.plot(X[IDX==1][:,0], X[IDX==1][:,1], 'yellow', marker='o', linewidth=0, label='C2')
plt.plot(X[IDX==2][:,0], X[IDX==2][:,1], 'c.', marker='o', label='C3')
plt.scatter(C[:,0], C[:,1], marker='x', color='black', s=150 , linewidth=3, label="Centroids", zorder=10)
plt.legend()
plt.show()

# Βήμα 4. Μελέτη της επίδρασης του k στη συσταδοποίηση
from sklearn.metrics import silhouette_score

k_values = range(2, 11)
sse_values = []
silhouette_scores = []

for k in k_values:
    kmeans = KMeans(n_clusters=k)
    kmeans.fit(X)
    sse_values.append(kmeans.inertia_)  # inertia είναι το SSE
    silhouette_scores.append(silhouette_score(X, kmeans.labels_))

# Γράφημα k - SSE
plt.figure(2)
plt.plot(k_values, sse_values, 'bo-')
plt.xlabel('Αριθμός συστάδων (k)')
plt.ylabel('SSE')
plt.title('Σχέση k - SSE')
plt.show()

# Εκτύπωση των αποτελεσμάτων
print("\nΑποτελέσματα αξιολόγησης:")
print("-------------------------")
for k, sse, silhouette in zip(k_values, sse_values, silhouette_scores):
    print(f"k={k}:")
    print(f"SSE: {sse:.2f}")
    print(f"Silhouette Score: {silhouette:.3f}\n")