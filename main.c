/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:26:32 by msariasl          #+#    #+#             */
/*   Updated: 2022/12/07 10:09:06 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../ft_printf.h"

int main()
{
  int fd = open("A.txt", O_RDONLY);
  char *text[8192];
  int i = 0;
  text[i] = get_next_line(fd);
  if (text[i] == NULL)
    return 0;
  ft_printf("%s", text[i]);
  i++;
  while (*text != 0)
  {
    text[i] = get_next_line(fd);
    if (text[i] == NULL)
      break;
    ft_printf("%s", text[i]);
    i++;
  }
  ft_printf("\n\n- - - - - > M A N D O T O R Y _ _ _ P A R T < - - - - -\n\n(one space need to exits above the header!)");
  ft_printf("\n\nIs this part okey for you?");
  ft_printf("\nGive points from 100: ");
  int p = 0;
  scanf("%d", &p);
  ft_printf("Given %d\n", p);
  int pd = open("points.txt", O_RDWR | O_CREAT, 0777);
  char *str = ft_itoa(p);
  write(pd, str, 3);
}
