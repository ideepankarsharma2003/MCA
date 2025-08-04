# Air Quality Dataset: Handle missing values and visualize
data(airquality)
summary(airquality)
airquality$Ozone[is.na(airquality$Ozone)] <- mean(airquality$Ozone, na.rm = TRUE)
airquality$Solar.R[is.na(airquality$Solar.R)] <- mean(airquality$Solar.R, na.rm = TRUE)
library(ggplot2)
ggplot(airquality, aes(x = factor(Month), y = Ozone)) +
  geom_boxplot() +
  labs(title = "Ozone Levels by Month", x = "Month", y = "Ozone")
