# python script to create R files for each exercise

exercises = {
    "01_airquality_data_cleaning.R": """
# Air Quality Dataset: Handle missing values and visualize
data(airquality)
summary(airquality)
airquality$Ozone[is.na(airquality$Ozone)] <- mean(airquality$Ozone, na.rm = TRUE)
airquality$Solar.R[is.na(airquality$Solar.R)] <- mean(airquality$Solar.R, na.rm = TRUE)
library(ggplot2)
ggplot(airquality, aes(x = factor(Month), y = Ozone)) +
  geom_boxplot() +
  labs(title = "Ozone Levels by Month", x = "Month", y = "Ozone")
""",

    "02_titanic_missing_values_visualization.R": """
# Titanic Dataset: Handle missing values and visualize survival patterns
titanic <- as.data.frame(Titanic)
# Example for csv: titanic <- read.csv("titanic.csv")
# Impute missing Age with median
titanic$Age[is.na(titanic$Age)] <- median(titanic$Age, na.rm = TRUE)
library(ggplot2)
ggplot(titanic, aes(x = Sex, fill = factor(Survived))) +
  geom_bar(position = "dodge") +
  labs(title = "Survival by Sex", x = "Sex", fill = "Survived")
""",

    "03_naive_bayes_titanic.R": """
library(e1071)
model_nb <- naiveBayes(Survived ~ Pclass + Sex + Age + Fare, data = titanic)
pred <- predict(model_nb, titanic)
table(pred, titanic$Survived)
""",

    "04_svm_mtcars.R": """
library(e1071)
data(mtcars)
mtcars$am <- factor(mtcars$am)
svm_model <- svm(am ~ mpg + hp + wt, data = mtcars)
pred_svm <- predict(svm_model, mtcars)
table(pred_svm, mtcars$am)
""",

    "05_knn_mnist.R": """
# Example with iris (replace with MNIST for real scenario)
library(class)
data(iris)
set.seed(123)
train_idx <- sample(1:nrow(iris), 0.7 * nrow(iris))
train <- iris[train_idx, ]
test <- iris[-train_idx, ]
knn_pred <- knn(train[,1:4], test[,1:4], cl = train$Species, k = 3)
table(knn_pred, test$Species)
""",

    "06_multiple_linear_regression_boston.R": """
library(MASS)
data(Boston)
model_lm <- lm(medv ~ ., data = Boston)
summary(model_lm)
""",

    "07_logistic_regression_titanic.R": """
log_model <- glm(Survived ~ Pclass + Sex + Age + Fare, data = titanic, family = binomial)
summary(log_model)
""",

    "08_polynomial_regression_synthetic.R": """
set.seed(100)
x <- 1:100
y <- 5 + 2*x - 0.05*x^2 + rnorm(100,0,10)
data_poly <- data.frame(x, y)
poly_model <- lm(y ~ poly(x, 2), data = data_poly)
summary(poly_model)
plot(x, y)
lines(x, predict(poly_model), col = "red", lwd = 2)
""",

    "09_hierarchical_clustering_mtcars.R": """
data(mtcars)
d <- dist(mtcars)
hc <- hclust(d)
plot(hc, main = "Hierarchical Clustering Dendrogram")
""",

    "10_dbscan_clustering.R": """
library(dbscan)
set.seed(123)
data <- matrix(rnorm(200), ncol=2)
data[51:100, ] <- data[51:100, ] + 3
db <- dbscan(data, eps = 0.5, minPts = 5)
plot(data, col = db$cluster + 1L, main = "DBSCAN Clustering")
"""
}

for filename, content in exercises.items():
    with open(f"assignments/{filename}", "w") as f:
        f.write(content.strip() + "\n")

print("R script files have been created!")
