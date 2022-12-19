/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:26:30 by msariasl          #+#    #+#             */
/*   Updated: 2022/12/19 23:25:21 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "../get_next_line_bonus.h"

int main()
{
  int fd = open("B.txt", O_RDONLY);
  char **text;
  *text = get_next_line(fd);
  if (*text != NULL)
    printf("%s", *text);
  while (*text != 0)
  {
    *text = get_next_line(fd);
    if (*text != NULL)
      printf("%s", *text);
    else
      break;
    (*text)++;
  }
  printf("\n- - - - - > B O N U S _ _ _ P A R T < - - - - -\n\n(one space need to exits above the header!)");
  printf("\n\nIs this part okey for you?");
  printf("\nGive points from 25: ");
  int p = 0;
  scanf("%d", &p);
  printf("Given %d", p);
  int pd = open("points.txt", O_RDONLY);
  char str[3];
  ssize_t rd_bytes = read(pd, str, 3);
  if (rd_bytes < 0)
    return 0;
  printf("\n\nT O T A L _ _ _ P O I N T S");
  int pp = atoi(str);
  pp += p;
  printf("\n\n%d\n\n", pp);
  printf("K A R M A _ _ _ T E S T\n");
  int fdA = open("A.txt", O_RDONLY);
  int fdB = open("B.txt", O_RDONLY);
  printf("\n1. -> %s",get_next_line(fdA));
  printf("2. -> %s",get_next_line(fdB));
  printf("3. -> %s",get_next_line(fdA));
  printf("4. -> %s\n",get_next_line(fdB));
}