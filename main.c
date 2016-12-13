/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:56:37 by mgould            #+#    #+#             */
/*   Updated: 2016/12/12 18:39:03 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX 31
#define MAX_FILES 26
#define MAX_LINES 20
#include <unistd.h>
#include <test.h>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

// get a random number between

int get_rand(int range)
{
	int rando;

	rando = 0;
	rando = (rand() % range);
	if (rando == 0)
		rando = 1;
	return (rando);
}

char *makeline(int max_letters)
{
	char *line;
	int i;
	static char letter = 'A';
	int len;
	char *clen;
	int flag;

	flag = 0;
	while (!(ft_is_prime((len = get_rand(max_letters)))))
			continue;
	//printf("letters in line:%d\n", len);
	clen = ft_itoa(len);
	//printf("clen:%s\n", clen);
	i = 0;
	line = (char *)malloc(sizeof(char)*(len + 1));
	line[len] = '\0';
	line[len - 1] = '\n';
	//printf("%s\n", line);
	while(i < (len - 1))
	{
		if (clen[i] && flag == 0)
			line[i] = clen[i];
		else
		{
			flag = 1;
			line[i] = letter;
		}
		//printf("line:%d:%c\n", i,  line[i]);
		i++;
	}
	letter += 1;
	letter = 65 + ((letter - 65) % 26);
	//printf("line is:%s\n", line);
	return (line);
}

char **make_lines(int lines_in_file)
{
	int i;
	char **lines;

	i = 0;
	lines = (char **)malloc(sizeof(char *)*(lines_in_file + 1));
	printf("lines in file:%d\n", lines_in_file);
	lines[lines_in_file] = NULL;
	while(i < lines_in_file)
	{
		lines[i] = makeline(MAX);
		i++;
	}
	return (lines);
}

int main(int ac, char **av)
{
	int num_files;
	int fd;
	char file_name[6] = "toutA";
	char *line;
	char **lines;
	int i;

	fd = 0;
	line = NULL;
	if (ac != 2)
	{
		printf("Enter the number of files to create, max 26, default is 4\n");
		num_files = 4;
	}
	else
		num_files = ft_atoi(av[1]);
	if (num_files > MAX_FILES)
		num_files = MAX_FILES;

	srand(time(NULL));
	i = 0;
	while (num_files)
	{
		printf("CREATED FILE %s\n", file_name);
		fd = open((const char*)file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (!fd)
		{
			printf("error making file\n");
			return (0);
		}
		lines = make_lines(rand() % MAX_LINES);
		while (lines[i])
		{
			ft_putstr_fd((const char *)lines[i], fd);
			//printf("%s:\n%s\n", file_name, lines[i]);
			free(lines[i]);
			i++;
		}
		free(lines);
		close(fd);
		file_name[4] += 1;
		num_files--;
		i = 0;
	}

	return (0);
}













