# Experiment 1: Data Cleaning and Visualization - airquality Dataset

# Load necessary libraries
library(ggplot2)
library(dplyr)

# Load the built-in dataset
data("airquality")
df <- airquality

# View the first few rows
head(df)

# Check structure
str(df)

# Summary to observe missing values
summary(df)

# Count missing values per column
colSums(is.na(df))

# Handling Missing Values:
# Option 1: Remove rows with NA
df_cleaned <- na.omit(df)

# Option 2: Impute missing values (mean imputation)
df_imputed <- df
df_imputed$Ozone[is.na(df_imputed$Ozone)] <- mean(df_imputed$Ozone, na.rm = TRUE)
df_imputed$Solar.R[is.na(df_imputed$Solar.R)] <- mean(df_imputed$Solar.R, na.rm = TRUE)

# After cleaning
colSums(is.na(df_imputed))

# Visualization 1: Ozone levels by Month
ggplot(df_imputed, aes(x = factor(Month), y = Ozone)) +
  geom_boxplot(fill = "skyblue") +
  labs(title = "Ozone Levels by Month", x = "Month", y = "Ozone (ppb)")

# Visualization 2: Solar Radiation vs Ozone
ggplot(df_imputed, aes(x = Solar.R, y = Ozone)) +
  geom_point(color = "darkgreen") +
  geom_smooth(method = "lm", se = FALSE, color = "red") +
  labs(title = "Solar Radiation vs Ozone", x = "Solar Radiation", y = "Ozone")

# Visualization 3: Line plot for Temp over time
df_imputed$Date <- as.Date(paste(1973, df_imputed$Month, df_imputed$Day, sep = "-"))
ggplot(df_imputed, aes(x = Date, y = Temp)) +
  geom_line(color = "purple") +
  labs(title = "Temperature Trend Over Time", x = "Date", y = "Temperature (F)")
