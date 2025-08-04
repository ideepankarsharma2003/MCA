# install.packages("titanic")
library(titanic)
data <- titanic_train

# Check missing values
summary(data)

# Impute missing age with mean
data$Age[is.na(data$Age)] <- mean(data$Age, na.rm=TRUE)

# Drop unnecessary columns
data <- subset(data, select = -c(Cabin))

# Visualize survival
library(ggplot2)
ggplot(data, aes(x = factor(Survived))) + geom_bar() +
  labs(title="Survival Count", x="Survived", y="Count")

ggplot(data, aes(x = factor(Pclass), fill = factor(Survived))) + 
  geom_bar(position = "dodge") + labs(title="Survival by Passenger Class")