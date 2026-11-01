
# Import libraries
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score

# Load dataset
df = pd.read_csv("emails.csv")

# Preprocessing
df = df.dropna()
X = df.iloc[:, 1:-1]
y = df.iloc[:, -1]

# Split dataset
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Feature scaling
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# KNN Model
knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, y_train)
pred1 = knn.predict(X_test)

# SVM Model
svm = SVC(kernel='linear')
svm.fit(X_train, y_train)
pred2 = svm.predict(X_test)

# Evaluate models
print("KNN Accuracy:", accuracy_score(y_test, pred1))
print("SVM Accuracy:", accuracy_score(y_test, pred2))
