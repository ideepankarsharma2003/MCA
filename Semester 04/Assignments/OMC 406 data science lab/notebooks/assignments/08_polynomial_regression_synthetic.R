set.seed(100)
x <- 1:100
y <- 5 + 2*x - 0.05*x^2 + rnorm(100,0,10)
data_poly <- data.frame(x, y)
poly_model <- lm(y ~ poly(x, 2), data = data_poly)
summary(poly_model)
plot(x, y)
lines(x, predict(poly_model), col = "red", lwd = 2)
