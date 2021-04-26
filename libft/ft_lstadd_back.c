/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:27:34 by hboudhir          #+#    #+#             */
/*   Updated: 2019/11/29 18:58:02 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{    
	t_list *temp;
    
    temp = (t_list*)malloc(sizeof(t_list));
    temp->content = 10;
    temp->next = NULL;
    if (*lst == NULL)
        *lst = temp;
    else
    {
        t_list *p;
        p = *lst;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;            
    }  
	
	
}