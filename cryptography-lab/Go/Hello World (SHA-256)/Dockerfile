FROM golang:1.21

WORKDIR /app
COPY ["./main.go","/main.go ."]

RUN go build -o hello main.go
CMD ["./hello"]
