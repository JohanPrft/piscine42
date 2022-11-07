/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctutor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:37:34 by vcart             #+#    #+#             */
/*   Updated: 2022/08/13 15:12:09 by vcart            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_show_matrice(int row, int col, int matrice[row][col])
{
    int x;
    int y;

    x = 0;
    while (x < row)
    {
        y = 0;
        while (y < col)
        {
            ft_putchar(' ');
            ft_putchar('0' + matrice[x][y]);
            y++;
        }
        ft_putchar('\n');
        x++;
    }
}


int ft_empy_row(int row[6])
{
    int i;

    i = 1;
    while (i < 5)
    {
        if (row[i] != 0)
            return (0);
    }
    return (1);
}

int absentSurLigne (int k, int matrix[6][6], int i)
{
    int j;

    j = 1;
    while (j < 6)
    {
        if (matrix[i][j] == k)
            return (0);
        j++;
    }
    return (1);
}

int absentSurColonne (int k, int matrix[6][6], int j)
{
    int i;

    i = 1;
    while (i < 6)
    {
        if (matrix[i][j] == k)
            return (0);
        i++;
    }
    return (1);
}

int valideSurLigne (int k, int matrix[6][6], int i)
{
    int j;
    int show;

    j = 1;
    show = 1;
    while (j < 5)
    {
        if (matrix[i][j] < matrix[i + 1][j])
            show++;
        j++;
    }
    if (show == matrix[i][0])
        return (1);
    return (0);
}

int valideSurColonne (int k, int matrix[6][6], int j)
{
    int i;
    int show;

    i = 1;
    show = 1;
    while (i < 5)
    {
        if (matrix[i][j] < matrix[i][j + 1])
            show++;
        i++;
    }
    if (show == matrix[0][j])
        return (1);
    return (0);
}

int estValide (int matrix[6][6], int position)
{
    
    int i;
    int j;
    int k;
    
    if (position == 4 * 4)
        return (1);
    i = position / 4;
    j = position % 4;
    k = 4;
    if (matrix[i][j] != 0)
        return estValide(matrix, position+1);
    while(k >= 1)
    {
        if ((absentSurLigne(k, matrix, i) && absentSurColonne(k, matrix, j)))
        {
            matrix[i][j] = k;

            if ( estValide (matrix, position+1) )
                return 1;
        }
        k--;
    }

    return 0;
}

int    main()
{
    int matrix[6][6] = 
    {
        {0, 4, 3, 2, 1, 0},
        {4, 0, 0, 0, 0, 1},
        {3, 0, 0 ,0 ,0 ,2},
        {2, 0, 0, 0, 0, 2},
        {1, 0, 0, 0, 0, 2},
        {0, 1, 2, 2, 2, 0}     };
  
	   	estValide(matrix, 5);
		ft_show_matrice(6, 6, matrix);	
}
