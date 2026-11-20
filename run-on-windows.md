# Running this project on a windows machine using a docker container

### make sure the container is running from docker desktop
```cmd
docker run --rm -it -v "${PWD}:/work" -w /work gcc:latest bash
```

### then inside the container run the c program using gcc
```cmd
gcc -Wall -Wextra -std=c11 main.c ushell/core.c -o shell
```