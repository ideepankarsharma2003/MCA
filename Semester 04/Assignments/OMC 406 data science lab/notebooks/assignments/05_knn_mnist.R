# Load necessary libraries
library(class)

# Load MNIST data (make sure files are in your working directory)
train <- read.csv("data/archive/mnist_train.csv")
test <- read.csv("data/archive/mnist_test.csv")

# Convert labels to factors
train$label <- as.factor(train$label)
test$label <- as.factor(test$label)


# Use smaller subsets for faster testing (k-NN is slow on large data)
train_small <- train[1:2000, ]   # 2,000 training samples
test_small <- test[1:300, ]      # 300 test samples


# Apply k-NN with k = 5
pred <- knn(train = train_small[, -1],
            test = test_small[, -1],
            cl = train_small$label,
            k = 5)

# Confusion Matrix
conf_matrix <- table(Predicted = pred, Actual = test_small$label)
print(conf_matrix)

# Accuracy
accuracy <- mean(pred == test_small$label)
cat("Accuracy:", round(accuracy * 100, 2), "%\n")

# Remove zero-variance columns before PCA
pixel_data <- train_small[, -1]  # exclude label column

# Keep only columns with non-zero variance
pixel_data <- pixel_data[, apply(pixel_data, 2, var) != 0]

# Apply PCA
pca <- prcomp(pixel_data, center = TRUE, scale. = TRUE)

# Create a dataframe with the first 2 principal components and labels
pca_data <- data.frame(pca$x[, 1:2], label = train_small$label)

# Plot clusters
library(ggplot2)
ggplot(pca_data, aes(x = PC1, y = PC2, color = label)) +
  geom_point(alpha = 0.6) +
  labs(title = "PCA of MNIST (Train Set - First 2 PCs)",
       x = "Principal Component 1", y = "Principal Component 2") +
  theme_minimal()
