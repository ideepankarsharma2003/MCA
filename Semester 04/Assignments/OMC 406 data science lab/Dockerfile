FROM rocker/tidyverse:latest

# Install system dependencies
RUN apt-get update && apt-get install -y \
    python3 python3-pip python3-venv libzmq3-dev curl git sudo


# Create virtualenv and install Jupyter inside it
RUN python3 -m venv /opt/venv && \
    /opt/venv/bin/pip install --upgrade pip && \
    /opt/venv/bin/pip install notebook jupyter_client

# Add venv to PATH so jupyter is accessible
ENV PATH="/opt/venv/bin:$PATH"

# Install required R packages
RUN R -e "install.packages(c('e1071', 'class', 'MASS', 'dbscan', 'ggplot2', 'dplyr', 'tidyr', 'caret', 'IRkernel'))"

# Register the IRkernel (R Jupyter kernel)
RUN R -e "IRkernel::installspec(user = FALSE)"

# Set RStudio password (user 'rstudio' already exists in rocker images)
RUN echo "rstudio:rstudio" | chpasswd

EXPOSE 8888
EXPOSE 8787

# CMD ["jupyter", "notebook", "--ip=0.0.0.0", "--port=8888", "--allow-root", "--NotebookApp.token=''"]
COPY start.sh /start.sh
RUN chmod +x /start.sh
CMD ["/start.sh"]
