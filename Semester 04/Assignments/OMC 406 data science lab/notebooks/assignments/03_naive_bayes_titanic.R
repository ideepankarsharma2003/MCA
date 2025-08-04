library(e1071)
library(titanic)

# Load Titanic dataset
data <- titanic_train

# Remove missing values
data <- na.omit(data)

# Convert variables to factors
data$Survived <- factor(data$Survived)
data$Sex <- factor(data$Sex)
data$Pclass <- factor(data$Pclass)

# Train-test split (70% train, 30% test)
set.seed(123)
train_idx <- sample(1:nrow(data), 0.7 * nrow(data))
train <- data[train_idx, ]
test <- data[-train_idx, ]

# Train Naive Bayes model
model <- naiveBayes(Survived ~ Pclass + Sex + Age, data = train)

# Make predictions
pred <- predict(model, test)

# Confusion Matrix
conf_matrix <- table(Predicted = pred, Actual = test$Survived)
print(conf_matrix)

# Accuracy
accuracy <- sum(diag(conf_matrix)) / sum(conf_matrix)
cat("Accuracy:", round(accuracy * 100, 2), "%\n")

# Predict class probabilities
prob_pred <- predict(model, test, type = "raw")  # returns matrix with prob for 0 and 1
test$prob_survived <- prob_pred[, "1"]
test$Sex <- factor(test$Sex)

# Plot: Probability of Survival by Age and Sex
library(ggplot2)

ggplot(test, aes(x = Age, y = prob_survived, color = Sex)) +
  geom_point(alpha = 0.5) +
  geom_smooth(method = "loess", se = FALSE) +
  labs(title = "Predicted Probability of Survival by Age and Sex",
       x = "Age", y = "Predicted Probability (Survived = 1)") +
  theme_minimal()

test$pred_class <- pred

# Compute accuracy by Pclass
library(dplyr)

accuracy_by_pclass <- test %>%
  group_by(Pclass) %>%
  summarise(accuracy = mean(pred_class == Survived))

# Plot
ggplot(accuracy_by_pclass, aes(x = Pclass, y = accuracy, fill = Pclass)) +
  geom_col() +
  labs(title = "Model Accuracy by Passenger Class",
       x = "Passenger Class", y = "Accuracy") +
  scale_y_continuous(labels = scales::percent) +
  theme_minimal()

# Convert confusion matrix to data frame
conf_df <- as.data.frame(conf_matrix)
colnames(conf_df) <- c("Predicted", "Actual", "Freq")

ggplot(conf_df, aes(x = Actual, y = Predicted, fill = Freq)) +
  geom_tile(color = "white") +
  geom_text(aes(label = Freq), color = "black", size = 5) +
  scale_fill_gradient(low = "white", high = "steelblue") +
  labs(title = "Confusion Matrix Heatmap") +
  theme_minimal()
