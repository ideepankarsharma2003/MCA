
# 📘 PMC406 – Data Science Laboratory

### Detailed Unit-wise Notes

---

## **Unit 1: Data Preparation & Visualization**

**Topics:** Data cleaning, handling missing values, feature engineering, descriptive statistics, visualization

### 1.1 Data Cleaning

* **Definition:** Process of detecting and correcting (or removing) corrupt or inaccurate records.
* **Common issues:** Missing values, duplicates, inconsistent formatting, outliers.

**R Functions/Packages:**

* `is.na()`, `na.omit()`, `complete.cases()` – detect/remove missing values
* `mean(x, na.rm=TRUE)` – calculate ignoring NA
* `mice`, `VIM` packages – advanced imputation
* `dplyr` – data manipulation

**Example (Airquality dataset):**

```R
data("airquality")
summary(airquality)
# Handling missing values
airquality$Ozone[is.na(airquality$Ozone)] <- mean(airquality$Ozone, na.rm=TRUE)
```

---

### 1.2 Feature Engineering

* Creating new features to improve model performance.
  Examples:
* **Binning** – convert continuous → categorical
* **One-hot encoding** – categorical → dummy variables (`model.matrix`)
* **Scaling/Normalization** – `scale()`

---

### 1.3 Descriptive Statistics

* **Central Tendency:** Mean, Median, Mode
* **Dispersion:** Variance, Standard deviation, Range, IQR
* **Shape:** Skewness, Kurtosis

**R Functions:**

```R
mean(data$col); median(data$col); sd(data$col); var(data$col); range(data$col)
```

---

### 1.4 Data Visualization

**Packages:** `ggplot2`, `plotly`, `lattice`

* Bar chart → `geom_bar()`
* Histogram → `geom_histogram()`
* Scatter plot → `geom_point()`
* Boxplot → `geom_boxplot()`
* Line chart → `geom_line()`

**Example:**

```R
library(ggplot2)
ggplot(airquality, aes(x=Month, y=Ozone)) + geom_boxplot(fill="skyblue")
```

---

## **Unit 2: Classification**

**Topics:** Decision Trees, k-NN, Naïve Bayes, SVM

### 2.1 Decision Trees

* **Algorithm:** Splits data recursively based on information gain or Gini index.
* **R Package:** `rpart`, `rpart.plot`

**Example (Titanic dataset):**

```R
library(rpart)
fit <- rpart(Survived ~ Pclass + Age + Sex, data=titanic_train, method="class")
rpart.plot(fit)
```

---

### 2.2 k-Nearest Neighbors (k-NN)

* **Concept:** Assigns class based on majority vote of nearest neighbors.
* **Package:** `class`

```R
library(class)
pred <- knn(train, test, cl=train_labels, k=5)
```

---

### 2.3 Naïve Bayes

* **Concept:** Probabilistic classifier based on Bayes theorem.
* **Package:** `e1071`

```R
library(e1071)
model <- naiveBayes(Survived ~ Pclass + Sex + Age, data=titanic_train)
pred <- predict(model, titanic_test)
```

---

### 2.4 Support Vector Machine (SVM)

* **Concept:** Finds hyperplane that maximizes margin between classes.
* **Package:** `e1071`

```R
svm_model <- svm(am ~ mpg + hp + wt, data=mtcars)
plot(svm_model, mtcars)
```

---

## **Unit 3: Regression**

**Topics:** Linear, Logistic, Polynomial regression

### 3.1 Multiple Linear Regression

```R
data("Boston", package="MASS")
lm_model <- lm(medv ~ lstat + rm + age, data=Boston)
summary(lm_model)
```

---

### 3.2 Logistic Regression

* Binary classification (0/1 outcome).

```R
glm_model <- glm(Survived ~ Age + Sex + Pclass, data=titanic_train, family=binomial)
summary(glm_model)
```

---

### 3.3 Polynomial Regression

```R
set.seed(1)
x <- 1:100
y <- 5 + 0.05*x + 0.01*x^2 + rnorm(100, 0, 10)
poly_model <- lm(y ~ poly(x,2))
```

---

## **Unit 4: Clustering**

**Topics:** K-Means, Hierarchical, DBSCAN

### 4.1 K-Means

```R
set.seed(123)
clusters <- kmeans(iris[,1:4], centers=3)
plot(iris[,1:2], col=clusters$cluster)
```

---

### 4.2 Hierarchical Clustering

```R
d <- dist(mtcars, method="euclidean")
hc <- hclust(d, method="complete")
plot(hc)
```

---

### 4.3 DBSCAN

```R
library(dbscan)
db <- dbscan(iris[,1:4], eps=0.5, minPts=5)
plot(db, iris[,1:2])
```

---

## **Unit 5: Association Rule Mining**

**Topics:** Apriori, Eclat, Rule Pruning, Visualization

### 5.1 Apriori Algorithm

```R
library(arules)
data("Groceries")
rules <- apriori(Groceries, parameter=list(supp=0.01, conf=0.5))
inspect(rules[1:5])
```

---

### 5.2 Eclat Algorithm

```R
rules_eclat <- eclat(Groceries, parameter=list(supp=0.01, maxlen=5))
inspect(rules_eclat[1:5])
```

---

### 5.3 Rule Pruning & Visualization

```R
library(arulesViz)
plot(rules, method="graph")
```

---

## **Unit 6: Text Mining & Sentiment Analysis**

**Topics:** Text preprocessing, Naïve Bayes text classification, Sentiment analysis

### 6.1 Text Preprocessing

* Lowercasing, stopword removal, stemming
* Packages: `tm`, `SnowballC`

```R
library(tm)
docs <- Corpus(VectorSource(text_data))
docs <- tm_map(docs, content_transformer(tolower))
docs <- tm_map(docs, removePunctuation)
docs <- tm_map(docs, removeWords, stopwords("english"))
```

---

### 6.2 Text Classification

```R
library(e1071)
dtm <- DocumentTermMatrix(docs)
train <- as.data.frame(as.matrix(dtm))
model <- naiveBayes(category ~ ., data=train)
```

---

### 6.3 Sentiment Analysis

```R
library(syuzhet)
text <- c("I love data science", "I hate exams")
sentiment <- get_sentiment(text, method="bing")
barplot(sentiment)
```

---

## **Unit 7: Time Series Analysis**

**Topics:** Trend, seasonality, forecasting

### 7.1 Decomposition

```R
ts_data <- ts(AirPassengers, frequency=12)
decomposed <- decompose(ts_data)
plot(decomposed)
```

### 7.2 Forecasting (ARIMA)

```R
library(forecast)
fit <- auto.arima(AirPassengers)
forecasted <- forecast(fit, h=12)
plot(forecasted)
```

