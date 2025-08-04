library(dbscan)
set.seed(123)
data <- matrix(rnorm(200), ncol=2)
data[51:100, ] <- data[51:100, ] + 3
db <- dbscan(data, eps = 0.5, minPts = 5)
plot(data, col = db$cluster + 1L, main = "DBSCAN Clustering")
