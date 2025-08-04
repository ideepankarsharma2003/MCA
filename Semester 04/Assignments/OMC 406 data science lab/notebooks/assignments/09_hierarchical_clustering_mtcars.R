data(mtcars)
d <- dist(mtcars)
hc <- hclust(d)
plot(hc, main = "Hierarchical Clustering Dendrogram")
