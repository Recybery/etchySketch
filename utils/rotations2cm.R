library("tidyr")
library("ggplot2")


h_dats <- as.data.frame(c(0:3))
names(h_dats) <- c("rot")
h_dats$dist <- c(7.0, 10.6, 14.2, 17.8)
ggplot(h_dats) + geom_point(aes(x=rot, y=dist))
h_dats.lm <- lm( dist ~ rot, h_dats)
summary(h_dats.lm)

v_dats <- as.data.frame(c(0:2))
names(v_dats) <- c("rot")
v_dats$dist <- c(5.0, 8.3, 11.9)
ggplot(v_dats) + geom_point(aes(x=rot, y=dist))
v_dats.lm <- lm( dist ~ rot, v_dats)
summary(v_dats.lm)

