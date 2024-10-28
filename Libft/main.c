/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:20:52 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/28 10:42:51 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int test_ft_isalpha(void)
{
    int cases[] = {'A', 'z', '5', 'b', ' ', '0', '\n', EOF};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        if (isalpha(cases[i]) != ft_isalpha(cases[i]))
        {
            printf("ft_isalpha(%c / %d) -> FAILED! : expected -> %d, got -> %d\n", 
                cases[i], cases[i], isalpha(cases[i]), ft_isalpha(cases[i]));
            return 0;
        }
    }
    printf("ft_isalpha -> PASSED!\n");
    return 1;
}

int test_ft_isdigit(void)
{
    int cases[] = {'A', 'z', '5', 'b', ' ', '0', '\n', EOF};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        if (isdigit(cases[i]) != ft_isdigit(cases[i]))
        {
            printf("ft_isdigit(%c / %d) -> FAILED! : expected -> %d, got -> %d\n", 
                cases[i], cases[i], isdigit(cases[i]), ft_isdigit(cases[i]));
            return 0;
        }
    }
    printf("ft_isdigit -> PASSED!\n");
    return 1;
}

int test_ft_isalnum(void)
{
    int cases[] = {'A', 'z', '5', 'b', ' ', '0', '\n', EOF};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        if (isalnum(cases[i]) != ft_isalnum(cases[i]))
        {
            printf("ft_isalnum(%c / %d) -> FAILED! : expected -> %d, got -> %d\n", 
                cases[i], cases[i], isalnum(cases[i]), ft_isalnum(cases[i]));
            return 0;
        }
    }
    printf("ft_isalnum -> PASSED!\n");
    return 1;
}

void run_memcpy_tests(void)
{
	char s[] = "Hello, World!";
	char d[] = "Hello, World!";

    	ft_memcpy(s + 2, s, 5);
    	printf("memcpy  ft_: %s\n", s);

    	memcpy(d + 2, d, 5);
  	printf("memcpy  std: %s\n", d);

}

int test_ft_memmove(void)
{
	char s[] = "Hello, World!";
	char d[] = "Hello, World!";
	
	memmove(s + 2, s , 5);
	printf("memmove std: %s \n",s);
	ft_memmove(d + 2, d , 5);
	printf("memmove ft_: %s \n", d);
	return 1;
}

void	test_ft_strlcpy(void)
{
	char *src = "123456789012345678901111";
	char s[20];
	char d[20];

//	strlcpy(s, src, sizeof(s));
	printf("strlcpy std: %s\n", s);
	ft_strlcpy(d, src, sizeof(d));
	printf("strlcpy ft_: %s\n", d);
}

void	test_ft_strlcat(void)
{
	char *src = 0;
	char s[20] = "123456";
	char d[20] = "123456";

	strlcat(s, src, 20);
	printf("strlcat std: %s\n", s);
	ft_strlcat(d, src, 20);
	printf("strlcat ft_: %s\n", d);

}

void test_ft_toupper(void)
{
	char t[] = {97, 65, 0 , -1, 255, 127};
	int i = 0;

	while (i < sizeof(t))
	{
		printf("\nTest %d : toupper(%c / %d)---\n", i+1, t[i], t[i]);
		printf("std --> %c / %d\n", toupper(t[i]), toupper(t[i]));
		printf("ft_ --> %c / %d\n", ft_toupper(t[i]), ft_toupper(t[i]));
		i++;
	}
}

void test_ft_tolower(void)
{
	char t[] = {97, 65, 0 , -1, 255, 127, 128, -2};
	int i = 0;

	while (i < sizeof(t))
	{
		printf("\nTest %d : tolower(%c / %d)---\n", i+1, t[i], t[i]);
		printf("std --> %c / %d\n", tolower(t[i]), tolower(t[i]));
		printf("ft_ --> %c / %d\n", ft_tolower(t[i]), ft_tolower(t[i]));
		i++;
	}
}
int main(void)
{
    printf("<---------- Output --------->\n\n");
    //test_ft_isalpha();
    //test_ft_isdigit();
    //test_ft_isalnum();
    //run_memcpy_tests();
    //test_ft_memmove();
    //test_ft_strlcpy();
    //test_ft_strlcat();
	//test_ft_toupper();
	test_ft_tolower();
    return 0;
}

