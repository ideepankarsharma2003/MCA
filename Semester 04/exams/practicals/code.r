options(repos = c(CRAN = "https://cloud.r-project.org")) 

install_if_missing <- function(pkgs) {
  for (p in pkgs) {
    if (!requireNamespace(p, quietly = TRUE)) {
      install.packages(p, dependencies = TRUE)
    }
  }
}

install_if_missing(c("cluster", "ggplot2", "factoextra"))


library(stats)
library(cluster)
library(ggplot2)
suppressPackageStartupMessages({library(factoextra)})  

X <- scale(iris[, 1:4])  

d  <- dist(X, method = "euclidean")
hc <- hclust(d, method = "ward.D2")

plot(as.dendrogram(hc), main = "Iris Hierarchical Clustering (Ward.D2)",
     ylab = "Height", xlab = "Samples")

k <- 3
fviz_dend(hc, k = k, rect = TRUE, show_labels = FALSE,
          main = "Iris Dendrogram (Ward.D2) with k=3")

cl <- cutree(hc, k = k)
table(cl)

sil_k <- sapply(2:6, function(kk) {
  ss <- silhouette(cutree(hc, k = kk), d)
  mean(ss[, "sil_width"])
})
print(round(setNames(sil_k, 2:6), 3))

pca <- prcomp(X, center = FALSE,)
pc  <- as.data.frame(pca$x[, 1:2])
pc$cluster <- factor(cl)

ggplot(pc, aes(PC1, PC2, color = cluster)) +
  geom_point(size = 2) +
  labs(title = "Iris clusters (Agglomerative, k=3) — PCA projection") +
  theme_minimal()
