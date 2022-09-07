FROM --platform=linux/amd64 ubuntu

RUN apt-get update && apt-get install -y vim          \
                                         gcc          \
                                         make         \
                                         nasm

WORKDIR /libasm
COPY env/res/vimrc /etc/vim/vimrc.local

CMD ["/bin/bash"]
