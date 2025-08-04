#!/bin/bash
# Start RStudio Server in background
rstudio-server start

# Start Jupyter Notebook in foreground
exec jupyter notebook --ip=0.0.0.0 --port=8888 --allow-root --NotebookApp.token=''
