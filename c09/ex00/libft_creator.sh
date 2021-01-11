gcc -c -o ft_putchar.o ft_putchar.c
gcc -c -o ft_strlen.o ft_strlen.c
ar rc libft.a ft_putchar.o ft_strlen.o
ranlib libft.a
