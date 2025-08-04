# Load necessary package
library(titanic)
library(ggplot2)
library(dplyr)

# Load dataset
data <- titanic_train

# Data Cleaning: Remove NAs
data <- na.omit(data)

# Ensure proper types
data$Survived <- factor(data$Survived)
data$Sex <- factor(data$Sex)
data$Pclass <- factor(data$Pclass)

# Train logistic regression model
model <- glm(Survived ~ Pclass + Sex + Age, data = data, family = binomial)

# Model Summary
summary(model)

# Predict probabilities
data$predicted_prob <- predict(model, type = "response")

# Classify as 0 or 1 using 0.5 threshold
data$predicted_class <- ifelse(data$predicted_prob > 0.5, 1, 0)

# Confusion Matrix
conf_matrix <- table(Predicted = data$predicted_class, Actual = data$Survived)
print(conf_matrix)

# Accuracy
accuracy <- mean(data$predicted_class == as.numeric(as.character(data$Survived)))
cat("Accuracy:", round(accuracy * 100, 2), "%\n")


ggplot(data, aes(x = Age, y = predicted_prob, color = Sex)) +
  geom_point(alpha = 0.6) +
  geom_smooth(method = "loess") +
  labs(title = "Predicted Survival Probability by Age and Sex",
       x = "Age", y = "Predicted Probability") +
  theme_minimal()

avg_pred <- data %>%
  group_by(Pclass) %>%
  summarise(Average_Predicted_Survival = mean(predicted_prob))

ggplot(avg_pred, aes(x = Pclass, y = Average_Predicted_Survival, fill = Pclass)) +
  geom_col() +
  labs(title = "Average Predicted Survival by Passenger Class",
       x = "Pclass", y = "Predicted Survival Probability") +
  theme_minimal()

