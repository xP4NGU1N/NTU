# SC1015 Project - Credit Card Debt Repayment


## About

This is a project for SC1015 (Introduction to Data Science and Artificial Intelligence) using data from [credit card holders (Kaggle)](https://www.kaggle.com/datasets/rikdifos/credit-card-approval-prediction?select=credit_record.csv). A brief overview of our code is as follows:

1. Data Extraction
2. Data Preperation & Cleaning
3. Explaratory Data Analysis
4. Linear Regression & Random Forest Regression
5. Random Forest Classifier
6. Artificial Neural Network (TensorFlow & Keras)


## Data Folder

This folder contains the CSV files of our dataset.

**credit_record.csv** - Contains the key personal and financial information about credit card holders. This includes Age, Income, Education Status etcetra. 

**application_record.csv** - Contains the duration taken for credit card holders to pay off their outstanding debts. As credit card holders are able to take on multiple loans at a time, this dataset tracks each transaction.



## Problem Definition

Singaporeans in their 20s are taking on increasing amounts of credit card debt, causing many to be unable to repay credit card debts. Therefore, our team intends to identify the factors that lead to credit card approval as a form of risk analytics, as approval would likely mean ability of individuals to pay back their credit card debts. Ultimately, we aim to help banks determine if individuals should be granted a credit card based on the factors identified, and avoid loaning to those with poor credit scores. 


## Code

**Data Preparation & Cleaning**

We merged the CSV files together, then dropped irrelevant columns while forming new columns to aid our analysis. We also convererted qualitative descriptions into categorical (0/1) variables. Anomalies were removed using the Isolation Forest algorithm.

*Target Variable: Days of Loan Overdue*

**Explaratory Data Analysis**

We seperated our numerical variables from our categorical variables. Then, We conducted a uni-variate and bi-variate analysis of each variable. This helped us identify those with strong correlation to days of loan overdue, which we will utilise in our Machine Learning models.

**Linear Regression & Random Forest Regression**

We performed a train-test split and tested the accuracy of each numerical variable using a regression model. By comparing R-Squared value, we identified that income is the best variable to estimate the days of loan overdue. 

**Random Forest Classifier**

We performed a stratified K-Fold Cross Validation process to maintain the same class ratio across our train and test sets as our original dataset. Then, we used income to predict if an applicant will have difficulties paying back his or her loan on time (or even having to default on the loan).

**Artificial Neural Network (TensorFlow & Keras)**

We trained an Artifical Neural Network model with a sequential classifier to determine if individuals should get their credit card approved. By training the model on 4 variables (Income_level, Car_owned, Property_owned, Employed), the model enables us to do forecasting of credit card approval.  


## Conclusion

We managed to achieve our objectives of identifying key variables that affects the probability of an individual failing to repay credit card debts. We also developed an artificial neural network model to help banks determine if individuals should be granted a credit card. Overall, we reinforced our knowledge on what was taught in this module, and also explored other algorithms and machine learning libraries. 


## Contribution

@preetish246: Exploratory Data Analysis, Linear Regression

@ngweekiat: Artificial Neural Network (TensorFlow & Keras)

@xP4NGU1N: Data Preparation & Cleaning, Random Forest


## References

- Isolation Forest | Anomaly Detection with Isolation Forest. (2021, July 26). Analytics Vidhya. https://www.analyticsvidhya.com/blog/2021/07/anomaly-detection-using-isolation-forest-a-complete-guide/
- How To Do Scikit-Learn Stratified Cross-Validation Splits. (n.d.). Www.rasgoml.com. Retrieved April 24, 2022, from https://www.rasgoml.com/feature-engineering-tutorials/how-to-do-scikit-learn-stratified-cross-validation-splits
- Arvai, K. (2019, July 21). Fine tuning a classifier in scikit-learn. Medium. https://towardsdatascience.com/fine-tuning-a-classifier-in-scikit-learn-66e048c21e65
- Mwiti, D. (2022, April 4). How To Build a Deep Learning Model to Predict Employee Retention Using Keras and TensorFlow. DigitalOcean. https://www.digitalocean.com/community/tutorials/how-to-build-a-deep-learning-model-to-predict-employee-retention-using-keras-and-tensorflow
