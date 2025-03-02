import scipy.io
import numpy as np
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

# Βήμα 1: Φόρτωση δεδομένων
mat_file = scipy.io.loadmat('xV.mat')
xV = np.array(mat_file['xV'])

def perform_kmeans(X, step_name):
    """Εκτελεί k-means και εμφανίζει τα αποτελέσματα"""
    k = 3
    kmeans = KMeans(n_clusters=k).fit(X)
    IDX = kmeans.labels_
    C = kmeans.cluster_centers_
    
    # Υπολογισμός SSE
    sse = kmeans.inertia_
    
    # Δημιουργία γραφήματος
    plt.figure(figsize=(8, 6))
    plt.plot(X[IDX==0][:,0], X[IDX==0][:,1], 'limegreen', marker='o', linewidth=0, label='C1')
    plt.plot(X[IDX==1][:,0], X[IDX==1][:,1], 'yellow', marker='o', linewidth=0, label='C2')
    plt.plot(X[IDX==2][:,0], X[IDX==2][:,1], 'c.', marker='o', label='C3')
    plt.scatter(C[:,0], C[:,1], marker='x', color='black', s=150, linewidth=3, label="Centroids", zorder=10)
    plt.legend()
    plt.title(f'Συσταδοποίηση για {step_name}')
    plt.show()
    
    return sse

# Βήμα 2: k-means με τα δύο πρώτα χαρακτηριστικά
X = xV[:,[0,1]]
sse_2 = perform_kmeans(X, "τα δύο πρώτα χαρακτηριστικά")
print(f"SSE για τα δύο πρώτα χαρακτηριστικά: {sse_2:.2f}")

# Βήμα 3: k-means με τα χαρακτηριστικά [296, 305]
X = xV[:,[296, 305]]
sse_3 = perform_kmeans(X, "τα χαρακτηριστικά [296, 305]")
print(f"SSE για τα χαρακτηριστικά [296, 305]: {sse_3:.2f}")

# Βήμα 4: k-means με τα δύο τελευταία χαρακτηριστικά
X = xV[:,[467, 468]] # 469 χαρακτηριστικά, άρα οι δείκτες είναι 467 και 468
sse_4 = perform_kmeans(X, "τα δύο τελευταία χαρακτηριστικά")
print(f"SSE για τα δύο τελευταία χαρακτηριστικά: {sse_4:.2f}")

# Βήμα 5: k-means με τα χαρακτηριστικά [205, 175]
X = xV[:,[205, 175]]
sse_5 = perform_kmeans(X, "τα χαρακτηριστικά [205, 175]")
print(f"SSE για τα χαρακτηριστικά [205, 175]: {sse_5:.2f}")

# Βήμα 6: Σύγκριση αποτελεσμάτων
print("\nΣύγκριση SSE:")
print("-------------")
print(f"Βήμα 2 (χαρακτηριστικά [0,1]): {sse_2:.2f}")
print(f"Βήμα 4 (τελευταία χαρακτηριστικά): {sse_4:.2f}")
print(f"Βήμα 5 (χαρακτηριστικά [205,175]): {sse_5:.2f}")