# Data Cleaning and Preparation: IBM HR Analytics Attrition Dataset

This document provides a detailed explanation of the data cleaning and preparation process for the IBM HR Analytics Attrition dataset, mapped directly to the assignment requirements.

## 1. Assignment Tasks

### a. Understanding the dataset:

1. Import the dataset in a notebook environment with python pandas.
2. Show the number of attributes (columns) and number of records (rows).
3. Show the statistics of the dataset (column wise mean, standard deviation, max, min etc.).
4. Count the number of missing values in the dataset and show them.
5. Count the number of duplicate values in the dataset and show them.

### b. Data Cleaning:

1. If you find any missing values in the dataset (nan values) replace those with the column-wise median for numeric data, and with mode for categorical data.
2. If you find any duplicates in the dataset, keep just one copy of the data.
3. Remember, if any row in the target column (Attrition) is missing, you must drop that row.
4. Remove any outliers present in the numeric columns.
5. Standardize the string columns data to lower case.

### c. Creation of Input and Output Features:

1. You need to split the data into two parts. The “Features” variable will consist of all the columns in the dataset except the target column. And the “Labels” variable will contain only the target column.
2. The target column contains two classes (Yes/No). Convert them to numeric classes: 0 (No) and 1 (Yes) and replace them in the “Labels” column.

---

## 2. Implementation & Rationale

### a. Understanding the Dataset

#### 1. Import and Load

- **Implementation**: Used `kagglehub` to download the latest dataset and `pathlib.Path` with `glob` to find the CSV file. Loaded using `pd.read_csv`.
- **Rationale**: `pathlib` provides a more modern and robust way to handle file paths across different operating systems.

#### 2. Dimension Analysis

- **Implementation**: Used `df.shape` and unpacked it into `rows, cols`.
- **Rationale**: Identifying the size of the dataset is the first step in auditing data quality and tracking how many records are filtered out during cleaning.

#### 3. Statistical Summary

- **Implementation**: Used `df.describe(include='all')`.
- **Rationale**: By using `include='all'`, we get statistics for both numeric columns (mean, std, etc.) and categorical columns (unique, top, frequency), giving a complete overview of the data distribution.

#### 4. Missing and Duplicate Counts

- **Implementation**:
  - Missing: `df.isnull().sum()` and filtered for values greater than zero.
  - Duplicates: `df.duplicated().sum()`.
- **Rationale**: Before applying fixes, we must confirm if issues actually exist. This prevents unnecessary processing and confirms the starting state of the data.

### b. Data Cleaning

#### 1. Missing Value Imputation

- **Implementation**: Iterated through columns. Used `median()` for numeric types and `mode()[0]` for categorical types.
- **Rationale**:
  - **Median** is used for numbers because it is not affected by extreme outliers (unlike the mean).
  - **Mode** is used for text because it represents the most common occurrence, which is the most statistically likely value for a missing category.

#### 2. Duplicate Handling

- **Implementation**: Used `df.drop_duplicates(inplace=True)`.
- **Rationale**: Duplicate records can cause "data leakage" and bias machine learning models by giving certain patterns more weight than they deserve.

#### 3. Target Column (Attrition) Integrity

- **Implementation**: Used `df.dropna(subset=['Attrition'], inplace=True)`.
- **Rationale**: Since `Attrition` is what we want the model to learn, we cannot "guess" or impute missing values for it. Records with a missing target are unusable for supervised learning.

#### 4. Outlier Removal

- **Implementation**: Applied the **Interquartile Range (IQR)** method.
  - $Lower Bound = Q1 - 1.5 \times IQR$
  - $Upper Bound = Q3 + 1.5 \times IQR$
- **Rationale**: Outliers can distort the learning process of many ML algorithms. The IQR method is a standard statistical approach to identify and remove extreme anomalies that don't follow the general pattern of the data.

#### 5. String Standardization

- **Implementation**: Selected all columns with `object` or `str` dtypes and applied `.str.lower()`.
- **Rationale**: Standardizing to lower case prevents the model from treating "Yes" and "yes" as different categories, ensuring consistency across all text features.

### c. Feature Creation

#### 1. Splitting Features and Labels

- **Implementation**:
  - `Features = df.drop(columns='Attrition')`
  - `Labels = df[['Attrition']]`
- **Rationale**: Machine learning algorithms require independent variables (Features) and the dependent variable (Labels) as separate inputs to learn the relationship between them.

#### 2. Target Encoding

- **Implementation**: Used `.replace({'no': 0, 'yes': 1})` on the Labels column.
- **Rationale**: Most classification models require numeric inputs for loss calculation. Mapping "No/Yes" to "0/1" is a standard binary encoding practice that allows mathematical optimization.
