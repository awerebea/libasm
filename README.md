# libasm
21-School (Ecole42) 'libasm' project. Score 100/125 (no bonus part).

# Description
A static library of some stdlib functions written in assembler.

List of implemented functions:
```
size_t    ft_strlen(char const *str);
char      *ft_strcpy(char * dst, const char * src);
int       ft_strcmp(const char *s1, const char *s2);
ssize_t   ft_write(int fd, const void *buf, size_t count);
ssize_t   ft_read(int fildes, void *buf, size_t nbyte);
char      *ft_strdup(const char *s1);
```

# Conditions
Due to the difference in the organization of system calls in different operating systems, without changing the files, this project will compile and work only on macOS.

# Usage
To build library run: `make`

To compile and run the test program ("tester") linked with the library, run: `make test`
