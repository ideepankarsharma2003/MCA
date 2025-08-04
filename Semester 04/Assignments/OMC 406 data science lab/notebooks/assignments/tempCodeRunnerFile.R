# Load packages
library(e1071)
library(ggplot2)

# Prepare data
data(mtcars)
mtcars$am <- factor(mtcars$am)

# Train SVM model
svm_model <- svm(am ~ mpg + hp + wt, data = mtcars, kernel = "linear")  # using linear kernel for interpretability

# Predictions
pred_svm <- predict(svm_model, mtcars)

# Confusion matrix
conf_matrix <- table(Predicted = pred_svm, Actual = mtcars$am)
print(conf_matrix)

# Create prediction grid
mpg_seq <- seq(min(mtcars$mpg), max(mtcars$mpg), length = 100)
wt_seq <- seq(min(mtcars$wt), max(mtcars$wt), length = 100)
grid <- expand.grid(mpg = mpg_seq, wt = wt_seq)
grid$hp <- median(mtcars$hp)  # fix hp at median

# Predict on grid
grid$pred <- predict(svm_model, newdata = grid)

# Plot decision boundary
ggplot() +
  geom_tile(data = grid, aes(x = mpg, y = wt, fill = pred), alpha = 0.3) +
  geom_point(data = mtcars, aes(x = mpg, y = wt, color = am), size = 3) +
  labs(title = "SVM Classification: Transmission (am)",
       x = "Miles per Gallon (mpg)", y = "Weight (wt)",
       fill = "Predicted", color = "Actual") +
  theme_minimal()

# Extract support vectors
support_vectors <- mtcars[svm_model$index, ]

ggplot(mtcars, aes(x = mpg, y = wt, color = am)) +
  geom_point(size = 3) +
  geom_point(data = support_vectors, aes(x = mpg, y = wt), shape = 8, size = 4, color = "black") +
  labs(title = "Support Vectors Highlighted",
       subtitle = "Black stars are support vectors",
       x = "mpg", y = "wt") +
  theme_minimal()
