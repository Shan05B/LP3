
# Import libraries
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans

# Load dataset
df = pd.read_csv("sales_data_sample.csv", encoding="latin1")

# Select numerical features
X = df[['SALES', 'QUANTITYORDERED']]

# Feature scaling
sc = StandardScaler()
X = sc.fit_transform(X)

# Elbow Method
wcss = []

for i in range(1, 11):
    km = KMeans(n_clusters=i, random_state=42, n_init=10)
    km.fit(X)
    wcss.append(km.inertia_)

# Plot elbow graph
plt.plot(range(1, 11), wcss, marker='o')
plt.xlabel("Number of Clusters")
plt.ylabel("WCSS")
plt.title("Elbow Method")
plt.show()

# Apply K-Means
km = KMeans(n_clusters=3, random_state=42, n_init=10)
df['Cluster'] = km.fit_predict(X)

# Display clusters
print(df[['SALES', 'QUANTITYORDERED', 'Cluster']].head())
print(df['Cluster'].value_counts())
