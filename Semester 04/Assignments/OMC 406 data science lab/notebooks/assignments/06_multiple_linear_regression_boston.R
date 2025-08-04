# Load necessary library
library(MASS)

# Load dataset
data(Boston)

# Fit multiple linear regression model
model_lm <- lm(medv ~ ., data = Boston)

# Model summary
summary(model_lm)


# Predict on training data
predicted_medv <- predict(model_lm, newdata = Boston)

# Plot
plot(Boston$medv, predicted_medv,
     main = "Actual vs Predicted House Prices",
     xlab = "Actual medv",
     ylab = "Predicted medv",
     col = "blue", pch = 20)
abline(a = 0, b = 1, col = "red", lwd = 2)
plot(model_lm, which = 1)  # Residuals vs Fitted
