int main(int argc, char **args) {
    char *wellFineThen = "Hello world\n";

#if defined(__gnu_linux__)
    __asm__ ("movq $1, %%rax;"
#elif defined(__APPLE__) && defined(__MACH__)
    __asm__ ("movq $0x2000004, %%rax;"
#else
#error Unsupported system
#endif
             "movq $1, %%rdi;"
             "movq $12, %%rdx;"
             "syscall;"
             :
             : "S" (wellFineThen)
    );

    return 0;
}
