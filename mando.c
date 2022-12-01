/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mando.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:26:32 by msariasl          #+#    #+#             */
/*   Updated: 2022/12/01 15:48:48 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "../get_next_line.h"

int main()
{
  int fd = open("A.txt", O_RDONLY);
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
  printf("\n\n- - - - - > M A N D O T O R Y _ _ _ P A R T < - - - - -\n\n(one space need to exits above the header!)");
  printf("\n\nIs this part okey for you?");
  printf("\nGive points from 100: ");
  int p = 0;
  scanf("%d", &p);
  printf("Given %d", p);
  int pd = open("points.txt",O_RDWR | O_CREAT ,0777);
  char *str = ft_itoa(p);
  write(pd,str,3);  
}