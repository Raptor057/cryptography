# C++ base image
FROM gcc:13

WORKDIR /app
WORKDIR /app
COPY ["./main.cpp", "./"]

RUN apt-get update && apt-get install -y libssl-dev
RUN g++ main.cpp -o hello -lcrypto

CMD ["./hello"]
