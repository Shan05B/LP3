
# Import libraries
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import r2_score, mean_squared_error

# Load dataset
df = pd.read_csv("uber.csv")

# Preprocessing
df = df.dropna()
df = df.drop(columns=['Unnamed: 0', 'key'], errors='ignore')

# Select input and output
X = df[['pickup_longitude', 'pickup_latitude',
        'dropoff_longitude', 'dropoff_latitude',
        'passenger_count']]

y = df['fare_amount']

# Remove invalid fare values
df = df[df['fare_amount'] > 0]
X = df[['pickup_longitude', 'pickup_latitude',
        'dropoff_longitude', 'dropoff_latitude',
        'passenger_count']]
y = df['fare_amount']

# Identify outliers
sns.boxplot(x=y)
plt.show()

# Check correlation
sns.heatmap(df.select_dtypes(include='number').corr(),
            annot=True)
plt.show()

# Split dataset
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)

# Linear Regression
lr = LinearRegression()
lr.fit(X_train, y_train)
pred1 = lr.predict(X_test)

# Random Forest Regression
rf = RandomForestRegressor(n_estimators=10, random_state=42)
rf.fit(X_train, y_train)
pred2 = rf.predict(X_test)

# Model evaluation
print("Linear Regression")
print("R2 Score:", r2_score(y_test, pred1))
print("RMSE:", np.sqrt(mean_squared_error(y_test, pred1)))

print("Random Forest")
print("R2 Score:", r2_score(y_test, pred2))
print("RMSE:", np.sqrt(mean_squared_error(y_test, pred2)))
